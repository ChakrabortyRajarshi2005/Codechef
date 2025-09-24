Mirror Jump
There are 
N
N points on the number line, labeled 
1
1 to 
N
N from left to right.
Chef is initially standing at point 
K
K.

Chef's goal is to reach point 
N
N. To do this, he can perform the following types of moves:

Move one step left - that is, if he is currently at point 
X
X, he can move to point 
X
−
1
X−1.
Move one step right - that is, if he is currently at point 
X
X, he can move to point 
X
+
1
X+1.
Mirror his position about the segment 
[
1
,
N
]
[1,N].
This means, if he is currently at point 
X
X, he will instantly move to point 
N
+
1
−
X
N+1−X.
The three types of moves can each be performed however many times he likes, and in any order.
Chef's position must lie in 
[
1
,
N
]
[1,N] at all times.

Find the minimum number of moves needed for Chef to reach point 
N
N, starting at 
K
K.

Input Format
The first line of input will contain a single integer 
T
T, denoting the number of test cases.
The first and only line of input will contain two space-separated integers 
N
N and 
K
K.
Output Format
For each test case, output on a new line the minimum number of moves Chef needs to reach point 
N
N.

Constraints
1
≤
T
≤
210
1≤T≤210
1
≤
N
≤
20
1≤N≤20
1
≤
K
≤
N
1≤K≤N
Sample 1:
Input
Output
4
10 6
10 3
7 1
3 3
4
3
1
0
Explanation:
Test case 
1
1: Chef starts at 
K
=
6
K=6 and wants to reach position 
N
=
10
N=10.
The fastest way is to just move one step to the right four times.

Test case 
2
2: Chef starts at 
K
=
3
K=3 and wants to reach position 
10
10.
This can be done in three moves, one method is as follows:

Move one step left. Chef's position is now 
2
2.
Mirror his position. Chef's position is now 
N
−
2
+
1
=
10
−
2
+
1
=
9
N−2+1=10−2+1=9.
Move one step right. Chef's position is now 
10
10.
Test case 
3
3: Chef is at position 
1
1.
If he mirrors his position, he will immediately end up at position 
N
N. So, the answer is 
1
1.

Test case 
4
4: 
N
=
K
N=K, so Chef is already at his target position. No moves are needed.
#pragma optimization (Ofast)
#pragma GCC optimization ("unroll-loops")
//#pragma GCC target (“avx , avx2”)
//#pragma GCC optimization (“01 , 02 , O3”)

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>

const int Mod = 1e9 + 7;

using namespace std;
using namespace __gnu_pbds;

#define int            long long int
#define double         long double
#define fast           cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
#define nl             cout << "\n"
#define fr(i, a, b)    for (int i = (a);i < (b); i++)
#define rfr(i, a, b)   for (int i = (a);i >=(b); i--)
#define afr(arr, a)    for (int i = (0);i < (a); i++) cin >> arr[i]
#define ff             first
#define ss             second
#define pb             push_back
#define sz(x)          ((int)(x).size())
#define ci(v)          for (auto & a : (v)) cin >> a;
#define co(v)          for (auto & a : (v)) cout << a <<" ";
#define cfr(i,x)       for (auto & i : (x))
#define ciso(x)        for (auto & i : (x)) cout << i.first << " "<<i.second << "\n"
#define all(x)         (x).begin(),(x).end()
#define rall(x)        (x).begin(),(x).end(),greater<int>()
#define yes            cout << "Yes\n"
#define no             cout << "No\n"
#define out(ans)       cout << ans << '\n'
#define xout(ans)      cout << ans << " "
#define yn(a)          (a)? cout << "Yes\n" : cout << "No\n"
#define mxe(n)         *max_element(n.begin(), n.end())
#define mne(n)         *min_element(n.begin(), n.end())
#define bin(x,y)       bitset<y>(x)
#define unq(v)         v.resize(distance(v.begin(), unique(v.begin(), v.end())));

template <class T> using V = vector<T>;
template <class T> using S = set<T>;
template <class T> using US = unordered_set<T>;
template <class U, class V> using P = pair<U,V>;
template <class U, class V> using M = map<U,V>;
template <class U, class V> using UM = unordered_map<U,V>;

void solve(){
    int n,k; cin >> n >> k;
    out(min(n - k, k));
}

int32_t main(){
fast; int t(1); cin >> t; while(t--) solve();
}
