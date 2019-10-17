#include <iostream>
#include <string>
#include <set>

using namespace std;

int main()
{
    int n;
    set<string> s;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        string ss;
        cin >> ss;
        s.insert(ss);
    }
    cout << s.size();
    return 0;
}