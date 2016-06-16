#include<iostream>
#include<cstdlib>
#include<queue>

using namespace std;

int low[50],discover[50],p[50],time=0,artpt[50]={0};
int count=0;

void dfs(int a[][50],int i,int v[],int n)
{
    v[i]=1;
    low[i]=discover[i]=++time;
    //cout<<i+1<<", ";
    for(int j=0;j<n;j++)
    {
        if(a[i][j])
        {
            if(!v[j])
            {
                p[j]=i;
                dfs(a,j,v,n);
                low[i]=min(low[i],low[j]);
            }
            else if(j != p[i])
            {
                low[i]=min(low[i],discover[j]);
            }
        }
    }
}

void Articulation(int a[][50],int n)
{
    for(int i=0;i<n;i++)
    {
        if(p[i]==-1)
        {
            for(int j=0;j<n;j++)
            {
                if(p[j]==i) count++;

            }
            if(count>1) artpt[i]=1;
        }
        else
        {
            for(int j=0;j<n;j++)
            {
                if(a[i][j])
                {
                    if(low[j] >= discover[i])
                        artpt[i]=1;
                }

            }
        }
    }
}

int main()
{
    int adjmat[50][50],visited[50]={0};
    for (int i = 0; i < 50; i++)
        for (int j = 0; j < 50; j++)
            adjmat[i][j] = 0;
    int n,m,a,b;
    cout<<"Enter no. of vertices:";
    cin>>n;
    for(int i=0;i<n;i++)
        p[i]=-1;
    cout<<"Enter number of edges:";
    cin>>m;
    for(int i=0;i<m;i++)
    {
        cout<<"Enter end points of the edge "<<i+1<<":";
        cin>>a>>b;
        adjmat[a-1][b-1]=1;
        adjmat[b-1][a-1]=1;
    }
    for(int i=0;i<n;i++)
    {
        if(visited[i]!=1)
           dfs(adjmat,i,visited,n);
    }
    Articulation(adjmat,n);
    cout<<"\nThe Articulation Points in the given graph is/are:\n\n";
    for(int i=0;i<n;i++)
    {
        if(artpt[i]==1)
            cout<<i+1<<"      ";
    }
    cout<<"\n\n";
}
