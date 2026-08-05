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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head == nullptr||left == right) return head;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* templ = dummy;
        for (int i = 1; i < left ; i++) {
            templ = templ->next;
        }
        ListNode* curr = templ->next;
        ListNode* prev = nullptr;
        for (int i = left; i <= right; i++) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        ListNode* leftNode = templ->next;
        leftNode->next = curr;
        templ->next = prev;
        return dummy->next;
    }
};