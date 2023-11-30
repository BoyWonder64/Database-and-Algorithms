#include "LinkedList.h"
#include <string>
#include <iostream>
using namespace std;

void TestFindMid1();
void TestFindMid2();
void MergeTest();
void MergeSortTest();

bool checkCase(string name, bool condition);
int main()
{
	TestFindMid1();
	TestFindMid2();
	MergeTest();
	MergeSortTest();
	system("pause");
	return 0;
}


void TestFindMid1() {
	int nums[] = { 50, 75, 25, 32, 55, 42, 97, 81, 12, 96, 18, 68, 13, 54, 72 };
	LinkedList<int>myList;

	for (int i = 0; i < 15; i++) {
		myList.insert(nums[i]);
	}
	LinkedListIterator<int> it(myList.begin());
	LinkedListIterator<int> mid(myList.getMiddle(it.getNode()));

	checkCase("Middle Check 1: ", *mid == 81);
}
void TestFindMid2() {
	int nums[] = { 50, 75, 25, 32, 55, 42, 97, 81, 12, 96, 18, 68, 13, 54 };
	LinkedList<int>myList;

	for (int i = 0; i < 14; i++) {
		myList.insert(nums[i]);
	}
	LinkedListIterator<int> it(myList.begin());
	LinkedListIterator<int> mid(myList.getMiddle(it.getNode()));

	checkCase("Middle Check 2: ", *mid == 97);
}


void MergeTest() {
	int nums1[] = { 1, 3, 5, 7 };
	int nums2[] = { 2, 4, 6, 8 };

	LinkedList<int>first;
	LinkedList<int>second;

	for (int i = 0; i < 4; i++) {
		first.insert(nums1[i]);
		second.insert(nums2[i]);
	}
	LinkedListIterator<int> itFirst(first.begin());
	LinkedListIterator<int> itSecond(second.begin());

	LinkedListIterator<int> itMerge(first.mergeInOrder(itFirst.getNode(), itSecond.getNode()));


	bool test = true;
	int i = 1;
	while (itMerge.getNode()) {
		if (*itMerge != i) {
			test = false;
		}
		i++;
		++itMerge;
	}
	if (i != 9) {
		test = false;
	}

	checkCase("Merge Test: ", test);
}


bool checkCase(string name, bool condition) {
	if (!condition) {
		cout << "Failed: " << name << endl;
	}
	else {
		cout << name << ": passed" << endl;
	}
	return condition;
}

void MergeSortTest() {
	int nums[] = { 50, 75, 25, 32, 55, 42, 97, 81, 12, 96, 18, 68, 13, 54 };
	LinkedList<int>myList;

	for (int i = 0; i < 14; i++) {
		myList.insert(nums[i]);
	}
	myList.mergeSort();

	int result[] = { 12, 13, 18, 25, 32, 42, 50, 54, 55, 68, 75, 81, 96, 97 };
	auto temp = myList.begin();
	int i = 0;
	bool test = true;
	for (int i = 0; i < 14; i++) {
		if (result[i] != *temp) {
			test = false;
			break;
		}
		++temp;
	}
	checkCase("Merge Sort Test: ", test);

}
