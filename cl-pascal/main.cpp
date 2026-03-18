/*===============================================================================
File:         main.cpp
Project:      cl-pascal
Component:    Main util
Author:       Alexander Pascal (fryman)
Created:      2026-02-25
Last Update:  2026-03-13
Version:      M1
Purpose:
              main file
Overview:
              Terminal Applet
Notes:
              
TODO:         TOP ; Make the maths project full expression aware 0
TODO:         make token quote aware 3
================================================================================*/

#include "main.h"
#include "clengine.h"
#include "headers.h"
#include "about.h"

std::string CL_VER{""};

using namespace std;

constexpr char build_HHMM[] =
{
    __TIME__[0],
    __TIME__[1],
    __TIME__[3],
    __TIME__[4],
};

void getBuildNum()
{
        CL_VER = VERPREFIX + "-" + build_HHMM + " " + VERSUFFIX;
}


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
    getBuildNum();
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
    showAboutBox();
    system("osascript -e 'tell application \"Terminal\" to close front window'");
#elif defined(__WIN32)
    system("exit");
    return EXIT_SUCCESS;
#endif
    
}
