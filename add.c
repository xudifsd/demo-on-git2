#include <stdio.h>
#include <limits.h>
#include <git2.h>

static const char * add_usage = "add <filename>";

int main(int argc, char *argv[]) {
	if (argc < 2){
		usage(add_usage);
	}
	git_repository *repo;
	git_index *index;
	char project_root[PATH_MAX];
	if (git_repository_discover(project_root, PATH_MAX, ".", 0, "/")){
		die("current not in git project dir");
	}
	fprintf(stderr, "debug: project_root is %s\n", project_root);
	git_repository_open(&repo, project_root);

	git_repository_index(&index, repo);

	int i;
	for ( i = 1 ; i < argc ; i++ ) {
		char *filename = argv[i];
		if (git_index_add(index, filename, 0)){
			error("can not add %s to repository", filename);
		}
	}

	if (git_index_write(index)){
		die("can not write to index file");
	}
	git_index_free(index);
	git_repository_free(repo);
}
