//
//  clengine.h
//  cl-pascal
//
//  Created by Alex Pascal on 2026/02/25.
//

bool cl_run();

enum class command
{
    CMD_HELP,
    CMD_ABOUT,
    CMD_ADD,
    CMD_SUB,
    CMD_RANDOM,
    CMD_REPEAT,
    CMD_CLR,
    CMD_QUIT,
    ARG_FORMAT_H,
    CMD_INVALID
};
