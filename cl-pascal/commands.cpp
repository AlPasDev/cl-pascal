/*===============================================================================
File:        commands.cpp
Project:     cl-pascal
Component:   command runner
Author:      Alexander Pascal (fryman)
Created:     2026-02-25
Last Update: 2026-03-05
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
#include <string_view>
#include <random>
#include <chrono>
#include <ctime>

using namespace std;


//command list string ; string_view
constexpr string_view CL_COMMANDLIST
{
    "help       < Prints the help menu, i.e. this one.\n"
    "about      < Prints the about/version screen\n"
    "maths      < \"maths [add;sub;mult;div] num1 num2\": maths functions for calculations\n"
    "rand       < \"rand [min-range] [max-range]\"        Produces some random numbers from a set range\n"
    "echo       < echo \"phrase\" [repeat-amount]         duplicates the inputted text \n"
    "time       < Shows the current date&time \n"
    "clear      < Clears the screen\n"
    "quit       < quits the application\n"
    "\n\n/f <command>     < Shows the format for each command\n"
    "/?               < Prints the help menu, i.e. this one.\n"
    "devinfo          < Prints the developer info/debug screen\n"
};

/*++
cm_help()
Routine Description:

    help command banner

Arguments:
     
Return Value:
    SUCCESS ; int
Side Effects:

    None.

--*/
int cm_help()
{
    cout << "\nSELECTED: HELP\n";
    cout << "================================\n"
         << "Commands:" << '\n'
         << CL_COMMANDLIST << '\n'
         << "================================\n";
    
    
    return SUCCESS;
}

/*++
cm_random(vector<string> uStr)
Routine Description:

    random command

Arguments:
     
Return Value:
    SUCCESS
Side Effects:

    None.

--*/
int cm_random(const vector<string>& uStr)
{
    if(uStr.size() > 3 || uStr.size() < 3)
    {
        cout << "FORMAT: rand [min-range] [max-range]" << '\n';
        return FAILURE;
    }
    
    int min{};
    int max{};
    
    try
    {
        min = stoi(uStr[1]);
        max = stoi(uStr[2]);
    }
    catch (...)
    {
        cerr << "ERROR: Args must be integers.\n";
        return FAILURE;
    }
    
    if(min > max)
    {
        cerr << "ERROR: [min-range] must not be larger than [max-range]\n";
        return FAILURE;
    }
    
    static random_device rd;
    static mt19937 gen(rd());
    uniform_int_distribution<> dist(min, max);
    
    cout << dist(gen) << '\n';
    
    return SUCCESS;
}


/*++
cm_time()
Routine Description:

    date & time output

Arguments:
     
Return Value:
    SUCCESS ; int
Side Effects:

    None.

--*/
int cm_time()
{
    auto now = chrono::system_clock::now();
    time_t time = chrono::system_clock::to_time_t(now);
    
    cout << ctime(&time);
    return SUCCESS;
}


/*++
cm_clear()
Routine Description:

    clear command

Arguments:
     
Return Value:
    SUCCESS
Side Effects:

    None.

--*/
int cm_clear()
{
    for(int i{0}; i < 50; ++i)
        cout << '\n';
        
    return SUCCESS;
}

/*++
cm_about()
Routine Description:

    about command;

Arguments:
     
Return Value:
    SUCCESS ; int
Side Effects:

    None.

--*/
int cm_about()
{
    openBanner();
    return SUCCESS;
}

/*++
cm_devInfo()
Routine Description:

    developer information command;

Arguments:
     
Return Value:
    SUCCESS ; int
Side Effects:

    None.

--*/
int cm_devInfo()
{
//    auto now = chrono::system_clock::now();
  //  time_t time = chrono::system_clock::to_time_t(now);
    
    cout << "=======================================================================\n"
         << "DEVELOPER INFO / DEBUG INFO" << '\n'
         << CL_NAME << '\n'
         << CL_COPYRIGHT << '\n' << '\n'
         << "Version: "
         << CL_VER << '\n'
         << "STRING INFO: v [version number].[date][month]-[time] [milestone]\n"
         << "Compile Info: " << "\n\n"
         << "Date:           "
         << __DATE__ << "\nTime:           "
         << __TIME__ << '\n'
         << "Branch:         "
         << CL_BRANCH << '\n'
         << "Milestone:      "
         << CL_MILESTONE << '\n'
         << "Compiled by:    "
         << CL_DEVNAME << '\n'
         << "Build Lab:      "
         << CL_BUILDLAB << '\n'
         << "User OS Info:   "
         << CL_USEROS
         << "\n\n\n"
         << "\"/?\" or \"help\" for help" << '\n'
         << "=======================================================================\n";
    
    
    return SUCCESS;
}

/*++
cm_echo()
Routine Description:

    echo command

Arguments:
     
Return Value:
    SUCCESS ; int
Side Effects:

    None.

--*/
int cm_echo(const vector<string>& uStr) //TODO: ...
{
 /*   if(uStr.size() > 2 || uStr.size() < 2)
    {
        cout << "FORMAT: echo \"phrase\" [repeat-amount] " << '\n';
        return FAILURE;
    }
*/
    int argsSize{static_cast<int>(uStr.size())};
    
    for(int i{1}; i < argsSize; ++i)
    {
        cout << uStr[i] << " ";
    }
    cout << '\n';

    return SUCCESS;
}
