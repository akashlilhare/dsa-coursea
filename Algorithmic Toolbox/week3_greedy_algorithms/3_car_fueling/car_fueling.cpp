#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;
using std::max;

int compute_min_refills(int dist, int tank, vector<int> & stops) {
    int min_reffils = 0;
    int cand =0;
    int curr = 0;
    int n = stops.size();

    for(int i=1; i<n; i++){
        if(stops[i] - stops[i-1] > tank 
            || stops[0] > tank 
            || dist - stops[n-1] > tank )
            return -1;
    }

    for(int i=1; i<n; i++){
        if(i == n-1){
            if((dist - curr) <= tank)
                return min_reffils;
            else if ((stops[i] - curr) <= tank)
                return min_reffils + 1;
            else{
                min_reffils += 1;
                curr = stops[i-1];
                i --;
                continue;
            }
        }else if((stops[i] - curr) <= tank){
            cand = stops[i];
        } else{
            min_reffils += 1;
            curr = cand;
            i --;
        }
    }
    return min_reffils;
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
