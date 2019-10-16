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

void SListPushFront(SListNode** pphead, SLTDataType x)//ͷ��
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
void SListPopFront(SListNode** pphead)//ͷɾ
{
	SListNode* tmp = (*pphead)->next;
	if (*pphead == NULL)//ͷɾͷ����Ϊ��
	{
		return;
	}
	free(*pphead);
	*pphead = tmp;
}

void SListInsertAfter(SListNode* pos, SLTDataType x)//���
{
	SListNode* tmp = BuyListNode(x);
	tmp->next = pos->next;
	pos->next = tmp;
}
void SListEraseAfter(SListNode* pos)//��ɾ
{
	SListNode* tmp = pos->next;
	if (tmp == NULL)
	{
		return;
	}
	pos->next = tmp->next;
	free(tmp);
}
SListNode* SListFind(SListNode* phead, SLTDataType x)//����ĳһ��x
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
	printf("��%d���ڵ���%d\n", 3, pGet->data);
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
LNode *GetNode(Student stu)//����һ���ڵ�
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
void Insert(LinkList list, Student stu)//β��
{
	LNode *pCur = list;
	while ((pCur->next) != NULL)
	{
		pCur = pCur->next;
	}
	LNode *pGet = GetNode(stu);
	pCur->next = pGet;
}
void Show(LinkList list)	//��ӡ
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
LNode *Locate(LinkList list, char *name)	//��������
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
LNode *Find(LinkList list, int val)	//��val���ڵ����
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
void Delete(LinkList list, int val)	//ɾ����val���ڵ�
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
int Getlength(LinkList list)	//�õ�����
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
void ListInsert(LinkList list, Student stu, int val)//���뵽��val���ڵ�
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
	Student stu4 = { "0213", "hello", 90 };		//����ѧ����Ϣ
	LNode list;
	Init(&list);
	Insert(&list, stu1);
	Insert(&list, stu2);
	Insert(&list, stu3);
	Insert(&list, stu4);					//����ѧ����Ϣ
	LNode* pCur =Find(&list, 3);
	printf("%s  %d\n", Locate(&list, &stu2.name)->data.no, Locate(&list, &stu2.name)->data.score);//�����������ң�����ѧ�źͳɼ�
	printf("%s %10s %4d\n", pCur->data.no, pCur->data.name, pCur->data.score);//��val���ڵ���ң�����ѧ������Ϣ
	printf("%d\n", Getlength(&list));	//�õ�����ĳ���
	ListInsert(&list, stu5,3);//���뵽��val���ڵ�
	Show(&list);
	Delete(&list, 2);	//ɾ����val���ڵ����Ϣ
	Show(&list);
	return 0;
}*/

