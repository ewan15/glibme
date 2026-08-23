#include "glibme.hpp"

namespace glibme {

bool isalpha(int c)
{
  return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

bool isdigit(int c)
{
  return c >= '0' && c <= '9';
}

bool isalnum(int c)
{
  return isalpha(c) || isdigit(c);
}

bool isspace(int c)
{
  return c == ' ' || c == '\f' || c == '\n' || c == '\r' || c == '\t' || c == '\v';
}

bool isxdigit(int c)
{
  return isdigit(c) || (c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F');
}

bool isprint(int c)
{
  return c >= ' ' && c <= '~';
}

int tolower(int c)
{
  if (c >= 'A' && c <= 'Z')
    c = c + ('a' - 'A');
  return c;
}

int toupper(int c)
{
  if (c >= 'a' && c <= 'z')
    c = c - ('a' - 'A');
  return c;
}

} // namespace glibme
