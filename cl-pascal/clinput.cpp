//
//  clinput.cpp
//  cl-pascal
//
//  Created by Alex Pascal on 2026/02/25.
//


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
    string cm_In;
    getline(cin, cm_In);
    
    //string uInFormat{sTokenize(cm_In)};
    
    return cm_In;
}
