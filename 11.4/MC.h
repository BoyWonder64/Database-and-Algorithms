#pragma once

#include "GameState.h"

class MC {
public:
	MC();
	MC(GameState);
	void buildGraph(GameState);
	void solve();
	Graph<GameState> getGraph();

private:
	Graph<GameState> graph;
};

MC::MC() {
	GameState start(3, 3, true);
	graph.addVertex(start);
	buildGraph(start);
}


Graph<GameState> MC::getGraph() {
	return graph;
}

MC::MC(GameState start) {
	graph.addVertex(start);
	buildGraph(start);
}


void MC::buildGraph(GameState curr) {
	if (!curr.isValidState()) {
		return;
	}
	//    Possible Moves
	//1.  missionary only
	//2   cannibal only 
	//3   missinary cannible
	//4   2 missionary 
	//5   2 cannibals
	bool boatSide = !curr.isBoatLeft();

	GameState start(3, 3, true);

	for (int m = 0; m <= 2; m++) { //Number of missionaries in the boat
		for (int c = 0; c <= 2; c++) { //Number of cannibals in the boat
			if (m + c > 2 || m + c == 0) continue;//Skip any iteration larger than boat size

			int missToMove, cansToMove;
			if (curr.isBoatLeft()) {
				missToMove = curr.getMissionariesLeft() - m;
				cansToMove = curr.getCannibalsLeft() - c;
			}
			else {
				missToMove = curr.getMissionariesLeft() + m;
				cansToMove = curr.getCannibalsLeft() + c;
			}

			GameState state(missToMove, cansToMove, boatSide);

			//If the  cannibals don't eat the missionaries and the vertex is not already in the list
			if (state.isValidState() && graph.getVertexPos(state) < 0) {
				graph.addVertex(state);
				graph.addEdge(curr, state);
				graph.addEdge(state, curr);
				buildGraph(state);
			}
		}
	}
}

