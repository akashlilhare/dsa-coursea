#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<int> optimal_summands(int n) {
  vector<int> summands;
  
  if(n<=2){
    summands.push_back(n);
    return summands;
  }

  int k = static_cast<int>(floor(sqrt(n)));

  while(k *(k+1)/2 <=n){
    k++;
  }

  k--;
  summands.reserve(k);
  for(int i=1; i<=k; i++){
    if(i == k){
      summands.push_back(n);
    }else{
      n -= i;
      summands.push_back(i);
    }
  }
  return summands;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> summands = optimal_summands(n);
  std::cout << summands.size() << '\n';
  for (size_t i = 0; i < summands.size(); ++i) {
    std::cout << summands[i] << ' ';
  }
}
