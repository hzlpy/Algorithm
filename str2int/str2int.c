#include <stdio.h>

#define MAX_INT 2147483647
#define MIN_INT -2147483648

int str2int(char* str)
{
    int ret = 0;
    int flag = 1;       // + / -
    // 
    if (NULL == str) 
    {
        return 0;
    }
    // 判断是否含有空格
    if (' ' == (*str)) 
    {
        str ++;
    }
    // 判断是否含有 + / -
    if (('-' == (*str)) || ('+' == (*str)))
    {
        str ++;
        if (('-' == (*str)))
        {
            flag = -1;
        }
    }
    // 判断是否到了字符串末尾 '\0'
    while ('\0' != (*str)) 
    {
        // 判断字符是否为数字
        int n = 0;
        if ('0' <= (*str) && '9' >= (*str))
        {
            n = (*str) - '0';
        }
        // 判断是否溢出
        if (flag > 0 && (ret > (MAX_INT / 10) || (ret == (MAX_INT / 10) && n > MAX_INT % 10)))
        {
            ret = MAX_INT;
            break;
        }
        else if (flag <0 && (n > (unsigned)MIN_INT / 10 || (n == (unsigned)MIN_INT / 10 && n > (unsigned)MIN_INT % 10)))
        {
            n = MIN_INT;
            break;
        }
        ret = ret * 10 + n;
        str ++;
    }
    ret = ret * flag;
    return ret;
}

int main()
{
    char* str = "214748365";
    int ret = str2int(str);
    printf("ret = %d \n", ret);
    return 0;
}