/*
 * @SEU(master);@ZZULI(bachelor)
 * author:CuiXuan
 * email:873059043@qq.com
 * If you find any errors, please let me know.
 * If you have any better solution, please let me know.
 *
 * Solution Using time 389ms
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void adjustTree(struct ListNode** lists,int i,int length,int* tree){
    int l,r;
    if(i*2 < length){
        l=tree[i*2];
    }else{
        l=i*2-length;
    }
    if(i*2+1 < length){
        r=tree[i*2+1];
    }else{
        r=i*2-length+1;
    }
	if(lists[l]==NULL)tree[i]=r;
	else if(lists[r]==NULL)tree[i]=l;
	else tree[i]= lists[l]->val > lists[r]->val ?r:l;
}
void buildWinnerTree(struct ListNode** lists,int length,int* tree){
    int i;
    for(i=length-1;i>=1;i--){
        adjustTree(lists,i,length,tree);
    }
}
void adjustToRoot(struct ListNode** lists,int tar,int length,int* tree){
    while(tar>0){
        adjustTree(lists,tar,length,tree);
        tar=tar/2;
    }
}
struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    struct ListNode *p,*head;
    int* tree=(int*)malloc(sizeof(int)*(listsSize));
    if(listsSize==0)return NULL;
    else if(listsSize==1)return lists[0];
    buildWinnerTree(lists,listsSize,tree);
	if(lists[tree[1]]==NULL)return NULL;
	p=lists[tree[1]];lists[tree[1]]=lists[tree[1]]->next;
	head=p;
	adjustToRoot(lists,(tree[1]+listsSize)/2,listsSize,tree);
	while(lists[tree[1]]!=NULL){
	    p->next=lists[tree[1]];
	    lists[tree[1]]=lists[tree[1]]->next;
	    p=p->next;
	    adjustToRoot(lists,(tree[1]+listsSize)/2,listsSize,tree);
	}
    return head;
}
