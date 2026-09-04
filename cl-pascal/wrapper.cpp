/*===============================================================================
File:        wrapper.cpp
Project:     cl-pascal
Component:   wrapper functions for cmd dispatch
Author:      Alexander Pascal (fryman)
Created:     2026-03-09
Last Update: 2026-09-04
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

double m_result{0};

int wrap_help(const std::vector<std::string>&)
{
    return cm_help();
}

int wrap_hist(const std::vector<std::string>&)
{
    return cm_hist();
}

int wrap_strLine(const std::vector<std::string>&)
{
    return cm_strLine();
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

int wrap_meal(const std::vector<std::string>&)
{
    return cm_meal();
}

int wrap_maths(const std::vector<std::string>& u_ln)
{
    m_result = cm_maths(u_ln, m_result);
    
    std::cout << m_result << '\n';
    
    return SUCCESS;
}
