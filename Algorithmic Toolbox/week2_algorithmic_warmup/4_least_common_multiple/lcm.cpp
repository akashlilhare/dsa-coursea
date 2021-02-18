#include <iostream>

long long lcm_naive(int a, int b) {
  for (long l = 1; l <= (long long) a * b; ++l)
    if (l % a == 0 && l % b == 0)
      return l;

  return (long long) a * b;
}

long long gcd(int a, int b){
  if(a == 0)
    return b;
  if(b == 0)
    return a;
  if(a > b)
    return gcd(a%b, b);
  else 
    return gcd(a, b%a);
}

long long lcm_fast(int a, int b){
  long long pro = (long long) a*b ;
  return (long long) (pro/gcd(a,b));
}

int main() {
  int a, b;
  std::cin >> a >> b;
  //std::cout << lcm_naive(a, b) << std::endl;
  std::cout<<lcm_fast(a, b);
  return 0;
}
