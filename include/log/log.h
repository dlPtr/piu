#ifndef _T_UTILS_H
#define _T_UTILS_H

#include <stdio.h>
#include <unistd.h>
#include "colors.h"

static FILE *g_logTo = NULL;

#define _ut_log_ex(color, fformat, ...) do {                                         \
    fprintf(g_logTo, color "%s:%d "fformat"\n" UT_NONE, __FILE__, __LINE__, ##__VA_ARGS__);   \
} while(0);

/**
 * @brief 输出一条info级别的日志
 */
#define ut_log_info(format, ...) do {           \
    g_logTo = stdout;                           \
    _ut_log_ex(UT_NONE, format, ##__VA_ARGS__);  \
} while(0);

/**
 * @brief 输出一条error级别的日志
 */
#define ut_log_error(format, ...) do {            \
    g_logTo = stderr;                           \
    _ut_log_ex(UT_L_RED, format, ##__VA_ARGS__); \
} while(0);

#endif /* _T_UTILS_H */
