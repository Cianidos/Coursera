#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
     string s;
     s += "Hello";
     {
          s += " world";
     }
     cout << s;
     return 0;
}