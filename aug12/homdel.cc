/**
 * Solution to Home Delivery problem.
 *
 * URL: https://www.codechef.com/AUG12/problems/HOMDEL
 */

#include <iostream>
#include <algorithm>
#include <cmath>
 
using namespace std;
 
int main() {
    int N, M, S, G, D;
    cin >> N;
    
    int matrix[N][N];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> matrix[i][j];
        }
    }    
    
    // floyd-warshall
    for (int k = 0; k < N; k++)
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
    
    cin >> M;
    for (int i = 0; i < M; i++) {
        cin >> S >> G >> D;
        int delivery = matrix[S][G] + matrix[G][D];
        cout << delivery << " " << abs(matrix[S][D] - delivery) << endl;
    }
    
    return 0;
} 
