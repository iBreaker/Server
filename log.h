#ifndef LOG_H
#define LOG_H

#include <stdio.h>
#include <stdarg.h>

typedef enum{
    DEBUG,
    INFO,
    WORNING,
    ERROR,
    FATAL
}DEBUG_LEVEL;

void log_printf(DEBUG_LEVEL debug_level, const char * fmt, ...);

#endif
/* vim: set ft=c :*/
