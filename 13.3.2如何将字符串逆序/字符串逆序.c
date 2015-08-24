#include <stdio.h>
#include <string.h>

void reverseStr(char *str)
{
	//定义两个指针，一个指向字符串的第一个字符，另一个指向最后一个字符('\0'之前)
	char *beg, *end;
	beg = end = str;
	//找到'\0'的位置
	while ((*end) != '\0') {
		end ++;
	}
	//回退一步，使end指向最后一个字符
	end --;
	//开始交换
	while (beg < end) {
		char t = (*beg);
		(*beg) = (*end);
		(*end) = t;
		beg ++;
		end --;
	}
}

int main()
{
	char s[] = "I am Happy";
	reverseStr(s);
	printf("%s\n", s);
}
