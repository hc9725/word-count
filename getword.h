#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <string.h>
#include "dbllink.h"
#include "wordinsert.h"
extern  Dlinklist list;
extern  Dlinklist lista;
extern  Dlinklist listb;
extern  Dlinklist listc;
extern  Dlinklist listd;
extern  Dlinklist liste;
extern  Dlinklist listf;
extern  Dlinklist listg;
extern  Dlinklist listh;
extern  Dlinklist listi;
extern  Dlinklist listj;
extern  Dlinklist listk;
extern  Dlinklist listl;
extern  Dlinklist listm;
extern  Dlinklist listn;
extern  Dlinklist listo;
extern  Dlinklist listp;
extern  Dlinklist listq;
extern  Dlinklist listr;
extern  Dlinklist lists;
extern  Dlinklist listt;
extern  Dlinklist listu;
extern  Dlinklist listv;
extern  Dlinklist listw;
extern  Dlinklist listx;
extern  Dlinklist listy;
extern  Dlinklist listz;
//extern  Dlinklist listw;

//void getword(FILE *fp,int uptolower,Dlinklist list);
//void getword(FILE *fp,int uptolower,Dlinklist list,char cnt);
void getword(FILE *fp,int uptolower,char cnt);
void wordtolist(char *ss, int islistempty,char cnt);
