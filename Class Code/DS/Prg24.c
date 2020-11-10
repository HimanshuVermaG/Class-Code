// Q. Implement BFS
#include<stdio.h>
int a[20][20], q[20], visited[20], n, i, j, f = 0, r= -1;
void bfs(int v)
{
    for (int i = 1; i <= n; i++)
    {
        if (a[v][i] && !visited[i])
        {
            q[++r] = i;
        }
        if (f <= r)
        {
            visited[q[f]] = 1;
            bfs(q[f++]);
        }
        
    }
    
}
void main()
{
    int v;
    printf("\nEnter the number of vertices: ");
    scanf("%d",&n);

    for (int i = 1; i <= n; i++)
    {
        q[i]= 0;
        visited[i]=0;
    }
    
    printf("\nEnter graph data in matrix for: \n");
    for (int i = 1; i <=n; i++)
    {
        for (int j = 1; j <=n; j++)
        {
            printf("Enter the value of arr[%d][%d]:",i,j);
            scanf("%d",&a[i][j]);
        }
        
    }
    printf("\nEnter the starting vertex: ");
    scanf("%d",&v);
    bfs(v);
    
}
