#include <iostream>

using namespace std;

int T, P1, P2, K, p, rem;
string res;

int main() {
    cin >> T;

    for (int i = 0; i < T; i++) {
        cin >> P1 >> P2 >> K;

        p = P1 + P2;
        rem = p / K;

        if (rem % 2 == 0) {
            res = "CHEF";
        } else {
            res = "COOK";
        }

        cout << res << endl;
    }

    return 0;
}
