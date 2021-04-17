#include "signed_overflow.hpp"

// Seacord, Robert C., The CERT C Coding Standard
bool additionWillOverflow(int first, int second)
{
  bool second_positive = second > 0;
  bool second_negative = second < 0;

  if ((second_positive && (first > (INT_MAX - second))) || (second_negative && (first < (INT_MIN - second))))
    return true;
  return false;
}

// Fridtun, Dag, TurtleSec
bool additionWillOverflow(int first, int second)
{
  long long f = first, s = second;
  return s + f > INT_MAX || s + f < INT_MIN;
}
