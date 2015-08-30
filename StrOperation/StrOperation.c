#include <stdio.h>
#include <assert.h>

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
//内存复制函数
void *memcpy(void *str1, const void *str2, size_t n);

char *memmove(char *dst, const char *src, size_t count);

void main()
{
	char dst[20]= "Hello,";
	char src[]= "World.";
	//printf("%s\n",strcpy(dst,src));
	//printf("字符串的长度为%d. \n",strlen(src));
	//printf("%s\n",strcpy(dst,src));
	//puts(strlwr(src));
	//puts(strupr(src));
	char d[10] = {0};
	char s[] = "How";
	//memcpy(d, s, 2);
	memmove(d, s, strlen(s)+1);
	puts(d);
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

void *memcpy(void *dst, const void *src, size_t count)
{
	assert((dst != NULL) && (src != NULL));
	char *temp = (char*)dst;
	const char *s = (char*)src;
	while (count --) {
		*temp++ = *s++;
	}
	return dst;
}

char *memmove(char *dst, const char *src, size_t count)
{
	assert((dst != NULL) && (src != NULL));
	char *ret = dst;
	if (dst < src || dst > src+count) {
		// 从开头开始拷贝
		while (count --) {
			*dst++ = *src++;
		}
	} else {
		// 从结尾开始拷贝
		dst = dst + count - 1;
		src = src + count - 1;
		while (count --) {
			*dst-- = *src--;
		}
	}
	return ret;
}