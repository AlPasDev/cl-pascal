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
int wrap_help(const std::vector<std::string>&);
int wrap_about(const std::vector<std::string>&);
int wrap_clear(const std::vector<std::string>&);
int wrap_time(const std::vector<std::string>&);
int wrap_devinfo(const std::vector<std::string>&);
int wrap_quit(const std::vector<std::string>&);
int wrap_maths(const std::vector<std::string>& u_ln);

bool cl_run();

struct command
{
    std::string name;
    int (*handler)(const std::vector<std::string>&);
};

/*enum class command
{
    CMD_HELP,
    CMD_ABOUT,
    CMD_MATHS,
    CMD_MOD,
    CMD_RANDOM,
    CMD_ECHO,
    CMD_CLR,
    CMD_QUIT,
    CMD_TIME,
    CMD_DEVINFO,
    ARG_FORMAT_H,
    CMD_INVALID
};
*/

command commandTable[]
{
    {"help", wrap_help},
    {"maths", wrap_maths},
    {"rand", cm_random},
    {"echo", cm_echo},
    {"devinfo", wrap_devinfo},
    {"time", wrap_time},
    {"developer", wrap_devinfo},
    {"about", wrap_about},
    {"clear", wrap_clear},
    {"quit", wrap_quit},
    {"exit", wrap_quit},
    {"/f", arg_formatH},
    {"/?", wrap_help}
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
    CMD_TIME_H,
    CMD_QUIT_H,
    ARG_FORMAT_H,
    CMD_DEVINFO_H,
    CMD_INVALID_H
};
