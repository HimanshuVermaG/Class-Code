#include <stdio.h>
#include <stdlib.h>
#define SIZE 40

struct Snode{
    int vertex;
    struct Snode* next;
};

struct Graph{
    int numVertex;
    struct Snode** adjVertexList;
    int* visited;
};

//Creating A Node
struct Snode* Enternode(int data){
    struct Snode* newnode = malloc(sizeof(struct Snode));
    newnode -> vertex = data;
    newnode -> next = NULL;
    return newnode;
}

//Creating A Graph
struct Graph* EnterGraph(int vertices){
    struct Graph* graph = malloc(sizeof(struct Graph));
    graph -> numVertex = vertices;
    graph -> adjVertexList = malloc(vertices * sizeof(struct Snode*));
    graph -> visited = malloc(vertices* sizeof(int));

    for(int i=0; i<vertices; i++){
        graph -> adjVertexList[i] = NULL;
        graph -> visited[i] = 0;
    }
    return graph;
}

//Adding Edge
void AddEdge(struct Graph* graph, int source, int destination){
    struct Snode* newnode = Enternode(destination);
    newnode -> next = graph -> adjVertexList[source];
    graph -> adjVertexList[source] = newnode;

    newnode = Enternode(source);
    newnode -> next = graph -> adjVertexList[destination];
    graph -> adjVertexList[destination] = newnode;
}

//Printing Graph
void printGraph(struct Graph* graph){
    for(int v = 1; v < graph -> numVertex; v++){
        struct Snode* temp = graph -> adjVertexList[v];
        printf("\nAdjacency List of Vertex %d\n",v);
        while(temp){
            printf("%d , ", temp -> vertex);
            temp = temp -> next;
        }
        printf("\n");
    }
}

//DepthFirstSearch Function
void DepthFirstSearch(struct Graph* graph, int startVertex){

   struct Snode* adjList = graph -> adjVertexList[startVertex];
   struct Snode* temp = adjList;

   graph -> visited[startVertex] = 1;
   printf("Visited %d\n",startVertex);

   while(temp){
       int adjvertex = temp -> vertex;
       if(graph -> visited[adjvertex] == 0){
           DepthFirstSearch(graph,adjvertex);
       }
       temp = temp -> next;
   }
}

int main(){
    struct Graph* graph = NULL;
    printf("\nHow many Vertices in Graph: ");
    int numVer;
    scanf("%d",&numVer);
    graph = EnterGraph(numVer+1);

    printf("\nEnter the Graph's Adjancecy Matrix: \n");
    int adMat[numVer][numVer];

    for(int i = 1; i <= numVer; i++){
        for(int j = 1; j <= numVer; j++){
            scanf("%d",&adMat[i][j]);
            if(adMat[i][j] == 1){
                if(adMat[j][i] == 1){
                  continue;
                }
                AddEdge(graph,i,j);
            }
        }
    }

    printGraph(graph);
    
    printf("\nEnter The Starting Vertex: ");
    int startVert;
    scanf("%d",&startVert);

    DepthFirstSearch(graph,startVert);
}