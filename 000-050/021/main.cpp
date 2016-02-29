// http://yukicoder.me/problems/67
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <vector>


int
main()
{
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int n, k;
  std::cin >> n >> k;
  std::vector<int> points(n);
  for (int i = 0; i < n; i++) {
    std::cin >> points[i];
  }
  auto mm = std::minmax_element(points.begin(), points.end());
  std::cout << (*mm.second - *mm.first) << std::endl;

  return EXIT_SUCCESS;
}
