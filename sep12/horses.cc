/**
 * Solution to Racing Horses.
 *
 * URL: https://www.codechef.com/viewsolution/1333933
 */

#include <iostream>
#include <cmath>
#include <set>
#include <limits>
 
using namespace std;
 
int main() {
    int T, N;
    long long int s;
    cin >> T;
    for (int t = 0; t < T; t++) {
        cin >> N;
        set<long long int> S;
        for (int n = 0; n < N; n++) {
            cin >> s;
            S.insert(s);
        }
        
        if (S.size() < N) {
            cout << 0 << endl;
            continue;
        }
        else {
            long long int diff = numeric_limits<long long int>::max();
            long long int prev = -1;
            for (set<long long int>::iterator iter = S.begin() ; iter != S.end(); ++iter) {
                if (prev == -1) prev = *iter;
                else if (diff > *iter - prev) diff = *iter - prev;
                prev = *iter;
            }
            cout << diff << endl;
        }
    }
    return 0;
} 
