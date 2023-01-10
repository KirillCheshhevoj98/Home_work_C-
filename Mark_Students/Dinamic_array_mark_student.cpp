#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<math.h >
#include<time.h>
#include<Windows.h>

void Print_Array_Marks(int* array, int size);
void Incorrect_input_array(int size);
void Incorrect_input_mark(int mark, int size);
void Incorrect_input_marks(int marks);
void Keybord_Array_Fill(int* array, int size);
void Random_Array_Fill(int* array, int size, int startValue, int endValue);
int Sum_All_Marks(int* array, int size);
double Average_mark(int* array, int size);
int Value_of_the_maximum_mark(int* array, int size);
int Value_of_the_minimum_mark(int* array, int size);
void Ascending_Sort_Array(int* array, int size);
void Descending_Sort_Array(int* array, int size);
void Removing_serial_number(int* array, int size, int mark);
void Removing_value_of_the_marks(int* array, int size, int marks);

int main()
{
	setlocale(LC_ALL, "Rus");

	int fExit = 1;
	int choice, fill_array, sort_choice, mark_delete_choice;
	int* array = NULL;
	int size = 0;
	int mark, marks;
	int add_mark;
	do
	{
		Print_Array_Marks(array, size);
		printf("1. Fill in the list of marks.\n");
		printf("2. Displaying a list of marks on the console screen. \n");
		printf("3. Finding the sum of all marks. \n");
		printf("4. Finding the average student mark. \n");
		printf("5. Finding the value of the maximum mark of the student. \n");
		printf("6. Finding the value of the minimum mark of the student. \n");
		printf("7. Sorting the list of marks. \n");
		printf("8. Removing a mark from the list. \n");
		printf("9. Add marks to the list. \n");
		printf("10. Exit.\n");

		printf("Enter a menu item: ");
		fflush(stdin);
		scanf("%d", &choice);

		switch (choice)
		{
			case 1:
				printf("Fill in the list of marks: \n");
				printf("1. From keybord. \n");
				printf("2. Random numbers. \n");

				printf("Enter a menu item: ");
				fflush(stdin);
				scanf("%d", &fill_array);

				switch (fill_array)
				{
					case 1:
					{
						printf("Enter the length of the list of marks: ");
						fflush(stdin);
						scanf("%d", &size);

						Incorrect_input_array(size);

						Keybord_Array_Fill(array, size);

						Print_Array_Marks(array, size);
					}
					break;

					case 2:
					{
						printf("Enter the length of the list of marks: ");
						fflush(stdin);
						scanf("%d", &size);

						Incorrect_input_array(size);

						Random_Array_Fill(array, size, 0, 10);

						Print_Array_Marks(array, size);
					}
					break;

					default:
					{
						printf("Incorrect input.");
					}
					break;
				}
				break;

			case 2:
			{
				Print_Array_Marks(array, size);
			}
			break;

			case 3:
			{
				printf("The sum all marks %d \n", Sum_All_Marks(array, size));
			}
			break;

			case 4:
			{
				printf("The average student mark %.2lf", Average_mark(array, size));
			}
			break;

			case 5:
			{
				printf("The value of the maximum mark of the student: %d", Value_of_the_maximum_mark(array, size));
			}
			break;

			case 6:
			{
				printf("The value of the minimum mark of the student: %d", Value_of_the_minimum_mark(array, size));
			}
			break;

			case 7:
			{
				printf("Sorting the list of marks:\n");
				printf("1. Ascending. \n");
				printf("2. Descending. \n");

				printf("Enter a menu item: ");
				fflush(stdin);
				scanf("%d", &sort_choice);

				switch (sort_choice)
				{
					case 1:
					{
						Ascending_Sort_Array(array, size);

						printf("Sorted array: \n");

						Print_Array_Marks(array, size);
					}
					break;

					case 2:
					{
						Descending_Sort_Array(array, size);

						printf("Sorted array: \n");

						Print_Array_Marks(array, size);
					}
					break;

					default:
					{
						printf("Incorrect input.");
					}
					break;
				}
			}
			break;

			case 8:
			{
				printf("Removing a mark from the list: \n");
				printf("1. By serial number. \n");
				printf("2. By the value of the mark. \n");

				printf("Enter a menu item: ");
				fflush(stdin);
				scanf("%d", &mark_delete_choice);

				switch (mark_delete_choice)
				{
					case 1:
					{
						Print_Array_Marks(array, size);

						printf("Enter the number of the mark you want to delete: ");
						fflush(stdin);
						scanf("%d", &mark);

						Incorrect_input_mark(mark, size);

						Removing_serial_number(array, size, mark);

						Print_Array_Marks(array, size);
					}
					break;

					case 2:
					{
						Print_Array_Marks(array, size);

						printf("Enter the value of the marks you want to delete: ");
						fflush(stdin);
						scanf("%d", &marks);

						Incorrect_input_marks(marks);

						Removing_value_of_the_marks(array, size, marks);

						Print_Array_Marks(array, size);
					}

					default:
					{
						printf("Encorrect input");
					}
					break;
				}
			}
			break;

			case 9:
			{
				printf("Add marks to the list: \n");
				printf("1. One mark at the end of the list. \n");
				printf("2. A few marks at the end of the list. \n");
				printf("3. The specified number of marks in the specified position. \n");

				printf("Enter a menu item: ");
				scanf("%d", &add_mark);

				switch (add_mark)
				{

				}
			}
			break;

			case 10:
				fExit = 0;
			break;
		}
		system("pause");
		system("cls");
	} while (fExit == 1);

	getchar();
	return 0;
}

