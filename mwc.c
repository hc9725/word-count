#include <unistd.h>
#include <sys/stat.h>
#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "dbllink.h"
#include "getword.h"
#include "getwordstdin.h"
//#include "wordcount.h"
#include "wordinsert.h"
void *myprint(void *data)
{
	STWD *stp =(STWD *)data;
	printf("%-4d ",stp->frq);
	printf("%s\n",stp->word);
};
Dlinklist list;
Dlinklist lista;
Dlinklist listb;
Dlinklist listc;
Dlinklist listd;
Dlinklist liste;
Dlinklist listf;
Dlinklist listg;
Dlinklist listh;
Dlinklist listi;
Dlinklist listj;
Dlinklist listk;
Dlinklist listl;
Dlinklist listm;
Dlinklist listn;
Dlinklist listo;
Dlinklist listp;
Dlinklist listq;
Dlinklist listr;
Dlinklist lists;
Dlinklist listt;
Dlinklist listu;
Dlinklist listv;
Dlinklist listw;
Dlinklist listx;
Dlinklist listy;
Dlinklist listz;
int cmpword(const void *a, const void *b);
int cmpfrq(const void *a,const void *b);
void main(int argc, char **argv)
{

	char *pathname;
	FILE *fp;
	static int uptolower = 0;
	list =  initlist();
	lista =  initlist();
	listb =  initlist();
	listc =  initlist();
	listd =  initlist();
	liste =  initlist();
	listf =  initlist();
	listg =  initlist();
	listh =  initlist();
	listi =  initlist();
	listj =  initlist();
	listk =  initlist();
	listl =  initlist();
	listm =  initlist();
	listn =  initlist();
	listo =  initlist();
	listp =  initlist();
	listq =  initlist();
	listr =  initlist();
	lists =  initlist();
	listt =  initlist();
	listu =  initlist();
	listv =  initlist();
	listw =  initlist();
	listx =  initlist();
	listy =  initlist();
	listz =  initlist();
	int opt;
	int nesecs,tfnd;
	nesecs = 0;
	tfnd = 0;
	int flag = 1;
	int flagul=0;
	while((opt = getopt(argc,argv, "dlfhe")) != -1)
	{
		switch(opt)
		{
			case 'd':
				{
					flag = 1;
				//	sortlist(list, cmpword);
				//	myscan(list, myprint);
				};break;
			case 'l':
				{
					flag = 2;
				//	myscan(list,myprint);
				};break;
			case 'f':
				{
					flag = 3;
				//	sortlist(list, cmpword);
				//	sortlist(list, cmpfrq);
				//	myscan(list, myprint);
				};break;
			case 'e':
				{
					flagul = 1;
				};break;
			case 'h':
			default :
				{
					printf("Usage:\n\t-d dictionary sort\n\t-l  the origonl sort\n\t-f frequence sort\
					\n\t-h help\n\t-c to engore the uper or lower case\n\t with the file path \n");
					exit(1);
				}
		}
	}
	   	 if(flagul == 1)
	               	 uptolower = 1;
		if(optind < argc)
		{
			while(optind < argc)
			{
				pathname = argv[optind++];
				if(access(pathname,0) == -1)
				{
					printf("mwc:%s:没有那个文件或者目录\n",pathname);
					exit(1);
				}
				else if(access(pathname,4) == -1)
				{
					printf("mwc:%s:权限不够\n",pathname);
					exit(1);
				}
				else
				{
					struct stat sb;
					printf("%s\n",pathname);
					stat(pathname,&sb);
					if(S_ISDIR(sb.st_mode))
					{
						printf("mwc:%s/: 是一个目录\n",pathname);	
					//	exit(1);
						//break;
						//continue;

					}
					else
					{
						fp = fopen(pathname,"r");
	                			if(fp == NULL)
						{
							printf("mwc: %s:未知错误发生\n",pathname);
                        				exit(1);
					 	}	
					 	//printf("herehere11 %s\n",pathname);	
         					//getword(fp,uptolower,list);
						//wordcount(list);
						switch(flag)
						{
						//	printf("herehere %s\n",pathname);
							case 1:
							{
						//	printf("comehere yet?\n");
						//		int listlen = dlistlength(list);
						//		printf("%d\n",listlen);
								//sortlist(list,cmpword);
								char cnt = 'd';
         							getword(fp,uptolower,cnt);
							//	sortlist(list,cmpword);
								myscan(list,myprint);
								myscan(lista,myprint);
								myscan(listb,myprint);
								myscan(listc,myprint);
								myscan(listd,myprint);
								myscan(liste,myprint);
								myscan(listf,myprint);
								myscan(listg,myprint);
								myscan(listh,myprint);
								myscan(listi,myprint);
								myscan(listj,myprint);
								myscan(listk,myprint);
								myscan(listl,myprint);
								myscan(listm,myprint);
								myscan(listn,myprint);
								myscan(listo,myprint);
								myscan(listp,myprint);
								myscan(listq,myprint);
								myscan(listr,myprint);
								myscan(lists,myprint);
								myscan(listt,myprint);
								myscan(listu,myprint);
								myscan(listv,myprint);
								myscan(listw,myprint);
								myscan(listx,myprint);
								myscan(listy,myprint);
								myscan(listz,myprint);
							};break;
							case 2:
							{
								char cnt = 'l';
         							getword(fp,uptolower,cnt);
								myscan(list,myprint);
							};break;
							case 3:
							{
								char cnt = 'd';
         							getword(fp,uptolower,cnt);
							//	sortlist(list,cmpword);
								mergelist(list,lista);
								mergelist(list,listb);
								mergelist(list,listc);
								mergelist(list,listd);
								mergelist(list,liste);
								mergelist(list,listf);
								mergelist(list,listg);
								mergelist(list,listh);
								mergelist(list,listi);
								mergelist(list,listj);
								mergelist(list,listk);
								mergelist(list,listl);
								mergelist(list,listm);
								mergelist(list,listn);
								mergelist(list,listo);
								mergelist(list,listp);
								mergelist(list,listq);
								mergelist(list,listt);
								mergelist(list,listd);
								mergelist(list,listt);
								mergelist(list,listu);
								mergelist(list,listv);
								mergelist(list,listw);
								mergelist(list,listx);
								mergelist(list,listy);
								mergelist(list,listz);
								sortlist(list,cmpfrq);
								myscan(list,myprint);
								quicksortlist(list,cmpfrq);
								myscan(list,myprint);
							};break;
							default:
							{
								printf("error\n");
								exit(0);
							};break;
						}
						dclearlist(list);
					}
				}
			}
		}
		else
		{
			//getwordstdin(uptolower,list);
			printf("\n");
			//wordcount(list);
			switch(flag)
			{
				case 1:
				{
					char cnt = 'd';
				//	getwordstdin(uptolower,list);
					getwordstdin(uptolower,cnt);
					//sortlist(list,cmpword);
					myscan(list,myprint);
					};break;
				case 2:
				{
					char cnt = 'l';
					getwordstdin(uptolower,cnt);
					myscan(list,myprint);
					};break;
				case 3:
				{
					char cnt = 'd';
					getwordstdin(uptolower,cnt);
					//sortlist(list,cmpword);
					sortlist(list,cmpfrq);
					myscan(list,myprint);
				};break;
				default:
				{
					printf("error\n");
					exit(0);
				};break;
			}
		}
}


int cmpword(const void *a, const void *b)
{
	STWD *p1 = (STWD *)a;
	STWD *p2 = (STWD *)b;
	return  strcmp((const char *)p1->word, (const char *)p2->word);
//	printf("%d",i);
//	return i;
}



int cmpfrq(const void *a,const void *b)
{
	int a1 = *(int *)a;
	int b1 = *(int *)b;
	if((a1 - b1) > 0)
		return 1;
	else if(a1 == b1)
		return 0;
	else return -1;
}
