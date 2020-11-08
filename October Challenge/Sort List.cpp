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
public:
    ListNode* sortList(ListNode* head) {
        vector<int> v;
        ListNode* k = head;
        while(k != NULL){
            v.push_back(k->val);
            k = k->next;
        }
        sort(v.begin(),v.end());
        k = head;
        for(int x : v){
            k->val = x;
            k = k->next;
        }
        return head;
    }
};