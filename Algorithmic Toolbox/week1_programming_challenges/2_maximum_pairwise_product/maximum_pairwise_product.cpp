#include <iostream>
#include <vector>
#include <algorithm>

int MaxPairwiseProduct(const std::vector<int>& numbers) {
    int max_product = 0;
    int n = numbers.size();

    for (int first = 0; first < n; ++first) {
        for (int second = first + 1; second < n; ++second) {
            max_product = std::max(max_product,
                numbers[first] * numbers[second]);
        }
    }

    return max_product;
}

long long MaxPairWiseProductSol(const std::vector<int>& numbers){
    long long ans;
    int len = numbers.size();
    int num_1_index = -1;
    int num_2_index = -1;
    for(int i =0; i < len; i++){
        if(numbers[num_1_index] < numbers[i] || num_1_index == -1){
            num_1_index = i;
        }
    }

    for(int i=0; i <len; i++){
        if((i != num_1_index) && ((numbers[num_2_index] < numbers[i] ) || (num_2_index == -1))){
            num_2_index = i;
        }
    }
    ans = numbers[num_1_index] * numbers[num_2_index];

    return ans;
}


int main() {
    int n;
    std::cin >> n;
    std::vector<int> numbers(n);
    std::vector<int> test{1,2,3,4,5,6};
    for (int i = 0; i < n; ++i) {
        std::cin >> numbers[i];
    }

   // std::cout << MaxPairwiseProduct(test)<< "\n";
    std::cout << MaxPairWiseProductSol(test);
    return 0;
}
