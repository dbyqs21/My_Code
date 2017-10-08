#include <stdlib.h>
#include <stdio.h>
#define MaxVertexNum 20

typedef struct GNode *ptrToGNode;
typedef int WeightType;
typedef struct VNode VNodeType;
typedef int Vertex;

struct VNode{
	int data;
	char name;
	int flag;
};

struct GNode{
	int Nv;   //������
	int Ne;   //����
	WeightType G[MaxVertexNum][MaxVertexNum];   // ����ͼ�ı�
	VNodeType V[MaxVertexNum];   //���涥�������
};

struct ENode {
	Vertex V1, V2;  //���������<V1,V2>
	WeightType Weight;   //Ȩ��
};

typedef  ENode *ptrToENode;
typedef ptrToENode Edge;
typedef ptrToGNode MGraph;   //���ڽӾ���洢ͼ

//����һ��ֻ��Nv�������ͼ
typedef int Vertex;
MGraph creatGraph(int NumVertex)
{
	MGraph Graph= (MGraph)malloc(sizeof(struct GNode));
	Graph->Nv = NumVertex;
	Graph->Ne = 0;

	for (int v = 0; v < NumVertex; ++v)
	{
		for (int w = 0; w < NumVertex; ++w)
			Graph->G[v][w] = INT_MAX;
		Graph->V[v].flag = 0;
	}
	return Graph;
}

void InsertEdge(MGraph Graph, Edge E)
{
	//����ͼ
	Graph->G[E->V1][E->V2] = E->Weight;
	//����ͼ
	Graph->G[E->V2][E->V1] = E->Weight;
}

MGraph buildGraph()
{
	MGraph Graph;
	Vertex v;
	printf("������ͼ�Ľڵ�����:");
	scanf_s("%d", &v);
	Graph = creatGraph(v);
	printf("������ͼ�ı���");
	scanf_s("%d", &(Graph->Ne));

	if (Graph->Ne)
	{
		 Edge E = (Edge)malloc(sizeof(struct ENode));
		 for (Vertex v = 0; v < Graph->Ne; ++v)
		 {
			 printf("�������%d���ߡ���ʽ�������� ������ Ȩֵ�������0��ʼ��ţ� ", v + 1);
			 scanf_s("%d %d %d", &(E->V1), &(E->V2), &(E->Weight));
			 InsertEdge(Graph, E);
		 }
		 free(E);
		 //����ڵ������ݵĻ�����Ҫ��������
		 for (Vertex v = 0; v < Graph->Nv; ++v)
		 {
			/* printf("�������%d���ڵ������", v + 1);
			 scanf_s("%d", &(Graph->V[v].data));*/
			 Graph->V[v].name = 'A' + v;
		 }
	}
	return Graph;
}

//������ʱ�־
void clearFlag(MGraph Graph)
{
	for (int k=0; k < Graph->Nv; ++k)
		Graph->V[k].flag = 0;
}

//ͼ��������ȱ���
void DFS(MGraph Graph,int start)
{

		if (Graph->V[start].flag == 0)
		{
			printf("%c ", Graph->V[start].name);
			Graph->V[start].flag = 1;
		}

		int k = 0;
		for (; k < Graph->Nv; ++k)
		{
			if (Graph->V[k].flag == 0 && Graph->G[start][k] < INT_MAX)
				DFS(Graph, k);
		}

		if (k == Graph->Nv)  //�ݹ����
			return;
}

//ͼ�Ĺ����������
void BFS(MGraph Graph, int start)
{
	if (Graph->V[start].flag == 0)
	{
		printf("%c ", Graph->V[start].name);
		Graph->V[start].flag = 1;
	}
	int outpoint = 0;
	int * queue = (int*)malloc(sizeof(int)*Graph->Nv);
	int flag = 0;
	for (int k = 0; k < Graph->Nv; ++k)   //�������д�start����һ��ֱ������нڵ�
	{
		if (Graph->V[k].flag == 0 && Graph->G[start][k] < INT_MAX)
		{
			printf("%c ", Graph->V[k].name);
			Graph->V[k].flag = 1;
			outpoint = 1;
			//��k���
			queue[flag++] = k;
		}
	}
	if (outpoint ==0)   //�ݹ����
		return;

	//����
	for (int k = 0; k < flag;++k)
	{
		BFS(Graph, queue[k]);
	}
	free(queue);
}


//��Ȩͼ�����·���㷨
void dijkstra(const MGraph Graph, int Collected[], int start)
{
	for (int k = 0; k < Graph->Nv; ++k)
	{
		Collected[k] = -1;
	}
	Collected[start] = 0;  //��ʼ����¼�����·�����㼯��

	//��������δ��¼��Collection�еĽڵ�V��dist[V]Ϊstart��V�����·�����ȡ�
	int * dist = (int*)malloc(sizeof(int)*Graph->Nv);
	
	while (true)
	{
		for (int k = 0; k < Graph->Nv; ++k)
		{
			dist[k] = INT_MAX;
		}
		int flag = 0;
		//�������δ��¼��Collection�еĵ㵽ԭ�����̾��룬·��ֻ����Collection�еĵ�
		for (int k = 0; k < Graph->Nv; ++k)  
		{
			if (Collected[k] == -1)   //kΪδ��¼�Ľڵ�
			{
				flag = 1;
				int * cnt = (int*)malloc(sizeof(int)*Graph->Nv);//���ڼ�¼Collected�еĵ㵽k֮��ľ���
				for (int i = 0; i < Graph->Nv; ++i) cnt[i] = INT_MAX;//��ʼ��cnt

				//���start��k֮������·���������dist[k]��
				for (int i = 0; i < Graph->Nv; ++i)
				{
					if (Collected[i] >= 0)  //i�ڵ���Collection��
					{
						cnt[i] = Collected[i]+Graph->G[k][i];
					}
				}

				//�ҵ���С��ֵ
				int min = 0;
				if (cnt[0] >0)
				     min = cnt[0];
				for (int i = 0; i < Graph->Nv; ++i)
				{
					if (cnt[i]>=0 && cnt[i] < min)
						min = cnt[i];
				}
				dist[k] = min;
				free(cnt);
			}
		}
		if (flag == 0) break;   //���ȫ���ڵ㶼������collected�����˳�

		//����dist����С��ֵ��������collected
		int min = dist[0];
		int j = 0;
		for (int i = 0; i < Graph->Nv; ++i)
		{
			if (dist[i] < min)
			{
				min = dist[i];
				j = i;   //����j�ڵ��·����С
			}
		}
		Collected[j] = min;
	}
	free(dist);
}



/***************���Գ���***************************************/
int main4()
{
	MGraph Graph = buildGraph();

	DFS(Graph, 1);
	clearFlag(Graph);
	printf("\n");
	BFS(Graph, 0);
	clearFlag(Graph);
	printf("\n");

	int *collected = (int*)malloc(sizeof(int)*Graph->Nv);
	dijkstra(Graph, collected, 0);
	for (int k = 0; k < Graph->Nv; ++k)
	{
		printf("%d ", collected[k]);
	}
	printf("\n");

	system("pause");
	return 0;
}