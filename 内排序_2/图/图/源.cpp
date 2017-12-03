#include <stdio.h>
#include<stdlib.h>
typedef struct ArcNode {	//弧结点的结构
	int adjvex; // 该弧所指向的顶点的!位置!注意只是位置,没有存放的数据data
	struct ArcNode *nextarc; // 指向下一条弧的指针
	int *info; // 该弧相关信息的指针（权值）
}ArcNode;
typedef struct VNode {	//顶点节点的结构
	int data; // 顶点信息
	ArcNode *firstarc; // 指向第一条依附该顶点的弧的指针
}VNode, AdjList[50];
typedef struct {	//图的邻接表结构定义
	AdjList vertices;	//存放顶点的数组
	int vexnum, arcnum; // 图的当前顶点数和弧数
}ALGraph;
int locateALG(ALGraph g, int v) {
	for (int i = 0;i < g.vexnum;i++) {
		if (g.vertices[i].data == v)
			return i;}return -1;}
int CreateADG(ALGraph &g) {
	int i, j, k, l;
	ArcNode *p;
	int v1, v2;
	int c;
	printf("请输入有向图的顶点数:");//顶点数
	scanf_s("%d", &g.vexnum);
	while (g.vexnum>50) {
		printf("\n请输入有向图的顶点数：");
		scanf_s("%d", &g.vexnum);}
	i = g.vexnum*(g.vexnum - 1);
	printf("请输入有向图的边数:");//边数
	scanf_s("%d", &g.arcnum);
	while (g.arcnum>i) {
		printf("\n请输入有向图的边数：");
		scanf_s("%d", &g.arcnum);}
	getchar();//输入顶点
	printf("请依次输入有向图的各个顶点:");
	for (i = 0;i<g.vexnum;i++) {//输入顶点信息
		scanf_s("%d", &c);
		l = locateALG(g, c);
		if (l >= 0) {
			printf("输入的顶点重复，请重新输入\n");
			i--;
			continue;}
		g.vertices[i].data = c;
		g.vertices[i].firstarc = NULL;//顶点指针首先初始化为null
}
	for (k = 0;k<g.arcnum;k++) {//输入边的信息
		printf("请输入第%d条弧的起点与终点(用逗号分隔)：", k + 1);
		scanf_s("%d,%d", &v1, &v2);	//输入一条边依附的起点序号和终点序号
		i = locateALG(g, v1);
		j = locateALG(g, v2);
		if (i<0 || j<0 || i == j || (g.vexnum<0)) {
			k--;
			continue;
		}
		p = (ArcNode*)malloc(sizeof(ArcNode));//建立结点
		if (!p) return -1;
		p->adjvex = j;//保存该弧所指向的终点位置
					  //单链表
		p->nextarc = g.vertices[i].firstarc;//顶点i的链表，保存该弧所指向的终点位置
		g.vertices[i].firstarc = p;//添加到最左边 

	}
	printf("有向图的邻接表创建成功\n\n");
	return 1;
}
int visit[50] = { 0 };
int flag = 0;
int dfs(ALGraph G, int vi, int vj) {

	int i = 0;
	ArcNode *p;

	for (i = 0;i < G.vexnum;i++) {
		if (G.vertices[i].data == vi) {
			visit[i] = 1;break;
		}
	}
	p = G.vertices[i].firstarc;
	//printf("%d,%d,%d", vi, G.vertices[p->adjvex].data, vj);
	while (p != NULL) {
		if (G.vertices[p->adjvex].data == vj) {
			flag = 1;printf("该路为通路\n"); return 1;
		}
		if (visit[p->adjvex] != 1) {
			dfs(G, G.vertices[p->adjvex].data, vj);if (flag == 1) return 1;
		}
		p = p->nextarc;
	}
	if (p == NULL) {
		return 0;
	}
}
void dfs_sc(ALGraph g) {
	int vi, vj, k = 0;
	printf("输入要查找的弧：");
	scanf_s("%d,%d", &vi, &vj);
	k = dfs(g, vi, vj);
	if (k != 1)
	{
		printf("该路不通");
	}
	scanf_s("%d", vi);
}
int main()
{
	ALGraph g;
	CreateADG(g);
	dfs_sc(g);
	return 0;
}