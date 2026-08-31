/*===============================================================================
File:        maths.cpp
Project:     cl-pascal
Component:   Mathematics util
Author:      Alexander Pascal (fryman)
Created:     2026-02-27
Last Update: 2026-08-31
Purpose:
             Maths functions + control
Overview:
Notes:       TODO: TOP ; Make the maths project full expression aware 1
===============================================================================*/

#include "main.h"
#include "clengine.h"
#include "maths.h"
#include "headers.h"


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
    if(currentIn == "+") return maths::MATHS_ADD;
    if(currentIn == "-") return maths::MATHS_SUB;
    if(currentIn == "/") return maths::MATHS_DIV;
    if(currentIn == "*") return maths::MATHS_MUL;
    if(currentIn == "!") return maths::MATHS_FACT;
    if(currentIn == "pow") return maths::MATHS_POW;
    if(currentIn == "%") return maths::MATHS_MOD;
    if(currentIn == "sqrt") return maths::MATHS_SQRT;
    
    return maths::MATHS_INV;
}

tempunits tempCmdToEnum(const string_view currentIn)
{
    if(currentIn == "C") return tempunits::TEMP_CELS;
    if(currentIn == "F") return tempunits::TEMP_FAHR;
    if(currentIn == "K") return tempunits::TEMP_KELV;
    
    
    return tempunits::TEMP_INVALID;
}

/*
mTokenType equationParser(const string_view currentIn)
{

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
double cm_maths(const vector<string>& uStr)
{
    bool isSqrt      = (uStr.size() == 3 && uStr[2] == "sqrt"); // "a sqrt"
    bool isBinary    = (uStr.size() == 4);                      // "a op b"
[[maybe_unused]]    bool isFactorial = (uStr.size() == 3 && uStr[2] == "!");

    if (!isSqrt && !isBinary)
    {
        cerr << "INVALID INPUT! " << s_mFormat << '\n';
        return FAILURE;
    }

    double mResult{0}, a{0}, b{0};

    try
    {
        a = stod(uStr[1]);
        if (isBinary) b = stod(uStr[3]);   // only parse b when it exists
    }
    catch (...)
    {
        cerr << "INVALID INPUT! " << s_mFormat << '\n';
        return FAILURE;
    }

    
    
  //  if(!typeCheck(uStr))
  //      break;



    switch (mCmdToEnum(uStr[2])) {
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
            
        case maths::MATHS_FACT:
            mResult = cm_fact(uStr);
            
        case maths::MATHS_POW:
            mResult = pow(a, b);
            break;
        
        case maths::MATHS_SQRT:
            mResult = sqrt(a);
            break;
            
        case maths::MATHS_MOD:
            mResult = cm_mod(uStr);
            
       // case maths::MATHS_MOD: TODO: MAKE A WHOLE NEW FUNCTION
         //   mResult = a % b;
            break;
            
        default:
            cerr << "INVALID INPUT!" << s_mFormat << '\n';
            return FAILURE;
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
int cm_mod(const vector<string>& uStr)
{
   // if(!)
    int modRes{0};  // result of mod %
    int a{};        // num 1
    int b{};        // num 2
    
    try
    {
        a = stoi(uStr[1]);
        b = stoi(uStr[3]);
    }
    catch (...)
    {
        cerr << "INVALID INPUT!" << s_mFormat << '\n';
        return FAILURE;
    }
    
    modRes = a%b;
    
    return modRes;
}

/*++
cm_fact(vector<string> uStr)
Routine Description:

    factorial function

Arguments:
    vector<string> uStr
Return Value:
    int ; factTotal; factorial result
Side Effects:

    None.

--*/

//TODO: FACTORIAL
int cm_fact(const vector<string>& uStr)
{
    int factTotal{0};
    int a{};
    
    try
    {
        a = stoi(uStr[1]);
    }
    catch (...)
    {
        cerr << "INVALID INPUT!" << s_mFormat << '\n';
        return FAILURE;
    }
    
    for(int x = a; x > 1; x--)
    {
        factTotal *= x;
    }
    
    return factTotal;
}

/*++
cm_temp()
Routine Description:

    temp converter calc

Arguments:
    const vector<string>& uStr
Return Value:
    SUCCESS ; int
Side Effects:

    None.

--*/
int cm_temp(const vector<string>& uStr) //TODO: ...
{
    
    [[maybe_unused]] int argsSize{static_cast<int>(uStr.size())};
    if(uStr.size() != 4)
    {
        cout << s_tempFormat << '\n';
        return FAILURE;
    }

    double origTemp{stod(uStr[1])};
    double tempResult{0};
    
    switch (tempCmdToEnum(uStr[2])) {
        case tempunits::TEMP_CELS:
            if(uStr[3] == "F")
            {
                tempResult = (origTemp * 1.8) + 32;
            }
            else if (uStr[3] == "K")
            {
                tempResult = (origTemp + 273.15);
            }
            break;
            
        case tempunits::TEMP_FAHR:
            if(uStr[3] == "C")
            {
                tempResult = (origTemp - 32) / 1.8;
            }
            else if (uStr[3] == "K")
            {
                tempResult = (origTemp + 459.67)/1.8;
            }
            break;
            
        case tempunits::TEMP_KELV:
            if(uStr[3] == "F")
            {
                tempResult = (origTemp * 1.8) - 459.67;
            }
            else if (uStr[3] == "C")
            {
                tempResult = origTemp - 273.15;
            }
            break;
            
        default:
            cerr << "INVALID INPUT!" << s_tempFormat << '\n';
            return FAILURE;
            break;
    }
    
    cout << origTemp << " degrees " << uStr[2] << " is " << tempResult << " degrees " << uStr[3] << '\n';
    
    return SUCCESS;
}
