Tuple Slimes
There are 
N
N slimes arranged in a line, and the attribute of the 
i
i-th slime can be represented by a tuple 
(
A
i
,
B
i
)
(A 
i
​
 ,B 
i
​
 ).

You need to perform the following operations exactly 
N
−
1
N−1 times. At the 
K
K-th 
(
1
≤
K
≤
N
−
1
)
(1≤K≤N−1) operation:

Choose two adjacent indices 
i
i, 
j
j (
1
≤
i
,
j
≤
N
−
K
+
1
1≤i,j≤N−K+1, 
∣
i
−
j
∣
=
1
∣i−j∣=1), and let the 
i
i-th slime eat the 
j
j-th slime.
After this operation, the attribute of the 
i
i-th slime becomes 
(
A
i
+
B
j
,
B
i
−
A
j
−
B
j
)
(A 
i
​
 +B 
j
​
 ,B 
i
​
 −A 
j
​
 −B 
j
​
 ) (and the 
j
j-th slime disappears). Note that after each operation, the number of slimes decreases by 
1
1, and all slimes are reindexed starting from 
1
1. The relative order between uneaten slimes remains unchanged.
After these operations, only one slime 
(
A
1
,
B
1
)
(A 
1
​
 ,B 
1
​
 ) remains. Find the maximum value of 
(
A
1
+
B
1
)
(A 
1
​
 +B 
1
​
 ).

Input Format
The first line of input will contain a single integer 
T
T, denoting the number of test cases.
Each test case consists of multiple lines of input.
The first line of each test case contains one integer 
N
N — the number of slimes.
The next 
N
N lines describe the slimes. The 
i
i-th of these 
N
N lines contains two space-separated integers 
A
i
A 
i
​
  and 
B
i
B 
i
​
 .
Output Format
For each test case, output the maximum value of the final 
(
A
1
+
B
1
)
(A 
1
​
 +B 
1
​
 ).

Constraints
1
≤
T
≤
2
⋅
10
4
1≤T≤2⋅10 
4
 
2
≤
N
≤
500
2≤N≤500
−
10
9
≤
A
i
,
B
i
≤
10
9
−10 
9
 ≤A 
i
​
 ,B 
i
​
 ≤10 
9
 
The sum of 
N
2
N 
2
  over all test cases won't exceed 
2.5
⋅
10
5
2.5⋅10 
5
 .
Sample 1:
Input
Output
3
2
1 2
3 4
3
5 -6
1 2
-1 -3
5
3 8
0 0
-8 7
-7 -2
1 4
6
1
31
Explanation:
Test Case 
1
1:

If you choose slime 
1
1 to eat slime 
2
2, the attribute of slime 
1
1 becomes 
(
A
1
+
B
2
,
B
1
−
A
2
−
B
2
)
=
(
1
+
4
,
2
−
3
−
4
)
=
(
5
,
−
5
)
(A 
1
​
 +B 
2
​
 ,B 
1
​
 −A 
2
​
 −B 
2
​
 )=(1+4,2−3−4)=(5,−5).

If you choose slime 
2
2 to eat slime 
1
1, the attribute of slime 
2
2 becomes 
(
A
2
+
B
1
,
B
2
−
A
1
−
B
1
)
=
(
3
+
2
,
4
−
1
−
2
)
=
(
5
,
1
)
(A 
2
​
 +B 
1
​
 ,B 
2
​
 −A 
1
​
 −B 
1
​
 )=(3+2,4−1−2)=(5,1).

Thus, it is optimal to choose slime 
2
2 to eat slime 
1
1. The answer is 
5
+
1
=
6
5+1=6.# include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
 
using ll = long long;
using u32 = unsigned int;
using u64 = unsigned long long;
using i128 = __int128;
using pi = pair<int, int>;
using vi = vector<int>;
using ti = tuple<int, int, int>;
using pll = pair<ll, ll>;
using vll = vector<ll>;
using tll = tuple<ll, ll, ll>;
template <class T>
using vc = vector<T>;
template <class T>
using pq = priority_queue<T>;
template <class T>
using pqg = priority_queue<T, vector<T>, greater<T>>;
 
template <class T>
constexpr T infty = 0;
template <>
constexpr int infty<int> = 1'000'000'001;
template <>
constexpr ll infty<ll> = ll(infty<int>) * infty<int> * 2;
template <>
constexpr u32 infty<u32> = infty<int>;
template <>
constexpr u64 infty<u64> = infty<ll>;
template <>
constexpr i128 infty<i128> = i128(infty<ll>) * infty<ll>;
template <>
constexpr double infty<double> = infty<ll>;
template <>
constexpr long double infty<long double> = infty<ll>;
 
