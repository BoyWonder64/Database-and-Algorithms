#include <iostream>
#include <string>
#include <cstdio>
#include <memory>
#include "MyStack.h"

using namespace std;
//Code to check the stack
void testMyStack();
void checkSize();
void errorHandeling();
void testTemplate();
//Aids in testing the program
bool checkTestMemory(string, int, int);
//Checks to see if the results match
bool checkTest(string, int, int);
bool checkTest(string, string, string);

int main()
{
	cout << "Testing MyStack\n" << endl;
	testMyStack();
	checkSize();
	errorHandeling();
	testTemplate();
	cout << "Done\n";
	system("pause");
	return 0;
}




//This helps with testing, do not modify.
void testMyStack() {
	auto stack = make_unique< MyStack <int> >();

	stack->push(1);

	int data = stack->peek();
	stack->pop();
	checkTest("MyStack #1", 1, data);

	stack->push(1);
	stack->push(2);
	stack->push(3);
	stack->push(4);
	stack->push(5);
	checkTest("MyStack #2", 5, stack->peek());
	stack->pop();
	checkTest("MyStack #3", 4, stack->peek());
	stack->pop();
	checkTest("MyStack #4", 3, stack->peek());
	stack->pop();
	checkTest("MyStack #5", 2, stack->peek());
	stack->pop();
	checkTest("MyStack #6", 1, stack->peek());
	stack->pop();

}




void checkSize() {
	auto stack = make_unique< MyStack <int> >();
	// Check currentSize
	checkTest("MyStack #7", 0, stack->size());
	stack->push(12);
	stack->push(32);
	checkTest("MyStack #8", 2, stack->size());

	// Now test filling it up
	stack->push(14);
	stack->push(53);
	stack->push(47);
	checkTest("MyStack #9", 5, stack->size());
}

void errorHandeling() {
	// Now cover error handling
	auto stack = make_unique< MyStack <int> >();
	string caughtError = "";
	int num;
	try {
		num = stack->peek();
	}
	catch (exception &e) {
		caughtError = "caught";
	}
	checkTest("MyStack #10", "caught", caughtError);
}
void testTemplate(){

		// Test some strings
		auto sstack = make_unique < MyStack<string> >();

		sstack->push("pencil");
		sstack->push("pen");
		sstack->push("marker");

		checkTest("MyStack #11", 3, sstack->size());

		// Remove pen from the stack.
		string temp = sstack->peek(); // Get marker
		sstack->pop();               // Remove marker
		sstack->pop();               // Remove pen
		sstack->push(temp);          // Push marker back in

									 // See if it worked
		checkTest("MyStack #12", "marker", sstack->peek());
		sstack->pop();
		checkTest("MyStack #13", "pencil", sstack->peek());
		sstack->pop();

		checkTest("MyStack #14", 0, sstack->size());
	

}

//This helps with testing, do not modify.
bool checkTest(string testName, int whatItShouldBe, int whatItIs) {

	if (whatItShouldBe == whatItIs) {
		cout << "Passed " << testName << endl;
		return true;
	}
	else {
		cout << "***Failed test " << testName << " *** " << endl << "   Output was " << whatItIs << endl << "   Output should have been " << whatItShouldBe << endl;
		return false;
	}
}


//This helps with testing, comment it in when ready, but do not modify the code.
bool checkTest(string testName, string whatItShouldBe, string whatItIs) {

	if (whatItShouldBe == whatItIs) {
		cout << "Passed " << testName << endl;
		return true;
	}
	else {
		if (whatItShouldBe == "") {
			cout << "***Failed test " << testName << " *** " << endl << "   Output was " << whatItIs << endl << "   Output should have been blank. " << endl;
		}
		else {
			cout << "***Failed test " << testName << " *** " << endl << "   Output was " << whatItIs << endl << "   Output should have been " << whatItShouldBe << endl;
		}
		return false;
	}
}

//This helps with testing, do not modify.
bool checkTestMemory(string testName, int whatItShouldBe, int whatItIs) {

	if (whatItShouldBe == whatItIs) {
		cout << "Passed " << testName << endl;
		return true;
	}
	else {
		cout << "***Failed test " << testName << " *** " << endl << ".  ";
		cout << "You are manually managing " << whatItIs << " bytes in memory, but it should be " << whatItShouldBe << " bytes." << endl;
		return false;
	}
}


