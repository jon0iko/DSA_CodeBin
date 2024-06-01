#include <bits/stdc++.h>
using namespace std;

struct Heap
{
	int *arr;
	int size;
	int capacity;
};

typedef struct Heap heap;

void heapify(heap *h, int index)
{
	int left = index * 2 + 1;
	int right = index * 2 + 2;
	int min = index;

	if (left >= h->size || left < 0)
		left = -1;
	if (right >= h->size || right < 0)
		right = -1;

	if (left != -1 && h->arr[left] < h->arr[index])
		min = left;
	if (right != -1 && h->arr[right] < h->arr[min])
		min = right;

	if (min != index)
	{
		int temp = h->arr[min];
		h->arr[min] = h->arr[index];
		h->arr[index] = temp;

		heapify(h, min);
	}
}

heap *createHeap(int capacity, int *nums)
{
	heap *h = (heap *)malloc(sizeof(heap));

	if (h == NULL)
	{
		printf("Memory error");
		return NULL;
	}
	h->size = 0;
	h->capacity = capacity;

	h->arr = (int *)malloc(capacity * sizeof(int));

	if (h->arr == NULL)
	{
		printf("Memory error");
		return NULL;
	}
	int i;
	for (i = 0; i < capacity; i++)
	{
		h->arr[i] = nums[i];
	}

	h->size = i;
	i = (h->size - 1 - 1) / 2;
	while (i >= 0)
	{
		heapify(h, i);
		i--;
	}
	return h;
}

void insertHelper(heap *h, int index)
{
	int parent = (index - 1) / 2;

	if (h->arr[parent] > h->arr[index] && parent >= 0)
	{

		int temp = h->arr[parent];
		h->arr[parent] = h->arr[index];
		h->arr[index] = temp;

		insertHelper(h, parent);
	}
}

int extractMin(heap *h)
{
	int deleteItem;

	if (h->size == 0)
	{
		printf("\nHeap id empty.");
		return -999;
	}

	deleteItem = h->arr[0];

	h->arr[0] = h->arr[h->size - 1];
	h->size--;

	heapify(h, 0);
	return deleteItem;
}

void insert(heap *h, int data)
{
	h->size++;
	cout << h->size << endl;
	h->arr[h->size-1] = data;
	insertHelper(h, h->size-1);
	//heapify(h, h->size-1);
}

void printHeap(heap *h)
{

	for (int i = 0; i < h->size; i++)
	{
		printf("%d ", h->arr[i]);
	}
	printf("\n");
}

int main()
{
	int arr[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
	heap *hp = createHeap(9, arr);

	printHeap(hp);

	insert(hp, -1);
	printHeap(hp);
	// extractMin(hp);
	// printHeap(hp);

	return 0;
}
