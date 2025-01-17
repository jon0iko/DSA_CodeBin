#include <bits/stdc++.h>
using namespace std;

int H[50];
int sizee = -1;


int parent(int i)
{
	return (i - 1) / 2;
}


int leftChild(int i)
{
	return ((2 * i) + 1);
}


int rightChild(int i)
{
	return ((2 * i) + 2);
}


void shiftUp(int i)
{
	while (i > 0 && H[parent(i)] < H[i]) {

		swap(H[parent(i)], H[i]);
		i = parent(i);
	}
}


void shiftDown(int i)
{
	int maxIndex = i;

	int l = leftChild(i);

	if (l <= sizee && H[l] > H[maxIndex]) {
		maxIndex = l;
	}

	int r = rightChild(i);

	if (r <= sizee && H[r] > H[maxIndex]) {
		maxIndex = r;
	}

	if (i != maxIndex) {
		swap(H[i], H[maxIndex]);
		shiftDown(maxIndex);
	}
}


void insert(int p)
{
	sizee = sizee + 1;
	H[sizee] = p;

	shiftUp(sizee);
}


int extractMax()
{
	int result = H[0];


	H[0] = H[sizee];
	sizee = sizee - 1;

	shiftDown(0);
	return result;
}


void changePriority(int i, int p)
{
	int oldp = H[i];
	H[i] = p;

	if (p > oldp) {
		shiftUp(i);
	}
	else {
		shiftDown(i);
	}
}


int getMax()
{
	return H[0];
}


void remove(int i)
{
	H[i] = getMax() + 1;
	shiftUp(i);
	extractMax();
}

int main()
{

	insert(45);
	insert(20);
	insert(14);
	insert(12);
	insert(31);
	insert(7);
	insert(11);
	insert(13);
	insert(7);

	int i = 0;

	cout << "Priority Queue : ";
	while (i <= sizee) {
		cout << H[i] << " ";
		i++;
	}

	cout << "\n";

	cout << "Node with maximum priority : "
		<< extractMax() << "\n";

	cout << "Priority queue after "
		<< "extracting maximum : ";
	int j = 0;
	while (j <= sizee) {
		cout << H[j] << " ";
		j++;
	}

	cout << "\n";


	changePriority(2, 15);
	cout << "Priority queue after "
		<< "priority change : ";
	int k = 0;
	while (k <= sizee) {
		cout << H[k] << " ";
		k++;
	}

	cout << "\n";

	remove(3);
	cout << "Priority queue after "
		<< "removing the element : ";
	int l = 0;
	while (l <= sizee) {
		cout << H[l] << " ";
		l++;
	}
	return 0;
}
