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
	int i = 0;
	int len = 0;
	//�����еĽڵ���Ŀ������ֵ
	int total = 10;
	//���屨���Ĵ�С������ֵ
	int num = 3;
	//��¼����������(1,2,,,num)
	int k = 1; 
	//��ǰ�ڵ��λ��
	int pos = 0;
	PNODE pHead,pTail,pNew,pNode,pTemp,pCurr;
	/*����һ��ѭ������*/
	pHead = (PNODE)malloc(sizeof(NODE));	//Ϊͷ�ڵ㶯̬�����ڴ�
	pTail = pHead;
	pTail->pNext = pHead;
	pTail->data = 1;
	/*�������м���ڵ�*/
	for ( i=1; i<=total; ++i)
	{
		/*����һ���½ڵ�*/
		pNew = (PNODE)malloc(sizeof(NODE));
		pNew->data = i;
		/*���½ڵ���뵽ѭ��������*/
		pTail->pNext = pNew;
		pNew->pNext = pHead;
		pTail = pNew;
	}

	pNode = pHead->pNext;
	while (pHead != pNode)
	{
		len ++;
		pNode = pNode->pNext;
	}
	//printf("len = %d\n",len);

	pNode = pHead->pNext;//�׽ڵ�
	pos = 1;
	/*��ʼ������ɾ����������3�Ľڵ�*/
	while (total >= 3) //���ܽڵ���С��3ʱ��ѭ����ֹ
	{
		k ++;
		pos ++;
		pTemp = pNode;
		pNode = pNode->pNext;

		if (pNode == pHead)
		{
			pNode = pNode->pNext;
		}
		if (k == num) //��������numʱ
		{
			/*ɾ����ǰ�ڵ㣬����¼����λ��*/
			pCurr = pNode; //��ǰ�ڵ㣬׼��ɾ��
			pTemp->pNext = pNode->pNext;
			printf("pos = %d\n",pCurr->data);
			total --;
			k = 1;
			free(pCurr);
		}
	}

	//free(pTemp);
	//����ɾ���ڵ���ѭ������
// 	pNode = pHead->pNext;
// 	while (pHead != pNode)
// 	{
// 		printf("%d, ",pNode->data);
// 		pNode = pNode->pNext;
// 	}
}