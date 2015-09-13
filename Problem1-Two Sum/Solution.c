#define HASH_SIZE 10000
struct node{
	int value;
	int key;
	struct node* next;
};
struct node* data[HASH_SIZE];

int contains(int key){
	int hash = abs(key)%HASH_SIZE;
	struct node* p = data[hash];
	while(p!=NULL){
		if(p->key==key)return 1;
		p=p->next;
	}
	return 0;
}
void put(int key,int value){
	int hash = abs(key)%HASH_SIZE;
	struct node* p = data[hash];
	struct node* s = (struct node*)malloc(sizeof(struct node));
	s->key=key;
	s->value=value;
	s->next=NULL;
	if(p==NULL){
		data[hash] = s;
		return;
	}
	while(p->next!=NULL){
		p=p->next;
	}
	p->next=s;
}
int get(int key){
	int hash = abs(key)%HASH_SIZE;
	struct node* p = data[hash];
	while(p!=NULL){
		if(p->key==key)return p->value;
		p=p->next;
	}
	return 0;
}
int abs(int value){
	return value>0?value:-value;
}
int* twoSum(int* nums, int numsSize, int target) {
	 int* res = (int*)malloc(sizeof(int)*2);
	 int value;
	 for(value=0;value<HASH_SIZE;value++){
	     data[value]=NULL;
	 }
     for(int i=0;i<numsSize;i++){
		 if(contains(target-nums[i])){
			 value = get(target-nums[i]);
			 res[0]=value;
			 res[1]=i+1;
			 return res;
		 }
		 put(nums[i],i+1);
     }
    return res;
}
