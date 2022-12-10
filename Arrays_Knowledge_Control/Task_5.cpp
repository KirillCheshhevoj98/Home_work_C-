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
	Определить среднее арифметическое кратных 5 и некратных 10.
	*/

	setlocale(LC_ALL, "rus");
	const int MAX_SIZE = 100;
	int arr[MAX_SIZE];
	int size, max, imax;
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

	int sum = 0;
	int counter = 0;
	double average_value = 0;
	for (int i = 0; i < size; i++)
	{
		if (arr[i] % 5 == 0 || arr[i] % 10 > 0)
		{
			sum += arr[i];
			counter++;
		}
	}

	average_value = (double)sum / counter;

	printf("The arithmetic mean of multiples of 5 and non-multiples of 10: %.2lf\n", average_value);
	getchar();
	return 0;
}
