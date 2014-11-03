#include <stdio.h>
#include <string.h>
#define LENGTH 10 //这里只支持两个9位数相加，最后一位要存放'\0'
//声明函数
//输入
void myInput(char* n);
//打印
void myPrint(char* n, int len);
void myPrintResult(char *n, int len);
//加法n3 = n1 + n2
void myAdd(char* n1, char* n2, char *n3);

int main()
{
	char n1[LENGTH];
	char n2[LENGTH];
	char n3[LENGTH+1];//考虑到n1+n2后最高位可能产生进位，故n3设为LENGTH+1位
	myInput(n1);
	myPrint(n1,LENGTH);
	myInput(n2);
	myPrint(n2,LENGTH);
	myAdd(n1,n2,n3);
	myPrintResult(n3,LENGTH+1);
	return 0;
}

//定义函数
void myInput(char* n)
{
	char s[LENGTH];
	int i,len;
	printf("Please input a big number: ");
	//把输入整型数字存放到字符数组中
	scanf("%s",s);
	//获取字符串的长度
	len = strlen(s);
	//把s中的字符转存到n中
	for (i=LENGTH-1; i>= 0; --i)
	{
		if (i>=LENGTH-len)
		{
			n[i] = s[i-(LENGTH-len)]-'0';
		}
		else
		{
			n[i] = 0;
		}
	}
}

void myPrint(char* n,int len)
{
	int i=0;
	for (i=0; i<len; ++i)
	{
		printf("%d",n[i]);
	}
	printf("\n");
}

void myAdd(char* n1, char* n2, char *n3)
{
	int i;
	int temp;
	//初始化n3
	for (i=0; i<LENGTH+1; ++i)
	{
		n3[i] = 0;
	}
	for (i=0; i<LENGTH; ++i)
	{
		n3[i+1] = n1[i] + n2[i];
	}
	//检查进位
	for (i=LENGTH; i>=1; --i)
	{
		temp = n3[i];	
		if (temp >= 10)
		{
			n3[i-1] = n3[i-1] + temp/10;
			n3[i] = n3[i] % 10;
		}
	}
}

void myPrintResult(char *n, int len)
{
	int i = 0;
	for (i=0; i<len; ++i)
	{
		if (0 != n[i])
		{
			break;
		}
	}
	while (i<len)
	{
		printf("%d",n[i]);
		i++;
	}
	printf("\n");
}