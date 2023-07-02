#ifndef VECTOR_H
#define VECTOR_H

#include <algorithm>
#include <limits>

template <typename T>
class vector {
public:
  using value_type = T;
  using reference = value_type &;
  using const_reference = const value_type &;
  // using iterator = VectorIterator<T>;
  // using const_iterator = VectorConstIterator<T>;
  using size_type = size_t;
  using pointer =value_type*;

public:
  vector() : arr(nullptr), sz(0), cap(0) {}
  explicit vector(size_type n) {
    sz = n;
    cap = n;
    arr = new value_type[n];
  }
  vector(std::initializer_list<value_type> const &items) {
    sz = items.size();
    cap = items.size();
    arr = new value_type[cap];
    for (size_type i = 0; i < sz; i++) {
      arr[i] = items.begin()[i];
    }
  }

  vector(const vector &v) { operator=(v); }
  vector(vector &&v) {operator=(std::move(v));}
  ~vector() {
    if (arr != nullptr) {
      delete[] arr;
      arr = nullptr;
      sz = 0;
      cap = 0;
    }
  }

  vector &operator=(const vector &v) {
    sz = v.sz;
    cap = v.cap;
    arr = new value_type[cap];
    for (size_type i = 0; i < sz; i++) {
      arr[i] = v.arr[i];
    }
    return *this;
  }
  vector &operator=(vector &&v) {
    sz = v.sz;
    cap = v.cap;
    arr = v.arr;
    v.sz = 0;
    v.cap = 0;
    v.arr = nullptr;
    return *this;
  }

  reference at(size_type pos) {
    if (pos >= sz) {
      throw std::out_of_range(
        "Error: Accessing an inaccessible area of memory"
        );
    }
    return arr[pos];
  } 
  inline reference operator[](size_type pos) {return at(pos);}
  size_type capacity() { return cap; }

private:
  T* arr;
  size_type sz;
  size_type cap;
};

#endif