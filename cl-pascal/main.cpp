/*===============================================================================
File:        main.cpp
Project:     cl-pascal
Component:   Main util
Author:      Alexander Pascal (fryman)
Created:     2026-02-25
Last Update: 2026-02-25

Purpose:
    main file
Overview:
     Build a program that behaves like a small terminal.

     Example:

     > help
     > add 5 7
     > random
     > quit

     Program runs in a loop and interprets commands.
     Requirements:

     infinite loop until quit
     read full line input
     if / else command parsing
     functions per command

Assumptions:
    
Notes:
    
===============================================================================*/

#include <iostream>
#include "main.h"

void openBanner()
{
    cout << "================================\n"
         << CL_NAME << '\n'
         << CL_COPYRIGHT << '\n' << '\n'
         << "Version: "
         << CL_VER << '\n'
         << "================================\n";
}
int main(int argc, const char * argv[])
{
    openBanner();
    
  //  do {
  //      cl_run();
  //  } while (!exit());
    
    return EXIT_SUCCESS;
    
}
