#include <stdio.h>
#define LENGTH 10
/*��������*/
//��ʼ��һ������
void init(int *n, int length);
//����
void swap(int *a, int *b);
//��ת
void reverse(int* n, int length);
//��ӡ����
void print(int* n, int length);
int main(void)
{
	int n[LENGTH];
	init(n,LENGTH);		//��ʼ������
	print(n,LENGTH);	//��ӡ����
	reverse(n,LENGTH);	//��ת
	print(n,LENGTH);	//��ӡ
	return 0;
}
/*****************************************************************************
    *  @brief    : init ��ʼ������
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
    *  @brief    : swap ����a,b
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
    *  @brief    : reverse ��ת
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
	while (end > begin)//��end > beginʱ
	{
		//����n[end]��n[begin]
		swap(&n[begin],&n[end]);
		end--;
		begin++;
	}
}
/*****************************************************************************
    *  @brief    : print ��ӡ����
    *  @author   : Zhangle
    *  @date     : 2014/11/4 9:07
    *  @version  : ver 1.0
    *  @inparam  : 
    *  @outparam :  
*****************************************************************************/
void print(int* n, int length)
{
	int i = 0;
// 	for (i=0; i<length; ++i)//forѭ����ӡ
// 	{
// 		printf("%d",n[i]);
// 	}

	for (i=0; i<length; ++i)//forѭ����ӡ
	{
		printf("%d",*n++);
	}
	printf("\n");
}