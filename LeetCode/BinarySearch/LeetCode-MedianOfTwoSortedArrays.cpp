class Solution {
public:
    int searchUpperBoundIndex(vector<int>& v, int value) {
        return distance(v.begin(), upper_bound(v.begin(), v.end(), value)) - 1;
    }
    int searchLowerBoundIndex(vector<int>& v, int value) {
        return distance(v.begin(), lower_bound(v.begin(), v.end(), value)) - 1;
    }
    pair<int, int> searchPossibleMedian(vector<int>& X, vector<int>& Y, int k, bool lowerbound) {
        int n = X.size();
        int m = Y.size();
        
        int l = 0;
        int r = n - 1;
        
        while (l < r) {
            int mid = (l + r) >> 1;
            
            int yi = lowerbound ? searchLowerBoundIndex(Y, X[mid]) : searchUpperBoundIndex(Y, X[mid]);
            
            int leftLength = mid + yi + 1;

            if (leftLength == k) {
                return { X[mid], leftLength };
            }

            if (leftLength < k) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        
        int yi = lowerbound ? searchLowerBoundIndex(Y, X[l]) : searchUpperBoundIndex(Y, X[l]);
        
        return { X[l], l + yi + 1 };
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums2.size() > nums1.size()) {
            nums1.swap(nums2);
        }
        
        int size = nums1.size() + nums2.size();
        
        if (size == 0) {
            return 0;
        }
        
        if (size & 1) {
            int k = size / 2;
            pair<int, int> possible_median = searchPossibleMedian(nums1, nums2, k, true);
            if (possible_median.second != k) {
                possible_median = searchPossibleMedian(nums2, nums1, k, false);
                
                assert(possible_median.second == k);
                return possible_median.first;
            }
            
            return possible_median.first;
        }
        
        int k1 = size / 2;
        
        pair<int, int> possible_median = searchPossibleMedian(nums1, nums2, k1, true);
        
        if (possible_median.second != k1) {
            possible_median = searchPossibleMedian(nums2, nums1, k1, false);

            assert(possible_median.second == k1);
        }

        int one_mid = possible_median.first;
        
        int k2 = (size - 1) / 2;
        
        possible_median = searchPossibleMedian(nums1, nums2, k2, true);
        
        if (possible_median.second != k2) {
            possible_median = searchPossibleMedian(nums2, nums1, k2, false);

            assert(possible_median.second == k2);
        }
        
        int two_mid = possible_median.first;
        
        return (one_mid + two_mid) / (double)2;
    }
};
