#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Rational {
public:
    Rational(long n = 0, long d = 1) {
        if (d == 0) {
            throw invalid_argument("Invalid argument");
        }
        numerator = n;
        denominator = d;
        this->prim();
    }

    int Numerator() const {
        return numerator;
    }

    int Denominator() const {
        return denominator;
    }

    bool operator<(const Rational& other) const {
        double a = (double) this->Numerator() / (double) this->Denominator();
        double b = (double) other.Numerator() / (double) other.Denominator();
        return a < b;
    }
    bool operator>(const Rational& other) const {
        return other < *this;
    }

    bool operator==(const Rational& other) const {
        return this->Numerator() == other.Numerator() &&
               this->Denominator() == other.Denominator();
    }

    Rational operator*(const Rational& other) const {
         Rational result(this->Numerator() * other.Numerator(),
                         this->Denominator() * other.Denominator());
        return result;
    }

    Rational operator/(const Rational& other) const {
        if (other.Numerator() == 0) {
            throw domain_error("Division by zero");
        }
        Rational result(this->Numerator() * other.Denominator(),
                        this->Denominator() * other.Numerator());
        return result; 
    }

    Rational operator+(const Rational& other) const {
        Rational result(this->Numerator() * other. Denominator() +
                        this->Denominator() * other.Numerator(),
                        this->Denominator() * other.Denominator());
        return result;
    }

    Rational operator-(const Rational& other) {
        Rational result(this->Numerator() * other.Denominator() -
                        this->Denominator() * other.Numerator(),
                        this->Denominator() * other.Denominator());
        return result;
    }

friend ostream& operator<<(ostream &outp, const Rational& other);
friend istream& operator>>(istream &inp, Rational& other);
private:
    void prim() {
        int n = this->Numerator(), d = this->Denominator();
        int a = abs(n), b = abs(d);
        while (a != 0 && b != 0)
        {
            if (a > b)
            {
                a %= b;
            }
            else
            {
                b %= a;
            }
        }
        int r;
        if (a > b) {
            r = a;
        } else {
            r = b;
        }
        if (n < 0 and d < 0) {
            n = abs(n);
            d = abs(d);
        } else if (d < 0) {
            n = -n;
            d = abs(d);
        }
        numerator = n / r;
        denominator = d / r;
    }
    long numerator;
    long denominator;
};

ostream& operator<<(ostream &outp, const Rational& other) {
    outp << other.Numerator() << '/' << other.Denominator();
    return outp;
}

istream& operator>>(istream &inp, Rational& other) {
    inp >> other.numerator;
    inp.ignore(1);
    inp >> other.denominator;
    other.prim();
    return inp;
}

int main() {
    Rational a, b;
    char op;
    cin >> a >> op >> b;
    try {
    if (op == '+') {
        cout << a + b;
    } else if (op == '-') {
        cout << a - b;
    } else if (op == '*') {
        cout << a * b;
    } else if (op == '/') {
        cout << a / b;
    }
    } catch (exception &ex) {
        cout << ex.what();
    } 
    return 0;
}