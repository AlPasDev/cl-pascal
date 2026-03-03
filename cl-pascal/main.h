/*===============================================================================
File:        main.h
Project:     cl-pascal
Component:   Main util
Author:      Alexander Pascal (fryman)
Created:     2026-02-27
Last Update: 2026-03-03
Purpose:
    main header file
Overview:
Assumptions:
     uStr > User String
 
Notes:
=================================================================================*/

#define cCL_VER "1.0A"

#include <string_view>
#include <string>
#include <vector>

//const strings
constexpr std::string_view CL_NAME{"Pascal Command Line Application"};
constexpr std::string_view CL_VER{"v1.03m-1108 beta"};
constexpr std::string_view CL_COPYRIGHT{"Copyright (c) 2026, Alexander Pascal"};
constexpr std::string_view CL_COPYRIGHT2{"Copyright (c) 2026, PascSoft"};

constexpr int SUCCESS{0};
constexpr int FAILURE{1};

//banner/main running func prototypes
void openBanner();
void exitMsg();

//input function prototypes
std::vector<std::string> sTokenize(std::string uLine);
std::string cl_input();

//command function prototypes
int cm_help();
int cm_random(std::vector<std::string> uStr);
int cm_clear();
int cm_about();
int cm_echo(std::vector<std::string> uStr);
bool cm_quit();
int arg_formatH(std::vector<std::string> uStr);

//maths func prototypes
double cm_maths(std::vector<std::string> uStr);
int cm_mod(std::vector<std::string> uStr);
