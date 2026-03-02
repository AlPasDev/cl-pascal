/*===============================================================================
File:        commands.cpp
Project:     cl-pascal
Component:   command runner
Author:      Alexander Pascal (fryman)
Created:     2026-02-25
Last Update: 2026-03-02
Purpose:
     functions for each command
Overview:
 
     help or /?
     about
     maths
     TODO: random
     TODO: repeat
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
#include <string_view>

using namespace std;

constexpr string_view CL_COMMANDLIST
{
    "help   < Prints the help menu, i.e. this one.\n"
    "about  < Prints the about/version screen\n"
    "maths  < \"maths [add;sub;mult;div] num1 num2\": maths functions for calculations\n"
    "rand   < (UNDER CONSTRUCTION)Produces some random numbers from a set range\n"
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

int cm_random() //TODO: ..
{
    return FAILURE;
}

int cm_clear()
{
    for(int i{0}; i < 50; ++i)
        cout << '\n';
        
    return SUCCESS;
}

int cm_about()
{
    openBanner();
    return SUCCESS;
}

int cm_repeat(vector<string> uStr) //TODO: ...
{
    int max = stoi(uStr[3]);
    for(int i{0}; i < max; ++i)
    {
        cout << uStr[2] << '\n';
    }
    return SUCCESS;
}

cformats helpToInt(const string_view currentIn)
{
    if(currentIn == "help") return cformats::CMD_HELP_H;
    if(currentIn == "maths") return cformats::CMD_MATHS_H;
    if(currentIn == "rand") return cformats::CMD_RANDOM_H;
    if(currentIn == "repeat") return cformats::CMD_REPEAT_H;
    if(currentIn == "about") return cformats::CMD_ABOUT_H;
    if(currentIn == "clear") return cformats::CMD_CLR_H;
    if(currentIn == "quit") return cformats::CMD_QUIT_H;
    if(currentIn == "/f") return cformats::ARG_FORMAT_H;
    if(currentIn == "/?") return cformats::CMD_HELP_H;
    
    return cformats::CMD_INVALID_H;
}


int arg_formatH(vector<string> uStr) 
{
    switch(helpToInt(uStr[1]))
    {
        case cformats::CMD_MATHS_H:
            cout << "FORMAT: maths [add;sub;mult;div] \"num1\" \"num2\"" << '\n';
            break;
            
        case cformats::CMD_RANDOM_H:
            cout << "FORMAT: rand [min-range] [max-range]" << '\n';
            break;
        
        case cformats::CMD_REPEAT_H:
            cout << "FORMAT: repeat \"phrase\" [repeat-amount]" << '\n';
            break;
        
        case cformats::ARG_FORMAT_H:
            cout << "FORMAT: /f <command>" << '\n';
            break;
            
        case cformats::CMD_ABOUT_H:
        case cformats::CMD_QUIT_H:
        case cformats::CMD_HELP_H:
        case cformats::CMD_CLR_H:
            cout << "NO ARGUMENTS FOR COMMAND.\n";
            break;
        
        default:
            cout << "INVALID COMMAND!" << '\n';
            break;
            
    }
    return SUCCESS;
}



