#define _CRT_SECURE_NO_WARNINGS 1
/*#include<stdio.h>
void SListInit(SListNode** pphead)
{
	*pphead = (SListNode*)malloc(sizeof(SListNode));
	(*pphead)->data = 0;
	(*pphead)->next = NULL;
}

void SListDestory(SListNode* phead)
{
	while (phead->next)
	{
		SListEraseAfter(phead);
	}
	free(phead);
}

SListNode* BuyListNode(SLTDataType x)
{
	SListNode* res = (SListNode*)malloc(sizeof(SListNode));
	res->data = x;
	res->next = NULL;
	return res;
}

void SListPushFront(SListNode** pphead, SLTDataType x)//头插
{
	SListNode *tmp;
	//	if (*pphead == NULL)
	//{
	//*pphead = BuySListNode(x);
	//return;
	//}
	tmp = BuyListNode(x);
	tmp->next = *pphead;
}
void SListPopFront(SListNode** pphead)//头删
{
	SListNode* tmp = (*pphead)->next;
	if (*pphead == NULL)//头删头不能为空
	{
		return;
	}
	free(*pphead);
	*pphead = tmp;
}

void SListInsertAfter(SListNode* pos, SLTDataType x)//后插
{
	SListNode* tmp = BuyListNode(x);
	tmp->next = pos->next;
	pos->next = tmp;
}
void SListEraseAfter(SListNode* pos)//后删
{
	SListNode* tmp = pos->next;
	if (tmp == NULL)
	{
		return;
	}
	pos->next = tmp->next;
	free(tmp);
}
SListNode* SListFind(SListNode* phead, SLTDataType x)//查找某一个x
{
	SListNode* tmp;
	for (tmp = phead; tmp; tmp = tmp->next)
	{
		if (tmp->data == x)
		{
			return tmp;
		}
	}
}
void SListRemove(SListNode** pphead, SLTDataType x)
{
	SListNode* tmp;
	if ((*pphead)->data == x)
	{
		SListPopFront(pphead);
		return;
	}
	for (tmp = *pphead; tmp->next; tmp = tmp->next)
	{
		if (tmp->next->data == x)
		{
			SListEraseAfter(tmp);
			return;
		}
	}
}
void SListPrint(SListNode* phead)
{
	SListNode* tmp;
	for (tmp = phead; tmp; tmp = tmp->next)
	{
		printf("%d->", tmp->data);
	}
	printf("NULL\n");
}
typedef struct Node
{
	int data;
	struct Node* next;
}Node, *PList;
void InitList(PList list)
{
	if (list->next == NULL)
	{
		return;
	}
	list->data = 0;
	list->next = NULL;
}
Node *GetNode(int val)
{
	Node* pGet = (Node*)malloc(sizeof(Node));
	pGet->data = val;
	pGet->next = NULL;
	return pGet;
}
void InsertHead(PList list, int val)
{
	Node* pGet = GetNode(val);
	pGet->next = list->next;
	list->next = pGet;
}
void Show(PList list)
{
	Node *pCur = list->next;
	while (pCur != NULL)
	{
		printf("%d->", pCur->data);
		pCur = pCur->next;
	}
	printf("NULL");
	printf("\n");
}
void InsertTail(PList list, int val)
{
	Node* pCur = list->next;
	while (pCur->next != NULL)
	{
		pCur = pCur->next;
	}
	Node* pGet = GetNode(val);
	pCur->next = pGet;
}
int GetLength(PList list)
{
	Node *pCur = list->next;
	int count = 0;
	while (pCur != NULL)
	{
		count++;
		pCur = pCur->next;
	}
	return count;
}
Node* Find(PList list, int val)
{
	Node* pCur = list->next;
	int count = 1;
	while (count != val)
	{
		pCur = pCur->next;
		count++;
	}
	return pCur;
}
int main()
{
	Node list;
	InitList(&list);
	InsertHead(&list, 10);
	InsertHead(&list, 20);
	InsertHead(&list, 30);
	InsertTail(&list, 40);
	InsertTail(&list, 50);
	InsertTail(&list, 60);
	Node* pGet = Find(&list, 3);
	printf("第%d个节点是%d\n", 3, pGet->data);
	printf("%d\n", GetLength(&list));
	Show(&list);
}*/

