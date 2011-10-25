#include "setup.h"

const char *setup_git_directory(git_repository **repo){
	char project_root[PATH_MAX];
	char oldcwd[PATH_MAX];

	if (!getcwd(oldcwd, PATH_MAX)){
		perror("getcwd:");
		die("encounter error when get cwd");
	}
	int len = strlen(oldcwd);
	oldcwd[len] = '/';
	oldcwd[len + 1] = '\0';

	if (git_repository_discover(project_root, PATH_MAX, oldcwd, 0, NULL)){
		die("git_repository_discover error");
	}

	if (chdir(project_root)){
		die("can not change to project root");
	}
	git_repository_open(repo, project_root);
	return path_prefix(git_repository_path(*repo, GIT_REPO_PATH_WORKDIR), oldcwd);
}
