/**
 * Solution to Coin Flip problem.
 *
 * URL: https://www.codechef.com/viewsolution/1504703
 */

#include <iostream>
 
using namespace std;
 
int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        int G;
        cin >> G;
        for (int g = 0; g < G; g++) {
            int I, N, Q;
            cin >> I >> N >> Q;
            if (I == Q) {
                cout << N/2 << endl;
            }
            else {
                cout << (N%2==0 ? N/2 : N/2+1) << endl;
            }
        }
    }
    
    return 0;
} 
