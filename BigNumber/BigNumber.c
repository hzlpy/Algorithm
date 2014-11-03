#include <stdio.h>
#include <string.h>
#define LENGTH 10 //����ֻ֧������9λ����ӣ����һλҪ���'\0'
//��������
//����
void myInput(char* n);
//��ӡ
void myPrint(char* n, int len);
void myPrintResult(char *n, int len);
//�ӷ�n3 = n1 + n2
void myAdd(char* n1, char* n2, char *n3);

int main()
{
	char n1[LENGTH];
	char n2[LENGTH];
	char n3[LENGTH+1];//���ǵ�n1+n2�����λ���ܲ�����λ����n3��ΪLENGTH+1λ
	myInput(n1);
	myPrint(n1,LENGTH);
	myInput(n2);
	myPrint(n2,LENGTH);
	myAdd(n1,n2,n3);
	myPrintResult(n3,LENGTH+1);
	return 0;
}

//���庯��
void myInput(char* n)
{
	char s[LENGTH];
	int i,len;
	printf("Please input a big number: ");
	//�������������ִ�ŵ��ַ�������
	scanf("%s",s);
	//��ȡ�ַ����ĳ���
	len = strlen(s);
	//��s�е��ַ�ת�浽n��
	for (i=LENGTH-1; i>= 0; --i)
	{
		if (i>=LENGTH-len)
		{
			n[i] = s[i-(LENGTH-len)]-'0';
		}
		else
		{
			n[i] = 0;
		}
	}
}

void myPrint(char* n,int len)
{
	int i=0;
	for (i=0; i<len; ++i)
	{
		printf("%d",n[i]);
	}
	printf("\n");
}

void myAdd(char* n1, char* n2, char *n3)
{
	int i;
	int temp;
	//��ʼ��n3
	for (i=0; i<LENGTH+1; ++i)
	{
		n3[i] = 0;
	}
	for (i=0; i<LENGTH; ++i)
	{
		n3[i+1] = n1[i] + n2[i];
	}
	//����λ
	for (i=LENGTH; i>=1; --i)
	{
		temp = n3[i];	
		if (temp >= 10)
		{
			n3[i-1] = n3[i-1] + temp/10;
			n3[i] = n3[i] % 10;
		}
	}
}

void myPrintResult(char *n, int len)
{
	int i = 0;
	for (i=0; i<len; ++i)
	{
		if (0 != n[i])
		{
			break;
		}
	}
	while (i<len)
	{
		printf("%d",n[i]);
		i++;
	}
	printf("\n");
}