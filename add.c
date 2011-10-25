#include <stdio.h>
#include <limits.h>
#include <git2.h>
#include "setup.h"
#include "usage.h"

static const char * add_usage = "add <filename>";

int main(int argc, char *argv[]) {
	if (argc < 2){
		usage(add_usage);
	}
	git_repository *repo;
	git_index *index;

	const char *prefix;
	prefix = setup_git_directory(&repo);
	fprintf(stderr, "debug: prefix is %s\n", prefix);

	git_repository_index(&index, repo);

	int i;
	for ( i = 1 ; i < argc ; i++ ) {
		char *filename = make_path(prefix, argv[i]);
		if (git_index_add(index, filename, 0)){
			error("can not add %s to repository", filename);
		}
	}

	if (git_index_write(index)){
		die("can not write to index file");
	}
	git_index_free(index);
	git_repository_free(repo);
	return 0;
}
