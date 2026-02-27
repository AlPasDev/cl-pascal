/*===============================================================================
File:        commands.cpp
Project:     cl-pascal
Component:   command runner
Author:      Alexander Pascal (fryman)
Created:     2026-02-25
Last Update: 2026-02-25

Purpose:
 
     functions for each command
Overview:
 
     help
     about
     add
     sub
     random
     repeat
     clear
     quit

Assumptions:
    
Notes:
    
===============================================================================*/
#include "main.h"
#include "clengine.h"
#include <iostream>
#include <sstream>

using namespace std;

constexpr int SUCCESS{0};
constexpr string_view CL_COMMANDLIST
{
    "help   < Prints the help menu, i.e. this one.\n"
    "about  < Prints the about/version screen\n"
    "add    < Adds two inputted numbers together\n"
    "sub    < Subtracts two inputted numbers together\n"
    "rand   < Produces some random numbers from a set range\n"
    "repeat < duplicates the inputted text \n"
    "clear  < Clears the screen\n"
    "quit   < quits the application\n"
    "\n\n/f <command>    < Shows the format for each command\n"
};

int cm_help()
{
    cout << "\nSELECTED: HELP\n";
    cout << "================================\n"
         << "Commands:" << '\n'
         << CL_COMMANDLIST << '\n'
         << "================================\n";
    
    
    
    return SUCCESS;
}

int cm_add(string_view uStr)
{
    return SUCCESS;
}

int cm_sub(string_view uStr)
{
    return SUCCESS;
}

int cm_random()
{
    return SUCCESS;
}

int cm_clear()
{
    return SUCCESS;
}

int cm_about()
{
    return SUCCESS;
}

int cm_repeat(string_view uStr)
{
    return SUCCESS;
}

int arg_formatH(string_view uStr)
{
    return SUCCESS;
}



