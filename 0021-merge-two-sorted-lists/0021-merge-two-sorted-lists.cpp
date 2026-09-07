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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        ListNode* i = list1;
        ListNode* j = list2;
        ListNode dummy(0);
        ListNode* temp= &dummy;
        while(i != nullptr && j !=nullptr){
            if(i->val <= j->val){
                temp->next = i;
                i= i->next;
                temp=temp->next;
            } else{
                temp->next = j;
                j= j->next;
                temp=temp->next;
            }
        }
        if(i !=nullptr){
            temp->next=i;  
        }else{
            temp->next = j;
        }
        return dummy.next;
    }
};