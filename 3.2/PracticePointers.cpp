#include <iostream>
#include <memory>
#include <string>
#include <stdexcept>
using namespace std;


int main()
{
   auto num = make_shared<int>(34);
   auto lst = make_unique<int[]>(3);

    lst[0] = 42;
    lst[1] = *num;
    lst[2] = lst[1] + lst[0];
  
        
    cout << lst[0] << " " << lst[1] << " " << lst[2] << endl;
  
}