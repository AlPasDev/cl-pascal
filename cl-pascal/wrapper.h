/*===============================================================================
File:        wrapper.h
Project:     cl-pascal
Component:   wrapper Header
Author:      Alexander Pascal (fryman)
Created:     2026-03-09
Last Update: 2026-03-09
Purpose:
             wrapper header
Overview:
Assumptions:
Notes:
=================================================================================*/

int wrap_help(const std::vector<std::string>&);
int wrap_about(const std::vector<std::string>&);
int wrap_clear(const std::vector<std::string>&);
int wrap_time(const std::vector<std::string>&);
int wrap_devinfo(const std::vector<std::string>&);
int wrap_quit(const std::vector<std::string>&);
int wrap_maths(const std::vector<std::string>& u_ln);
int wrap_new(const std::vector<std::string>& u_ln);
//int wrap_abtbox(const std::vector<std::string>& u_ln);
//int wrap_bugfix(const std::vector<std::string>&);
