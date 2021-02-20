class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), [](const auto& a, const auto& b) {
           return a[1] > b[1]; 
        });
        
        int boxes = 0;
        
        for (int i = 0; i < boxTypes.size(); ++i)
            boxes += min(truckSize, boxTypes[i][0]) * boxTypes[i][1],
            truckSize -= max(0, min(truckSize, boxTypes[i][0]));
        
        return boxes;
    }
};
