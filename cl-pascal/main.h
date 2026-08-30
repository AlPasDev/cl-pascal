/*===============================================================================
File:        main.h
Project:     cl-pascal
Component:   Main util
Author:      Alexander Pascal (fryman)
Created:     2026-02-27
Last Update: 2026-03-13
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

#ifndef FLAGS_H
#define FLAGS_H

extern bool isBugFixActive;

#endif

//const strings
constexpr std::string_view CL_NAME{"Pascal Terminal Application"};
extern std::string CL_VER;
extern std::vector<std::string> cmdHist;
constexpr std::string VERPREFIX{"v1.30au"};
constexpr std::string VERSUFFIX{"M2"};
constexpr std::string_view CL_COPYRIGHT{"Copyright (c) 2026, Alexander Pascal"};
constexpr std::string_view CL_COPYRIGHT2{"Copyright (c) 2026, PascSoft"};
constexpr std::string_view CL_BRANCH{"cl-math"};
constexpr std::string_view CL_DEVNAME{"alpascal"};
constexpr std::string_view CL_BUILDLAB{"MacOS @ Hilton College, South Africa"};
constexpr std::string_view CL_MILESTONE{"M2"};
constexpr std::string_view s_mFormat{"FORMAT: calc [+|-|/|;|%|pow]"};
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
void cl_prompt();

//input function prototypes
std::vector<std::string> sTokenize(std::string uLine);
std::string cl_input();

//meal func prototypes
int cm_meal();


//command function prototypes
int cm_help();
int cm_random(const std::vector<std::string>& uStr);
int cm_clear();
int cm_about();
int cm_time();
int cm_echo(const std::vector<std::string>& uStr);
int cm_newFeats();
int cm_devInfo();
int cm_hist();
bool cm_quit();
int arg_formatH(const std::vector<std::string>& uStr);

//maths func prototypes
double cm_maths(const std::vector<std::string>& uStr);
int cm_mod(const std::vector<std::string>& uStr);
int cm_fact(const std::vector<std::string>& uStr);

//bugfix func prototypes
void cm_bugfix_out();
std::vector<std::string> bugfix_tokenizer(std::string u_bIn);
void bugfix_select();
int bugfix_main(const std::vector<std::string>& uStr);
int bugfix_log();
int bugfix_read();




