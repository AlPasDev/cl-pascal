/*===============================================================================
File:        wrapper.cpp
Project:     cl-pascal
Component:   wrapper functions for cmd dispatch
Author:      Alexander Pascal (fryman)
Created:     2026-03-09
Last Update: 2026-03-13
Purpose:
             wrapper header
Overview:
Assumptions:
Notes:
=================================================================================*/

#include "main.h"
#include "clengine.h"
#include "wrapper.h"
#include "about.h"

#include <iostream>

int wrap_help(const std::vector<std::string>&)
{
    return cm_help();
}

/*
int wrap_bugfix(const std::vector<std::string>&)
{
    return bugfix_main();
}


int wrap_abtbox(const std::vector<std::string>&)
{
    return showAboutBox();
}
*/
int wrap_about(const std::vector<std::string>&)
{
    return cm_about();
}

int wrap_clear(const std::vector<std::string>&)
{
    return cm_clear();
}

int wrap_time(const std::vector<std::string>&)
{
    return cm_time();
}

int wrap_devinfo(const std::vector<std::string>&)
{
    return cm_devInfo();
}

int wrap_quit(const std::vector<std::string>&)
{
    return cm_quit();
}

int wrap_new(const std::vector<std::string>&)
{
    return cm_newFeats();
}

int wrap_maths(const std::vector<std::string>& u_ln)
{
    if(u_ln.size() < 4)
    {
        std::cerr << s_mFormat << '\n';
        return FAILURE;
    }
    
    std::cout << cm_maths(u_ln) << '\n';
    
    return SUCCESS;
}
