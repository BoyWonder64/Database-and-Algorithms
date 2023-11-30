#pragma once
#include <iostream>
#include <string>

using namespace std;

class Subsequences;
ostream&operator<< (ostream& out, const Subsequences&b);


class Subsequences{

    public:
        Subsequences(string sentence);
        bool isSubsequence(string sub);
        bool helperFunction(string sub, int iWord, int iSub);
        friend ostream& operator<< (std::ostream& out, const Subsequences& b);

private:
    string testSentence;
};

Subsequences::Subsequences(string sentence){
    testSentence = sentence;
}


bool Subsequences:: isSubsequence(string sub){

    if(sub[0] != testSentence[0]){
      return false;
    } else {
        return helperFunction(sub, 0, 0);;
    }

}//end isSubsequence


bool Subsequences::helperFunction(string sub, int iWord, int iSub) {
    if(testSentence.length() != iWord){
        if (sub.length() != iSub) {
            if (sub.length() > iSub) {
                if (sub[iSub] == testSentence[iWord]) {
                    iWord++;
                    iSub++;
                    return helperFunction(sub, iWord, iSub);
                } else {
                    iWord++;
                    return helperFunction(sub, iWord, iSub);
                }
            }
        }
    }
    if(sub.length() == iSub) {
        if (testSentence.length() != iWord || testSentence.length() == iWord) {
            return true;
        } else {
            return false;
        }
    }

} //end of helperFunction

ostream&operator<< (ostream& out, const Subsequences&b){
    return out;
}