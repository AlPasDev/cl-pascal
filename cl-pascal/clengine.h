/*===============================================================================
File:        clengine.h
Project:     cl-pascal
Component:   Main util
Author:      Alexander Pascal (fryman)
Created:     2026-02-27
Last Update: 2026-03-03
Purpose:
    cl engine header file > enum class for command
Overview:
     
Assumptions:
     uStr > User String
    
Notes:
    
 ===============================================================================*/
#include "wrapper.h"
bool cl_run();

struct command
{
    std::string name;
    int (*handler)(const std::vector<std::string>&);
};


enum class cformats
{
    CMD_HELP_H,
    CMD_ABOUT_H,
    CMD_MATHS_H,
    CMD_MOD_H,
    CMD_RANDOM_H,
    CMD_ECHO_H,
    CMD_CLR_H,
    CMD_MEAL_H,
    CMD_TIME_H,
    CMD_QUIT_H,
    ARG_FORMAT_H,
    CMD_DEVINFO_H,
    CMD_INVALID_H
};

enum class RNG
{
    opt_minstd_rand,
    opt_mt19937,
    opt_ranlux24,
    opt_knuth_b,
    opt_default
};
