// http://yukicoder.me/problems/43
#include <cmath>
#include <cstdlib>
#include <iostream>


int
main()
{
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int a, b;
  std::cin >> a >> b;
  std::div_t d = std::div(b, a);
  std::cout << (d.quot + (d.rem != 0)) << std::endl;

  return EXIT_SUCCESS;
}
