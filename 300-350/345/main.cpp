#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <string>
#include <stack>


int
main()
{
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  std::string s;
  std::cin >> s;

  std::stack<std::string::size_type> wposStack;
  std::string::size_type minLen = std::numeric_limits<std::string::size_type>::max();
  for (std::string::size_type i = s.length() - 1; i != static_cast<std::string::size_type>(-1); i--) {
    switch (s[i]) {
      case 'c':
        if (wposStack.size() > 1) {
          wposStack.pop();
          minLen = std::min(minLen, wposStack.top() - i + 1);
          wposStack.pop();
        }
        break;
      case 'w':
        wposStack.push(i);
        break;
    }
  }
  if (minLen == std::numeric_limits<std::string::size_type>::max()) {
    std::cout << -1 << std::endl;
  } else {
    std::cout << minLen << std::endl;
  }

  return EXIT_SUCCESS;
}
