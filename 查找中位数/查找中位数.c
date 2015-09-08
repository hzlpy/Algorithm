#include <stdio.h>

int partition(int array[], int beg, int end)
{
	int i = beg;
	int j = end;
	int base = array[i];
	while (i < j) {
		while (i < j && array[j] >= base) {
			j--;
		}
		if (i < j) {
			array[i] = array[j];
			i++;
		}
		while (i < j && array[i] <= base) {
			i++;
		}
		if (i < j) {
			array[j] = array[i];
			j--;
		}
	}
	array[i] = base;
	return i;
}

int findMiddle(int array[], int beg, int end, int Kth)
{
	if (end - beg < 2) {
		return array[beg];
	}
	int i = partition(array, beg, end);
	if (i == Kth) {
		return array[i];
	} else if (i < Kth) {
		findMiddle(array, i+1, end, Kth);
	} else {
		findMiddle(array, beg, i-1, Kth);
	}
}

int main()
{
	int array[] = {1,2,3,4,2,1,1,2,5,3,11};
	int length = sizeof(array) / sizeof(array[0]);
	int beg = 0;
	int end = length - 1;
	printf("%d \n", findMiddle(array, beg, end, length/2));
}
