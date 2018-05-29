#include <stdio.h>

/*
	Lab Assignment 2:

	In this lab, you will implement your own dynamic memory allocator (heap manager) in C.
	We will use the simple (but somehwat inefficient) free list system of heap allocation.
	You will demonstrate how to use your allocator to allocate dynamic memory for a variety
	of C types.

*/

// memory block
struct Block 
{
	int block_size;				// number of bytes in the data section
	struct Block *next_block; 	// pointer to the next block
};

// overhead size
const int struct_SIZE = sizeof(struct Block);

// size of a void pointer
const int VP_SIZE = sizeof(void*);

// will always point to the first free block in the free list
struct Block *free_head;

// initialize buffer
void my_initialize_heap (int size)
{
	free_head = malloc(size);

	free_head->block_size = size - struct_SIZE; 
	free_head->next_block = NULL;
}

// rounding up memory size
int roundUp(int numToRound)
{
    int remainder = numToRound % VP_SIZE;

    if (remainder == 0)
        return numToRound;

    return numToRound + VP_SIZE - remainder;
}

// fills an allocation request and returns a pointer to the data portion of the block
void* my_alloc (int size)
{
	struct Block *p = free_head; // free_head iterator
	struct Block *next_block;
	//struct Block *previous_block;
	struct Block *new_block;

	int desired_size = roundUp(size + struct_SIZE);

	while (p)
	{
		if (p->block_size >= desired_size)
		{
			int excess = p->block_size - desired_size;

			// Check if the excess memory is big enough for a new block
			if (excess > struct_SIZE)
			{
				int insert_location = p->block_size - desired_size;

				// Insert new block
				new_block = (struct Block *)((char *)(p + 1) + excess);
				new_block->block_size = size;
				new_block->next_block = NULL;

				p = p->next_block;

				// return pointer to data portion
				return (void*)(new_block + 1);
			}
			else
			{
				p = p->next_block;

				return (void*)(p + 1);
			}

		}
		else if (p->block_size < desired_size)
		{
			p = p->next_block;
		}
		else
		{
			return NULL;
		}
	}
}

void my_free(void *data)
{ 
	struct Block *temp = ((struct Block *)data - 1);
	temp->next_block = free_head;
	free_head = temp;
}

int main ()
{
	/*
	int n;
	printf("Enter a positive integer n:\n");
    scanf("%d", &n);

	my_initialize_heap(sizeof(int)*n);
	*/

	my_initialize_heap(100);

	int *p = my_alloc(sizeof(int));
	printf( "%p\n", p);
	my_free(p);

	int *q = my_alloc(sizeof(int));
	printf("%p\n", q);

	return 0;
}
