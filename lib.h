#ifndef LIB_H
#define LIB_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <git2.h>
#include <limits.h>

/* path.c */
extern char *get_prefix(const char *a, const char *b);
extern char *prefix_path(const char *prefix, char *path);

/* setup.c */
extern const char *setup_git_directory(git_repository **repo);

/* usage.c */
extern void usage(const char *err);
extern void die(const char *err, ...);
extern int error(const char *err, ...);


#endif /* LIB_H */
