/*===============================================================================
File:        clengine.h
Project:     cl-pascal
Component:   Main util
Author:      Alexander Pascal (fryman)
Created:     2026-02-27
Last Update: 2026-02-27
Purpose:
    cl engine header file > enum class for command
Overview:
     
Assumptions:
     uStr > User String
    
Notes:
    
===============================================================================*/

bool cl_run();


enum class command
{
    CMD_HELP,
    CMD_ABOUT,
    CMD_MATHS,
    CMD_RANDOM,
    CMD_REPEAT,
    CMD_CLR,
    CMD_QUIT,
    ARG_FORMAT_H,
    CMD_INVALID
};

enum class cformats
{
    CMD_HELP_H,
    CMD_ABOUT_H,
    CMD_MATHS_H,
    CMD_RANDOM_H,
    CMD_REPEAT_H,
    CMD_CLR_H,
    CMD_QUIT_H,
    ARG_FORMAT_H,
    CMD_INVALID_H
};
