#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "dbllink.h"
//初始化头指针
Dlinklist initlist()
{
	head = NULL;	
head = malloc(sizeof(Dlnode));
	head->data = NULL;
	head->next = head;
	head->prior = head;
	return head;
}
//找到头节点head
Dlinklist dgethead(Dlinklist p)
{
	while(p->data != NULL)
	{
		p = p->next;
	}
	return p;
}
//创建一个节点
Dlinklist  dmakenode(void *e)
{
	Dlinklist s = malloc(sizeof(Dlnode));
	if(s==NULL)
	return(NULL);
	s->next = NULL;
	s->prior = NULL;
	s->data = e;
	return s;
}
//在结点前增加节点   未输入index，暂定为0即插入到head前
ret dinsertbefore(Dlinklist p, void *e)
{
	//(*p==NULl)
	//it(EXIT_FAILURE);
/*	lnode *s = malloc(sizeof(dlnode));
*	if( *s==NULL)
*	exit(EXIT_FAILURE);
*/
	if(p!=NULL)
	{
		Dlinklist s;
		s = dmakenode(e);
		if(NULL == s) 
		return(ERROR);
		s->next = p;
		s->prior = p->prior;
		p->prior->next = s;
		p->prior = s;
		//is->data = e;
	/*	Dlinklist head = dgethead(p);
		Dlinklist fhead=head->next;
		s->next = fhead;
		s->prior = fhead->prior;
		fhead->prior->next = s;
		fhead->prior = s;
	*/
		return OK;
	}
	else return NO;
}


ret dinsertbeforen(Dlinklist p, void *e, int index)//在任意结点前插入结点
{
	
	if(p!=NULL)
	{
	//	int j=dlistlength(p);
	//	if(j>index)
	//	{
			Dlinklist s;
			int i;
			s = dmakenode(e);
			if(NULL == s) 
			return(ERROR);
			//is->data = e;
			Dlinklist head = p;
			Dlinklist fhead = head;
			for(i=0;i<index;i++)
			{
				fhead = fhead->next;
			}
			s->next = fhead;
			s->prior = fhead->prior;
			fhead->prior->next = s;
			fhead->prior = s;
			return OK;
	//	}
	//	else return NO;
	}
	else return NO;

	
}
//在头点结点后增加节点
ret dinsertafter(Dlinklist p, void *e)
{
/*	lnode *s = malloc(sizeof(dlnode));
*	if( *s==NULL)
*	exit(EXIT_FAILURE);
*/	if(p!=NULL)
	{
		Dlinklist s;
		s = dmakenode(e); 
		if(s == NULL)
		return(ERROR);
		//s->data = e;
		s->next = p->next;
		s->prior = p;
		p->next->prior = s;
		p->next = s;
		return OK;
	}
	else return NO;
}


ret  dinsertaftern(Dlinklist p, void *e,int index)//在任意节点后插入节点
{	if(p!=NULL)
	{
		int j=dlistlength(p);
		if(j+1 > index)
		{
			Dlinklist s;
			Dlinklist tmpp=p;
			int i;
			s = dmakenode(e); 
			if(s == NULL)
			return(ERROR);
			//s->data = e;
			for(i=0;i<index;i++)
			{
				tmpp=tmpp->next;
			}
			s->next = tmpp->next;
			s->prior = tmpp;
			tmpp->next->prior = s;
			tmpp->next = s;
			return OK;
		}
		else return NO;
	}
	else return NO;
}
// 查找元素在链表中的位置
Dlinklist dlocateitem(Dlinklist p, void *e) 
{	
	if(p!=NULL)
	{
		Dlinklist retp = dgethead(p);
		retp = retp->next;
		while(retp->data != NULL   )
		{
			if(retp->data == e)
			{
				return retp;
			}
			retp = retp->next;
		}
	}
	return NULL;
}
//删除某个节点值
ret ddeletenode(Dlinklist p, void *e)
{
	////Dlinklist tempp = dlocateitem(p,e);
	if(p!=NULL)
	{
		Dlinklist head = dgethead(p);
		Dlinklist temp;
		Dlinklist tempp;
		for(temp=head->next;temp->data != NULL;temp = temp->next)	
		{
		
			tempp = dlocateitem(temp,e);
			if(tempp != NULL)
			{
				tempp->prior->next = tempp->next;
				tempp->next->prior = tempp->prior;
			}
		}
	return OK;
	}
	else return NO;
//	free(tempp);
//	free(temp);
//	free(head);
}

ret ddeletenoden(Dlinklist p,int index)// 删除第index个节点
{
	if(p !=NULL){
		int j=dlistlength(p);
		if(j<index)
		return NO;
		else
		{
			Dlinklist tmpp = p;
			int i;
			for(i=0;i<index;i++)
			{
				tmpp = tmpp->next;
			}
			tmpp->next->prior = tmpp->prior;
			tmpp->prior->next = tmpp->next;
			free(tmpp);
			return OK;
		}
		return NO;
	}
	
	else return NO;
}

