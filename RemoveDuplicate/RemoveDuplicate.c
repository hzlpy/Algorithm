#include <stdio.h>
#include <string.h>
#define FLAG '1'

enum bool{
	false,true
};

//��������
void removeDuplicate(char *s);
void removeDuplicate2(char *s);
void print(char *s);
int main()
{
	char s[] = "abdcadgfh";//�������д��char *s = "abdcadgfh"������ᱨ��
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
	*  @description: ��������ѭ�����жϵ�ǰ�ַ�������ַ��Ƿ����ͬ���������ַ��д����뵱ǰ
					 �ַ���ͬ���ַ���������ַ�һ����ǡ��������ʱ������ַ����ڱ�ǣ���
					 �������
					 ʱ�临�Ӷȣ�O(n*n)
*****************************************************************************/
void removeDuplicate(char *s)
{
	//��s�ĳ���
	int length = strlen(s);
	int i = 0;//ѭ������
	int j = 0;
	for (i=0; i<length; ++i)
	{
		for (j=i+1; j<length; ++j)
		{
			if (s[i] == s[j])
			{
				s[j] = FLAG;//���ظ����ַ���һ�����
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
	//����һ����СΪ256������
	bool b[256];
	//��ʼ��c
	int i;//ѭ�����
	int p = 0;
	//��s�ĳ���
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

