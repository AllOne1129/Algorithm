#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 100
#define TRUE 1
#define FALSE 0

void BubbleSort(void);		//���� ����
int IsNumberExist(int, int);	//�� ��ġ�� �ʰ� �ϱ� ����
int Buf[MAX];					//������ ���

void BubbleSort(void)
{
	int i = 0, j = 0;
	int Temp = 0;

	for (i = 0; i < MAX; i++)
	{
		for (j = 0; j < 99 - i; j++)
		{
			if (Buf[j] > Buf[j + 1])
			{
				Temp = Buf[j];
				Buf[j] = Buf[j + 1];
				Buf[j + 1] = Temp;
			}
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

	BubbleSort();

	printf("���� ��\n");
	for (i = 0; i < MAX; i++)
	{
		printf("%4d", Buf[i]);

		if (i % 10 == 9)
			putchar('\n');
	}

	return 0;
}