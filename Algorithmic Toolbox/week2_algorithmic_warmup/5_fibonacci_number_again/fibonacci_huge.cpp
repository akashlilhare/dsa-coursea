#include <iostream>
#include <vector>
typedef long long int ll;

long long get_fibonacci_huge_naive(long long n, long long m) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % m;
}

ll Periodic(ll m){
    ll a=0, b=1, c=a+b;
    for(int i=0; i<m*m; i ++){
        c =(a+b) %m;
        a =b;
        b =c;
        if(a ==0 and b ==1)
            return i+1;
    }
}

int solve(ll n, ll m){
    long long remainder = n %Periodic(m);
    long long first =0;
    long long second =1;
    long long res =remainder;
    for(int i=1; i<remainder; i++){
        res = (first + second) %m;
        first = second;
        second = res;
    }
    return res %m;
}



int main() {
    long long n, m;
    std::cin >> n >> m;
    //std::cout << get_fibonacci_huge_naive(n, m) << '\n';
    std::cout << solve(n,m);
    return 0;
}