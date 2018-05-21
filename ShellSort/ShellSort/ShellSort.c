#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 100
#define TRUE 1
#define FALSE 0

void ShellSort(void);		//버블 정렬
int IsNumberExist(int, int);	//수 겹치기 않게 하기 위함
int Buf[MAX];					//정렬할 대상

void ShellSort(void)
{
	int i = 0, j = 0;
	int ChangeData;
	int Skip;

	for (Skip = MAX / 3 + 1; Skip >= 1; Skip = Skip / 3 + 1)
	{
		for (i = Skip; i < MAX; i++)
		{
			ChangeData = Buf[i];
			for (j = i; j >= Skip; j-=Skip)
			{
				if (Buf[j-Skip] < ChangeData)
					break;

				Buf[j] = Buf[j - Skip];
			}

			
			Buf[j] = ChangeData;
		}

		if (Skip == 1)
			break;
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

	ShellSort();

	printf("수정 후\n");
	for (i = 0; i < MAX; i++)
	{
		printf("%4d", Buf[i]);

		if (i % 10 == 9)
			putchar('\n');
	}

	return 0;
}