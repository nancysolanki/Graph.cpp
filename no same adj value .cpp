// C++ program for the above approach

#include <bits/stdc++.h>
using namespace std;

// Function that prints the edges of
// the generated graph
void printConnections(
	vector<pair<int, int> > store,
	vector<int> ind, int ind1)
{
	// First print connections
	// stored in store[]
	for (auto pr : store) {
		cout << pr.first << " "
			<< pr.second << "\n";
	}

	// Check if there is more than one
	// occurrence of 1st unique element
	if (ind.size() != 0) {

		// Print all other occurrence
		// of 1st unique element with
		// second unique element
		for (auto x : ind) {
			cout << ind1 << " "
				<< x + 1 << "\n";
		}
	}
}

// Function to construct the graph such
// that the every adjacent nodes have
// different value
void constructGraph(char arr[], int N)
{
	vector<int> ind;

	// Stores pair of edges formed
	vector<pair<int, int> > store;

	// Stores first unique occurrence
	char x = arr[0];

	int count = 0, ind1;

	for (int i = 1; i <= N - 1; ++i) {

		// Check for the second
		// unique occurrence
		if (arr[i] != x) {

			// Store indices of 2nd
			// unique occurrence
			ind1 = i + 1;

			// To check if arr has only
			// 1 unique element or not
			count++;

			// Store the connections of all
			// unique elements with Node 1
			store.push_back({ 1, i + 1 });
		}

		// If value at node (i + 1) is
		// same as value at Node 1 then
		// store its indices
		else {
			ind.push_back(i);
		}
	}

	// If count is zero then it's not
	// possible to construct the graph
	if (count == 0) {
		cout << "Not Possible";
	}

	// If more than 1 unique
	// element is present
	else {
		cout << "Possible"
			<< "\n";

		// Print the edges
		printConnections(store, ind, ind1);
	}
}

// Driver Code
int main()
{
	int N = 5;

	// Given array having node values
	char arr[] = { 'a', 'b', 'a', 'b', 'c' };

	// Function Call
	constructGraph(arr, N);

	return 0;
}
