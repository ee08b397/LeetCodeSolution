/*
 * @SEU(master);@ZZULI(bachelor)
 * author:CuiXuan
 * email:873059043@qq.com
 * If you find any errors, please let me know.
 * If you have any better solution, please let me know.
 *
 * Solution Using time 1ms
 */
void getLetterCom(char** res,char* digits,char* tmp,int index,char map[10][5],int *top){
    int i,digit=digits[index]-'0';
	char* letters;
    if(digits[index]==0){
        letters=(char*)malloc(sizeof(char)*index);
        tmp[index]=0;
		strcpy(letters,tmp);
        res[*top]=letters;
		(*top)++;
        return;
    }
    for(i=0;map[digit][i];i++){
        tmp[index]=map[digit][i];
        getLetterCom(res,digits,tmp,index+1,map,top);
    }
}
char** letterCombinations(char* digits, int* returnSize) {
	 char map[10][5]={" ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
     char** res,*tmp;
     int num=1,length=0,top=0;
     while(digits[length]){
         if(digits[length]=='0' || digits[length]=='1')continue;
         else if(digits[length]=='7' || digits[length]=='9')num*=4;
         else num*=3;
         length++;
     }
     res=(char**)malloc(sizeof(char*)*num);
     if(length==0){
         *returnSize=0;
         return res;
     }
     tmp=(char*)malloc(sizeof(char)*length);
     getLetterCom(res,digits,tmp,0,map,&top);
     *returnSize=top;
     return res;
}
