
#include "conf.h"

config_t config;

int init_config(){
    config.debug_level = DEBUG;
    return 0;
}
