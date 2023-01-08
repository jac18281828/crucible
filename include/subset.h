#pragma once

#include <algorithm>
#include <functional>
#include <unordered_set>
#include <vector>

namespace subset {

using set_t = std::vector<int>;
using set_size_t = set_t::size_type;
using visitor_t = std::function<void(set_t const &)>;
// 1 2 3
// 1 2 3 12 13 23 123
inline void all_sets(set_t const &set, visitor_t visitor, set_size_t index = 0,
                     set_t init_set = set_t()) {
  if (index < std::size(set)) {
    auto begin = std::begin(set);
    std::advance(begin, index);
    for (; begin != std::end(set); ++begin) {
      auto working_set = set_t(init_set);
      if (std::find(std::begin(working_set), std::end(working_set), *begin) ==
          std::end(working_set)) {
        working_set.push_back(*begin);
        visitor(working_set);
        all_sets(set, visitor, index + 1, working_set);
      }
    }
  }
}

inline bool has_divisible_sum(set_t const &set, const int k) {
  for (const auto &elei : set) {
    for (const auto &elej : set) {
      if (elei != elej && ((elei + elej) % k) == 0) {
        return true;
      }
    }
  }
  return false;
}

inline set_t::size_type non_div_subset(set_t const &set, const int k) {
  set_size_t max_set_size = 0U;
  all_sets(set, [&max_set_size, set, k](set_t const &possible) {
    if (!has_divisible_sum(possible, k)) {
      max_set_size = std::max(max_set_size, std::size(possible));
    }
  });
  return max_set_size;
}

} // namespace subset