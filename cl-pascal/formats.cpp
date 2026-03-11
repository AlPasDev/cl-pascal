//
//  formats.cpp
//  cl-pascal
//
//  Created by Alex Pascal on 2026/03/09.
//
#include "main.h"
#include "clengine.h"
#include <iostream>
#include <sstream>
#include <string_view>
#include <random>
#include <chrono>
#include <ctime>

using namespace std;


/*++
helpToInt(const string_view currentIn)
Routine Description:

    help command to enum type

Arguments:
    const string_view currentIn
Return Value:
    command::CMD_INVALID_H;
Side Effects:

    None.

--*/
cformats helpToInt(const string_view currentIn)
{
    if(currentIn == "help") return cformats::CMD_HELP_H;
    if(currentIn == "maths") return cformats::CMD_MATHS_H;
    if(currentIn == "rand") return cformats::CMD_RANDOM_H;
    if(currentIn == "echo") return cformats::CMD_ECHO_H;
    if(currentIn == "devinfo") return cformats::CMD_DEVINFO_H;
    if(currentIn == "about") return cformats::CMD_ABOUT_H;
    if(currentIn == "clear") return cformats::CMD_CLR_H;
    if(currentIn == "time") return cformats::CMD_TIME_H;
    if(currentIn == "quit") return cformats::CMD_QUIT_H;
    if(currentIn == "/f") return cformats::ARG_FORMAT_H;
    if(currentIn == "/?") return cformats::CMD_HELP_H;
    
    return cformats::CMD_INVALID_H;
}

/*++
arg_formatH(vector<string> uStr)
Routine Description:

    format finder for command
 
Arguments:
     
Return Value:
    SUCCESS
Side Effects:

    None.

--*/
int arg_formatH(const vector<string>& uStr)
{
    if(uStr.size() > 2 || uStr.size() < 2)
    {
        cout << "FORMAT: /f <command> " << '\n';
        return FAILURE;
    }
    switch(helpToInt(uStr[1]))
    {
        case cformats::CMD_MATHS_H:
            cout << "FORMAT: maths [add;sub;mult;div] \"num1\" \"num2\"" << '\n';
            break;
            
        case cformats::CMD_RANDOM_H:
            cout << "FORMAT: rand [min-range] [max-range]" << '\n';
            break;
        
        case cformats::CMD_ECHO_H:
            cout << "FORMAT: echo \"phrase\" [repeat-amount]" << '\n';
            break;
        
        case cformats::ARG_FORMAT_H:
            cout << "FORMAT: /f <command>" << '\n';
            break;
            
        case cformats::CMD_ABOUT_H:
        case cformats::CMD_QUIT_H:
        case cformats::CMD_HELP_H:
        case cformats::CMD_TIME_H:
        case cformats::CMD_CLR_H:
        case cformats::CMD_DEVINFO_H:
            cout << "NO ARGUMENTS FOR COMMAND.\n";
            break;
        
        default:
            cout << "INVALID COMMAND!" << '\n';
            break;
            
    }
    return SUCCESS;
}



