/*
 * @SEU(master);@ZZULI(bachelor)
 * author:CuiXuan
 * email:873059043@qq.com
 * If you find any errors, please let me know.
 * If you have any better solution, please let me know.
 *
 * Solution Using time 79ms
 */
char* convert(char* s, int numRows) {
    char* ch;
    char map[1000][1000];
    int length=0,index=0,i,j,k;
    if(numRows<=1)return s;
    for(i=0;s[i];i++)length++;
	ch = (char*)malloc(sizeof(char)*length*2);
    if(numRows==2){
        for(i=0;i<length;i=i+2)ch[index++]=s[i];
        for(i=1;i<length;i=i+2)ch[index++]=s[i];
        ch[index]=0;
        return ch;
    }
	for(i=0;i<numRows;i++){
		for(j=0;j<length;j++){
			map[i][j]=0;
		}
	}
    i=0,j=0,index=0;
    while(s[index]){
        if(j%2){
            i=numRows-2;
            while(i>=1 && s[index])map[i--][j]=s[index++];
        }else{
            i=0;
            while(i<numRows && s[index])map[i++][j]=s[index++];
        }
        j++;
    }
    index=0;
    for(i=0;i<numRows;i++){
        for(k=0;k<j;k++){
            if(map[i][k]!=0)ch[index++]=map[i][k];
        }
    }
    ch[index]=0;
    return ch;
}
