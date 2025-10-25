Tactical Conversion
You are given a binary string 
S
S of length 
N
N, i.e. each character of 
S
S is either 
0
0 or 
1
1.

You would like to convert every character of 
S
S into 
0
0.
To achieve this, you can perform the following operation:

Choose an index 
i
i 
(
1
≤
i
≤
N
)
(1≤i≤N) such that 
S
i
=
1
S 
i
​
 =1, and change 
S
i
S 
i
​
  to 
0
0.
However, there is one restriction:
You cannot perform two consecutive operations on adjacent indices.
That is, if you operate on the sequence of indices 
i
1
,
i
2
,
…
,
i
k
i 
1
​
 ,i 
2
​
 ,…,i 
k
​
 , then for each 
1
≤
j
<
k
1≤j<k the condition 
∣
i
j
−
i
j
+
1
∣
>
1
∣i 
j
​
 −i 
j+1
​
 ∣>1 must hold.

Determine whether it is possible to make the entire string consist of only zeros under these conditions.

Input Format
The first line of input contains a single integer 
T
T, denoting the number of test cases.
Each test case consists of two lines of input:
The first line contains a single integer 
N
N — the length of the binary string.
The second line contains the binary string 
S
S of length 
N
N, consisting only of characters 0 and 1.
Output Format
For each test case, output a single string on a new line — YES if it is possible to convert the entire string to all zeros under the given rule, or NO otherwise.

You may print each character of the string in uppercase or lowercase (for example, the strings YES, yEs, yes, and yeS will all be treated as identical).

Constraints
1
≤
T
≤
2
⋅
10
5
1≤T≤2⋅10 
5
 
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
 
S
S is a binary string.
The sum of 
N
N over all test cases won't exceed 
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
2
00
3
001
3
101
3
111
2
11
Yes
Yes
Yes
No
No
Explanation:
Test case 
1
1: No operations are needed.

Test case 
2
2: There is a single 
1
1 at position 
3
3.
Simply perform one operation with 
i
=
3
i=3, and the string becomes 
000
000 as desired.

Test case 
3
3: There are two 
1
1's, at positions 
1
1 and 
3
3.
Perform one operation with 
i
=
1
i=1, and the next operation with 
i
=
3
i=3, and we're done.

Test case 
4
4: There are three ones, at positions 
1
,
2
,
3
1,2,3.
It's not possible to operate on all of them, because:

If our first operation is on index 
1
1, the second operation cannot be index 
2
2 and so must be index 
3
3.
But then after index 
3
3 we cannot operate on index 
2
2 anyway, so that index will continue to contain a 
1
1.
Similarly, the first operation being on index 
3
3 will leave us unable to operate on index 
2
2.
Finally, if the first operation is on index 
2
2, then the second operation cannot be on either index 
1
1 or index 
3
3 since they're both adjacent to it.#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    
    string s;
    cin >> s;
    
    int maxLen = 0, cnt = 0, len = 0;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '1'){
            cnt++;
            len++;
            maxLen = max(maxLen, len);
        }
        else {
            len = 0;
        }
    }
    if(cnt == 0){
        cout << "YES" << endl;
        return;
    }
    
    if((maxLen == 2 && cnt == 2) || (maxLen == 3 && cnt == 3)){
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
}

int main() {
	// your code goes here
    int t;
    cin >> t;
    
    while(t--){
        solve();
    }
}
