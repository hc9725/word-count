#include "getwordstdin.h"
void getwordstdin(int uptolower,char cnt)
//void getwordstdin(int uptolower,Dlinklist list)
{
	char ss[256];
	char c;
	int i =0;
	int len = 0;
	int islistempty=1;
	while(scanf("%c",&c) != EOF)
	{
		if((c >= '0' && c<='9') || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		{
			if(uptolower == 1)
			{
				if(c >= 'A' && c <= 'Z')
				{
					ss[i++] = c + 32;
				}
				else
				{
					ss[i++] = c;
				}
			}
			else 
			{
				ss[i++] = c;
			}
		}
		else
		{
			ss[i++] = '\0';
			len = strlen(ss);
			if(len >0)
			{
				//wordinsert(list,ss, islistempty);
				wordinsert(list,ss, islistempty,cnt);
				islistempty = 0;
			}
			i = 0;
			ss[i] = '\0';
		}

	}
	ss[i++] = '\0';
	len = strlen(ss);
	if(len >0)
		{
		//wordinsert(list,ss,islistempty);
		wordinsert(list,ss,islistempty,cnt);
		islistempty = 0;
		}
}
