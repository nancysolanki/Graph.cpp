class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        
        // Indegree count vector
        vector<int>inedges(n,0);
        
        // result vector
        vector<int>result;
        
        int e_size = edges.size();
        
        // populate indegree count of all nodes from given edge list
        for(int i=0;i<e_size;i++)
            inedges[edges[i][1]]++;
        
        // push node in to result who has Indegree 0 as it can not be reached any way and so it must be the start node
        for(int i=0;i<n;i++)
            if(!inedges[i])result.push_back(i);
        
        return result;
    }
};
