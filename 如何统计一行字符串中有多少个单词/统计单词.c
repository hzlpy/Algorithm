#include <stdio.h>
#include <string.h>

int wordCount(char *str)
{
	if (NULL == str) {
		return 0;
	}
	int count = 0;//记录单词的个数
	int word = 0;//0表示不是单词
	int index = -1;	//记录上一次空格的位置
	int i = 0, j = 0;
	while (((*str) == ' ')&&((*str) != '\0')) {
		str++;
	}
	while ((*str) != '\0') {
		if ((*str) == ' ') {//测试是空格
			word = 1;
		} else if (word == 1) {
			count ++;
			word = 0;
		}
		str++;
	}

	if (word == 0 && (*str) == '\0') {
		count ++;
	}
	return count;
}

int main()
{
	char *s = "  Happy birthday";
	printf("count = %d\n", wordCount(s));
}
