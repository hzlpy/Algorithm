#include <stdio.h>
#define LENGTH 10
/*声明函数*/
//初始化一个数组
void init(int *n, int length);
//交换
void swap(int *a, int *b);
//反转
void reverse(int* n, int length);
//打印数组
void print(int* n, int length);
int main(void)
{
	int n[LENGTH];
	init(n,LENGTH);		//初始化数组
	print(n,LENGTH);	//打印数组
	reverse(n,LENGTH);	//反转
	print(n,LENGTH);	//打印
	return 0;
}
/*****************************************************************************
    *  @brief    : init 初始化数组
    *  @author   : Zhangle
    *  @date     : 2014/11/4 9:11
    *  @version  : ver 1.0
    *  @inparam  : 
    *  @outparam :  
*****************************************************************************/
void init(int *n, int length)
{
	int begin = 0;
	for (begin = 0; begin<length; ++begin)
	{
		*n = begin;
		n++;
	}
}

/*****************************************************************************
    *  @brief    : swap 交换a,b
    *  @author   : Zhangle
    *  @date     : 2014/11/4 8:50
    *  @version  : ver 1.0
    *  @inparam  : 
    *  @outparam :  
*****************************************************************************/
void swap(int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

// void swap1(int a, int b)
// {
// 	int temp;
// 	temp = a;
// 	a = b;
// 	b = temp;
// }
// 
// void swap2(int *a, int *b)
// {
// 	int* temp;
// 	temp = a;
// 	a = b;
// 	b = temp;
// }

/*****************************************************************************
    *  @brief    : reverse 反转
    *  @author   : Zhangle
    *  @date     : 2014/11/4 9:06
    *  @version  : ver 1.0
    *  @inparam  : 
    *  @outparam :  
*****************************************************************************/
void reverse(int* n, int length)
{
	int begin = 0;
	int end = length-1;
	while (end > begin)//当end > begin时
	{
		//交换n[end]与n[begin]
		swap(&n[begin],&n[end]);
		end--;
		begin++;
	}
}
/*****************************************************************************
    *  @brief    : print 打印数组
    *  @author   : Zhangle
    *  @date     : 2014/11/4 9:07
    *  @version  : ver 1.0
    *  @inparam  : 
    *  @outparam :  
*****************************************************************************/
void print(int* n, int length)
{
	int i = 0;
// 	for (i=0; i<length; ++i)//for循环打印
// 	{
// 		printf("%d",n[i]);
// 	}

	for (i=0; i<length; ++i)//for循环打印
	{
		printf("%d",*n++);
	}
	printf("\n");
}