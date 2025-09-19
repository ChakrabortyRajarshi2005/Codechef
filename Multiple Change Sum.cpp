Multiple Change Sum
Given an array 
A
A of length 
N
N.

There is an integer variable 
X
X and a score 
S
S. Initially, 
X
=
0
X=0 and 
S
=
0
S=0.

You play the following single-player game on the array 
A
A for the next 
N
N seconds:

In the 
t
t-th second (
1
≤
t
≤
N
1≤t≤N), you may choose any index 
i
i such that 
1
≤
i
≤
N
1≤i≤N and 
t
∣
i
t∣i (i.e., 
i
i is a multiple of 
t
t).
Then, update the score 
S
S as follows: 
S
=
S
+
∣
X
−
A
i
∣
S=S+∣X−A 
i
​
 ∣.
Then, set 
X
=
A
i
X=A 
i
​
 .
Alternatively, you can also choose to do nothing in the 
t
t-th second (both 
X
X and 
S
S remain unchanged).
Define 
f
(
A
)
f(A) to be the maximum possible final score 
S
S that can be achieved by playing the game optimally.

You are given an array 
A
A of length 
N
N. You need to handle 
Q
Q updates to the array. Each update is of the form 
(
i
,
x
)
(i,x) and means: set 
A
i
=
x
A 
i
​
 =x. Output the value of 
f
(
A
)
f(A) after each update.

Important note on test generation (read carefully): For all the official tests, the update index 
i
i in each pair 
(
i
,
x
)
(i,x) is generated uniformly at random from 
{
1
,
2
,
…
,
N
}
{1,2,…,N}, independently across updates. Note that only the indices are constrained this way, the new values 
x
x may be arbitrary within the given bounds.

Input Format
The first line of input will contain a single integer 
T
T, denoting the number of test cases.
Each test case consists of multiple lines of input.
The first line of each test case contains two space-separated integers 
N
N and 
Q
Q — the number of elements in the array and the number of updates to handle, respectively.
The next line contains 
N
N space-separated integers 
A
1
,
A
2
,
…
,
A
N
A 
1
​
 ,A 
2
​
 ,…,A 
N
​
  — the initial array.
The next 
Q
Q lines describe the updates. The 
k
k-th of these lines contains two space-separated integers 
i
k
i 
k
​
  and 
x
k
x 
k
​
 , indicating the assignment 
A
i
k
=
x
k
A 
i 
k
​
 
​
 =x 
k
​
 .
Output Format
After each update, output on a new line the current value of 
f
(
A
)
f(A).

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
2
⋅
10
5
1≤N≤2⋅10 
5
 
1
≤
Q
≤
5
⋅
10
4
1≤Q≤5⋅10 
4
 
1
≤
A
i
≤
10
9
1≤A 
i
​
 ≤10 
9
 
1
≤
x
k
≤
10
9
1≤x 
k
​
 ≤10 
9
 
1
≤
i
k
≤
N
1≤i 
k
​
 ≤N
Each 
i
k
i 
k
​
  is generated uniformly randomly in the interval 
[
1
,
N
]
[1,N].
The sum of 
N
N across all test cases won't exceed 
2
⋅
10
5
2⋅10 
5
 
The sum of 
Q
Q across all test cases won't exceed 
5
⋅
10
4
5⋅10 
4
 
Sample 1:
Input
Output
3
6 3
5 2 6 7 9 3
3 1
5 4
6 8
4 4
5 10 4 3
1 3
4 8
2 1
1 9
8 5
6 4 3 4 9 8 4 5
7 1
8 5
2 8
6 2
4 3
31
23
28
19
20
22
24
39
39
39
35
35
Explanation:
Test Case 
1
1, After Update 
1
1:

After the first update 
(
i
,
x
)
=
(
3
,
1
)
(i,x)=(3,1), the array becomes 
A
=
[
5
,
2
,
1
,
7
,
9
,
3
]
A=[5,2,1,7,9,3]. Initially, 
X
=
0
X=0 and 
S
=
0
S=0. Here is an optimal sequence of moves that can be performed:

t
=
1
t=1 (allowed 
i
∈
{
1
,
2
,
3
,
4
,
5
,
6
}
i∈{1,2,3,4,5,6}): choose 
i
=
5
i=5 (
A
5
=
9
A 
5
​
 =9).
S
=
0
+
∣
0
−
9
∣
=
9
,
X
=
9.
S=0+∣0−9∣=9,X=9.

