// http://yukicoder.me/problems/59
#include <cstdlib>
#include <iostream>
#include <string>

static constexpr int N_ALPHABET = 'z' - 'a' + 1;


int
main()
{
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  std::string s;
  std::cin >> s;
  for (std::string::size_type i = 0; i < s.length(); i++) {
    s[i] = static_cast<char>('A' + ((s[i] - 'A') + (N_ALPHABET - (i + 1) % N_ALPHABET)) % N_ALPHABET);
  }
  std::cout << s << std::endl;

  return EXIT_SUCCESS;
}
