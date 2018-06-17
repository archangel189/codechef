#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

set<int> S;
vector<int> POS;
vector<vector<int> > POS_PERMS;

int T, K, N;
int num[8];

void init_S() {
    for (int i = 1; i < N+1; i++) {
        S.insert(i);
    }
}

int count_perm() {
    int k = 0;

    for (int i = 1; i < N; i++) {
        if (num[i] > num[i-1]) k++;
    }

    return k;
}

int solve() {
    int sol = 0, pos;

    sort(POS.begin(), POS.end());

    do {
        // setup permutation
        set<int>::iterator iter = S.begin();
        for (int i = 0; i < POS.size(); i++) {
            pos = POS[i];
            num[pos] = *iter;
            ++iter;
        }

        if (count_perm() == K) sol++;
    } while ( next_permutation(POS.begin(), POS.end()) );

    return sol;
}

int main() {
    cin >> T;

    for (int i = 0; i < T; i++) {
        cin >> N >> K;

        int n;
        init_S();
        for (int j = 0; j < N; j++) {
            cin >> n;
            num[j] = n;
            if (n != 0) S.erase(n);
            if (n == 0) POS.push_back(j);
        }

        cout << solve() << endl;
        S.clear();
        POS.clear();
    }

    return 0;
}
