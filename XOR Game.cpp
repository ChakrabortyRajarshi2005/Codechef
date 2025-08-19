XOR Game
Alice and Bob are playing a game that involves an array 
A
A of length 
N
N containing non-negative integers. The following sequence of events occurs exactly once:

Alice chooses two (not necessarily distinct) indices 
i
i and 
j
j. Then, Alice sets 
A
i
:
=
A
i
⊕
A
j
A 
i
​
 :=A 
i
​
 ⊕A 
j
​
  where 
⊕
⊕ denotes the bitwise XOR operation.
Then, Bob chooses two (not necessarily distinct) indices 
i
i and 
j
j and sets 
A
i
:
=
A
i
⊕
A
j
A 
i
​
 :=A 
i
​
 ⊕A 
j
​
 .
The score of the board is calculated as 
A
1
⊕
A
2
⊕
⋯
⊕
A
n
A 
1
​
 ⊕A 
2
​
 ⊕⋯⊕A 
n
​
 .
Alice wants to maximize the score while Bob wants to minimize the score. Assuming both players use optimal strategies, determine the final score.

Input Format
The first line of input will contain a single integer 
T
T, denoting the number of test cases.
Each test case consists of multiple lines of input.
The first line of each test case contains 
N
N - the size of the array 
A
A.
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
For each test case, output on a new line the optimal score.

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
 
0
≤
A
i
<
2
30
0≤A 
i
​
 <2 
30
 
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
2
1 1
2
1 2
4
1 0 3 4
4
16 17 18 19
9
15 27 18 23 99 64 16 0 37
0
2
3
1
36
Explanation:
Test Case 1 : Alice can choose 
i
=
1
,
j
=
1
i=1,j=1 and change 
A
1
=
A
1
⊕
A
2
=
0
A 
1
​
 =A 
1
​
 ⊕A 
2
​
 =0. Hence, 
A
A becomes 
[
0
,
1
]
[0,1]. Now, Bob can choose 
i
=
2
,
j
=
2
i=2,j=2 and change 
A
A to 
[
0
,
0
]
[0,0]. This has a score of 
0
0.

Test Case 2 : Alice can choose 
i
=
1
,
j
=
2
i=1,j=2 and change 
A
=
[
3
,
2
]
A=[3,2]. Now, Bob chooses 
i
=
2
,
j
=
1
i=2,j=1 and changes 
A
=
[
3
,
1
]
A=[3,1] which has a score of 
2
2.

import java.io.*;
import java.util.*;

class Solution {
    static final int BITS = 30; // values < 2^30

    static class Node {
        int cnt;
        int[] ch = new int[] { -1, -1 };
    }

    static ArrayList<Node> trie;

    static void initTrie() {
        trie = new ArrayList<>();
        trie.add(new Node()); // root = 0
    }

    static void insertTrie(int val, int delta) {
        int node = 0;
        trie.get(node).cnt += delta;
        for (int b = BITS - 1; b >= 0; b--) {
            int bit = (val >>> b) & 1;
            if (trie.get(node).ch[bit] == -1) {
                trie.get(node).ch[bit] = trie.size();
                trie.add(new Node());
            }
            node = trie.get(node).ch[bit];
            trie.get(node).cnt += delta;
        }
    }

    // returns {minXor, valueT}
    static int[] queryMinAndValue(int C) {
        int node = 0;
        int minX = 0;
        int value = 0;
        for (int b = BITS - 1; b >= 0; b--) {
            int bit = (C >>> b) & 1;
            int pref = bit;
            int nxt = trie.get(node).ch[pref];
            if (nxt != -1 && trie.get(nxt).cnt > 0) {
                node = nxt;
                value = (value << 1) | pref;
            } else {
                int alt = pref ^ 1;
                node = trie.get(node).ch[alt];
                minX |= (1 << b);
                value = (value << 1) | alt;
            }
        }
        return new int[] { minX, value };
    }

    // Fast scanner
    static final class FastScanner {
        private final InputStream in;
        private final byte[] buffer = new byte[1 << 16];
        private int ptr = 0, len = 0;
        FastScanner(InputStream is) { in = is; }
        private int read() throws IOException {
            if (ptr >= len) {
                len = in.read(buffer);
                ptr = 0;
                if (len <= 0) return -1;
            }
            return buffer[ptr++];
        }
        int nextInt() throws IOException {
            int c, sgn = 1, x = 0;
            do { c = read(); } while (c <= ' ');
            if (c == '-') { sgn = -1; c = read(); }
            while (c > ' ') { x = x * 10 + (c - '0'); c = read(); }
            return x * sgn;
        }
    }

    public static void main(String[] args) throws Exception {
        FastScanner fs = new FastScanner(System.in);
        StringBuilder out = new StringBuilder();
        int T = fs.nextInt();
        while (T-- > 0) {
            int N = fs.nextInt();
            int[] arr = new int[N];
            int S = 0;
            for (int i = 0; i < N; i++) {
                arr[i] = fs.nextInt();
                S ^= arr[i];
            }

            // Precompute S^v values and their counts; find M1 and M2 (top two maxima)
            HashMap<Integer, Integer> map = new HashMap<>();
            for (int v : arr) {
                int sVal = S ^ v;
                map.put(sVal, map.getOrDefault(sVal, 0) + 1);
            }
            int M1 = -1, M2 = -1;
            for (int key : map.keySet()) {
                if (key > M1) {
                    M2 = M1;
                    M1 = key;
                } else if (key > M2) {
                    M2 = key;
                }
            }
            int M1count = (M1 == -1) ? 0 : map.getOrDefault(M1, 0);

            // Build trie of all arr values
            initTrie();
            for (int v : arr) insertTrie(v, +1);

            int answer = 0;

            for (int x : arr) {
                int C = S ^ x;

                // Get minimal (m1, t1)
                int[] q1 = queryMinAndValue(C);
                int m1 = q1[0];
                int t1 = q1[1];

                // remove one occurrence of t1 to find m2
                insertTrie(t1, -1);
                int[] q2 = queryMinAndValue(C);
                int m2 = q2[0];
                // restore t1
                insertTrie(t1, +1);

                // compute max_except: maximum of S^u for u != the particular t1 instance
                int sval_t1 = S ^ t1;
                int maxExcept;
                if (sval_t1 == M1) {
                    // If M1 occurs more than once, it still remains; otherwise second maximum
                    if (M1count >= 2) maxExcept = M1;
                    else maxExcept = M2;
                } else {
                    maxExcept = M1;
                }
                // two candidate choices for Alice
                int cand1 = Math.min(m1, maxExcept);    // Alice removes some u != t1
                int cand2 = Math.min(m2, sval_t1);      // Alice removes u == t1
                int g = Math.max(cand1, cand2);
                if (g > answer) answer = g;
            }

            out.append(answer).append('\n');
        }
        System.out.print(out.toString());
    }
}
