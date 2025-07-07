Shop Game (Easy)
This problem has the same setup as the hard version. The difference is here you only need the value of the whole string, while in the hard version you need the sum over all substrings.

You are the owner of a shop with 
N
N different unique items to sell, numbered 
1
,
2
,
…
,
N
1,2,…,N. The items have been numbered such that item 
i
i is always larger (in size) than item 
i
−
1
i−1. The cost of the 
i
i-th item is 
C
i
C 
i
​
 . The cost of an item does not have any correlation with the size.

There is a display zone in your shop, and customers are only able to see items that are on the display zone. The rules are as follows:

At the start of each day, you can choose to add some items to the display zone.
Once an item has been placed on the display zone, it cannot be removed until a customer buys it.
When a customer comes, he must see at least 
2
2 different items on the display zone, to ensure that he has some freedom of choice.
Once a customer buys an item, it cannot be bought by another customer, and it cannot be kept on the display zone.
K
(
1
≤
K
<
N
)
K(1≤K<N) customers will come to your shop, one by one, on days 
1
1, 
2
2, 
…
…, 
K
K respectively. On the 
i
i-th day, the customer has a preference of 
A
i
A 
i
​
 , where 
A
i
=
0
A 
i
​
 =0 means that he will buy the smallest item (which is present on the display zone), and 
A
i
=
1
A 
i
​
 =1 means that he will buy the largest item (which is present on the display zone). Note that 
A
A is a binary string.

You want to maximize the total revenue that you get. Your revenue is the sum of 
C
i
C 
i
​
  over all sold items.

Let 
f
(
A
)
f(A) denote the maximum possible revenue corresponding to the binary string 
A
A of length 
K
K (representing the preferences of the customers).

You are given 
N
N, the cost of all items 
C
i
C 
i
​
  and a binary string 
A
A of length 
K
K.

Find 
f
(
A
)
f(A) modulo 
10
9
+
7
10 
9
 +7.

Input Format
The first line of input will contain a single integer 
T
T, denoting the number of test cases.
Each test case consists of multiple lines of input.
The first line of each test case contains 
2
2 integers 
N
N and 
K
K - the number of items, and the number of customers.
The second line contains 
N
N integers - 
C
1
,
C
2
,
…
,
C
N
C 
1
​
 ,C 
2
​
 ,…,C 
N
​
 .
The third line contains a binary string 
A
A of length 
K
K.
Output Format
For each test case, output on a new line 
f
(
A
)
f(A) modulo 
10
9
+
7
10 
9
 +7.

Constraints
1
≤
T
≤
10
4
1≤T≤10 
4
 
2
≤
N
≤
2
⋅
10
5
2≤N≤2⋅10 
5
 
1
≤
K
<
N
1≤K<N
1
≤
C
i
≤
10
9
1≤C 
i
​
 ≤10 
9
 
A
i
∈
{
0
,
1
}
A 
i
​
 ∈{0,1}
∣
A
∣
=
K
∣A∣=K
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
4
2 1
3 10
1
3 2
10 5 4
11
3 2
10 5 4
10
7 4
1000000000 1000000000 1000000000 1000000000 1000000000 1000000000 1000000000
1111
10
9
15
999999979
Explanation:
Test Case 1: We are forced to keep both the 
2
2 items on display zone for the first and only customer (due to the constraint of at least 
2
2 items on display). The customer buys the larger item, which is item 
2
2, and that gives us a revenue of 
10
10.

Test Case 2: For the first customer, we keep all the items 
1
1, 
2
2 and 
3
3 on display. He buys the largest item, i.e. item 
3
3. Then, the second customer comes and buys item numbered 
2
2.

Test Case 4: Do not forget to print your answer modulo 
10
9
+
7
10 
9
 +7.

Did you like the problem statement?
11 users found this helpful

#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl '\n'

ll mod = 1e9+7;

struct fenwick {
    int n;
    vector<ll> t;
    fenwick(int _n){
        n = _n;
        t = vector<ll>(n+5);
    }

    void add(int x, ll v) {
        for (; x <= n; x += x & -x) t[x] += v;
    }

    ll sum(int x)  {
        ll s = 0;
        for (; x > 0; x -= x & -x) s += t[x];
        return s;
    }

    int kth(ll k) {
        int idx = 0;
        for (int bit = 1 << (31 - __builtin_clz(n)); bit; bit >>= 1) {
            int nxt = idx + bit;
            if (nxt <= n && t[nxt] < k) {
                idx = nxt;
                k -= t[nxt];
            }
        }
        return idx + 1;
    }
};

ll sum_top_k(int k, fenwick &cnt, fenwick &sm, vector<ll> &Wdesc) 
{
    if (k <= 0) return 0;
    int thr = cnt.kth(k);
    ll used = cnt.sum(thr-1);
    ll before = sm.sum(thr-1);
    return before + (ll)(k - used) * Wdesc[thr];
}

void solve(){
    int n, k; cin >> n >> k;
    vector<ll> arr(n+1);
    for (int i = 1; i <= n; i++) cin >> arr[i];

    string s; cin >> s;
    int L = 0, R = 0;
    for (int i = k-1; i >= 0; i--) {
        if (s[i] == '0') L++;
        else break;
    }
    for (int i = 0; i < k; i++) {
        if (s[i] == '0') R = i+1;
    }

    vector<ll> all(arr.begin()+1, arr.end());
    sort(all.begin(), all.end(), greater<ll>());
    all.erase(unique(all.begin(), all.end()), all.end());
    int M = all.size();

    vector<ll> Wdesc(M+1);
    for (int i = 0; i < M; i++) 
        Wdesc[i+1] = all[i];

    vector<int> comp(n+1);
    for (int i = 1; i <= n; i++) {
        comp[i] = lower_bound(all.begin(), all.end(), arr[i], greater<ll>()) - all.begin() + 1;
    }

    fenwick cntL(M), sumL(M), cntR(M), sumR(M);
    for (int i = 1; i <= n; i++){
        int r = comp[i];
        cntR.add(r, 1);
        sumR.add(r, arr[i]);
    }

    ll ans = 0;
    for (int s = 1; s <= n; s++) {
        int r = comp[s];
        cntR.add(r, -1);
        sumR.add(r, -arr[s]);

        int left_sz  = s-1;
        int right_sz = n-s;
        int lo = max(L, k - right_sz);
        int hi = min(R, left_sz);

        if (lo <= hi) {
            int pstar = lo;
            if (lo < hi) {
                auto f = [&](int p){
                    ll wL = sum_top_k(p+1, cntL, sumL, Wdesc) - sum_top_k(p, cntL, sumL, Wdesc);
                    int rem = k - p;
                    ll wR = rem>0 ? sum_top_k(rem,   cntR, sumR, Wdesc) - sum_top_k(rem-1, cntR, sumR, Wdesc) : 0;
                    return wL > wR;
                };
                if (!f(lo)) {
                    pstar = lo;
                } else if (f(hi-1)) {
                    pstar = hi;
                } else {
                    int Lp = lo, Rp = hi-1;
                    while (Lp+1 < Rp) {
                        int mid = (Lp+Rp)/2;
                        if (!f(mid)) Rp = mid;
                        else Lp = mid;
                    }
                    pstar = Rp;
                }
            }
            ll cur = sum_top_k(pstar, cntL, sumL, Wdesc) + sum_top_k(k-pstar, cntR, sumR, Wdesc);
            ans = max(ans, cur);
        }

        cntL.add(r, 1);
        sumL.add(r, arr[s]);
    }

    cout << ans % mod<< endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) solve();
    return 0;
}
