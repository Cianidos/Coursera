#include <map>
#include <iostream>
#include <string>
#include <set>

using namespace std;

int main()
{
    int q;
    map<string, set<string>> synoms;
    cin >> q;
    for (int i = 0; i < q; ++i)
    {
        string query;
        cin >> query;
        if (query == "ADD")
        {
            string word1, word2;
            cin >> word1 >> word2;
            synoms[word1].insert(word2);
            synoms[word2].insert(word1);
        }
        else if (query == "COUNT")
        {
            string word;
            cin >> word;
            cout << synoms[word].size() << "\n";
        }
        else if (query == "CHECK")
        {
            string word1, word2;
            cin >> word1 >> word2;
            if (synoms[word1].count(word2))
            {
                cout << "YES\n";
            }
            else
            {
                cout << "NO\n";
            }
        }
    }
    return 0;
}
