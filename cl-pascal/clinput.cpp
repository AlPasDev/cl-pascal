/*===============================================================================
File:        clinput.cpp
Project:     cl-pascal
Component:   Main util
Author:      Alexander Pascal (fryman)
Created:     2026-02-27
Last Update: 2026-03-03
Purpose:
             Input control
Overview:
Assumptions:
Notes:
===============================================================================*/


#include "headers.h"

#include "main.h"
#include "clengine.h"
using namespace std;

/*++
sTokenize(string uLine)
Routine Description:

    tokenize the user string

Arguments:
     uLine
Return Value:
    tokens ; string
Side Effects:

    None.

--*/
vector<string> sTokenize(string uLine)
{
    vector<string> tokens;     //tokens from string
    istringstream iss(uLine);  //string stream from uLine
    
    string word;               //word from tokens
    
    while(iss >> word)
    {
        tokens.push_back(word);
    }
    
    return tokens;
}

/*++
cl_input()
Routine Description:

    user input function
 
Arguments:
     
Return Value:
    cm_In . string
Side Effects:

    None.

--*/
string cl_input()
{
ENTER:
    string cm_In;
    getline(cin, cm_In);
    
    if(cm_In.empty())
        goto ENTER;
    
    //string uInFormat{sTokenize(cm_In)};
    
    return cm_In;
}
