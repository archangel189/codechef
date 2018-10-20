#include <iostream>
#include <cstring>
#include <numeric>
#include <limits>
#include <map>

using namespace std;

int T;
long long int N, D;

map<long long int, long long int> memo;
map<long long int, long long int>::iterator memo_it, memo_next;
long long int result = numeric_limits<long long int>::max();
long long int result_p = numeric_limits<long long int>::max();


long long int digitsum(long long int n) {
    long long int sum = 0;
    int x;
    string p = to_string(n), q;

    for (int i = 0; i < p.size(); i++) {
        q = p[i];
        sum += atoi(q.c_str());
    }

    return sum;
}


void fn(long long int n, long long int p) {
    if (n < result || (n == result && p < result_p)) {
        result = n;
        result_p = p;
    }

    memo_it = memo.find(n);
    if (memo_it == memo.end()) {
        memo[n] = p;
    } else {
        if (p < memo_it->second) {
            memo[n] = p;
        } else {
            return;
        }
    }

    long long sn = digitsum(n), snd = digitsum(n+D);

    if ( sn != n ) {
        fn(sn, p+1);
    }

    memo_next = memo.find(snd);
    if ( memo_next == memo.end() || p+1 < memo[snd] ) {
        fn(n+D, p+1);
    }
}


int main() {
    cin >> T;

    for (int i = 0; i < T; i++) {
        cin >> N >> D;

        fn(N, 0);
        cout << result << " " << result_p << endl;

        memo.clear();
        result = numeric_limits<long long int>::max();
        result_p = numeric_limits<long long int>::max();
    }

    return 0;
}
