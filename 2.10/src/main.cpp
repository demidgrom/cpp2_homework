#include <cassert>
#include <ranges>
#include <vector>

#include "sort.hpp"

int main() {
  auto size = 1uz << 10;

  //  ---------------------------------------

  std::vector<int> vector(size, 0);

  //  ---------------------------------------

  for (auto i = 0uz; i < size; ++i) {
    vector[i] = size - i;
  }

  //  ---------------------------------------

  sort(vector);

  //  ---------------------------------------
}
