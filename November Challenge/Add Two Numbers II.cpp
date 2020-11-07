/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    stack<int> convstack(ListNode* l1){
        stack<int> s;
        while(l1){
            s.push(l1->val);
            l1 = l1->next;
        }
        return s;
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1 = convstack(l1);
        stack<int> s2 = convstack(l2);
        ListNode* prev = NULL;
        int carry = 0;
        while(!s1.empty() || !s2.empty()){
            int f = s1.empty() ? 0 : s1.top();
            int s = s2.empty() ? 0 : s2.top();
            int ans = (f + s + carry);
            carry = ans / 10;
            ans = ans % 10;
            ListNode* n = new ListNode(ans,prev);
            prev = n;
            if(!s1.empty()) s1.pop();
            if(!s2.empty()) s2.pop();
        }
        if(carry){
            ListNode* n = new ListNode(carry,prev);
            prev = n;
        }
        return prev;
        
    }
};