#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>
#include <errno.h>
#include "dbllink.h"
//字符字符串比较函数
int chrcmp(const void *a,const void *b)
{
	return strcmp((const char *)a, (const char *)b);
}
//整型比较函数
int intcmp(const void *p1,const void *p2)
{
	int a= *(int *)p1;
	int b= *(int *)p2;
	if((a - b) > 0)
		return 1;
	else if(a == b)
		return 0;
	else 
		return -1;
}
//结构体比较函数   按int类型比较
int strtcmpint(const void *p1,const void *p2)
{
	ST *st1 =(ST *)p1;
	ST *st2 =(ST *)p2;
	if((st1->aint - st2->aint) > 0)
		return 1;
	else if(st1->aint == st2->aint)
		return 0;
	else 
		return -1;
}

//结构体比较函数   按char *类型比较
int strtcmpcharp(const void *p1,const void *p2)
{
	ST *st1 =(ST *)p1;
	ST *st2 =(ST *)p2;
	return strcmp((const char *)st1->acharp, (const char *)st2->acharp);
}

//char **类型比较，，
int charppcmp(const void *p1,const void *p2)
{
	char **a = (char **)p1;
	char **b = (char **)p2;
	char a1 = **a;
	char b1 = **b;
	return strcmp( (const char *)a, (const char *)b);
}


//从头至尾 扫描并访问链表
/*void myscan(Dlinklist list, VisitFunc visit)
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
}*/
//打印
void *myprintchar(void *data)
{
    printf("%c\t",*((char*)data));

}
void *myprintstr(void *data)
{
    printf("%s\t",(char*)data);

}
void *myprintint(void *data)
{
    printf("%d\t",*((int *)data));

}
void *myprintst(void *data)
{
    ST *stp = (ST *)data;
//    ST st;
      printf("%d\t",stp->aint);
      printf("%c\t",stp->achar);
      printf("%s\t",stp->acharp);
	printf("\n");
}
 

//char类型测试用例
void testchar()
{	
	printf("\n\n\n--------------------------------------------\n");
	printf("this is the test for char\n");
	char falg ='c';
	Dlinklist list;
	list = initlist();//初始化
	char x='x';
	char y ='y';
	char z ='z';
	char a ='a';
	char g ='g';
	char r ='r';
	char c ='c';
	char m ='m';
	char s ='s';
	dinsertbefore(list,&x);//插入到头结点前面
	dinsertbefore(list,&x);//插入到头结点前面
	dinsertbefore(list,&x);//插入到头结点前面
	dinsertbefore(list,&x);//插入到头结点前面
	dinsertbefore(list,&y);//插入到头结点前面
	dinsertafter(list,&z);//插入到头结点后面
	dinsertbefore(list,&a);//插入到头结点前面
	dinsertbefore(list,&g);//插入到头结点前面
	dinsertbefore(list,&g);//插入到头结点前面
	dinsertbefore(list,&g);//插入到头结点前面
	dinsertbefore(list,&g);//插入到头结点前面
	dinsertbefore(list,&g);//插入到头结点前面
	dinsertbefore(list,&g);//插入到头结点前面
	dinsertbefore(list,&g);//插入到头结点前面
	dinsertafter(list,&r);//插入到头结点后面
	dinsertbefore(list,&c);//插入到头结点前面
	dinsertbefore(list,&m);//插入到头结点前面
	dinsertafter(list,&s);//插入到头结点后面
//	dinsertbeforen(list,&a,3);
//	printf("just insert at a right positision 4\n");
//	dinsertaftern(list,&b,4);
//	printf("the the index larger than the length  the wrong position 15\n");
//	dinsertaftern(list,&b,15);
//	printf("scan from head to tail\n");
	myscan(list,myprintchar);
//	list = list->next;
//	list = list->next;
//	char ch = *(char * )list->next->data;
//	printf("1111111\n%c\n11111\n",ch);
//	myscan(list,myprintchar);
	quicksortlist(list,chrcmp);
	myscan(list,myprintchar);
/*	printf("scan from tail to head\n");
	myrescan(list,myprintchar);
	int j = dlistlength(list);//求链表长度
	printf("the length of the list is \n%d\n",j);
	
	printf("sort the list and we get  \n");

	ret f =sortlist(list,chrcmp);
	myscan(list,myprintchar);
	printf("del the node in 2 \n");
	 f = ddeletenoden(list,3);
	if(f==OK)
	printf("delete OK\n");
	else printf("ERROR\n");
	printf("del the node with length larger than index  100\n");
	f = ddeletenoden(list,100);
	if(f==OK)
	printf("delete OK\n");
	else printf("delete  ERROR\n");
	myscan(list,myprintchar);
	printf("drop all the nodes with value c\n");
	ddeletenode(list,&c);//删除结点值为c的所有结点
	myscan(list,myprintchar);
	 j = dlistlength(list);//求链表长度
	printf("the length of the list is \n%d\n",j);
	printf("insert a node ahead of any position  2\n");
	dinsertbeforen(list,&c,2);
	myscan(list,myprintchar);
	printf("insert a node  after  any position  3\n");
	dinsertaftern(list,&a,3);
	myscan(list,myprintchar);
	printf("cp all the node with value a to the node with value b\n");
	setitem(list, &b, &a);
	myscan(list,myprintchar);
	
	
	Dlinklist list1;
	list1 = initlist();//初始化
	char x='a';
	char y ='b';
	char z ='c';
	dinsertbefore(list1,&x);//插入到头结点前面
	dinsertbefore(list1,&y);//插入到头结点前面
	dinsertafter(list1,&z);//插入到头结点后面
	printf("another list is ready \n");
	myscan(list1,myprintchar);
	Dlinklist list2 = mergelist(list,list1);
	printf("make the list and list1 as one list\n");
	myscan(list2,myprintchar);
	printf("sort the new list\n");
	sortlist(list2, chrcmp);
	myscan(list2,myprintchar);
	printf("then  we clear the list\n");
	dclearlist(list);//将链表清空
	f = disempty(list);
	if(f==OK)
	printf("it's not empty\n");
	else printf("it is empty\n");
	printf("destroy the list\n");
	ddestroylist(list);
	if(list)
	printf("its gone\n");
	else printf("it's still here\n");
*/
}
	
