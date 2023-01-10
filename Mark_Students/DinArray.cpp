#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<math.h >
#include<time.h>
#include<Windows.h>

void Random_Array_Fill(int* array, int size, int startValue, int endValue)
{
	srand(time(0));
	for (int i = 0; i < size; i++)
	{
		*(array + i) = rand() % (endValue - startValue + 1) + startValue;
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

int main()
{
	setlocale(LC_ALL, "Rus");

	int* arr = NULL;
	int size, menu1, fill_array, fExit = 1;

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
		fflush(stdin);
		scanf("%d", &menu1);

		switch (menu1)
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

						}
						break;

						case 2:
						{
							printf("Enter the length of the list of marks: ");
							fflush(stdin);
							scanf("%d", &size);
							while (size < 1)
							{
								printf("Incorrect input. \n");
								printf("Enter the length of the list of marks: ");
								fflush(stdin);
								scanf("%d", &size);
							}
							if (arr != NULL)
							{
								free(arr);
							}
							arr = (int*)malloc(size * sizeof(int));

							Random_Array_Fill(arr, size, 0, 10);

						}
						break;

						default:
						{

						}
						break;
					}
				}
			break;
			case 2:
				{
				Print_Array_Marks(arr, size);
				}
			break;
			case 3:
				{

				}
			break;
			case 4:
				{

				}
			break;
			case 5:
				{

				}
			break;
			case 6:
				{

				}
			break;
			case 7:
				{
	
				}
			break;
			case 8:
				{

				}
			break;
			case 9:
				{

				}
			break;
			case 10:
				{

				}
			break;
			default:
				{

				}
			break;
		}
	} while (fExit == 1);

	getchar();
	return 0;
}




