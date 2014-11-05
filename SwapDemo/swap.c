#include <stdio.h>
/************************************************************************/
/* C����ʵ��a,b�������ֽ���                                                */
/************************************************************************/
void swap(int a, int b);

void swap2(int* a, int* b);
int main(void)
{
	int a = 3;
	int b = 4;
	swap2(&a,&b);
	printf("a = %d, b = %d\n",a,b);
}
//���ַ�������ʵ�ֽ���
void swap(int a, int b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}
/*****************************************************************************
    *  @brief    : swap2 ����a,b
    *  @author   : Zhangle
    *  @date     : 2014/11/5 8:25
    *  @version  : ver 1.0
    *  @inparam  : 
    *  @outparam :  
*****************************************************************************/
void swap2(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}