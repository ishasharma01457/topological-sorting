#include <iostream>
#include <conio.h>
#include <list>
#include <stack>
using namespace std;
class Graph {
	int Vertx;


	list<int>* adj;


	void topoUtil(int v, bool visit[], stack<int>& Stack);

public:
	Graph(int Vertx);


	void Edge(int v, int w);


	void topo();
};

Graph::Graph(int Vertx)
{
	this->Vertx = Vertx;
	adj = new list<int>[Vertx];
}

void Graph::Edge(int v, int w)
{
	adj[v].push_back(w);
}

void Graph::topoUtil(int v, bool visit[],
								stack<int>& Stack)
{

	visit[v] = true;


	list<int>::iterator i;
	for (i = adj[v].begin(); i != adj[v].end(); ++i)
		if (!visit[*i])
			topoUtil(*i, visit, Stack);

	Stack.push(v);
}



void Graph::topo()
{
	stack<int> Stack;


	bool* visit = new bool[Vertx];
	for (int i = 0; i < Vertx; i++)
		visit[i] = false;


	for (int i = 0; i < Vertx; i++)
		if (visit[i] == false)
			topoUtil(i, visit, Stack);


	while (Stack.empty() == false) {
		cout << Stack.top() << " ";
		Stack.pop();
	}
}


int main()
{

	Graph g(8);
	g.Edge(5, 2);
	g.Edge(5, 0);
	g.Edge(4, 0);
	g.Edge(4, 1);
    g.Edge(2, 3);
    g.Edge(3, 1);
    g.Edge(1, 2);
    g.Edge(2, 3);

	cout << " Topological Sort ";
	g.topo();

	return 0;
}
