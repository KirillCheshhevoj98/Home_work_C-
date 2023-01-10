#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<math.h >
#include<time.h>
#include<Windows.h>

void Incorrect_input_array(int size);
void Incorrect_input_mark(int mark, int size);
void Incorrect_input_marks(int marks);
void Print_Array_Marks(int* array, int size);
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
	setlocale(LC_ALL, "RUS");

	const int MIN_VALUE_MARK = 1, MAX_VALUE_MARK = 10;
	int* array = NULL;
	int choice_menu, choice_fill_array, sort_choice, mark_delete_choice;
	int fExit = 1;
	int size = 0, mark, marks;

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
		scanf("%d", &choice_menu);

		switch (choice_menu)
		{
			case 1: 
			{
				printf("Fill in the list of marks: \n");
				printf("1. From keybord. \n");
				printf("2. Random numbers. \n");

				printf("Enter a menu item: ");
				fflush(stdin);
				scanf("%d", &choice_fill_array);

				switch (choice_fill_array)
				{
					case 1:
					{
						printf("Enter the length of the list of marks: ");
						fflush(stdin);
						scanf("%d", &size);

						Incorrect_input_array(size);

						if (array != NULL)
						{
							free(array);
						}
						array = (int*)malloc(size * sizeof(int));

						Keybord_Array_Fill(array, size);
					}
					break;

					case 2:
					{
						printf("Enter the length of the list of marks: ");
						fflush(stdin);
						scanf("%d", &size);

						Incorrect_input_array(size);

						if (array != NULL)
						{
							free(array);
						}
						array = (int*)malloc(size * sizeof(int));

						Random_Array_Fill(array, size, MIN_VALUE_MARK, MAX_VALUE_MARK);
					}
					break;

					default:
					{
						printf("Incorrect input.\n");
					}
					break;
				}
			}
			break;

			case 2:
			{
				Print_Array_Marks(array, size);
			}
			break;

			case 3:
			{
				printf("The sum all marks %d\n", Sum_All_Marks(array, size));
			}
			break;

			case 4:
			{
				printf("The average student mark %.2lf\n", Average_mark(array, size));
			}
			break;

			case 5:
			{
				printf("The value of the maximum mark of the student: %d\n", Value_of_the_maximum_mark(array, size));
			}
			break;

			case 6:
			{
				printf("The value of the minimum mark of the student: %d\n", Value_of_the_minimum_mark(array, size));
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
					std::cin >> mark;
					//scanf("%d", &mark);

					Incorrect_input_mark(mark, size);

					Removing_serial_number(array, size, mark);
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

				}

				default:
				{
					printf("Encorrect input");
				}
				break;
				}
			}
			break;

			case 10:
			{
				fExit = 0;
			}
			break;

			default:
			{
				printf("Incorrect input.\n");
			}
			break;
		}
		system("pause");
		system("cls");
	} while (fExit == 1);

	getchar();
	return 0;
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

void Print_Array_Marks(int* array, int size)
{
	printf("The list of marks: \n");

	for (int i = 0; i < size; i++)
	{
		printf("%d) %d\n", i + 1, *(array + i));
	}
}

void Keybord_Array_Fill(int* array, int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("Enter ¹%d mark: ", i + 1);
		fflush(stdin);
		scanf("%d", (array + i));
	}
}

void Random_Array_Fill(int* array, int size, int startValue, int endValue)
{
	srand(time(0));
	for (int i = 0; i < size; i++)
	{
		*(array + i) = rand() % (endValue - startValue + 1) + startValue;
	}
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

	for (int i = 0; i < size; i++)
	{
		if (array[i] > maximum_mark)
		{
			maximum_mark = array[i];
		}
	}

	return maximum_mark;
}

int Value_of_the_minimum_mark(int* array, int size)
{
	int minimum_mark = array[0];

	for (int i = 0; i < size; i++)
	{
		if (array[i] < minimum_mark)
		{
			minimum_mark = array[i];
		}
	}

	return minimum_mark;
}

void Ascending_Sort_Array(int* array, int size)
{
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
}

void Descending_Sort_Array(int* array, int size)
{
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
}

void Removing_serial_number(int* array, int size, int mark)
{
	for (int i = mark; i < size; i++)
	{
		array[i] = array[i + 1];
	}
	size--;
}

void Removing_value_of_the_marks(int* array, int size, int marks)
{
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
}