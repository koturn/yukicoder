// http://yukicoder.me/problems/111
#include <cstdlib>
#include <iostream>


int
main()
{
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  unsigned int d, p;
  std::cin >> d >> p;
  std::cout << static_cast<int>(d * (100 + p) / 100.0) << std::endl;

  return EXIT_SUCCESS;
}
