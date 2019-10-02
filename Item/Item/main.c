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

/*#include<stdio.h>
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
}*/

/*#include<stdio.h>
#include<string.h>
void Function(int num[],int len)
{
	for (int i = 0; i <= len / 2; i++)
	{
		if (num[i] != num[len - 1 - i])
		{
			printf("不是回文数!\n");
			return;
		}
	}
	printf("是回文数!\n");
	return;
}
int main()
{
	int input[10] = { 0 };
	int len;
	scanf_s("%d", &input);
	len = strlen(input);
	Function(input,len);
	}*/

/*#include<stdio.h>
typedef struct Student
{
	int data;
	struct Student * next;
}Student,*PList;
void InitList(Student *list)
{
	if (list->next == NULL)
	{
		return;
	}
	list->data = 0;
	list->next = NULL;
}
Student *GetNode(int val)
{
	Student *pGet = (Student*)malloc(sizeof(Student));
	pGet->data = val;
	pGet->next = NULL;
	return pGet;
}
void HeadList(Student *list, int val)
{
	Student *pGet = GetNode(val);
	pGet->next = list->next;
	list->next = pGet;
}
void Show(Student *list)
{
	Student *pCur = list->next;
	while (pCur != NULL)
	{
		printf("%d ", pCur->data);
		pCur = pCur->next;
	}
}
Student *LastKNode(Student *list, int val)//找倒数第K个节点
{
	int count = val-1;
	Student *pCur1 = list->next;
	Student *pCur2 = list->next;
	while (count != 0)
	{
		pCur1 = pCur1->next;
		if (pCur1->next == NULL)
		{
			printf("节点不够！");
			break ;
		}
		count--;
	}
	while (pCur1->next != NULL)
	{
		pCur1 = pCur1->next;
		pCur2 = pCur2->next;
	}
	return pCur2;
}
void TailList(Student *list, int val)
{
	Student *pCur = list;
	while ((pCur->next) != NULL)
	{
		pCur = pCur->next;
	}
	Student* pGet = GetNode(val);
	pGet->next = pCur->next;
	pCur->next = pGet;
}
int main()
{
	Student list;
	InitList(&list);
	HeadList(&list, 10);
	HeadList(&list, 20);
	HeadList(&list, 30);
	HeadList(&list, 40);
	HeadList(&list, 50);
	HeadList(&list, 60);
	HeadList(&list, 70);
	TailList(&list, 80);
	TailList(&list, 90);
	TailList(&list, 99);
	printf("%d\n", LastKNode(&list, 3)->data);
	Show(&list);
}*/

/*#include<stdio.h>
typedef struct LNode
{
	int data;
	struct LNode *next;
}LNode,PList;
void Init(PList *list)
{
	if (list->next == NULL)
	{
		return;
	}
	list->next = NULL;
}
LNode *GetNode( int val)
{
	LNode *pGet = (LNode *)malloc(sizeof(LNode));
	pGet->data = val;
	pGet->next = NULL;
	return pGet;
}
void Tail(PList *list, int val)
{
	LNode *pCur = list->next;
	while (pCur->next != NULL)
	{
		pCur = pCur->next;
	}
	LNode *pGet = GetNode(val) ;
	pGet->next = pCur->next ;
	pCur->next = pGet;
}
void Show(PList *list)
{
	LNode *pCur = list;
	while (pCur != NULL)
	{
		printf("%d  ", pCur->data);
		pCur = pCur->next;
	}
}
int main()
{
	LNode list;
	Tail(&list, 10);
	Tail(&list, 20);
	Tail(&list, 30);
	Show(&list);
}*/


/*#include<stdio.h>
int Function(int arr)
{
	//int len;
	//len = sizeof(arr) / sizeof(arr[0]);
	//printf("%d", len);
	if (arr == 10)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int main()
{
	int arr = 10;
	printf("%d",Function(arr));
}*/
/*#include<stdio.h>
int hasGroupsSizeX(int* deck, int deckSize){
	int count = 0;
	if (deckSize<2)
	{
		return 0;
	}
	else
	{
		for (int i = 0; i <= 100; i++)//母数
		{
			for (int j = 0; j <= 100; j++)//子数
			{
				if (deck[i] == deck[j])
				{
					count++;
				}
			}
			if (count%deckSize != 0)
			{
				return 0;
			}
			count = 0;
		}
		return 1;
	}
}
int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 6, 5, 4, 3, 2, 1 };
	printf("%d",hasGroupsSizeX(arr, 2));
}*/

/*int game(int* guess, int guessSize, int* answer, int answerSize){
	int count = 0;
	for (int i = 0; i<guessSize; i++)
	{
		if (guess[i] == answer[i])
		{
			count++;
		}
	}
	return count;
}*/

