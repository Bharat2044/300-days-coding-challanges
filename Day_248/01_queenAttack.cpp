// Question Link: https://www.interviewbit.com/problems/queen-attack/

/*
Queen Attack

Problem Description:
On an N * M chessboard, where rows are numbered from 1 to N and columns from 1 to M, there are queens at some cells. Return an N * M array A, where A[i][j] is the number of queens that can attack cell (i, j). While calculating the answer for cell (i, j), assume there is no queen at that cell.

Notes:
Queen is able to move any number of squares vertically, horizontally, or diagonally on a chessboard. A queen cannot jump over another queen to attack a position.
You are given an array of N strings, each of size M. Each character is either a 1 or 0 denoting if there is a queen at that position or not, respectively.
Expected time complexity in worst-case O(N*M).

Problem Constraints:
1 <= N <= 500
1 <= M <= 500

Input Format:
The first argument is an array of strings.

Output Format:
Return an N * M array of integers.

Example Input:
A = ["010",
     "100",
     "001"]

Example Output:
[[3, 1, 2]
 [1, 3, 3]
 [2, 3, 0]]

Example Explanation:
The chessboard is,
[0 1 0]
[1 0 0]
[0 0 1]

where a 1 denotes a queen at that position.
Cell (1, 1) is attacked by queens at (2, 1), (1,2) and (3,3).
Cell (1, 2) is attacked by queen at (2, 1). Note that while calculating this, we assume that there is no queen at (1, 2).
Cell (1, 3) is attacked by queens at (3, 3) and (1, 2).
and so on...

Finally, we return matrix
[3, 1, 2]
[1, 3, 3]
[2, 3, 0]
*/



bool isValid(int i,int j,int n,int m){
    if(i<0 || j<0 || i>=n || j>=m)
    return false;
    return true;
}

int dx[8]={-1,-1,0,1,1,1,0,-1};
int dy[8]={0,1,1,1,0,-1,-1,-1};

int f(int i,int j,int k,vector<string>&A,int n,int m){
   
    int x=i+dx[k];
    int y=j+dy[k];
   
    int count=0;
    if(isValid(x,y,n,m)){
        if(A[x][y]=='1')
        count++;
        else
        count+=f(x,y,k,A,n,m);
    }
   return count;
}

vector<vector<int> > Solution::queenAttack(vector<string> &A) {
    int n=A.size();
    int m=A[0].size();
    vector<vector<int>> ans(n,vector<int>(m,0));
     
       for(int k=0;k<8;k++){
           for(int i=0;i<n;i++){
               for(int j=0;j<m;j++){
                   ans[i][j]+=f(i,j,k,A,n,m);
               }
           }
       }  
    return ans;  
}
