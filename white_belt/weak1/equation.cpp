#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    float a, b, c;
    cin >> a >> b >> c;
    if (a == 0 && b != 0)
    {
        cout << (-c) / b;
    }
    else if (a == 0 && b == 0)
    {
        
    }
    else if (c == 0)
    {
        cout << 0 << " " << (-b) / a;
    }
    else
    {
        float d = sqrt(b * b + (-4 * a * c));
        float x1 = (-b + d) / (2 * a);
        float x2 = (-b - d) / (2 * a);
        if (x1 == x2)
        {
            cout << x1;
        }
        else if (x1 != x1 && x2 == x2)
        {
            cout << x2;
        }
        else if (x1 == x1 && x2 != x2)
        {
            cout << x1;
        }
        else if (x1 == x1 && x2 == x2)
        {
            cout << x1 << " " << x2;
        }
    }
}
