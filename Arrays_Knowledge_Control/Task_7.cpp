#include<stdio.h>
#include<conio.h>
#include<locale.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>

int main()
{
	/*
	Даны 2 массива.
	Получить третий массив из отрицательных элементов первого, кратных трем, и четных положительных элементов второго. Полученный массив отсортировать по убыванию.
	*/

	setlocale(LC_ALL, "rus");
	const int MAX_SIZE = 100;
	int arr1[MAX_SIZE], arr2[MAX_SIZE], arr3[MAX_SIZE], arr4[MAX_SIZE], arr5[MAX_SIZE];
	int size1,size2;
	printf("Enter the number of elements[1..%d] of array №1\n", MAX_SIZE);
	scanf("%d", &size1);
	while (size1<1 || size1>MAX_SIZE)
	{
		printf("Incorrect input, try again\n");
		fflush(stdin);
		scanf("%d", &size1);
	}

	srand(time(0));
	int startRange = -10, endRange = 10;
	for (int i = 0; i < size1; i++)
	{
		arr1[i] = rand() % (endRange - startRange + 1) + startRange;
	}

	printf("Source array\n");
	for (int i = 0; i < size1; i++)
	{
		printf("%d) %d\n", i + 1, arr1[i]);
	}

	printf("Enter the number of elements[1..%d] of array №2\n", MAX_SIZE);
	scanf("%d", &size2);
	while (size2<1 || size2>MAX_SIZE)
	{
		printf("Incorrect input, try again\n");
		fflush(stdin);
		scanf("%d", &size2);
	}

	srand(time(0));
	for (int i = 0; i < size2; i++)
	{
		arr2[i] = rand() % (endRange - startRange + 1) + startRange;
	}

	printf("Source array\n");
	for (int i = 0; i < size2; i++)
	{
		printf("%d) %d\n", i + 1, arr2[i]);
	}

	int i3 = 0, i4 = 0;
	for (int i = 0; i < size1; i++)
	{
		if (arr1[i] < 0 && arr1[i] % 3 == 0)
		{
			arr3[i3] = arr1[i];
			i3++;
		}
	}

	for (int i = 0; i < size2; i++)
	{
		if (arr2[i] > 0 && arr2[i] % 2 == 0)
		{
			arr3[i4] = arr2[i];
			i4++;
		}
	}
	
	int tmp = i3 + i4;

	for (int i = 0; i < tmp; i++)
	{
		printf("%d) %d\n", i + 1, arr3[i]);
	}
	getchar();
	return 0;
}
