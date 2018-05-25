#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 100
#define TRUE 1
#define FALSE 0

void QuickSort(int, int);		//���� ����
int IsNumberExist(int, int);	//�� ��ġ�� �ʰ� �ϱ� ����
int Buf[MAX];					//������ ���

void QuickSort(int Left, int Right)
{
	int ChangeData, i, j, Temp;

	if (Left < Right)
	{
		ChangeData = Buf[Right];
		i = Left - 1;
		j = Right;
		for (;;)
		{
			while (Buf[++i] < ChangeData);
			while (Buf[--j] > ChangeData);
			if (i >= j)
				break;

			Temp = Buf[i];
			Buf[i] = Buf[j];
			Buf[j] = Temp;
		}
		Temp = Buf[i];
		Buf[i] = Buf[Right];
		Buf[Right] = Temp;

		QuickSort(Left, i - 1);
		QuickSort(i + 1, Right);
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

	printf("���� ��\n");
	for (i = 0; i < MAX; i++)
	{
		printf("%4d", Buf[i]);

		if (i % 10 == 9)
			putchar('\n');
	}

	QuickSort(0, MAX - 1);

	printf("���� ��\n");
	for (i = 0; i < MAX; i++)
	{
		printf("%4d", Buf[i]);

		if (i % 10 == 9)
			putchar('\n');
	}

	return 0;
}