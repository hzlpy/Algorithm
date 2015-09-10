#include <stdio.h>
#include <string.h>

int partition(char *str, int length)
{
	int ret = 0;
	int beg = 0;
	int end = length-1;
	char temp;
	while (beg < end) {
		while (beg < end && str[end] == '1') {
			end --;
		}
		while (beg < end && str[beg] == '0') {
			beg ++;
		}
		if (str[beg] == '1' && str[end] == '0') { //交换条件
			temp = str[beg];
			str[beg] = str[end];
			str[end] = temp;
			ret ++;
			beg ++;
			end --;
		}
	}
	return ret;
}

void print(char array[], int length)
{
	int i=0;
	for (i=0; i<length; i++) {
		printf("%c ", array[i]);
	}
}

int main()
{
	char str[] = "110";
	int length = strlen(str);
	printf("str length is %d\n", length);
	printf("str size is %d\n", sizeof(str));
	printf("ret is %d\n", partition(str, length));
	print(str, length);
	return 0;
}