//替换某个元素的值
ret setitem(Dlinklist p,void *e, void  *edest)
{
	if(p)
	{
		Dlinklist retp = dlocateitem(p,e);
		if(retp == NULL)
		{
			printf("can not find the node ");
		}
		else{
			retp->data = edest;
		}
	return OK;
	}	
	else return NO;
}



//返回链表中元素总个数
int dlistlength(Dlinklist p)
{
	if(p!=NULL)
	{
		int i=1;
		//Dlinklist head = dgethead(p);
		Dlinklist ptmp = p->next;
		//while(ptmp != head)
		while(ptmp->data !=NULL)
		{
			ptmp = ptmp->next;
			i++;
		}
		return(i);
	}
	else return(0);
}



//正序遍历 
Dlinklist dscan(Dlinklist p, VisitFunc visit)
{
	if(p!=NULL)
	{
		void *retp = NULL;
		if( p==NULL)
		//return 0;
		{
			printf("Linklist error");	
			//	exit(1);
			return NULL;	
		}
		int i=0;
     		i = dlistlength(p);
		if(i< 1 )
		{
			printf("you only get a headlist without any item");
			//exit(1);
			return NULL;
		}	
		else
		{	
			void *retp = NULL;
			while(p->next !=p)
			{
				retp = visit(p->data);
			}
		}
		return retp;
	}
	else return NULL;
}

//逆序遍历 
Dlinklist drescan(Dlinklist p, VisitFunc visit)
{
	if(p!=NULL)
	{
		void *retp = NULL;
		if( p==NULL)
		//return 0;
		{
			printf("Linklist error");	
			//	exit(1);
			return NULL;	
		}
		int i=0;
     		i = dlistlength(p);
		if(i< 1 )
		{
			printf("you only get a headlist without any item");
			//exit(1);
			return NULL;
		}	
		else
		{	
			void *retp = NULL;
			while(p->prior !=p)
			{
				retp = visit(p->data);
			}
		}
		return retp;
	}
	else return NULL;
}

//销毁链表
void ddestroylist(Dlinklist p)
{
	if(p!=NULL)
	{
	p = dclearlist(p);	
	p=NULL;
	free(p);
	}
}

//将链表置空
Dlinklist dclearlist(Dlinklist p)
{
	if(p!=NULL)
	{	
		Dlinklist tmpp1 = dgethead(p) ;
		Dlinklist tmpp2 ;
		for(; tmpp1->next != tmpp1; )
		{
			tmpp2 = tmpp1->next;
			tmpp1-> next = tmpp2->next;
			tmpp2->next->prior = tmpp1;
			free(tmpp2);
		}
		return tmpp1;
	}
	return NULL;
}


//判断表p是否为空表
ret disempty(Dlinklist p)
{
//	Dlinklist head =dgethead(p);	
	if(p==NULL)
	{
		printf("a NULL list occored");
		return NO;
	}
	else
	{
		if(p->next == p)
		return NO;
		else 
		return OK;
	}
}

//升序排列  
ret  sortlist(Dlinklist p,int cmpall(const void *a,const void *b))
{
	if(p==NULL)
	{
		printf("a NULL list occord");
		return NO;
	}
	else
	{
		//Dlinklist head = dgethead(p);
		Dlinklist p1=NULL;
		Dlinklist p2=NULL;
		Dlinklist p3=malloc(sizeof(Dlnode));	
		int len = dlistlength(p);
		int j,i;
		if(len<3)
		{
			return NO;
		}
		else
		{	
			int docmp=1;
			while(docmp)
			{
				p1 = p->next;
				p2 = p1->next;
				docmp =0;
				while(p2->data !=NULL)
				{
					if(cmpall(p1->data, p2->data) >0)
					{
					
						p3->data = p1->data;
						p1->data =  p2->data;
						p2->data = p3->data;
						docmp = 1;	
					}
					p1 = p1->next;
					p2=p2->next;
				}
			}
		
		
		}
		free(p3);
	return OK;
}
return NO;	
}

