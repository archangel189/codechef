/**
 * Solutions to Little Elephant and Bombs.
 *
 * URL: https://www.codechef.com/AUG12/problems/LEBOMBS/
 */

#include <iostream>
 
using namespace std;
 
int main() {
    int T, N;
    string S;
    
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> N;
        int buildings[N];
        cin >> S;
        int count = 0;
        for (int j = 0; j < N; j++) {
            if (j == 0) {
                if (N < 2) {
                    if (S[j] == '0') {
                        count++;
                    }
                }
                else if (S[j] == '0' && S[j+1] == '0') {
                    count++;
                }
            }
            else if (j == N-1) {
                if (S[j] == '0' && S[j-1] == '0') {
                    count++;
                }
            }
            else if (S[j] == '0' && S[j-1] == '0' && S[j+1] == '0') {
                count++;
            }
        }
        
        cout << count << endl;
    }
    
    return 0;
} 
