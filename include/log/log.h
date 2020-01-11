#ifndef _T_UTILS_H
#define _T_UTILS_H

#include <stdio.h>
#include <unistd.h>
#include "colors.h"

static FILE *g_logTo = NULL;

#define ut_log_ex(color, fformat, ...) do {                                         \
    fprintf(g_logTo, color "%s:%d "fformat"\n" UT_NONE, __FILE__, __LINE__, ##__VA_ARGS__);   \
} while(0);

#define ut_log_info(format, ...) do {           \
    g_logTo = stdout;                           \
    ut_log_ex(UT_NONE, format, ##__VA_ARGS__);  \
} while(0);

#define ut_log_err(format, ...) do {            \
    g_logTo = stderr;                           \
    ut_log_ex(UT_L_RED, format, ##__VA_ARGS__); \
} while(0);

#endif /* _T_UTILS_H */
