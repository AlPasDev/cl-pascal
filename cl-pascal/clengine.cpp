/*===============================================================================
File:        clengine.cpp
Project:     cl-pascal
Component:   CL Engine util
Author:      Alexander Pascal (fryman)
Created:     2026-02-27
Last Update: 2026-02-27
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

static vector<string> fStr{};
static float mResult{};

command cmdToInt(const string_view currentIn)
{
    if(currentIn == "help") return command::CMD_HELP;
    if(currentIn == "maths") return command::CMD_MATHS;
    if(currentIn == "rand") return command::CMD_RANDOM;
    if(currentIn == "repeat") return command::CMD_REPEAT;
    if(currentIn == "about") return command::CMD_ABOUT;
    if(currentIn == "clear") return command::CMD_CLR;
    if(currentIn == "quit") return command::CMD_QUIT;
    if(currentIn == "/f") return command::ARG_FORMAT_H;
    if(currentIn == "/?") return command::CMD_HELP;
    
    return command::CMD_INVALID;
}
void cl_prompt()
{
    string_view charLn{"> "};
    cout << charLn;
}

void cntr_cmd(vector<string> u_ln)
{
    
    switch (cmdToInt(u_ln[0])) {
        case command::CMD_HELP:
            cm_help();
            
            break;
            
        case command::CMD_MATHS:
            mResult = cm_maths(u_ln);
            cout << mResult << '\n';
            
            break;
            
        case command::CMD_RANDOM:
            cm_random();
            
            break;
            
        case command::CMD_REPEAT:
            cm_repeat(u_ln[1]);
            
            break;
            
        case command::CMD_ABOUT:
            cm_about();
            
            break;
            
        case command::CMD_CLR:
            cm_clear();
            
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

bool cm_quit()
{
    if(fStr[0] == "quit")
        return true;
    return false;
}


bool cl_run()
{
    cl_prompt();
    
    
    string uStr = cl_input();      // Own the string
    
    fStr = sTokenize(uStr);

    cntr_cmd(fStr);
    
    
    return true;
}

