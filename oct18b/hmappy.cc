#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;

const long long int NLIMIT = 100000;

long long int N, M, A[NLIMIT], B[NLIMIT], C[NLIMIT], MTOTAL = 0, MTARGET = 0, CMAX = 0;

long long int solve(long long int C_LOWER, long long int C_UPPER) {
    long long int m = 0,
                  mdiff,
                  c_avg = (C_LOWER + C_UPPER) / 2,
                  ccurr,
                  dups = -1,
                  chighest = 0,
                  CR[N];

    for (int n = 0; n < N; n++) {
        if (B[n] == 0) continue;
        ccurr = min(c_avg, C[n]);
        mdiff = ccurr / B[n];
        m += mdiff;
        CR[n] = mdiff * B[n];
        if (chighest < CR[n]) chighest = CR[n];
    }

    for (int n = 0; n < N; n++)
        if (chighest == c_avg && chighest == CR[n])
            dups++;
    if (dups == -1) dups = 0;

    if (m == MTARGET)
        return chighest;

    if (m-dups > MTARGET) {
        if (c_avg == C_UPPER-1) c_avg++;
        return solve(C_LOWER, c_avg);
    }
    else if (m-dups < MTARGET-dups)
        return solve(c_avg, C_UPPER);
    else
        return chighest;
}

int main() {
    cin >> N >> M;

    for (int i = 0; i < N; i++) cin >> A[i];

    for (int i = 0; i < N; i++) cin >> B[i];

    for (int i = 0; i < N; i++) {
        C[i] = A[i] * B[i];
        if (CMAX < C[i]) CMAX = C[i];
    }

    for (int i = 0; i < N; i++) if (B[i] > 0) MTOTAL += A[i];
    MTARGET = MTOTAL - M;

    long long int candies;
    if (M == 0) candies = CMAX;
    else if (MTARGET <= 0) candies = 0;
    else candies = solve(0, CMAX*2);

    cout << candies << endl;

    return 0;
}
