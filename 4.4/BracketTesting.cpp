#include <iostream>
#include "BracketCheck.h"
using namespace std;
bool check(string , string , bool );
int countCheck(string, string, string, int);
int main()
{
    check ("Easy", "()", true);
    check ("Not Matched", "(}", false);
    check ("Mixed but valid", "({}[])", true);
    check ("Too Many Closing", "({}[])]", false);
    check ("Not Matched", "({)(})", false);
    check ("Too Many Opening", "{()", false);
    check ("Code", "if (num == 7) { cout << num; }", true);
    check ("Bad Code", "if (num == 7) cout << num; }", false);
    cout << " " << endl;
    countCheck ("Easy", "()", "Count ",1);
    countCheck ("Not Matched", "(}", "Count ",0 );
    countCheck ("Mixed but valid", "({}[])","Count ",3);
    countCheck ("Too Many Closing", "({}[])]","Count ",3);
    countCheck ("Not Matched", "({)(})", "Count ",1);
    countCheck ("Too Many Opening", "{()","Count ",1);
    countCheck ("Code", "if (num == 7) { cout << num; }", "Count ",2);
    countCheck ("Bad Code", "if (num == 7) cout << num; }", "Count ",1);

    return 0;
}
bool check(string name, string expression, bool shouldBe){
    BracketCheck b(expression); //creates the object b and passes expression
    if(shouldBe == b.isBalanced()){
        cout << "Passed: " << name << endl;
        return true;
    }
    else{
        cout << "Failed: " << name << " " << b << endl;
    }
    return false;
}

int countCheck(string name, string expression, string title , int shouldBe){
    BracketCheck b(expression); //creates the object b and passes expression
    if(shouldBe == b.numBrackets()){
        cout << "Passed: " << name << " " << title <<"Bracket Count: " << b.numBrackets() << endl;
        return true;
    }
    else{
        cout << "Failed: " << name << " " << title << b << endl;
    }
    return false;
}


