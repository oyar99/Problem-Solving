class NumArray {
private:
    vector<int> T;
public:
    NumArray(vector<int>& nums) {
        T = vector<int>(nums.size() + 1);
        for (int i = 0; i < nums.size(); ++i) {
            T[i+1] = nums[i];
        }
        
        for (int i = 1; i < T.size(); ++i) {
            int p = i + (i & -i);
            if (p < T.size()) T[p] += T[i];
        }
        
    }
    
    void add(int i, int val) {
        while (i < T.size()) {
            T[i] += val;
            i = i + (i & -i);
            cout << "updating " << endl;
        }
    }
    
    void update(int i, int val) {
        int v = sumRange(i, i);
        add(i+1, val - v);
    }
    
    int sum(int i) {
        int s = 0;
        while (i > 0) {
            s += T[i];
            i = i - (i & -i);
        }
        return s;
    }
    
    int sumRange(int i, int j) {
        ++i;
        ++j;
        return sum(j) - sum(i-1);
    }
};