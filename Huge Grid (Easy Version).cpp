Huge Grid (Easy Version)
This is the easy version of the problem. Here yout task is to find the minimum possible path sum.

Given a binary sequence 
A
A of length 
N
N, we construct an 
N
×
N
N×N matrix 
B
B as follows:

If 
i
≤
j
i≤j, then 
B
i
,
j
=
∑
k
=
i
j
A
k
B 
i,j
​
 =∑ 
k=i
j
​
 A 
k
​
 .
Otherwise, 
B
i
,
j
=
B
j
,
i
B 
i,j
​
 =B 
j,i
​
 .
Define a path from 
(
1
,
1
)
(1,1) to 
(
N
,
N
)
(N,N) as a sequence of pairs:

P
=
[
(
i
1
,
j
1
)
,
(
i
2
,
j
2
)
,
…
,
(
i
2
N
−
1
,
j
2
N
−
1
)
]
,
P=[(i 
1
​
 ,j 
1
​
 ),(i 
2
​
 ,j 
2
​
 ),…,(i 
2N−1
​
 ,j 
2N−1
​
 )],
where:

(
i
1
,
j
1
)
=
(
1
,
1
)
(i 
1
​
 ,j 
1
​
 )=(1,1) and 
(
i
2
N
−
1
,
j
2
N
−
1
)
=
(
N
,
N
)
(i 
2N−1
​
 ,j 
2N−1
​
 )=(N,N).
(
i
k
+
1
,
j
k
+
1
)
=
(
i
k
+
1
,
j
k
)
(i 
k+1
​
 ,j 
k+1
​
 )=(i 
k
​
 +1,j 
k
​
 ) or 
(
i
k
,
j
k
+
1
)
(i 
k
​
 ,j 
k
​
 +1) for 
1
≤
k
<
2
N
−
1
1≤k<2N−1.
The path sum is defined as 
∑
(
i
,
j
)
∈
P
B
i
,
j
∑ 
(i,j)∈P
​
 B 
i,j
​
 .
Your task is to find the minimum possible path sum.

Input Format
The first line of input will contain a single integer 
T
T, denoting the number of test cases.
Each test case consists of multiple lines of input.
The first line of each test case contains an integer 
N
N.
The second line contains a binary string 
A
A of length 
N
N.
Output Format
For each test case, output on a new line: the minimum possible path sum.

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
6
1≤N≤10 
6
 
0
≤
A
i
≤
1
0≤A 
i
​
 ≤1
The sum of 
N
N over all test cases won't exceed 
10
6
10 
6
 .
Sample 1:
Input
Output
3
3
011
4
0000
1
1
5
0
1
Explanation:
Test Case 
1
1:

The matrix 
B
B is shown as follows:

0
0	
1
1	
2
2
1
1	
1
1	
2
2
2
2	
2
2	
1
1
We can see the minimum possible path sum is 
5
5. There are 
4
4 different paths that achieve the minimum possible path sum:

[
(
1
,
1
)
,
(
1
,
2
)
,
(
2
,
2
)
,
(
2
,
3
)
,
(
3
,
3
)
]
[(1,1),(1,2),(2,2),(2,3),(3,3)]
[
(
1
,
1
)
,
(
2
,
1
)
,
(
2
,
2
)
,
(
2
,
3
)
,
(
3
,
3
)
]
[(1,1),(2,1),(2,2),(2,3),(3,3)]
[
(
1
,
1
)
,
(
1
,
2
)
,
(
2
,
2
)
,
(
3
,
2
)
,
(
3
,
3
)
]
[(1,1),(1,2),(2,2),(3,2),(3,3)]
[
(
1
,
1
)
,
(
2
,
1
)
,
(
2
,
2
)
,
(
3
,
2
)
,
(
3
,
3
)
]
[(1,1),(2,1),(2,2),(3,2),(3,3)]

#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#include <chrono>
using namespace std;

#define fast_io ios_base::sync_with_stdio(false); cin.tie(nullptr)
mt19937_64 RNG(static_cast<uint64_t>(chrono::steady_clock::now().time_since_epoch().count()));
#define int long long
#define ll __int128
#define ull unsigned long long
#define vi vector<int>
#define vvi vector<vi>
#define vc vector<char>
#define vvc vector<vc>
#define vs vector<string>
#define vb vector<bool>
#define pii pair<int, int>
#define si set<int>
#define usi unordered_set<int>
#define mii map<int, int>
#define umi unordered_map<int,int>
#define qi queue<int>
#define pq priority_queue
#define di deque<int>
#define msi multiset<int>
#define umsi unordered_multiset<int>
#define pb push_back
#define eb emplace_back
#define ff first
#define ss second
#define mod1 1000000007
#define mod2 998244353
#define inf LLONG_MAX
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define in(a) int a; cin >> a
#define enter cout<<endl
#define rep(i, a, b) for (int i = a; i < b; i++)
#define rrep(i, a, b) for (int i = a; i >= b; i--)
#define trav(a, x) for (auto& a : x)
#define total(a) accumulate(a.begin(), a.end(), 0LL)
#define take(a,n) vi a(n); rep(i, 0, n) cin>>a[i]
#define debug(x) cerr << #x << " = " << x << endl
#define debugv(v) for (auto i : v) cerr << i << " "; cerr << endl
#define print(a) trav(i,a) cout<<i<<" ";enter
#define p(x) cout<<x<<endl



void solve()
{
    in(n);
    string a; cin>>a;
    
    vi pre(n+1,0);
    rep(i,1,n+1) pre[i]=pre[i-1]+(a[i-1]=='1');
    
    int i=1,j=1;
    int ans=0;
    while(i!=n and j!=n)
    {
        ans+=pre[j]-pre[i-1];
        j++;
        ans+=pre[j]-pre[i-1];
        i++;
    }
    if(a.back()=='1') ans++;
    p(ans);
}



int32_t main()
{
    fast_io;
    //auto begin = chrono::high_resolution_clock::now();

    int t = 1;
    cin >> t;

    while (t--)
    {
        solve();
    }

    /*auto end = chrono::high_resolution_clock::now();
    auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";*/
    return 0;
}
