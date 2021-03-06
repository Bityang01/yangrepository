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

/*#include<stdio.h>
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
}*/

/*#include<stdio.h>
void Function(int * heights,int heightsSize)
{
	int tmp = 0;
	int *arr = heights;
	for (int i = 0; i<heightsSize; i++)
	{
		for (int j = i; j<heightsSize; j++)
		{
			if (arr[i]>arr[j])
			{
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
		}
	}
	for (int k = 0; k < heightsSize; k++)
	{
		printf("%d ", arr[k]);
	}
	printf("\n");
	for (int k = 0; k < heightsSize; k++)
	{
		printf("%d ", heights[k]);
	}
}
int main()
{
	int heights[] = { 1, 2, 5, 7, 5, 3, 4 };
	Function(&heights,7);
}


//leetcode对一个数组排序后和原数组比较有多少位不同
int heightChecker(int* heights, int heightsSize){
	int count = 0;
	int tmp = 0;
	int arr[100] = { 0 };
	memcpy(arr, heights, sizeof(int)*heightsSize);
	for (int i = 0; i<heightsSize; i++)
	{
		for (int j = i; j<heightsSize; j++)
		{
			if (arr[i]>arr[j])
			{
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
		}
	}
	for (int k = 0; k<heightsSize; k++)
	{
		if (heights[k] != arr[k])
		{
			count++;
		}
	}
	return count;
}*/

/*#include<stdio.h>
void Function(int * arr,int ASize)
{
	int *B = (int *)malloc(sizeof(int)*ASize);
	int tmp = 0;
	for (int i = 0; i<ASize; i++)
	{
		if (((arr[i] >>32)&1)==1)
		{
			tmp = abs(arr[i]);
		}
		B[i] = pow(tmp, 2);
	}
	for (int k = 0; k < ASize; k++)
	{
		printf("%d ", B[k]);
	}
}
int* sortedSquares(int* A, int ASize){
	int B[10000] = { 0 };
	memcpy(B, A, sizeof(int)*ASize);
	int tmp = 0;
	for (int i = 0; i<ASize; i++)
	{
		if (((A[i] >> 31) & 1) != 0)
		{
			tmp = abs(A[i]);
		}
		B[i] = pow(tmp, 2);
	}
	for (int j = 0; j<ASize; j++)
	{
		for (int k = j; k<ASize; k++)
		{
			if (B[j]>B[k])
			{
				tmp = B[j];
				B[j] = B[k];
				B[k] = tmp;
			}
		}
	}
	for (int k = 0; k < ASize; k++)
	{
		printf("%d ", B[k]);
	}
	return B;
}
int main()
{
	int arr[] = { -1, -3, 0, 5, 10 };
	//Function;
	sortedSquares(&arr, 5);
}*/



//自除数
/**
* Note: The returned array must be malloced, assume caller calls free().

int* selfDividingNumbers(int left, int right, int* returnSize){
int* a =malloc(sizeof(int)*(right - left + 1));
int tmp=0;
*returnSize=0;
int count=0;
if(left>0)
{
for(int i=left;i<right;left++,i++)
{
a[count]=i;
count++;
while(i)
{
tmp=i%10;
if(tmp==0||(left%tmp)!=0)
{
count--;
break;
}
i=i/10;
}
}
return a;
}
return NULL;
}
int* selfDividingNumbers(int left, int right, int* returnSize) {
	int* a = calloc(right - left + 1, sizeof(int));
	int i = 0;
	*returnSize = 0;
	while (left <= right){
		int flag = 0, temp = left;
		while (temp > 0){
			int b = temp % 10;
			if (b == 0 || left % b != 0){
				flag = 1;
				break;
			}
			temp = temp / 10;
		}
		if (flag == 0){
			a[i] = left;
			i++;
			(*returnSize)++;
		}
		left++;
	}

	return a;
} */

/*#include<stdio.h>
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
	//int *arr = malloc(sizeof(int) * 2);
	// int count=0;
	for (int i = 0; i<numsSize; i++)
	{
		for (int j = i + 1; j<numsSize; j++)
		{
			if ((nums[i] + nums[j]) == target)
			{
				returnSize[0] = i;
				returnSize[1] = j;

			}
		}
	}
	return returnSize;
}
int main()
{
	int arr[] = { 2, 7, 11, 15 };
	int returnSize[] = { 0 };
	twoSum(&arr, 4,9,&returnSize);
	printf("%d %d\n", returnSize[0], returnSize[1]);
}*/




//leetcode两数之和
/**
* Note: The returned array must be malloced, assume caller calls free().

int* twoSum(int* nums, int numsSize, int target, int* returnSize){
	int* arr = malloc(sizeof(int) * 2);
	*returnSize = 2;
	// int count=0;
	for (int i = 0; i<numsSize; i++)
	{
		for (int j = i + 1; j<numsSize; j++)
		{
			if ((nums[i] + nums[j]) == target)
			{
				arr[0] = i;
				arr[1] = j;

			}
		}
	}
	return arr;
}*/



/*int peakIndexInMountainArray(int* A, int ASize){
	int count = 0;
	while (ASize >= 3)
	{
		while (A[0]<A[1])
		{
			for (int i = 0; i<ASize; i++)
			{
				if (A[i]<A[i + 1])
				{
					count = i + 1;
				}
				else
				{
					break;
				}
			}
			for (int j = count; j<ASize; j++)
			{
				if (A[j]>A[j + 1])
				{
					if (j == ASize - 1)
					{
						return count;
					}
				}
			}
		}
	}
}*/

/*#include<stdio.h>

int Function(int* A, int ASize){
	for (int i = 0; i<ASize; i++)
	{
		if (A[i]>A[i + 1])
		{
			return i;
		}
	}
}

int main()
{
	int arr[] = { 0, 2, 1, 0 };
	printf("%d \n", Function(&arr,4));
}


//leetcode山脉数组的峰顶索引
int peakIndexInMountainArray(int* A, int ASize){
	int count = 0;
	for (int i = 0; i<ASize - 1; i++)
	{
		if (A[i]>A[i + 1])
		{
			count = i;
			break;
		}
	}
	return count;
}

*/




/*int findComplement(int num){
	int arr[32] = { 0 };
	int sum = 0;
	for (int i = 0; i<32; i++)
	{
		arr[i] = (num >> i) & 1;
	}
	for (int j = 0; j<32; j++)
	{
		if (arr[j] == 0)
		{
			arr[j] = 1;
		}
		else
		{
			arr[j] = 0;
		}
	}
	for (int k = 0; k<3; k++)
	{
		if (arr[k] == 1)
		{
			sum = sum + pow(2, k);
		}
	}
	return sum;
}


//leetcode数字的补数
int findComplement(int num){
	int tmp = 0;
	int count = num;
	while (count>0)
	{
		count = count >> 1;
		tmp = (tmp << 1) | 1;
	}
	return num^tmp;
}*/


