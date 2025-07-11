#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

bool isPossible(vector<int>& A, vector<int>& B, int P, int maxTime) {
    int n = A.size();
    int m = B.size();
    int j = 0;  // pointer for B (artifacts)
    
    for (int i = 0; i < n; ++i) {
        while (j < m && abs(A[i] - B[j]) + abs(B[j] - P) > maxTime) {
            ++j;
        }
        if (j == m) return false;
        ++j; // assign this artifact to current person
    }
    return true;
}

int minimumTime(int N, int M, int P, vector<int>& A, vector<int>& B) {
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    int low = 0, high = 2e9, ans = high;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (isPossible(A, B, P, mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

int main() {
    int N, M, P;
    cin >> N >> M >> P;
    vector<int> A(N), B(M);

    for (int i = 0; i < N; ++i) cin >> A[i];
    for (int i = 0; i < M; ++i) cin >> B[i];

    cout << minimumTime(N, M, P, A, B) << endl;
    return 0;
}
