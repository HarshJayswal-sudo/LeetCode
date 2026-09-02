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
    ListNode* middleNode(ListNode* head) {
        ListNode* temp = head;
        int n = 1;
        while(temp->next){
            temp = temp->next;
            n++;
        }
        int mid = n/2;
        n=0;
        temp = head;
        while(temp->next){
            temp = temp->next;
            n++;
            if(n == mid){
                break;
            }
        }
        return temp;
    }
};