/*===============================================================================
File:        maths.cpp
Project:     cl-pascal
Component:   Mathematics util
Author:      Alexander Pascal (fryman)
Created:     2026-02-27
Last Update: 2026-03-03
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

/*++
mCmdToEnum(const string_view currentIn)
Routine Description:

    convert the user input to enum type for commands

Arguments:
    const string_view currentIn
Return Value:
    maths ; MATHS_INV;
Side Effects:

    None.

--*/
maths mCmdToEnum(const string_view currentIn)
{
    if(currentIn == "add") return maths::MATHS_ADD;
    if(currentIn == "sub") return maths::MATHS_SUB;
    if(currentIn == "div") return maths::MATHS_DIV;
    if(currentIn == "mul") return maths::MATHS_MUL;
    if(currentIn == "pow") return maths::MATHS_POW;
    if(currentIn == "mod") return maths::MATHS_MOD;
    
    return maths::MATHS_INV;
}

/*
bool typeCheck(vector<string> uStr)
{
    istringstream iss(uStr);
    float test;
    
    if(!(iss >> test))
        return FAILURE;
}
*/
/*++
cm_maths(vector<string> uStr)
Routine Description:

    maths function
 
Arguments:
    vector<string> uStr ; user string
Return Value:
    double mResult; ; result for maths
Side Effects:

    None.

--*/
double cm_maths(vector<string> uStr)
{
    if(uStr.size() > 4 || uStr.size() < 4)
    {
        cout << "FORMAT: maths [add;sub;mult;div;mod;pow] \"num1\" \"num2\"" << '\n';
        return FAILURE;
    }
    
  //  if(!typeCheck(uStr))
  //      break;

    double mResult{0};      // result of maths
    double a{0};            // num1
    double b{0};            // num2
    
    try //Try to convert string to double
    {
        a = stod(uStr[2]);
        b = stod(uStr[3]);
    }
    catch (...)
    {
        cout << "INVALID INPUT! FORMAT: maths [add;sub;mult;div;mod;pow] \"num1\" \"num2\"" << '\n';
        return FAILURE;
    }
        
    switch (mCmdToEnum(uStr[1])) {
        case maths::MATHS_ADD:
            mResult = a + b;
            break;
            
        case maths::MATHS_SUB:
            mResult = a - b;
            break;
            
        case maths::MATHS_DIV:
            if(b == 0)
            {
                cout << "INVALID: DIVIDE BY ZERO ERROR\n\n";
                break;
            }
            mResult = a/b;
            break;
            
        case maths::MATHS_MUL:
            mResult = a*b;
            break;
            
        case maths::MATHS_POW:
            mResult = pow(a, b);
            break;
        
        case maths::MATHS_MOD:
            mResult = cm_mod(uStr);
            
       // case maths::MATHS_MOD: TODO: MAKE A WHOLE NEW FUNCTION
         //   mResult = a % b;
           // break;
            
        default:
            break;
    }
    
    return mResult;
}

/*++
cm_mod(vector<string> uStr)
Routine Description:

    modulus function

Arguments:
    vector<string> uStr
Return Value:
    int ; modRes; modulus result
Side Effects:

    None.

--*/
int cm_mod(vector<string> uStr)
{
   // if(!)
    int modRes{0};  // result of mod %
    int a{};        // num 1
    int b{};        // num 2
    
    try
    {
        a = stoi(uStr[2]);
        b = stoi(uStr[3]);
    }
    catch (...)
    {
        cout << "INVALID INPUT! FORMAT: maths [add;sub;mult;div;mod;pow] \"num1\" \"num2\"" << '\n';
        return FAILURE;
    }
    
    modRes = a%b;
    
    return modRes;
}
