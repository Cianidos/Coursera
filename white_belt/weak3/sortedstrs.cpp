#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class SortedStrings
{
public:
    void AddString(const string &s)
    {
        strings.push_back(s);
        UpSort();
    }

    vector<string> GetSortedStrings()
    {
        return strings;
    }

private:
    void UpSort()
    {
        sort(strings.begin(), strings.end());
    }
    vector<string> strings;
};
