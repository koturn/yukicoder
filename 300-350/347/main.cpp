// http://yukicoder.me/problems/836
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>


static double
differential(int b, const std::vector<double>& as);

static double
integral(int b, const std::vector<double>& as);

static constexpr double EPS = 1.0e-9;


int
main()
{
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int n, b;
  std::cin >> n >> b;
  std::vector<double> as(n);
  for (auto& a : as) {
    std::cin >> a;
  }
  std::cout << std::fixed << std::setprecision(4)
            << differential(b, as) << '\n'
            << integral(b, as) << std::endl;

  return EXIT_SUCCESS;
}


static double
differential(int b, const std::vector<double>& as)
{
  double sum = 0.0;
  for (const auto& a : as) {
    sum += a * std::pow(b, a - 1);
  }
  return sum;
}


static double
integral(int b, const std::vector<double>& as)
{
  double sum = 0.0;
  for (const auto& a : as) {
    sum += std::abs(a + 1.0) < EPS ? std::log(b) : std::pow(b, a + 1) / (a + 1);
  }
  return sum;
}