/*#include<stdio.h>


/**
* Note: The returned array must be malloced, assume caller calls free().

int* sortArrayByParity(int* A, int ASize, int* returnSize){
	int tmp = 0;
	//int j=ASize-1;
	*returnSize = ASize;
	for (int i = 0; i<ASize; i++)
	{
		if ((A[i]) % 2 != 0)
		{
			for (int j = ASize - 1; j>0; j--)
			{
				if ((A[j] % 2) == 0)
				{
					tmp = A[i];
					A[i] = A[j];
					A[j] = tmp;
					break;
				}
			}
		}
	}
	return A;
}

int main()
{
	int arr[] = { 3, 1, 2, 4 };
	int aar1[] = { 0 };
	sortArrayByParity(&arr, 4, &aar1);
}



//leetcode按奇偶排序数组
/**
* Note: The returned array must be malloced, assume caller calls free().
*
int* sortArrayByParity(int* A, int ASize, int* returnSize){
	int tmp = 0;
	//int j=ASize-1;
	*returnSize = ASize;
	for (int i = 0; i<ASize; i++)
	{
		if ((A[i]) % 2 != 0)
		{
			for (int j = ASize - 1; j>i; j--)
			{
				if ((A[j] % 2) == 0)
				{
					tmp = A[i];
					A[i] = A[j];
					A[j] = tmp;
					break;
				}
			}
		}
	}
	return A;
}*/




/**
* Note: The returned array must be malloced, assume caller calls free().

char ** findWords(char ** words, int wordsSize, int* returnSize){
	char *arr1 = malloc(sizeof(char)*wordsSize);
	*returnSize = 0;
	int arr[26] = { 1, 2, 2, 1, 0, 1, 1, 1, 0, 1, 1, 1, 2, 2, 0, 0, 0, 0, 1, 0, 0, 2, 0, 2, 0, 2 };
	for (int i = 0; i<wordsSize; i++)
	{
		for (int j = 0; j<strlen((*words)[i]); j++)
		{
			if ((*(*words) + j)>'A'&&*((*words) + j)<'Z')
			{
				(*(*words) + j) += 32;
			}
			if (arr[(*(*words) + j) - 'a'] != arr[(*(*words)) - 'a'])
			{
				break;
			}
		}
	}
}*/




/**
* Note: The returned array must be malloced, assume caller calls free().

int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){
	int count = 0;
	int tmp = 0;
	int *arr = malloc(sizeof(int)*nums1Size);
	int *arr1 = malloc(sizeof(int)*nums1Size);
	for (int i = 0; i<nums1Size; i++)
	{
		for (int j = 0; j<nums2Size; j++)
		{
			if (nums1[i] == nums2[j])
			{
				arr[count] = nums1[i];
				count++;
			}
		}
	}
	for (int k = 0; k<nums1Size; k++)//arr1
	{
		for (int a = 0; a<nums1Size; a++)//arr
		{
			if (arr1[k] == arr[a])
			{
				break;
			}
			else
			{
				arr1[k] = arr[a];
			}
		}
	}
	for (int b = 0; b<nums1Size; b++)
	{
		if (arr1[b] != 0)
		{
			tmp++;
		}
	}
	*returnSize = tmp;
	return arr1;
}*/



/*#include<stdio.h>
int main()
{
	int arr[] = { 0 };
	for (int i = 0; i < 1000; i++)
	{
		int tmp = i;
		double sum = 0;
		int count = 0;
		while (tmp != 0)
		{
			arr[count] = tmp% 10;
			sum = sum + arr[count] * arr[count] * arr[count];
			count++;
			tmp = tmp / 10;
		}
		if (sum == i)
		{
			printf("%d \n",i);
		}
	}
}*/


/*bool uniqueOccurrences(int* arr, int arrSize){
	int *arr1 = malloc(sizeof(int)*arrSize);
	int ret = 0;
	for (int i = 0; i<arrSize; i++)
	{
		int tmp = 0;
		int count = 0;
		for (int k = i; (i != 0) && (k>0); k--)
		{
			if (arr[i] == arr[k - 1])
			{
				tmp = 1;
				break;
			}
		}
		if (tmp == 1)
		{
			continue;
		}
		for (int j = i; j<arrSize; j++)
		{
			if (arr[i] == arr[j])
			{
				count++;
			}
		}
		arr1[ret] = count;
		ret++;
	}
	for (int a = 0; a<ret; a++)
	{
		for (int b = a; b<ret; b++)
		{
			if (arr1[a] == arr1[b])
			{
				return false;
			}
		}
	}
	return true;
}*/

//leetcode给定一个非负整数 num，反复将各个位上的数字相加，直到结果为一位数
/*int addDigits(int num){
	int sum = num;
	while (sum >= 10)
	{
		num = sum;
		sum = 0;
		while (num)
		{
			sum = sum + num % 10;
			num = num / 10;
		}
	}
	return sum;
}*/

//斐波那契数
/*int fib(int N){
	if (N == 0)
		return 0;
	if (N == 1 || N == 2)
		return 1;
	else
	{
		return fib(N - 1) + fib(N - 2);
	}
}*/

//leetcode按奇偶排序数组，奇数位放奇数，偶数位放偶数
/**
* Note: The returned array must be malloced, assume caller calls free().

int* sortArrayByParityII(int* A, int ASize, int* returnSize){
	int a = 1;
	int b = 0;
	int *arr = malloc(sizeof(int)*ASize);
	for (int i = 0; i<ASize; i++)
	{
		if (A[i] % 2 != 0)
		{
			arr[a] = A[i];
			a += 2;
		}
		else{
			arr[b] = A[i];
			b += 2;
		}
	}
	if (a - 1>b - 1)
	{
		*returnSize = a - 1;
	}
	else{
		*returnSize = b - 1;
	}
	return arr;
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
	while (strcmp(pCur->data.name, name))
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
	LNode* pCur = Find(&list, 3);
	printf("打印链表\n");
	Show(&list);
	printf("按照姓名查找，返回学号和成绩(lisi)\n");
	printf("%s  %d\n", Locate(&list, &stu2.name)->data.no, Locate(&list, &stu2.name)->data.score);//按照姓名查找，返回学号和成绩
	printf("第3个节点查找，返回学生的信息\n");
	printf("%s %10s %4d\n", pCur->data.no, pCur->data.name, pCur->data.score);//第val个节点查找，返回学生的信息
	printf("链表的长度\n");
	printf("%d\n", Getlength(&list));	//得到链表的长度
	printf("插入到第3个节点\n");
	ListInsert(&list, stu5, 3);//插入到第val个节点
	Show(&list);
	printf("删除第2个节点的信息\n");
	Delete(&list, 2);	//删除第val个节点的信息
	Show(&list);
	return 0;
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
	while (strcmp(pCur->data.name, name))
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
	LNode* pCur = Find(&list, 3);
	printf("%s  %d\n", Locate(&list, &stu2.name)->data.no, Locate(&list, &stu2.name)->data.score);//按照姓名查找，返回学号和成绩
	printf("%s %10s %4d\n", pCur->data.no, pCur->data.name, pCur->data.score);//第val个节点查找，返回学生的信息
	printf("%d\n", Getlength(&list));	//得到链表的长度
	ListInsert(&list, stu5, 3);//插入到第val个节点
	Show(&list);
	Delete(&list, 2);	//删除第val个节点的信息
	Show(&list);
	return 0;
}*/


