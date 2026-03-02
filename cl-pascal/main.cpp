/*===============================================================================
File:        main.cpp
Project:     cl-pascal
Component:   Main util
Author:      Alexander Pascal (fryman)
Created:     2026-02-25
Last Update: 2026-02-27
Purpose:
    main file
Overview:
     Build a program that behaves like a small terminal.
     Example:

     > help
     > maths add 5 7
     > random
     > quit
 
     Program runs in a loop and interprets commands.
     Requirements:
 
     infinite loop until quit
     read full line input
     if / else command parsing
     functions per command

Assumptions:
     uStr > User String 
    
Notes:
    TODO:
        random
        repeat
        run management
        add comments
        CHECK IF EMPTY
        MATHS_SQR
        MATHS_MOD
===============================================================================*/

#include <iostream>
#include "main.h"
#include "clengine.h"

using namespace std;


void openBanner()
{
    cout << "================================\n"
         << CL_NAME << '\n'
         << CL_COPYRIGHT << '\n' << '\n'
         << "Version: "
         << CL_VER << '\n'
         << "\"/?\" or \"help\" for help" << '\n'
         << "================================\n";
}

void exitMsg()
{
    cout << "Thank you! - AP \n";
}


int main(int argc, const char * argv[])
{
    openBanner();
    
    do
    {
        cl_run();
    } while (cm_quit() != true);
    
    exitMsg();
    
    return EXIT_SUCCESS;
    
}
