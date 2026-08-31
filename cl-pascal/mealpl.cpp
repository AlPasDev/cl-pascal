/*===============================================================================
File:        mealpl.cpp
Project:     cl-pascal
Component:   Macro Tracker Applet
Author:      Alexander Pascal (fryman)
Created:     2026-08-30
Last Update: 2026-08-31
Purpose:
             Macro Tracker Applet functions + control
Overview:
             Ported from Macro Tracker Project
Notes:
TODO:        Make a proper exit condition/input 0
TODO:        Remake as Command Util Standards 3
===============================================================================*/

#include "main.h"
#include "clengine.h"
#include "headers.h"
#include "mealpl.h"

using namespace std;

constexpr int targetKCal{3300};

constexpr int targetProteinMin{150};
[[maybe_unused]] constexpr int targetProteinMax{170};

constexpr int targetCarbsMin{400};
[[maybe_unused]] constexpr int targetCarbsMax{450};
constexpr int maxMealEntries{100};

/*++
cm_meal()
Routine Description:

    meal plan command function

Arguments:
     
Return Value:
    SUCCESS ; int
Side Effects:

    None.

--*/
int cm_meal()
{
    int kCalTot{};
    int carbTot{};
    int proteinTot{};
    
    int inKCal{};
    int inCarb{};
    int inProtein{};
    
    cout << "Welcome Alexander.\n";
    
    for(int x = 1; x <= maxMealEntries; ++x)
    {
        cout << "Enter meal no. " << x << " Macros:\n";
        cin >> inKCal >> inProtein >> inCarb;
        if(inKCal == 0)
        {
            break;
        }
        
        kCalTot     += inKCal;
        carbTot     += inCarb;
        proteinTot  += inProtein;
        
        cout << "Current Macros:\nkcals: " << kCalTot << " protein: " << proteinTot << " carbs: " << carbTot << '\n';
        
        targetWarn(kCalTot, targetKCal, "KCal");
        targetWarn(proteinTot, targetProteinMin, "Protein");
        targetWarn(carbTot, targetCarbsMin, "Carbs");
    }
    
    cout << "Final Macros Data: kcals: " << kCalTot << " protein: " << proteinTot << " carbs: " << carbTot << '\n';
    
    return SUCCESS;
}


/*++
targetWarn()
Routine Description:

    Warning Options for macros that have not reached target..

Arguments:
    int totMacro, int targetVal, const std::string& macroType
Return Value:
    VOID
Side Effects:

    None.

--*/

void targetWarn(int totMacro, int targetVal, const std::string& macroType)
{
    if(totMacro < targetVal)
    {
        cout << "Warning: " << macroType << " target is not reached!\n";
    }
}
