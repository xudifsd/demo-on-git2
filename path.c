#include <stdlib.h>
#include <string.h>
#include <limits.h>

static char *clean_path(char *path){
	if (!memcmp(path, "./", 2)){
		path += 2;
		while (*path == '/')
			path++;
	}
	return path;
}

/*
   return static allocated space
   value is diff part of a and b
 */
char *get_prefix(const char *a, const char *b){
	static char prefix[PATH_MAX];
	int alen, blen, commonlen, rtn_val;
	const char *longer;

	alen = strlen(a);
	blen = strlen(b);
	commonlen = alen > blen ? blen: alen;
	longer = alen > blen ? a: b;
	rtn_val = memcmp(a, b, commonlen);
	if (rtn_val) {
		return NULL;
	}
	strcpy(prefix, longer + commonlen);
	if (!strcmp(prefix, "/"))
		return NULL;
	return prefix;
}

/* path could be any relative path like ./file ../file */
char *prefix_path(const char *prefix, char *path){
	static char rtn[PATH_MAX];
	char *pre = (prefix == NULL)? NULL: strdup(prefix);
	int pre_len;
	char *p;
	for (;;){
		path = clean_path(path);
		if (!memcmp(path, "../", 3)){
			pre_len = (pre == NULL)? 0: strlen(pre);
			if (pre_len){
				p = pre + pre_len - 2;
				while ((*p != '/') && (p != pre - 1)){
					p--;
				}
				*(p + 1) = '\0';
			} else
				return NULL;
			path += 3;
			continue;
		}else
			break;
	}
	pre_len = (pre == NULL)? 0: strlen(pre);
	memcpy(rtn, pre, pre_len);
	if (pre_len && (pre[pre_len] != '/')){
		rtn[pre_len] = '/';
		rtn[pre_len + 1] = '\0';
		pre_len++;
	}
	memcpy(rtn + pre_len, path, strlen(path));
	rtn[pre_len + strlen(path)] = '\0';
	free(pre);
	return rtn;
}
