// http://yukicoder.me/problems/1
#include <cstdlib>
#include <array>
#include <iostream>


int
main()
{
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int n;
  std::cin >> n;

  std::array<int, 10> items{0};
  for (int i = 0; i < n; i++) {
    int a, b, c;
    std::cin >> a >> b >> c;
    items[a - 1]++;
    items[b - 1]++;
    items[c - 1]++;
  }
  int cnt = 0, rems = 0;
  for (auto&& e : items) {
    cnt += e / 2;
    rems += (e %= 2);
  }
  cnt += rems / 4;
  std::cout << cnt << std::endl;

  return EXIT_SUCCESS;
}
