/**
 * Solution to Granama Recipes.
 *
 * URL: https://www.codechef.com/DEC12/problems/GRANAMA/
 */

#include <iostream>
#include <set>
 
using namespace std;
 
int main() {
    int T;
    cin >> T;
    
    for (int t = 0; t < T; t++) {
        string R, S;
        set<char> cr, cs;
        multiset<char> rr, rs;
        cin >> R >> S;
        
        for (int r = 0; r < R.size(); r++) {
            cr.insert(R[r]);
            rr.insert(R[r]);
        }
        
        for (int r = 0; r < S.size(); r++) {
            cs.insert(S[r]);
            rs.insert(S[r]);
        }
        
        bool chef = (cr == cs) ? true : false;
        bool real = (rr == rs) ? true : false;
        if (chef == real) {
            cout << "YES" << endl;
        }
        else 
        {
            cout << "NO" << endl;
        }
    }
    
    
    return 0;
} 
