#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;
using std::max;

int compute_min_refills(int dist, int tank, vector<int> & stops) {
    int numReffils =0;
    int currentRefill =0;

    while(currentRefill <= tank){
        int lastRefill = currentRefill;
        while(currentRefill <= tank and stops[currentRefill +1] -stops[lastRefill] <= dist){
            currentRefill ++;

            if(currentRefill == lastRefill)
                return -1;
            
            if(currentRefill <= tank)
                numReffils ++;
        }
    }
    return numReffils;
}


int main() {
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;

    vector<int> stops(n);
    for (size_t i = 0; i < n; ++i)
        cin >> stops.at(i);

    cout << compute_min_refills(d, m, stops) << "\n";

    return 0;
}