/*int countPrimeSetBits(int L, int R){
	int count = 0;
	for (int i = L; i <= R; i++)
	{
		int ret = 0;
		int tmp = 0;
		for (int j = 0; j<32; j++)//判断有多少个1
		{
			if (((i >> j) & 1) == 1)
			{
				tmp++;
			}
		}
		for (int k = 2; k <= sqrt(tmp); k++)//判断是不是素数
		{
			if ((tmp%k) == 0)
			{
				ret = 1;//不是素数
				break;
			}
		}
		if (ret == 0)
		{
			count++;
		}
	}
	return count;
}*/


//顺序栈
/*#include<stdio.h>
#include<stdlib.h> 
#include<conio.h>
#define maxsize 20
#define datatype char
typedef struct
{
	datatype data[maxsize];
	int top;
}SeqStack;
void InitStack(SeqStack *s)
{
	s->top = -1;
}
int Push(SeqStack *s, datatype x)
{
	if (s->top == maxsize - 1)
		return 0;
	s->data[++s->top] = x;
	return 1;
}
int Pop(SeqStack *s, datatype *x)
{
	if (s->top == -1)
		return 0;
	*x = s->data[s->top--];
	return 1;
}
int GetTop(SeqStack *s, datatype *x)
{
	if (s->top == -1)
		return 0;
	*x = s->data[s->top];
	return 1;
}
char menu(void)
{
	char ch;
	system("cls");
	printf("\n"); printf("\n");
	printf("                       顺序栈操作\n");
	printf("            =================\n");
	printf("                       请选择\n");
	printf("                       1、入栈\n");
	printf("                       2、出栈\n");
	printf("                       3、取栈顶元素\n");
	printf("                       0、退出\n");
	printf("            =================\n");
	printf("            选择（0，1，2，3）\n");
	ch = getchar();
	return (ch);
}
void main()
{
	SeqStack st;
	int flag = 1, k;
	datatype x;
	char choice;
	InitStack(&st);
	do{
		choice = menu();
		switch (choice)
		{
		case '1':
			printf("请输入入栈数据=？");
			scanf("%d", &x);
			k = Push(&st, &x);
			if (k)printf("入栈结束");
			else printf("栈为空");
			getchar();
			break;
		case '2':
			k = Pop(&st, &x);
			if (k) printf("出栈数据=%d\n",x);
			else printf("栈为空");
			getchar();
			break;
		case '3':
			k = GetTop(&st, &x);
			if (k) printf("栈顶元素=%d\n", x);
			else printf("栈为空");
			getchar();
			break;
		case '0':
			flag = 0;
			break;
		default:
			break;
		}
	} while (flag == 1);
}*/

/*#include<stdio.h>
typedef struct StackNode{
	int data;
	struct StackNode *next;
}StackNode,*LinkStack;
StackNode* Get(int val)
{
	StackNode* pGet = (StackNode*)malloc(sizeof(StackNode));
	pGet->data = val;
	pGet->next = NULL;
	return pGet;
}
void InitStack(LinkStack S)//链栈的初始化
{
	S = NULL;
}
void Push(LinkStack S, int val)//入栈
{
	StackNode* pGet = Get(val);
	pGet->next = S;
	S = pGet;
}
int Pop(LinkStack S)//出栈
{
	int val = 0;
	StackNode *p;
	if (S == NULL)
	{
		return 0;
	}
	val = S->data;
	//p = S;
	S = S->next;
	return val;
}
int main()
{
	//StackNode sta;
	LinkStack S = NULL;
	//InitStack(&sta);
	Push(&S, 10);
	Push(&S, 20);
	Push(&S, 30);
	printf("%d\n", Pop(&S));
	printf("%d\n",Pop(&S));
}


/*#include<stdio.h>
typedef struct StackNode{
	int data;
	struct StackNode* next;
}StackNode,*LinkStack;
void InitStack(LinkStack *S)//链栈的初始化
{
	S = NULL;
}
StackNode* Get(int val)
{
	StackNode* pGet = (StackNode*)malloc(sizeof(StackNode));
	pGet->data = val;
	pGet->next = NULL;
	return pGet;
}

int Pop(LinkStack S, int e)
{
	if (S == NULL)
	{
		return 0;    // 栈空
	}
	e = S->data;    //将栈顶元素赋值给e
	StackNode *p;
	p = S;         // 临时保存栈顶元素空间，准备释放
	S = S->next;    // 修改栈顶指针
	free( p);     // 释放原栈顶元素空间
	return 1;
}
int Push(LinkStack *S, int e)
{
	//元素e入栈
	//StackNode *p;
	StackNode* p = (StackNode*)malloc(sizeof(StackNode));
	p->data = e;        // 将新节点数据域置为e
	p->next = S;        // 将新节点插入栈顶
	S = p;             // 修改栈顶指针
	return 1;         // 链栈要注意指针的方向是从栈顶指向栈底的 
}

int main()
{
	//StackNode sta;
	LinkStack S ;
	InitStack(&S);
	Push(&S, 10);
	Push(&S, 20);
	printf("%d\n",Pop(&S, 20));
}*/



/*#include <iostream>

using namespace std;

// 链栈的存储结构
typedef struct StackNode
{
	int data;
	struct StackNode *next;
}StackNode, *LinkStack;

// 初始化
int InitStack(LinkStack &S)
{
	S = NULL;   // 将栈顶指针置空
	return 1;
}

// 入栈
int Push(LinkStack &S, int e)
{
	//元素e入栈
	StackNode *p;
	p = new StackNode;  // 生成新节点

	p->data = e;        // 将新节点数据域置为e
	p->next = S;        // 将新节点插入栈顶
	S = p;             // 修改栈顶指针
	return 1;         // 链栈要注意指针的方向是从栈顶指向栈底的 
}

// 出栈
int Pop(LinkStack &S, int &e)
{
	if (S == NULL)
	{
		return 0;    // 栈空
	}
	e = S->data;    //将栈顶元素赋值给e
	StackNode *p;
	p = S;         // 临时保存栈顶元素空间，准备释放
	S = S->next;    // 修改栈顶指针
	delete p;     // 释放原栈顶元素空间
	return 1;
}

// 取栈顶元素
int GetTop(LinkStack S)
{
	//返回S的栈顶元素,不修改栈顶指针
	if (S != NULL)  // 栈非空
		return S->data;  // 返回栈顶元素的值,栈顶指针不变
}

void TraveStack(LinkStack S)
{
	StackNode *p;
	p = S;
	while (p)
	{
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}

int main()
{
	LinkStack S;

	if (InitStack(S))
	{
		printf("链栈初始化成功!\n");
	}
	else
	{
		printf("链栈初始化失败!\n");
	}

	// 入栈
	int n;
	printf("请输入栈的元素个数:");
	scanf("%d", &n);
	for (int i = 0; i < n;)
	{
		int e;
		printf("请输入第%d个入栈的元素:", ++i);
		scanf("%d", &e);
		Push(S, e);
	}
	printf("遍历栈:\n");
	TraveStack(S);

	// 出栈（取出两个元素）
	for (int i = 0; i < 2;)
	{
		int a;
		Pop(S, a);
		printf("第%d个出栈的元素:%d\n", ++i, a);
	}
	printf("遍历栈:\n");
	TraveStack(S);

	printf("栈顶元素是:%d\n", GetTop(S));

	system("pause");

	return 0;


#include<stdio.h>
typedef struct StackNode
{
	int data;
	struct StackNode *next;
}StackNode, *LinkStack;

// 初始化
int InitStack(LinkStack &S)
{
	S = NULL;   // 将栈顶指针置空
	return 1;
}
int main()
{
	LinkStack S;

	if (InitStack(S))
	{
		printf("链栈初始化成功!\n");
	}
}}*/




