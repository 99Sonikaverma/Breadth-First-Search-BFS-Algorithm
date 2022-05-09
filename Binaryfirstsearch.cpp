#include<iostream>
#include <list>
using namespace std;
class Graphs
{
	int Vertex; // No. of vertices

	// Pointer to an array containing adjacency lists items

	list<int> *adjacency;
public:
	Graphs(int Vertex); // Constructor

	// This is a function to add an edge to graph
	void addEdge(int x, int y);

	// prints BFS traversal from a given source s
	void BFS(int a);
};

Graphs::Graphs(int Vertex)
{
	this->Vertex = Vertex;
	adjacency = new list<int>[Vertex];
}

void Graphs::addEdge(int x, int y)
{
	adjacency[x].push_back(y); //It Add y to x’s list.
}

void Graphs::BFS(int a)
{
	// Mark all the vertices as not visited
	bool *visited = new bool[Vertex];
	for(int i = 0; i < Vertex; i++)
		visited[i] = false;

	// Create a queue for BFS
	list<int> queue;

	// Mark the current node as visited and enqueue it
	visited[a] = true;
	queue.push_back(a);

	// 'i' will be used to get all adjacent
	// vertices of a vertex
	list<int>::iterator i;

	while(!queue.empty())
	{
		// Dequeue a vertex from queue and print it
		a = queue.front();
		cout << a << " ";
		queue.pop_front();

		// Get all adjacent vertices of the dequeued
		// vertex s. If a adjacent has not been visited,
		// then mark it visited and enqueue it
		for (i = adjacency[a].begin(); i != adjacency[a].end(); ++i)
		{
			if (!visited[*i])
			{
				visited[*i] = true;
				queue.push_back(*i);
			}
		}
	}
}

// Driver program to test methods of graph class
int main()
{
	// Create a graph given in the above diagram
	Graphs g(4);
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 2);
	g.addEdge(2, 0);
	g.addEdge(2, 3);
	g.addEdge(3, 3);

	cout << "Following is Breadth First Traversal "
		<< "(starting from vertex 2) \n";
	g.BFS(2);

	return 0;
}
