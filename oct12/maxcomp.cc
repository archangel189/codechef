/**
 * Solution to Event Organizer.
 *
 * URL: https://www.codechef.com/OCT12/problems/MAXCOMP/
 */

#include <iostream>
#include <set>
#include <deque>
#include <algorithm>
 
using namespace std;
 
struct elem {
    int start;
    int end;
    int comp;
    int left_idx;
} e;
 
struct elem_comp {
    bool operator() (elem lhs, elem rhs ) { return lhs.end <= rhs.end; }
};
 
deque<elem> R;
int M[2000];
 
int solve(int j) {
    if (j == -1)
        return 0;
    else if (M[j] != -1)
        return M[j];
        
    M[j] = max( R[j].comp + solve(R[j].left_idx) , solve(j-1));
    return M[j];
}
 
int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        for (int xx = 0; xx < 2000; xx++) 
            M[xx] = -1;
        
        int N;
        cin >> N;
        int P[N];
        multiset<elem, elem_comp> elems;
        for (int n = 0; n < N; n++) {
            cin >> e.start >> e.end >> e.comp;
            elems.insert(e);
        }
        
        for (multiset<elem, elem_comp>::iterator iter = elems.begin() ; iter != elems.end() ; iter++) {
            R.push_back(*iter);
        }
        
        for (int i = R.size()-1; i >= 0; i--) {
            for (int j = i; j >= 0; j--) {
                if (R[j].end <= R[i].start) {
                    R[i].left_idx = j;
                    break;
                }
                R[i].left_idx = -1;
            }
        }
        
        cout << solve(R.size()-1) << endl;
        R.clear();
    }
    
    return 0;
} 
