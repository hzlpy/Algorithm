#include <stdio.h>

int binarySearch(int *a, int n, int target);
int binarySearch2(int *a, int beg, int end, int target);

/*
 * @function    : binarySearch
 * @author   	: ZhangLe
 * @date     	: 2015/8/23 21:19
 * @version  	: ver 1.0
 * @inparam  	: void
 * @outparam    : void
 * @description : 非递归
 */
int binarySearch(int *a, int n, int target) {
	int beg = 0;
	int end = n - 1;
	int mid = 0;
	while (beg <= end) {
		mid = (beg + end) / 2;
		if (a[mid] < target) {
			beg = mid+1;
		} else if (a[mid] > target){
			end = mid - 1;
		} else {
			return mid;
		}
	}
	return -1;
}

/*
 * @function    : binarySearch2
 * @author   	: ZhangLe
 * @date     	: 2015/8/23 21:20
 * @version  	: ver 1.0
 * @inparam  	: void
 * @outparam    : void
 * @description : 递归
 */
int binarySearch2(int *a, int beg, int end, int target) {
	if (beg > end) {
		return -1;
	}
	int mid = (beg + end) / 2;
	if (a[mid] == target) {
		return mid;
	} else {
		if (a[mid] < target) {
			binarySearch2(a, mid+1, end, target);
		} else {
			binarySearch2(a, beg, mid-1, target);
		}
	}
}

int main()
{
	int a[] = {1,2,3,4,5,7,10,50};
	int len = 8;
	int tar = 50;

	printf("%d\n", binarySearch(a, len, tar));
	printf("%d\n", binarySearch2(a, 0, len-1, tar));
}
