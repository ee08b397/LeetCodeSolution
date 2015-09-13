/*
 * @SEU(master);@ZZULI(bachelor)
 * author:CuiXuan
 * email:873059043@qq.com
 * If you find any errors, please let me know.
 * If you have any better solution, please let me know.
 *
 * Solution Using time 6ms
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode *s,*p=(struct ListNode*)malloc(sizeof(struct ListNode));
    s=head;p->next=head;
    while(n-- && s!=NULL)s=s->next;
    while(s!=NULL){
        s=s->next;
        p=p->next;
    }
    if(p->next==head){
        head=head->next;
    }else{
        p->next=p->next->next;
    }
    return head;
}
