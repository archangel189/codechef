/**
 * Solution to Pizza Delivery.
 *
 * URL: https://www.codechef.com/DEC12/problems/DBOY/
 */

#define _CRT_SECURE_NO_DEPRECATE
#define _SECURE_SCL 0
 
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <map>
#include <set>
#include <string>
#include <utility>
#include <vector>
#include <iostream>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <cctype>
#include <sstream>
#include <cassert>
#include <bitset>
#include <memory.h>
#include <complex>
 
using namespace std;
 
#pragma comment(linker, "/STACK:200000000")
 
typedef long long int64;
 
#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; i--)
#define fore(i, a, n) for(int i = (int)(a); i < (int)(n); i++)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define last(a) (int(a.size()) - 1)
#define all(a) a.begin(), a.end()
#define vi vector<int>
 
const double EPS = 1E-9;
const int INF = 1E9;
const int64 INF64 = (int64) 1E18;
const double PI = 3.1415926535897932384626433832795;
 
int main() {
  int T;
  cin >> T;
  
  forn(t, T) {
    int N;
    cin >> N;
    vi H(N), K(N); 
    forn(n, N) {
        cin >> H[n];
    }
    forn(n, N) {
        cin >> K[n];
    }
    
    sort(all(H));
    
    int mh = H[N-1];
    int D[2*mh+1];
    forn(i, 2*mh+1) {
        D[i] = INF;
    }
    
    int64 c = 0;
    int h = 0, ph = 0, pc = 0;
    forn(i, N) {
        h = 2*H[i];
        D[ph] = pc;
        fore(j, ph+1, h+1) {
            forn(k, N) {
                if (K[k] <= j && D[j-K[k]]+1 < D[j]) {
                    D[j] = D[j-K[k]]+1;
                }
            }
        }
        c += D[h];
        
        ph = h;
        pc = D[h];
    }    
    cout << c << endl;
  }
  
  return 0;
}
