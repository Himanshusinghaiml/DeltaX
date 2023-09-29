#include <iostream>
using namespace std;

// Function to find the highest power of 2 less than or equal to n
unsigned long long highestPowerOf2(unsigned long long n) {
    // Continue dividing n by 2 until it's not divisible
    while ((n & (n - 1)) != 0) {  // Check if n is a power of 2
        n &= (n - 1);  // Clear the lowest set bit
    }
    return n;
}

int main() {
    int T;
    cin >> T;

    for (int i = 0; i < T; i++) {
        unsigned long long N;
        cin >> N;
        bool playerA_turn = true;
        while (N > 1) {
            // Check if N is a power of 2
            if ((N & (N - 1)) == 0) {  // Efficient way to check if N is a power of 2
                N /= 2;
            } else {
                unsigned long long power_of_2 = highestPowerOf2(N);
                N -= power_of_2;
            }

            // Switch turns
            playerA_turn = !playerA_turn;
        }
        if (playerA_turn) {
            cout << "PlayerB" << std::endl;
        } else {
            cout << "PlayerA" << std::endl;
        }
    }

    return 0;
}
