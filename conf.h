#ifndef GLOBAL_H
#define GLOBAL_H 

#include <stdio.h>
#include "log.h"

typedef struct{
    DEBUG_LEVEL debug_level;
}config_t;

extern config_t config;

int init_config();

#endif

/* vim:set filetype=c: */

