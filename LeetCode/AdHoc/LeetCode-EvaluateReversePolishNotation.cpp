class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        
        stack<int> s;
        
        for (int i = 0; i < tokens.size(); ++i) {
            if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/") {
                int t2 = s.top();
                s.pop();
                int t1 = s.top();
                s.pop();
                
                if (tokens[i] == "+") s.push(t1 + t2);
                else if (tokens[i] == "-") s.push(t1 - t2);
                else if (tokens[i] == "/") s.push(t1 / t2);
                else s.push(t1 * t2);   
    
            } else {
                s.push(stoi(tokens[i]));
            }
        }
        
        return s.top();
    }
};
