#include "test_runner.h"

using namespace std;

template<typename T>
class Table {
  vector<vector<T>> bd;

 public:
  Table(size_t a, size_t b) : bd(vector<vector<T>>(a, vector<T>(b, T()))) {}

  pair<size_t, size_t> Size() const { return make_pair(bd.size(), bd[0].size());
  }
  void Resize(size_t a, size_t b) {
    bd.resize(a);
    for (auto& i : bd) {
      i.resize(b);
    }
  }

  auto& operator[](size_t i) { return bd[i];
  }
  auto& operator[](size_t i) const { return bd[i]; }
};

void TestTable() {
  Table<int> t(1, 1);
  ASSERT_EQUAL(t.Size().first, 1u);
  ASSERT_EQUAL(t.Size().second, 1u);
  t[0][0] = 42;
  ASSERT_EQUAL(t[0][0], 42);
  t.Resize(3, 4);
  ASSERT_EQUAL(t.Size().first, 3u);
  ASSERT_EQUAL(t.Size().second, 4u);
}
//
//int main() {
//  TestRunner tr;
//  RUN_TEST(tr, TestTable);
//  return 0;
//}