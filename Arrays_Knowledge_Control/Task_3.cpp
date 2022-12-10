#include<stdio.h>
#include<conio.h>
#include<locale.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>

int main()
{
	/*
	Дан массив. 
	Все элементы массива расположить в обратном порядке.
	*/

	setlocale(LC_ALL, "rus");
	const int MAX_SIZE = 100;
	int arr[MAX_SIZE];
	int size, sum_even = 0, sum_add = 0;

	printf("Enter the number of elements[1..%d]\n", MAX_SIZE);
	scanf("%d", &size);
	while (size<1 || size>MAX_SIZE)
	{
		printf("Incorrect input, try again\n");
		fflush(stdin);
		scanf("%d", &size);
	}

	srand(time(0));
	int startRange = -10, endRange = 10;
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % (endRange - startRange + 1) + startRange;
	}

	printf("Source array\n");
	for (int i = 0; i < size; i++)
	{
		printf("%d) %d\n", i + 1, arr[i]);
	}

	printf("Processed array\n");
	int j = 0;
	for (int i = size - 1; i >= 0; i--, j++)
	{
			printf("%d) %d\n", j + 1, arr[i]);
	}
	getchar();
	return 0;
}
