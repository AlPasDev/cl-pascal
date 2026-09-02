/*===============================================================================
File:        maths.h
Project:     cl-pascal
Component:   Mathematics Header
Author:      Alexander Pascal (fryman)
Created:     2026-02-27
Last Update: 2026-09-02
Purpose:
             Maths header
Overview:
Assumptions:
Notes:
             TODO: TOP ; Make the maths project full expression aware
===============================================================================*/


enum class maths
{
    MATHS_ADD,
    MATHS_SUB,
    MATHS_DIV,
    MATHS_MUL,
    MATHS_POW,
    MATHS_MOD,  //TODO: .
    MATHS_SQRT, //TODO: .
    MATHS_FACT,
    MATHS_INV
};

enum class tempunits
{
    TEMP_CELS,
    TEMP_FAHR,
    TEMP_KELV,
    TEMP_INVALID
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

struct Coordinate
{
    double x{};
    double y{};
};
