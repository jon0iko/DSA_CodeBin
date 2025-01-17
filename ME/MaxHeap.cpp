#include <malloc.h>
#include <stdio.h>

struct Heap {
	int* arr;
	int size;
	int capacity;
};

typedef struct Heap heap;

void maxHeapify(heap* h, int index)
{
	int left = index * 2 + 1;
	int right = index * 2 + 2;
	int max = index;

	if (left >= h->size || left < 0)
		left = -1;
	if (right >= h->size || right < 0)
		right = -1;


	if (left != -1 && h->arr[left] > h->arr[max])
		max = left;
	if (right != -1 && h->arr[right] > h->arr[max])
		max = right;

	if (max != index) {
		int temp = h->arr[max];
		h->arr[max] = h->arr[index];
		h->arr[index] = temp;


		maxHeapify(h, max);
	}
}

heap* createHeap(int capacity, int* nums)
{
	heap* h = (heap*)malloc(sizeof(heap));

	if (h == NULL) {
		printf("Memory error");
		return NULL;
	}
	h->size = 0;
	h->capacity = capacity;

	h->arr = (int*)malloc(capacity * sizeof(int));

	if (h->arr == NULL) {
		printf("Memory error");
		return NULL;
	}
	int i;
	for (i = 0; i < capacity; i++) {
		h->arr[i] = nums[i];
	}

	h->size = i;
	i = (h->size - 2) / 2;
	while (i >= 0) {
		maxHeapify(h, i);
		i--;
	}
	return h;
}

void insertHelper(heap* h, int index)
{


	int parent = (index - 1) / 2;

	if (h->arr[parent] < h->arr[index]) {

		int temp = h->arr[parent];
		h->arr[parent] = h->arr[index];
		h->arr[index] = temp;

		insertHelper(h, parent);
	}
}


int extractMax(heap* h)
{
	int deleteItem;

	if (h->size == 0) {
		printf("\nHeap id empty.");
		return -999;
	}

	deleteItem = h->arr[0];

	h->arr[0] = h->arr[h->size - 1];
	h->size--;


	maxHeapify(h, 0);
	return deleteItem;
}

void insert(heap* h, int data)
{

	if (h->size < h->capacity) {
		h->arr[h->size] = data;
		insertHelper(h, h->size);
		h->size++;
	}
}

void printHeap(heap* h)
{

	for (int i = 0; i < h->size; i++) {
		printf("%d ", h->arr[i]);
	}
	printf("\n");
}

int main()
{
	int arr[9] = {1,2,3,4,5,6,7,8,9};
	heap* hp = createHeap(9, arr);

	printHeap(hp);
	extractMax(hp);
	printHeap(hp);
}
