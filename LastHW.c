#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
#define N 7
#define X 4
typedef struct
{
	char name[20];
	char color[10];
	float price;
	int code;
	int size;
}PRODUCT;
typedef struct
{
	int catalog_name;
	char book_name[30];
	char autor_name[20];
	int number_of_pages;
	int year_of_Publish;
}Book;

void main()
{
	int num = 0;

	while (1)
	{
		printf("Amit 312416472 & ziv 311516207 Project ");
		printf("choose a program:\n");
		printf("1- exercise 1\n");
		printf("2- exercise 2\n");
		printf("3- exercise 3\n");
		printf("4- exit\n");
		scanf_s("%d", &num);

		switch (num)
		{
		case 1:
		{
			exercise1();
			break;
		}

		case 2:
		{
			exercise2();
			break;
		}
		case 3:
		{
			exercise3();
			break;
		}

		case 4:
		{
			return;
		}


		}
	}

}

void exercise1()

{
	int arr[20];
	int i, *copyarr, *index, *sum;
	printf("enter 20 numbers\n");
	for (i = 0; i < 20; i++) {
		scanf("%d", &arr[i]);
	}
	SPEICEL_NUMBER(arr, &copyarr, &index, &sum);
	printf("\nthe special number is - %d\n", copyarr);
	printf("the sum of the special number digits is - %d\n", sum);
	printf("the index of the special number is - %d", index);

}
int SPEICEL_NUMBER(int arr[20], int *copyarr, int *index, int *sum)
{
	int reverse = 0;
	int sum1 = 0;
	int i, n = 0;
	for (i = 0; i < 20; i++)
	{
		if (arr[i] % 2 == 0) {
			*copyarr = arr[i];
			while (*copyarr != 0) {
				n = *copyarr % 10;
				reverse = (reverse * 10) + n;
				*copyarr /= 10;
				sum1 = sum1 + n;


			}
			if (arr[i] == reverse) {

				*copyarr = arr[i];
				*index = i;
				*sum = sum1;

			}

		}
	}
	return 0;
}

void exercise2()

{
	int i, indexnum;
	PRODUCT arr[N] =
	{
		{"socks",   "red",  9.5,33,42},
		{"trousers",   "green",  200.0,55,40},
		{"short",   "brown",  56.5,77,52},
		{"pajama",   "white",  80.4,11,46},
		{"cap",  "black",  17.2,66,40},
		{"trousers"  ,"violet",  150.0,55,52},
		{"socks",  "black",  12.5,33,52},
	};
	int special_size;
	int special_code;

	printf("Enter you size\n");
	scanf("%d", &special_size);
	indexnum = get_cheapest_by_size(arr, special_size);
	if (indexnum != -1)
	{
		printf("the cheapest product of yuor size\n");
		print_product_info(arr[indexnum]);
	}
	else
		printf("there is no product of yuor size\n");

	printf("enter code of your interestr");
	scanf("%d", &special_code);
	printf("\nthe information of product with your code are:\n");
	print_by_code(arr, special_code);

	printf("\nincrease prices:\n\n");
	increase_price(arr);

	for (i = 0; i < N; i++)
	{
		print_product_info(arr[i]);

	}
}
int get_cheapest_by_size(PRODUCT arr[N], int special_size)
{
	int indexnum;
	switch (special_size)
	{
	case 40:
		indexnum = 5;
		break;
	case 42:
		indexnum = 1;
		break;
	case 46:
		indexnum = 4;
		break;
	case 52:
		indexnum = 7;
		break;
	default:
		indexnum = -1;
		break;
	}
	return indexnum;
}

void increase_price(PRODUCT arr[N])
{
	int i;

	for (i = 0; i < N; i++)
	{
		if (arr[i].price < 50)
		{
			arr[i].price *= 1.2;
		}
	}
}

void print_product_info(PRODUCT mutzar)
{

	printf("Name: %s \n", mutzar.name);
	printf("Color: %s \n", mutzar.color);
	printf("Price: %f \n", mutzar.price);
	printf("Code: %d \n", mutzar.code);
	printf("Size: %d \n", mutzar.size);
}
void print_by_code(PRODUCT arr[N], int special_code)
{
	int i;
	for (i = 0; i < N; i++)
	{
		if (arr[i].code == special_code)
		{
			print_product_info(arr[i]);
		}
	}
}

void exercise3()
{
	Book arr[X] = { 0 };
	int i;
	for (i = 0; i < X; i++)
	{
		printf("\n# %d\n", i + 1);
		scanf_s("%c");

		printf("Enter the book name\n");
		gets_s(arr[i].book_name);

		printf("Enter the autor name\n");
		gets_s(arr[i].autor_name);

		printf("Enter the number of pages\n");
		scanf_s("%d", &arr[i].number_of_pages);

		printf("Enter year of publish\n");
		scanf_s("%d", &arr[i].year_of_Publish);

		printf("Enter catalog number\n");
		scanf_s("%d", &arr[i].catalog_name);

	}


	printf("info about max pages \n");
	max_pages(arr);

	int catalog_Number;
	printf("please enter catalog number: \n");
	scanf_s("%d", &catalog_Number);
	printf("info about  matching catalog number: \n");
	print_by_id(arr, catalog_Number);

	int yearofPublish;
	printf("please enter year of publish\n");
	scanf_s("%d", &yearofPublish);

	int count;
	count = year_of_publish(arr, yearofPublish);

	printf("the number of books in this year is: %d \n", count);

}
void max_pages(Book arr[X])
{
	int i, index = 0, max = arr[0].number_of_pages;

	for (i = 1; i < X; i++)
	{
		if (max < arr[i].number_of_pages)
		{
			index = i;
		}
	}
	printf("catalog number is: %d \n", arr[index].catalog_name);
	printf("the name of the autor is: %s \n", arr[index].autor_name);
	printf("the name of the book is: %s \n", arr[index].book_name);

}

void print_by_id(Book arr[X], int catalogNumber)
{
	int i;
	for (i = 0; i < X; i++)
	{
		if (arr[i].catalog_name == catalogNumber)
		{
			printf("the name of the autor is: %s \n", arr[i].autor_name);
			printf("the name of the book is: %s \n", arr[i].book_name);
			printf("the year of publish is: %d \n", arr[i].year_of_Publish);
			return;
		}
	}
}

int year_of_publish(Book arr[X], int YearOfPublish)
{
	int i, count = 0;
	for (i = 0; i < X; i++)
	{
		if (arr[i].year_of_Publish == YearOfPublish)
		{
			count++;
		}
	}
	return count;
}