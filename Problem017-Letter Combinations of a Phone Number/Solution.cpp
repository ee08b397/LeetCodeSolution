/*
 * @SEU(master);@ZZULI(bachelor)
 * author:CuiXuan
 * email:873059043@qq.com
 * If you find any errors, please let me know.
 * If you have any better solution, please let me know.
 *
 * Solution Using time 3ms
 */
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        length=digits.size();
        if(length==0)return res;
        char* tmp=(char*)malloc(sizeof(char)*(length+1));
        getLetterCom(res,0,digits,tmp);
        return res;
    }
private:
    char map[10][5]={" ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    int top=0,length=0;
    void getLetterCom(vector<string>& res,int index,string digits,char* tmp){
        if(index>=length){
            tmp[index]=0;
            string letters=string(tmp);
            res.push_back(letters);
            return;
        }
        int digit=digits[index]-'0';
        for(int i=0;map[digit][i];i++){
            tmp[index]=map[digit][i];
            getLetterCom(res,index+1,digits,tmp);
        }
    }
};
