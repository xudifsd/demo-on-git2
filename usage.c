#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "usage.h"

static void report(const char *prefix, const char *err, va_list params)
{
	fputs(prefix, stderr);
	vfprintf(stderr, err, params);
	fputs("\n", stderr);
}

void usage(const char *err)
{
	fprintf(stderr, "usage: %s\n", err);
	exit(129);
}

void die(const char *err, ...)
{
	va_list params;

	va_start(params, err);
	report("fatal: ", err, params);
	va_end(params);
	exit(128);
}

int error(const char *err, ...)
{
	va_list params;

	va_start(params, err);
	report("error: ", err, params);
	va_end(params);
	return -1;
}
