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
  const char *ptr = nptr;
  while (*ptr == ' ' || *ptr == '\t' || *ptr == '\n' || *ptr == '\r' || *ptr == '\v' ||
         *ptr == '\f') {
    ++ptr;
  }

  int sign = 1;
  if (*ptr == '+') {
    ++ptr;
  } else if (*ptr == '-') {
    sign = -1;
    ++ptr;
  }

  int result = 0;
  while (*ptr >= '0' && *ptr <= '9') {
    result = (result * 10) + ((*ptr) - '0');
    ++ptr;
  }

  return result * sign;
}

long atol(const char *nptr)
{
  const char *ptr = nptr;
  while (*ptr == ' ' || *ptr == '\t' || *ptr == '\n' || *ptr == '\r' || *ptr == '\v' ||
         *ptr == '\f') {
    ++ptr;
  }

  long sign = 1;
  if (*ptr == '+') {
    ++ptr;
  } else if (*ptr == '-') {
    sign = -1;
    ++ptr;
  }

  long result = 0;
  while (*ptr >= '0' && *ptr <= '9') {
    result = (result * 10) + ((*ptr) - '0');
    ++ptr;
  }

  return result * sign;
}

long long atoll(const char *nptr)
{
  const char *ptr = nptr;
  while (*ptr == ' ' || *ptr == '\t' || *ptr == '\n' || *ptr == '\r' || *ptr == '\v' ||
         *ptr == '\f') {
    ++ptr;
  }

  long long sign = 1;
  if (*ptr == '+') {
    ++ptr;
  } else if (*ptr == '-') {
    sign = -1;
    ++ptr;
  }

  long long result = 0;
  while (*ptr >= '0' && *ptr <= '9') {
    result = (result * 10) + ((*ptr) - '0');
    ++ptr;
  }

  return result * sign;
}

int abs(int n)
{
  return n < 0 ? -n : n;
}

long labs(long n)
{
  return n < 0 ? -n : n;
}

long long llabs(long long n)
{
  return n < 0 ? -n : n;
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
