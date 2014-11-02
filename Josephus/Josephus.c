//  [10/28/2014 Happy]
/************************************************************************/
/* 据说著名犹太历史/数学家约瑟夫（Josephus）有过以下的故事：在罗马人占领乔塔帕
特后，40个犹太士兵与约瑟夫躲到一个洞中，眼见脱逃无望，一群人决定集体自杀，然而
私下约瑟夫与某个家伙并不赞成，于是约瑟夫建议自杀方式，41个人排成圆圈，由第1个人
开始报数，每报数到3的人就必须自杀，然后由下一个重新报数，直到所有人都自杀身亡为
止。约瑟夫与不想自杀的那个人分别排在第16个与第31个位置，于是逃过了这场死亡游戏。                                                                     */
/************************************************************************/
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
//定义结构体
typedef struct Node
{
	struct Node* pNext;
	int data;
}NODE, *PNODE;

//声明函数
//解Josephus问题
void solveJosephus();

int main(void)
{
	solveJosephus();
}

void solveJosephus()
{
	int i = 0; //循环标志
	int len = 0;
	int total = 10;//定义中的节点数目，并赋值
	int num = 3;//定义报数的大小，并赋值

	PNODE pHead;//头节点
	PNODE pCurr;//当前节点
	PNODE pPre;//指向pCurr的前驱节点
	pHead = NULL;
	/*创建一个循环链表*/
	for (i=1; i<=total; i++)
	{
		//动态分配内存
		pCurr = (PNODE)malloc(sizeof(NODE));
		//检查内存是否分类成功
		if (NULL == pCurr)
		{
			printf("动态分配内存失败，退出程序\n");
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
	pCurr->pNext = pHead;//尾节点的后继节点为pHead，形成循环链表
	
	pCurr = pHead;//将头节点指定为当前节点

	while (total >= 3)
	{
		for (i=1; i<num; ++i)
		{
			pPre = pCurr;
			pCurr = pCurr->pNext;
		}
		pPre->pNext = pCurr->pNext;//将当前节点的下一个节点赋值给当前节点
		printf("delete number is : %d\n",pCurr->data);
		free(pCurr);//释放被删除节点的内存
		total--;//节点总数减1
		pCurr = pPre->pNext;//指定当前节点
	}
}