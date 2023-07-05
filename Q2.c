#include <stdlib.h>
#include "exam.h"


int mystrstr(char *s, char *t)
{
	int n = strlen(s);
	int m = strlen(t);
	if (n < m) {
		return 0;
	}
	int appearanes = 0;
	for (int i = 0; i < n; i++) {
		if (strncmp(s + i, t,m) == 0) {
			appearanes++;
		}
	}
	return appearanes;
}