/*#include<stdio.h>
#include<math.h>
//����һ�� 32 λ���з�������������Ҫ�����������ÿλ�ϵ����ֽ��з�ת��

int Function(int num)
{
	int tmp = 0;
	int count = 0;
	int arr[10] = { 0 };
	int x= (num >> 32) & 1;//�����λ
	for (int i = 0;num&&( i < 10); i++)
	{
		arr[i] = num % 10;//arr[0]=��λ��arr[1]=ʮλ��arr[2]=��λ
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
			printf("���ǻ�����!\n");
			return;
		}
	}
	printf("�ǻ�����!\n");
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
Student *LastKNode(Student *list, int val)//�ҵ�����K���ڵ�
{
	int count = val-1;
	Student *pCur1 = list->next;
	Student *pCur2 = list->next;
	while (count != 0)
	{
		pCur1 = pCur1->next;
		if (pCur1->next == NULL)
		{
			printf("�ڵ㲻����");
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
		for (int i = 0; i <= 100; i++)//ĸ��
		{
			for (int j = 0; j <= 100; j++)//����
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
//ɾ���ڵ㣬ֻ��ɾ���Ľڵ�
/*void deleteNode(struct ListNode* node) {
	node->val = node->next->val;
	node->next = node->next->next;
}


//��дתСд
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



//����������ϲ����ϲ�����Ӵ�С���
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

//��������
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



//������������ͬ�ڵ�
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


//leetcode��һ������������ԭ����Ƚ��ж���λ��ͬ
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



//�Գ���
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




//leetcode����֮��
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


//leetcodeɽ������ķ嶥����
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


//leetcode���ֵĲ���
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



//leetcode����ż��������
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

//leetcode����һ���Ǹ����� num������������λ�ϵ�������ӣ�ֱ�����Ϊһλ��
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

//쳲�������
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

//leetcode����ż�������飬����λ��������ż��λ��ż��
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
LNode *GetNode(Student stu)//����һ���ڵ�
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
void Insert(LinkList list, Student stu)//β��
{
	LNode *pCur = list;
	while ((pCur->next) != NULL)
	{
		pCur = pCur->next;
	}
	LNode *pGet = GetNode(stu);
	pCur->next = pGet;
}
void Show(LinkList list)	//��ӡ
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
LNode *Locate(LinkList list, char *name)	//��������
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
LNode *Find(LinkList list, int val)	//��val���ڵ����
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
void Delete(LinkList list, int val)	//ɾ����val���ڵ�
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
int Getlength(LinkList list)	//�õ�����
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
void ListInsert(LinkList list, Student stu, int val)//���뵽��val���ڵ�
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
	Student stu4 = { "0213", "hello", 90 };		//����ѧ����Ϣ
	LNode list;
	Init(&list);
	Insert(&list, stu1);
	Insert(&list, stu2);
	Insert(&list, stu3);
	Insert(&list, stu4);					//����ѧ����Ϣ
	LNode* pCur = Find(&list, 3);
	printf("��ӡ����\n");
	Show(&list);
	printf("�����������ң�����ѧ�źͳɼ�(lisi)\n");
	printf("%s  %d\n", Locate(&list, &stu2.name)->data.no, Locate(&list, &stu2.name)->data.score);//�����������ң�����ѧ�źͳɼ�
	printf("��3���ڵ���ң�����ѧ������Ϣ\n");
	printf("%s %10s %4d\n", pCur->data.no, pCur->data.name, pCur->data.score);//��val���ڵ���ң�����ѧ������Ϣ
	printf("����ĳ���\n");
	printf("%d\n", Getlength(&list));	//�õ�����ĳ���
	printf("���뵽��3���ڵ�\n");
	ListInsert(&list, stu5, 3);//���뵽��val���ڵ�
	Show(&list);
	printf("ɾ����2���ڵ����Ϣ\n");
	Delete(&list, 2);	//ɾ����val���ڵ����Ϣ
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
LNode *GetNode(Student stu)//����һ���ڵ�
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
void Insert(LinkList list, Student stu)//β��
{
	LNode *pCur = list;
	while ((pCur->next) != NULL)
	{
		pCur = pCur->next;
	}
	LNode *pGet = GetNode(stu);
	pCur->next = pGet;
}
void Show(LinkList list)	//��ӡ
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
LNode *Locate(LinkList list, char *name)	//��������
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
LNode *Find(LinkList list, int val)	//��val���ڵ����
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
void Delete(LinkList list, int val)	//ɾ����val���ڵ�
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
int Getlength(LinkList list)	//�õ�����
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
void ListInsert(LinkList list, Student stu, int val)//���뵽��val���ڵ�
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
	Student stu4 = { "0213", "hello", 90 };		//����ѧ����Ϣ
	LNode list;
	Init(&list);
	Insert(&list, stu1);
	Insert(&list, stu2);
	Insert(&list, stu3);
	Insert(&list, stu4);					//����ѧ����Ϣ
	LNode* pCur = Find(&list, 3);
	printf("%s  %d\n", Locate(&list, &stu2.name)->data.no, Locate(&list, &stu2.name)->data.score);//�����������ң�����ѧ�źͳɼ�
	printf("%s %10s %4d\n", pCur->data.no, pCur->data.name, pCur->data.score);//��val���ڵ���ң�����ѧ������Ϣ
	printf("%d\n", Getlength(&list));	//�õ�����ĳ���
	ListInsert(&list, stu5, 3);//���뵽��val���ڵ�
	Show(&list);
	Delete(&list, 2);	//ɾ����val���ڵ����Ϣ
	Show(&list);
	return 0;
}*/


