#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

using std::vector;
using std::string;

bool cmp(int a, int b){
  return a>b;
}

string largest_number(vector<string> a) {
	std::stringstream ret;
	std::sort(a.begin(), a.end(), [](const string& a, const string& b) {
		return (a + b) < (b + a);
	});
	std::reverse(a.begin(), a.end());

	for (auto&& i : a) { ret << i; }
	string result;
	ret >> result;
	return result;
}

// string largest_number(vector<string> a) {
//   int n = a.size();
//   cout<<n<<endl;
//   vector<int> number;

//   for(int i=0; i<n; i++){
//     number.push_back(stoi(a[i]));
//   }

//   for(int i : number){
//     cout<<i<<"\t";
//   }
  
//   sort(number.begin(), number.end(), cmp);
//   cout<<endl;
//    for(int i : number){
//     cout<<i<<"\t";
//   }
  
//    string result ="";

//   for(int i=0; i<n; i++){
//     string curr = to_string(number[i]);
//   //  result += curr;
//   }

//   return result;
//  }

int main() {
  int n;
  std::cin >> n;
  vector<string> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  std::cout << largest_number(a);
}
