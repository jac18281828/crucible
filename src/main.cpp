#include <iostream>

#include "subset.h"

int main(int argc, char *argv[]) {
  (void)argc;
  (void)argv;

  int n_array, k;
  std::cin >> n_array >> k;
  auto in_set = subset::set_t();
  for (int i = 0; i < n_array; ++i) {
    int r;
    std::cin >> r;
    in_set.push_back(r);
  }

  const auto answer = subset::non_div_subset(in_set, k);

  std::cout << answer << std::endl;
  return 0;
}