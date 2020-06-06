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
// ��������
typedef struct
{
	Vexs vexs[MAX];       // ���㼯��
	int vexRT;           // ·������
	int vexPC;           //PC�� 
	int edgnum;           // ����
	int matrix[MAX][MAX]; // �ڽӾ���
}Graph, *PGraph;
/*
* ����ch��matrix�����е�λ��
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
* ��ȡһ�������ַ�
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
	// ����"������"��"����"
	printf("·������ PC�� ��·��: ");
	scanf("%d %d %d", &vRT,&vPC,&e);
	if ((pG = (Graph*)malloc(sizeof(Graph))) == NULL)
		return NULL;
	memset(pG, 0, sizeof(Graph));
	//memset��ʼ�� 
	pG->vexRT = vRT;
	pG->vexPC = vPC;
	pG->edgnum = e;
	// ��ʼ��"����"
	printf("·�����б�"); //A B C ...
	for (i = 0; i < pG->vexRT; i++)
	{
		pG->vexs[i].RT= read_char();
	}
	printf("PC���б�");// R S T ...
	for (i = 0; i < pG->vexPC; i++)
	{
		pG->vexs[i].PC= read_char();
	}
	// ��ʼ��"��"
	printf("��·��"); //AB\nCD\n...
	for (i = 0; i < pG->edgnum; i++)
	{
		// ��ȡ�ߵ���ʼ����ͽ�������
		c1 = read_char();
		c2 = read_char();
		p1 = get_position(*pG, c1);
		p2 = get_position(*pG, c2);
		if (p1 == -1 || p2 == -1)
		{
			printf("���������\n");
			free(pG);
			return NULL;
		}
		pG->matrix[p1][p2 + pG -> vexRT] = 1;
	}
	return pG;
}
/*
* ��ӡ����
*/
void print_graph(Graph G)
{
	int i, j;
 
	printf("����:\n");
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
	print_graph(*pG);       // ��ӡͼ
}
