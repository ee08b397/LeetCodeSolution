/*
 * @SEU(master);@ZZULI(bachelor)
 * author:CuiXuan
 * email:873059043@qq.com
 * If you find any errors, please let me know.
 * If you have any better solution, please let me know.
 *
 * Solution Using time 40ms
 */
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#define HASH_SIZE 1000
typedef struct x{
    char* key;
    int value;
    int hashcode;
    struct x* next;
}Map;
Map* hash[HASH_SIZE];
int* capicity;
int cmp(const void* a,const void* b){
    return *(char*)a - *(char*)b;
}
int getHash(char* value){
    int i=0,sum=0;
    for(i=0;value[i];i++){
        sum=(sum+value[i]*41)%HASH_SIZE;
    }
    return sum%HASH_SIZE;
}
void put(char* str,int value){
    Map* node = (Map*)malloc(sizeof(Map));
    node->key = (char*)malloc(sizeof(char)*(strlen(str)+1));
    strcpy(node->key,str);
    node->hashcode = getHash(node->key);
    node->value = value;
    node->next = NULL;
    int index = node->hashcode;
    if(hash[index] == NULL){
        hash[index] = node;
    }else{
        Map* p = hash[index];
        while(p->next != NULL){
            p = p->next;
        }
        p->next = node;
    }
}
int get(char* str){
    int index = getHash(str);
    Map* p = hash[index];
    while(p!=NULL){
        if(strcmp(p->key,str) == 0)return p->value;
        p = p->next;
    }
    return -1;
}
void freeHash(){
    int i;
    for(i=0;i<HASH_SIZE;i++){
        if(hash[i] != NULL){
            Map* p = hash[i];
            while(p!=NULL){
                Map* s = p;
                p = p->next;
                free(s);
            }
        }
    }
}
void expandCapicity(char*** returnColumn,int j,int** columnSizes){
    capicity[j] *=2;
    char** newColumn = returnColumn[j];
    int i;
    returnColumn[j] = (char**)malloc(sizeof(char*)*capicity[i]);
    for(i=0;i<columnSizes[0][j];i++){
        strcpy(returnColumn[j][i],newColumn[i]);
    }
    free(newColumn);
    return;
}
void insertStr(char*** returnColumn,int** columnSizes,int j,char* str){
    int i;
    if(columnSizes[0][j] >= capicity[j]-1){
        expandCapicity(returnColumn,j,columnSizes);
    }
    returnColumn[j][columnSizes[0][j]] = (char*)malloc(sizeof(char)*(strlen(str)+1));
    for(i=columnSizes[0][j];i>0;i--){
        if(strcmp(str,returnColumn[j][i-1]) < 0){
            strcpy(returnColumn[j][i],returnColumn[j][i-1]);
        }else{
            break;
        }
    }
    strcpy(returnColumn[j][i],str);
    columnSizes[0][j]++;
}
char*** groupAnagrams(char** strs, int strsSize, int** columnSizes, int* returnSize) {
    int i,j,len;
    char*** returnColumn = (char***)malloc(sizeof(char**)*strsSize);
    capicity = (int*)malloc(sizeof(capicity)*strsSize);
    *columnSizes = (int*)malloc(sizeof(int)*strsSize);
    *returnSize=0;
    char* res;
    if(strsSize==0){
        return returnColumn;
    }
    for(i=0;i<HASH_SIZE;i++){
        hash[i] = NULL;
    }
    for(i=0;i<strsSize;i++){
        capicity[i] = 16;
    }
    for(i=0;i<strsSize;i++){
        len = strlen(strs[i]);
        res = (char*)malloc(sizeof(char)*(len+1));
        strcpy(res,strs[i]);
        qsort(res,len,sizeof(res[0]),cmp);
        int index = get(res);
        if(index >=0 && index < *returnSize){
            insertStr(returnColumn,columnSizes,index,strs[i]);
        }else{
            returnColumn[*returnSize] = (char**)malloc(sizeof(char*)*capicity[i]);
            columnSizes[0][*returnSize] = 0;
            returnColumn[*returnSize][0] = (char*)malloc(sizeof(char)*(strlen(strs[i])+1));
            strcpy(returnColumn[*returnSize][0],strs[i]);
            columnSizes[0][*returnSize]++;
            put(res,*returnSize);
            (*returnSize)++;
        }
    }
    freeHash();
    return returnColumn;
}
