#include "stdio.h"

/*��������*/

//�ַ�����������
char *strcpy(char *dst, char *src);
//�ַ������Ⱥ��������Ȳ�������β��'\0'
int strlen(char *src);
//�ַ������Ӻ���
char *strcat(char *dst, char *src);
//�ַ���ת��ΪСд����
char *strlwr(char *src);
//�ַ���ת��Ϊ��д����
char *strupr(char *src);

void main()
{
	char dst[20]= "Hello,";
	char src[]= "World.";
	printf("%s\n",strcpy(dst,src));
	printf("�ַ����ĳ���Ϊ%d. \n",strlen(src));
	//printf("%s\n",strcpy(dst,src));
	puts(strlwr(src));
	puts(strupr(src));
}

/*****************************************************************************
    *  @brief    : strcpy �ַ�����������
    *  @author   : Zhangle
    *  @date     : 2014/10/27 8:16
    *  @version  : ver 1.0
    *  @inparam  : 
    *  @outparam :  
*****************************************************************************/
char *strcpy(char *dst, char *src)
{
	char *str = dst;
	while (*src != '\0') 
	{
		*dst = *src;
		dst ++;
		src ++;
	}
	*dst = '\0';
	return str;
}
/*****************************************************************************
    *  @brief    : strlen �ַ����ĳ���
    *  @author   : Zhangle
    *  @date     : 2014/10/27 8:26
    *  @version  : ver 1.0
    *  @inparam  : 
    *  @outparam :  
*****************************************************************************/
int strlen(char *src)
{
	int len = 0;
	while (*src != '\0')
	{
		len ++;
		src ++;
	}
	return len;
}

/*****************************************************************************
    *  @brief    : strcat concatenate two strings
    *  @author   : Zhangle
    *  @date     : 2014/10/27 8:07
    *  @version  : ver 1.0
    *  @inparam  : 
    *  @outparam :  
*****************************************************************************/
char *strcat(char *dst, char *src)
{
	char *str = dst;
	while(*dst!='\0') {
		dst++;		//�ҵ�dst�Ľ�β	
	}
	while(*src!='\0') {
		*dst = *src;
		dst ++;
		src ++;
	}
	*dst = '\0';
	return str;
}
/*****************************************************************************
    *  @brief    : strlwr �ַ���ת��ΪСд��ĸ
    *  @author   : Zhangle
    *  @date     : 2014/10/27 8:30
    *  @version  : ver 1.0
    *  @inparam  : 
    *  @outparam :  
*****************************************************************************/
char *strlwr(char *src)
{
	char *str = src;
	while (*src != '\0')
	{
		if (*src >= 'A' && *src <= 'Z')
		{
			*src = *src + 32;
		}
		src++;
	}
	return str;
}
/*****************************************************************************
    *  @brief    : strupr �ַ���ת��Ϊ��д��ĸ
    *  @author   : Zhangle
    *  @date     : 2014/10/27 8:36
    *  @version  : ver 1.0
    *  @inparam  : 
    *  @outparam :  
*****************************************************************************/
char *strupr(char *src)
{
	char *str = src;
	while (*src != '\0')
	{
		if (*src >= 'a' && *src <= 'z')
		{
			*src = *src - 32;
		}
		src++;
	}
	return str;
}