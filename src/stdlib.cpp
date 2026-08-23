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

int atoi(const char *nptr)
{
  (void)nptr;
  return 0;
}

long atol(const char *nptr)
{
  (void)nptr;
  return 0;
}

long long atoll(const char *nptr)
{
  (void)nptr;
  return 0;
}

int abs(int n)
{
  (void)n;
  return 0;
}

long labs(long n)
{
  (void)n;
  return 0;
}

long long llabs(long long n)
{
  (void)n;
  return 0;
}

div_t div(int numer, int denom)
{
  return {numer / denom, numer % denom};
}

ldiv_t ldiv(long numer, long denom)
{
  return {numer / denom, numer % denom};
}

lldiv_t lldiv(long long numer, long long denom)
{
  return {numer / denom, numer % denom};
}

} // namespace glibme
