#include "glibme.hpp"

namespace glibme {
namespace {
unsigned int rand_state = 1;
}

int rand(void)
{
  rand_state = rand_state * 123123871u + 12312u;
  return static_cast<int>((rand_state >> 1) & 0x7fffffff);
}

void srand(unsigned int seed)
{
  rand_state = seed;
}

} // namespace glibme
