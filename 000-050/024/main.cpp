// http://yukicoder.me/problems/69
#include <cstdlib>
#include <array>
#include <iostream>

#ifdef __GNUC__
#  define popcnt(n)  __builtin_popcount(n)
#else
static unsigned int
popcnt(unsigned int n)
{
  unsigned int cnt = 0;
  while (n != 0) {
    cnt += (n & 0x01);
    n >>= 1;
  }
}
#endif


static std::size_t
bsf(unsigned int n)
{
  for (std::size_t i = 0, len = sizeof(n) * 3; i < len; i++, n >>= 1) {
    if ((n & 0x01) == 0x01) {
      return i;
    }
  }
  return -1;
}


static const int MASK = 0x03ff;


int
main()
{
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int n;
  std::cin >> n;
  int candidateBit = MASK;
  for (int i = 0; popcnt(candidateBit) != 1 && i < n; i++) {
    std::array<int, 4> ns;
    std::string result;
    std::cin >> ns[0] >> ns[1] >> ns[2] >> ns[3] >> result;
    int n = ((1 << ns[0]) | (1 << ns[1]) | (1 << ns[2]) | (1 << ns[3]));
    candidateBit &= result == "YES" ? n : (~n & MASK);
  }
  std::cout << bsf(candidateBit) << std::endl;

  return EXIT_SUCCESS;
}
