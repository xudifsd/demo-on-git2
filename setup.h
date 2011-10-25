#ifndef SETUP_H
#define SETUP_H

#include <stdio.h>
#include <git2.h>
#include <limits.h>
#include <string.h>
#include "path.h"
#include "usage.h"

extern const char *setup_git_directory(git_repository **repo);
#endif /*SETUP_H*/
