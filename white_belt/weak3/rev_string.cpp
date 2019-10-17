#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class ReversibleString {
public:
ReversibleString(){
    value = "";
}
ReversibleString(string s) {
    value = s;
}
string ToString() const{
    return value;
}
void Reverse() {
    reverse(value.begin(), value.end());
}
private:
string value;
};


int main() {
  ReversibleString s("live");
  s.Reverse();
  cout << s.ToString() << endl;
  
  s.Reverse();
  const ReversibleString& s_ref = s;
  string tmp = s_ref.ToString();
  cout << tmp << endl;
  
  ReversibleString empty;
  cout << '"' << empty.ToString() << '"' << endl;
  
  return 0;
}