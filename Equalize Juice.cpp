Equalize Juice
Chef is hosting a party. In preparation, he has laid out 
N
N glasses of juice on a table, all in a line.
The 
i
i-th glass from the left initially has 
A
i
A 
i
​
  units of juice.

For aesthetic reasons, Chef would really like all the glasses to have an equal amount of juice.
To achieve this, he can do the following:

Choose an index 
i
i (
1
≤
i
≤
N
1≤i≤N).
Choose two non-negative integers 
x
x and 
y
y such that 
x
+
y
≤
A
i
x+y≤A 
i
​
 .
Then,
If 
i
>
1
i>1, pour 
x
x units of juice into glass 
i
−
1
i−1, i.e. increase 
A
i
−
1
A 
i−1
​
  by 
x
x.
If 
i
<
N
i<N, pour 
y
y units of juice into glass 
i
+
1
i+1, i.e. increase 
A
i
+
1
A 
i+1
​
  by 
y
y.
Remove glass 
i
i from the table. This reduces 
N
N by 
1
1.
Re-index the remaining glasses to start from 
1
1, left-to-right.
Find the minimum number of such operations that Chef needs, to ensure that all remaining glasses have an equal amount of juice remaining.

Input Format
The first line of input will contain a single integer 
T
T, denoting the number of test cases.
Each test case consists of two lines of input.
The first line of each test case contains a single integer 
N
N — the initial number of glasses.
The second line contains 
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
  — the initial amounts of juice in the glasses.
Output Format
For each test case, output on a new line the answer: the minimum number of operations needed to make all the glasses have an equal amount of juice.

Constraints
1
≤
T
≤
1000
1≤T≤1000
1
≤
N
≤
5000
1≤N≤5000
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
 
The sum of 
N
N over all test cases won't exceed 
5000
5000.
Sample 1:
Input
Output
3
3
1 6 2
4
7 7 7 7
5
4 3 1 1 2
1
0
3
Explanation:
Test case 
1
1: Choose 
i
=
2
i=2, 
x
=
3
x=3, 
y
=
2
y=2 (which is valid because 
x
+
y
≤
A
2
=
6
x+y≤A 
2
​
 =6).
This corresponds to pouring 
3
3 units into the left glass and 
2
2 units into the right one, and then removing the middle glass.
After this, the glasses have quantities 
[
4
,
4
]
[4,4], so we're done.

Test case 
2
2: All the glasses have equal quantities already, no moves are needed.

Test case 
3
3: One optimal sequence of operations is as follows.

Choose 
i
=
3
,
x
=
1
,
y
=
0
i=3,x=1,y=0. The glasses are now 
[
4
,
4
,
1
,
2
]
[4,4,1,2].
Choose 
i
=
3
,
x
=
0
,
y
=
1
i=3,x=0,y=1. The glasses are now 
[
4
,
4
,
3
]
[4,4,3].
Choose 
i
=
2
,
x
=
1
,
y
=
2
i=2,x=1,y=2. The glasses are now 
[
5
,
5
]
[5,5], and we're done.
It can be shown that using two or fewer moves is not possible.
#include <algorithm>
#include <bits/stdc++.h>
#define all(vec) vec.begin(),vec.end()
#define PB push_back
#define PF push_front
#define EB emplace_back
#define EF emplace_front
#define EM emplace
#define FI first
#define SE second
#define pct __builtin_popcountll
#define ctz __builtin_ctzll
#define lson(o) (o<<1)
#define rson(o) (o<<1|1)
#define SZ(a) ((long long) a.size())
#define FOR(i, a, b) for (int i = (a); i <= (b); ++i)
#define ROF(i, a, b) for (int i = (a); i >= (b); --i)
#define debug(var) cerr << #var <<":"<<var<<"\n";
#define cend cerr<<"\n-----------\n"
#define fsp(x) fixed<<setprecision(x)
#define minn(vec) *min_element(vec.begin(),vec.end())
#define maxx(vec) *max_element(vec.begin(),vec.end())

using namespace std;
#ifdef LOCAL
template<typename T> void _print(T x) { cerr << x; }
// 可以打印多层数组，但是格式不是很好
template<typename T> void _print(vector<T> v) { cerr << "[ "; for (T i : v) _print(i), cerr << " "; cerr << "]"; }
template<typename T> void _print(set<T> s) { cerr << "{ "; for (T i : s) _print(i), cerr << " "; cerr << "}"; }
template<typename T, typename U> void _print(pair<T, U> p) { cerr << "{"; _print(p.first); cerr << ", "; _print(p.second); cerr << "}"; }
template<typename T, typename U> void _print(map<T, U> m) { cerr << "{ "; for (auto &p : m) _print(p), cerr << " "; cerr << "}"; }
// 打印两层数组，格式好一些
template<typename T> void _print(vector<vector<T>> v){cerr<<"{\n";for (auto i : v) _print(i), cerr << "\n";cerr<<" }";}
#endif

using  ll = long long;using ull = unsigned long long;
using ld=double;using LD=long double;
using i128 = __int128;
using pdd = pair<ld,ld>;using plb = pair<ll,bool>;
using pll = pair<ll,ll>;using vll=vector<ll>;using vb=vector<bool>;
using tll = tuple<ll,ll,ll>;using vii=vector<int>;
using vpll = vector<pll>;using vtll = vector<tll>;
using vdb = vector<ld>;using vc=vector<char>;
using arr3 = array<ll,3> ;using arr2 = array<ll,2>;
using CD=complex<double>;
static constexpr ll MAXN=(ll)1e6+10,INF=(ll)1e17+3; // 1e17+3是素数 1e18+9是素数
static constexpr ll mod=(ll)1e9+7; // 998244353;
static constexpr double eps=1e-8;const double pi=acos(-1.0);
ll N,M,Q,X,K,T,lT;

inline void __();
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    
    cin>>lT;
    while(lT--)
        __();
    return 0;
}
/*

*/
inline void __(){
    cin>>N;
    vll A(N+5);
    FOR(i,1,N){
        cin>>A[i];
    }
    vll li(A.begin()+1,A.begin()+N+1);
    sort(all(li));li.resize(unique(all(li))-li.begin());
    ll ans=INF;
// #ifdef LOCAL
//     cerr<<"OK\n";
// #endif
    for(auto x:li){
        auto findi1=[&](ll st)->pll {
            ll sum=0;
            FOR(i,st,N){
                if(A[i]<=x){
                    return {i,sum};
                }
                sum+=A[i];
            }
            return {N+1,sum};
        };
        auto [st,sum]=findi1(1);
        ll need=0;
        ll lans=N;
        while (st<=N) {
            need=x-A[st]-sum;
            ll ost=st;
            if(need>0){
                while (need>0 && st<=N) {
                    ll add=0;
                    if(st!=ost) add=A[st];
                    tie(st,sum)=findi1(st+1);
                    sum+=add;
                    need-=sum;
                }
                sum=abs(need);
            }else{
                tie(st,sum)=findi1(st+1);
            }
            if(need<=0) lans--;
        }
        ans=min(lans,ans);
#ifdef LOCAL
    debug(x);
#endif
    }
    cout<<ans<<"\n";
}
/*

*/
