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
Notes:
=================================================================================*/

#define cCL_VER "1.0A"
#define DEBUG 1

#include <string_view>
#include <string>
#include <vector>

//const strings
constexpr std::string_view CL_NAME{"Pascal Terminal Application"};
constexpr std::string_view CL_VER{"v1.13m-0030 M1"};
constexpr std::string_view CL_COPYRIGHT{"Copyright (c) 2026, Alexander Pascal"};
constexpr std::string_view CL_COPYRIGHT2{"Copyright (c) 2026, PascSoft"};
constexpr std::string_view CL_BRANCH{"cl-math"};
constexpr std::string_view CL_DEVNAME{"alpascal"};
constexpr std::string_view CL_BUILDLAB{"MacOS @ Hilton College, South Africa"};
constexpr std::string_view CL_MILESTONE{"M1"};
constexpr std::string_view s_mFormat{"FORMAT: maths [+|-|/|;|%|pow]"};
constexpr std::string_view s_rFormat{"FORMAT: rand [min-range] [max-range] [gen amount] [generator type]"};

#if defined(_WIN32)
constexpr std::string_view CL_USEROS{"WIN32 ; Windows"};

#elif defined(__APPLE__)
constexpr std::string_view CL_USEROS{"OSX"};
#elif defined(__linux__)
constexpr std::string_view CL_USEROS{"LINUX"};

#elif defined(__unix__)
constexpr std::string_view CL_USEROS{"UNIX"};

#else
constexpr std::string_view CL_USEROS{"UNKNOWN OS NAME"};

#endif

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
int cm_random(const std::vector<std::string>& uStr);
int cm_clear();
int cm_about();
int cm_time();
int cm_echo(const std::vector<std::string>& uStr);
int cm_newFeats();
int cm_devInfo();
bool cm_quit();
int arg_formatH(const std::vector<std::string>& uStr);

//maths func prototypes
double cm_maths(const std::vector<std::string>& uStr);
int cm_mod(const std::vector<std::string>& uStr);
