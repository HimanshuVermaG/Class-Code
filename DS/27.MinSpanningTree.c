#include<stdio.h>
#define MAX 30
int adjMat[MAX][MAX],numVert;

struct edge{
	int u,v,w;
};
 
struct edgelist{
	struct edge data[MAX];
	int numVert;
};
struct edgelist elist;
struct edgelist spanlist;

void sort(){
	int i,j;
	struct edge temp;
	for(i=1; i<elist.numVert; i++){
        for(j=0; j<elist.numVert-1; j++){
            if(elist.data[j].w > elist.data[j+1].w){
				temp = elist.data[j];
				elist.data[j] = elist.data[j+1];
				elist.data[j+1] = temp;
			}
        }
    }		
}

int find(int belongs[],int vertexno){
	return(belongs[vertexno]);
}

void union1(int belongs[],int c1,int c2){
	int i;
	for(i=0; i<numVert; i++){
        if(belongs[i] == c2){
            belongs[i] = c1;
        }
    }	
}

void kruskal(){
	int belongs[MAX],i,j,cno1,cno2;
	elist.numVert=0;
 
	for(i=1; i<numVert; i++){
        for(j=0; j<i; j++){
			if(adjMat[i][j] != 0){
				elist.data[elist.numVert].u = i;
				elist.data[elist.numVert].v = j;
				elist.data[elist.numVert].w = adjMat[i][j];
				elist.numVert++;
			}
		}
    }
	
	sort();
	for(i=0; i<numVert; i++){
        belongs[i]=i;
    }
		
	spanlist.numVert = 0;
	for(i=0; i<elist.numVert; i++){
		cno1 = find(belongs , elist.data[i].u);
		cno2 = find(belongs , elist.data[i].v);
		
		if(cno1 != cno2){
			spanlist.data[spanlist.numVert] = elist.data[i];
			spanlist.numVert = spanlist.numVert+1;
			union1(belongs,cno1,cno2);
		}
	}
}
 
void print(){
	int i,cost=0;
	printf("\nEdge\tNode Pair\tWeight");
	for(i=0; i<spanlist.numVert; i++){
		printf("\n %d\t%d ---- %d\t  %d",i+1,spanlist.data[i].u,spanlist.data[i].v,spanlist.data[i].w);
		cost = cost+spanlist.data[i].w;
	}
	printf("\n\nMinimum Cost of the spanning tree: %d\n",cost);
}
 
int main(){
	int total_cost;
	
	printf("\nEnter number of vertices:");
	scanf("%d",&numVert);
	
	printf("\nEnter the adjacency matrix:\n");
	for(int i=0; i<numVert; i++){
        for(int j=0; j<numVert; j++){
            scanf("%d",&adjMat[i][j]);
        }
    }

	kruskal();
	print();
}
 