/*#include<stdio.h>
int main()
{
	char J[] = "HelloWorld";
	printf("%c  ", *J);
	printf("%s  ", J);
	printf("%c  ", J[0]);
}*/

/*int numJewelsInStones(char * J, char * S){
	int count = 0;
	for (int i = 0; i<(int)strlen(J); i++)
	{
		for (int j = 0; j<(int)strlen(S); j++)
		{
			if (*(J + i) == *(S + j))
			{
				count++;
			}
		}
	}
	return count;
}*/

/*#include<stdio.h>
char * defangIPaddr(char * address)
{
	for (char i = 0; i < 15; i++)
	{
			if (*(address + i) == '.')
			{
				*(address + i) = '[.]';
			}
	}
	return address;
}
int main()
{
	char address = "120.345.655.342";
	printf("%s\n",defangIPaddr(&address));
}*/
/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     struct ListNode *next;
* };
*/
//删除节点，只给删除的节点
/*void deleteNode(struct ListNode* node) {
	node->val = node->next->val;
	node->next = node->next->next;
}


//大写转小写
char * toLowerCase(char * str){
	for (int i = 0; i<strlen(str); i++)
	{
		if ((str[i] >= 'A') && (str[i] <= 'Z'))
		{
			str[i] = (char)(str[i] + 32);
		}
	}
	return str;
}

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     struct ListNode *next;
* };


struct ListNode* middleNode(struct ListNode* head){
	struct ListNode * pFast = head;
	struct ListNode * pSlow = head;
	while ((pFast) != NULL && (pFast->next != NULL))
	{
		pSlow = pSlow->next;
		pFast = pFast->next->next;
	}
	return pSlow;
}*/


/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     struct ListNode *next;
* };



//两有序链表合并，合并链表从大到小输出
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
	if (l1 == NULL)
		return l2;
	if (l2 == NULL)
		return l1;
	if (l1->val<l2->val)
	{
		l1->next = mergeTwoLists(l1->next, l2);
		return l1;
	}
	else{
		l2->next = mergeTwoLists(l1, l2->next);
		return l2;
	}
}*/

//汉明距离
/*int hammingDistance(int x, int y){
	int count = 0;
	for (int i = 0; i<32; i++)
	{
		if (((x >> i) & 1) != ((y >> i) & 1))
		{
			count++;
		}
	}
	return count;
}*/



//查找两链表相同节点
/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     struct ListNode *next;
* };

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
	int countA = 0;
	int countB = 0;
	int tmp = 0;
	struct ListNode* pCur1 = headA;
	struct ListNode* pCur2 = headB;
	while (pCur1->next != NULL)
	{
		countA++;
		pCur1 = pCur1->next;
	}
	while (pCur2->next != NULL)
	{
		countB++;
		pCur2 = pCur2->next;
	}
	tmp = abs(countA - countB);
	if (countA>countB)
	{
		while (tmp)
		{
			pCur1 = pCur1->next;
			tmp--;
		}
	}
	else
	{
		while (tmp)
		{
			pCur2 = pCur2->next;
			tmp--;
		}
	}
	while ((pCur1->next) != (pCur2->next))
	{
		pCur1 = pCur1->next;
		pCur2 = pCur2->next;
	}
	return pCur1;
}*/

#include<stdio.h>
typedef struct LNode
{
	int val;
	struct LNode* next;
}LNode,List;
void Init(List *list)
{
	if (list->next == NULL)
	{
		return;
	}
	list->val = 0;
	list->next = NULL;
}
LNode * GetNode(int val)
{
	LNode * pGet =(LNode*)malloc(sizeof(LNode));
	pGet->val = val;
	pGet->next = NULL;
	return pGet;
}
void Head(List *list, int val)
{
	LNode *pGet = GetNode(val);
	pGet->next = list->next;
	list->next = pGet;
}
void Show(List *list)
{
	LNode *pCur = list;
	while (pCur != NULL)
	{
		printf("%d ", pCur->val);
		pCur = pCur->next;
	}
}
void Tail(List *list, int val)
{
	LNode* pCur = list;
	LNode *pGet = (LNode *)malloc(sizeof(LNode));
	while (pCur->next != NULL)
	{
		pCur = pCur->next;
	}
	pCur->next = pGet;
	pGet->next = NULL;
}
void Delete(List *list, int val)
{
	int count = 1;
	LNode *pCur = list;
	while (count != val)
	{
		pCur = pCur->next;
		count++;
	}
	pCur = pCur->next->next;
}
void Showlist(List *list)
{
	LNode * pCur = list;
	while (pCur->next != NULL)
	{
		printf("%d  ", pCur->val);
		pCur = pCur->next;
	}
}
int main()
{
	LNode list;
	Init(&list);
	Head(&list, 10);
	Head(&list, 20);
	Head(&list, 30);
	Head(&list, 40);
	Tail(&list, 50);
	Delete(&list, 3);
	Show(&list);
}

