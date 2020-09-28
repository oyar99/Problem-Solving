class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        //L[i] corresponds to the index of the first busy seat to the left of the ith seat
        vector<int> L(seats.size());
        L[0] = -1;
        //R[i] corresponds to the index of the first busy seat to the right of the ith seat
        vector<int> R(seats.size());
        R[seats.size() - 1] = -1;
        
        //if seats[i-1] is busy, then that is the closest one to the ith seat. 
        //Otherwise the closest busy seat is L[i-1]
        for (int i = 1; i < seats.size(); ++i) {
            if (seats[i-1] == 1) L[i] = i - 1;
            else L[i] = L[i-1];
        }
        //if seats[i+1] is busy, then that is the closest one to the ith seat. 
        //Otherwise the closest busy seat is R[i+1]
        for (int i = seats.size() - 2; i >= 0; --i) {
            if (seats[i+1] == 1) R[i] = i + 1;
            else R[i] = R[i+1];
        }
        
        //d corresponds to the the maximum distance to a busy seat after having looked at the first i seats
        //Note that if the ith seat is busy, we skip this iteration since we cannot sit there.
        int d = max(seats[0] == 1 ? 0: R[0], seats[seats.size() - 1] == 1? 0 :(int) (seats.size() - L[seats.size() - 1] - 1));
        for (int i = 1; i < seats.size() - 1; ++i) {
            if (seats[i] == 1) continue;
            d = max(d, min(R[i] - i, i - L[i]));
        }
        return d;
    }
};