//leetcode只出现一次的数字
/*int singleNumber(int* nums, int numsSize){
	for (int i = 0; i<numsSize; i++)
	{
		int ret = 0;
		for (int j = 0; j<numsSize; j++)
		{
			if (i == j)
				continue;
			if (nums[i] == nums[j])
			{
				ret = 1;
			}
		}
		if (ret == 0)
		{
			return nums[i];
		}
	}
	return 0;
}*/


/*#include<stdio.h>
typedef struct StackNode{
	int data;
	struct StackNode* next;
}StackNode,*LinkStack;
int InitStack(LinkStack s)//初始化栈
{
	s = NULL;
	return 1;
}
StackNode* GetNode(int val)//生成一个节点
{
	StackNode * pGet = (StackNode*)malloc(sizeof(StackNode));
	pGet->data = val;
	pGet->next = NULL;
	return pGet;
}
void Push(LinkStack s, int val)
{
	StackNode* pGet = GetNode(val);
	pGet->data = val;
	pGet->next = s;
	s = pGet;
}
void Show(LinkStack s)
{
	while (s->next != NULL)
	{
		printf("%d  ", s->data);
		s = s->next;
	}
}
int main()
{
	LinkStack S=NULL;
	InitStack(S);
	Push(S, 10);
	Push(S, 20);
	Push(S, 30);
	Show(S);
}*/


/**
* Note: The returned array must be malloced, assume caller calls free().

int* nextGreaterElement(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){
	*returnSize = nums1Size;
	int ret = 0;
	int *arr = malloc(sizeof(int)*nums1Size);
	for (int i = 0; i<nums1Size; i++)
	{
		for (int j = 0; j<nums2Size; j++)
		{
			if (j == nums2Size - 1)
			{
				arr[i] = -1;
				break;
			}
			if (nums1[i] == nums2[j])
			{
				for (int k = j; k<nums2Size; k++)
				{
					if (nums1[i]<nums2[k])
					{
						arr[i] = nums2[k];
						ret == 1;
						break;
					}
				}
				if (ret == 0)
				{
					arr[i] = -1;
				}
				break;
			}
		}
	}
	return arr;
}

//leetcode下一个更大的数
/**
* Note: The returned array must be malloced, assume caller calls free().

int* nextGreaterElement(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){
	*returnSize = nums1Size;
	int *arr = malloc(sizeof(int)*nums1Size);
	for (int i = 0; i<nums1Size; i++)
	{
		int ret = 0;
		for (int j = 0; j<nums2Size; j++)
		{
			if (nums1[i] == nums2[j])
			{
				for (int k = j; k<nums2Size; k++)
				{
					if (nums1[i]<nums2[k])
					{
						arr[i] = nums2[k];
						ret = 1;
						break;
					}
				}
				if (ret == 0)
				{
					arr[i] = -1;
				}
				break;
			}
		}
	}
	return arr;
}*/

/*#include<stdio.h>
int reverse(int x){
	double sum = 0;
	int number = x;
	int count = 0;
	int tmp = (x >> 31) & 1;//tmp=1时负数
	while (number)
	{
		count++;
		number = number / 10;
	}
	int *arr = malloc(sizeof(int)*count);
	for (int i = 0; i<count; i++)
	{
		arr[i] = x % 10;//arr[0]=3 arr[1]=2 arr[2]=1
		x = x / 10;
	}
	for (int j = 0; j<count; j++)
	{
		sum = sum + arr[j] * pow(10, count - 1 - j);
	}
	if (tmp == 1)
	{
		sum = sum*(-1);
		return sum;
	}
	else
	{
		return sum;
	}
}
int main()
{
	int sum = 10;
	printf("%d\n", reverse(-2147483648));
}



int reverse(int x){
	long sum = 0;
	int number = x;
	int count = 0;
	int tmp = (x >> 31) & 1;//tmp=1时负数
	//int X=abs(x);
	while (number)
	{
		count++;
		number = number / 10;
	}
	int *arr = malloc(sizeof(int)*count);
	for (int i = 0; i<count; i++)
	{
		arr[i] = X % 10;//arr[0]=3 arr[1]=2 arr[2]=1
		X = X / 10;
	}
	for (int j = 0; j<count; j++)
	{
		sum = sum + arr[j] * pow(10, count - 1 - j);
	}
	if (tmp == 1)
	{
		sum = sum*(-1);
		return sum;
	}
	else
	{
		return sum;
	}
}*/


//leetcode回文数
/*bool isPalindrome(int x){
	int count = 0;
	int number = x;
	while (number)
	{
		count++;
		number = number / 10;
	}
	int *arr = malloc(sizeof(int)*count);
	if (x<0)
	{
		return false;
	}
	x = abs(x);
	for (int i = 0; i<count; i++)
	{
		arr[i] = x % 10;
		x = x / 10;
	}
	int left = 0;
	int right = count - 1;
	//while((left<right)&&(arr[left]==arr[right]))
	//{
	//left++;
	//right--;
	//}
	//if((left+1==right)||(left==right))
	//{
	//return true;
	//}else{
	//return false;
	//}
	for (left = 0, right = count - 1; (left<count) && (left<right); left++, right--)
	{
		if (arr[left] != arr[right])
		{
			return false;
		}
	}
	return true;
}*/

/*#include<stdio.h>
void Function(char **arr)
{
	for (int i = 0; i < strlen(*arr[0]); i++)
	{
		printf("%c\n", *arr[i]);
	}

}
int main()
{
	char *arr[] = { "hellow", "shide", "wode" };
	Function(&arr);
}


char * longestCommonPrefix(char ** strs, int strsSize){
	int ret = 0;
	char *arr = malloc(sizeof(char)*strlen(*strs[0]));
	for (int i = 0; i<strlen(*strs[0]); i++)
	{
		for (int j = 0; j<strsSize; j++)
		{
			if (strs[0][i] == strs[j][i])
			{
				arr[i] = strs[j][i];
			}
			else{
				ret = 1;
			}
		}
		if (ret == 0)
		{
			return arr;
		}
		else{
			return "";
		}
	}
}*/


/*#include<stdio.h>
int main()
{
	int i = 0;
	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	for (i = 0; i <= 12; i++)
	{
		arr[i] = 0;
		printf("hello\n");
	}
	return 0;
}*/


/*bool isValid(char * s){
	int count = 0;
	char* arr = malloc(sizeof(char)*strlen(s));
	for (int i = 0; i<strlen(s); i++)
	{
		if ((*(s + i) == '(') || (*(s + i) == '{') || (*(s + i) == '['))
		{
			*(arr + count) = *(s + i);
			count++;
		}
		if ((*(s + i) == ')') || (*(s + i) == '}') || (*(s + i) == ']'))
		{
			if ((*(s + i)) != (*(arr + count - 1) + 1) || (*(s + i)) != (*(arr + count - 1) + 2))
			{
				return false;
			}
		}
	}
	return true;
}*/