void testcharp()
{	printf("--------------------------------------\n");
	printf("test for the char pointer\n");
	Dlinklist list;
	char* a1="xxx";
	char* b1 ="yyy";
	char* c1 ="zzz";
	char* d1="ddd";
	char* e1="aaa";
	list = initlist();	
	dinsertbefore(list,a1);
	dinsertbefore(list,b1);
	dinsertafter(list,c1);
	dinsertafter(list,c1);
	dinsertafter(list,c1);
	dinsertafter(list,c1);
	dinsertafter(list,d1);
	dinsertafter(list,e1);
 	int  j = dlistlength(list);
	printf("the length of the list is \n%d\n",j);
	printf("scan from head to tail\n");
	myscan(list,myprintstr);
	printf("scan from tail to head\n");
	myrescan(list,myprintstr);
	printf("delete all the node with node c1\n");
	ddeletenode(list,c1);
	j = dlistlength(list);
	printf("the length of the list is \n%d\n",j);
	printf("cp the node with the value a1 to b1's\n");
	setitem(list, a1, b1);
	myscan(list,myprintstr);
	
	j = dlistlength(list);
	printf("the length of lists is    %d \n",j);
	printf("test list is empty or not\n");
	ret f = disempty(list);
	if(f==OK)
	printf("it's not empty\n");
	else printf("it is empty\n");
	 ret x = sortlist(list,chrcmp);
	myrescan(list,myprintstr);

//以下测试将两个链表合并，并按升序并按升序排列
	Dlinklist list1,list2;
	Dlinklist list3;
	list1 = initlist();
	char * i ="iii";	
	char * jj ="jjj";	
	dinsertbefore(list1,i);

	dinsertbefore(list1,i);
	dinsertbefore(list1,jj);
	printf("the list1 has the value of\n");
	myscan(list1, myprintstr);
	printf("list1 is ready\n");
	list3 = mergelist(list,list1);
	printf("after deal,the final list has the value of:\n");
	myscan(list3, myprintstr);
	printf("test for destroy\n");
	printf("clear the list");
	dclearlist(list);
	 f = disempty(list);
	if(f==OK)
	printf("it's not empty\n");
	else printf("it is empty\n");
	
	ddestroylist(list);

	if(list)
	printf("its gone\n");
	else printf("it's still here\n");
	myscan(list3, myprintstr);

//	 f = disempty(list);
//	disempty(a);/////
}
void testint()
{	printf("----------------------------------\n");
	printf("test for the int\n");
	Dlinklist list;	
	list = initlist();
	 int a2= 55;
	 int  b2 =3;
	 int c2 =85;
	 int c3 =35;
	dinsertbefore(list,&a2);//插入到头结点前面
	dinsertbefore(list,&b2);//插入到头结点前面
	dinsertafter(list,&c2);
	dinsertafter(list,&c2);//插入到头结点后面
	dinsertafter(list,&b2);
	dinsertaftern(list,&c3,4);
	dinsertbeforen(list,&a2,5);
	printf("scan head ->tail\n");
	myscan(list,myprintint);
	printf("sort the list\n");
	sortlist(list,intcmp);
	myscan(list,myprintint);
	int  j = dlistlength(list);//求链表长度
	printf("the length of the list is: %d\n",j);
	printf("scan tail ->head\n");
	myrescan(list,myprintint);
	printf("delete the node with vale c:\n");
	ddeletenode(list,&c2);//删除结点值为c的所有结点
	myscan(list,myprintint);
	printf("cp the node a to b\n");
	setitem(list, &a2, &b2);//将结点值为a的所有值替换为 b
	myscan(list,myprintint);

	Dlinklist list1;
	list1 = initlist();
	int a =21;
	int b =31;
	int c=41;
	dinsertbefore(list1,&a);//插入到头结点前面
	dinsertbefore(list1,&b);//插入到头结点前面
	dinsertbefore(list1,&c);//插入到头结点前面
	printf("list 1 is ready\n");
	myscan(list1,myprintint);
	printf("gether list and list1\n");
	Dlinklist list2 = mergelist(list,list1);
	myscan(list2,myprintint);
	printf("sort the list2\n");
	sortlist(list2,intcmp);
	myscan(list2,myprintint);
	printf("\nclear the list\n");
	dclearlist(list);//将链表清空
	ret f = disempty(list);
	if(f==OK)
	printf("it's not empty\n");
	else printf("it is empty\n");
	printf("destroy the list\n");
	ddestroylist(list);
	if(list)
	printf("its gone\n");
	else printf("it's still here\n");
}




