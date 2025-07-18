Smallest Possible Whole Number
Read problem statements in Bengali, Mandarin Chinese, Russian, and Vietnamese as well.
You are given two integers 
N
N and 
K
K. You may perform the following operation any number of times (including zero): change 
N
N to 
N
−
K
N−K, i.e. subtract 
K
K from 
N
N. Find the smallest non-negative integer value of 
N
N you can obtain this way.

Input
The first line of the input contains a single integer 
T
T denoting the number of test cases. The description of 
T
T test cases follows.
The first and only line of each test case contains two space-separated integers 
N
N and 
K
K.
Output
For each test case, print a single line containing one integer — the smallest value you can get.

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
N
≤
10
9
1≤N≤10 
9
 
0
≤
K
≤
10
9
0≤K≤10 
9
 
Subtasks
Subtask #1 (100 points): original constraints

Sample 1:
Input
Output
3
5 2
4 4
2 5
1
0
2
Explanation:
Example case 1:

First, we change 
N
=
5
N=5 to 
N
−
K
=
5
−
2
=
3
N−K=5−2=3.
Then, we have 
N
=
3
N=3 and we change it to 
N
−
K
=
3
−
2
=
1
N−K=3−2=1.
Since 
1
<
K
1<K, the process stops here and the smallest value is 
1
1.

Example case 2: We change 
N
=
4
N=4 to 
N
−
K
=
4
−
4
=
0
N−K=4−4=0. Since 
0
<
K
0<K, the process stops here and the smallest value is 
0
0.

Example case 3: Since 
2
<
K
2<K initially, we should not perform any operations and the smallest value is 
2
2.

Did you like the proble


#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	    int n,k;
	    cin>>n>>k;
	    if(k==0){
	        cout<<n<<endl;
	    }
	    else
	    cout<<n%k<<endl;
	}
	return 0;
}
