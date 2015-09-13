/*
 * @SEU(master);@ZZULI(bachelor)
 * author:CuiXuan
 * email:873059043@qq.com
 * If you find any errors, please let me know.
 * If you have any better solution, please let me know.
 *
 * Solution Using time 8ms
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void reverse(struct ListNode** p,struct ListNode **s){
	struct ListNode *l=(*p)->next,*tmp,*tail=(*p)->next,*flag=(*s)->next;
    (*p)->next=NULL;
    while(l!=flag){
        tmp=(*p)->next;
        (*p)->next=l;
        l=l->next;
        (*p)->next->next=tmp;
    }
    tail->next=l;
    *p=tail;
    *s=tail;
}
struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    struct ListNode *s,*p=(struct ListNode*)malloc(sizeof(struct ListNode));
    int len=k;
    p->next=head;
    head=p;s=p;
    while(k-- && s!=NULL)s=s->next;
    while(s!=NULL){
        reverse(&p,&s);
        k=len;
        while(k-- && s!=NULL)s=s->next;
    }
    return head->next;
}
