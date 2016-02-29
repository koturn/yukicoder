// http://yukicoder.me/problems/89
#include <cstdlib>
#include <iostream>


int
main()
{
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int n;
  std::cin >> n;
  int m = 1, cnt = 0;
  for (; m < n; m *= 2) {
    cnt++;
  }
  std::cout << cnt << std::endl;

  return EXIT_SUCCESS;
}
