#include <iostream>
using namespace std;
#include<queue>
#include<unordered_map>
#include<vector>
vector<int>* bfs(int V, int adj [][1000],int v1,int v2)
{
    bool visited[V];
    for(int i=0;i<V;i++)
    {
        visited[i]=false;           
    }
    queue<int>q;
    q.push(v1);
    visited[v1]=true;
    bool done=false;
    
  unordered_map<int,int>parent;
    parent[v2]=v2;
    while(!q.empty() and done==false)
    {
        int temp=q.front();
          q.pop();
        for(int i=0;i<V;i++)
        {
            if(visited[i]==false and adj[temp][i]==1)
            { 
                q.push(i);
                parent[i]=temp;
                visited[i]=true;
                
            
            if(i==v2)
            {
                done=true;
                break;
            }
            }  
        } 
      
    }  
   if(done==false)
    
    {
        return nullptr ;
    }
    else
    {
        vector<int>* output = new vector<int>(); 
        int current=v2;
        output->push_back(v2);
        while(current!=v1)
    { 
       
             current=parent[current];
             output->push_back(current);
    
    }    return output;

        }
  
}
int main()
{
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
    int v1,v2;
    cin>>v1>>v2;
    
 vector<int>* output=bfs(V,adj,v1,v2);
    if(output!=nullptr)
    {
        for (int i=0;i<output->size();i++)
        {
            cout<<output->at(i)<<" ";
        }
    }
  return 0;
}
