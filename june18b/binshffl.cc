#include <iostream>

using namespace std;

int T;
long long int A, B, sol;

unsigned count_bits(unsigned long long int num){
    long long int count = 0;

    while (num) {
        if (num & 1) count++;
        num = num >> 1;
    }

    return count;
}

int main(){
    cin >> T;

    for (int t = 0; t < T; t++) {
        cin >> A >> B;

        if (A == B)
            sol = 0;
        else if ( (B == 0 && A > 0) || (B == 1 && A > 1) )
            sol = -1;
        else if ( count_bits(A) > count_bits(B-1) )
            sol = 2;
        else
            sol = count_bits(B-1) - count_bits(A) + 1;

        cout << sol << endl;
    }

    return 0;
}
