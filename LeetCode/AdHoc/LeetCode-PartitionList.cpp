class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        
        if (head == nullptr) 
            return nullptr;
        
        vector<ListNode*> left;
        vector<ListNode*> right;
        
        ListNode * cur = head;
        
        while (cur != nullptr) {
            if (cur->val < x)
                left.push_back(cur);
            else
                right.push_back(cur);
            
            cur = cur->next;
        }
        
        for (int i = 0; i < left.size() + right.size() - 1; ++i)
            if (i < (int)left.size() - 1)
                (left[i])->next = left[i+1];
            else if (i == (int)left.size() - 1)
                (left[i])->next = right[0];
            else
                (right[i-left.size()])->next = right[i+1-left.size()];
        
        if (right.size() > 0) 
            (right[right.size() - 1])->next = nullptr;
        else
            (left[left.size() - 1])->next = nullptr;
        
        return left.size() > 0 ? left[0] : right[0];
    }
};
