#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#define MAX 100
#define isLetter(a)  ((((a)>='a')&&((a)<='z')) || (((a)>='A')&&((a)<='Z')))
#define LENGTH(a)  (sizeof(a)/sizeof(a[0]))
typedef struct{
	char RT;
	char PC;
}Vexs;
// 顶点类型
typedef struct
{
	Vexs vexs[MAX];       // 顶点集合
	int vexRT;           // 路由器数
	int vexPC;           //PC数 
	int edgnum;           // 边数
	int matrix[MAX][MAX]; // 邻接矩阵
}Graph, *PGraph;
/*
* 返回ch在matrix矩阵中的位置
*/
static int get_position(Graph g, char ch)
{
	int i;
	for (i = 0; i<g.vexRT; i++){ 
		if (g.vexs[i].RT == ch)
			return i;
	}
	for (i = 0; i<g.vexPC; i++){ 
		if (g.vexs[i].PC == ch)
			return i;
	} 
	return -1;
}
/*
* 读取一个输入字符
*/
static char read_char()
{
	char ch;
	do {
		ch = getchar();
	} while (!isLetter(ch));
	return ch;
}
Graph* create_graph()
{
	char c1, c2;
	int vRT,vPC, e;
	int i, p1, p2;
	Graph* pG;
	// 输入"顶点数"和"边数"
	printf("路由器数 PC数 线路数: ");
	scanf("%d %d %d", &vRT,&vPC,&e);
	if ((pG = (Graph*)malloc(sizeof(Graph))) == NULL)
		return NULL;
	memset(pG, 0, sizeof(Graph));
	//memset初始化 
	pG->vexRT = vRT;
	pG->vexPC = vPC;
	pG->edgnum = e;
	// 初始化"顶点"
	printf("路由器列表："); //A B C ...
	for (i = 0; i < pG->vexRT; i++)
	{
		pG->vexs[i].RT= read_char();
	}
	printf("PC机列表：");// R S T ...
	for (i = 0; i < pG->vexPC; i++)
	{
		pG->vexs[i].PC= read_char();
	}
	// 初始化"边"
	printf("线路："); //AB\nCD\n...
	for (i = 0; i < pG->edgnum; i++)
	{
		// 读取边的起始顶点和结束顶点
		c1 = read_char();
		c2 = read_char();
		p1 = get_position(*pG, c1);
		p2 = get_position(*pG, c2);
		if (p1 == -1 || p2 == -1)
		{
			printf("错误的输入\n");
			free(pG);
			return NULL;
		}
		pG->matrix[p1][p2 + pG -> vexRT] = 1;
	}
	return pG;
}
/*
* 打印矩阵
*/
void print_graph(Graph G)
{
	int i, j;
 
	printf("矩阵:\n");
	for (i = 0; i < G.vexRT+G.vexPC; i++)
	{
		for (j = 0; j < G.vexRT+G.vexPC; j++)
			printf("%d ", G.matrix[i][j]);
		printf("\n");
	}
}
int main()
{
	Graph* pG;
	pG = create_graph();
	print_graph(*pG);       // 打印图
}
