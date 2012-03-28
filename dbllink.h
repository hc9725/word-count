#ifndef DBLLINK_H
#define DBLLINK_H
typedef struct
{
	int frq;
	char *word;
}STWD;
	typedef struct  
	{
		int aint;
		char achar;
		char *acharp;

	}ST;
typedef struct dlnode{
	void *data;
	struct dlnode *prior, *next;
	}Dlnode;
typedef enum Ret
{
	OK =1,
	ERROR,
	NO,
}ret;
typedef Dlnode *Dlinklist;///////////////要加＊，，把node 和link分开。
Dlinklist head;
typedef void *(VisitFunc)(void *data);
//typedef int *(Chgcmp)(void *a,void *b);
//static int chgcmp(const void * a, const void *b);
Dlinklist  initlist();//创建一个链表
Dlinklist dgethead(Dlinklist p);//获得头结点指针
Dlinklist dmakenode(void *e);//创建一个结点
ret dinsertbefore(Dlinklist p, void *e);//在头结点前插入结点
ret  dinsertafter(Dlinklist p, void *e);//在头节点后插入结点
ret dinsertbeforen(Dlinklist p, void *e, int index);//在任意结点前插入结点
ret  dinsertaftern(Dlinklist p, void *e,int index);//在任意节点后插入结点
ret ddeletenode(Dlinklist p,void *e);// 删除含某个值的所有结点 在结构体中未实现
ret ddeletenoden(Dlinklist p,int index);// 删除第index个结点
Dlinklist dlocateitem( Dlinklist p, void *e); // 查找元素在链表中的位置
ret setitem(Dlinklist p,void *e, void *edest);//改变某个位置的值   在结构体中未实现
int dlistlength(Dlinklist p);// 元素个数
Dlinklist dscan(Dlinklist p,VisitFunc visit);//正序遍历
Dlinklist drescan(Dlinklist p,VisitFunc visit);//逆序遍历
void ddestroylist(Dlinklist p);// 销毁某个表
Dlinklist dclearlist(Dlinklist p);//将链表置空
ret disempty(Dlinklist p);//判断表是否为空表
ret sortlist(Dlinklist p, int cmpall(const void *a,const void *b));//升序排列
ret quicksortlist(Dlinklist p, int cmpall(const void *a,const void *b));//升序排列
void quicksort(Dlinklist leftlist, Dlinklist rightlist , int left,int right, int cmpall(const void *a,const void *b));
//void sortdec();//降序排列  = 升序排列 ＋ 逆序遍历即可
Dlinklist  mergelist(Dlinklist pa, Dlinklist pb);//将两个链表合二为一

void myscan(Dlinklist list, VisitFunc visit);
void myrescan(Dlinklist list, VisitFunc visit);
	

#endif
