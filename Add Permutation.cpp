Add Permutation
Given a (
1
1-indexed) permutation 
P
P of the integers in the range 
[
1
,
N
]
[1,N], you will first construct an array 
A
A also of size 
N
N where 
A
i
=
P
i
+
i
A 
i
​
 =P 
i
​
 +i. Now, let 
f
(
P
)
f(P) as the number of distinct elements in the array 
A
A.

For example, for 
P
=
[
3
,
4
,
1
,
2
]
P=[3,4,1,2], the constructed array 
A
A is 
[
4
,
6
,
4
,
6
]
[4,6,4,6] and thus 
f
(
P
)
=
2
f(P)=2.

Given integers 
N
N and 
K
K, find a permutation 
P
P of the integers in the range 
[
1
,
N
]
[1,N] with 
f
(
P
)
=
K
f(P)=K. It can be proven that an answer always exists under the given constraints.

Input Format
The first line of input will contain a single integer 
T
T, denoting the number of test cases.
The first and only line of each test case contains 
2
2 integers - 
N
N and 
K
K.
Output Format
For each test case, output on a new line 
N
N integers - 
P
1
,
P
2
,
…
,
P
N
P 
1
​
 ,P 
2
​
 ,…,P 
N
​
 , a permutation of integers in 
[
1
,
N
]
[1,N] satisfying 
f
(
P
)
=
K
f(P)=K.

If multiple answers are possible, all will be accepted.

Constraints
1
≤
T
≤
100
1≤T≤100
1
≤
K
≤
N
≤
100
1≤K≤N≤100
Sample 1:
Input
Output
5
1 1
2 1
2 2
4 2
6 3
1
2 1
1 2
3 4 1 2
6 3 4 5 2 1
Explanation:
Test Case 1 : For 
P
=
[
1
]
P=[1], 
A
=
[
2
]
A=[2] which has only one element.

Test Case 2 : For 
P
=
[
2
,
1
]
P=[2,1], 
A
=
[
3
,
3
]
A=[3,3] which has only one distinct element, i.e. 
3
3.

Test Case 3 : For 
P
=
[
1
,
2
]
P=[1,2], 
A
=
[
2
,
4
]
A=[2,4] which has 
2
2 distinct elements, i.e. 
2
2 and 
4
4.

Test Case 4 : Explained in problem statement.


#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define fr(i,a,b) for(int i = a; i < b; i++)
#define sum(v) accumulate((v).begin(), (v).end(), 0LL)
#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

typedef vector<int> vi;

void solve() {
    int t; cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;

        int same = n - k + 1;
        
        for(int i = same; i >= 1; i--) cout << i << " ";

        for(int i = same + 1; i <= n; i++) cout << i << " ";

        cout << "\n";
    }
}

// Author: GANESH KARTHIK Bhanupanthula
int32_t main() {
    fast
    solve();
    return 0;
}
