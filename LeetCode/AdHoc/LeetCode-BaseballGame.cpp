class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> s;
        
        for (const string& c: ops) {
            if (c == "+") {
                int a = s.top();
                s.pop();
                int b = s.top();
                s.push(a);
                s.push(a+b);
            } else if (c == "D") {
                s.push(s.top() * 2);
            } else if (c == "C") {
                s.pop();
            } else {
                s.push(stoi(c));
            }
        }
        
        int sum = 0;
        
        while (!s.empty()) {
            sum += s.top();
            s.pop();
        }
        
        return sum;
    }
};
