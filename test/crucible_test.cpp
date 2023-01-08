#include <vector>

#include "gtest/gtest.h"

#include "subset.h"

TEST(AllSetTest, ABCTest) {
  auto example = subset::set_t{1, 2, 3};
  auto result = std::vector<subset::set_t>();
  subset::all_sets(example, [&result](auto &s) { result.push_back(s); });
  std::for_each(std::begin(result), std::end(result), [](auto &s) {
    std::for_each(std::begin(s), std::end(s), [](auto &c) { std::cout << c; });
    std::cout << std::endl;
  });
  // 1, 2, 3, 12, 13, 32, 123
  ASSERT_EQ(std::size(result), 15);
}

TEST(NonDivTest, Test1) {
  auto example = subset::set_t{1, 7, 2, 4};
  auto answer = subset::non_div_subset(example, 3);
  ASSERT_EQ(answer, 3);
}

TEST(NonDivTest, Test2) {
  auto example = subset::set_t{278, 576, 496, 727, 410, 124, 338, 149,
                               209, 702, 282, 718, 771, 575, 436};
  auto answer = subset::non_div_subset(example, 7);
  ASSERT_EQ(answer, 11);
}

TEST(NonDivTest, Test3) {
  auto example = subset::set_t{19, 10, 12, 10, 24, 25, 22};
  auto answer = subset::non_div_subset(example, 4);
  ASSERT_EQ(answer, 3);
}
