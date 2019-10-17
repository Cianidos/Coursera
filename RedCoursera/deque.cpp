#include <iostream>
#include <vector>
using namespace std;
//
//template <typename T>
//class Node {
// public:
//  Node<T>* __left;
//  Node<T>* __right;
//  T __value;
//  Node(const T& _val = T(), Node<T>* _l = nullptr, Node<T>* _r = nullptr)
//      : __left(_l), __right(_r), __value(_val) {}
//};
//
//template <typename T>
//class Deque {
//  
//  Node<T>*__first, *__last;
//  size_t __size = 0;
//
// public:
//  Deque(size_t _s = 0) : __size(_s) {
//    __first = nullptr;
//    __last = nullptr;
//    if (_s > 0) {
//      for (; _s; --_s)
//        PushBack(T());
//    }
//  }
//
//  const bool Empty() const { return __size == 0; }
//  const size_t Size() const { return __size; }
//
//  const T& operator[](size_t _i) const {
//    Node<T>* res = __first;
//    for (; (_i); --_i) {
//      res = res->__right;
//    }
//    return res->__value;
//  }
//  T& operator[](size_t _i) {
//    Node<T>* res = __first;
//    for (; (_i); --_i) {
//      res = res->__right;
//    }
//    return res->__value;
//  }
//  const T& At(size_t _i) const {
//    if (_i >= __size || _i < 0) {
//      throw std::out_of_range("");
//    } else {
//      return (*this)[_i];
//    }
//  }
//  T& At(size_t _i) {
//    if (_i >= __size || _i < 0) {
//      throw std::out_of_range("");
//    } else {
//      return (*this)[_i];
//    }
//  }
//
//  const T& Front() const { return __first->__value; }
//  T& Front() { return __first->__value; }
//
//  const T& Back() const { return __last->__value; }
//  T& Back() { return __last->__value; }
//
//
//
//
//  void PushFront(const T& _val) {
//    ++__size;
//    if (__first == nullptr) {
//      __first = new Node<T>(_val);
//      __last = __first;
//    } else {
//      __first->__left = new Node<T>(_val, nullptr, __first);
//      __first = __first->__left;
//    }
//  }
//  void PushBack(const T& _val) {
//    ++__size;
//    if (__first == nullptr) {
//      __first = new Node<T>(_val);
//      __last = __first;
//    } else {
//      __last->__right = new Node<T>(_val, __last);
//      __last = __last->__right;
//    }
//  }
//};

template<class T>
class Deque {
  vector<T> left(0), right(0);
  size_t l = 0, r = 0;
  Deque() {
  }

    const bool Empty() const { return Size() == 0; }
  const size_t Size() const { return l + r; }
  
    const T& operator[](size_t _i) const {

    }
    T& operator[](size_t _i) {

    }
    const T& At(size_t _i) const {
      if (_i >= __size || _i < 0) {
        throw std::out_of_range("");
      } else {
        return (*this)[_i];
      }

    }
    T& At(size_t _i) {
      if (_i >= __size || _i < 0) {
        throw std::out_of_range("");
      } else {
        return (*this)[_i];
      }

    }
  
    const T& Front() const { return left[l - 1]; }
    T& Front() { return left[l - 1]; }
  
    const T& Back() const { return right[r - 1]; }
    T& Back() { return right[r - 1]; }
  
  
  
  
    void PushFront(const T& _val) { left.push_back(_val);
    }
    void PushBack(const T& _val) { right.push_back(_val);
    }


};


//
//int main() {
//  Deque<int> a;
//  cout << a.Size() << endl;
//  a.PushBack(10);
//  a.PushFront(20);
//  cout << a[0] << ' ' << a[1];
//  int e = a.Front();
//  int v = a.At(1);
//}