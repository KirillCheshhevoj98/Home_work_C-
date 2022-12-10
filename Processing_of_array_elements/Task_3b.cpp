#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<math.h >
#include<time.h>

int main()
{
	/*
		Все элементы массива уменьшить на число А.
	*/
	const int MAX_SIZE = 100;
	double arr[MAX_SIZE];
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
		printf("%d element = %.2lf\n", i + 1, arr[i]);
	}

	int value;
	printf("Enter value: ");
	scanf("%d", &value);

	while (value == 0)
	{
		printf("Incorrect input\n");
		fflush(stdin);
		scanf("%d", &value);
	}
	for (int i = 0; i < size; i++)
	{
		arr[i] /= value;
	}

	printf("Changed array:\n");
	
	for (int i = 0; i < size; i++)
	{
		printf("%d element = %.2lf\n", i + 1, arr[i]);
	}
	getchar();
	return 0;
}
