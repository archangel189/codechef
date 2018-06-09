/**
 * Solution for Naive Chef problem (June Challenge 2018 - Division 2).
 *
 * URL: https://www.codechef.com/JUNE18B/problems/NAICHEF
 */


#include <iostream>
#include <map>

using namespace std;

double solve(int n, int a, int b) {
    map<int, int> x;
    int y;

    for (int i = 0; i < n; i++) {
        cin >> y;
        x[y]++;
    }

    return (double) (x[a] * x[b]) / (n * n);
}

int main() {
    int t, n, a, b;
    cin >> t;

    for (int i = 0; i < t; i++) {
        cin >> n >> a >> b;
        cout << solve(n, a, b) << "\n";
    }

    return 0;
}
