#pragma once
#include <stack>
#include <queue>

using namespace std;


class Palindrome{
public:
    Palindrome(string sent) : sentence(sent) {}

    bool isPalindrome() const;


    friend ostream &operator << (ostream &out, const Palindrome &p);

private:
    string sentence;
    string stripSentence() const;
};
string Palindrome::stripSentence() const {
    string clean = "";
    for(char c:sentence){
        c = tolower(c);
        if(c >= 'a' && c <= 'z'){
            clean += c;
        }//end if
    } //end for
    return clean;
}//end stringSentence


bool Palindrome::isPalindrome() const {
    string clean = stripSentence();
    stack<char>s;
    queue<char>q;

    for(char c: clean){
        s.push(c);
        q.push(c);
    }
    while(!s.empty() ){
        if(s.top() != q.front()){
            return false;
        }
        s.pop();
        q.pop();
    }//end of while
    return true;
}

ostream &operator << (ostream &out, const Palindrome &p){
    out << p.sentence << " is ";
    if(!p.isPalindrome()){
        out <<"not ";
    }
    out << "a palindrome";

    return out;
}