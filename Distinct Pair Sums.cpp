Distinct Pair Sums
Read problems statements in Hindi, Mandarin Chinese, Russian, Vietnamese, and Bengali as well.
You are given a range of integers 
{
L
,
L
+
1
,
…
,
R
}
{L,L+1,…,R}. An integer 
X
X is said to be reachable if it can be represented as a sum of two not necessarily distinct integers in this range. Find the number of distinct reachable integers.

Input
The first line of the input contains a single integer 
T
T denoting the number of test cases. The description of 
T
T test cases follows.
The first and only line of each test case contains two space-separated integers 
L
L and 
R
R.
Output
For each test case, print a single line containing one integer — the number of reachable integers.

Constraints
1
≤
T
≤
10
5
1≤T≤10 
5
 
1
≤
L
≤
R
≤
10
6
1≤L≤R≤10 
6
 
Sample 1:
Input
Output
2
2 2
2 3
1
3
Explanation:
Example case 1: The only reachable integer is 
2
+
2
=
4
2+2=4.

Example case 2: 
4
4, 
5
5 and 
6
6 are reachable, since 
2
+
2
=
4
2+2=4, 
2
+
3
=
5
2+3=5 and 
3
+
3
=
6
3+3=6.

Did you like the problem?
233 users found this helpful
C++


#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
	    int L,R;
	    cin>>L>>R;
	    cout<<2*(R-L)+1<<endl;
	}
	return 0;
}
