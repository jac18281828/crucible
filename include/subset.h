#pragma once

#include <algorithm>
#include <functional>
#include <vector>

namespace subset {

using set_t = std::vector<int>;
using set_size_t = set_t::size_type;
using visitor_t = std::function<void(set_t const &)>;

// 1 2 3
// 1 2 3 12 13 23 123
inline void all_sets(
    set_t const &set, visitor_t visitor,
    std::function<bool(set_t)> filter = [](auto const &) { return true; },
    set_size_t index = 0, set_t init_set = set_t()) {
  if (index < std::size(set) && filter(init_set)) {
    auto begin = std::begin(set);
    std::advance(begin, index);
    for (; begin != std::end(set); ++begin) {
      auto working_set = set_t(init_set);
      if (std::find(std::begin(working_set), std::end(working_set), *begin) ==
          std::end(working_set)) {
        working_set.push_back(*begin);
        visitor(working_set);
        all_sets(set, visitor, filter, index + 1, working_set);
      }
    }
  }
}

inline bool sum_not_divisible(set_t const &set, const int k) {
  auto mod_val_map = std::vector<int>(k);
  for (const auto &element : set) {
    const auto d = element % k;
    mod_val_map[d]++;
    // case 2 numbers divide by k - the sum also divides
    if (mod_val_map[0] > 1) {
      return false;
    }
    // 2 numbers sum to k
    for (auto j = 0; j < k / 2; ++j) {
      if (mod_val_map[j] > 1 && mod_val_map[k - j - 1] > 1) {
        return false;
      }
    }
    if (((k % 2) == 0) && (mod_val_map[k / 2] > 1)) {
      return false;
    }
  }
  return true;
}

inline set_t::size_type non_div_subset(set_t const &set, const int k) {

  const auto is_ndiv_set = [k](set_t const &set) -> bool {
    return sum_not_divisible(set, k);
  };

  set_size_t max_set_size = 0U;
  all_sets(
      set,
      [&max_set_size, set, k](set_t const &possible) {
        if (std::size(possible) > 1 && sum_not_divisible(possible, k)) {
          max_set_size = std::max(max_set_size, std::size(possible));
        }
      },
      is_ndiv_set);
  return max_set_size;
}

} // namespace subset