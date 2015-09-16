/*
 * @SEU(master);@ZZULI(bachelor)
 * author:CuiXuan
 * email:873059043@qq.com
 * If you find any errors, please let me know.
 * If you have any better solution, please let me know.
 *
 * Solution Using time 4ms
 */
class Solution {//(i,j)--->>(j,m-1-i)--->>(m-1-i,m-1-j)--->>(m-1-j,i)--->>(i,j)
public:
    void rotate(vector<vector<int>>& matrix) {
        int N = matrix.size()-1;
        for(int i=0;i<matrix.size()/2;i++){
            for(int j=i;j<matrix.size()-i-1;j++){
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[N-j][i];
                matrix[N-j][i] = matrix[N-i][N-j];
                matrix[N-i][N-j] = matrix[j][N-i];
                matrix[j][N-i] = tmp;
            }
        }
    }
};
