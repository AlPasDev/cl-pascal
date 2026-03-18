/*===============================================================================
File:        maths.cpp
Project:     cl-pascal
Component:   Mathematics util
Author:      Alexander Pascal (fryman)
Created:     2026-02-27
Last Update: 2026-03-11
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
    if(currentIn == "pow") return maths::MATHS_POW;
    if(currentIn == "%") return maths::MATHS_MOD;
    if(currentIn == "sqrt") return maths::MATHS_SQRT;
    
    return maths::MATHS_INV;
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
    if(uStr.size() > 4 || uStr.size() < 4)
    {
        cout << s_mFormat << '\n';
        return FAILURE;
    }
    
    
  //  if(!typeCheck(uStr))
  //      break;

    double mResult{0};      // result of maths
    double a{0};            // num1
    double b{0};            // num2
    
    try //Try to convert string to double
    {
        a = stod(uStr[1]);
        b = stod(uStr[3]);
    }
    catch (...)
    {
        cerr << "INVALID INPUT! " << s_mFormat << '\n';
        return FAILURE;
    }
        
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
            
        case maths::MATHS_POW:
            mResult = pow(a, b);
            break;
        
       // case maths::MATHS_SQRT:
       //     mathsSqrt(
        //    break;
            
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