//leetcode有效的括号
/*bool isValid(char * s){
	int count = 0;
	char* arr = malloc(sizeof(char)*strlen(s));
	if ((strlen(s) % 2) != 0)
	{
		return false;
	}
	for (int i = 0; i<strlen(s); i++)
	{
		if ((*(s + i) == '(') || (*(s + i) == '{') || (*(s + i) == '['))
		{
			*(arr + count) = *(s + i);
			count++;
		}
		if ((*(s + i) == ')') || (*(s + i) == '}') || (*(s + i) == ']'))
		{
			if (count == 0)
			{
				return false;
			}
			if ((*(s + i)) == (*(arr + count - 1) + 1) || (*(s + i)) == (*(arr + count - 1) + 2))
			{
				*(arr + count - 1) = 0;
				count--;
			}
			else{
				return false;
			}
		}
	}
	if ((*(arr + 0) == '(') || (*(arr + 0) == '{') || (*(arr + 0) == '[') || (*(arr + 0) == ')') || (*(arr + 0) == '}') || (*(arr + 0) == ']'))
	{
		return false;
	}
	else{
		return true;
	}
}*/



/*#include<stdio.h>
int main()
{
	int i = 0;
	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	for (i = 0; i <= 12; i++)
	{
		arr[i] = 0;
		printf("hello\n");
	}
	return 0;
}


//leetcode删除数组中的排序项
int removeDuplicates(int* nums, int numsSize){
	int i = 0;
	int j = 1;
	if (numsSize == 0)
		return 0;
	while (j<numsSize)
	{
		if (nums[i] == nums[j])
		{
			j++;
		}
		else{
			i++;
			nums[i] = nums[j];
			j++;
		}
	}
	return i + 1;
}*/

//leetcode移除元素
/*int removeElement(int* nums, int numsSize, int val){
	int i = 0;
	int j = 0;
	while (j<numsSize)
	{
		if (nums[j] == val)
		{
			j++;
		}
		else{
			nums[i] = nums[j];
			i++;
			j++;
		}
	}
	return i;
}*/


/*int strStr(char * haystack, char * needle){
	int count = 0;
	int t = 0;
	if (strlen(haystack) == 0)
	{
		if (strlen(needle) == 0)
		{
			return 0;
		}
		else{
			return -1;
		}
	}
	if (strlen(needle) == 0)
	{
		return 0;
	}
	for (int i = 0; i<strlen(haystack); i++)
	{
		if (*(haystack + i) == *(needle + count))
		{
			count++;
		}
		else{
			count = 0;
			t = t + 1;
			i = t;
		}
		if (count == strlen(needle))
		{
			return i + 1 - count;
		}
	}
	return -1;
}

int strStr(char * haystack, char * needle){
	int i = 0, j = 0, t = i;
	while (haystack[i] && needle[j])
	{
		if (haystack[i] == needle[j])
		{
			i++; j++;
			continue;
		}
		else
		{
			t = t + 1;
			i = t;
			j = 0;
		}
	}
	if (needle[j] == '\0')
		return t;
	return -1;
}
#include<stdio.h>
int main()
{
	printf("%d\n",'h'&&'\0');
}*/

//leetcode搜索插入位置
/*int searchInsert(int* nums, int numsSize, int target){
	int left = 0;
	int right = numsSize - 1;
	while (left <= right){
		int mid = (left + right) / 2;
		if (nums[mid] == target){
			return mid;
		}
		if (nums[mid]<target){
			left = mid + 1;
		}
		if (nums[mid]>target){
			right = mid - 1;
		}
	}
	for (int i = 0; i<numsSize; i++)
	{
		if (nums[i]>target)
		{
			return i;
		}
		if (i == numsSize - 1)
		{
			return numsSize;
		}
	}
	return -1;
}*/


/*int lengthOfLastWord(char * s){
	int ret = 0;
	int flg = 0;
	int count = strlen(s);
	for (int j = 0; j<count; j++)
	{
		if (*(s + j) != ' ')
		{
			flg = 1;
		}
	}
	if (flg == 0){
		return 0;
	}
	if (count == 0)
	{
		return 0;
	}
	for (int i = count - 1; i >= 0; i--)
	{
		if (*(s + count - 1) == ' ')
		{
			continue;
		}
		if (*(s + i) == ' ')
		{
			return ret;
		}
		if (i == 0)
		{
			return ret + 1;
		}
		ret++;
	}
	return 1;
}*/


/*#include<stdio.h>
int main()
{
	char arr[] = "hello world";
	printf("%d\n", strlen(arr));
}*/



//leetcode最后一个单词的长度
/*int lengthOfLastWord(char * s){
	int flg = 0;
	int ret = 0;
	int count = strlen(s);
	for (int i = count - 1; i >= 0; i--){
		if (*(s + i) == ' ')
		{
			if (flg == 1)
			{
				break;
			}
			continue;
		}
		flg = 1;
		ret++;
	}
	return ret;
}
*/

/*int reverse(int x){
	int sum = 0;
	int number = x;
	int count = 0;
	int tmp = (x >> 31) & 1;//tmp=1时负数
	//int X=abs(x);
	while (number)
	{
		count++;
		number = number / 10;
	}
	int *arr = malloc(sizeof(int)*count);
	for (int i = 0; i<count; i++)
	{
		arr[i] = X % 10;//arr[0]=3 arr[1]=2 arr[2]=1
		X = X / 10;
	}
	for (int j = 0; j<count; j++)
	{
		sum = sum + arr[j] * pow(10, count - 1 - j);
	}
	if (tmp == 1)
	{
		sum = sum*(-1);
		return sum;
	}
	else
	{
		return sum;
	}
}


int reverse(int x){
	int count = 0;
	int sum = 0;
	long overFlow = 0;
	long num = x;
	int flg = (num >> 31) & 1;//flg=1代表负数
	num = abs(num);
	x = abs(x);
	while (num){
		count++;
		num = num / 10;
	}
	int* arr = malloc(sizeof(int)*count);
	for (int i = 0; i<count; i++){
		arr[i] = x % 10;//arr[0]=3 arr[1]=2 arr[2]=1
		x = x / 10;
	}
	for (int j = 0; j<count; j++){
		overFlow = overFlow + arr[j] * pow(10, count - 1 - j);
	}
	if (overFlow <= -2147483648 || overFlow >= 2147483647)
	{
		return 0;
	}
	else{
		sum = (int)(overFlow);
	}
	if (flg == 1)
	{
		return -1 * sum;
	}
	else{
		return sum;
	}
}


//leetcode整数反转
int reverse(int x){
	int num = x;
	int count = 0;
	long sum = 0;
	//num=abs(num);
	while (num)
	{
		count++;
		num = num / 10;
	}
	int* arr = malloc(sizeof(int)*count);
	for (int i = 0; i<count; i++)
	{
		arr[i] = x % 10;//arr[0]=3 arr[1]=2 arr[2]=1
		x = x / 10;
	}
	for (int j = count - 1; j >= 0; j--)
	{
		sum = sum + arr[j] * pow(10, count - 1 - j);
		if (sum<-2147483648 || sum>2147483647)
		{
			return 0;
		}
	}
	return sum;
}*/

