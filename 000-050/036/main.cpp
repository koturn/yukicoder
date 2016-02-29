// http://yukicoder.me/problems/27
#include <cmath>
#include <cstdint>
#include <cstdlib>
#include <iostream>


static int
countFactors(std::uint64_t n);


int
main()
{
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  std::uint64_t n;
  std::cin >> n;
  std::cout << (countFactors(n) > 3 ? "YES" : "NO") << std::endl;

  return EXIT_SUCCESS;
}


static int
countFactors(std::uint64_t n)
{
  int cnt = 1;
  for (; n % 2 == 0; n /= 2, cnt++);
  for (std::uint64_t i = 3, iMax = static_cast<std::uint64_t>(std::sqrt(n)) + 2; i <= iMax; i += 2) {
    int subcnt = 0;
    for (; n % i == 0; n /= i, subcnt++);
    if (subcnt != 0) {
      cnt += subcnt;
      iMax = std::sqrt(n) + 2;
    }
  }
  if (n != 1) {
    cnt++;
  }
  return cnt;
}
