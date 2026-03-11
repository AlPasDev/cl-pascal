/*===============================================================================
File:        maths.h
Project:     cl-pascal
Component:   Mathematics Header
Author:      Alexander Pascal (fryman)
Created:     2026-02-27
Last Update: 2026-03-03
Purpose:
    Maths header
Overview:
     
Assumptions:
     uStr > User String
    
Notes:
 TODO: TOP ; Make the maths project full expression aware
===============================================================================*/


enum class maths
{
    MATHS_ADD,
    MATHS_SUB,
    MATHS_DIV,
    MATHS_MUL,
    MATHS_POW, //TODO: .
    MATHS_MOD, //TODO: .
    MATHS_SQRT,
    MATHS_INV
};

enum class mTokenType
{
    number,
    plus,
    minus,
    star,
    slash,
    pow,
    leftparen,
    rightparen,
    end
};
