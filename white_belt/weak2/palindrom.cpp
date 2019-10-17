#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool IsPalindrom(string s)
{
    string cpy = s;
    reverse(s.begin(), s.end());
    return s == cpy;
}

vector<string> PalindromFilter(vector<string> words, int minLength) {
    vector<string> v;
    for (string s: words){
        if (IsPalindrom(s) && s.size() >= minLength) {
            v.push_back(s);
        }
    }
    return v;
}
int main()
{

    return 0;
}