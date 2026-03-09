//
//  wrapper.cpp
//  cl-pascal
//
//  Created by Alex Pascal on 2026/03/09.
//

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
    std::cout << cm_maths(u_ln) << '\n';
    
    return SUCCESS;
}
