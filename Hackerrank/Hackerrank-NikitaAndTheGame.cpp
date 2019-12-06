//This file only contains the functions used for solving the problem.
//The main function is omitted for brevity.

int split(vector<long>& A, int l, int r) {
    if (l >= r - 1) return 0;
    for (int i = l; i < r; ++i) {
        if (A[i+1] - A[l] == A[r] - A[i+1]) {
            int ans = 1 + max(split(A, l, i+1),split(A, i + 1, r));
            return ans;
        }
    }
    return 0;
}

int arraySplitting(vector<long>& arr) {
    vector<long> A(arr.size() + 1);
    A[0] = 0;
    for (int i = 0; i < arr.size();++i) A[i+1] = A[i] + arr[i];
    return split(A, 0, A.size() - 1);
}
