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
	int Nv;   //顶点数
	int Ne;   //边数
	WeightType G[MaxVertexNum][MaxVertexNum];   // 保存图的边
	VNodeType V[MaxVertexNum];   //保存顶点的数据
};

struct ENode {
	Vertex V1, V2;  //保存有向边<V1,V2>
	WeightType Weight;   //权重
};

typedef  ENode *ptrToENode;
typedef ptrToENode Edge;
typedef ptrToGNode MGraph;   //以邻接矩阵存储图

//创建一个只有Nv个顶点的图
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
	//有向图
	Graph->G[E->V1][E->V2] = E->Weight;
	//无向图
	Graph->G[E->V2][E->V1] = E->Weight;
}

MGraph buildGraph()
{
	MGraph Graph;
	Vertex v;
	printf("请输入图的节点数量:");
	scanf_s("%d", &v);
	Graph = creatGraph(v);
	printf("请输入图的边数");
	scanf_s("%d", &(Graph->Ne));

	if (Graph->Ne)
	{
		 Edge E = (Edge)malloc(sizeof(struct ENode));
		 for (Vertex v = 0; v < Graph->Ne; ++v)
		 {
			 printf("请输入第%d条边。格式：顶点编号 顶点编号 权值（定点从0开始编号） ", v + 1);
			 scanf_s("%d %d %d", &(E->V1), &(E->V2), &(E->Weight));
			 InsertEdge(Graph, E);
		 }
		 free(E);
		 //如果节点有数据的话，还要读入数据
		 for (Vertex v = 0; v < Graph->Nv; ++v)
		 {
			/* printf("请输入第%d个节点的数据", v + 1);
			 scanf_s("%d", &(Graph->V[v].data));*/
			 Graph->V[v].name = 'A' + v;
		 }
	}
	return Graph;
}

//清除访问标志
void clearFlag(MGraph Graph)
{
	for (int k=0; k < Graph->Nv; ++k)
		Graph->V[k].flag = 0;
}

//图的深度优先遍历
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

		if (k == Graph->Nv)  //递归出口
			return;
}

//图的广度优先搜索
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
	for (int k = 0; k < Graph->Nv; ++k)   //访问所有从start可以一步直达的所有节点
	{
		if (Graph->V[k].flag == 0 && Graph->G[start][k] < INT_MAX)
		{
			printf("%c ", Graph->V[k].name);
			Graph->V[k].flag = 1;
			outpoint = 1;
			//将k入队
			queue[flag++] = k;
		}
	}
	if (outpoint ==0)   //递归出口
		return;

	//出队
	for (int k = 0; k < flag;++k)
	{
		BFS(Graph, queue[k]);
	}
	free(queue);
}


//有权图的最短路径算法
void dijkstra(const MGraph Graph, int Collected[], int start)
{
	for (int k = 0; k < Graph->Nv; ++k)
	{
		Collected[k] = -1;
	}
	Collected[start] = 0;  //初始化收录到最短路径顶点集合

	//对于任意未收录在Collection中的节点V，dist[V]为start到V的最短路径长度。
	int * dist = (int*)malloc(sizeof(int)*Graph->Nv);
	
	while (true)
	{
		for (int k = 0; k < Graph->Nv; ++k)
		{
			dist[k] = INT_MAX;
		}
		int flag = 0;
		//求出所有未收录到Collection中的点到原点的最短距离，路径只包含Collection中的点
		for (int k = 0; k < Graph->Nv; ++k)  
		{
			if (Collected[k] == -1)   //k为未收录的节点
			{
				flag = 1;
				int * cnt = (int*)malloc(sizeof(int)*Graph->Nv);//用于记录Collected中的点到k之间的距离
				for (int i = 0; i < Graph->Nv; ++i) cnt[i] = INT_MAX;//初始化cnt

				//求出start到k之间的最短路径，存放在dist[k]中
				for (int i = 0; i < Graph->Nv; ++i)
				{
					if (Collected[i] >= 0)  //i节点在Collection中
					{
						cnt[i] = Collected[i]+Graph->G[k][i];
					}
				}

				//找到最小的值
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
		if (flag == 0) break;   //如果全部节点都加入了collected，就退出

		//挑出dist中最小的值，并加入collected
		int min = dist[0];
		int j = 0;
		for (int i = 0; i < Graph->Nv; ++i)
		{
			if (dist[i] < min)
			{
				min = dist[i];
				j = i;   //经过j节点的路径最小
			}
		}
		Collected[j] = min;
	}
	free(dist);
}



/***************测试程序***************************************/
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