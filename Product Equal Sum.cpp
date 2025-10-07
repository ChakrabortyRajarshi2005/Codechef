Product Equal Sum
An array 
A
A of length 
N
N is said to be good if 
A
1
⋅
A
2
⋅
…
A
N
=
A
1
+
A
2
+
…
+
A
N
A 
1
​
 ⋅A 
2
​
 ⋅…A 
N
​
 =A 
1
​
 +A 
2
​
 +…+A 
N
​
 , i.e. product equals sum.

Given an array 
A
A of length 
N
N, count how many subarrays of 
A
A are good. Formally, find the number of pairs 
(
L
,
R
)
(L,R) such that:

1
≤
L
≤
R
≤
N
1≤L≤R≤N
The array 
[
A
L
,
A
L
+
1
,
A
L
+
2
,
…
,
A
R
]
[A 
L
​
 ,A 
L+1
​
 ,A 
L+2
​
 ,…,A 
R
​
 ] is good.
Input Format
The first line of input will contain a single integer 
T
T, denoting the number of test cases.
Each test case consists of multiple lines of input.
The first line of each test case contains 
N
N - the size of the array.
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
Output Format
For each test case, output on a new line the number of good subarrays of 
A
A.

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
≤
N
1≤A 
i
​
 ≤N
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
3
2 1 3
4
2 2 2 2
6
1 2 1 4 1 1
1
1
4
7
8
1
Explanation:
Test case 1 : The good subarrays are 
[
2
]
,
[
1
]
,
[
3
]
[2],[1],[3] and 
[
2
,
1
,
3
]
[2,1,3].

Test Case 2 : 
[
2
]
[2] and 
[
2
,
2
]
[2,2] are good. 
[
2
]
[2] occurs 
4
4 times, and 
[
2
,
2
]
[2,2] occurs 
3
3 times.#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<pii> vpii;
typedef vector<vi> vvi;

#define pb push_back
#define all(x) x.begin(), x.end()
#define fr(i, start, n) for (int i = start; i < n; i++)

const ll MOD = 1e9 + 7;
#define N 1e7 + 5

void solve()
{
    int n;
    cin>>n;
    
    vll temp(n);
    
    fr(i,0,n) cin>>temp[i];
    
    vll v, index, ones;
    
    int countOnes = 0;
    int totalOnes = 0;
    int ind = 0;
    ll limit = 0;
    fr(i,0,n) {
        if(temp[i] != 1) {
            v.pb(temp[i]);
            index.pb(i);
            ones.pb(countOnes);
            countOnes = 0;
        }
        else {
            totalOnes++;
            countOnes++;
        }
        limit += temp[i];
    }
    int m = index.size();
    
    if(m==0) {
        cout<<totalOnes<<endl;
        return;
    }
    
    ones.pb(countOnes);
    
    // for(ll a: v) cout<<a<<" ";
    // cout<<endl;
    // for(ll a: index) cout<<a<<" ";
    // cout<<endl;
    // for(ll a: ones) cout<<a<<" ";
    // cout<<endl;
    
    // return;
    
    ll ans = totalOnes;
    for(int i = 0; i<n; i++) {
        int ind = lower_bound(all(index), i) - index.begin();
        ll prod = 1;
        ll sum = (index[ind] - i);
        
        // cout<<i<<endl;
        // cout<<prod<<" "<<sum<<endl;
        
        for(int j = ind; j<m; j++) {
            prod *= v[j];
            sum += v[j];
            if(sum <= prod and sum + ones[j + 1] >= prod){ 
                ans++;
                // cout<<sum <<prod<<endl;
            }
            if(prod > limit) break;
            sum += ones[j + 1];
        }
    }
    
    cout<<ans<<endl;
    // cout<<endl;
    
}
int main()
{
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}
