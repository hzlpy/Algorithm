//  [10/28/2014 Happy]
/************************************************************************/
/* ��˵������̫��ʷ/��ѧ��Լɪ��Josephus���й����µĹ��£���������ռ��������
�غ�40����̫ʿ����Լɪ��㵽һ�����У��ۼ�����������һȺ�˾���������ɱ��Ȼ��
˽��Լɪ����ĳ���һﲢ���޳ɣ�����Լɪ������ɱ��ʽ��41�����ų�ԲȦ���ɵ�1����
��ʼ������ÿ������3���˾ͱ�����ɱ��Ȼ������һ�����±�����ֱ�������˶���ɱ����Ϊ
ֹ��Լɪ���벻����ɱ���Ǹ��˷ֱ����ڵ�16�����31��λ�ã������ӹ����ⳡ������Ϸ��                                                                     */
/************************************************************************/
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
//����ṹ��
typedef struct Node
{
	struct Node* pNext;
	int data;
}NODE, *PNODE;

//��������
//��Josephus����
void solveJosephus();

int main(void)
{
	solveJosephus();
}

void solveJosephus()
{
	int i = 0; //ѭ����־
	int len = 0;
	int total = 10;//�����еĽڵ���Ŀ������ֵ
	int num = 3;//���屨���Ĵ�С������ֵ

	PNODE pHead;//ͷ�ڵ�
	PNODE pCurr;//��ǰ�ڵ�
	PNODE pPre;//ָ��pCurr��ǰ���ڵ�
	pHead = NULL;
	/*����һ��ѭ������*/
	for (i=1; i<=total; i++)
	{
		//��̬�����ڴ�
		pCurr = (PNODE)malloc(sizeof(NODE));
		//����ڴ��Ƿ����ɹ�
		if (NULL == pCurr)
		{
			printf("��̬�����ڴ�ʧ�ܣ��˳�����\n");
			exit(-1);
		}
		pCurr->data = i;

		if (NULL == pHead)
		{
			pHead = pCurr;
		} 
		else
		{
			pPre->pNext = pCurr;
		}
		pPre = pCurr;
	}
	pCurr->pNext = pHead;//β�ڵ�ĺ�̽ڵ�ΪpHead���γ�ѭ������
	
	pCurr = pHead;//��ͷ�ڵ�ָ��Ϊ��ǰ�ڵ�

	while (total >= 3)
	{
		for (i=1; i<num; ++i)
		{
			pPre = pCurr;
			pCurr = pCurr->pNext;
		}
		pPre->pNext = pCurr->pNext;//����ǰ�ڵ����һ���ڵ㸳ֵ����ǰ�ڵ�
		printf("delete number is : %d\n",pCurr->data);
		free(pCurr);//�ͷű�ɾ���ڵ���ڴ�
		total--;//�ڵ�������1
		pCurr = pPre->pNext;//ָ����ǰ�ڵ�
	}
}