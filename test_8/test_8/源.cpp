#include<iostream>
#include<fstream> 
using namespace std;
#define MaxVextexNum 30 /* 最大顶点数为30 */
#define INFINITY 32767    /* 定义一个权值的最大值 */       
typedef  struct {
	int vexs[MaxVextexNum];        /* 顶点表 */
	int  arcs[MaxVextexNum][MaxVextexNum];  /* 邻接矩阵，即边表 */
	int  n, e;                           /* 顶点数和边数 */
}MGraph;         /* MGragh是以邻接矩阵存储的图类型 */

typedef struct {
	int adjvertex;  /* 与已构造好的部分生成树的顶点之间权值最小的顶点 */
	int lowcost;  /* 某顶点与已构造好的部分生成树的顶点之 间的最小权值 */
}ClosEdge[MaxVextexNum];  /* 用prim算法求最小生成树时的辅助数组 */
void CreatGraph(MGraph *G) /* 建立有向图G的邻接矩阵存储 */
{
	int i, j, k, w;
	ifstream in("input.txt");
	//   printf("请输入顶点数和边数n e:") ;     
	// scanf("%d%d" ,&(G->n) ,&(G->e)) ;/* 输入顶点数和边数 */ 
	in >> G->n >> G->e;
	// printf("\n请输顶点字符信息(共%d个):", G->n);      
	for (i = 0; i<G->n; i++) {
		//	 scanf("%d" ,&(G->vexs[i]));  /* 输入顶点信息，建立顶点表 */ 
		in >> G->vexs[i];
	}
	for (i = 0;i<G->n; i++)
		for (j = 0;j<G->n; j++) {
			if (i == j) {
				G->arcs[i][j] = 0;
			}
			else
				G->arcs[i][j] = INFINITY;

		}/* 初始化邻接矩阵 32767为无穷大*/
		 // printf("\n请输入边<Vi,Vj>对应的顶点序号(共%d对)，以及权值:\n",G->e) ;   
	for (k = 0;k<G->e; k++) {
		// scanf("%d%d%d" ,&i ,&j ,&w);  /*输入e条边，建立邻接矩阵 */      
		in >> i >> j >> w;
		G->arcs[i][j] = w;
		G->arcs[j][i] = w;
	}
	printf("此连邻接矩阵为（32767为无穷大）：\n");
	for (i = 0; i<G->n;i++) {
		for (j = 0;j<G->n;j++)
			printf("%8d", G->arcs[i][j]);

		printf("\n");
	}
}
void MiniSpanTree_PRIM(MGraph G, int u, ClosEdge closedge) {/* 从第u个顶点出发构造图G的最小生成树，最小生成树顶点信息存放在数组closedge中*/
	int i, j, w, k, cost = 0;
	for (i = 0; i<G.n;i++) /* 辅助数组初始化 */
		if (i != u) {
			closedge[i].adjvertex = u;
			closedge[i].lowcost = G.arcs[u][i];
		}
	closedge[u].lowcost = 0;  /* 初始，U={u} */
	for (i = 0;i<G.n - 1; i++) /* 选择其余的G.n-1个顶点 */ {
		w = INFINITY;
		for (j = 0;j<G.n; j++) /* 在辅助数组closedge中选择权值最小的顶点*/
			if (closedge[j].lowcost != 0 && closedge[j].lowcost<w) {
				w = closedge[j].lowcost;
				k = j;
			}    /* 求出生成树的下一个顶点k */
		closedge[k].lowcost = 0;   /* 第k顶点并入U集 */
		for (j = 0; j<G.n; j++) /* 新顶点并入U后，修改辅助数组*/
			if (G.arcs[k][j]<closedge[j].lowcost) {

				closedge[j].adjvertex = k;
				closedge[j].lowcost = G.arcs[k][j];
			}
	}
	printf("\n最小生成树中包括的城市间的道路:\n");
	for (i = 0; i<G.n;i++)  /*打印最小生成树的各条边*/
		if (i != u) {
			printf("%d->%d,%d\n", i, closedge[i].adjvertex, G.arcs[i][closedge[i].adjvertex]);
			cost = cost + G.arcs[i][closedge[i].adjvertex];
		}
	printf("\n最小生成树的代价为:%d\n\n", cost);
}
int main() {
	int t;

	MGraph G;
	ClosEdge closedge;
	CreatGraph(&G);
	printf("请输入源点：");
	scanf_s("%d", &t);
	MiniSpanTree_PRIM(G, t, closedge);
	system("pause");
	return 1;
}