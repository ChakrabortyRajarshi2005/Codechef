Cycle and Add
You're given two arrays 
B
B and 
D
D, both of length 
N
N, as well as an integer 
C
C.
You also have an array 
A
A of length 
N
N initially filled with zeros.

You would like to make the arrays 
A
A and 
D
D equal to each other.
To achieve this, you can perform the following types of moves:

Cyclic shift the array 
A
A right one step.
That is, turn the array 
A
A from 
[
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
]
[A 
1
​
 ,A 
2
​
 ,…,A 
N
​
 ] into 
[
A
N
,
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
−
1
]
[A 
N
​
 ,A 
1
​
 ,A 
2
​
 ,…,A 
N−1
​
 ].
This operation has a cost of 
C
C.
Choose an index 
i
i (
1
≤
i
≤
N
1≤i≤N), and add 
1
1 to 
A
i
A 
i
​
 .
This operation has a cost of 
B
i
B 
i
​
 .
Each type of operation can be performed as many times as you like (including 
0
0), and the operations can be performed in any order you like.

Find the minimum cost of making the arrays 
A
A and 
D
D equal.
It can be proved that it's always possible to achieve this.

Input Format
The first line of input will contain a single integer 
T
T, denoting the number of test cases.
Each test case consists of three lines of input.
The first line of each test case contains two space-separated integers 
N
N and 
C
C — the length of the arrays, and the cost of a cyclic shift.
The second line contains 
N
N space-separated integers 
B
1
,
…
,
B
N
B 
1
​
 ,…,B 
N
​
 .
The third line contains 
N
N space-separated integers 
D
1
,
…
,
D
N
D 
1
​
 ,…,D 
N
​
 .
Output Format
For each test case, output on a new line the answer: the minimum cost of making arrays 
A
A and 
D
D equal.

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
2500
1≤N≤2500
1
≤
B
i
≤
10
6
1≤B 
i
​
 ≤10 
6
 
0
≤
D
i
≤
10
6
0≤D 
i
​
 ≤10 
6
 
1
≤
C
≤
10
6
1≤C≤10 
6
 
The sum of 
N
N over all test cases won't exceed 
2500
2500.
Sample 1:
Input
Output
4
3 2
3 5 4
1 2 0
3 2
3 4 2
2 1 3
4 11
2 3 2 1
5 4 5 1
4 7
4 3 4 2
5 7 6 3
11
15
33
62
Explanation:
Test case 
1
1: One optimal sequence of operations is as follows:

Initially, 
A
=
[
0
,
0
,
0
]
A=[0,0,0] and 
cost
=
0
cost=0.
First, increase 
A
1
A 
1
​
  by 
1
1. This has a cost of 
B
1
=
3
B 
1
​
 =3.
Now, 
A
=
[
1
,
0
,
0
]
A=[1,0,0] and 
cost
=
3
cost=3.
Next, increase 
A
1
A 
1
​
  by 
1
1 again. This has a cost of 
B
1
=
3
B 
1
​
 =3.
Now, 
A
=
[
2
,
0
,
0
]
A=[2,0,0] and 
cost
=
6
cost=6.
Next, perform a cyclic shift operation. This has a cost of 
C
=
2
C=2.
Now, 
A
=
[
0
,
2
,
0
]
A=[0,2,0] and 
cost
=
8
cost=8.
Finally, increase 
A
1
A 
1
​
  by 
1
1 again. This has a cost of 
B
1
=
3
B 
1
​
 =3.
Now, 
A
=
[
1
,
2
,
0
]
A=[1,2,0] and 
cost
=
11
cost=11.
At this point we have 
A
i
=
D
i
A 
i
​
 =D 
i
​
  for all 
i
i, so we're done.
It can be proved that achieving this with a cost of less than 
11
11 is impossible.#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

#define int long long
#define endl '\n'
#define pb push_back
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int,int>
#define all(v) (v).begin(), (v).end()
#define f first
#define s second

//cout << fixed << setprecision(3);


void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}
template<class T> 
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

//"s1.order_of_key()" return index ,,
//*s.find_by_order(1)  return element at that index ,,

template <typename A, typename B>
ostream& operator<<(ostream &os, const vector<pair<A, B>> &v) {
    for (auto &p : v)
        os << "(" << p.first << ", " << p.second << ") ";
    return os;
}


void yes() { cout << "YES\n"; }
void no()  { cout << "NO\n"; }

bool DEBUG = true;
#define debug(x) if(DEBUG) cout << "[DEBUG] " << #x << " = " << (x) << endl


template <typename T>
istream& operator>>(istream &is, vector<T> &v) {
    for (auto &x : v) is >> x;
    return is;
}
template <typename T>
ostream& operator<<(ostream &os, const vector<T> &v) {
    for (auto &x : v) os << x << " ";
    return os;
}
template <typename K, typename V>
ostream& operator<<(ostream &os, const map<K,V> &mp) {
    os << "{ ";
    for (auto &p : mp) {
        os << p.first << ":" << p.second << " ";
    }
    os << "}";
    return os;
}


