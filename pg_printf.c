#include "c.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

/*
 * This file contains versions of fprintf, vfprintf, etc. that behave
 * uniformly on all platforms, unlike the native library versions.
 * It is intended to be used by the core code and utilities.
 */

/* Function prototypes */
int pg_fprintf(FILE *stream, const char *fmt, ...);
int pg_vfprintf(FILE *stream, const char *fmt, va_list args);
int pg_sprintf(char *str, const char *fmt, ...);
int pg_vsprintf(char *str, const char *fmt, va_list args);
int pg_snprintf(char *str, size_t count, const char *fmt, ...);
int pg_vsnprintf(char *str, size_t count, const char *fmt, va_list args);

int
pg_fprintf(FILE *stream, const char *fmt, ...)
{
    va_list args;
    int     count;

    va_start(args, fmt);
    count = vfprintf(stream, fmt, args);
    va_end(args);

    return count;
}

int
pg_vfprintf(FILE *stream, const char *fmt, va_list args)
{
    return vfprintf(stream, fmt, args);
}

int
pg_sprintf(char *str, const char *fmt, ...)
{
    va_list args;
    int     count;

    va_start(args, fmt);
    count = vsprintf(str, fmt, args);
    va_end(args);

    return count;
}

int
pg_vsprintf(char *str, const char *fmt, va_list args)
{
    return vsprintf(str, fmt, args);
}

int
pg_snprintf(char *str, size_t count, const char *fmt, ...)
{
    va_list args;
    int     retval;

    va_start(args, fmt);
    retval = vsnprintf(str, count, fmt, args);
    va_end(args);

    return retval;
}

int
pg_vsnprintf(char *str, size_t count, const char *fmt, va_list args)
{
    return vsnprintf(str, count, fmt, args);
}
