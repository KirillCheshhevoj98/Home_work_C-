#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<math.h >
#include<time.h>

int main()
{
	setlocale(LC_ALL, "Rus");

	int choice, fill_array, fExit = 1;
	const int MAX_SIZE = 100;
	int arr[MAX_SIZE];
	int size;
	int sum = 0;
	double average_mark = 0;
	int sort;
	int tmp;
	int num = 0;
	int mark_delete_choice, mark_delete, add_mark, marks;

	do
	{
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
		scanf("%d", &choice);

		switch (choice)
		{

			case 1:
			{
				printf("Fill in the list of marks: \n");
				printf("1. From keybord. \n");
				printf("2. Random numbers. \n");

				printf("Enter a menu item: ");
				scanf("%d", &fill_array);

				switch (fill_array)
				{

					case 1:
					{
						printf("Enter the length of the list of marks[1...%d]: ", MAX_SIZE);
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
							printf("Enter ¹%d mark: ", i + 1);
							scanf("%d", &arr[i]);
							}
				
					}
					break;

					case 2:
					{
						printf("Enter the length of the list of marks[1...%d]: ", MAX_SIZE);
						scanf("%d", &size);

						while (size < 1 || size > 100)
						{
							printf("Incorrect input \n");
							printf("Enter the length of the list of marks[1...%d]: ", MAX_SIZE);
							fflush(stdin);
							scanf("%d", &size);
						}

						srand(time(0));
						int startRange = 0, endRange = 10;

						for (int i = 0; i < size; i++)
						{
							arr[i] = rand() % (endRange - startRange + 1) + startRange;
						}
					}
					break;
					default:
						printf("Incorrect input.");
					break;
				}
			system("pause");
			system("cls");
			}
			break;

			case 2:
			{
				printf("The list of marks: \n");
				for (int i = 0; i < size; i++)
				{
					printf("¹ %d mark = %d \n", i + 1, arr[i]);
				}
			}
			system("pause");
			system("cls");
			break;

			case 3:
			{
				for (int i = 0; i < size; i++)
				{
					sum += arr[i];
				}
				printf("The sum all marks %d \n", sum);
			}
			system("pause");
			system("cls");
			break;
			

			case 4:
			{
				average_mark = (double)sum / size;
				printf("The average student mark %.2lf", average_mark);
			}
			system("pause");
			system("cls");
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
			system("pause");
			system("cls");
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
			system("pause");
			system("cls");
			break;

			case 7:
			{
				printf("Sorting the list of marks:\n");
				printf("1. Ascending. \n");
				printf("2. Descending. \n");

				printf("Enter a menu item: ");
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
						printf("¹ %d mark = %d \n", i + 1, arr[i]);
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
						printf("¹ %d mark = %d \n", i + 1, arr[i]);
					}
				}
				break;

				default:
					printf("Incorrect input.");
					break;
				}
			}
			system("pause");
			system("cls");
			break;

			case 8:
			{
				printf("Removing a mark from the list: \n");
				printf("1. By serial number. \n");
				printf("2. By the value of the mark. \n");

				printf("Enter a menu item: ");
				scanf("%d", &mark_delete_choice);

				switch (mark_delete_choice)
				{
					case 1:
					{
						printf("The list of marks: \n");
						for (int i = 0; i < size; i++)
						{
							printf("¹ %d mark = %d \n", i + 1, arr[i]);
						}

						printf("Enter the number of the mark you want to delete: ");
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

						printf("The new list of marks:\n");
						for (int i = 0; i < size - 1; i++)
						{
							printf("¹ %d mark = %d\n", i + 1, arr[i]);
						}
					}
					system("pause");
					system("cls");
					break;

					case 2:
					{
						printf("The list of marks: \n");
						for (int i = 0; i < size; i++)
						{
							printf("¹ %d mark = %d\n", i + 1, arr[i]);
						}

						printf("Enter the value of the marks you want to delete: ");
						scanf("%d", &mark_delete);

						while (mark_delete < 0 || mark_delete > 10);
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
								arr[i] = arr[i + 1];
							}
						}

						printf("The new list of marks:\n");
						for (int i = 0; i < size - 1; i++)
						{
							printf("¹ %d mark = %d\n", i + 1, arr[i]);
						}
					}
					system("pause");
					system("cls");
					break;

				default:
					printf("Incorrect input");
					break;
				}
				
			}
			system("pause");
			system("cls");
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
				case 1:
				{
					printf("Enter the mark value: ");
					scanf("%d", &arr[size + 1]);

					if (arr[size + 1] >= 0 || arr[size + 1] <= 10)
					{
						printf("The new list of marks:\n");
						for (int i = 0; i < size + 1; i++)
						{
							printf("¹ %d mark = %d\n", i + 1, arr[i]);
						}
					}
				}
					system("pause");
					system("cls");
					break;
				case 2:
				{
					printf("Enter the mark value: ");
					scanf("%d", &marks);

					while (marks < 1 || marks > MAX_SIZE - size)
					{

					}
				}
					system("pause");
					system("cls");
					break;
				default:
					break;
				}
			}
			system("pause");
			system("cls");
			break;

			case 10:
			{
				fExit = 0;
			}
			system("pause");
			system("cls");
			break;
		}
	} while (fExit == 1);

	getchar();
	return 0;
}