int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
int lcm(int a, int b) { return a / gcd(a, b) * b; }

// Modular arithmetic
const int MOD = 1e9+7;
int mod_add(int a, int b) { return (a + b) % MOD; }
int mod_sub(int a, int b) { return (a - b + MOD) % MOD; }
int mod_mul(int a, int b) { return (a * b) % MOD; }

int mod_pow(int a, int b, int m = MOD) {
    int res = 1;
    a %= m;
    while (b > 0) {
        if (b & 1) res = (res * a) % m;
        a = (a * a) % m;
        b >>= 1;
    }
    return res;
}

int mod_inv(int a, int m = MOD) { return mod_pow(a, m-2, m); }

//******************************************************************************

int mex(const vector<int>& arr) {
    int n = arr.size();
    vector<bool> present(n + 1, false);  


    for (int x : arr) {
        if (x >= 0 && x <= n) {
            present[x] = true;
        }
    }

   
    for (int i = 0; i <= n; i++) {
        if (!present[i]) return i;
    }

    return n + 1; 
}
vector<int > prefixSum(const vector<int>& arr) {
    int n = arr.size();
    vector<int > pref(n + 1, 0); 
    for (int i = 1; i <= n; i++) {
        pref[i] = pref[i - 1] + arr[i - 1];
    }
    return pref;
}

vector<int> sieve(int n) {
    vector<int> prime, is_prime(n+1, 1);
    is_prime[0] = is_prime[1] = 0;
    for (int i = 2; i <= n; i++) {
        if (is_prime[i]) {
            prime.pb(i);
            for (int j = i*i; j <= n; j += i) is_prime[j] = 0;
        }
    }
    return prime;
}

vector<int> prime_factors(int n) {
    vector<int> factors;
    for (int i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            factors.pb(i);
            n /= i;
        }
    }
    if (n > 1) factors.pb(n);
    return factors;
}
vector<int> divisors(int n) {
    vector<int> divs;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            divs.pb(i);          
            if (i != n / i)      
                divs.pb(n / i);  
        }
    }
    sort(all(divs));
    return divs;
}
//******************************************************************************

// --------------------------
// DSU (Disjoint Set Union)
// --------------------------
struct DSU {
    vi parent, sz;
    DSU(int n) {
        parent.resize(n+1);
        sz.assign(n+1, 1);
        iota(all(parent), 0);
    }
    int find(int x) {
        return parent[x] = (parent[x] == x ? x : find(parent[x]));
    }
    bool unite(int a, int b) {
        a = find(a); b = find(b);
        if (a == b) return false;
        if (sz[a] < sz[b]) swap(a, b);
        parent[b] = a;
        sz[a] += sz[b];
        return true;
    }
};
//******************************************************************************

// Graph Utilities
// --------------------------
vector<vector<int>> adj;
vector<int> vis;

void dfs(int u) {
    vis[u] = 1;
    for (auto v : adj[u]) {
        if (!vis[v]) dfs(v);
    }
}

vector<int> bfs(int start, int n) {
    vector<int> dist(n+1, -1);
    queue<int> q;
    q.push(start);
    dist[start] = 0;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (auto v : adj[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    return dist;
}
//******************************************************************************
// --------------------------
// Precomputation (Factorials)
// --------------------------
const int MAXN = 2e5+5;
int fact[MAXN], invfact[MAXN];

void precompute_factorials() {
    fact[0] = 1;
    for (int i = 1; i < MAXN; i++) fact[i] = fact[i-1] * i % MOD;
    invfact[MAXN-1] = mod_inv(fact[MAXN-1]);
    for (int i = MAXN-2; i >= 0; i--) invfact[i] = invfact[i+1] * (i+1) % MOD;
}

int nCr(int n, int r) {
    if (r < 0 || r > n) return 0;
    return fact[n] * invfact[r] % MOD * invfact[n-r] % MOD;
}




// --------------------------
void solve() {
  int n,c;
  cin>>n>>c;
  vi b(n),d(n);
  cin>>b>>d;
  int mini = LLONG_MAX;
 // int sum  = accumulate(all(d),0LL);
  vvi dp(n+1,vi (n,0));
   
  for(int i=0;i<n;i++){
          dp[0][i] = b[i]*d[i];
  }
  int sum  = accumulate(all(dp[0]),0LL);
   mini = sum;
  for(int i=1;i<n;i++){
          for(int j=0;j<n;j++){
                  dp[i][j] = min(dp[i-1][(j)],d[j]*(b[(j-i+n)%n]));
          }
            sum = accumulate(all(dp[i]),0LL);
           mini = min(mini,i*c + sum);
  }
 
  cout<< mini << endl;
}

int32_t main() {
    fastio();
    precompute_factorials();
    DEBUG = true;
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}
