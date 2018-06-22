/**
 * Solution to Magic Rankings.
 *
 * URL: https://www.codechef.com/DEC12/problems/MGCRNK/
 */
#include <iostream>
#include <algorithm>
#include <cstdio>
 
using namespace std;
 
int main() {
    int T;
    cin >> T;
    
    for (int t = 0; t < T; t++) {
        int N;
        cin >> N;
        
        int S[N][N];
        long int X[N][N];
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cin >> S[i][j];
            }
        }
        
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (i == 0 && j == 0) {
                    X[i][j] = 0;
                }
                else if (i == 0) {
                    X[i][j] = X[i][j-1] + S[i][j];
                }
                else if (j == 0) {
                    X[i][j] = X[i-1][j] + S[i][j];
                }
                else {
                    X[i][j] = max(X[i-1][j] + S[i][j], X[i][j-1] + S[i][j]);
                }
            }
        }
        
        if (X[N-1][N-1] < 0) {
            cout << "Bad Judges" << endl;
        }
        else {
            float avg = (float) X[N-1][N-1] / (float) (N+N-3);
            printf("%f\n", avg);
        }
    }
    
    return 0;
} 
