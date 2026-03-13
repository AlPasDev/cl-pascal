/*===============================================================================
File:        bugfix.cpp
Project:     cl-pascal
Component:   BUGFIX ; a simple bug reporter
Author:      Alexander Pascal (fryman)
Created:     2026-03-13
Last Update: 2026-03-13
Version:     m1
Purpose:
             bugfix main
Overview:
Notes:
================================================================================*/

#include "main.h"
#include "headers.h"
#include "bugfix.h"
using namespace std;

vector<string> b_fIn{};
vector<string> bugOrFeatLog{};  //vector used for file logging
string reqType{};
string issueTitle{};
string issueDesc{};
string issueType{};

string fTitle{};
string fDesc{};

time_t issueNumGen{};

char flagType{};


/*++
cm_bugfix()
Routine Description:

    main bugfix func
 
Arguments:
     
Return Value:
    void
Side Effects:

    None.

--*/
void cm_bugfix_out()
{
    
    cout << "BUGFIX IS UNDER CONSTRUCTION ; Version: " << CL_VER << "\n\n";
    cout << "\n\n==Select Bug (b) or Feature (f), Enter Your Bug, and Description==\n";
    
}


/*++
issue_req()
Routine Description:

    request feature

Arguments:
     
Return Value:
    void
Side Effects:

    None.

--*/
void feat_req()
{
    cl_prompt();
    getline(cin, issueTitle);
    
    //bugOrFeatLog.push_back(fTitle);
    
    cl_prompt();
    getline(cin, issueDesc);
   // bugOrFeatLog.push_back(fDesc);

}


/*++
bugfix_select()
Routine Description:

    select bug or feature

Arguments:
     
Return Value:
    void
Side Effects:

    None.

--*/
//UNNEEDED NOW
void bugfix_select()
{
    getline(cin, reqType);
    
    if(reqType == "b")
    {
        issueType = "bug";
    }
    else if (reqType == "f")
    {
        issueType = "feature";
    }
    else
    {
        issueType = "unspecified";
    }
}

/*++
bugLog()
Routine Description:

    log the bug in file; for send

Arguments:
     
Return Value:
    void
Side Effects:

    None.

--*/
//UNNEEDED NOW

void bugLog()
{
    
}

/*++
featLog()
Routine Description:

    log the feat in file; for send

Arguments:
     
Return Value:
    void
Side Effects:

    None.

--*/

void featLog()
{
    
}

/*++
 bugfix_main()
Routine Description:

    main routine for bugfix

Arguments:
     
Return Value:
    SUCCESS : int
Side Effects:

    None.

--*/

int bugfix_main()
{
    cm_bugfix_out();
    bugfix_select();
    
    feat_req();
    
    auto now = chrono::system_clock::now();
    issueNumGen = chrono::system_clock::to_time_t(now);
    
    
    cout << "Thank you for reporting. \n";
    cout << "ISSUE LOGGED #:" << issueNumGen << "\n\n\n";
    
    bugfix_log();
    
    return SUCCESS;;
}


int bugfix_log()
{
    std::ofstream file("bugfix.txt", ios::app);

    if (!file)
    {
        std::cout << "File failed\n";
        return 1;
    }

    file << "NUMBER: " << issueNumGen << '\n';
    file << "TYPE:   " << issueType << '\n';
    file << "TITLE:  " << issueTitle << '\n';
    file << "DESC:   " << issueDesc << '\n';
    file << "-----------------\n";
    
    return SUCCESS;
}