// 比较大小的函数取自 qsort
//static int chgcmp(const void * a, const void *b)
//{
//	return  strcmp((const char *) a, ( const char *) b);
//}
//快速排序
ret  quicksortlist(Dlinklist p,int cmpall(const void *a,const void *b))
{
	if(p==NULL)
	{
		printf("a NULL list occord");
		return NO;
	}
	else
	{
		int len = dlistlength(p);
	//	printf("the length of the list is %d\n",len);
		if(len < 2)
		{
			return OK;
		}
		else
		{
			int left = 1;
			int right = len - 1;
			quicksort(p->next, p->prior, left, right, cmpall);
			//printf("the leftnode to sort  is  %c   the right node to sort is %c  \n",*(char *)p->next->data,*(char *)p->prior->data);
		}
	}


}
//递归快排
//void quicksortonce(Dlinklist leftlist, Dlinklist rightlist , int left,int right, int cmpall(const void *a,const void *b))
//{
//	int n = quicksortonce( leftlist, rightlist , left,right, cmpall(const void *a,const void *b));
//	if(n > left)
//	int n = quicksortonce( leftlist, rightlist , left,right, cmpall(const void *a,const void *b));
//	if(n && n <= right)
//	int n = quicksortonce( leftlist, rightlist , left,right, cmpall(const void *a,const void *b));
//
//}
void quicksort(Dlinklist leftlist, Dlinklist rightlist , int left,int right, int cmpall(const void *a,const void *b))
{
	//printf("in the quicksort///////////////////////\n");
//	printf("left is %d right is %d   ",left, right);
//	printf("the leftnode is  %c   the right node is %c  \n",*(char *)leftlist->data,*(char *)rightlist->data);
	if(left < right)
	{
		Dlinklist baselist = leftlist;
//		printf("the baselist node is   %c \n",*(char *)baselist->data);
		Dlinklist curleftlist = leftlist;
		Dlinklist currightlist = rightlist;
		leftlist = leftlist->prior;
		rightlist = rightlist->next;
		Dlinklist p;
		Dlinklist q;
		int curleft = left;
		int curright = right;
		while(curright > curleft)
		{
			while(curright > left && (cmpall(baselist->data,currightlist->data) < 0))
			{
				//printf("to find a small one curleft is %d  curright is %d    \n ",curleft,curright);
				//printf("the curleftnode is  %c   the curright node is %c  \n",*(char *)curleftlist->data,*(char *)currightlist->data);
				currightlist = currightlist->prior;
//				printf(" the curright node'prior node  is %c  \n",*(char *)currightlist->data);
				curright--;
			}
//			printf("now the curright is \\\\\\\\\\\\\\ %d\n ", curright);
			while(curleft < right && (cmpall(baselist->data,curleftlist->data) > 0))
			{
				//printf(" to find the bigger one curleft is %d  curright is %d    \n ",curleft,curright);
				//printf("the curleftnode is  %c   the curright node is %c  \n",*(char *)curleftlist->data,*(char *)currightlist->data);
				curleftlist = curleftlist->next;
				curleft++;
			}

			//exchange(curleftlist->data,currightlist->data);
			if(curleft < curright)	
			{
				//printf("here one changelxlxlxlxllxlxxlxllxlxlxl\n");
				p = curleftlist->prior;
				q = currightlist->next;
				curleftlist->next->prior = p; //del curleftlist
				p->next = curleftlist->next;
				currightlist->prior->next=q;//del currightlist
				q->prior = currightlist->prior;
				currightlist->next = p->next;//add currightlist
				currightlist->prior = p;
				p->next->prior = currightlist;
				p->next =currightlist;
				curleftlist->next = q;//add currleftlist
				curleftlist->prior = q->prior;
				q->prior->next = curleftlist;
				q->prior = curleftlist;
			
			curright--;
			curleft++;
			curleftlist = p->next->next;//back where it was
			currightlist = q->prior->prior;
			}	
		}
		//baselist->prior->next = baselist->next;//move the base(the left node ) to the curleftlist node's next;
		//baselist->next->prior = baselist->prior;
		//baselist->next = currightlist->next;
		//baselist->prior = currightlist;
		//currightlist->next->prior = baselist;
		//currightlist->next = baselist;
		//if(curleft < curright)
		//{
		if(left < curright)
		{
//		printf("here from if left is %d   curright is %d \n",left,curright);
			quicksort(leftlist->next,currightlist->prior,left,curright-1,cmpall);//recurse
		}
		if(right > curleft)
		{
			quicksort(currightlist->next,rightlist->prior,curright+1,right,cmpall); 
		}
	//}
	}
	exit(1);
}

//将两个链表合二为一
Dlinklist  mergelist(Dlinklist pa, Dlinklist pb)
{	if((pa==NULL)  && (pb!= NULL))
	{
		return pb;
	}
	else if((pa != NULL) && (pb == NULL))
	{
		return pa;
	}
	else if((pa == NULL)  && (pb ==NULL))
	{
		return NULL;
	}
	else
	{
	pa->prior->next = pb->next;
	pb->next->prior = pa->prior;
	pa->prior = pb->prior;
	pb->prior->next=pa;
	free(pb);	
	return pa;
	}

}



//从头至尾 扫描并访问链表
void myscan(Dlinklist list, VisitFunc visit)
{
	Dlnode *ipointer = NULL;
    void  *retp = NULL;

    ipointer = list->next;
    for (ipointer ; ipointer->data != NULL; )
    {
        retp = visit(ipointer->data);
        ipointer = ipointer->next;
    }
	printf("\n");
}
//从尾至头扫描并访问链表
void myrescan(Dlinklist list, VisitFunc visit)
{
	Dlnode *ipointer = NULL;
    void  *retp = NULL;

    ipointer = list->prior;
    for (ipointer ; ipointer->data != NULL; )
    {
        retp = visit(ipointer->data);
        ipointer = ipointer->prior;
    }
	printf("\n");
}
//打印






