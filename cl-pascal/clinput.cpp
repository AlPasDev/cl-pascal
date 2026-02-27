/*===============================================================================
File:        clinput.cpp
Project:     cl-pascal
Component:   Main util
Author:      Alexander Pascal (fryman)
Created:     2026-02-27
Last Update: 2026-02-27
Purpose:
    Input control
Overview:
     
Assumptions:
     uStr > User String
    
Notes:
===============================================================================*/


#include <iostream>
#include <sstream>
#include <string>
#include <string_view>
#include <vector>

#include "main.h"
#include "clengine.h"
using namespace std;

vector<string> sTokenize(string uLine)
{
    vector<string> tokens;
    istringstream iss(uLine);
    
    string word;
    
    while(iss >> word)
    {
        tokens.push_back(word);
    }
    
    return tokens;
}

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
