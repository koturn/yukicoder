// http://yukicoder.me/problems/987
#include <cstdint>
#include <cstdlib>
#include <iostream>
#include <string>


int
main()
{
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  std::string s;
  std::cin >> s;
  std::uint64_t cnt = 0, wcnt = 0;
  for (std::string::size_type i = s.length() - 1; i != static_cast<std::string::size_type>(-1); i--) {
    switch (s[i]) {
      case 'c':
        cnt += wcnt * (wcnt - 1) / 2;
        break;
      case 'w':
        wcnt++;
        break;
    }
  }
  std::cout << cnt << std::endl;

  return EXIT_SUCCESS;
}
