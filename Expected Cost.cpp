Expected Cost
You are on a one-dimensional number line, initially at 
x
=
1
x=1. You want to reach 
x
=
N
+
1
x=N+1.

You can do the following 
2
2 actions when you are at 
x
(
x
≤
N
)
x(x≤N):

Pay a cost of 
A
x
A 
x
​
  and move to 
x
+
1
x+1.
Pay a cost of 
B
x
B 
x
​
  and move to a random position among the positions 
x
=
1
,
2
,
…
,
N
+
1
x=1,2,…,N+1. All of the 
N
+
1
N+1 possibilities are equiprobable.
Find the minimum expected cost to reach 
N
+
1
N+1 if we make decisions optimally.

Input Format
The first line of input will contain a single integer 
T
T, denoting the number of test cases.
Each test case consists of multiple lines of input.
The first line of each test case contains 
N
N.
The second line contains 
N
N integers - 
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
 .
The third line contains 
N
N integers - 
B
1
,
B
2
,
…
,
B
N
B 
1
​
 ,B 
2
​
 ,…,B 
N
​
 .
Output Format
For each test case, output on a new line the minimum expected cost to reach 
N
+
1
N+1.

Your answer will be marked correct if either the absolute or the relative error does not exceed 
10
−
6
10 
−6
 .

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
A
i
,
B
i
≤
10
6
1≤A 
i
​
 ,B 
i
​
 ≤10 
6
 
The sum of 
N
N over all test cases does not exceed 
2
⋅
10
5
2⋅10 
5
 .
Sample 1:
Input
Output
5
1
5
2
1
2
5
2
10 2
1 10
3
1 2 3
3 2 1
6
67 15 44 35 28 11
22 12 23 12 5 30
4.0
2.0
2.5
6.0
61.666667
Explanation:
Test Case 1 : The optimal strategy is to always use the randomize operation when we are at 
x
=
1
x=1. Then, the probability that we reach 
x
=
2
x=2 in exactly 
i
i turns can be shown to be 
1
2
i
2 
i
 
1
​
  and the associated cost is 
2
⋅
i
2⋅i.

Summing up the infinite series, 
∑
i
=
1
inf
⁡
2
⋅
i
⋅
1
2
i
∑ 
i=1
inf
​
 2⋅i⋅ 
2 
i
 
1
​
 , we get 
4
4.

Test Case 2 : The optimal strategy is just to use the normal operation of going to 
x
+
1
x+1 when we are at 
x
=
1
x=1. The guaranteed cost of this operation is 
2
2.

#include <bits/stdc++.h>
using namespace std;

#ifndef LOCAL
    #define dbg(...) (void(0))
    #define debug() if (0)
#endif

template<class F> struct y_comb_t {
    F f;
    template<class T> y_comb_t(T &&_f) : f(forward<T>(_f)) {}
    template<class... Args> decltype(auto) operator()(Args &&...args) {
        return f(/* ref */ (*this), forward<Args>(args)...);
    }
};
template<class F> y_comb_t<decay_t<F>> y_comb(F &&f) { return {forward<F>(f)}; }

template<class T, class U> bool chmin(T &a, const U &b) {
    return a > b ? a = b, 1 : 0;
}
template<class T, class U> bool chmax(T &a, const U &b) {
    return a < b ? a = b, 1 : 0;
}
template<int N, class T> auto mk_arr(T x) {
    array<T, N> a;
    return a.fill(x), a;
}

using i32 = int32_t;
using u32 = uint32_t;
using i64 = int64_t;
using u64 = uint64_t;
using str = string;
using f80 = long double;
#define all(a) begin(a), end(a)
#define len(a) ((int)(a.size()))

const f80 eps = 1e-8;

void solve() {
    i32 n;
    cin >> n;
    vector<i32> a(n), b(n);
    for (auto &i : a) cin >> i;
    for (auto &i : b) cin >> i;
    auto check = [&](f80 s, f80 &v) {
        f80 sm = 0;
        v = 0;
        for (int i = n - 1; i >= 0; i--)
            sm += v = min(v + a[i], s / (n + 1) + b[i]);
        return sm > s;
    };
    f80 l = 0, r = 1e15, m, x = 0;
    for (int i = 0; i < 100; i++) {
        m = (l + r) / 2;
        (check(m, x) ? l : r) = m;
    }
    cout << x << "\n";
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(10);
    int t = 1;
    cin >> t;
    while (t--) solve();
}
