struct task {
    int start;
    int end;
    int profit;
};

class segment_tree {
    vector<int> T;
    vector<bool> M;
    
    public:
        segment_tree(int size) {
            T = vector<int>(4*size);
            M = vector<bool>(4*size, false);
        }
    
        void push(int v) {
            if (M[v]) {
                T[v*2] = T[v*2+1] = T[v];
                M[v*2] = M[v*2+1] = true;
                M[v] = false;
            }
        }
    
        void update(int v, int tl, int tr, int l, int r, int x) {
            if (l > r) return;
            if (l == tl && tr == r) {
                T[v] = x;
                M[v] = true;
            } else {
                push(v);
                int tm = (tl + tr) / 2;
                update(v*2, tl, tm, l, min(r, tm), x);
                update(v*2+1, tm+1, tr, max(l, tm+1), r, x);
            }
        }
    
        int get(int v, int tl, int tr, int pos) {
            if (tl == tr) return T[v];

            push(v);
            int tm = (tl + tr) / 2;
            if (pos <= tm) return get(v*2, tl, tm, pos);
            else return get(v*2+1, tm+1, tr, pos);
        }
};

//O(nlgn)
class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<task> tasks(startTime.size());
        for (int i = 0; i < startTime.size();++i) tasks[i] = {startTime[i], endTime[i],profit[i]};
        
        sort(tasks.begin(), tasks.end(), [](const task& a, const task& b) {return a.start < b.start;});
        
        vector<int> time;
        time.reserve(10e5+1);
        sort(startTime.begin(), startTime.end());
        sort(endTime.begin(), endTime.end());
        merge(startTime.begin(), startTime.end(), endTime.begin(), endTime.end(), back_inserter(time));

        segment_tree dp(time.size());

        for (int i = tasks.size() - 1; i >= 0;--i) {
            int ti = lower_bound(time.begin(), time.end(), tasks[i].end) - time.begin();
            int tj = lower_bound(time.begin(), time.end(), tasks[i].start) - time.begin();
            int v = max(dp.get(1, 0, time.size() - 1, ti) + tasks[i].profit, dp.get(1, 0, time.size() - 1, tj));
            dp.update(1, 0, time.size() - 1, 0, tj, v);
        }
        return dp.get(1, 0, time.size() - 1, 0);
    }
};
