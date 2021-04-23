#include<stdio.h>
#define INFINITY 9999
#define MAX 10

void dijkstra(int adjMat[MAX][MAX],int numVert,int startnode){
 
	int cost[MAX][MAX],distance[MAX],pred[MAX];
	int visited[MAX],count,minDistance,nextnode;
	//pred[] stores the predecessor of each node
	//count gives the number of nodes seen so far

	//create the cost matrix
	for(int i=0;i<numVert;i++){
        for(int j=0;j<numVert;j++){
            if(adjMat[i][j]==0){
                cost[i][j]=INFINITY;
            }
			else{
                cost[i][j]=adjMat[i][j];
            }
        }
    }

	//initialize pred[],distance[] and visited[]
	for(int i=0;i<numVert;i++){
		distance[i]=cost[startnode][i];
		pred[i]=startnode;
		visited[i]=0;
	}
	
	distance[startnode]=0;
	visited[startnode]=1;
	count=1;
	
	while(count<numVert-1){
		minDistance=INFINITY;
		
		//nextnode gives the node at minimum distance
		for(int i=0;i<numVert;i++){
            if(distance[i]<minDistance&&!visited[i]){
				minDistance=distance[i];
				nextnode=i;
			}
        }
			
		//check if a better path exists through nextnode			
		visited[nextnode]=1;
		for(int i=0;i<numVert;i++){
            if(!visited[i]){
                if(minDistance+cost[nextnode][i]<distance[i]){
		    		distance[i]=minDistance+cost[nextnode][i];
					pred[i]=nextnode;
				}
            }
        }			
		count++;
	}
 
	//print the path and distance of each node
	for(int i=0;i<numVert;i++){
        if(i!=startnode){
			printf("\nDistance of Node%d = %d",i,distance[i]);
			printf("\nPath: %d",i);
			int j=i;
			do{
				j=pred[j];
				printf(" <- %d",j);
			}while(j!=startnode);
            printf("\n");
	    }
    }
		
}
 
int main()
{
	int adjMat[MAX][MAX],numVert;
	printf("\nEnter no. of vertices:");
	scanf("%d",&numVert);
	printf("\nEnter the adjacency matrix:\n");
	
	for(int i=0;i<numVert;i++){
        for(int j=0;j<numVert;j++){
            scanf("%d",&adjMat[i][j]);
        }
    }
	
	printf("\nEnter the starting node:");
    int startNode;
	scanf("%d",&startNode);

	dijkstra(adjMat,numVert,startNode);
    /*
                 0
              /     \
           3 /       \ 1
            /         \
            1          2
            |        / |
          6 |    /     | 1
            |/         |
            3----------4
                 2
    */
}          

