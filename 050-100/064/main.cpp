// http://yukicoder.me/problems/119
#include <cstdint>
#include <cstdlib>
#include <array>
#include <iostream>

static constexpr int MOD = 3;


int
main()
{
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  std::array<std::uint64_t, MOD> fs;
  std::uint64_t n;
  std::cin >> fs[0] >> fs[1] >> n;
  fs[2] = fs[1] ^ fs[0];
  std::cout << fs[n % MOD] << std::endl;

  return EXIT_SUCCESS;
}
