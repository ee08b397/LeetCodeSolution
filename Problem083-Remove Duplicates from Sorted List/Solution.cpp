/*
 * @SEU(master);@ZZULI(bachelor)
 * author:CuiXuan
 * email:873059043@qq.com
 * If you find any errors, please let me know.
 * If you have any better solution, please let me know.
 *
 * Solution Using time 16ms
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *l,*r;
        while(head!=NULL && (head->next!=NULL && head->next->val==head->val))head=head->next;
        l=r=head;
        if(r!=NULL)r=r->next;
        while(r!=NULL){
            if(!(r->next!=NULL && r->next->val==r->val)){
                l->next=r;
                l=l->next;
            }
            r=r->next;
            l->next=NULL;
        }
        return head;
    }
};
