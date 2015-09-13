/*
 * @SEU(master);@ZZULI(bachelor)
 * author:CuiXuan
 * email:873059043@qq.com
 * If you find any errors, please let me know.
 * If you have any better solution, please let me know.
 *
 * Solution Using time 4ms
 */
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        char* tmp=(char*)malloc(sizeof(char)*(n+n+1));
        generate(res,n,n,tmp,0);
        return res;
    }
private:
    void generate(vector<string>& res,int l,int r,char* tmp,int index){
        if(l==0 && r==0){
            tmp[index]=0;
            res.push_back(string(tmp));
            return;
        }
        if(l>0){
            tmp[index]='(';
            generate(res,l-1,r,tmp,index+1);
        }
        if(r>0 && r>l){
            tmp[index]=')';
            generate(res,l,r-1,tmp,index+1);
        }
    }
};
