#include<stdio.h>
#include<stdlib.h>

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

void merge(int *arr, int *left, int leftCount, int *right, int rightCount) 
{
	int i, j, k = 0;

	while (i < leftCount && j < rightCount) 
	{
		if (left[i] < right[j])
			arr[k++] = left[i++];
		else 
			arr[k++] = right[j++];
	}
	
	while (i < leftCount) 
		arr[k++] = left[i++];

	while (j < rightCount) 
		arr[k++] = right[j++];
}

// Mergesort
void msort(int *arr, int size)
{
	int mid, i, *left, *right;

	if (size < 2) 
		return; 

	mid = size / 2;

	left = (int*)malloc(mid * sizeof(int));
	right = (int*)malloc((size - mid) * sizeof(int));

	for (i = 0; i<mid; i++) 
		left[i] = arr[i];

	for (i = mid; i<size; i++) 
		right[i - mid] = arr[i];

	msort(left, mid);
	msort(right, size - mid);
	merge(arr, left, mid, right, size - mid);
	
	free(left);
	free(right);
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
	msort(arr, size-1);
	printArray(arr, size);

    return 0;
}