#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>

using namespace std;

typedef long long      ll;
typedef pair<int, int> ii;
typedef vector<ii>     vii;
typedef vector<int>    vi;

#define INF 1000000000

int T, N, K;

int solve(int H[]) {
    int res = 0;

    for (int n = 1; n < N+1; n++)
        res += (H[n]-H[n-1]-1) / K;

    return res;
}

int main() {
    cin >> T;
    for (int t = 0; t < T; t++) {
        cin >> N >> K;

        int H[N+1];
        H[0] = 0;
        for (int n = 1; n < N+1; n++) cin >> H[n];
        cout << solve(H) << endl;
    }
    return 0;
}
