Cyclic Shift Minimization
A permutation 
P
P - 
[
P
1
,
P
2
,
.
.
.
,
P
N
]
[P 
1
​
 ,P 
2
​
 ,...,P 
N
​
 ] of size 
N
N is an array of size 
N
N consisting of integers 
1
1, 
2
2, .... 
N
N each exactly once, in some order.

Define 
f
(
P
)
=
f(P)= number of fixed points, i.e. number of 
i
i such that 
(
P
i
=
i
)
(P 
i
​
 =i).

A cyclic shift of 
[
P
1
,
P
2
,
.
.
.
.
,
P
N
]
[P 
1
​
 ,P 
2
​
 ,....,P 
N
​
 ] is 
[
P
X
+
1
,
…
,
P
N
,
P
1
,
P
2
,
.
.
.
,
P
X
]
[P 
X+1
​
 ,…,P 
N
​
 ,P 
1
​
 ,P 
2
​
 ,...,P 
X
​
 ] for each 
1
≤
X
≤
N
1≤X≤N. Note that there are exactly 
N
N cyclic shifts.

Define 
g
(
P
)
=
max
⁡
(
f
(
Q
)
)
g(P)=max(f(Q)) over all 
Q
Q which are cyclic shifts of 
P
P.

Construct a permutation of size 
N
N which has minimum value of 
g
(
P
)
g(P) among all permutations of size 
N
N.

Input Format
The first line of input will contain a single integer 
T
T, denoting the number of test cases.
Each test case consists of a single integer, 
N
N, the size of the permutation.
Output Format
For each test case, output the permutation 
p
p which minimized the value 
g
(
p
)
g(p).

Constraints
1
≤
T
≤
500
1≤T≤500
1
≤
N
≤
500
1≤N≤500
Sample 1:
Input
Output
3
1
3
6
1
2 1 3
3 5 1 6 2 4
Explanation:
Test Case 1: there is only 
1
1 possible permutation.

Test Case 2 : 
N
=
3
N=3,

f
(
[
2
,
1
,
3
]
)
=
1
f([2,1,3])=1 (only 
i
=
3
i=3 satisfies 
P
i
=
i
P 
i
​
 =i)
f
(
[
3
,
2
,
1
]
)
=
1
f([3,2,1])=1 (only 
i
=
2
i=2 satisfies 
P
i
=
i
P 
i
​
 =i)
f
(
[
1
,
3
,
2
]
)
=
1
f([1,3,2])=1 (only 
i
=
1
i=1 satisfies 
P
i
=
i
P 
i
​
 =i)
g
(
[
2
,
1
,
3
]
)
=
max
⁡
(
f
(
[
2
,
1
,
3
]
)
,
f
(
[
3
,
2
,
1
]
)
,
f
(
[
1
,
3
,
2
]
)
)
=
1
g([2,1,3])=max(f([2,1,3]),f([3,2,1]),f([1,3,2]))=1#include <bits/stdc++.h>
using namespace std;

int main() {
	int t; cin>>t;
	while(t--){
	    int n; cin>>n; 
	    vector<int> arr;
	    if(n%2 ==0){
	    int start = n/2;
	   // cout<<start<<endl;
	    while(start>=1){
	        arr.push_back(start);
	        start--;
	    }
	    int start2 = n/2;
	    while(n>start2){
	        arr.push_back(n);
	        n--;
	    }
	    for(int i =0; i<arr.size(); i++){
	        cout<<arr[i]<<" ";
	    }
	    cout<<endl;
	    }
	    else{
	        int start = n/2+1;
	   // cout<<start<<endl;
	    while(start>=1){
	        arr.push_back(start);
	        start--;
	    }
	    int start2 = n/2+1;
	    while(n>start2){
	        arr.push_back(n);
	        n--;
	    }
	    for(int i =0; i<arr.size(); i++){
	        cout<<arr[i]<<" ";
	    }
	    cout<<endl;
	    }
	}

}