void teststruct()
{	printf("-----------------------------------\n");
	printf("test for the value for struct\n");
	Dlinklist list;	
	char flag = 's';
	list = initlist();
	ST *st1=malloc(sizeof(ST));
	st1->aint = 5;
	st1->achar = 'a';
	st1->acharp = "aaa";
	ST *st2=malloc(sizeof(ST));
	ST *st3=malloc(sizeof(ST));
	st2->aint = 7;
	st2->achar = 'b';
	st2->acharp = "bbb";
	st3->aint = 6;
	st3->achar = 'c';
	st3->acharp = "ccc";
	dinsertafter(list,st1);
	dinsertbefore(list,st2);//插入到头结点前面
	dinsertbefore(list,st3);//插入到头结点前面
	dinsertafter(list,st1);
//	printf("%d \n",st1->aint);
//	printf("%c \n",st1->achar);
//	printf("%s \n",st1->acharp);
	
	printf("scan the list from head to tail\n");
	myscan(list,myprintst);
	printf("scan the list from tail to head\n");
	myrescan(list,myprintst);
	printf("sort the list by int \n");
	sortlist(list,strtcmpint);
	myscan(list,myprintst);
	printf("sort the list by charp\n");
	sortlist(list,strtcmpcharp);
	myscan(list,myprintst);
	int  j = dlistlength(list);//求链表长度
	printf("the length of the list is: %d\n",j);
	printf("scan head ->tail\n");
	myscan(list,myprintst);
	printf("scan tail ->head\n");
	myrescan(list,myprintst);
	printf("del the node with index of 3\n");
	ddeletenoden(list,3);
	myscan(list,myprintst);
//	printf("cp the node a to b\n");
//	setitem(list, &a2, &b2);//将结点值为a的所有值替换为 b
//	myscan(list,myprintint);
//	printf("\nclear the list\n");
	dclearlist(list);//将链表清空
	ret f = disempty(list);
	if(f==OK)
	printf("it's not empty\n");
	else printf("it is empty\n");
	printf("destroy the list\n");
	ddestroylist(list);
	if(list)
	printf("its gone\n");
	else printf("it's still here\n");
/////////////////////////////////////////////////////////////////////

}




void main()
{
	int cho;
	int loop=1;
	while(loop)
	{
		printf("1-char 2-char * 3-int  4-struct\n");
		scanf("%d",&cho);
		switch(cho){
			case 1:testchar();break;
			case 2:testcharp();break;
			case 3:testint();break;
			case 4:teststruct();break;
			default :printf("inpurt wrong\n");break;

		}
	printf("1-again  0-exit\n");
	scanf("%d",&loop);
	}
}










