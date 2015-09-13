/*
 * @SEU(master);@ZZULI(bachelor)
 * author:CuiXuan
 * email:873059043@qq.com
 * If you find any errors, please let me know.
 * If you have any better solution, please let me know.
 *
 * Solution Using time 112ms
 */
class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1)return s;
        string chs=string(s);
        int index=0;
        if(numRows==2){
            for(int i=0;i<s.size();i=i+2)chs[index++]=s[i];
            for(int i=1;i<s.size();i=i+2)chs[index++]=s[i];
            return chs;
        }
        char map[1000][1000];
        for(int i=0;i<numRows;i++){
            for(int j=0;j<s.size();j++)
            map[i][j]=0;
        }
        index=0;
        int col=0;
        while(s[index]){
            if(col%2){
                int i=numRows-2;
                while(i>=1 && s[index])map[i--][col]=s[index++];
            }else{
                int i=0;
                while(i<numRows && s[index])map[i++][col]=s[index++];
            }
            col++;
        }
        index=0;
        for(int i=0;i<numRows;i++){
            for(int j=0;j<col;j++){
                if(map[i][j])chs[index++]=map[i][j];
            }
        }
        return chs;
    }
};
