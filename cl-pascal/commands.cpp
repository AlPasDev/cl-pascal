/*===============================================================================
File:        commands.cpp
Project:     cl-pascal
Component:   command runner
Author:      Alexander Pascal (fryman)
Created:     2026-02-25
Last Update: 2026-08-31
Purpose:
             functions for each command
Overview:
             help
             about
             new
             calc
             rand
             echo
             time
             clear
             quit
             f <command>
             /? or ?
             devinfo
TODO:        bugfix
             
Assumptions:
Notes:
 
BUG-009  High  Open  echo's documented repeat-amount feature not implemented
 
===============================================================================*/
#include "main.h"
#include "clengine.h"
#include "headers.h"

using namespace std;


//command list string ; string_view
constexpr string_view CL_COMMANDLIST
{
    "help       < Prints the help menu, i.e. this one.\n"
    "about      < Prints the about/version screen\n"
//    "tabout     < Pop-ups the about/version screen\n"
    "new        < Prints what's new in this version\n"
    "calc       < calc [+|-|/|*|pow|sqr]: maths functions for calculations <under construction>\n"
    "rand       < rand [min-range] [max-range] [gen amount] [generator type]\n"
    "             Produces random nums from range. /f the command for types.\n"
    "echo       < echo \"phrase\" [repeat-amount]\n"
    "             duplicates the inputted text \n"
    "time       < Shows the current date&time \n"
    "clear      < Clears the screen\n"
    "hist       < Shows the history of commands used.\n"
    "temp       < Converts Cels, Fahr, Kelv.\n"
    "macro      < Macro Meal Tracker Applet\n"
    "quit       < quits the application\n"
    "\n\n/f <command>     < Shows the format for each command\n"
    "/? or ?          < Prints the help menu, i.e. this one.\n"
    "devinfo          < Prints the developer info/debug screen\n"
    "bugfix           < reporting issues & feature requests <under construction>\n"
    "                 < /r to read history of bugfix.\n"
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

RNG optToRNG(const string_view cIn)
{
    if(cIn == "lcg") return RNG::opt_minstd_rand;
    if(cIn == "mt") return RNG::opt_mt19937;
    if(cIn == "s&c") return RNG::opt_ranlux24;
    if(cIn == "slcg") return RNG::opt_knuth_b;
    if(cIn == "default") return RNG::opt_default;
    if(cIn == "\n") return RNG::opt_default;
    if(cIn == " ") return RNG::opt_default;
    
    return RNG::opt_default;
}


/*++
cm_random(vector<string> uStr)
Routine Description:

    random command

Arguments:
     
Return Value:
    SUCCESS
Notes:
    minstd_rand
    mt19937
    ranlux24
    knuth_b
    default
--*/
int cm_random(const vector<string>& uStr)
{
    if(uStr.size() != 5)
    {
        cout << s_rFormat << '\n';
        return FAILURE;
    }
    
    int min{};        //min range
    int max{};        //max range
    int gen_amt{};    //gen amount
    
    try
    {
        min = stoi(uStr[1]);
        max = stoi(uStr[2]);
        gen_amt = stoi(uStr[3]);
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
    
    RNG opt = optToRNG(uStr[4]);
        
    static random_device rd;
    uniform_int_distribution<> dist(min, max);
    
    for(int i{0}; i < gen_amt; ++i)
    {
        switch (opt) {
            case RNG::opt_mt19937:
                
                static mt19937 gen_mt19937(rd());
                cout << dist(gen_mt19937);

                break;
                
            case RNG::opt_default:
                
                static default_random_engine gen_default_random_engine(rd());
                cout << dist(gen_default_random_engine);

                break;
                
            case RNG::opt_ranlux24:
                
                static ranlux24 gen_ranlux24(rd());
                cout << dist(gen_ranlux24);

                break;
                
            case RNG::opt_knuth_b:
                
                static knuth_b gen_knuth_b(rd());
                cout << dist(gen_knuth_b);

                break;
                
            case RNG::opt_minstd_rand:
                
                static minstd_rand gen_minstd_rand(rd());
                cout << dist(gen_minstd_rand);
                
                break;
                
            default:
                cerr << "INVALID RNG OPTION" << '\n';
                break;
        }
        
        if(i != gen_amt - 1)
            cout << ' ';
        
        if((i + 1) % 10 == 0)
            cout << '\n';
        
    }
    cout << '\n';
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
cm_hist()
Routine Description:

    Prints History of Commands

Arguments:
     
Return Value:
    SUCCESS ; int
Side Effects:

    None.

--*/
int cm_hist()
{
    cout << "Command: \n";
    for(int i{0}; i < cmdHist.size(); ++i)
    {
        cout << cmdHist[i] << '\n';
    }
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
cm_newFeats()
Routine Description:

    new features ~ command;

Arguments:
     
Return Value:
    SUCCESS ; int
Side Effects:

    None.

--*/
int cm_newFeats()
{
    cout << "=======================================================================\n"
         << "Version: "
         << CL_VER << " - Pre-Release"<<'\n'
         << "What's New?:          \n"
         << "- Added \"hist\" command.\n"
         << "\n\n\n"
         << "Type \"bugfix\" for reporting issues & feature requests." << '\n'
         << "\"/?\" or \"help\" for help" << '\n'
         << "=======================================================================\n";
    
    
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

