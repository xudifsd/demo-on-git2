#include "lib.h"

static char *rm_usage = "rm <path to remove>";

int main(int argc, char *argv[]) {
	if (argc < 2)
		usage(rm_usage);

	int i, position;
	const char *prefix;
	git_repository *repo;
	git_index *index;

	prefix = setup_git_directory(&repo);
	if (git_repository_index(&index, repo))
		error("error when reading index file");

	for ( i = 1 ; i < argc ; i++ ) {
		position = git_index_find(index, argv[i]);
		if (position < 0)
			error("no entry found which named %s", argv[i]);
		else{
			if (git_index_get_unmerged_bypath(index, argv[i])) {
				int j;
				for ( j = position ; j < position + 3 ; j++ ) {
					if (git_index_remove(index, j))
						error("can not remove %s whose stage is %d from index", argv[i], j - position);
				}
			} else{
				if (git_index_remove(index, position))
					error("can not remove %s from index", argv[i]);
			}
		}
	}

	if (git_index_write(index))
		die("can not write index file");
	git_index_free(index);
	git_repository_free(repo);
	return 0;
}
