// Question Link: https://www.codechef.com/problems/NETFLIX

/*
Problem:

Alice, Bob, and Charlie are contributing to buy a Netflix subscription. However, Netfix allows only two users to share a subscription.

Given that Alice, Bob, and Charlie have A,B, and C rupees respectively and a Netflix subscription costs X rupees, find whether any two of them can contribute to buy a subscription.

Input Format:
The first line of input will contain a single integer T, denoting the number of test cases.
Each test case contains four space-separated integers A,B,C, and X — the amount that Alice, Bob, and Charlie have, and the cost of a Netflix subscription respectively.

Output Format:
For each test case, output YES, if any two of Alice, Bob, and Charlie can contribute to buy a Netflix subscription or NO otherwise.
You may print each character in uppercase or lowercase. For example, NO, no, No, and nO are all considered identical.

Constraints:
1 ≤ T ≤ 1000
1 ≤ A, B, C, X ≤ 100

Sample 1:
Input
4
1 1 1 3
2 3 1 5
4 2 3 4
2 1 4 7
Output
NO
YES
YES
NO

Explanation:
Test case 1: No two people can contribute to collect enough money to buy a Netflix subscription.
Test case 2: Alice and Bob can contribute and collect a total of 5 rupees which is enough to buy a Netflix subscription of 5 rupees.
Test case 3: One possible way is, Bob and Charlie can contribute and collect a total of 5 rupees which is enough to buy a Netflix subscription of 4 rupees.
Note that there are other possible ways as well.
Test case 4: No two people can contribute to collect enough money to buy a Netflix subscription.
*/




// Time Complexity = O(t), Space Complexity = O(1)
#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin >> t;
	
	while(t--) {
	    int a, b, c, x;
	    cin >> a >> b >> c >> x;
	    
	    if(a+b>=x || b+c>=x || a+c>=x) 
	        cout << "YES\n";
	    else 
	        cout << "NO\n";
	}
	
	return 0;
}