//leetcode最大子序和
/*int maxSubArray(int* nums, int numsSize){
	int sumMax = nums[0];
	for (int i = 0; i<numsSize; i++)
	{
		int sum = 0;
		for (int j = i; j<numsSize; j++)
		{
			sum = sum + nums[j];
			if (sum>sumMax)
			{
				sumMax = sum;
			}
		}
	}
	return sumMax;
}*/



//leetcode加一
/**
* Note: The returned array must be malloced, assume caller calls free().
*/
/*int* plusOne(int* digits, int digitsSize, int* returnSize){
	int flg = 0;
	*returnSize = digitsSize;
	int* arr = malloc(sizeof(int)*(digitsSize + 1));
	for (int i = digitsSize - 1; i >= 0; i--)
	{
		if (digits[i] != 9)
		{
			flg = 1;
			digits[i] = digits[i] + 1;
			for (int j = i + 1; j<digitsSize; j++)
			{
				digits[j] = 0;
			}
			return digits;
		}
	}
	if (flg == 0)
	{
		arr[0] = 1;
		for (int k = 1; k <= digitsSize; k++)
		{
			arr[k] = 0;
		}
	}
	*returnSize = digitsSize + 1;
	return arr;
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
	while (strcmp(pCur->data.name, name))
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
	LNode* pCur = Find(&list, 3);
	printf("%s  %d\n", Locate(&list, &stu2.name)->data.no, Locate(&list, &stu2.name)->data.score);//按照姓名查找，返回学号和成绩
	printf("%s %10s %4d\n", pCur->data.no, pCur->data.name, pCur->data.score);//第val个节点查找，返回学生的信息
	printf("%d\n", Getlength(&list));	//得到链表的长度
	ListInsert(&list, stu5, 3);//插入到第val个节点
	Show(&list);
	Delete(&list, 2);	//删除第val个节点的信息
	Show(&list);
	return 0;
}*/


/*#include<stdio.h>
#include<string.h>
typedef struct Book{				//定义书籍信息
	char ISBN[20];
	char bookName[20];
	double Price;
}Book;

typedef struct LNode{			//定义书籍节点
	Book data;
	struct LNode * next;
}LNode, *LinkList;

void InitList(LinkList list)		//初始化链表
{
	if (list->next == NULL)
	{
		return;
	}
	list->next = NULL;
}

LNode *GetNode(Book book)//生成一个节点
{
	LNode * pGet = (LNode *)malloc(sizeof(LNode));
	strcpy(pGet->data.bookName, book.bookName);
	strcpy(pGet->data.ISBN, book.ISBN);
	pGet->data.Price = book.Price;
	pGet->next = NULL;
	return pGet;
}

void InsertTailList(LinkList list, Book book)//尾插
{
	LNode *pCur = list;
	while ((pCur->next) != NULL)
	{
		pCur = pCur->next;
	}
	LNode *pGet = GetNode(book);
	pCur->next = pGet;
}

LNode *nameFind(LinkList list, char *name)	//书名查找
{
	LNode *pCur = list->next;
	while (strcmp(pCur->data.bookName, name))
	{
		pCur = pCur->next;
	}
	return pCur;
}

void Delete(LinkList list, int val)	//删除第val本书籍
{
	LNode* pCur = list;
	int count = 1;
	while (count != val)
	{
		pCur = pCur->next;
		count++;
	}
	pCur->next = pCur->next->next;
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

void Modify(LinkList list, int val,Book book)//修改书籍
{
	int tmp = 1;
	LNode* pCur = list->next;
	while (tmp != val)
	{
		pCur = pCur->next;
		tmp++;
	}
	strcpy(pCur->data.ISBN, book.ISBN);
	strcpy(pCur->data.bookName, book.bookName);
	pCur->data.Price = book.Price;
}

void Show(LinkList list)	//打印
{
	LNode *pCur = list->next;
	while (pCur != NULL)
	{
		printf("%s ", pCur->data.ISBN);
		printf("%10s ", pCur->data.bookName);
		printf("%6d ", pCur->data.Price);
		printf("\n");
		pCur = pCur->next;
	}
	printf("\n");
}
int main()
{
	printf("=============================\n");
	printf("        图书管理系统\n");
	printf("         1、初始化系统\n");
	printf("         2、查看当前存放的书籍\n");
	printf("         3、向系统录入书籍\n");
	printf("         4、查找书籍\n");
	printf("         5、删除书籍\n");
	printf("         6、查看当前书籍总量\n");
	printf("         7、修改书籍信息\n");
	printf("         0、退出系统\n");
	printf("\n");
	printf("=============================\n");
	int tmp;
	int count = 1;
	LNode list;
	InitList(&list);
	while (count){
		printf("请输入你的操作\n");
		scanf_s("%d", &tmp);
		switch (tmp)
		{
		case 1:
		{
			InitList(&list);
			printf("初始化完成！\n");
			count = 1;
			break;
		}
		case 2:
		{
			Show(&list);
			count = 1;
			break;
		}
		case 3:
		{
			int ret = 0;
			printf("你想输入多少本书籍？");
			scanf_s("%d", &ret);
			for (int i = 0; i < ret; i++)
			{
				Book book;
				printf("书籍的ISBN号：");
				scanf("%s", book.ISBN);
				printf("书名：");
				scanf("%s", book.bookName);
				printf("书籍价格：");
				scanf_s("%d", &book.Price);
				InsertTailList(&list, book);
				printf("录入完成！\n");
			}
			count = 1;
			break;
		}
		case 4:
		{
			char arr[10] = { NULL };
			printf("请输入要查找书籍的书名：");
			scanf("%s", arr);
			printf("%s", nameFind(&list, arr)->data.ISBN);
			printf("%10s ", nameFind(&list, arr)->data.bookName);
			printf("%6d ", nameFind(&list, arr)->data.Price);
			printf("\n");
			break;
		}
		case 5:
		{
			int val = 0;
			printf("请输入想删除第几本书！");
			scanf_s("%d", &val);
			Delete(&list, val);
			printf("删除成功！");
			count = 1;
			break;
		}
		case 6:
		{
			printf("当前书库有%d本书籍！\n",Getlength(&list));
			count = 1;
			break;
		}
		case 7:
		{
			int val = 0;
			Book book;
			printf("请输入你想修改第几本书籍！");
			scanf("%d", &val);
			printf("书籍的ISBN号：");
			scanf("%s", book.ISBN);
			printf("书名：");
			scanf("%s", book.bookName);
			printf("书籍价格：");
			scanf_s("%d", &book.Price);
			Modify(&list, val,book);
			printf("修改成功！");
			count = 1;
			break;
		}
		case 0:
		{
			printf("退出系统成功！\n");
			count = 0;
		}
		default:
			break;
		}
	}

}



/*char * addBinary(char * a, char * b){
	int aNum = 0;
	int bNum = 0;
	for (int i = strlen(a) - 1; i >= 0; i--)
	{
		aNum = aNum + pow(2, strlen(a) - 1 - i);
	}
	for (int j = strlen(b) - 1; j >= 0; j--)
	{
		bNum = bNum + pow(2, strlen(b) - 1 - j);
	}
	int sumNum = aNum + bNum;
	int count = 0;
	int ret = sumNum;
	while (ret)
	{
		count++;
		ret = ret / 2;
	}
	char* arr = malloc(sizeof(char)*count);
	int tmp = 0;
	for (int k = count - 1; k >= 0; k--)
	{
		tmp = sumNum % 2;
		sumNum = sumNum / 2;
		*(arr + k) = tmp;
	}
	return arr;
}*/

