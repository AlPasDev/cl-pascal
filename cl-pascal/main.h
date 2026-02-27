//
//  main.h
//  cl-pascal
//
//  Created by Alex Pascal on 2026/02/25.
//
#define cCL_VER 1.0A
#include <string_view>
#include <string>
#include <vector>

constexpr std::string_view CL_NAME{"Pascal Command Line Application"};
constexpr std::string_view CL_VER{"1.26f-0900 alpha"};
constexpr std::string_view CL_COPYRIGHT{"Copyright (c) 2026, Alexander Pascal"};
constexpr std::string_view CL_COPYRIGHT2{"Copyright (c) 2026, PascSoft"};

void openBanner();

std::vector<std::string> sTokenize(std::string uLine);
std::string cl_input();

int cm_help();
int cm_add(std::string_view uStr);
int cm_sub(std::string_view uStr);
int cm_random();
int cm_clear();
int cm_about();
int cm_repeat(std::string_view uStr);
bool cm_quit();
int arg_formatH(std::string_view uStr);
