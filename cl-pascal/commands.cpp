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
#include "headers.h"

using namespace std;


//command list string ; string_view
constexpr string_view CL_COMMANDLIST
{
    "help       < Prints the help menu, i.e. this one.\n"
    "about      < Prints the about/version screen\n"
    "new        < Prints what's new in this version\n"
    "maths      < maths [+|-|/|*|pow|sqr]:                                    maths functions for calculations\n"
    "rand       < rand [min-range] [max-range] [gen amount] [generator type]: Produces random nums from range. /f the command for types.\n"
    "echo       < echo \"phrase\" [repeat-amount]:                            duplicates the inputted text \n"
    "time       < Shows the current date&time \n"
    "clear      < Clears the screen\n"
    "quit       < quits the application\n"
    "\n\n/f <command>     < Shows the format for each command\n"
    "/? or ?          < Prints the help menu, i.e. this one.\n"
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
    
    static random_device rd;
    uniform_int_distribution<> dist(min, max);
    
    for(int i{0}; i < gen_amt; ++i)
    {
        switch (optToRNG(uStr[4])) {
            case RNG::opt_mt19937:
                
                static mt19937 genM(rd());
                cout << dist(genM);

                break;
                
            case RNG::opt_default:
                
                static default_random_engine genD(rd());
                cout << dist(genD);

                break;
                
            case RNG::opt_ranlux24:
                
                static ranlux24 genR(rd());
                cout << dist(genR);

                break;
                
            case RNG::opt_knuth_b:
                
                static knuth_b genK(rd());
                cout << dist(genK);

                break;
                
            case RNG::opt_minstd_rand:
                
                static minstd_rand genMi(rd());
                cout << dist(genMi);
                
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
         << "What's New?:          \n "
         << "- created options for rand command.\n"
         << "- Added symbol control for maths (ported to rtm).\n"
         << "- Added a what's new menu.\n"
         << "\n\n\n"
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

