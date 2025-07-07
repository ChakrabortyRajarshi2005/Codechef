Mex Tree (Min)
The problem is nearly identical to Mex Tree (Max Version) except here you must find the minimum possible score.

You have a tree with 
N
N vertices. A tree is a connected undirected acyclic graph on 
N
N vertices with 
N
−
1
N−1 edges.

You want to assign distinct labels to the vertices of the tree. You will choose a permutation 
P
P of the integers 
[
0
,
N
−
1
]
[0,N−1] and then assign the vertex 
X
X a label of 
P
X
P 
X
​
 .

Define 
M
E
X
(
S
)
MEX(S) for a set 
S
S, as the minimum non-negative integer not present in 
S
S. For example, 
M
E
X
(
{
1
,
0
,
2
,
2
,
4
}
)
=
3
MEX({1,0,2,2,4})=3 and 
M
E
X
(
{
1
}
)
=
0
MEX({1})=0.

Define 
f
(
u
,
v
)
f(u,v) as 
M
E
X
(
{
P
X
1
,
P
X
2
,
P
X
3
,
…
,
P
X
K
}
)
MEX({P 
X 
1
​
 
​
 ,P 
X 
2
​
 
​
 ,P 
X 
3
​
 
​
 ,…,P 
X 
K
​
 
​
 }) where 
X
1
,
X
2
,
…
,
X
K
X 
1
​
 ,X 
2
​
 ,…,X 
K
​
  are the vertices on the unique simple path from 
u
u to 
v
v (including 
u
u and 
v
v themselves, so 
X
1
=
u
X 
1
​
 =u, 
X
K
=
v
X 
K
​
 =v).

Define 
s
c
o
r
e
score of the tree as 
∑
X
=
1
N
∑
Y
=
X
N
f
(
X
,
Y
)
∑ 
X=1
N
​
 ∑ 
Y=X
N
​
 f(X,Y), i.e. the sum of 
f
f over all pairs of vertices.

You must find the minimum possible value of 
s
c
o
r
e
score if you can suitably choose the permutation 
P
P.

Input Format
The first line of input will contain a single integer 
T
T, denoting the number of test cases.
Each test case consists of multiple lines of input.
The first line of each test case contains a single integer 
N
N.
The next 
N
−
1
N−1 lines contain 
2
2 integers each, 
u
u and 
v
v - representing an edge in the tree.
Output Format
For each test case, output on a new line the minimum possible score.

Constraints
1
≤
T
≤
50
1≤T≤50
3
≤
N
≤
2000
3≤N≤2000
1
≤
u
,
v
≤
N
1≤u,v≤N
The set of input edges define a tree
The sum of 
N
N over all test cases does not exceed 
2000
2000.
Sample 1:
Input
Output
2
4
1 2
2 3
3 4
4
1 2
1 3
1 4
7
5
Explanation:
Test Case 1 : We choose 
P
=
[
1
,
2
,
3
,
0
]
P=[1,2,3,0]. The calculations are as follows:

f
(
1
,
1
)
=
0
f(1,1)=0
f
(
1
,
2
)
=
0
f(1,2)=0
f
(
1
,
3
)
=
0
f(1,3)=0
f
(
1
,
4
)
=
4
f(1,4)=4
f
(
2
,
2
)
=
0
f(2,2)=0
f
(
2
,
3
)
=
0
f(2,3)=0
f
(
2
,
4
)
=
1
f(2,4)=1
f
(
3
,
3
)
=
0
f(3,3)=0
f
(
3
,
4
)
=
1
f(3,4)=1
f
(
4
,
4
)
=
1
f(4,4)=1
Adding the values, we get 
4
+
1
+
1
+
1
=
7
4+1+1+1=7. It can be proven a smaller score is impossible.

Did you like the problem statement?
#include<iostream>
#include<vector>

using namespace std;

auto pushing_limits = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

void solve(){
    int n, u, v;
    cin >> n;
    vector<int> degree(n, 0); //degree[i] is the degree of the node i.
    for(int i = 1; i <= n - 1; i++){
        cin >> u >> v;
        degree[u - 1]++;
        degree[v - 1]++;
    }
    int leaves_count = 0; //leaves_count is the number of nodes that are leaves, i.e., nodes with degree 1
    for(int i = 0; i < n; i++){
        if(degree[i] == 1){
            leaves_count++;
            if(leaves_count >= 3)
                break;
        }
    }
    int answer = (n - 1) + (leaves_count >= 3?2:n);
    cout << answer;
    
    cout << endl;
    return;
}

int main(){
    int tt;
    cin >> tt;
    while(tt--){
        solve();
    }
    return 0;
}
