/**
 * Solution to Fierce Battles.
 *
 * URL: https://www.codechef.com/OCT12/problems/DRGNBOOL/
 */

#include <iostream>
#include <map>
 
using namespace std;
 
int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        int N, M;    
        cin >> N >> M;
        map<int, int> soints, sofloats;
        int C, L;
        for (int n = 0; n < N; n++) {
            cin >> C >> L;
            soints[L] += C;
        }
        
        for (int m = 0; m < M; m++) {
            cin >> C >> L;
            sofloats[L] += C;
        }        
        
        // compute
        int needed = 0;
        for (map<int, int>::iterator iter = soints.begin(); iter != soints.end(); iter++) {
            int l = (*iter).first, intc = soints[l], floatc = sofloats[l];
            if (intc < floatc) needed += floatc - intc;
        }
        
        cout << needed << endl;
    }
    
    
    return 0;
} 
