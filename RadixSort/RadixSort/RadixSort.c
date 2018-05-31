#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 100
#define TRUE 1
#define FALSE 0

typedef struct _NODE
{
	int Data;
	struct _NODE *Next;
} NODE;

void RadixSort(void);		//기수 정렬
int IsNumberExist(int, int);	//수 겹치기 않게 하기 위함
void InitializeQueue(void);
void Put(int, int);
void Get(int);

int Buf[MAX];					//정렬할 대상
NODE *Front[10];
NODE *Rear[10];
NODE *ptrNode;
int IndexNum;

void RadixSort(void)
{
	int i, num, SortNum, j;
	int Digit = 1;
	j = 0;

	for (Digit = 1; Digit < MAX; Digit *= 10)
	{
		for (i = 0; i < MAX; i++)
		{
			num = Buf[i];
			SortNum = num / Digit % 10;
			Put(SortNum, num);
		}

		IndexNum = 0;

		for (i = 0; i < 10; i++)
		{
			Get(i);
		}
	}
}

int IsNumberExist(int Data, int Num)
{
	int i = 0;

	for (i = 0; i < Num; i++)
	{
		if (Buf[i] == Data)
			return TRUE;
	}

	return FALSE;
}

void InitializeQueue(void)
{
	int i = 0;

	for (i = 0; i < 10; i++)
	{
		Front[i] = (NODE *)malloc(sizeof(NODE));
		Rear[i] = (NODE *)malloc(sizeof(NODE));
		
		Front[i]->Next = Rear[i];
		Rear[i]->Next = Rear[i];
	}
}

void Put(int index, int num)
{
	ptrNode = (NODE *)malloc(sizeof(NODE));
	ptrNode->Data = num;

	if (Front[index]->Next == Rear[index])
	{
		Front[index]->Next = ptrNode;
		ptrNode->Next = Rear[index]; 
		Rear[index]->Next = ptrNode;
	}

	else
	{
		Rear[index]->Next->Next = ptrNode;
		ptrNode->Next = Rear[index];
		Rear[index]->Next = ptrNode;
	}
}

void Get(int Sortindex)
{
	NODE *ptr;
	NODE *deleteNode;
	ptr = Front[Sortindex]->Next;
	while (ptr != Rear[Sortindex])
	{
		Buf[IndexNum++] = ptr->Data;
		deleteNode = ptr;
		ptr = ptr->Next;
		free(deleteNode);
	}
	
	Front[Sortindex]->Next = Rear[Sortindex];
	Rear[Sortindex]->Next = Rear[Sortindex];
}

int main()
{
	int i = 0;

	InitializeQueue();

	srand((unsigned int)time(NULL));

	for (i = 0; i < 100; i++)
	{
		Buf[i] = rand() % MAX;
		if (IsNumberExist(Buf[i], i))
			i--;
	}

	printf("수정 전\n");
	for (i = 0; i < MAX; i++)
	{
		printf("%4d", Buf[i]);

		if (i % 10 == 9)
			putchar('\n');
	}

	RadixSort();

	printf("수정 후\n");
	for (i = 0; i < MAX; i++)
	{
		printf("%4d", Buf[i]);

		if (i % 10 == 9)
			putchar('\n');
	}

	return 0;
}