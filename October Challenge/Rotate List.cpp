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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* end = head;
        if(!head || head->next == NULL) return head;
        int n = 1;
        while(end->next != NULL) {
            end = end->next;
            n++;
        }
        end->next = head;
        k %= n;
        ListNode* nt = head;
        for(int i = 1; i < n - k; i++) nt = nt->next;
        head = nt->next;
        nt->next = NULL;
        return head;
        
        
    }
};