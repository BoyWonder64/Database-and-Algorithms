#include <iostream>
#include "LinkedList.h"

using namespace std;

int main()
{
    LinkedList<int>numbers;
    numbers.insert(1);
    numbers.insert(2);
    numbers.insert(3);
    numbers.insert(5);
    numbers.insert(18);
    numbers.insert(6);

    numbers.pointerPractice(4, 18);
    cout << "List Values: " << numbers << endl;

    return 0;
}
