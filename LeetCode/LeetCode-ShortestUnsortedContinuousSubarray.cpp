//This solution has a runtime complexity of O(nlgn)

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        
        //If array is sorted, no change needs to be done
        if (is_sorted(nums.begin(), nums.end())) return 0;
        
        vector<int> min_heap(nums);
        vector<int> max_heap(nums);
        make_heap(min_heap.begin(), min_heap.end(), greater<int>());
        make_heap(max_heap.begin(), max_heap.end(), less<int>());
        
        int l = 0;
        
        //Finds the index l such that the subarray nums[0..l-1] is sorted
        while (!min_heap.empty()) {
            int u = min_heap.front();
            pop_heap(min_heap.begin(), min_heap.end(), greater<int>());
            min_heap.pop_back();
            if (u != nums[l]) break;
            
            ++l;
        }
        
        int r = nums.size() - 1;
        
        //Finds the index R such that the subarray nums[R+1...N] is sorted
        while (!max_heap.empty()) {
            int u = max_heap.front();
            pop_heap(max_heap.begin(), max_heap.end(), less<int>());
            max_heap.pop_back();
            
            if (u != nums[r]) break;
            
            --r;
        }
        //Lenght of subarray [L..R]
        return r - l + 1;
    }
};
