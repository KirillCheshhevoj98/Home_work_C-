#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<math.h >
#include<time.h>

int main()
{
	/*
		сумму элементов массива с k1-го по k2-й (значения k1 и k2 вводятся с клавиатуры; k2 > k1);
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
	int startRange = 0, endRange = 10;
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % (endRange - startRange + 1) + startRange;
	}

	printf("Original array:\n");
	for (int i = 0; i < size; i++)
	{
		printf("%d element = %d\n", i + 1, arr[i]);
	}

	int num1 = 0;
	printf("Enter number1: ");
	scanf("%d", &num1);

	while (num1 < 1 || num1 > size)
	{
		printf("Incorect input.\n");
		fflush(stdin);
		scanf("%d", &num1);
	}

	int num2 = 0;
	printf("Enter number2: ");
	scanf("%d", &num2);

	while (num2 < num1 || num2 > size)
	{
		printf("Incorect input.\n");
		fflush(stdin);
		scanf("%d", &num2);
	}
	
	int sum = 0;
	
	for (int i = 0; i < size; i++)
	{
		if (i >= num1 - 1 && i <= num2 - 1)
		{
			sum += arr[i];
		}
	}

	printf("Sum elements array = %d", sum);
	getchar();
	return 0;
}
