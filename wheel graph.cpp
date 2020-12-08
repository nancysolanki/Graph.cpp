
play_arrow

brightness_4
// C++ Program to find the diameter,  
// cycles and edges of a Wheel Graph 
#include <bits/stdc++.h> 
using namespace std; 
  
// Function that calculates the 
// Number of Cycle in Wheel Graph. 
int totalCycle(int vertices) 
{ 
    int result = 0; 
  
    // calculates no. of Cycle. 
    result = pow(vertices, 2) - (3 * vertices) + 3; 
  
    return result; 
} 
  
// Function that calculates the 
// Number of Edges in Wheel graph. 
int Edges(int vertices) 
{ 
    int result = 0; 
  
    result = 2 * (vertices - 1); 
  
    return result; 
} 
  
// Function that calculates the 
// Diameter in Wheel Graph. 
int Diameter(int vertices) 
{ 
    int result = 0; 
  
    // calculates Diameter. 
    if (vertices == 4) 
        result = 1; 
    else
        result = 2; 
  
    return result; 
} 
  
// Driver Code 
int main() 
{ 
    int vertices = 4; 
  
    cout << "Number of Cycle = " << totalCycle(vertices) << endl; 
    cout << "Number of Edges = " << Edges(vertices) << endl; 
    cout << "Diameter = " << Diameter(vertices); 
  
    return 0; 
} 
