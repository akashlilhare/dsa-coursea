<<<<<<< HEAD
#include <bits/stdc++.h>
using namespace std;

// bool cmp(pair<int,int> f, pair<int,int> s){
//   return f.first > 
// }

long long max_dot_product(vector<int> a, vector<int> b) {
  vector<pair<int,int>> pair;
  int n = a.size();

  // for(int i=0; i<n; i++){
  //   pair.push_back(make_pair(a[i],b[i]));
  // }

  // sort(pair.begin(), pair.end(), cmp);

  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  
=======
#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

long long max_dot_product(vector<int> a, vector<int> b) {
  // write your code here
>>>>>>> eecc4387e852d46461d27b9fddba0c632269b313
  long long result = 0;
  for (size_t i = 0; i < a.size(); i++) {
    result += ((long long) a[i]) * b[i];
  }
  return result;
}

int main() {
  size_t n;
  std::cin >> n;
  vector<int> a(n), b(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  for (size_t i = 0; i < n; i++) {
    std::cin >> b[i];
  }
  std::cout << max_dot_product(a, b) << std::endl;
}
