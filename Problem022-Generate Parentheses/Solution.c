/*
 * @SEU(master);@ZZULI(bachelor)
 * author:CuiXuan
 * email:873059043@qq.com
 * If you find any errors, please let me know.
 * If you have any better solution, please let me know.
 *
 * Solution Using time 2ms
 */
void generate(char** res,int* size,int l,int r,char* tmp,int index){
    if(l==0 && r==0){
        tmp[index]=0;
        res[*size]=(char*)malloc(sizeof(char)*index);
        strcpy(res[*size],tmp);
        (*size)++;
        return;
    }
    if(l>0){
        tmp[index]='(';
        generate(res,size,l-1,r,tmp,index+1);
    }
    if(r>0 && l<r){
        tmp[index]=')';
        generate(res,size,l,r-1,tmp,index+1);
    }
}
char** generateParenthesis(int n, int* returnSize) {
    char** res;
    char* tmp=(char*)malloc(sizeof(char)*(n*2+1));
    int l=n,r=n;
    res=(char**)malloc(sizeof(char*)*1000000);
    *returnSize=0;
    generate(res,returnSize,l,r,tmp,0);
    return res;
}
