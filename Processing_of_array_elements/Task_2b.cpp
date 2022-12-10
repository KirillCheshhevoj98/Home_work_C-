#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<math.h >
#include<time.h>

int main()
{
	/*
		явл€етс€ ли k-й элемент массива четным числом;
	*/
	const int MAX_SIZE = 100;
	int arr[MAX_SIZE];
	int size;

	printf("Enter size array[1...%d]: ", MAX_SIZE);
	scanf("%d", &size);

	while (size < 1 || size > 100)
	{
		printf("Incorrect input\n");
		printf("Enter size array[1...%d]: ", MAX_SIZE);
		fflush(stdin);
		scanf("%d", &size);
	}

	srand(time(0));
	int startRange = -50, endRange = 50;
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % (endRange - startRange + 1) + startRange;
	}

	printf("Original array:\n");
	for (int i = 0; i < size; i++)
	{
		printf("%d element = %d\n", i + 1, arr[i]);
	}

	int num;

	printf("Enter number element: ");
	scanf("%d", &num);

	while (num < 1 || num > size)
	{
		printf("Incorrect input\n");
		fflush(stdin);
		scanf("%d", &num);
	}

	if (arr[num - 1] % 2 == 0)
	{
		printf("%d - even number", arr[num - 1]);
	}
	else
	{
		printf("%d - odd number", arr[num - 1]);
	}
	getchar();
	return 0;
}
