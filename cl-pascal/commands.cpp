/*===============================================================================
File:        commands.cpp
Project:     cl-pascal
Component:   command runner
Author:      Alexander Pascal (fryman)
Created:     2026-02-25
Last Update: 2026-02-27
Purpose:
     functions for each command
Overview:
 
     help or /?
     about
     maths
     random
     repeat
     clear
     quit
     /f [command]

Assumptions:
    
Notes:
    
===============================================================================*/
#include "main.h"
#include "clengine.h"
#include <iostream>
#include <sstream>

using namespace std;

constexpr string_view CL_COMMANDLIST
{
    "help   < Prints the help menu, i.e. this one.\n"
    "about  < Prints the about/version screen\n"
    "maths  < \"maths [add;sub;mult;div] num1 num2\": maths functions for calculations\n"
    "rand   < Produces some random numbers from a set range\n"
    "repeat < duplicates the inputted text \n"
    "clear  < Clears the screen\n"
    "quit   < quits the application\n"
    "\n\n/f <command>    < Shows the format for each command\n"
    "/?              < Prints the help menu, i.e. this one.\n"
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

int arg_formatH(vector<string> uStr)
{
    return SUCCESS;
}



