#include <vector>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    int q;
    vector<bool> queue;
    cin >> q;
    for (int i = 0; i < q; ++i)
    {
        string query;
        int k;
        cin >> query;
        if (query == "WORRY")
        {
            cin >> k;
            queue[k] = true;
        }
        else if (query == "QUIET")
        {
            cin >> k;
            queue[k] = false;
        }
        else if (query == "COME")
        {
            cin >> k;
            queue.resize(queue.size() + k, false);
        }
        else if (query == "WORRY_COUNT")
        {
            int s = 0;
            for (bool ch : queue)
            {
                if (ch)
                {
                    ++s;
                }
            }
            cout << s << "\n";
        }
    }
    return 0;
}