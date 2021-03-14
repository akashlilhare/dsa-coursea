#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

int get_majority_element(vector<int> &a, int left, int right) {
  if (left == right) return -1;
  if (left + 1 == right) return a[left];
  
  sort(a.begin(), a.end());
  int mid = (left + right)/2;
  int max_occ = a[mid];
  int count =0;

  for(int i=0; i<right; i++){
    if(a[i] == max_occ)
      count++;
  }
  if(count > right/2){
      return 1;
    }
  return -1;
}



int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  std::cout << (get_majority_element(a, 0, a.size()) != -1) << '\n';
}
