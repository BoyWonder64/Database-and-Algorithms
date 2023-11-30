#include <iostream>
#include <string>
#include "Graph.h"

using namespace std;

Graph<int> populateNumbersGraph();
void testWithNumbers();
void testEdges();

bool checkCase(string name, bool condition);

int main() {
	testWithNumbers();
	void testEdges();
	system("pause");

}

void testWithNumbers() {
	cout << "Numbers Graph" << endl;
	Graph<int> g = populateNumbersGraph();

	cout << g << endl;
	cout << "\nNumber Graph Test Cases" << endl;
	checkCase("Numbers Test size", g.getNumVertices() == 10);
	checkCase("Vertex position test", g.getVertexPos(7) == 3);

	
}

void testEdges() {
	Graph<int> g = populateNumbersGraph();

	checkCase("Edge Test 1", g.isEdge(1, 4) == true);
	checkCase("Edge Test 2", g.isEdge(1, 0) == true);
	checkCase("Edge Test", g.isEdge(0, 4) == false);
}

Graph<int>populateNumbersGraph() {
	Graph<int>g;
	int verts[] = { 9, 2, 1, 7, 5, 4, 8, 3, 6, 0 };
	for (int i = 0; i < 10; i++) {
		g.addVertex(verts[i]);
	}


	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(0, 3);
	g.addEdge(1, 4);
	g.addEdge(4, 5);
	g.addEdge(5, 6);
	g.addEdge(3, 6);
	g.addEdge(6, 7);
	g.addEdge(2, 7);
	g.addEdge(6, 8);
	g.addEdge(5, 8);
	g.addEdge(5, 9);
	g.addEdge(9, 8);
	
	g.addEdge(1, 0);
	g.addEdge(2, 0);
	g.addEdge(3, 0);
	g.addEdge(4, 1);
	g.addEdge(5, 4);
	g.addEdge(6, 5);
	g.addEdge(6, 3);
	g.addEdge(7, 6);
	g.addEdge(7, 2);
	g.addEdge(8, 6);
	g.addEdge(8, 5);
	g.addEdge(9, 5);
	g.addEdge(8, 9);


	return g;
}

bool checkCase(string name, bool condition) {
	if (!condition) {
		cout << "Failed: " << name << endl;
	}
	else {
		cout << "Passed: " << name << endl;
	}return condition;
}