# define rep1(a) for (std::decay_t<decltype(a)> _ = 0; _ < (a); ++_)
# define rep2(i, a) for (std::decay_t<decltype(a)> i = 0; i < (a); ++i)
# define rep3(i, a, b) for (std::decay_t<decltype(b)> i = a; i < (b); ++i)
# define rep4(i, a, b, c) for (std::decay_t<decltype(b)> i = a; i < (b); i += (c))
# define per1(a) for (std::decay_t<decltype(a)> _ = (a) - 1; _ >= (0); --_)
# define per2(i, a) for (std::decay_t<decltype(a)> i = (a) - 1; i >= (0); --i)
# define per3(i, a, b) for (std::decay_t<decltype(b)> i = (b) - 1; i >= (a); --i)
# define per4(i, a, b, c) for (std::decay_t<decltype(b)> i = (b) - 1; i >= (a); i -= (c))
# define overload4(a, b, c, d, e, ...) e
# define rep(...) overload4(__VA_ARGS__, rep4, rep3, rep2, rep1)(__VA_ARGS__)
# define per(...) overload4(__VA_ARGS__, per4, per3, per2, per1)(__VA_ARGS__) 
# define for_subset(t, s) for (int t = (s); t >= 0; t = (t == 0 ? -1 : (t - 1) & (s)))
 
# define all(x) x.begin(), x.end()
# define len(x) int(x.size())
# define elif else if
# define eb emplace_back
# define mp make_pair
# define mt make_tuple
# define fi first
# define se second
# define stoi stoll
 
int popcnt(int x) {return __builtin_popcount(x);}
int popcnt(u32 x) {return __builtin_popcount(x);}
int popcnt(ll x) {return __builtin_popcountll(x);}
int popcnt(u64 x) {return __builtin_popcountll(x);}
int topbit(int x) {return (x == 0 ? -1 : 31 - __builtin_clz(x));}
int topbit(u32 x) {return (x == 0 ? -1 : 31 - __builtin_clz(x));}
int topbit(ll x) {return (x == 0 ? -1 : 63 - __builtin_clzll(x));}
int topbit(u64 x) {return (x == 0 ? -1 : 63 - __builtin_clzll(x));}
int lowbit(int x) {return (x == 0 ? -1 : __builtin_ctz(x));}
int lowbit(u32 x) {return (x == 0 ? -1 : __builtin_ctz(x));}
int lowbit(ll x) {return (x == 0 ? -1 : __builtin_ctzll(x));}
int lowbit(u64 x) {return (x == 0 ? -1 : __builtin_ctzll(x));}
 
template <typename T, typename U>
T ceil(T x, U y) {
	return (x > 0 ? (x + y - 1) / y : x / y);
}
template <typename T, typename U>
T floor(T x, U y) {
	return (x > 0 ? x / y : (x - y + 1) / y);
}
template <typename T, typename U>
pair<T, T> divmod(T x, U y) {
	T q = floor(x, y);
	return {q, x - q * y};
}
 
template <typename T, typename U>
T SUM(const vector<U>& A) {
	T sum = 0;
	for (auto&& a: A) sum += a;
	return sum;
}
#define MIN(v) *min_element(all(v))
#define MAX(v) *max_element(all(v))
#define LB(c, x) distance((c).begin(), lower_bound(all(c), (x)))
#define UB(c, x) distance((c).begin(), upper_bound(all(c), (x)))
#define UNIQUE(x) sort(all(x)), x.erase(unique(all(x)), x.end()), x.shrink_to_fit()

// 重载比较运算符时需要把重载函数放在chmax,chmin前面,否则会调用系统的默认比较
template <class T, class S>
inline bool chmax(T& a, const S& b) {
	return (a < b ? a = b, 1 : 0);
}
template <class T, class S>
inline bool chmin(T& a, const S& b) {
	return (a > b ? a = b, 1 : 0);
}
 
vc<int> s_to_vi(const string& S, char first_char) {
	vc<int> A(S.size());
	rep(i, S.size()) {A[i] = (S[i] != '?' ? S[i] - first_char : -1);}
	return A;
}
 
template <typename T, typename U>
vector<T> cumsum(vector<U>& A, int off = 1) {
	int N = A.size();
	vector<T> B(N + 1);
	rep(i, N) B[i + 1] = B[i] + A[i];
	if (off == 0) B.erase(B.begin());
	return B;
}
 
//stable sort
template <typename T>
vector<int> argsort(const vector<T>& A) {
	vector<int> ids(len(A));
	iota(all(ids), 0);
	sort(all(ids), [&](int i, int j){
		return (A[i] == A[j] ? i < j : A[i] < A[j]);
	});
	return ids;
}
 
