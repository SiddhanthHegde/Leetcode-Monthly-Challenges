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
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* A = head;
        ListNode* nhead = head;
        ListNode* prev = head;
        int c = 1;
        while(nhead && nhead->next){
            ListNode* nex = A->next;
            prev->next = nex;
            nhead = nex->next;
            nex->next = A;
            A->next = nhead;
            prev = A;
            A = nhead;
            if(c == 1) {
                dummy->next = nex;
                c++;
            }
        }
        return dummy->next;
    }
};
