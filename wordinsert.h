#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include "dbllink.h"
int cmp_list_word(const void *a, const void *b);
//void wordinsert(Dlinklist list,char *word,int islistempty);
void wordinsert(Dlinklist list,char *word,int islistempty,char cnt);
