/*===============================================================================
File:        main.cpp
Project:     cl-pascal
Component:   Main util
Author:      Alexander Pascal (fryman)
Created:     2026-02-25
Last Update: 2026-03-05
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
        TOP ; Make the maths project full expression aware
        
        make token quote aware 3
        run management 3
 
===============================================================================*/

#include "main.h"
#include "clengine.h"
#include "headers.h"

using namespace std;


/*++
openBanner()
Routine Description:

    prints the welcome banner for CL

Arguments:
Return Value:
    void
Side Effects:

    None.

--*/
void openBanner()
{
    cout << "=======================================================================\n"
         << CL_NAME << '\n'
         << CL_COPYRIGHT << '\n' << '\n'
         << "Version: "
         << CL_VER << '\n'
         << "\"/?\" or \"help\" for help" << '\n'
         << "\"devinfo\" for developer/debug info" << '\n'
         << "=======================================================================\n";
}

/*++
exitMsg()
Routine Description:

    prints the exit msg

Arguments:
Return Value:
    void
Side Effects:

    None.

--*/
void exitMsg()
{
    cout << "Thank you! - AP \n";
}

/*++
main(int argc, const char * argv[])
Routine Description:

    main function loop

Arguments:
    int argc, const char * argv[]
Return Value:
    int ; EXIT_SUCCESS;
Side Effects:

    None.

--*/
int main(int argc, const char * argv[])
{
#if DEBUG
    std::cout << "Executable path: " << argv[0] << '\n';
#endif
    openBanner();
    
    do
    {
        cl_run();
    } while (cm_quit() != true);
    
    exitMsg();

#if defined(__APPLE__)
  //  kill(getpid(), SIGKILL);
    system("osascript -e 'tell application \"Terminal\" to close front window'");
#elif defined(__WIN32)
    system("exit");
    return EXIT_SUCCESS;
#endif
    
}
