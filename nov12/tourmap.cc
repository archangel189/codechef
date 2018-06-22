/**
 * Solution to Sridhar Likes Travelling.
 *
 * URL: https://www.codechef.com/NOV12/status/TOURMAP
 */

#include <iostream>
#include <set>
#include <map>
#include <utility>
#include <cstdlib>
#include <vector>
 
using namespace std;
 
typedef vector<int> vi; 
typedef vector<vi> vvi; 
typedef pair<int,int> ii; 
#define sz(a) int((a).size()) 
#define pb push_back 
#define all(c) (c).begin(),(c).end() 
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end()) 
 
int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        int N;
        cin >> N;
        map<string, pair<string, int> > paths;
        set<string> occ;
        for (int n = 0; n < N-1; n++) {
            string from, to, cost;
            int acost;
            cin >> from >> to >> cost;
            acost = atoi(cost.substr(0, cost.size()-1).c_str());
            
            paths[from] = make_pair(to, acost);
            if (occ.find(from) == occ.end())
                occ.insert(from);
            else
                occ.erase(from);
                
            if (occ.find(to) == occ.end())
                occ.insert(to);
            else
                occ.erase(to);
        }
        
        string first, second, begin;
        set<string>::iterator it = occ.begin();
        first = *it++;
        second = *it;
        
        if (paths.find(first) == paths.end())
            begin = second;
        else
            begin = first;
 
        int tcost = 0;
        for (int n = 0; n < N-1; n++) {
            cout << begin << " " << paths[begin].first << " " << paths[begin].second << "$" << endl;
            tcost += paths[begin].second;
            begin = paths[begin].first;
        }        
        
        cout << tcost << "$" << endl;
    }
    
    return 0;
} 
