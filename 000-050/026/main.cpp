// http://yukicoder.me/problems/74
#include <cstdlib>
#include <algorithm>
#include <array>
#include <iostream>


int
main()
{
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int n, m;
  std::cin >> n >> m;
  std::array<bool, 3> cups;
  cups.fill(false);
  cups[n - 1] = true;
  for (int i = 0; i < m; i++) {
    int p, q;
    std::cin >> p >> q;
    std::swap(cups[p - 1], cups[q - 1]);
  }
  std::cout << (std::distance(cups.begin(), std::find(cups.begin(), cups.end(), true)) + 1) << std::endl;

  return EXIT_SUCCESS;
}
