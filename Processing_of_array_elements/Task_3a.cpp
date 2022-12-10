#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<math.h >
#include<time.h>

int main()
{
	/*
		Все элементы массива увеличить в 2 раза. 
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

	for (int i = 0; i < size; i++)
	{
		arr[i] *= 2;
	}

	printf("Changed array:\n");
	for (int i = 0; i < size; i++)
	{
		printf("%d element = %d\n", i + 1, arr[i]);
	}
	getchar();
	return 0;
}
