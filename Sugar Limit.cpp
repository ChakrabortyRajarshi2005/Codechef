Sugar Limit
Chef bought 
N
N different snacks, and now needs to decide which ones to eat.
The 
i
i-th snack has a tastiness of 
A
i
A 
i
​
 , and contains 
B
i
B 
i
​
  units of sugar.
Note that 
A
i
A 
i
​
  can be 
0
0 or even negative.

Chef wants to limit his sugar intake, so he will choose some non-negative integer 
L
L, and then he can only eat a snack if it has at most 
L
L units of sugar, i.e. that satisfies 
B
i
≤
L
B 
i
​
 ≤L.
Note that he doesn't need to eat every snack that satisfies 
B
i
≤
L
B 
i
​
 ≤L: he can decide to skip some of them too.

Let 
S
S denote the sum of tastiness values of all the snacks Chef decides to eat, after choosing the value of 
L
L.
Chef's satisfaction then equals 
(
S
−
L
)
(S−L). That is, Chef's satisfaction is the sum of tastiness values of everything he eats, minus the threshold value 
L
L.

What is Chef's maximum possible satisfaction, if he chooses the value of 
L
L and the snacks he eats appropriately?

Input Format
The first line of input will contain a single integer 
T
T, denoting the number of test cases.
Each test case consists of three lines of input.
The first line of each test case contains a single integer 
N
N, the number of snacks.
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
  — the tastiness values.
The third line contains 
N
N space-separated integers 
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
  — the sugar quantities.
Output Format
For each test case, output on a new line the maximum possible satisfaction Chef can achieve.

Constraints
1
≤
T
≤
100
1≤T≤100
1
≤
N
≤
100
1≤N≤100
−
100
≤
A
i
≤
100
−100≤A 
i
​
 ≤100
1
≤
B
i
≤
100
1≤B 
i
​
 ≤100
Sample 1:
Input
Output
3
2
4 -1
2 4
4
5 12 -6 1
4 2 4 1
1
8
9
2
14
0
Explanation:
Test case 
1
1: Choose 
L
=
2
L=2, and eat only the first snack.
This gives a tastiness of 
A
1
=
4
A 
1
​
 =4, so the overall satisfaction is 
4
−
2
=
2
4−2=2. This is optimal.

Test case 
2
2: Choose 
L
=
4
L=4, and eat snacks 
1
,
2
,
4
1,2,4. This gives a satisfaction of 
(
A
1
+
A
2
+
A
4
−
L
)
=
(
5
+
12
+
1
−
4
)
=
14
(A 
1
​
 +A 
2
​
 +A 
4
​
 −L)=(5+12+1−4)=14, which is optimal.
Note that even though 
A
3
≤
L
=
4
A 
3
​
 ≤L=4, it's ideal to not eat it.

Test case 
3
3: Choose 
L
=
0
L=0 and don't eat any snacks. The overall satisfaction is 
0
0, which is still better than eating any snack.
#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        vector < int > brr(n);
        for (int i = 0; i < n; i++) {
            cin >> brr[i];
        }
        int maxl = * max_element(brr.begin(), brr.end());
        int s = 0;
        int ans = INT_MIN;
        for (int l = 1; l <= maxl; l++) {
            s = 0;
            for (int i = 0; i < n; i++) {

                if (brr[i] <= l && arr[i] > 0) {
                    s += arr[i];
                }
            }
            ans = max(ans, s - l);

        }
        if (ans < 0) {
            cout << 0 << '\n';
        }
        else {
            cout << ans << "\n";
        }
    }

}
