#pragma once
#include <iostream>
#include <string>
#include <stdexcept>
#include <stack>
#include <queue>

using namespace std;

class BracketCheck;
ostream&operator<< (ostream& out, const BracketCheck&b);

class BracketCheck {
    public:
        BracketCheck(string exp); // Constructor declaration?
        int numBrackets();
        bool isMatch(char open, char close);
        bool isBalanced();
        string stripSentence() const;
private:
    string bPlaceholder;
};

BracketCheck::BracketCheck(string exp){
    bPlaceholder = exp;
    }



string BracketCheck::stripSentence() const {
    string clean = "";
    for(char c:bPlaceholder){
        if(c >= 'a' || c <= 'z'){
            clean += c;
        }//end if
    } //end for
    return clean;
}//end stringSentence



bool BracketCheck::isBalanced() { //Returns true if the brackets are balanced
    string clean = stripSentence();
    stack<char> bList;
    int count = 0;

    for (char c: clean) {
        if (c == '(' || c == '{' || c == '[') {
            bList.push(c);
            }
        if(bList.empty() && c == ')' || bList.empty() && c == '}' || bList.empty() && c == ']' ){
            return false;
        } if(!bList.empty()){
            bool flag = isMatch(bList.top(),c);
            if (flag == true){
                bList.pop();
                count++;
            }
        }

        } // end of for

        if (!bList.empty()) {
            return false;
        } else {
            return true;
        }

}//end of isBalanced


bool BracketCheck::isMatch(char open, char close) {
    if (open == '(' && close == ')') {
        return true;
    }
    if(open == '{' && close == '}'){
        return true;
    }
    if(open == '[' && close == ']'){
        return true;
    } else {
        return false;
    }
}

int BracketCheck::numBrackets() { //returns the number of pairs of brackets
    string clean = stripSentence();
    stack<char> bList;
    int count = 0;

    for (char c: clean) {
        if (c == '(' || c == '{' || c == '[') {
            bList.push(c);
        }
        if(!bList.empty()){
            bool flag = isMatch(bList.top(), c);
            if (flag) {
                bList.pop();
                count++;
            }
        }
    }

    return count;
}


ostream& operator<<(ostream& out, const BracketCheck&b){

    return out;
}
