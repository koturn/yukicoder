#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>


int
main()
{
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int n;
  std::cin >> n;
  std::unordered_map<std::string, int> etoMap;
  for (int i = 0; i < n; i++) {
    std::string a;
    std::cin >> a;
    etoMap[a]++;
  }
  auto itr = std::find_if(
      etoMap.begin(),
      etoMap.end(),
      [&](const decltype(etoMap)::value_type& e) {
        return e.second > (n + 1) / 2;
      });
  std::cout << (itr == etoMap.end() ? "YES" : "NO") << std::endl;

  return EXIT_SUCCESS;
}
