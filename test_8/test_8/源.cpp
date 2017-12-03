#include<iostream>
#include<fstream> 
using namespace std;
#define MaxVextexNum 30 /* ��󶥵���Ϊ30 */
#define INFINITY 32767    /* ����һ��Ȩֵ�����ֵ */       
typedef  struct {
	int vexs[MaxVextexNum];        /* ����� */
	int  arcs[MaxVextexNum][MaxVextexNum];  /* �ڽӾ��󣬼��߱� */
	int  n, e;                           /* �������ͱ��� */
}MGraph;         /* MGragh�����ڽӾ���洢��ͼ���� */

typedef struct {
	int adjvertex;  /* ���ѹ���õĲ����������Ķ���֮��Ȩֵ��С�Ķ��� */
	int lowcost;  /* ĳ�������ѹ���õĲ����������Ķ���֮ �����СȨֵ */
}ClosEdge[MaxVextexNum];  /* ��prim�㷨����С������ʱ�ĸ������� */
void CreatGraph(MGraph *G) /* ��������ͼG���ڽӾ���洢 */
{
	int i, j, k, w;
	ifstream in("input.txt");
	//   printf("�����붥�����ͱ���n e:") ;     
	// scanf("%d%d" ,&(G->n) ,&(G->e)) ;/* ���붥�����ͱ��� */ 
	in >> G->n >> G->e;
	// printf("\n���䶥���ַ���Ϣ(��%d��):", G->n);      
	for (i = 0; i<G->n; i++) {
		//	 scanf("%d" ,&(G->vexs[i]));  /* ���붥����Ϣ����������� */ 
		in >> G->vexs[i];
	}
	for (i = 0;i<G->n; i++)
		for (j = 0;j<G->n; j++) {
			if (i == j) {
				G->arcs[i][j] = 0;
			}
			else
				G->arcs[i][j] = INFINITY;

		}/* ��ʼ���ڽӾ��� 32767Ϊ�����*/
		 // printf("\n�������<Vi,Vj>��Ӧ�Ķ������(��%d��)���Լ�Ȩֵ:\n",G->e) ;   
	for (k = 0;k<G->e; k++) {
		// scanf("%d%d%d" ,&i ,&j ,&w);  /*����e���ߣ������ڽӾ��� */      
		in >> i >> j >> w;
		G->arcs[i][j] = w;
		G->arcs[j][i] = w;
	}
	printf("�����ڽӾ���Ϊ��32767Ϊ����󣩣�\n");
	for (i = 0; i<G->n;i++) {
		for (j = 0;j<G->n;j++)
			printf("%8d", G->arcs[i][j]);

		printf("\n");
	}
}
void MiniSpanTree_PRIM(MGraph G, int u, ClosEdge closedge) {/* �ӵ�u�������������ͼG����С����������С������������Ϣ���������closedge��*/
	int i, j, w, k, cost = 0;
	for (i = 0; i<G.n;i++) /* ���������ʼ�� */
		if (i != u) {
			closedge[i].adjvertex = u;
			closedge[i].lowcost = G.arcs[u][i];
		}
	closedge[u].lowcost = 0;  /* ��ʼ��U={u} */
	for (i = 0;i<G.n - 1; i++) /* ѡ�������G.n-1������ */ {
		w = INFINITY;
		for (j = 0;j<G.n; j++) /* �ڸ�������closedge��ѡ��Ȩֵ��С�Ķ���*/
			if (closedge[j].lowcost != 0 && closedge[j].lowcost<w) {
				w = closedge[j].lowcost;
				k = j;
			}    /* �������������һ������k */
		closedge[k].lowcost = 0;   /* ��k���㲢��U�� */
		for (j = 0; j<G.n; j++) /* �¶��㲢��U���޸ĸ�������*/
			if (G.arcs[k][j]<closedge[j].lowcost) {

				closedge[j].adjvertex = k;
				closedge[j].lowcost = G.arcs[k][j];
			}
	}
	printf("\n��С�������а����ĳ��м�ĵ�·:\n");
	for (i = 0; i<G.n;i++)  /*��ӡ��С�������ĸ�����*/
		if (i != u) {
			printf("%d->%d,%d\n", i, closedge[i].adjvertex, G.arcs[i][closedge[i].adjvertex]);
			cost = cost + G.arcs[i][closedge[i].adjvertex];
		}
	printf("\n��С�������Ĵ���Ϊ:%d\n\n", cost);
}
int main() {
	int t;

	MGraph G;
	ClosEdge closedge;
	CreatGraph(&G);
	printf("������Դ�㣺");
	scanf_s("%d", &t);
	MiniSpanTree_PRIM(G, t, closedge);
	system("pause");
	return 1;
}