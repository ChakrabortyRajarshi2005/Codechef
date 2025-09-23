Cities Colours
You once again find yourself exploring the beautiful region of Chefland.

There are 
N
N cities in a row. Each city has a color preference of 
C
i
C 
i
​
  and has a wealth of 
W
i
W 
i
​
 . Initially, you are at city 
1
1 with a color of 
0
0, and you have 
0
0 coins. For simplicity's sake, it is guaranteed that 
C
1
=
W
1
=
0
C 
1
​
 =W 
1
​
 =0. Then, you may perform any of the following operations:

Set your color to any integer you wish. This reduces the amount of coins you have by 
K
K.
Move from city 
i
i to city 
i
+
1
i+1. If your current color is the same as 
C
i
+
1
C 
i+1
​
 , you will gain 
W
i
+
1
W 
i+1
​
  coins. Otherwise, you will lose 
W
i
+
1
W 
i+1
​
  coins.
If you are at city 
N
N, your travel ends.
Note that you can have a negative amount of coins at any time.

What is the maximum number of coins you can end up with after this trip?

Input Format
The first line of input will contain a single integer 
T
T, denoting the number of test cases.
Each test case consists of multiple lines of input.
The first line contains 
2
2 integers - 
N
N and 
K
K, the number of cities and the cost to change colour.
The second line contains 
N
N integers - 
W
1
,
W
2
,
…
,
W
N
W 
1
​
 ,W 
2
​
 ,…,W 
N
​
 .
The third line contains 
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
Output Format
For each test case, output a single integer, the maximum number of coins you can have after ending your travel.

Constraints
1
≤
T
≤
10
5
1≤T≤10 
5
 
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
 
0
≤
K
≤
10
9
0≤K≤10 
9
 
0
≤
W
i
≤
10
9
0≤W 
i
​
 ≤10 
9
 
0
≤
C
i
<
N
0≤C 
i
​
 <N
C
1
=
W
1
=
0
C 
1
​
 =W 
1
​
 =0
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
3 100000
0 2 4
0 1 1
3 3
0 2 4
0 1 1
6 2
0 1 1 1 1 1
0 1 2 2 2 3
5 2
0 1 1 1 1000
0 1 2 3 1
5 15
0 11 12 13 14
0 3 2 1 4
-6
3
-1
997
-10
Explanation:
Test Case 1: It is optimal to never change your color. You will lose 
2
2 coins from entering city 
2
2 with the wrong color and lose 
4
4 coins for entering city 
3
3 with the wrong color.

Test Case 2: It is optimal to change your color to 
1
1. It costs 
3
3 coins to change your color, and you will gain 
6
6 coins from entering cities 
2
2 and 
3
3.
#include <bits/stdc++.h>
using namespace std;

const long long mini = LLONG_MIN;

int main() {
   
    int t; 
    cin >> t;
    while (t--) {
        int n; 
        long long k;
        cin >> n >> k;
        
        vector<long long> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        
        vector<int> c(n);
        for (int i = 0; i < n; i++) cin >> c[i];
        
        unordered_map<int,long long> mp;
        mp[0] = 0;
        
        priority_queue<pair<long long,int>> pq;
        pq.push({0,0});
        
        long long extra = 0;
        
        for (int i = 1; i < n; i++) {
            while (!pq.empty() && mp[c[pq.top().second]] != pq.top().first) {
                pq.pop();
            }
            long long best = pq.empty() ? mini : pq.top().first;
            
            extra -= a[i];
            
            long long same = mini;
            if (mp.count(c[i])) same = mp[c[i]] + 2*a[i];
            
            long long v1 = (best == mini ? mini : best - k + 2*a[i]);
            long long put = max(v1, same);
            
            if (!mp.count(c[i])) mp[c[i]] = put;
            else mp[c[i]] = max(mp[c[i]], put);
            
            pq.push({mp[c[i]], i});
        }
        
        long long ans = mini;
        for (auto it: mp) ans = max(ans, it.second);
        cout << ans + extra << endl;
    }
    return 0;
}