/*#include<stdio.h>
#include<string.h>
typedef struct student
{
	char no[8];
	char name[20];
	int score;
}Student;
typedef struct LNode
{
	Student data;
	struct LNode *next;
}LNode, *LinkList;
void Init(LinkList list)
{
	if (list == NULL)
	{
		return;
	}
	list->next = NULL;
}
LNode *GetNode(Student stu)//生成一个节点
{
	LNode * pGet = (LNode *)malloc(sizeof(LNode));
	strcpy(pGet->data.name, stu.name);
	strcpy(pGet->data.no, stu.no);
	//pGet->data.name = stu.name;
	//pGet->data.no = stu.no;
	pGet->data.score = stu.score;
	pGet->next = NULL;
	return pGet;
}
void Insert(LinkList list, Student stu)//尾插
{
	LNode *pCur = list;
	while ((pCur->next) != NULL)
	{
		pCur = pCur->next;
	}
	LNode *pGet = GetNode(stu);
	pCur->next = pGet;
}
void Show(LinkList list)	//打印
{
	LNode *pCur = list->next;
	while (pCur != NULL)
	{
		printf("%s ", pCur->data.no);
		printf("%10s ", pCur->data.name);
		printf("%4d ", pCur->data.score);
		printf("\n");
		pCur = pCur->next;
	}
	printf("\n");
}
LNode *Locate(LinkList list, char *name)	//姓名查找
{
	LNode *pCur = list->next;
	//while (pCur->data.name != name)
	//while (strcpy(pCur->data.name,*name)!=pCur->data.name)
	while (strcmp(pCur->data.name,name))
	{
		pCur = pCur->next;
	}
	return pCur;
}
LNode *Find(LinkList list, int val)	//第val个节点查找
{
	LNode *pCur = list->next;
	int count = 1;
	while (count != val)
	{
		pCur = pCur->next;
		count++;
	}
	return pCur;
}
void Delete(LinkList list, int val)	//删除第val个节点
{
	LNode* pCur = list;
	int count = 1;
	while (count != val)
	{
		pCur = pCur->next;
		count++;
	}
	//LNode *p = pCur;
	pCur->next = pCur->next->next;
	//free(p->next);
}
int Getlength(LinkList list)	//得到长度
{
	int count = 0;
	LNode* pCur = list->next;
	while (pCur != NULL)
	{
		count++;
		pCur = pCur->next;
	}
	return count;
}
void ListInsert(LinkList list, Student stu, int val)//插入到第val个节点
{
	LNode *pCur = list;
	int count = 1;
	while (count != val)
	{
		pCur = pCur->next;
		count++;
	}
	LNode *pGet = GetNode(stu);
	pGet->next = pCur->next;
	pCur->next = pGet;
}
int main()
{
	Student stu1 = { "0210", "zhansan", 70 };
	Student stu2 = { "0211", "lisi", 78 };
	Student stu5 = { "0214", "world", 99 };
	Student stu3 = { "0212", "wangwu", 80 };
	Student stu4 = { "0213", "hello", 90 };		//定义学生信息
	LNode list;
	Init(&list);
	Insert(&list, stu1);
	Insert(&list, stu2);
	Insert(&list, stu3);
	Insert(&list, stu4);					//插入学生信息
	LNode* pCur =Find(&list, 3);
	printf("%s  %d\n", Locate(&list, &stu2.name)->data.no, Locate(&list, &stu2.name)->data.score);//按照姓名查找，返回学号和成绩
	printf("%s %10s %4d\n", pCur->data.no, pCur->data.name, pCur->data.score);//第val个节点查找，返回学生的信息
	printf("%d\n", Getlength(&list));	//得到链表的长度
	ListInsert(&list, stu5,3);//插入到第val个节点
	Show(&list);
	Delete(&list, 2);	//删除第val个节点的信息
	Show(&list);
	return 0;
}*/

#include<stdio.h>
#include<math.h>
//给出一个 32 位的有符号整数，你需要将这个整数中每位上的数字进行反转。

int Function(int num)
{
	int tmp = 0;
	int count = 0;
	int arr[10] = { 0 };
	int x= (num >> 32) & 1;//存符号位
	for (int i = 0;num&&( i < 10); i++)
	{
		arr[i] = num % 10;//arr[0]=个位；arr[1]=十位；arr[2]=百位
		num = num / 10;
		count++;
	}
	for (int j = 0; j < 10; j++)
	{
		tmp = tmp + arr[j]*pow(10, count-1-j);
	}
	tmp = tmp*pow(1, x);
	return tmp;
}
int main()
{
	int input = 0;
	scanf_s("%d", &input);
	printf("%d\n", Function(input));
}