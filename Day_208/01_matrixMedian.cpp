// Question Link: https://www.interviewbit.com/problems/matrix-median/

/*
Matrix Median

Problem Description:
Given a matrix of integers A of size N x M in which each row is sorted.

Find and return the overall median of matrix A.

NOTE: No extra memory is allowed.

NOTE: Rows are numbered from top to bottom and columns are numbered from left to right.

Problem Constraints:
1 <= N, M <= 10^5
1 <= N*M <= 10^6
1 <= A[i] <= 10^9
N*M is odd

Input Format:
The first and only argument given is the integer matrix A.

Output Format:
Return the overall median of matrix A.

Example Input:
Input 1: 
A = [   [1, 3, 5],
        [2, 6, 9],
        [3, 6, 9]   ] 
Input 2: 
A = [   [5, 17, 100]    ]

Example Output:
Output 1: 
 5 
Output 2: 
 17

Example Explanation:
Explanation 1: 
A = [1, 2, 3, 3, 5, 6, 6, 9, 9]
Median is 5. So, we return 5. 
Explanation 2:
Median is 17.
*/



int Solution::findMedian(vector<vector<int> > &matrix) {
    int r=matrix.size();
    int c=matrix[0].size();
    int k = (r * c + 1) / 2;
    
    int a = INT_MAX;
    int b = INT_MIN;
    
    for(int i = 0; i < r; i++){
        a = min(a, matrix[i][0]);
        b = max(b, matrix[i][c-1]);
    }
    
    while(a < b){
        int m = (a + b) / 2;
        int count = 0;
        
        for(int i = 0; i < r; i++)
            count = count + upper_bound(matrix[i].begin(), matrix[i].end(), m) - matrix[i].begin();
        
        if(count < k) 
            a = m + 1;
        else 
            b = m;
    }
        
    return a;
}