/*int countPrimeSetBits(int L, int R){
	int count = 0;
	for (int i = L; i <= R; i++)
	{
		int ret = 0;
		int tmp = 0;
		for (int j = 0; j<32; j++)//�ж��ж��ٸ�1
		{
			if (((i >> j) & 1) == 1)
			{
				tmp++;
			}
		}
		for (int k = 2; k <= sqrt(tmp); k++)//�ж��ǲ�������
		{
			if ((tmp%k) == 0)
			{
				ret = 1;//��������
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


//˳��ջ
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
	printf("                       ˳��ջ����\n");
	printf("            =================\n");
	printf("                       ��ѡ��\n");
	printf("                       1����ջ\n");
	printf("                       2����ջ\n");
	printf("                       3��ȡջ��Ԫ��\n");
	printf("                       0���˳�\n");
	printf("            =================\n");
	printf("            ѡ��0��1��2��3��\n");
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
			printf("��������ջ����=��");
			scanf("%d", &x);
			k = Push(&st, &x);
			if (k)printf("��ջ����");
			else printf("ջΪ��");
			getchar();
			break;
		case '2':
			k = Pop(&st, &x);
			if (k) printf("��ջ����=%d\n",x);
			else printf("ջΪ��");
			getchar();
			break;
		case '3':
			k = GetTop(&st, &x);
			if (k) printf("ջ��Ԫ��=%d\n", x);
			else printf("ջΪ��");
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
void InitStack(LinkStack S)//��ջ�ĳ�ʼ��
{
	S = NULL;
}
void Push(LinkStack S, int val)//��ջ
{
	StackNode* pGet = Get(val);
	pGet->next = S;
	S = pGet;
}
int Pop(LinkStack S)//��ջ
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
void InitStack(LinkStack *S)//��ջ�ĳ�ʼ��
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
		return 0;    // ջ��
	}
	e = S->data;    //��ջ��Ԫ�ظ�ֵ��e
	StackNode *p;
	p = S;         // ��ʱ����ջ��Ԫ�ؿռ䣬׼���ͷ�
	S = S->next;    // �޸�ջ��ָ��
	free( p);     // �ͷ�ԭջ��Ԫ�ؿռ�
	return 1;
}
int Push(LinkStack *S, int e)
{
	//Ԫ��e��ջ
	//StackNode *p;
	StackNode* p = (StackNode*)malloc(sizeof(StackNode));
	p->data = e;        // ���½ڵ���������Ϊe
	p->next = S;        // ���½ڵ����ջ��
	S = p;             // �޸�ջ��ָ��
	return 1;         // ��ջҪע��ָ��ķ����Ǵ�ջ��ָ��ջ�׵� 
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

// ��ջ�Ĵ洢�ṹ
typedef struct StackNode
{
	int data;
	struct StackNode *next;
}StackNode, *LinkStack;

// ��ʼ��
int InitStack(LinkStack &S)
{
	S = NULL;   // ��ջ��ָ���ÿ�
	return 1;
}

// ��ջ
int Push(LinkStack &S, int e)
{
	//Ԫ��e��ջ
	StackNode *p;
	p = new StackNode;  // �����½ڵ�

	p->data = e;        // ���½ڵ���������Ϊe
	p->next = S;        // ���½ڵ����ջ��
	S = p;             // �޸�ջ��ָ��
	return 1;         // ��ջҪע��ָ��ķ����Ǵ�ջ��ָ��ջ�׵� 
}

// ��ջ
int Pop(LinkStack &S, int &e)
{
	if (S == NULL)
	{
		return 0;    // ջ��
	}
	e = S->data;    //��ջ��Ԫ�ظ�ֵ��e
	StackNode *p;
	p = S;         // ��ʱ����ջ��Ԫ�ؿռ䣬׼���ͷ�
	S = S->next;    // �޸�ջ��ָ��
	delete p;     // �ͷ�ԭջ��Ԫ�ؿռ�
	return 1;
}

// ȡջ��Ԫ��
int GetTop(LinkStack S)
{
	//����S��ջ��Ԫ��,���޸�ջ��ָ��
	if (S != NULL)  // ջ�ǿ�
		return S->data;  // ����ջ��Ԫ�ص�ֵ,ջ��ָ�벻��
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
		printf("��ջ��ʼ���ɹ�!\n");
	}
	else
	{
		printf("��ջ��ʼ��ʧ��!\n");
	}

	// ��ջ
	int n;
	printf("������ջ��Ԫ�ظ���:");
	scanf("%d", &n);
	for (int i = 0; i < n;)
	{
		int e;
		printf("�������%d����ջ��Ԫ��:", ++i);
		scanf("%d", &e);
		Push(S, e);
	}
	printf("����ջ:\n");
	TraveStack(S);

	// ��ջ��ȡ������Ԫ�أ�
	for (int i = 0; i < 2;)
	{
		int a;
		Pop(S, a);
		printf("��%d����ջ��Ԫ��:%d\n", ++i, a);
	}
	printf("����ջ:\n");
	TraveStack(S);

	printf("ջ��Ԫ����:%d\n", GetTop(S));

	system("pause");

	return 0;


#include<stdio.h>
typedef struct StackNode
{
	int data;
	struct StackNode *next;
}StackNode, *LinkStack;

// ��ʼ��
int InitStack(LinkStack &S)
{
	S = NULL;   // ��ջ��ָ���ÿ�
	return 1;
}
int main()
{
	LinkStack S;

	if (InitStack(S))
	{
		printf("��ջ��ʼ���ɹ�!\n");
	}
}}*/




//leetcodeֻ����һ�ε�����
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
int InitStack(LinkStack s)//��ʼ��ջ
{
	s = NULL;
	return 1;
}
StackNode* GetNode(int val)//����һ���ڵ�
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
*/
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

//leetcode��һ���������
/**
* Note: The returned array must be malloced, assume caller calls free().
*/
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
}