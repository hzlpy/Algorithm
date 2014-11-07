#include <stdio.h>
#include <string.h>
#define FLAG '1'

enum bool{
	false,true
};

//函数声明
void removeDuplicate(char *s);
void removeDuplicate2(char *s);
void print(char *s);
int main()
{
	char s[] = "abdcadgfh";//这里如果写成char *s = "abdcadgfh"，程序会报错
	removeDuplicate(s);
	print(s);
	return 0;
}
/*****************************************************************************
    *  @brief    : removeDuplicate 
    *  @author   : Zhangle
    *  @date     : 2014/11/6 8:44
    *  @version  : ver 1.0
    *  @inparam  : 
    *  @outparam :  
	*  @description: 利用两个循环，判断当前字符与后续字符是否会相同。若后续字符中存在与当前
					 字符相同的字符，则给该字符一个标记。在输出的时候，如果字符等于标记，则
					 不输出。
					 时间复杂度：O(n*n)
*****************************************************************************/
void removeDuplicate(char *s)
{
	//求s的长度
	int length = strlen(s);
	int i = 0;//循环变量
	int j = 0;
	for (i=0; i<length; ++i)
	{
		for (j=i+1; j<length; ++j)
		{
			if (s[i] == s[j])
			{
				s[j] = FLAG;//给重复的字符做一个标记
			}
		}
	}
}
/*****************************************************************************
    *  @brief    : removeDuplicate2 
    *  @author   : Zhangle
    *  @date     : 2014/11/7 19:28
    *  @version  : ver 1.0
    *  @inparam  : 
    *  @outparam :  
*****************************************************************************/
void removeDuplicate2(char *s)
{
	//定义一个大小为256的数组
	bool b[256];
	//初始化c
	int i;//循环标记
	int p = 0;
	//求s的长度
	int length = strlen(s);
	for (i=0; i<256; ++i)
	{
		b[i] = 0;
	}

	for (i=0; i<length; ++i)
	{
		if (!b[s[i]])
		{
			s[p++] = s[i];
			b[s[i]] = true;
		}
	}
}

/*****************************************************************************
    *  @brief    : print
    *  @author   : Zhangle
    *  @date     : 2014/11/6 8:47
    *  @version  : ver 1.0
    *  @inparam  : 
    *  @outparam :  
*****************************************************************************/
void print(char *s)
{
	int i;
	int length = strlen(s);
	for (i=0; i<length; ++i)
	{
		if (FLAG != s[i])
		{
			printf("%c",s[i]);
		}
	}
	printf("\n");
}

