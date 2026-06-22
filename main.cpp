#include <iostream>
#include <vector>

std::vector<int> merge(std::vector<int> &left, std::vector<int> &right) {
  // pointer to first element in each list
  // compare elements, lower value is emplaced and pointer moves until pointer
  // is at end
  std::vector<int> res{};
  auto l{left.begin()};
  auto r{right.begin()};
  while (l != left.end() && r != right.end()) {
    if (*l < *r) {
      res.emplace_back(*l);
      ++l;
    } else {
      res.emplace_back(*r);
      ++r;
    }
  }
  if (l == left.end()) {
    while (r != right.end()) {
      res.emplace_back(*r);
      ++r;
    }
  } else {
    while (l != left.end()) {
      res.emplace_back(*l);
      ++l;
    }
  }
  return res;
}

std::vector<int> merge_sort(std::vector<int> &v) {
  // splits vector into two vectors
  // recursively sorts each half
  // returns vector
  if (v.size() <= 1) {
    return v;
  }
  auto middle{v.begin() + v.size() / 2};
  std::vector<int> left{v.begin(), middle};
  std::vector<int> right{middle, v.end()};
  left = merge_sort(left);
  right = merge_sort(right);

  return merge(left, right);
}

void print_list(std::vector<int> &v) {
  for (auto &i : v) {
    std::cout << i << ' ';
  }
  std::cout << '\n';
}

int main() {
  std::vector<int> v{6, 4, 36, 2, 9, 5, 78, 1, 7, 13, 20, 8};
  std::cout << "List before sorting: ";
  print_list(v);
  v = merge_sort(v);
  std::cout << "List after sorting: ";
  print_list(v);
  return 0;
}
