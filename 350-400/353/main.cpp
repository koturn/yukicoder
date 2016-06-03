#include <cstdlib>
#include <iostream>


int
main()
{
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int a, b;
  std::cin >> a >> b;
  std::cout << -(-a - b) << std::endl;

  return EXIT_SUCCESS;
}