// A[I[0]], A[I[1]], ...
template <typename T>
vc<T> rearrange(const vc<T>& A, const vc<int>& I) {
	vc<T> B(len(I));
	rep(i, len(I)) B[i] = A[I[i]];
	return B;
}
 
template <typename T, typename U>
ostream& operator<<(ostream& os, const pair<T, U>& p) {
  os << p.fi << " " << p.se;
  return os;
}
template <typename Tuple, size_t... Is>
ostream& print_tuple(ostream &os, const Tuple &t, index_sequence<Is...>) {
	bool first = true;
	using expander = int[];
	(void) expander{0, ((void)(os << (first ? "" : " ") << std::get<Is>(t), first = false), 0)...};
	return os;
}
template <typename... Ts>
ostream& operator<<(ostream &os, const tuple<Ts...> &t) {
	return print_tuple(os, t, index_sequence_for<Ts...>{});
}
template <typename T>
ostream& operator<<(ostream& os, const vector<T>& vec) {
  for (size_t i = 0; i < vec.size(); i++) {
    if(i) os << " ";
    os << vec[i];
  }
  return os;
}
template <typename T>
struct is_tuple : std::false_type{};
template <typename... Ts>
struct is_tuple<tuple<Ts...>> : std::true_type{};
template <typename Tuple, size_t... Is>
void debug_print_tuple(ostream &os, const Tuple &t, index_sequence<Is...>) {
	os << "(";
	bool first = true;
	using expander = int[];
	(void) expander{0, ((void)(os << (first ? "" : ", ") << std::get<Is>(t), first = false), 0)...};
	os << ")";
}
template <typename T>
void debug_print(const T &value, ostream &os) {
	if constexpr (is_tuple<T>::value) {
		debug_print_tuple(os, value, std::make_index_sequence<std::tuple_size<T>::value>{});
	} else {
		os << value;	
	}
}
template <typename T, typename U>
void debug_print(const pair<T, U> &p, ostream &os) {
	os << "(";
	debug_print(p.first, os);
	os << ", ";
	debug_print(p.second, os);
	os << ")";
}
template <typename T>
void debug_print(const vector<T> &vec, ostream &os) {
	os << "[";
	bool first = true;
	for (const auto &elem : vec) {
		if (!first) os << ", ";
		first = false;
		debug_print(elem, os);
	}
	os << "]";
}
void bug() {
  cerr << "\n";
  cerr.flush();
}
template <class Head, class... Tail>
void bug(Head&& head, Tail&&... tail) {
  debug_print(head, cerr);
  ((cerr << " ", debug_print(tail, cerr)), ...);
  cerr << "\n";
  cerr.flush();
}
 
void YES(bool t = 1) {cout << (t ? "YES" : "NO") << endl;}
void NO(bool t = 1) {YES(!t);}
void Yes(bool t = 1) {cout << (t ? "Yes" : "No") << endl;}
void No(bool t = 1) {Yes(!t);}
void yes(bool t = 1) {cout << (t ? "yes" : "no") << endl;}
void no(bool t = 1) {yes(!t);}
//-------------------- template ending --------------------

int main ()
{
	ios::sync_with_stdio(false); cin.tie(0);
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		vi a(n), b(n);
		rep(i, n) cin >> a[i] >> b[i];
		vector dp(n, vector(n, vll(3, -1)));
		
		function<ll(int, int, int)> solve = [&](int l, int r, int k) {
			if (dp[l][r][k] != -1) return dp[l][r][k];
			if (l == r) {
				if (k == 0) return dp[l][r][k] = a[l];
				if (k == 1) return dp[l][r][k] = b[l];
				return dp[l][r][k] = a[l] + b[l];
			}
			ll res = (k == 2 ? -infty<ll> : infty<ll>);
			rep(i, l, r) {
				if (k == 0) {
					chmin(res, solve(l, i, 0) + solve(i + 1, r, 1));
					chmin(res, solve(l, i, 1) + solve(i + 1, r, 0));
				} elif (k == 1) {
					chmin(res, solve(l, i, 1) - solve(i + 1, r, 2));
					chmin(res, solve(i + 1, r, 1) - solve(l, i, 2));
				} else {
					chmax(res, solve(l, i, 2) - solve(i + 1, r, 0));
					chmax(res, solve(i + 1, r, 2) - solve(l, i, 0));
				}
			}
			return dp[l][r][k] = res;
		};
		
		cout << solve(0, n - 1, 2) << endl;
	}
	return 0;
}
