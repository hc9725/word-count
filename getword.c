#include "getword.h"
void getword(FILE *fp, int uptolower,char cnt)
//void getword(FILE *fp, int uptolower, Dlinklist list)
{
	char c;
	int islistempty=1;
	static int  ipro = 0;
	char  cnext;
	char  cnnext;
	static int  i = 0;
	int len = 0;
	char   ss[50];
	char *sss = ss;
	c = fgetc(fp);
//	printf("%d",uptolower);
	while(c != EOF)
	{
		if((c == '\\'|| c== '-') && ipro > 0)
		{
			
			 if((cnext = fgetc(fp)) == EOF)
			{
				//len = strlen(ss);
				//if(len > 0)
				if(ipro > 0)
				{
					ss[i++] = '\0';
					if(i > 50)
					{
						printf("%.*s** is too long\n",50,ss);
						i = 0;
						ipro =0;
					}
					else
					{
						wordtolist(ss,islistempty,cnt);
						islistempty = 0;
					}
				}
				exit(0);
			}	
			if(cnext == 'u')
			{
					
				 if((cnnext = fgetc(fp)) == EOF)
				{
					//len = strlen(ss);
					//if(len > 0)
					if(ipro > 0)
					{
						ss[i++] = '\0';
						if(i > 50)
						{
							printf("%.*s** is too long\n",50,ss);
							i = 0;
							ipro =0;
						}
						else
						{
							wordtolist(ss,islistempty,cnt);
							islistempty = 0;
						}
					}
					exit(0);
				}	
				if((cnnext >= '0' && cnnext <= '9') || (cnnext >= 'a' && cnnext <= 'z')||\
				(cnnext>= 'A' && cnnext <= 'Z'))
				{
					//ss[i++] = c;
					//printf("%c",cnnext);
					if(uptolower == 1)
					{
						if(cnnext >= 'A' && cnnext <=  'Z')
						{
							ss[i++] = cnnext + 32;
						}
						else
						{
							ss[i++] = cnnext;
				//			printf("%c",cnnext);
						}
					}
					else 
					{
				//		printf("%c",cnnext);
						ss[i++] = cnnext;
					}
					ipro =1;
				}
				else 
				{
					ss[i++] = '\0';
					//printf("%s ",ss);
					//len = strlen(ss);
					//if(len > 0)
					if(ipro > 0)
					{
						if(i > 50)
						{
							
							printf("%.*s** is too long\n",50,ss);
							i = 0;
							ipro =0;
						}
						else
						{
							wordtolist(ss,islistempty,cnt);
							islistempty = 0;
						}
					}
					ipro = 0;
					ss[0] = '\0';
					i = 0;
				}

			}
		}
		else if(c == '\'' && ipro > 0)
		{
			 if((cnext = fgetc(fp)) == EOF)
			 {  
				//len = strlen(ss);
				//if(len > 0)
				if(ipro >0  )
					{
						ss[i++] = '\0';
						if( i >50)
						{
						
							printf("%.*s** is too long\n",50,ss);
							i = 0;
							ipro =0;
						}
						else
						{
							wordtolist(ss,islistempty,cnt);
							islistempty = 0;
						}
					}
			 	exit(0);
			 }
			
			else 
			{
				if((cnext >= '0' && cnext <= '9') || (cnext >= 'a' && cnext <= 'z')|| (cnext >= 'A' && cnext <= 'Z'))
				{	
				//	printf("%c",c);
					ss[i++]=c;
					if(uptolower ==1)
					{
						if(cnext >= 'A' && cnext <= 'Z')
						{
				//			printf("%c",cnext);
							ss[i++] = cnext + 32;
						}
						else 
						{
				//			printf("%c",cnext);
							ss[i++] = cnext;
						}
					}
					else
					{
				//		printf("%c",cnext);
						ss[i++]=cnext;
					}
					ipro = 1;
				}
				else 
				{
					ipro = 0;
					continue;
				}
			}
		}
		else if((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z')|| (c >= 'A' && c <= 'Z'))
		{
			//printf("%c ",c);
			if(uptolower == 1)
			{
				if(c >= 'A' && c <= 'Z')
				{
				//	printf("%c",c);
					ss[i++] = c + 32;
				}
				else 
				{
				//	printf("%c",c);
					ss[i++] = c;
				}
			}
			else
			{
				//printf("%c",c);
				ss[i++] = c;
			}
			ipro = 1;
			//printf("blbl");
		}
		else 
		{	if(ipro > 0)
			{
				ss[i++] = '\0';
				if(i >50)
				{
				
					printf("%.*s** is too long\n",50,ss);
					i = 0;
					ipro =0;
				}
				else
				{
					wordtolist(ss,islistempty,cnt);
					islistempty = 0;
				}
				ss[0] ='\0' ;
				ipro = 0;
				i = 0;
			}
			else 
			{
				ipro = 0;
			}
		}
		
		c = fgetc(fp);
	}
//	len = strlen(ss);
//	if(len > 0)
	if(ipro > 0 )
	{
		ss[i++] = '\0';
		if(i > 50)
		{
			
			printf("%.*s** is too long\n",50,ss);
			i = 0;
			ipro =0;
		}
		else
		{
			wordtolist(ss,islistempty,cnt);
			islistempty = 0;
		}	
	}
}
void wordtolist(char *ss, int islistempty,char cnt)
{
	if(cnt == 'l')
	{
		wordinsert(list,ss,islistempty,cnt);
	}
	else
	{
		char firstch = ss[0];
		switch(firstch)
		{
			case 'a':
			case 'A': wordinsert(lista,ss,islistempty,cnt);break;
			case 'b':
			case 'B': wordinsert(listb,ss,islistempty,cnt);break;
			case 'c':
			case 'C': wordinsert(listc,ss,islistempty,cnt);break;
			case 'd':
			case 'D': wordinsert(listd,ss,islistempty,cnt);break;
			case 'e':
			case 'E': wordinsert(liste,ss,islistempty,cnt);break;
			case 'f':
			case 'F': wordinsert(listf,ss,islistempty,cnt);break;
			case 'g':
			case 'G': wordinsert(listg,ss,islistempty,cnt);break;
			case 'h':
			case 'H': wordinsert(listh,ss,islistempty,cnt);break;
			case 'i':
			case 'I': wordinsert(listi,ss,islistempty,cnt);break;
			case 'j':
			case 'J': wordinsert(listj,ss,islistempty,cnt);break;
			case 'k':
			case 'K': wordinsert(listk,ss,islistempty,cnt);break;
			case 'l':
			case 'L': wordinsert(listl,ss,islistempty,cnt);break;
			case 'm':
			case 'M': wordinsert(listm,ss,islistempty,cnt);break;
			case 'n':
			case 'N': wordinsert(listn,ss,islistempty,cnt);break;
			case 'o':
			case 'O': wordinsert(listo,ss,islistempty,cnt);break;
			case 'p':
			case 'P': wordinsert(listp,ss,islistempty,cnt);break;
			case 'q':
			case 'Q': wordinsert(listq,ss,islistempty,cnt);break;
			case 'r':
			case 'R': wordinsert(listr,ss,islistempty,cnt);break;
			case 's':
			case 'S': wordinsert(lists,ss,islistempty,cnt);break;
			case 't':
			case 'T': wordinsert(listt,ss,islistempty,cnt);break;
			case 'u':
			case 'U': wordinsert(listu,ss,islistempty,cnt);break;
			case 'v':
			case 'V': wordinsert(listv,ss,islistempty,cnt);break;
			case 'w':
			case 'W': wordinsert(listw,ss,islistempty,cnt);break;
			case 'x':
			case 'X': wordinsert(listx,ss,islistempty,cnt);break;
			case 'y':
			case 'Y': wordinsert(listy,ss,islistempty,cnt);break;
			case 'z':
			case 'Z': wordinsert(listz,ss,islistempty,cnt);break;
			default :wordinsert(list,ss,islistempty,cnt);break;
		}
	
	}
}
