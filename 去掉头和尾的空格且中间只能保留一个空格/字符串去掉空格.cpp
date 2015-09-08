#include <stdio.h>

char* formatString(char *sourceString) {
	char *ret = sourceString;
	char *temp;
	while (*ret == ' ') {
		ret ++;
	}
	temp = ret;
	while (*temp != '\0') {
		if (*temp == ' ') {
			//判断下一个是否为空格
			if (*(temp+1) == ' ') { //如果为空格
				char *temp1 = temp;
				while (*(temp1) != '\0') {
					*temp1 = *(temp1+1);
					temp1++;
				}
				//temp++;
			} else {
				temp++;
			}
		} else {
			temp++;
		}
	}
	if (*temp == '\0') {
		if (*(temp-1) == ' ') {
			*(temp-1) = '\0';
		}
	}
	return ret;
}


/*
O（1）的空间复杂度和O（n）的时间复杂度，在源串上做处理。
*/
char* formatString2(char *sourceString) {
	char* res=sourceString;
	char* solve=sourceString;
	while(*solve==' ')   //去除左边的空格
		solve++;
	int has=0;
	while(*solve!='\0') 
	{
		if(*solve==' ')
		{
			if(has==0)
			{
				*res++=*solve++;
				has=1;
			}
			else
				solve++;
		}
		else{
			*res++=*solve++;
			has=0;
		}
	}
	if(*(res-1)==' ')     //去除右边空格  res指向的是下一个待处理的位置，因此判断的时候是判断res-1的位置
		*(--res)='\0';
	else
		*(res)='\0';
	return sourceString;
}  


void main()
{
	char str[] = "   Hello   world  .";
	printf("%s \n",formatString2(str));
}