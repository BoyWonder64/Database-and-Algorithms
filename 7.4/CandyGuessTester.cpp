#include <iostream>
#include <cmath>
#include <sstream>
#include <memory>
#include "Queue.h"
#include "Person.h"

using namespace std;

Queue<Person>findWinners(int numberOfCandies, Queue<Person>guessList);
void testQueue();
void testConstructors();
void testCandyGuessMethod1();
void testCandyGuessMethod2();

template<class Type>
bool test(string, Type, Type);

int main() {
	testQueue();
	testConstructors();
	testCandyGuessMethod1();
	testCandyGuessMethod2();
}

/*  TODO ********** TODO ********** TODO ********** TODO ********** TODO ********** TODO ********** TODO
	Complete the following method to determine the people who won the Candy in a Jar guessing game.  
	numberOfCandies represents the number of Candies in the Jar. 
	guessList contains the names and guesses of each of the people playing the game.
********** TODO ********** TODO ********** TODO ********** TODO ********** TODO*/
Queue<Person> findWinners(int numberOfCandies, Queue<Person>guessList) {
	Queue<Person>winners;
    Queue<Person>side;
    //winning amount  = 10
    //p.person p.amount
    //numberOfCandies = 100
    int i = 0;
    int difference;
    int winAgainst = numberOfCandies;

        while(!guessList.isEmpty()){

            Person p = guessList.peek(i);
            difference = p.getAmount() - numberOfCandies;
            guessList.dequeue();
            abs(difference);
            if(fdim(difference, numberOfCandies) < fdim(winAgainst, numberOfCandies) ) {
                if(difference)
                winAgainst = difference;
                winners.clear();
                winners.enqueue(p);
                if (fdim(difference, numberOfCandies) == fdim(winAgainst, numberOfCandies)){
                    winners.enqueue(p);
                }

            }
            i++;
        }


return winners;
}

void testQueue() {
	Queue<int> one;
	for (int i = 0; i < 5; i++) {
		one.enqueue(i);
	}
	
	test("01 Adding to Queue", one.peek(0), 0);
	one.dequeue();
	test("02 Removing from Queue", one.peek(0), 1);
	one.clear();

	test("03 Clear", one.isEmpty(), true);
	bool check = true;
	try {
		one.dequeue();
	}
	catch (exception &e) {
		check = false;
	}
	test("04 Removing from empty queue", check, false);

}
void testConstructors() {
	Queue<int> one;
	for (int i = 0; i < 5; i++) {
		one.enqueue(i);
	}
	Queue<int>two = one;
	stringstream ss1;
	stringstream ss2;
	ss1 << one;
	ss2 << two;

	test("05 Copy Constructor: ", ss1.str() == ss2.str(), true);
	two.enqueue(10);
	ss1.str("");
	ss2.str("");
	ss1 << one;
	ss2 << two;

	test("06 Deep Copy in Copy Constructor: ", ss1.str() == ss2.str(), false);

	one = two;
	two.enqueue(10);
	ss1.str("");
	ss2.str("");
	ss1 << one;
	ss2 << two;
	test("07 Deep Copy operator=: ", ss1.str() == ss2.str(), false);
}
void testCandyGuessMethod1() {
	Queue<Person>guesses;
	string names[] = { "Sarah", "Kim", "Bob", "Brook", "Zed", "Brock", "Ted" };
	int gs[] = { 105, 96, 95, 93, 106, 104, 105};
	for (int i = 0; i < 7; i++) {
		unique_ptr<Person>g = make_unique<Person>(Person(names[i], gs[i]));
		guesses.enqueue(*g);
	}

	Queue<Person> correct;

	correct.enqueue(Person("Kim", 96));
	correct.enqueue(Person("Brock", 104));


	Queue<Person> temp = findWinners(100, guesses);

	stringstream ss1, ss2;
	ss1 << temp << endl;
	ss2 << correct<< endl;

	test("08 Candy Guess: ", ss1.str() == ss2.str(), true);
}

void testCandyGuessMethod2() {
	Queue<Person>guesses;
	string names[] = { "Sarah", "Kim", "Bob", "Brook", "Zed", "Brock", "Ted", "Ana" };
	int gs[] = {40, 60, 45, 44, 55, 48, 52, 48};
	for (int i = 0; i < 8; i++) {
		unique_ptr<Person>g = make_unique<Person>(Person(names[i], gs[i]));
		guesses.enqueue(*g);
	}

	Queue<Person> correct;

	correct.enqueue(Person("Brock", 48));
	correct.enqueue(Person("Ted", 52));
	correct.enqueue(Person("Ana", 48));

	Queue<Person> temp = findWinners(50, guesses);

	stringstream ss1, ss2;
	ss1 << temp << endl;
	ss2 << correct<< endl;
	test("09 Candy Guess: ", ss1.str() == ss2.str(), true);
}



template<class Type>
bool test(string name, Type is, Type shouldBe) {
	if (is == shouldBe) {
		cout << "Passed: " << name << endl;
		return true;
	}
	else {
		cout << "Failed: " << name << " was " << is << " should be: " << shouldBe << endl;
	}
	return false;
}