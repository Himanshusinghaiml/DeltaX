#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, p, q;
    cin >> n >> p >> q;

    vector<int> A(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }

    int count = 0;
    int currentSum = 0;
    int left = 0;

    for (int right = 0; right < n; ++right) {
        currentSum += A[right];

        while (currentSum > q || (right - left + 1) == p) {
            currentSum -= A[left];
            left++;
        }

        if (currentSum == q && (right - left + 1) != p) {
            count++;
        }
    }

    cout << count << endl;

    return 0;
}
