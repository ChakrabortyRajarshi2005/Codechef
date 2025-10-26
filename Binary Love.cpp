Binary Love
Alice and Bob are playing a game on a binary string 
S
S of length 
N
N.

Alice wants to make the number of substrings 01 and 10 equal, and both counts must be non-zero.
Formally, let 
c
01
c 
01
​
  denote the number of indices 
i
i (
1
≤
i
<
N
1≤i<N) such that 
S
i
=
0
S 
i
​
 =0 and 
S
i
+
1
=
1
S 
i+1
​
 =1, and similarly let 
c
10
c 
10
​
  denote the number of indices 
i
i (
1
≤
i
<
N
1≤i<N) such that 
S
i
=
1
S 
i
​
 =1 and 
S
i
+
1
=
0
S 
i+1
​
 =0.
Alice would like for 
c
01
=
c
10
c 
01
​
 =c 
10
​
  and 
c
01
>
0
c 
01
​
 >0 to both hold.

Bob, on the other hand, wants to prevent Alice from achieving this condition.

The players take turns alternately, with Alice going first.
In each turn, the current player can remove exactly one character from either the beginning or the end of the string.

The game ends immediately when the string becomes empty or when Alice's desired condition (
c
01
=
c
10
>
0
c 
01
​
 =c 
10
​
 >0) is satisfied.

If Alice can make the number of 01 and 10 substrings equal (and both non-zero), she wins.
Otherwise, if Bob can prevent this condition until the string becomes empty, Bob wins.
In particular, if the initial string satisfies the required condition, Alice wins immediately, without even having to make a move.

Determine the winner of the game if both players play optimally.

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
For each test case, output a single string — Alice if Alice wins the game, or Bob if Bob wins the game.

You may print each character of the string in uppercase or lowercase (for example, the strings BOB, bOb, bob, and boB will all be treated as identical).

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
i
∈
{
0
,
1
}
S 
i
​
 ∈{0,1}
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
4
3
000
3
010
4
0001
4
0101
Bob
Alice
Bob
Alice
Explanation:
Test case 
1
1: We have 
c
01
=
c
10
=
0
c 
01
​
 =c 
10
​
 =0 for the initial string.
No matter what the players do in terms of deleting characters, this won't change.
Alice wants 
c
01
>
0
c 
01
​
 >0, so she cannot win here.

Test case 
2
2: We have 
c
01
=
c
10
=
1
c 
01
​
 =c 
10
​
 =1 initially.
Alice's condition is already satisfied, so she wins immediately.

Test case 
4
4: We have 
S
=
0101
S=0101, for which 
c
01
=
2
c 
01
​
 =2 and 
c
10
=
1
c 
10
​
 =1.
Alice must make a move; she can delete the last character to make 
S
=
010
S=010 which as seen earlier satisfies Alice's condition; so Alice wins.#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while(t--) {
        int n;
        string s;
        cin >> n >> s;
        
        int transitions = 0;
        for(int i = 0; i < n-1; i++) {
            if(s[i] != s[i+1]) {
                transitions++;
            }
        }
        
        if(transitions <= 1) {
            cout << "Bob" << endl;
        } else {
            cout << "Alice" << endl;
        }
    }
    
    return 0;
}
