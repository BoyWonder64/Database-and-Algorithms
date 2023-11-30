#include <iostream>
#include <sstream>
#include "Collection.h"
using namespace std;

void SwapTest();
void InsertionSortTest();
void BubbleSortTest();
void PivotTest();
void QuickSortTest();
void findMinInRange();
void SelectionSortTest();
bool checkCase(string name, bool condition);

int main()
{
	SwapTest();
	InsertionSortTest();
	BubbleSortTest();
	PivotTest();
	QuickSortTest();
	findMinInRange();
	SelectionSortTest();
	system("pause");
	return 0;
}

void SwapTest() {
	stringstream str;
	Collection<int> nums;
	for (int i = 0; i < 4; i++) {
		nums.add(i);
	}
	nums.swap(1, 2);
	str << nums;
	bool test = str.str() == "0 2 1 3";

	if (!checkCase("Swap Test", test)) {
		cout << "\tOrder was: " << nums;
	}
}

void findMinInRange() {

	int nums[] = { 0, 99, 5, 2, 6, 7, 3, 4, 90, 91 };

	Collection<int>c;
	for (int i = 0; i < 10; i++) {
		c.add(nums[i]);
	}

	int min = c.findMinInRange(4);


	if (!checkCase("Min in Range Value: ", min == 6)) {
		cout << "\tMin was " << min << ", should have been 6" << endl;
	}
}

void SelectionSortTest() {
	stringstream str;

	string msg = "selectionsortseemsinefficient";
	Collection<char>c;
	for (char l : msg) {
		c.add(l);
	}

	c.sortBySelection();
	str << c;
	bool test = str.str() == "c c e e e e e e f f i i i i l m n n n o o r s s s s t t t";
	if (!checkCase("Selection Sort Test", test)) {
		cout << "\tOrder was: " << c << endl;
	}
}
void InsertionSortTest() {
	stringstream str;

	string msg = "insertionsort";
	Collection<char>c;
	for (char l : msg) {
		c.add(l);
	}

	c.sortByInsertion();
	str << c;
	bool test = str.str() == "e i i n n o o r r s s t t";
	if (!checkCase("Insertion Sort Test", test)) {
		cout << "\tOrder was: " << c << endl;
	}
}

void BubbleSortTest() {
	stringstream str;

	string msg = "bubblesort";
	Collection<char>c;
	for (char l : msg) {
		c.add(l);
	}

	c.sortByBubble();
	str << c;
	bool test = str.str() == "b b b e l o r s t u";
	if (!checkCase("Bubble Sort Test", test)) {
		cout << "\tOrder was: " << c << endl;
	}
}

void PivotTest() {
	stringstream str;
	int nums[] = { 99, 99, 5, 2, 6, 3, 7, 4, 90, 91 };

	Collection<int>c;
	for (int i = 0; i < 10; i++) {
		c.add(nums[i]);
	}

	int pivot = c.partition(2, 7);
	str << c;

	if (!checkCase("Check Pivot Value: ", pivot == 5)) {
		cout << "\tPivot was " << pivot << ", should have been 5" << endl;
	}
	bool test = str.str() == "99 99 4 2 3 5 7 6 90 91";
	if (!checkCase("Partition Test", test)) {
		cout << "\tOrder was: " << c << endl;
	}
}

void QuickSortTest() {
	stringstream str;

	string msg = "nlognquicksortismoreefficient";
	Collection<char>c;
	for (char l : msg) {
		c.add(l);
	}

	c.sortByQuick();
	str << c;
	bool test = str.str() == "c c e e e f f g i i i i k l m n n n o o o q r r s s t t u";
	if (!checkCase("Quick Sort Test", test)) {
		cout << "\tOrder was: " << c << endl;
	}
}

bool checkCase(string name, bool condition) {
	if (!condition) {
		cout << "Failed: " << name << endl;
	}
	else {
		cout << "Passed: " << name << endl;
	}
	return condition;
}
