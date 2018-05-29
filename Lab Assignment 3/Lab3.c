#include <stdio.h>

int type;
/*
	type = 1 (int)
	type = 2 (float)
	type = 3 (char)
	type = 4 (string)
	type = 5 (struct)
*/

typedef struct Person
{
	char* name;
	int age;

} Person;

// Print elements in an array
void printArray(void* arr, int size, int type)
{
	if (type == 1) // int
	{
		for (int i = 0; i < size; i++)
    		printf("%d ", *((int*)arr + i));
	}
	else if (type == 2) // float
	{
		for (int i = 0; i < size; i++)
    		printf("%.2f ", *((float*)arr + i));
	}
	else if (type == 3) // char
	{
		for (int i = 0; i < size; i++)
    		printf("%c ", *((char*)arr + i));
	}
	else if (type == 4) // string
	{	
   		printf("%s", (char*)arr);
	}
	else if (type == 5) // struct
	{
		Person* temp = (Person*)arr;

		for (int i = 0; i < size; i++)
		{
			printf("%s-%d ", temp->name, temp->age);
			temp = ((Person*)temp + 1);

			if (i != size - 1)
				printf(" ");
		}
	}
}

// Compare function for passing in to built-in function 'qsort'
int cmpfunc (const void* a, const void* b)
{
	if (type == 1) // int
	{
		return ((*(int*)a) - (*(int*)b));
	}
	else if (type == 2) // float
	{
		return ((*(float*)a) - (*(float*)b));
	}
	else if (type == 3) // char
	{
		return ((*(char*)a) - (*(char*)b));
	}
	else if (type == 4) // string
	{
		return strcmp((*(char**)a) , (*(char**)b));
	}
	else if (type == 5) // struct
	{
		Person* temp_a = (Person*)a;
		Person* temp_b = (Person*)b;

		// Sort by name first then age
		if(strcmp(temp_a->name, temp_b->name) == 0)
			return (temp_a->age - temp_b->age);

		return strcmp(temp_a->name, temp_b->name);

		/*
		// Sort by age first then name
		if((temp_a->age - temp_b->age) == 0)
			return (strcmp(temp_a->name, temp_b->name);

		return (temp_a->age - temp_b->age);
		*/
	}

	if(type != 5)
		printf("\n\n");
}

int main()
{
	int arr_size;

	printf("\n");

	// Sorting array of integers
	type = 1;
	int arr_int[] = {4, 65, 2, -31, 0, 99, 2, 83, 782};
	arr_size = sizeof(arr_int) / sizeof(arr_int[0]);
	qsort(arr_int, arr_size, sizeof(int), cmpfunc);
	printArray(arr_int, arr_size, type);
	printf("\n\n");

	// Sorting array of floating point values
	type = 2;
	float arr_float[] = {645.32, 37.40, 76.30, 5.40, -34.23, 1.11, -34.94, 23.37, 635.46, -876.22, 467.73, 62.26};
	arr_size = sizeof(arr_float) / sizeof(arr_float[0]);
	qsort(arr_float, arr_size, sizeof(float), cmpfunc);
	printArray(arr_float, arr_size, type);
	printf("\n\n");

	// Sorting array of characters
	type = 3;
	char arr_char[] = {'z', 'y', 'a', 't', 'p', 'q', 'l', 'k'};
	arr_size = sizeof(arr_char) / sizeof(arr_char[0]);
	qsort(arr_char, arr_size, sizeof(char), cmpfunc);
	printArray(arr_char, arr_size, type);
	printf("\n\n");

	// Sorting array of strings
	type = 4;
	char* arr_string[] = {"apple", "zebra", "turtle", "yellow", "quest", "buffalo", "elephant"};
	arr_size = sizeof(arr_string) / sizeof(arr_string[0]);
	qsort(arr_string, arr_size, sizeof(char*), cmpfunc);
	for (int i = 0; i < arr_size; i++)
	{
		int string_length = strlen(arr_string[i]) + 1;
		printArray(arr_string[i], string_length, type);
		
		if(i != arr_size-1)
			printf(" ");
	}
	printf("\n\n");

	// Sorting array of structures
	type = 5;
	Person arr_struct[] = {[0].name = "Hal", [0].age = 20,
						   [1].name = "Susann",[1].age = 31,
						   [2].name = "Dwight",[2].age = 19,
						   [3].name = "Kassandra",[3].age = 21,
						   [4].name = "Lawrence",[4].age = 25,
						   [5].name = "Cindy",[5].age = 22,
						   [6].name = "Cory",[6].age = 27,
						   [7].name = "Mac",[7].age = 19,
						   [8].name = "Romana",[8].age = 27,
						   [9].name = "Doretha",[9].age = 32,
						   [10].name = "Danna",[10].age = 20,
						   [11].name = "Zara",[11].age = 23,
						   [12].name = "Rosalyn",[12].age = 26,
						   [13].name = "Risa",[13].age = 24,
						   [14].name = "Benny",[14].age = 28,
						   [15].name = "Juan",[15].age = 33,
						   [16].name = "Natalie",[16].age = 25};
	arr_size = sizeof(arr_struct) / sizeof(arr_struct[0]);
	qsort(arr_struct, arr_size, sizeof(Person), cmpfunc);
	printArray(arr_struct, arr_size, type);
	printf("\n");

    return 0;
}