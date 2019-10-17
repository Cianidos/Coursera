#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <vector>

using namespace std;

class Date
{
private:
  int year;
  int month;
  int day;

public:
  Date(int new_year, int new_month, int new_day)
  {
    year = new_year;
    month = new_month;
    day = new_day;
  }
  int GetYear() const { return year; }
  int GetMonth() const { return month; }
  int GetDay() const { return day; }
};

bool
operator<(const Date& lhs, const Date& rhs)
{
  if (lhs.GetYear() != rhs.GetYear()) {
    return lhs.GetYear() < rhs.GetYear();
  }
  if (lhs.GetMonth() != rhs.GetMonth()) {
    return lhs.GetMonth() < rhs.GetMonth();
  }
  if (lhs.GetDay() != rhs.GetDay()) {
    return lhs.GetDay() < rhs.GetDay();
  }
  return false;
}

ostream&
operator<<(ostream& stream, const Date& date)
{
  cout << setfill('0') << setw(4) << date.GetYear() << "-" << setfill('0')
       << setw(2) << date.GetMonth() << "-" << setfill('0') << setw(2)
       << date.GetDay();
  return stream;
}

class Database
{
private:
  map<Date, set<string>> db;

public:
  void AddEvent(const Date& date, const string& event)
  {
    db[date].insert(event);
  }
  bool DeleteEvent(const Date& date, const string& event)
  {
    if (db.count(date) && db.at(date).count(event)) {
      db.at(date).erase(event);
      return true;
    };
    return false;
  }
  int DeleteDate(const Date& date)
  {
    if (db.count(date)) {
      int n = db.at(date).size();
      db.erase(date);
      return n;
    }
    return 0;
  }
  set<string> Find(const Date& date) const
  {
    set<string> n;
    if (db.count(date)) {
      n = db.at(date);
    }
    return n;
  }
  void Print() const
  {
    for (auto& item : db) {
      for (const string& event : item.second) {
        cout << item.first << " " << event << endl;
      }
    }
  }
};

Date
GetValidDate(const string& s)
{
  stringstream ss(s);
  string y, m, d;

  if (ss.peek() == '-') {
    y += ss.peek();
    ss.ignore(1);
  }
  if (ss.peek() == '+') {
    ss.ignore(1);
  }
  while (isdigit(ss.peek())) {
    y += ss.peek();
    ss.ignore(1);
  }

  if (y[0] == '-') {
    throw runtime_error("Wrong date format: " + s);
  }

  if (ss.eof()) {
    throw runtime_error("Wrong date format: " + s);
  }

  if (ss.peek() == '-') {
    ss.ignore(1);
    if (ss.peek() == '-') {
      m += ss.peek();
      ss.ignore(1);
    }
    if (ss.peek() == '+') {
      ss.ignore(1);
    }
    while (isdigit(ss.peek())) {
      m += ss.peek();
      ss.ignore(1);
    }
  } else {
    throw runtime_error("Wrong date format: " + s);
  }

  if (m[0] == '-' && m.size() == 1) {
    throw runtime_error("Wrong date format: " + s);
  }

  if (m[0] == '-') {
    throw runtime_error("Month value is invalid: " + m);
  }

  if (ss.eof()) {
    throw runtime_error("Wrong date format: " + s);
  }

  if (ss.peek() == '-') {
    ss.ignore(1);
    if (ss.peek() == '-') {
      d += ss.peek();
      ss.ignore(1);
    }
    if (ss.peek() == '+') {
      ss.ignore(1);
    }
    while (isdigit(ss.peek())) {
      d += ss.peek();
      ss.ignore(1);
    }
  } else {
    throw runtime_error("Wrong date format: " + s);
  }

  if (d[0] == '-' && d.size() == 1) {
    throw runtime_error("Wrong date format: " + s);
  }

  if (d[0] == '-') {
    throw runtime_error("Day value is invalid: " + d);
  }

  if (!ss.eof()) {
    throw runtime_error("Wrong date format: " + s);
  }

  int year = atoi(y.c_str());
  int month = atoi(m.c_str());
  int day = atoi(d.c_str());

  if (month <= 0 || month > 12) {
    throw runtime_error("Month value is invalid: " + to_string(month));
  }

  if (day <= 0 || day > 31) {
    throw runtime_error("Day value is invalid: " + to_string(day));
  }

  //	cout << year << "/" << month << "/" << day << endl;
  return Date(year, month, day);
}

int
main()
{
  Database db;

  string command, cmd;
  while (getline(cin, command)) {
    if (command.empty()) {
      continue;
    }
    stringstream ss(command);
    ss >> cmd;
    if (cmd == "Add") {
      string date, event;
      ss >> date >> event;
      try {
        Date ValidDate = GetValidDate(date);
        db.AddEvent(ValidDate, event);
      } catch (const runtime_error& e) {
        cout << e.what() << endl;
        break;
      }
    } else if (cmd == "Del") {
      string date, event;
      ss >> date >> event;
      try {
        Date ValidDate = GetValidDate(date);
        if (!event.empty()) {
          bool b = db.DeleteEvent(ValidDate, event);
          if (b) {
            cout << "Deleted successfully" << endl;
          } else {
            cout << "Event not found" << endl;
          }
        } else {
          int n = db.DeleteDate(ValidDate);
          cout << "Deleted " << n << " events" << endl;
        }
      } catch (const runtime_error& e) {
        cout << e.what() << endl;
        break;
      }
    } else if (cmd == "Find") {
      string date;
      ss >> date;
      try {
        Date ValidDate = GetValidDate(date);
        set<string> events = db.Find(ValidDate);
        if (events.size()) {
          for (const string& event : events) {
            cout << event << endl;
          }
        }
      } catch (const runtime_error& e) {
        cout << e.what() << endl;
        break;
      }
    } else if (cmd == "Print") {
      db.Print();
    } else {
      cout << "Unknown command: " << cmd << endl;
    }
  }

  return 0;
}