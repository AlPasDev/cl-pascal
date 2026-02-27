//
//  clengine.cpp
//  cl-pascal
//
//  Created by Alex Pascal on 2026/02/25.
//
#include "main.h"
#include "clengine.h"
#include <iostream>
#include <string>
#include <string_view>

static std::vector<std::string> fStr{};

using namespace std;

command cmdToInt(const string_view currentIn)
{
    if(currentIn == "help") return command::CMD_HELP;
    if(currentIn == "add") return command::CMD_ADD;
    if(currentIn == "sub") return command::CMD_SUB;
    if(currentIn == "rand") return command::CMD_RANDOM;
    if(currentIn == "repeat") return command::CMD_REPEAT;
    if(currentIn == "about") return command::CMD_ABOUT;
    if(currentIn == "clear") return command::CMD_CLR;
    if(currentIn == "quit") return command::CMD_QUIT;
    if(currentIn == "/f") return command::ARG_FORMAT_H;
    
    return command::CMD_INVALID;
}
void cl_prompt()
{
    string_view charLn{"> "};
    cout << charLn;
}

void cntr_cmd(string_view u_ln)
{
    
    switch (cmdToInt(u_ln)) {
        case command::CMD_HELP:
            cm_help();
            
            break;
            
        case command::CMD_ADD:
            cm_add(u_ln);
            break;
            
        case command::CMD_SUB:
            cm_sub(u_ln);
            
            break;
            
        case command::CMD_RANDOM:
            cm_random();
            
            break;
            
        case command::CMD_REPEAT:
            cm_repeat(u_ln);
            
            break;
            
        case command::CMD_ABOUT:
            cm_about();
            
            break;
            
        case command::CMD_CLR:
            cm_clear();
            
            break;
            
        case command::CMD_QUIT:
            cm_quit();
            
            break;
            
        case command::ARG_FORMAT_H:
            
            arg_formatH(u_ln);

            break;
            
        default:
            cout << "Invalid Input";
            break;
    }
}

bool cm_quit()
{
    if(fStr[0] == "quit")
        return true;
    return false;
}


bool cl_run()
{
    cl_prompt();
    
    
    string uStr = cl_input();      // Own the string
    
    fStr = sTokenize(uStr);
    
    cntr_cmd(uStr);
    
    cntr_cmd(fStr[0]);
    
    return true;
}

