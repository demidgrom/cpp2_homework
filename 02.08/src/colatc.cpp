#include <print>
#include <vector>

using ull = unsigned long long int;

std::size_t collatz(ull n, std::vector<std::size_t>& lengths) {
  if (n >= lengths.size()) {
    lengths.resize(n + 1);
  }

  if (lengths[n] == 0)
    lengths[n] = 1 + collatz(((n % 2) == 1) ? (3 * n) + 1 : (n / 2), lengths);

  return lengths[n];
}

int main() {
  std::vector<std::size_t> lengths(2, 0);
  lengths[1] = 1;

  std::size_t maxLength = 0;
  ull bestStart = 1;

  for (ull i = 1; i <= 1000; ++i) {
    auto length = collatz(i, lengths);

    if (length > maxLength) {
      maxLength = length;
      bestStart = i;
    }
  }

  std::print("len: {}, start: {}\n", maxLength, bestStart);
}