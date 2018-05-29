#include <stdio.h>
#include <stdlib.h>

int getPivot(int i, int j)
{
	int pivot = (i + j) / 2;
	return pivot;
}

void swap(int *x, int *y)
{
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

// Quicksort
void qsort(int *a, int first, int last)
{
	int key, i, j, k;

	if (first < last)
	{
		k = getPivot(first, last); // get pivot index
		swap(&a[first], &a[k]);    // move pivot to the front via swap function
		key = a[first];			   // set pivot value as the key
		
		// set cursor values
		i = first + 1;
		j = last;

		while (i <= j)
		{
			// If current element <= key, move up the list
			while ((i <= last) && (a[i] <= key))
				i++;

			// If current element > key, move down the list
			while ((j >= first) && (a[j] > key))
				j--;
			
			// If both indexes intersect, swap elemnts
			if (i < j)
				swap(&a[i], &a[j]);
		}

		// place pivot in its rightful spot in the list via swap function
		swap(&a[first], &a[j]);

		// recursively sort the list of elements to the left of the pivot
		qsort(a, first, j-1);

		// recursively sort the list of elements to the right of the pivot
		qsort(a, j+1, last);
	}
}

void merge(int *a, int first, int mid, int last)
{
	int l_size = (mid - last) + 1;
	int r_size = last - mid;

	int left[l_size], right[r_size];

	for (int i = 0; i < l_size; i++)
		left[i] = a[first + i];
	
	for (int i = 0; i < r_size; i++)
		right[i] = a[(mid+1) + i];

	int i = 0;
	int j = 0;
	int k = 1;

	while (i < l_size && j < r_size)
	{
		if (left[i] <= right[j])
		{
			a[k] = left[i];
			i++;
		}
		else if (left[i] > right[j])
		{
			a[k] = right[j];
			j++;
		}
		k++;
	}

	while (j < r_size)
	{
		a[k] = right[j];
		j++;
		k++;
	}
}

// Mergesort
void msort(int *a, int first, int last)
{
	if (first < last)
	{
		int mid = (first + (last - 1)) / 2;

		msort(a, first, mid);
		msort(a, mid+1, last);
		merge(a, first, mid, last);
	}
}

void printArray(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		if (i == (n-1))
			printf("%d", a[i]);
		else
			printf("%d, ", a[i]);
	}
	printf("\n");
}

int main()
{
	int size = 10;
	int arr[10] = {4, 65, 2, -31, 0, 99, 2, 83, 782, 1};

	//printf("Quick Sort\n");
	//qsort(arr, 0, size-1);
	//printArray(arr, size);

	printf("Merge Sort\n");
	msort(arr, 0, size-1);
	printArray(arr, size);

    return 0;
}