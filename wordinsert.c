#include "wordinsert.h"
#include "dbllink.h"

//void wordinsert(Dlinklist list, char *word, int islistempty, char cnt)
void wordinsert(Dlinklist list, char *word, int islistempty,char cnt)
{
	Dlinklist list1 = list->next;
	int doexchange = 0;
	//static int listempty = 1;
	if (cnt == 'l')
	{
		if(1 == islistempty )
		{
			STWD *st = malloc(sizeof(STWD));
			if(st == NULL)
			{
				printf("system malloc wrong!\n");
				exit(1);
			}
			else
			{
				st->frq = 1;
				//sprintf(st->word,"%s", word);
				st->word = strdup(word);
				dinsertbefore(list,st);	
			}
		}
		else
		{
			while(0 == doexchange && list1->data != NULL )
			{
				if(cmp_list_word(list1->data,word) == 0)
				{
					STWD *pst = (STWD *)list1->data;
					pst->frq +=1;
					doexchange = 1;
				}	
				list1 = list1->next;
			}
			if(doexchange != 1)
			{
				STWD *st = malloc(sizeof(STWD));
				if(st == NULL)
				{
					printf("system molloc error\n");
					exit(1);
				}
				else
				{
					st->frq = 1;
				//	sprintf(st->word,"%s", word);
					st->word = strdup(word);
					dinsertbefore(list,st);
				}
			}
			//listempty = 0;
		}

	}
//insert by dectionary order
	else if( cnt == 'd')
	{
		if(1 == islistempty )
		{
			STWD *st = malloc(sizeof(STWD));
			if(st == NULL)
			{
				printf("system molloc error\n");
				exit(1);
			}
			else
			{
				st->frq = 1;
				//sprintf(st->word,"%s", word);
				st->word =  strdup(word);
				dinsertbefore(list,st);	
			}
		}
		else
		{
			int indexcnt = 1;
			while(0 == doexchange && list1->data != NULL)	
			{
				int cmplistwd  = cmp_list_word(list1->data,word);
				if( cmplistwd ==0)
				{
					STWD *pst = (STWD *)list1->data;
					pst->frq +=1;
					doexchange = 1;
				}
				else if(cmplistwd > 0)
				{
					STWD *st = malloc(sizeof(STWD));
					if(st == NULL)
					{
						printf("system molloc error\n");
						exit(1);
					}
					else
					{
						st->frq = 1;
						//sprintf(st->word,"%s", word);
						st->word = strdup(word);
						dinsertbeforen(list,st,indexcnt);	
						doexchange = 1;
					}
				}	
				list1 = list1->next;
				indexcnt ++;	
			}
			if(doexchange != 1)
			{
				STWD *st = malloc(sizeof(STWD));
				if(st == NULL)
				{
					printf("system molloc error\n");
					exit(1);
				}
				else 
				{
					st->frq = 1;
					//sprintf(st->word,"%s", word);
					st->word = strdup(word);
					dinsertbefore(list,st);
				}
			}
		}
	}



}//main fuc's





int cmp_list_word(const void *a, const void *b)
{
	STWD *p1 = (STWD *)a;
	//STWD *p2 = (STWD *)b;
	char *p2 = (char *)b;
	return  strcmp((const char *)p1->word, p2);
//	printf("%d",i);
//	return i;
}
