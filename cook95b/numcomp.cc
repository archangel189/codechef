#include <iostream>

using namespace std;

int T;
long long int a, b, n;

int solve() {
    long long int abs_a, abs_b;

    if (a < 0) abs_a = -a;
    else abs_a = a;

    if (b < 0) abs_b = -b;
    else abs_b = b;

    if (n % 2 == 0) {
        if (abs_a == abs_b) return 0;
        else if (abs_a > abs_b) return 1;
        else return 2;
    } else {
        if (a < 0 && b < 0) {
            if (a == b) {
                return 0;
            } else if (a < b) {
                return 2;
            } else {
                return 1;
            }
        } else if (a < 0 && b >= 0) {
            return 2;
        } else if (a >= 0 && b < 0) {
            return 1;
        } else {
            if (a == b) {
                return 0;
            } else if (a < b) {
                return 2;
            } else {
                return 1;
            }
        }
    }
}

int main() {
    cin >> T;

    for (int i = 0; i < T; i++) {
        cin >> a >> b >> n;
        cout << solve() << endl;
    }

    return 0;
}