t
=
2
t=2 (allowed 
i
∈
{
2
,
4
,
6
}
i∈{2,4,6}): choose 
i
=
2
i=2 (
A
2
=
2
A 
2
​
 =2).
S
=
9
+
∣
9
−
2
∣
=
16
,
X
=
2.
S=9+∣9−2∣=16,X=2.

t
=
3
t=3 (allowed 
i
∈
{
3
,
6
}
i∈{3,6}): choose 
i
=
3
i=3 (
A
3
=
1
A 
3
​
 =1).
S
=
16
+
∣
2
−
1
∣
=
17
,
X
=
1.
S=16+∣2−1∣=17,X=1.

t
=
4
t=4 (allowed 
i
∈
{
4
}
i∈{4}): do nothing.
S
=
17
,
X
=
1.
S=17,X=1.

t
=
5
t=5 (allowed 
i
∈
{
5
}
i∈{5}): choose 
i
=
5
i=5 (
A
5
=
9
A 
5
​
 =9).
S
=
17
+
∣
1
−
9
∣
=
25
,
X
=
9.
S=17+∣1−9∣=25,X=9.

t
=
6
t=6 (allowed 
i
∈
{
6
}
i∈{6}): choose 
i
=
6
i=6 (
A
6
=
3
A 
6
​
 =3).
S
=
25
+
∣
9
−
3
∣
=
31
,
X
=
3.
S=25+∣9−3∣=31,X=3.

Thus, the final score is 
S
=
31
S=31.
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct Node { ll a,b,c1,c,c2,d; };
Node mergeNode(const Node& L,const Node& R){
    Node res;
    res.a = max(L.a + R.a, L.b + R.c);
    res.b = max(L.a + R.b, L.b + R.d);
    res.c1 = max({L.c1, L.a + R.c1, L.b + R.c2});
    res.c = max(L.c + R.a, L.d + R.c);
    res.d = max(L.c + R.b, L.d + R.d);
    res.c2 = max({L.c2, L.c + R.c1, L.d + R.c2});
    return res;
}
int MAXN_PRE = 200005;
vector<vector<int>> divisors_pre;
vector<ll> a;
vector<multiset<ll>> sset;
vector<Node> seg;
void build(int node,int l,int r){
    if(l==r){
        ll mn = *sset[l].begin();
        ll mx = *sset[l].rbegin();
        seg[node].a = 0;
        seg[node].b = -2*mn;
        seg[node].c1 = -mn;
        seg[node].c = 2*mx;
        seg[node].d = 0;
        seg[node].c2 = mx;
    } else {
        int mid=(l+r)/2;
        build(2*node,l,mid);
        build(2*node+1,mid+1,r);
        seg[node]=mergeNode(seg[2*node],seg[2*node+1]);
    }
}
void update(int node,int l,int r,int idx){
    if(l==r){
        ll mn = *sset[idx].begin();
        ll mx = *sset[idx].rbegin();
        seg[node].a = 0;
        seg[node].b = -2*mn;
        seg[node].c1 = -mn;
        seg[node].c = 2*mx;
        seg[node].d = 0;
        seg[node].c2 = mx;
    } else {
        int mid=(l+r)/2;
        if(idx<=mid) update(2*node,l,mid,idx);
        else update(2*node+1,mid+1,r,idx);
        seg[node]=mergeNode(seg[2*node],seg[2*node+1]);
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    divisors_pre.assign(MAXN_PRE, {});
    for(int d=1;d<MAXN_PRE;d++){
        for(int j=d;j<MAXN_PRE;j+=d) divisors_pre[j].push_back(d);
    }
    int T; if(!(cin>>T)) return 0;
    while(T--){
        int n,q; cin>>n>>q;
        a.assign(n+1,0);
        for(int i=1;i<=n;i++) cin>>a[i];
        sset.assign(n+1, multiset<ll>());
        for(int i=1;i<=n;i++){
            for(int j=i;j<=n;j+=i) sset[i].insert(a[j]);
        }
        seg.assign(4*(n+5), Node());
        build(1,1,n);
        while(q--){
            int idx; ll x; cin>>idx>>x;
            ll old = a[idx];
            for(int d : divisors_pre[idx]){
                if(d>n) continue;
                auto it = sset[d].find(old);
                if(it!=sset[d].end()) sset[d].erase(it);
                sset[d].insert(x);
                update(1,1,n,d);
            }
            a[idx]=x;
            Node res = seg[1];
            ll ans = max({0LL, res.c1, res.c2});
            cout<<ans<<"\n";
        }
    }
    return 0;
}
