

#include<stdio.h>
#include<cstdlib>
struct graph{
	int v;
	int e;
	int **adj;
};
typedef struct graph;
graph* create_adj_matrix_of_graph()
{
	graph *g;
	g=(graph *)malloc(sizeof(graph));
	if(!g)
	{
	printf("Memory error\n");
	return g;
	}
	printf("Enter a number of nodes and vertices \n");
	scanf("%d%d",&g->v,&g->e);
	g->adj=(int**)malloc(sizeof(int*)*(g->v*g->v));
	for(int i=0;i<g->v;i++)
	{
		for(int j=0;j<g->v;j++)
		{
			g->adj[i][j]=0;
		}
	}
		printf("Enter nodes number in a pair that connected in an edge\n");
		int u,v;
		for(int i=0;i<g->e;i++)
		{
			scanf("%d%d",&u,&v);
			g->adj[u][v]=1;
			g->adj[v][u]=1;
		}
		return g;
}
int main()
{
	 graph *G ;
	G =create_adj_matrix_of_graph();
	for(int i=0;i<G->v;i++)
	{
		for(int j=0;j<G->v;j++)
		{
			printf(" %d ",G->adj[i][j]);
		}
		printf("\n");
	}
}