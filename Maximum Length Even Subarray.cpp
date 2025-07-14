Maximum Length Even Subarray
Read problem statements in Mandarin, Bengali, Russian, and Vietnamese as well.
You are given an integer 
N
N. Consider the sequence containing the integers 
1
,
2
,
…
,
N
1,2,…,N in increasing order (each exactly once). Find the maximum length of its contiguous subsequence with an even sum.

Input Format
The first line of the input contains a single integer 
T
T denoting the number of test cases. The description of 
T
T test cases follows.
The first and only line of each test case contains a single integer 
N
N.
Output Format
For each test case, print a single line containing one integer --- the maximum length of a contiguous subsequence with even sum.

Constraints
1
≤
T
≤
10
4
1≤T≤10 
4
 
1
≤
N
≤
10
4
1≤N≤10 
4
 
Subtasks
Subtask #1 (100 points): original constraints

Sample 1:
Input
Output
3
3
4
5
3
4
4
Explanation:
Example case 1: The optimal choice is to choose the entire sequence, since the sum of all its elements is 
1
+
2
+
3
=
6
1+2+3=6, which is even.

Example case 3: One of the optimal choices is to choose the subsequence 
[
1
,
2
,
3
,
4
]
[1,2,3,4], which has an even sum.

#include <iostream>
using namespace std;

int main() {
	int t,n;
	cin>>t;
	while(t--){
	    cin>>n;
	    int count=(n/2)+(n%2);
	    if(count%2==0){
	        cout<<n<<endl;
	    }
	    else{
	        cout<<n-1<<endl;
	    }
	    
	}
	return 0;
}
