#include <iostream>
using namespace std;
#include<queue>
int solver(int adj[][1000],int v)
{   
    queue<int>q;    
    int count=0;
    bool visited[v];
    for(int i=0;i<v;i++)
    {
        visited[i]=false;
    }
    q.push(0);
    visited[0]=true;
    while(!q.empty())
    {
        int curr=q.front();
        q.pop();
        for(int i=0;i<v;i++)
        {
            if(visited[i]==false and adj[curr][i]==1)
            {
                q.push(i);
                visited[i]=true;
                
            }
        }
        bool flag=false;
        for(int i=0;i<v;i++)
        {
            if(visited[i]==false)
            {
                flag=true;
            }
        }
        while(q.empty() and flag==true)
        { count=count+1;
            
        for(int i=0;i<v;i++)
        {
            if(visited[i]==false)
            {   q.push(i);
                visited[i]=true;
                break;
            }
        }
        }
    }  count=count+1;
   
    
    
    return count;
    
    
}
int main()
{
     int v ,e;
    cin>>v>>e;
    int adj[1000][1000];
    for(int i=0;i<v;i++)
    {
        for(int j=0;j<v;j++)
        {
            adj[i][j]=0;
        }
    }
    
    int a,b;
    for(int i=0;i<e;i++)
    {
      cin>>a>>b;
        adj[a][b]=1;
        adj[b][a]=1;
    }
  int ans=solver(adj,v);
    cout<<ans;
    return 0;
}
