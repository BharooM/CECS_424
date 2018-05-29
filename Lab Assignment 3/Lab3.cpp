#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

struct Person
{
	string name;
	int age;
};

// Print elements in an array (int, float, char, string)
template<class T>
void printArray(T arr[], int size)
{
	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";
}

// Print elements in an array (struct)
void printStruct(Person arr[], int size)
{
	for (int i = 0; i < size; i++)
		cout << (*((Person*)arr + i)).name << "-" << (*((Person*)arr + i)).age << " ";
}

// Compare function for sorting array of structures
int cmpfunc(Person const& a, Person const& b) 
{
	// Sort by name first then age
	if (a.name == b.name)
		return a.age < b.age;
	
	return a.name < b.name;

	/*
	// Sort by age first then name
	if (a.age == b.age)
		return a.name < b.name;

	return a.age < b.age;
	*/
}

int main()
{
	int arr_size;

	// Sorting array of integers
	int arr_int[] = { 4, 65, 2, -31, 0, 99, 2, 83, 782 };
	arr_size = sizeof(arr_int) / sizeof(arr_int[0]);
	sort(arr_int, arr_int + arr_size);
	printArray(arr_int, arr_size);
	cout << "\n\n";

	// Sorting array of floating point values
	float arr_float[] = { 645.32, 37.40, 76.30, 5.40, -34.23, 1.11, -34.94, 23.37, 635.46, -876.22, 467.73, 62.26 };
	arr_size = sizeof(arr_float) / sizeof(arr_float[0]);
	sort(arr_float, arr_float + arr_size);
	printArray(arr_float, arr_size);
	printf("\n\n");

	// Sorting array of characters
	char arr_char[] = { 'z', 'y', 'a', 't', 'p', 'q', 'l', 'k' };
	arr_size = sizeof(arr_char) / sizeof(arr_char[0]);
	sort(arr_char, arr_char + arr_size);
	printArray(arr_char, arr_size);
	printf("\n\n");

	// Sorting array of strings
	string arr_string[] = { "apple", "zebra", "turtle", "yellow", "quest", "buffalo", "elephant" };
	arr_size = sizeof(arr_string) / sizeof(arr_string[0]);
	sort(arr_string, arr_string + arr_size);
	printArray(arr_string, arr_size);
	printf("\n\n");

	// Sorting array of structures
	Person arr_struct[] = { {"Hal", 20},
							{"Susann", 31},
							{"Dwight", 19}, 
							{"Kassandra",21},
							{"Lawrence", 25},
							{"Cindy", 22},
							{"Cory", 27},
							{"Mac", 19},
							{"Romana", 27},
							{"Doretha", 32},
							{"Danna", 20},
							{"Zara", 23},
							{"Rosalyn", 26},
							{"Risa", 24},
							{"Benny", 28},
							{"Juan", 33},
							{"Natalie", 25} };
	arr_size = sizeof(arr_struct) / sizeof(arr_struct[0]);
	sort(arr_struct, arr_struct + arr_size, cmpfunc);
	printStruct(arr_struct, arr_size);
	printf("\n\n");

	return 0;
}
