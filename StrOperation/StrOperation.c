#include "stdio.h"

/*函数声明*/

//字符串拷贝函数
char *strcpy(char *dst, char *src);
//字符串长度函数，长度不包括结尾的'\0'
int strlen(char *src);
//字符串连接函数
char *strcat(char *dst, char *src);
//字符串转换为小写函数
char *strlwr(char *src);
//字符串转换为大写函数
char *strupr(char *src);

void main()
{
	char dst[20]= "Hello,";
	char src[]= "World.";
	printf("%s\n",strcpy(dst,src));
	printf("字符串的长度为%d. \n",strlen(src));
	//printf("%s\n",strcpy(dst,src));
	puts(strlwr(src));
	puts(strupr(src));
}

/*****************************************************************************
    *  @brief    : strcpy 字符串拷贝函数
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
    *  @brief    : strlen 字符串的长度
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
		dst++;		//找到dst的结尾	
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
    *  @brief    : strlwr 字符串转换为小写字母
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
    *  @brief    : strupr 字符串转换为大写字母
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