#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 100
#define TRUE 1
#define FALSE 0

void InsertionSort(void);		//삽입 정렬
int IsNumberExist(int, int);	//수 겹치기 않게 하기 위함
int Buf[MAX];					//정렬할 대상

void InsertionSort(void)
{
	int i = 0, j = 0;
	int ChangeData;
	int Temp=0;

	for (i = 0; i < MAX; i++)
	{
		ChangeData = Buf[i];
		Temp = 100;
		for (j = i; j >= 0; j--)
		{
			if (Buf[j] < ChangeData)
				break;
			
			Buf[j] = Buf[j-1];
		}

		Buf[j+1]=ChangeData;
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

int main()
{
	int i = 0;

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

	InsertionSort();

	printf("수정 후\n");
	for (i = 0; i < MAX; i++)
	{
		printf("%4d", Buf[i]);

		if (i % 10 == 9)
			putchar('\n');
	}

	return 0;
}