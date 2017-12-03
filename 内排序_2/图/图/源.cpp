#include <stdio.h>
#include<stdlib.h>
typedef struct ArcNode {	//�����Ľṹ
	int adjvex; // �û���ָ��Ķ����!λ��!ע��ֻ��λ��,û�д�ŵ�����data
	struct ArcNode *nextarc; // ָ����һ������ָ��
	int *info; // �û������Ϣ��ָ�루Ȩֵ��
}ArcNode;
typedef struct VNode {	//����ڵ�Ľṹ
	int data; // ������Ϣ
	ArcNode *firstarc; // ָ���һ�������ö���Ļ���ָ��
}VNode, AdjList[50];
typedef struct {	//ͼ���ڽӱ�ṹ����
	AdjList vertices;	//��Ŷ��������
	int vexnum, arcnum; // ͼ�ĵ�ǰ�������ͻ���
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
	printf("����������ͼ�Ķ�����:");//������
	scanf_s("%d", &g.vexnum);
	while (g.vexnum>50) {
		printf("\n����������ͼ�Ķ�������");
		scanf_s("%d", &g.vexnum);}
	i = g.vexnum*(g.vexnum - 1);
	printf("����������ͼ�ı���:");//����
	scanf_s("%d", &g.arcnum);
	while (g.arcnum>i) {
		printf("\n����������ͼ�ı�����");
		scanf_s("%d", &g.arcnum);}
	getchar();//���붥��
	printf("��������������ͼ�ĸ�������:");
	for (i = 0;i<g.vexnum;i++) {//���붥����Ϣ
		scanf_s("%d", &c);
		l = locateALG(g, c);
		if (l >= 0) {
			printf("����Ķ����ظ�������������\n");
			i--;
			continue;}
		g.vertices[i].data = c;
		g.vertices[i].firstarc = NULL;//����ָ�����ȳ�ʼ��Ϊnull
}
	for (k = 0;k<g.arcnum;k++) {//����ߵ���Ϣ
		printf("�������%d������������յ�(�ö��ŷָ�)��", k + 1);
		scanf_s("%d,%d", &v1, &v2);	//����һ���������������ź��յ����
		i = locateALG(g, v1);
		j = locateALG(g, v2);
		if (i<0 || j<0 || i == j || (g.vexnum<0)) {
			k--;
			continue;
		}
		p = (ArcNode*)malloc(sizeof(ArcNode));//�������
		if (!p) return -1;
		p->adjvex = j;//����û���ָ����յ�λ��
					  //������
		p->nextarc = g.vertices[i].firstarc;//����i����������û���ָ����յ�λ��
		g.vertices[i].firstarc = p;//��ӵ������ 

	}
	printf("����ͼ���ڽӱ����ɹ�\n\n");
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
			flag = 1;printf("��·Ϊͨ·\n"); return 1;
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
	printf("����Ҫ���ҵĻ���");
	scanf_s("%d,%d", &vi, &vj);
	k = dfs(g, vi, vj);
	if (k != 1)
	{
		printf("��·��ͨ");
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