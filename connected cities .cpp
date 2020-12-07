
play_arrow

brightness_4
// C++ program for the above approach
 
#include <bits/stdc++.h>
using namespace std;
 
vector<int> parent, size;
 
// Utility function to find set of an
// element v using path compression
// technique
int find_set(int v)
{
    // If v is the parent
    if (v == parent[v])
        return v;
 
    // Otherwsie, recursively
    // find its parent
    return parent[v]
           = find_set(parent[v]);
}
 
// Function to perform union
// of the sets a and b
int union_sets(int a, int b)
{
    // Find parent of a and b
    a = find_set(a);
    b = find_set(b);
 
    // If parent are different
    if (a != b) {
 
        // Swap Operation
        if (size[a] < size[b])
            swap(a, b);
 
        // Update parent of b as a
        parent[b] = a;
        size[a] += size[b];
        return 1;
    }
 
    // Otherwise, return 0
    return 0;
}
 
// Function to create a Minimum Cost
// Spanning tree for given houses
void MST(int houses[][2], int n)
{
    // Stores adjacency list of graph
    vector<pair<int, pair<int, int> > > v;
 
    // Traverse each coordinate
    for (int i = 0; i < n; i++) {
 
        for (int j = i + 1; j < n; j++) {
 
            // Find the Manhattan distance
            int p = abs(houses[i][0]
                        - houses[j][0]);
 
            p += abs(houses[i][1]
                     - houses[j][1]);
 
            // Add the edges
            v.push_back({ p, { i, j } });
        }
    }
 
    parent.resize(n);
    size.resize(n);
 
    // Sort all the edges
    sort(v.begin(), v.end());
 
    // Initialize parent[] and size[]
    for (int i = 0; i < n; i++) {
        parent[i] = i, size[i] = 1;
    }
 
    /// Stores the minimum cost
    int ans = 0;
 
    // Finding the minimum cost
    for (auto x : v) {
 
        // Perform the unioun operation
        if (union_sets(x.second.first,
                       x.second.second)) {
            ans += x.first;
        }
    }
 
    // Print the minimum cost
    cout << ans;
}
 
// Driver Code
int main()
{
    // Given houses
    int houses[][2] = { { 0, 0 }, { 2, 2 }, 
                        { 3, 10 }, { 5, 2 }, 
                        { 7, 0 }};
 
    int N = sizeof(houses)
            / sizeof(houses[0]);
 
    // Function Call
    MST(houses, N);
 
    return 0;
}
