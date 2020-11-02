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

/*
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode* temp = head;
        vector<int> v;
        while(temp){
            v.push_back(temp->val);
            temp = temp->next;
        }
        sort(v.begin(),v.end());
        temp = head;
        for(int x : v){
            temp->val = x;
            temp = temp->next;
        }
        return head;
    }
};*/

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode* dummy = new ListNode(-1);
        ListNode* curr = head;
        ListNode* prev, *nextn;
        while(curr){
            prev = dummy;
            nextn = prev->next;
            while(nextn){
                if(curr->val < nextn->val) break;
                prev = nextn;
                nextn = nextn->next;
            }
            ListNode* currnext = curr->next;
            curr->next = nextn;
            prev->next = curr;
            curr = currnext;
        }
        return dummy->next;
    }
};