/*===============================================================================
File:        maths.cpp
Project:     cl-pascal
Component:   Mathematics util
Author:      Alexander Pascal (fryman)
Created:     2026-02-27
Last Update: 2026-02-27
Purpose:
    Maths functions + control
Overview:
     
Assumptions:
     uStr > User String
    
Notes:
===============================================================================*/

#include "main.h"
#include "clengine.h"
#include "maths.h"
#include <iostream>
#include <sstream>
#include <string_view>

using namespace std;

maths mCmdToEnum(const string_view currentIn)
{
    if(currentIn == "add") return maths::MATHS_ADD;
    if(currentIn == "sub") return maths::MATHS_SUB;
    if(currentIn == "div") return maths::MATHS_DIV;
    if(currentIn == "mul") return maths::MATHS_MUL;
    
    return maths::MATHS_SUB;
}

int cm_maths(std::vector<std::string> uStr)
{
    int mResult{0};
    int a = stoi(uStr[2]);
    int b = stoi(uStr[3]);
    
    switch (mCmdToEnum(uStr[1])) {
        case maths::MATHS_ADD:
            mResult = a + b;
            break;
        case maths::MATHS_SUB:
            mResult = a - b;
            break;
        case maths::MATHS_DIV:
            mResult = a/b;
            break;
        case maths::MATHS_MUL:
            mResult = a*b;
            break;
            
        default:
            break;
    }
    
    return mResult;
}
