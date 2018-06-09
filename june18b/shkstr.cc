/**
 * Solution for Sheokand and String problem (June Challenge 2018 - Division 2).
 *
 * Note: Solution is only optimal for Sub-Task #1.
 *
 * URL: https://www.codechef.com/JUNE18B/problems/SHKSTR
 */

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> S;
vector<int> R;
vector<string> P;

map<string, string> V;
map<int, map<string, string> > X;
map<int, string> XL;
string xls;

void build() {
    string s, pref, v, xl;

    for (int i = 0; i < S.size(); i++) {
        s = S[i];

        for (int j = 1; j < s.size()+1; j++) {
            pref = s.substr(0, j);
            v = V[pref];

            if (v.size() == 0 || s < v) {
                V[pref] = s;
            }
        }
        X[i+1] = V;

        if (xls.size() == 0 || s < xls) {
            xls = s;
        }
        XL[i+1] = xls;
    }
}

void solve() {
    int r;
    map<string, string> x;
    string p, pp, xpp, tmp;

    for (int i = 0; i < P.size(); i++) {
        tmp = "";
        r = R[i];
        p = P[i];
        x = X[r];

        for (int j = 1; j < p.size()+1; j++) {
            pp = p.substr(0, j);
            xpp = x[pp];

            if (xpp.size() > 0) {
                tmp = xpp;
            }
        }

        if (tmp.size() > 0) {
            cout << tmp << endl;
        }
        else {
            cout << XL[r] << endl;
        }
    }
}

int main() {
    int N;
    cin >> N;

    string Si;
    for (int i = 0; i < N; i++) {
        cin >> Si;
        S.push_back(Si);
    }

    int Q;
    cin >> Q;

    int Ri;
    string Pi;
    for (int i = 0; i < Q; i++) {
        cin >> Ri >> Pi;
        R.push_back(Ri);
        P.push_back(Pi);
    }

    build();
    solve();

    return 0;
}
