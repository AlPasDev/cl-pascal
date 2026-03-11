/*===============================================================================
File:        wrapper.cpp
Project:     cl-pascal
Component:   wrapper functions for cmd dispatch
Author:      Alexander Pascal (fryman)
Created:     2026-03-09
Last Update: 2026-03-09
Purpose:
    wrapper header
Overview:
     
Assumptions:
     uStr > User String
    
Notes:
=================================================================================*/

#include "main.h"
#include "clengine.h"
#include "wrapper.h"

#include <iostream>

int wrap_help(const std::vector<std::string>&)
{
    return cm_help();
}

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

int wrap_maths(const std::vector<std::string>& u_ln)
{
    if(u_ln.size() != 4)
    {
        std::cerr << "Incorrect Usage: " << s_mFormat << '\n';
        return FAILURE;
    }
    
    return cm_maths(u_ln);
}
