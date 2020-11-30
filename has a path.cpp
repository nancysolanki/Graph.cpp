#include <iostream>
#include<queue>
using namespace std;

bool hasPath(int adj[][1000],int V,int a,int b)
{
   bool visited[V];
    for(int i=0;i<V;i++)
    {
        visited[i]=false;
    }
    queue<int>q;
    q.push(a);
   visited[a]=true;
    while(!q.empty())
    { 
        int temp=q.front();
    
          if(q.front()==b)
          {
              return true;
          }    
        q.pop();

      for(int i=0;i<V;i++)
      {
          if(visited[i]==false and adj[temp][i]==1)
          {
              q.push(i);
              visited[i]=true;
          }
       
      }
    }
    return false;
    
}



int main() {
    int V, E;
    cin >> V >> E;
     int adj[1000][1000];
    for(int i=0;i<V;i++)
    {
        for(int j=0;j<V;j++)
        {
            adj[i][j]=0;
        }
    }
    for(int i=0;i<E;i++)
    {
        int a,b;
        cin>>a>>b;
        adj[a][b]=1;
        adj[b][a]=1;

    }
    int a,b;
    cin>>a>>b;
    bool flag=hasPath(adj,V,a,b);
    if(flag==true)
        cout<<"true";
    else
        cout<<"false";

  return 0;
}

