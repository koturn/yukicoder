// http://yukicoder.me/problems/14 #include <cstdlib>
#include <algorithm>
#include <iostream>
#include <vector>


int
main()
{
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int len, n;
  std::cin >> len >> n;
  std::vector<int> blockWidths;
  for (int i = 0; i < n; i++) {
    int w;
    std::cin >> w;
    blockWidths.emplace_back(w);
  }
  std::sort(blockWidths.begin(), blockWidths.end());

  int sum = 0;
  decltype(blockWidths)::size_type i = 0;
  for (; i < blockWidths.size() && (sum += blockWidths[i]) <= len; i++);
  std::cout << i << std::endl;

  return EXIT_SUCCESS;
}
