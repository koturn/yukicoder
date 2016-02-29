#include <cmath>
#include <cstdlib>
#include <iostream>


int
main()
{
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int n;
  std::cin >> n;

  std::string::size_type cnt1 = 0, cnt2 = 0;
  for (int i = 0; i < n; i++) {
    std::string::size_type t;
    std::string s;
    std::cin >> t >> s;
    std::string::size_type nType = static_cast<std::string::size_type>(std::floor(12 * t / 1000));
    if (nType < s.length()) {
      cnt1 += nType;
      cnt2 += s.length() - nType;
    } else {
      cnt1 += s.length();
    }
  }
  std::cout << cnt1 << ' ' << cnt2 << std::endl;

  return EXIT_SUCCESS;
}