//leetcodex的平方根
/*int mySqrt(int x){
	for (long i = 1; i <= x; i++)
	{
		if ((i*i)>x)
		{
			return i - 1;
		}
		if ((i*i) == x)
		{
			return i;
		}
	}
	return 0;
}*/


//leetcode爬楼梯
/*int climbStairs(int n){
	if (n == 1)
		return 1;
	if (n == 2)
		return 2;
	int f1 = 1;
	int f2 = 2;
	int f3 = 0;
	for (int i = 3; i <= n; i++){
		f3 = f1 + f2;
		f1 = f2;
		f2 = f3;
	}
	return f3;
}*/


//链栈
/*#include<stdio.h>

typedef struct StackNode{
	int data;
	struct LinkStack* next;
}StackNode,*LinkStack;

LinkStack S = NULL;

void Push(LinkStack list, int val)
{
	StackNode* pGet = (StackNode*)malloc(sizeof(StackNode));
	pGet->data = val;
	pGet->next = S;
	S = pGet;
}

int Pop()
{
	int tmp = S->data;
	S = S->next;
	return tmp;
}

void Show(LinkStack list)
{
	StackNode* pCur = S;
	while (pCur != NULL){
		printf("%d  ", pCur->data);
		pCur = pCur->next;
	}
}

int main()
{
	StackNode stack;
	int input = 0;
	int count = 0;
	printf("想入栈几个元素？\n");
	scanf_s("%d", &count);
	for (int i = 0; i < count; i++)
	{
		scanf_s("%d", &input);
		if (input == -1)
		{
			printf("出栈元素是%d  \n",Pop());
		}
		else{
			Push(&stack, input);
		}
	}
	Show(&stack);
}*/

//顺序栈
/*#include<stdio.h>
#define MAXSIZE 3

typedef struct{
	int* base;
	int* top;
	int stacksize;
}sqStack;



void InitStack(sqStack* S){
	S->base = (int* )malloc(sizeof(int)*MAXSIZE);
	S->top = S->base;
	S->stacksize = MAXSIZE;
}

void Push(sqStack *S,int val)
{
	if ((S->top - S->base )== S->stacksize)
	{
		printf("栈满！\n");
		return;
	}
	*S->top++ = val;
	printf("入栈成功\n");
}

int Pop(sqStack *S)
{
	int tmp=0;
	if (S->base == S->top)
	{
		printf("栈空！\n");
		return;
	}
	tmp = *--S->top;
	return tmp;
}

int main()
{
	int input = 0;
	int num = 0;
	sqStack St;
	InitStack(&St);
	printf("要入栈几个元素？\n");
	scanf_s("%d", &input);
	for (int i = 0; i < input; i++)
	{
		scanf_s("%d", &num);
		if (num == -1)
		{
			printf("出栈元素是%d\n", Pop(&St));
		}
		else{
			Push(&St, num);
		}
	}
}*/


/*#include<stdio.h>
#define MAXQSIZE 100
typedef struct {
	char name[20];
	char sex;
}Person;

typedef struct {
	Person *base;
	int fronter;
	int rear;
}SqQueue;
 
void InitQueue(SqQueue *Q)	//初始化
{
	Q->base = (SqQueue*)malloc(sizeof(SqQueue)*MAXQSIZE);
	if (!Q->base)
	{
		return;
	}
	Q->fronter = Q->rear = 0;
}

void EnQueue(SqQueue *Q, Person e)		//入队
{
	if (((Q->rear+1) % MAXQSIZE )== Q->fronter)
		return;
	Q->base[Q->rear] = e;
	Q->rear = (Q->rear + 1) % MAXQSIZE;
}

Person DeQueue(SqQueue *Q)		//出队
{
	if (Q->fronter == Q->rear)
		return;
	Person tmp;
	tmp = Q->base[Q->fronter];
	Q->fronter = (Q->fronter + 1) % MAXQSIZE;
	return tmp;
}

int QueueEmpty(SqQueue *Q)		//判空
{
	if ((Q->fronter) == (Q->rear)){
		return 1;
	}
	else{
		return 0;
	}
}

Person GetHead(SqQueue *Q)			//得到头
{
	if (Q->fronter != Q->rear)
	{
		return Q->base[Q->fronter];
	}
}

void DancerPartner(Person dancer[], int num)
{
	SqQueue Mdancers, Fdencers;
	Person p;
	InitQueue(&Mdancers);
	InitQueue(&Fdencers);
	for (int i = 0; i < num; i++)
	{
		p = dancer[i];
		if (p.sex == 'F')
		{
			EnQueue(&Fdencers,p);
		}
		else{
			EnQueue(&Mdancers, p);
		}
		printf("The dancing partners are:\n");
		while ((!QueueEmpty(&Fdencers)) && (!QueueEmpty(&Mdancers)))
		{
			Person Fper = DeQueue(&Fdencers);
			printf("%s  ", Fper.name);
			Person Mper = DeQueue(&Mdancers);
			printf("%s  ", Mper.name);
			printf("\n");
		}
		//实现输出队头女士和男士的姓名
		if (!QueueEmpty(&Fdencers))
		{
			p = GetHead(&Fdencers);
			printf("The first women to get a partner is:%s\n", p.name);
		}
		else{
			if(!QueueEmpty(&Mdancers)){
				p = GetHead(&Mdancers);
				printf("The first men to get a partner is:%s\n", p.name);
			}
		}
	}
}
int main()
{
	Person dancer[5] = { {"女1", 'F'}, {"男1",'M'}, {"女2",'F'}, {"男2",'M'}, {"女3",'F'} };
	DancerPartner(dancer, 5);
}*/



/*void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
	for (int i = 0; i<nums2Size; i++)
	{
		for (int j = 0; j<m; j++)
		{
			if ((nums1[0] == 0) && (nums2[0] == 1))
			{
				nums1[0] = nums2[0];
				break;
			}
			if (nums2[i]<nums1[j])
			{
				for (int k = m; k>j; k--)
				{
					nums1[k] = nums1[k - 1];
				}
				nums1[j] = nums2[i];
				m++;
				break;
			}

			if (nums2[i] >= nums1[m - 1])
			{
				nums1[m] = nums2[i];
				m++;
				break;
			}
		}
	}
}*/


//leetcode合并两个有序数组
/*void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
	int count = 0;
	for (int i = nums1Size - 1; i >= 0; i--){
		if (count != n){
			nums1[i] = nums2[count];
			count++;
		}
	}
	for (int j = 0; j<nums1Size; j++){
		for (int k = nums1Size - 1; k>j; k--){
			if (nums1[k]<nums1[k - 1]){
				nums1[k] = nums1[k] ^ nums1[k - 1];
				nums1[k - 1] = nums1[k] ^ nums1[k - 1];
				nums1[k] = nums1[k] ^ nums1[k - 1];
			}
		}
	}
}*/


//leetcode删除有序链表中的重复元素
/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     struct ListNode *next;
* };
*/

