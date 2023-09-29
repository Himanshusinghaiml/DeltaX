#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    
    sort(A.begin(), A.end()); // Sort the array in ascending order
    
    int minDifference = A[M - 1] - A[0]; // Initialize the minimum difference with the maximum and minimum elements of the first M elements
    
    for (int i = M; i < N; ++i) {
        minDifference = min(minDifference, A[i] - A[i - M + 1]); // Update the minimum difference as we slide the window of size M
    }
    
    cout << minDifference << endl; // Print the lowest possible value of the function F(B)
    
    return 0;
}
