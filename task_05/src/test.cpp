#include <gtest/gtest.h>

#include <numeric>

#include "quick_sort.hpp"

TEST(Quick_Sort, Simple) {
  std::vector<int> vec1{9, 8, 7, 6, 5, 4, 2, 3, 1, 0};
  ASSERT_EQ(QuickSort(vec1), (std::vector<int>{0, 1, 2, 3, 4, 5, 6, 7, 8, 9}));
  std::vector<int> vec2{10, 90, 30, 80, 60, 50};
  ASSERT_EQ(QuickSort(vec2), (std::vector<int>{10, 30, 50, 60, 80, 90}));
  std::vector<int> vec3{12,  43,  15, 26, -1233, 346, 1325,
                        -56, -12, 78, 0,  3345,  -34};
  ASSERT_EQ(QuickSort(vec3), (std::vector<int>{-1233, -56, -34, -12, 0, 12, 15,
                                               26, 43, 78, 346, 1325, 3345}));
  vec3.push_back(-10);
  vec3.push_back(1000);
  vec3.push_back(5);
  ASSERT_EQ(QuickSort(vec3),
            (std::vector<int>{-1233, -56, -34, -12, -10, 0, 5, 12, 15, 26, 43,
                              78, 346, 1000, 1325, 3345}));
}

TEST(Quick_Sort, EmptyVector) {
  std::vector<int> vec;
  ASSERT_EQ(QuickSort(vec), (std::vector<int>{}));
}

TEST(Quick_Sort, SingleElement) {
  std::vector<int> vec{1};
  ASSERT_EQ(QuickSort(vec), (std::vector<int>{1}));
}

TEST(Quick_Sort, RepeatedElements) {
  std::vector<int> vec{5, 5, 5, 5};
  ASSERT_EQ(QuickSort(vec), (std::vector<int>{5, 5, 5, 5}));
}

TEST(Quick_Sort, MixedNumbers) {
  std::vector<int> vec{-1, 3, -2, 5, 4, -3};
  ASSERT_EQ(QuickSort(vec), (std::vector<int>{-3, -2, -1, 3, 4, 5}));
}

TEST(Quick_Sort, AlreadySorted) {
  std::vector<int> vec{1, 2, 3, 4, 5};
  ASSERT_EQ(QuickSort(vec), (std::vector<int>{1, 2, 3, 4, 5}));
}

TEST(Quick_Sort, ReverseOrder) {
  std::vector<int> vec{5, 4, 3, 2, 1};
  ASSERT_EQ(QuickSort(vec), (std::vector<int>{1, 2, 3, 4, 5}));
}

TEST(Quick_Sort, ZerosAndNegatives) {
  std::vector<int> vec{0, -1, 0, -2, 0, -3};
  ASSERT_EQ(QuickSort(vec), (std::vector<int>{-3, -2, -1, 0, 0, 0}));
}

TEST(Quick_Sort, LargeArray) {
  std::vector<int> vec(1000);
  std::iota(vec.begin(), vec.end(), -500);
  std::random_shuffle(vec.begin(), vec.end());
  std::vector<int> sorted_vec(vec);
  std::sort(sorted_vec.begin(), sorted_vec.end());
  ASSERT_EQ(QuickSort(vec), sorted_vec);
}
