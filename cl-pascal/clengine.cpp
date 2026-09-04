/*===============================================================================
File:        clengine.cpp
Project:     cl-pascal
Component:   CL Engine util
Author:      Alexander Pascal (fryman)
Created:     2026-02-27
Last Update: 2026-09-04
Purpose:
             Command Line engine + Dispatch for commands
Overview:
Assumptions:
Notes:
===============================================================================*/

#include "main.h"
#include "clengine.h"
#include "headers.h"
#include "about.h"

using namespace std;

static vector<string> fStr{}; //Formatted String
bool isBugFixActive{false};
vector<string> cmdHist;
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

command commandTable[]
{
    {"help", wrap_help},
    {"calc", wrap_maths},
    {"rand", cm_random},
    {"echo", cm_echo},
    {"devinfo", wrap_devinfo},
    {"bugfix", bugfix_main},
    {"time", wrap_time},
    {"hist", wrap_hist},
    {"strline", wrap_strLine},
    {"temp", cm_temp},
    {"developer", wrap_devinfo},
    {"new", wrap_new},
    {"macro", wrap_meal},
    {"about", wrap_about},
    //{"tabout", wrap_abtbox},
    {"clear", wrap_clear},
    {"quit", wrap_quit},
    {"exit", wrap_quit},
    {"/f", arg_formatH},
    {"/?", wrap_help},
    {"?", wrap_help}
};

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
    
    for(const auto& cmd : commandTable)
    {
        if(u_ln[0] == cmd.name)
        {
            cmd.handler(u_ln);
            return;
        }
    }
    
  //  if(!fSuccess)
    //    return;
    
    cerr << "Unknown Command: " << u_ln[0] << "\n";
    cerr << "Please Try Again.\n";
    
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
     
Return Value:lastRslt
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
    
    cmdHist.push_back(uStr); //log command

    
    fStr = sTokenize(uStr);

    cntr_cmd(fStr);
        
    return true;
}

