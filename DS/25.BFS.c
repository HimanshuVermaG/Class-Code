#include<stdio.h>
#include<stdlib.h>
#define SIZE 40

struct Queue{
    int items[SIZE];
    int front;
    int rear;
};

//Creating A Queue
struct Queue* EnterQueue(){
    struct Queue* queue = malloc(sizeof(struct Queue));
    queue -> front = -1;
    queue -> rear = -1;
    return queue;
}

//Bool Empty Func of Queue 
int isEmpty(struct Queue* queue){
    if(queue -> rear == -1){
        return 1;
    }
    return 0;
}

//Pushing Value in Queue
void enqueue(struct Queue* queue, int data){
    if(queue -> rear == SIZE -1 ){
        printf("!! ERROR: QUEUE ALREADY FULL !!");
    }
    else{
        if(queue -> front == -1){
            queue -> front = 0;
        }
        (queue -> rear)++;
        queue -> items[queue -> rear] = data;
    }
}

//Popping Value From Queue
int dequeue(struct Queue* queue){
    int waste;
    if(isEmpty(queue)){
        printf("!! ERROR: QUEUE IS ALREADY EMPTY !!");
        waste = -1;
    }
    else{
        waste = queue -> items[queue -> front];
        (queue -> front)++;
        if(queue -> front > queue -> rear){
            printf("Resetting Queue ");
            queue -> front = -1;
            queue -> rear = -1;
        }
    }
    return waste;
}

//Printing Queue
void printQueue(struct Queue* queue){
    if(isEmpty(queue)){
        printf("!! ERROR: QUEUE IS EMPTY !!");
        return;
    }
    printf("\nTHE QUEUE IS: ");
    for(int i = queue -> front; i <= queue -> rear; i++){
        printf("%d ", queue -> items[i]);
    }
}

struct Qnode{
    int vertex;
    struct Qnode* next;
};

//Createing A Node
struct Qnode* EnterNode(int data){
    struct Qnode* newnode = malloc(sizeof(struct Qnode));
    newnode -> vertex = data ;
    newnode -> next = NULL;
    return newnode;
}

struct Graph{
    int numVertex;
    struct Qnode** adjVertexList;
    int* visited;
};

//Creating A Graph
struct Graph* EnterGraph(int vertices){
    struct Graph* graph = malloc(sizeof(struct Graph));
    graph -> numVertex = vertices;
    graph -> adjVertexList = malloc(vertices * sizeof(struct Qnode*));
    graph -> visited = malloc(vertices * sizeof(int));

    for(int i = 0; i< vertices; i++){
        graph -> adjVertexList[i] = NULL;
        graph -> visited[i] = 0;
    }
    return graph;
}

//Adding Edge
void addEdge(struct Graph* graph, int source, int destination){
    struct Qnode* newNode = EnterNode(destination);
    newNode -> next = graph -> adjVertexList[source];
    graph -> adjVertexList[source] = newNode;

    newNode = EnterNode(source);
    newNode -> next = graph -> adjVertexList[destination];
    graph -> adjVertexList[destination] = newNode; 
}

//BreadthFirstSearch Function
void BreadthFirstSearch(struct Graph* graph, int startVertex){
    struct Queue* queue = EnterQueue();
    graph -> visited[startVertex] = 1;
    enqueue(queue, startVertex);

    while(!isEmpty(queue)){
        printQueue(queue);
        int currVertex = dequeue(queue);
        printf("\nVisited %d\n", currVertex);

        struct Qnode* temp = graph -> adjVertexList[currVertex];

        while(temp){
            int adjVertex = temp -> vertex;
            if(graph -> visited[adjVertex] == 0){
                graph -> visited[adjVertex] = 1;
                enqueue(queue, adjVertex);
            }
            temp = temp -> next;
        }
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
                addEdge(graph,i,j);
            }
        }
    }

    
    
    printf("\nEnter The Starting Vertex: ");
    int startVert;
    scanf("%d",&startVert);

    BreadthFirstSearch(graph,startVert);
}
