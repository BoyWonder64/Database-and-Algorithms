#include <iostream>
#include "Palindrome.h"

using namespace std;

bool check(string, string, bool);

int main()
{
    Palindrome p("Taco Cat");

    check ("Easy", "mom", true);
    check ("With spaces", "taco cat", true);
    check ("With Capitals", "A man a plan a canal Panama", true);
    check ("With punctuation", "Don't nod.", true);
    check ("Not a palindrome", "madams", false);

    return 0;
}

bool check(string name, string expression, bool shouldBe){
    Palindrome p(expression);
    if(shouldBe == p.isPalindrome()){
        cout << "Passed: " << name << " " << p << endl;
        return true;
    }
    else{
        cout << "Failed: " << name << " " << p << endl;
    }

    return false;
}
