#include <iostream>
#include <string>
#include <vector>
#include "Graph.h"
#include "MC.h"

using std::cout;
using std::endl;

//Function Headers
Graph<int> populateNumbersGraph();
bool testWithNumbers();
void testEdges();
void testMissionariesCannibals();
bool checkCase(string name, bool condition);


int main() {
	testEdges();
	if (testWithNumbers()) {
		testMissionariesCannibals();
	}
	system("pause");
	return 0;
}

void testEdges() {
	Graph<int> g = populateNumbersGraph();

	checkCase("Edge Test 1", g.isEdge(1, 4) == true);
	checkCase("Edge Test 2", g.isEdge(1, 0) == true);
	checkCase("Edge Test", g.isEdge(0, 4) == false);
}

bool testWithNumbers() {
	cout << "Numbers Graph" << endl;
	Graph<int> g = populateNumbersGraph();

	cout << g << endl;
	cout << "\nNumber Graph Test Cases" << endl;
	checkCase("Numbers Test size", g.getNumVertices() == 10);
	checkCase("Vertex position test", g.getVertexPos(7) == 3);

	vector<int>sol = g.getPath(0, 5);
	if (checkCase("Solution implemented", sol.size() > 0)) {
		checkCase("Checking path order 1", sol[0] == 0);
		checkCase("Checking path order 2", sol[sol.size() - 1] == 5);
		checkCase("Checking solution size", sol.size() <= 4);

		int possPath1[] = { 0, 1, 4, 5 };
		int possPath2[] = { 0, 3, 6, 5 };

		bool isPath = true;
		for (unsigned int i = 0; i < sol.size(); i++) {
			if (sol[i] != possPath1[i] && sol[i] != possPath2[i]) {
				isPath = false;
			}
		}
		checkCase("Is solution", isPath);
		return true;
	}
	return false;
}

void testMissionariesCannibals() {
	cout << "\nMissionaries Cannibals Solution" << endl;

	MC mc;
	Graph<GameState> g = mc.getGraph();
	vector<GameState> sol = g.getPath(GameState(3, 3, true), GameState(0, 0, false));
	if (checkCase("Solution implemented", sol.size() > 0)) {
		for (unsigned int i = 0; i < sol.size(); i++) {
			cout << sol[i] << endl;
		}
		cout << "\nMissionaries Cannibals Test Cases" << endl;
		checkCase("Solution Size: ", sol.size() == 12);
		checkCase("Solution Order: ", sol[0] == GameState(3, 3, true));
		checkCase("Solution Order: ", sol[sol.size()-1] == GameState(0, 0, false));

		bool isValid = true;

		for (unsigned int i = 1; i < sol.size(); i++) {
			if (!sol[i].isNeighbor(sol[i - 1])) {
				isValid = false;
			}
		}
		checkCase("Valid Solution", isValid);
	}
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


/*
Numbers Undirected Graph
[0]-----------[2]
|  \            \
|   \            \
[1]  [3]----[6]---[7]
|          /  \
|         /    \
|        /      \
|     [5]--------[8]
|    /   \       /
|   /     \     /
|  /       \   /
[4]         [9]
*/

bool checkCase(string name, bool condition) {
	if (!condition) {
		cout << "Failed: " << name << endl;
	}
	else {
		cout << "Passed: " << name << endl;
	}return condition;
}