#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<math.h >
#include<time.h>
#include<Windows.h>

int main()
{
	setlocale(LC_ALL, "Rus");

	int choice, fill_array, fExit = 1;
	const int MAX_SIZE = 100;
	int arr[MAX_SIZE];
	int size = 0, sum = 0, num = 0;
	double average_mark = 0;
	int sort;
	int tmp;
	int mark_delete_choice, mark_delete, add_mark, add_marks, mark, marks;
	int position;

	do
	{
		if (size > 0)
		{
			for (int i = 0; i < size; i++)
			{
				printf("%d ", arr[i]);
			}
			printf("\n");
		}

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
			{
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
						printf("Enter the length of the list of marks[1...%d]: ", MAX_SIZE);
						fflush(stdin);
						scanf("%d", &size);

						while (size < 1 || size > 100)
						{
							printf("Incorrect input. \n");
							printf("Enter the length of the list of marks[1...%d]: ", MAX_SIZE);
							fflush(stdin);
							scanf("%d", &size);
						}

							for (int i = 0; i < size; i++)
							{
								printf("Enter ?%d mark: ", i + 1);
								fflush(stdin);
								scanf("%d", &arr[i]);
							}
				
					}
					break;

					case 2:
					{
						printf("Enter the length of the list of marks[1...%d]: ", MAX_SIZE);
						fflush(stdin);
						scanf("%d", &size);

						while (size < 1 || size > 100)
						{
							printf("Incorrect input \n");
							printf("Enter the length of the list of marks[1...%d]: ", MAX_SIZE);
							fflush(stdin);
							scanf("%d", &size);
						}

						srand(time(0));
						int startRange = 1, endRange = 10;

						for (int i = 0; i < size; i++)
						{
							arr[i] = rand() % (endRange - startRange + 1) + startRange;
						}
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

			case 2:
			{
				printf("The list of marks: \n");
				for (int i = 0; i < size; i++)
				{
					printf("? %d mark = %d \n", i + 1, arr[i]);
				}
			}
			break;

			case 3:
			{
				for (int i = 0; i < size; i++)
				{
					sum += arr[i];
				}
				printf("The sum all marks %d \n", sum);
			}
			break;
			

			case 4:
			{
				average_mark = (double)sum / size;
				printf("The average student mark %.2lf", average_mark);
			}
			break;

			case 5:
			{
				int max = arr[0];

				for (int i = 0; i < size; i++)
				{
					if (arr[i] > max)
					{
						max = arr[i];
					}
				}
				printf("The value of the maximum mark of the student: %d", max);
			}
			break;

			case 6:
			{
				int min = arr[0];

				for (int i = 0; i < size; i++)
				{
					if (arr[i] < min)
					{
						min = arr[i];
					}
				}
				printf("The value of the minimum mark of the student: %d", min);
			}
			break;

			case 7:
			{
				printf("Sorting the list of marks:\n");
				printf("1. Ascending. \n");
				printf("2. Descending. \n");

				printf("Enter a menu item: ");
				fflush(stdin);
				scanf("%d", &sort);

				switch (sort)
				{

				case 1:
				{
					for (int j = 0; j < size - 1; j++)
					{
						for (int i = 0; i < size - 1 - j; i++)
						{
							if (arr[i] > arr[i + 1])
							{
								tmp = arr[i];
								arr[i] = arr[i + 1];
								arr[i + 1] = tmp;
							}
						}
					}

					printf("Sorted array: \n");
					for (int i = 0; i < size; i++)
					{
						printf("? %d mark = %d \n", i + 1, arr[i]);
					}
				}
				break;

				case 2:
				{
					for (int j = 0; j < size - 1; j++)
					{
						for (int i = 0; i < size - 1 - j; i++)
						{
							if (arr[i] < arr[i + 1])
							{
								tmp = arr[i];
								arr[i] = arr[i + 1];
								arr[i + 1] = tmp;
							}
						}
					}

					printf("Sorted array: \n");
					for (int i = 0; i < size; i++)
					{
						printf("? %d mark = %d \n", i + 1, arr[i]);
					}
				}
				break;

				default:
					printf("Incorrect input.");
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
						printf("The list of marks: \n");
						for (int i = 0; i < size; i++)
						{
							printf("? %d mark = %d \n", i + 1, arr[i]);
						}

						printf("Enter the number of the mark you want to delete: ");
						fflush(stdin);
						scanf("%d", &num);

						while (num < 1 || num > size);
						{
							printf("Incorrect input. \n");
							printf("Enter the number of the mark you want to delete: ");
							fflush(stdin);
							scanf("%d", &num);
						}

						for (int i = num - 1; i < size - 1; i++)
						{
							arr[i] = arr[i + 1];
						}
						size--;

						printf("The new list of marks:\n");
						for (int i = 0; i < size; i++)
						{
							printf("? %d mark = %d\n", i + 1, arr[i]);
						}
					}
					break;

					case 2:
					{
						printf("The list of marks: \n");
						for (int i = 0; i < size; i++)
						{
							printf("? %d mark = %d\n", i + 1, arr[i]);
						}

						printf("Enter the value of the marks you want to delete: ");
						fflush(stdin);
						scanf("%d", &mark_delete);

						while (mark_delete < 1 || mark_delete > 10);
						{
							printf("Incorrect input. \n");
							printf("Enter the value of the marks you want to delete: ");
							fflush(stdin);
							scanf("%d", &mark_delete);
						}

						for (int i = 0; i < size; i++)
						{
							if (arr[i] == mark_delete)
							{
								for (int j = i; j < size - 1; j++)
								{
									arr[j] = arr[j + 1];
								}
								size--;
								i--;
							}
						}
						size--;

						printf("The new list of marks:\n");
						for (int i = 0; i < size; i++)
						{
							printf("? %d mark = %d\n", i + 1, arr[i]);
						}
					}
					break;

				default:
					printf("Incorrect input");
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
				fflush(stdin);
				scanf("%d", &add_mark);

				switch (add_mark)
				{
				case 1:
				{
					printf("Enter the mark value: ");
					fflush(stdin);
					scanf("%d", &mark);

					if (mark > 1 || mark < 10)
					{
						arr[size] = mark;
						printf("The new list of marks:\n");
						for (int i = 0; i < size + 1; i++)
						{
							printf("? %d mark = %d\n", i + 1, arr[i]);
						}
					}
				}
					break;
				case 2:
				{
					int array1[MAX_SIZE];

					printf("Enter the mark value: ");
					fflush(stdin);
					scanf("%d", &add_marks);

					while (add_marks < 1 || add_marks > MAX_SIZE - size)
					{
						printf("Incorrect input. \n");
						printf("Enter the number of ratings: ");
						fflush(stdin);
						scanf("%d", &add_marks);
					}

					for (int i = 0; i < add_marks; i++)
					{
					}
				}
					break;
				default:
					break;
				}
			}
			break;

			case 10:
			{
				fExit = 0;
			}
			break;
		}
		system("pause");
		system("cls");
	} while (fExit == 1);

	getchar();
	return 0;
}