/*struct ListNode* deleteDuplicates(struct ListNode* head){
	struct ListNode* ptr = head;
	struct ListNode* pCur = head;
	while (pCur != NULL)
	{
		while (pCur != NULL&&ptr->val == pCur->val)
		{
			pCur = pCur->next;
		}
		ptr->next = pCur;
		ptr = pCur;
		if (pCur == NULL){
			break;
		}
		pCur = pCur->next;
		/*if(pCur->val==pCur->next->val)
		{
		while(ptr->val==pCur->next->val)
		{
		pCur=pCur->next;
		}
		ptr=pCur;
		}
		ptr=pCur;
		pCur=pCur->next;*/
	/*}
	return head;
}*/



/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     struct ListNode *next;
* };
*/

//leetcode移除链表元素
/*struct ListNode* removeElements(struct ListNode* head, int val){
	if (head == NULL){
		return NULL;
	}
	struct ListNode* prev = head;
	struct ListNode* cur = head->next;
	while (cur != NULL){
		if (cur->val == val){
			prev->next = cur->next;
			cur = cur->next;
		}
		else{
			prev = cur;
			cur = cur->next;
		}
	}
	if (head->val == val)
	{
		head = head->next;
	}
	return head;
}*/






/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     struct ListNode *next;
* };
*/

//leetcode回文链表
/*bool isPalindrome(struct ListNode* head){
	if (head == NULL || head->next == NULL){
		return true;
	}
	struct ListNode* fast = head;
	struct ListNode* slow = head;
	while (fast != NULL&&fast->next != NULL){
		fast = fast->next->next;
		slow = slow->next;
	}
	struct ListNode* cur = slow;
	struct ListNode* curNext = NULL;
	while (cur != NULL){
		curNext = cur->next;
		cur->next = slow;
		slow = cur;
		cur = curNext;
	}
	while (slow != head&&slow != NULL){
		if (slow->val != head->val){
			return false;
		}
		head = head->next;
		if (head == slow){
			return true;
		}
		slow = slow->next;
	}
	return true;
}*/


/*class Solution {
	public int[] intersection(int[] nums1, int[] nums2) {
		int[] array = new int[((nums1.length>nums2.length) ? nums1.length : nums2.length)];
		int ret = 0;
		for (int i = 0; i<nums1.length; i++){
			for (int j = 0; j<nums2.length; j++){
				if (nums1[i] == nums2[j]){
					array[ret] = nums1[i];
					ret++;
					break;
				}
			}
		}
		int count = 0;
		int i = 0;
		while (i != (ret - 1)){
			for (int j = i + 1; j<ret; j++){
				if (array[i] == array[j]){
					for (int k = j; k<ret - 1; k++){
						array[k] = array[k + 1];
					}
					ret--;
					count = 1;
				}
			}
			if (count == 0){
				i++;
			}
		}
		return arr;
	}
}*/

/*#include<stdio.h>
#define MaxSize 100

typedef struct {		//顺序栈的结构，注意是int
	int* base;
	int* top;
	int StackSize;
}SqStack;

void InitStack(SqStack *s){		//顺序栈的初始化
	s->base = (int*)malloc(sizeof(int)*MaxSize);
	s->top = s->base;
	s->StackSize = MaxSize;
}

void pushStack(SqStack *s, int val){		////顺序栈的入栈
	*(s->top) = val;
	s->top++;
}

int Pop(SqStack *s){		//顺序栈的出栈
	int ret = 0;
	if (s->base == s->top){
		return -1;
	}
	s->top--;
	ret = *(s->top);
	return ret;
}



int main()
{
	SqStack s;
	InitStack(&s);
	pushStack(&s, 1);
	pushStack(&s, 2);
	pushStack(&s, 3);
	pushStack(&s, 4);
	pushStack(&s, 5);
	printf("%d\n", Pop(&s));
	printf("%d\n", Pop(&s));
	printf("%d\n", Pop(&s));
	printf("%d\n", Pop(&s));
}*/


/*#include<stdio.h>
#define MaxSize 100

typedef struct {	//队列的结构
	int* base;
	int* front;
	int* rear;
	int SqQueueSize;
}SqQueue;

void Init(SqQueue* q){	//队列的初始化
	q->front = q->rear = (int *)malloc(sizeof(int)*MaxSize);
	q->SqQueueSize = MaxSize;
}

void Push(SqQueue * q, int val){		//队列的入队
	if (q->SqQueueSize == 0){
		return 0;
	}
	*(q->rear )= val;
	q->rear++;
	if (q->SqQueueSize == 0){	//循环队列的实现也可以用这样的方式
		q->rear = q->base;
	}
	q->SqQueueSize--;
}

int Pop(SqQueue* q){		//队列的出队
	if (q->front == q->rear){
		return -1;
	}
	int ret = *(q->front);
	q->front++;
	q->SqQueueSize++;
	return ret;
}

int main()
{
	SqQueue q;
	Init(&q);
	Push(&q, 1);
	Push(&q, 2);
	Push(&q, 3);
	Push(&q, 4);
	Push(&q, 5);
	Push(&q, 6);
	printf("%d\n", Pop(&q));
	printf("%d\n", Pop(&q));
	printf("%d\n", Pop(&q));
	printf("%d\n", Pop(&q));
}*/

/*#include<stdio.h>

typedef struct StackNode{	//链栈的结构
	int data;
	struct StackNode* next;
}StackNode;

void InitStack(StackNode* S){		//链栈的初始化
	S = NULL;
}

void Push(StackNode* S, int val){		//链栈的入栈
	StackNode* p = (StackNode*)malloc(sizeof(StackNode));
	p->data = val;
	p->next = S;
	S = p;
}

int Pop(StackNode* S){		//链栈的出栈
	int ret = 0;
	if (S == NULL){
		return -1;
	}
	ret = S->data;
	S = S->next;
	return ret;
}

int main()
{
	StackNode S;
	InitStack(&S);
	Push(&S, 1);
	Push(&S, 2);
	Push(&S, 3);
	Push(&S, 4);
	Push(&S, 5);
	printf("%d\n", Pop(&S));
	printf("%d\n", Pop(&S));
	printf("%d\n", Pop(&S));
	printf("%d\n", Pop(&S));
}*/

#include<stdio.h>

typedef struct BiTNode{
	int data;
	struct BiTNode* lchild, *rchild;
}BiTNode,*BiTree;


void Create(BiTree Tree){	//创建二叉树
	int a = 0;
	scanf_s("%d", &a);
	if (a == '#')
		Tree = NULL;
	else{
		Tree = (BiTree)malloc(sizeof(BiTNode));
		Tree->data = a;
		Create(Tree->lchild);
		Create(Tree->rchild);
	}
}

void InOrder(BiTree Tree){	//先序遍历
	if (Tree){
		InOrder(Tree->lchild);
		printf("%d  ", Tree->data);
		InOrder(Tree->rchild);
	}
}

void preOrder(BiTree Tree)//前序遍历
{
	if (Tree != NULL)
	{
		printf("%d  ", Tree->data);
		preOrder(Tree->lchild);
		preOrder(Tree->rchild);
	}
	return;
}

void PostOrder(BiTree Tree)//后序遍历
{
	if (Tree != NULL)
	{
		PostOrder(Tree->lchild);
		PostOrder(Tree->rchild);
		printf("%d  ", Tree->data);
	}
	return;
}

int main()
{
	BiTNode Tree;
	Create(&Tree);
	InOrder(&Tree);
}