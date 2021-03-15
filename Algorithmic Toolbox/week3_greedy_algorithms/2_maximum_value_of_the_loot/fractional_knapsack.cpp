#include <iostream>
#include <vector>
<<<<<<< HEAD

using std::vector;

int get_max_index(vector<int> weights, vector<int> values) {
    int max_i = 0;
    double max = 0;

    for (int i = 0; i < weights.size(); i++) {
        if (weights[i] != 0 && (double) values[i] / weights[i] > max) {
            max = (double) values[i] / weights[i];
            max_i = i;
        }
    }
    return max_i;
}

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
    double value = 0.0;

    for (int i = 0; i < weights.size(); i++) {
        if (capacity == 0) return value;
        int index = get_max_index(weights, values);
        int a = std::min(capacity, weights[index]);
        value += a * (double) values[index] / weights[index];
        weights[index] -= a;
        capacity -= a;
    }

    return value;
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
=======
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
>>>>>>> eecc4387e852d46461d27b9fddba0c632269b313
