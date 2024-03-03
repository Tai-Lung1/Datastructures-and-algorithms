#include<stdio.h>
#include<stdlib.h>
int st[10],a[10][10],v[10],u[10],q[10],n,top=-1,rear=-1,front=0;
void dfs(int s)
{
    int i;
    v[s]=1;
    st[++top]=s;
    for(i=1;i<=n;i++){
        if(a[s][i]==1 && v[i]==0){
            printf("Officer %d->Officier%d\n",s,i);
            dfs(i);
        }
    }
}
void bfs(int s){
    int m,i;
    for(i=1;i<=n;i++)
        u[i]=0;
    rear=front=0;
    u[s]=1;
    q[++rear]=s;
    printf("Reachable officers using BFSS method from given Officerr: %d are \n",s);
    while(front<=rear){
        m=q[front++];
        for(i=1;i<=n;i++)
        {
            if(a[m][i]==1 && u[i]==0){
                q[++rear]=i;
                printf("Officier %d\n",i);
                u[i]=1;
            }
        }
    }
}
int main(){
    int s,i,j,ch;
    while(1)
    {
        printf("1.Create a graph\n2.DFS treaversal method\n3.bfs\n4.exit");
        printf("Enter the choice\n");
        scanf("%d",&ch);
        switch(ch){
            case 1:printf("Enter the number of Officers\n");
            scanf("%d",&n);
            printf("Enter the adjacency Matrix");
            for(i=1;i<=n;i++){
                for(j=1;j<=n;j++)
                    scanf("%d",&a[i][j]);
            }
            break;
            case 2:printf("Depth First Search Traversal\n");
            printf("Enter Source Officier\n");
            scanf("%d",&s);
            for(i=1;i<=n;i++)
                v[i]=0;
            dfs(s);
            for(i=1;i<=n;i++){
                if(v[i]==0){
                    printf("Graph is not connected\n");
                    break;
                }
            }
            break;
            case 3:printf("Breadth First Search Traversal\n");
            printf("Enter Source Officier\n");
            scanf("%d",&s);
            bfs(s);
            for(i=1;i<=n;i++){
                if(u[i]==0){
                    printf("Graph is not connected\n");
                    break;
                }
            }
            break;
            case 4:exit(0);
            default:printf("invalid\n");
        }
    }
    return 0;
}