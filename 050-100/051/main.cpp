// http://yukicoder.me/problems/100
#include <cstdint>
#include <cstdlib>
#include <iostream>


int
main()
{
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  std::int64_t w, d;
  std::cin >> w >> d;
  for (; d > 1; d--) {
    w -= w / (d * d);
  }
  std::cout << w << std::endl;

  return EXIT_SUCCESS;
}
