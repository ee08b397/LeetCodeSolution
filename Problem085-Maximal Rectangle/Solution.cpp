/*
 * @SEU(master);@ZZULI(bachelor)
 * author:CuiXuan
 * email:873059043@qq.com
 * If you find any errors, please let me know.
 * If you have any better solution, please let me know.
 *
 * Solution Using time 32ms
 */
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        stack<int> st;
        int i,j,max=0;
        int row=matrix.size();
        int col=row==0?0:matrix[0].size();
        vector<char> map(col,0);
        for(i=0;i<row;i++){
            for(j=0;j<col;j++){
                if(matrix[i][j]=='1')map[j]++;
                else map[j]=0;
                while(!st.empty() && map[st.top()]>map[j]){
                    int index = st.top();
                    st.pop();
                    int area = (st.empty()?j:j-st.top()-1)*map[index];
                    max = max>area?max:area;
                }
                st.push(j);
            }
            while(!st.empty()){
                int index = st.top();
                st.pop();
                int area = (st.empty()?j:j-st.top()-1)*map[index];
                max = max>area?max:area;
            }
        }
        return max;
    }
};
