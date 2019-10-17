#include <fstream>
#include <string>
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
    ifstream input("input.txt");
    int line;
    if (input)
    {
        int n, m;
        input >> n >> m;
        cout << setw(10);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                input >> line;
                input.ignore(1);
                cout << setw(10) << line;
                if (j < m-1) {
                    cout << ' ';
                }
            } 
            if (i < n-1) {
                cout << '\n';
            }
        }
    }
    return 0;
}