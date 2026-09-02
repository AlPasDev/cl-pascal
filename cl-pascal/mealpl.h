/*===============================================================================
File:        mealpl.h
Project:     cl-pascal
Component:   Meal Plan Applet Header
Author:      Alexander Pascal (fryman)
Created:     2026-08-30
Last Update: 2026-09-02
Purpose:
             Meal Plan Applet header
Overview:
Notes:
TODO:
===============================================================================*/

void targetWarn(int totMacro, int targetVal, const std::string& macroType);

struct Meal
{
    int inKCal{};
    int inCarb{};
    int inProtein{};
    int inFat{};
};

struct Targets
{
    int kcal{};
    int protein{};
    int carbs{};
    int fat{};
};
