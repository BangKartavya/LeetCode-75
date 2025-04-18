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
        ListNode* oddEvenList(ListNode* head) {
            ListNode* odd = new ListNode(-1);
            ListNode* tempOdd = odd;
            ListNode* even = new ListNode(-1);
            ListNode* tempEven = even;

            ListNode* temp = head;
            int i = 1;
            while(temp) {
                if(i % 2) {
                    tempOdd->next = temp;
                    tempOdd = tempOdd->next;
                } else {
                    tempEven->next = temp;
                    tempEven = tempEven->next;
                }
                temp = temp->next;
                i++;
            }

            tempEven->next = nullptr;
            tempOdd->next = even->next;

            return odd->next;
        }
};