void Print_Array_Marks(int* array, int size)
{
	array = (int*)malloc(size * sizeof(int));

	printf("The list of marks: \n");

	for (int i = 0; i < size; i++)
	{
		printf("%d) %d\n", i + 1, *(array + i));
	}

	free(array);
	array = NULL;
}

void Incorrect_input_array(int size)
{
	while (size < 1)
	{
		printf("Incorrect input. \n");
		printf("Enter the length of the list of marks: ");
		fflush(stdin);
		scanf("%d", &size);
	}
}

void Incorrect_input_mark(int mark, int size)
{
	while (mark < 1 || mark > size);
	{
		printf("Incorrect input. \n");
		printf("Enter the number of the mark you want to delete: ");
		fflush(stdin);
		scanf("%d", &mark);
	}
}

void Incorrect_input_marks(int marks)
{
	while (marks < 1 || marks > 10);
	{
		printf("Incorrect input. \n");
		printf("Enter the value of the marks you want to delete: ");
		fflush(stdin);
		scanf("%d", &marks);
	}
}

void Keybord_Array_Fill(int* array, int size)
{
	array = (int*)malloc(size * sizeof(int));

	for (int i = 0; i < size; i++)
	{
		printf("Enter ¹%d mark: ", i + 1);
		fflush(stdin);
		scanf("%d", (array+i));
	}
}

void Random_Array_Fill(int* array, int size, int startValue, int endValue)
{
	array = (int*)malloc(size * sizeof(int));

	srand(time(0));
	for (int i = 0; i < size; i++)
	{
		*(array + i) = rand() % (endValue - startValue + 1) + startValue;
	}

	free(array);
	array = NULL;
}

int Sum_All_Marks(int* array, int size)
{
	int sum = 0;

	for (int i = 0; i < size; i++)
	{
		sum += array[i];
	}

	return sum;
}

double Average_mark(int* array, int size)
{
	double average_mark = 0;
	average_mark = (double)Sum_All_Marks(array, size) / size;
	return average_mark;
}

int Value_of_the_maximum_mark(int* array, int size)
{
	int maximum_mark = array[0];

	array = (int*)malloc(size * sizeof(int));

	for (int i = 0; i < size; i++)
	{
		if (array[i] > maximum_mark)
		{
			maximum_mark = array[i];
		}
	}

	free(array);
	array = NULL;

	return maximum_mark;
}

int Value_of_the_minimum_mark(int* array, int size)
{
	int minimum_mark = array[0];

	array = (int*)malloc(size * sizeof(int));

	for (int i = 0; i < size; i++)
	{
		minimum_mark = array[i];
	}

	free(array);
	array = NULL;

	return minimum_mark;
}

void Ascending_Sort_Array(int* array, int size)
{
	array = (int*)malloc(size * sizeof(int));

	int tmp;

	for (int j = 0; j < size - 1; j++)
	{
		for (int i = 0; i < size - 1 - j; i++)
		{
			if (array[i] > array[i + 1])
			{
				tmp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = tmp;
			}
		}
	}

	free(array);
	array = NULL;
}

void Descending_Sort_Array(int* array, int size)
{
	array = (int*)malloc(size * sizeof(int));

	int tmp;

	for (int j = 0; j < size - 1; j++)
	{
		for (int i = 0; i < size - 1 - j; i++)
		{
			if (array[i] < array[i + 1])
			{
				tmp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = tmp;
			}
		}
	}

	free(array);
	array = NULL;
}

void Removing_serial_number(int* array, int size, int mark)
{
	array = (int*)malloc(size * sizeof(int));

	for (int i = mark - 1; i < size - 1; i++)
	{
		array[i] = array[i + 1];
	}
	size--;

	free(array);
	array = NULL;
}

void Removing_value_of_the_marks(int* array, int size, int marks)
{
	array = (int*)malloc(size * sizeof(int));

	for (int i = 0; i < size; i++)
	{
		if (array[i] == marks)
		{
			for (int j = i; j < size - 1; j++)
			{
				array[j] = array[j + 1];
			}
			size--;
			i--;
		}
	}
	size--;

	free(array);
	array = NULL;
}


