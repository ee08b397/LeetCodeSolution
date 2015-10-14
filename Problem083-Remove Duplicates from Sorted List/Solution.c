/*
 * @SEU(master);@ZZULI(bachelor)
 * author:CuiXuan
 * email:873059043@qq.com
 * If you find any errors, please let me know.
 * If you have any better solution, please let me know.
 *
 * Solution Using time 4ms
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode *l,*r=head;
    while(head!=NULL && (head->next!=NULL && head->next->val==head->val))head=head->next;
    l=head;
    if(head!=NULL)r=head->next;
    else r=head;
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
