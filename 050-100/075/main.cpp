#include <cmath>
#include <cstdlib>
#include <array>
#include <iostream>

static const std::array<int, 4> DX{1, 0, -1, 0};
static const std::array<int, 4> DY{0, 1, 0, -1};


int
main()
{
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  std::array<int, 2> goalPos;
  int l;
  std::cin >> goalPos[0] >> goalPos[1] >> l;

  int angle = 1;
  std::array<int, 2> curPos{0, 0};
  std::array<int, 2> diff;
  diff[0] = goalPos[0] - curPos[0];
  diff[1] = goalPos[1] - curPos[1];

  int cnt = 0;
  for (; diff[0] != 0 || diff[1] != 0; diff[0] = goalPos[0] - curPos[0], diff[1] = goalPos[1] - curPos[1]) {
    int d = (diff[0] * DX[angle]) + (diff[1] * DY[angle]);
    if (d > 0) {
      std::div_t divres = std::div(d, l);
      cnt += divres.quot + (divres.rem != 0);
      int idx = angle % 2;
      curPos[idx] = goalPos[idx];
    } else if (d < 0) {
      angle = (angle + 1) % DX.size();
      cnt++;
    }
  }
  std::cout << cnt << std::endl;

  return EXIT_SUCCESS;
}
