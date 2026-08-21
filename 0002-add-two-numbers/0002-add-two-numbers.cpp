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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry =0;
        ListNode* first = l1;
        ListNode*  second = l2;
        ListNode* prev= nullptr;
        first = l1;
            second = l2;
        while(first!= nullptr && second != nullptr){
            int sum = first->val + second->val + carry;
            first->val =sum % 10;
            carry = sum/10;
            prev = first;
            first = first->next;
            second = second->next;
        }
        if(second!=nullptr){
            prev->next = second;
            first =second;
        }
        while(first != nullptr && carry>0){
            int sum = carry+first->val;
            first->val = sum%10;
            carry = sum/10;
            prev = first;
            first = first->next;
        }
        if(carry >0){
            prev->next = new ListNode(carry);
        }
        return l1;

    }
};