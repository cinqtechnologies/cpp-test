#include <iostream>
#include <tuple>

// There are lots of algorithms for fibonacci
// The chosen one is O(log n) and is better for high N
// However, dynamic programming is faster for low N

using namespace std;

using tuplell = tuple<uint64_t, uint64_t>;

tuplell fib(const uint64_t n) {
  if (n <= 0) {
    return tuplell(0, 1);
  }
  const auto [a, b] = fib(n >> 1);
  const auto c = a * ((b << 1) - a);
  const auto d = (a * a) + (b * b);
  return (n & 1) ? tuplell(d, c + d) : tuplell(c, d);
}

int main(int argc, char **argv) {
  uint64_t N = 0;
  cin >> N;
  const auto [a, b] = fib(N);
  cout << a << endl;
  return 0;
}
