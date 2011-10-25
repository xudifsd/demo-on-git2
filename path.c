#include <stdlib.h>
#include <string.h>
#include <limits.h>

/*All return static allocated space*/

char *path_prefix(const char *a, const char *b){
	static char prefix[PATH_MAX];
	int alen, blen, commonlen, rtn_val;
	const char *longer;

	alen = strlen(a);
	blen = strlen(b);
	commonlen = alen > blen ? blen: alen;
	longer = alen > blen ? a: b;
	rtn_val = memcmp(a, b, commonlen);
	if ( rtn_val ) {
		return NULL;
	}
	return strcpy(prefix, longer + commonlen);
}

char *make_path(const char *prefix, const char *basename){
	static char path[PATH_MAX];
	int len = (prefix == NULL)? 0: strlen(prefix);
	memcpy(path, prefix, len);
	if (len && (prefix[len] != '/')){
		path[len] = '/';
		path[len + 1] = '\0';
		len++;
	}
	strcpy(path + len, basename);
	return path;
}
