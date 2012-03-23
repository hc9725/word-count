#include "wordcount.h"
void wordcount(Dlinklist list)
{
	Dlinklist p1 = list->next;
	Dlinklist p2 = NULL; 
	int i = 1;
	int j;
	int len = dlistlength(list);
	int delnum = 0;
	//printf("\nthe length of the list is %d",len);
	while(p1->data != NULL)
	{
		p2 = p1->next;
		j=i+1;
		while(p2->data != NULL)
		{
			if(cmpword(p1->data,p2->data) == 0)
			{
				p2 = p2->prior;
				ddeletenoden(list,j);
				delnum += 1;
				j--;
			}

			p2 = p2->next;
			j++;
		}
		if(delnum != 0)
		{
			STWD *pst = (STWD *)p1->data;
			pst->frq += delnum;
		//	printf("%d",pst->frq);
		//	((STWD *)p1->data)->frq += delnum;
		delnum = 0;
		}
		p1 = p1->next;
		i++;
	}
}


