#include "log.h"

/*
 * 日志函数
 * */
void log_printf(DEBUG_LEVEL debug_level, const char * fmt, ...){
    switch (debug_level){
        case DEBUG:break;
        case INFO:break;
        case WORNING:break;
        case ERROR:break;
        case FATAL:break;
    }

    va_list vl;
    va_start(vl, fmt);
    printf(fmt, vl);
    return;
}


/* vim:set filetype=c : */
