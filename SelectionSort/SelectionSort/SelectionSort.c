#include <stdio.h>
#include <stdlib.h>
#define MAX 100
#define TRUE 1
#define FALSE 0

void SelectionSort(void);		//선택 정렬
int IsNumberExist(int, int);	//수 겹치기 않게 하기 위함
int Buf[MAX];					//정렬할 대상

void SelectionSort(void)
{
	int i = 0, j = 0;
	int ChangeData;
	int Temp;

	for (i = 0; i < MAX; i++)
	{
		for (j = i + 1; j < MAX; j++)
		{
			if (j == i + 1 || Buf[j] < Buf[ChangeData])
				ChangeData = j;
		}

		if (Buf[ChangeData] < Buf[i])
		{
			Temp = Buf[i];
			Buf[i] = Buf[ChangeData];
			Buf[ChangeData] = Temp;
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

int main()
{
	int i = 0;
	for (i = 0; i < 100; i++)
	{
		Buf[i] = rand() % MAX;
		if (IsNumberExist(Buf[i],i))
			i--;
	}

	printf("수정 전\n");
	for (i = 0; i < MAX; i++)
	{
		printf("%4d", Buf[i]);
		
		if (i % 10 == 9)
			putchar('\n');
	}

	SelectionSort();

	printf("수정 후\n");
	for (i = 0; i < MAX; i++)
	{
		printf("%4d", Buf[i]);

		if (i % 10 == 9)
			putchar('\n');
	}

	return 0;
}