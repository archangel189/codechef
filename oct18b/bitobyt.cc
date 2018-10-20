#include <iostream>
#include <cmath>

using namespace std;

int T, N;
unsigned long long int r1 = 0, r2 = 0, r3 = 0, mod, quot;

int main() {
    cin >> T;

    for (int i = 0; i < T; i++) {
        cin >> N;

        mod = (N-1)%26;
        quot = (N-1)/26;
        if (mod >= 10) {
            r3 = pow(2, quot);
        } else if (mod >= 2) {
            r2 = pow(2, quot);
        } else {
            r1 = pow(2, quot);
        }

        cout << r1 << " " << r2 << " " << r3 << endl;
        r1 = 0; r2 = 0; r3 = 0;
    }

    return 0;
}
