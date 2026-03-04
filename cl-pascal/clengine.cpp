/*===============================================================================
File:        clengine.cpp
Project:     cl-pascal
Component:   CL Engine util
Author:      Alexander Pascal (fryman)
Created:     2026-02-27
Last Update: 2026-03-03
Purpose:
    Command Line engine + Dispatch for commands
Overview:
     
Assumptions:
     uStr > User String
    
Notes:
    
===============================================================================*/

#include "main.h"
#include "clengine.h"
#include <iostream>
#include <string>
#include <string_view>

using namespace std;

static vector<string> fStr{}; //Formatted String
//static double mResult{};      //math result

/*++
cmdToInt(const string_view currentIn)
Routine Description:

    command to enum type

Arguments:
    const string_view currentIn
Return Value:
    command::CMD_INVALID;
Side Effects:

    None.

--*/
command cmdToInt(const string_view currentIn)
{
    if(currentIn == "help") return command::CMD_HELP;
    if(currentIn == "maths") return command::CMD_MATHS;
    if(currentIn == "rand") return command::CMD_RANDOM;
    if(currentIn == "echo") return command::CMD_ECHO;
    if(currentIn == "devinfo") return command::CMD_DEVINFO;
    if(currentIn == "time") return command::CMD_TIME;
    if(currentIn == "developer") return command::CMD_DEVINFO;
    if(currentIn == "about") return command::CMD_ABOUT;
    if(currentIn == "clear") return command::CMD_CLR;
    if(currentIn == "quit") return command::CMD_QUIT;
    if(currentIn == "exit") return command::CMD_QUIT;
    if(currentIn == "/f") return command::ARG_FORMAT_H;
    if(currentIn == "/?") return command::CMD_HELP;
    
    return command::CMD_INVALID;
}

/*++
cl_prompt()
Routine Description:

    prints the ">"

Arguments:
    void
Return Value:
    void
Side Effects:

    None.

--*/
void cl_prompt()
{
    string_view charLn{"> "};
    cout << charLn;
}

/*++
cntr_cmd(vector<string> u_ln)
Routine Description:

    command control switch

Arguments:
    u_ln
Return Value:
    void
Side Effects:

    None.

--*/
void cntr_cmd(vector<string> u_ln)
{
    if(u_ln.empty())
        return;
    
    switch (cmdToInt(u_ln[0])) {
        case command::CMD_HELP:
            cm_help();
            
            break;
            
        case command::CMD_MATHS:
            if(u_ln.size() < 4)
            {
                cerr << "Incorrect Usage: maths <add|sub|mul|div> a b " << '\n';
                break;
            }
            
            cout << cm_maths(u_ln) << '\n';
            
            break;
//        case command::CMD_MOD:
  //          cm_mod(u_ln);
            
    //        break;
            
        case command::CMD_RANDOM:
            cm_random(u_ln);
            
            break;
            
        case command::CMD_ECHO:
            cm_echo(u_ln);
            
            break;
            
        case command::CMD_ABOUT:
            cm_about();
            
            break;
            
        case command::CMD_CLR:
            cm_clear();
            
            break;
        case command::CMD_TIME:
            cm_time();
            
            break;
        
        case command::CMD_DEVINFO:
            cm_devInfo();
            
            break;
            
        case command::CMD_QUIT:
            cm_quit();
            
            break;
            
        case command::ARG_FORMAT_H:
            
            arg_formatH(u_ln);

            break;
            
        default:
            cout << "Invalid Input";
            break;
    }
}

/*++
cm_quit()
Routine Description:

    quit command; exit

Arguments:
     
Return Value:
    false
Side Effects:

    None.

--*/
bool cm_quit()
{
    
    if(!fStr.empty() && (fStr[0] == "quit" || fStr[0] == "exit"))
        return true;
    
    return false;
    
}


/*++
cl_run()
Routine Description:

    run loop

Arguments:
     
Return Value:
    bool true;
Side Effects:

    None.

--*/
bool cl_run()
{
NEWLINE:
    cl_prompt();
    
    
    string uStr = cl_input();      // Own the string
    if(uStr.empty()) //TODO: CHECK IF EMPTY
        goto NEWLINE;

    
    fStr = sTokenize(uStr);

    cntr_cmd(fStr);
    
    
    return true;
}

