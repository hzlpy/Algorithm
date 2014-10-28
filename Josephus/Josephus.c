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
	int i = 0;
	int len = 0;
	//定义中的节点数目，并赋值
	int total = 10;
	//定义报数的大小，并赋值
	int num = 3;
	//记录报数的数字(1,2,,,num)
	int k = 1; 
	//当前节点的位置
	int pos = 0;
	PNODE pHead,pTail,pNew,pNode,pTemp,pCurr;
	/*创建一个循环链表*/
	pHead = (PNODE)malloc(sizeof(NODE));	//为头节点动态分配内存
	pTail = pHead;
	pTail->pNext = pHead;
	pTail->data = 1;
	/*往链表中加入节点*/
	for ( i=1; i<=total; ++i)
	{
		/*产生一个新节点*/
		pNew = (PNODE)malloc(sizeof(NODE));
		pNew->data = i;
		/*将新节点插入到循环链表中*/
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

	pNode = pHead->pNext;//首节点
	pos = 1;
	/*开始报数，删除报到数字3的节点*/
	while (total >= 3) //当总节点数小于3时，循环终止
	{
		k ++;
		pos ++;
		pTemp = pNode;
		pNode = pNode->pNext;

		if (pNode == pHead)
		{
			pNode = pNode->pNext;
		}
		if (k == num) //当报数到num时
		{
			/*删掉当前节点，并记录它的位置*/
			pCurr = pNode; //当前节点，准备删除
			pTemp->pNext = pNode->pNext;
			printf("pos = %d\n",pCurr->data);
			total --;
			k = 1;
			free(pCurr);
		}
	}

	//free(pTemp);
	//遍历删除节点后的循环链表
// 	pNode = pHead->pNext;
// 	while (pHead != pNode)
// 	{
// 		printf("%d, ",pNode->data);
// 		pNode = pNode->pNext;
// 	}
}