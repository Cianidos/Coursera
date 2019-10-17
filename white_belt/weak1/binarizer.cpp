#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    string s;
    cin >> n;
    while (n > 0)
    {
        if (n % 2 == 0)
        {
            s.append("0");
        }
        else
        {
            s.append("1");
        }
        n /= 2;
    }
    reverse(s.begin(), s.end());
    cout << s;
}