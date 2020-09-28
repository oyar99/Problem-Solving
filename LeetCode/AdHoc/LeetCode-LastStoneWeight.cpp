class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        if (stones.size() >= 3) {
            make_heap(stones.begin(), stones.end());
            int r = stones.front();
            pop_heap(stones.begin(), stones.end());
            stones.pop_back();
            while (stones.size() >= 1 && r > 0) {
                int m = stones.front();
                pop_heap(stones.begin(), stones.end());
                stones.pop_back();
                r -= m;
                if (r > 0) {
                    stones.push_back(r);
                    push_heap(stones.begin(), stones.end());
                }
                
                if (stones.size() == 0) break;
                r = stones.front();
                pop_heap(stones.begin(), stones.end());
                stones.pop_back();
            }
            return r > 0?r:0;
        }
        if (stones.size() == 2) {
            return abs(stones[1] - stones[0]);
        }
        if (stones.size() == 1) {
            return stones[0];
        }
        return -1;
    }
};