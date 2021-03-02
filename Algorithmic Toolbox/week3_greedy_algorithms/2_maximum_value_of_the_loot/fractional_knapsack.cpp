#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

using std::vector;

bool cmp(pair<int,int> a, pair<int,int> b){
  double r1 = a.second / a.first;
  double r2 = b.second / b.first;

  return r1 > r2;
}

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {

  int n = weights.size();
  vector<pair<int,int>> itemPair;

  for(int i=0; i< n; i++)
    itemPair.push_back(make_pair(weights[i], values[i]));

  sort(itemPair.begin(), itemPair.end(), cmp);

  //for(int i=0; i<n; i++)
    //cout<<itemPair[i].second/itemPair[i].first<<"\t"<<"("<<itemPair[i].first<<","<<itemPair[i].second<<")"<<endl;
  
  double weight =0.0;
  double price = 0.0;

  for(int i=0; i<n; i++){
    if(itemPair[i].first+weight <= capacity){
      price += itemPair[i].second;
      weight += (double)itemPair[i].first;
    }else{
      int remain = capacity - weight;
      price  = price + (double)itemPair[i].second * remain;
      break;
    }
  }

  return price;
}

int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}
