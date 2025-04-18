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
        ListNode* deleteMiddle(ListNode* head) {
            ListNode* slow = new ListNode(-1);
            ListNode* temp = head;
            ListNode* fast = head;

            while(fast && fast->next) {
                slow = temp;
                temp = temp->next;
                fast = fast->next->next;
            }

            if(!slow->next) return nullptr;
            else {
                slow->next = slow->next->next;
            }
            return head;
        }
};