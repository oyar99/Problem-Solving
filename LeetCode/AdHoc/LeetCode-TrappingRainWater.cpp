class Solution {
public:
    vector<int> get_next_greater_or_equal(vector<int>& height) {
        int n = height.size();
        
        vector<int> nextGreaterOrEqual(n, -1);
        stack<int> aux_stack;
        
        for (int i = 0; i < n; ++i) {
            while (!aux_stack.empty() && height[i] >= height[aux_stack.top()]) {
                nextGreaterOrEqual[aux_stack.top()] = i;
                aux_stack.pop();
            }
            
            aux_stack.push(i);
        }
        
        return nextGreaterOrEqual;
    }
    vector<int> get_prefix_sum(vector<int>& height) {
        int n = height.size();
        
        vector<int> prefixSum(n + 1, 0);
        
        for (int i = 0; i < n; ++i) {
            prefixSum[i+1] = prefixSum[i] + height[i];
        }
        
        return prefixSum;
    }
    int trap(vector<int>& height) {
        int n = height.size();
        
        if (n <= 2) {
            return 0;
        }
        
        vector<int> nextGreaterOrEqualFromLeft = get_next_greater_or_equal(height);
        vector<int> reverseHeight(height);
        reverse(reverseHeight.begin(), reverseHeight.end());
        vector<int> nextGreaterOrEqualFromRight = get_next_greater_or_equal(reverseHeight);
        vector<int> prefixSum = get_prefix_sum(height);
        
        auto comp = [](const pair<int, int>& a, const pair<int, int>& b) { 
            if (a.first == b.first) {
                return a.second > b.second;
            }
            return a.first < b.first;
        };
        map<pair<int, int>, int, decltype(comp)> areas(comp);
        
        for (int i = 0; i < n; ++i) {            
            int j = nextGreaterOrEqualFromLeft[i];
            
            if (j == -1) {
                continue;
            }
            int k = nextGreaterOrEqualFromRight[(n - 1) - j] == -1 ? 
                i : (n - 1) - nextGreaterOrEqualFromRight[(n - 1) - j];
            
            int rangeSum = prefixSum[j] - prefixSum[k+1]; // the sum between (i, j) exclusive
            int area = (((j-k-1) * min(height[k], height[j])) - rangeSum);
            
            areas.insert({{ k, j }, area });
            
            i = j - 1;
        }
        
        int area = 0;
        
        int furthestPoint = -1;
        for (const auto& interval: areas) {   
            if (interval.first.first < furthestPoint) {
                continue;
            }
            furthestPoint = interval.first.second;
            area += interval.second;
        }
        
        return area;
    }
};
