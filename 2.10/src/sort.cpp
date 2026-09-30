#include "sort.hpp"

int MedianOfThree(int first, int middle, int last) {
  if (first < middle) {
    if (middle < last) {
      return middle;
    }

    return first < last ? last : first;
  }

  if (first < last) {
    return first;
  }

  return middle < last ? last : middle;
}

std::size_t Partition(std::vector<int>& array, std::size_t left,
                      std::size_t right) {
  const auto middle = left + (right - left - 1) / 2;

  const auto pivot =
      MedianOfThree(array[left], array[middle], array[right - 1]);

  auto lhs = left;
  auto rhs = right - 1;

  while (true) {
    while (array[lhs] < pivot) {
      ++lhs;
    }

    while (array[rhs] > pivot) {
      --rhs;
    }

    if (lhs >= rhs) {
      return rhs;
    }

    std::swap(array[lhs], array[rhs]);

    ++lhs;
    --rhs;
  }
}

void QuickSort(std::vector<int>& array, std::size_t left, std::size_t right) {
  if (right - left <= 1) {
    return;
  }

  const auto split = Partition(array, left, right);

  QuickSort(array, left, split + 1);
  QuickSort(array, split + 1, right);
}

void sort(std::vector<int>& array) { QuickSort(array, 0, array.size()); }