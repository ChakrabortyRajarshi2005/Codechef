Interactive MST
There is a weighted undirected connected simple graph 
G
G with 
N
N vertices, 
M
M edges, with binary weights. The 
i
i-th edge connects 
U
i
U 
i
​
  and 
V
i
V 
i
​
 , and has a weight of 
W
i
W 
i
​
 . It is guaranteed that 
0
≤
W
i
≤
1
0≤W 
i
​
 ≤1 for all edges.

Alice and Bob are playing a game on the graph. Alice knows everything about the graph, but Bob knows only 
N
N, 
M
M and the edges, i.e. he does not know the weights. Note that 
2
≤
N
≤
13
2≤N≤13.

Bob can do the following action at most 
2
⋅
M
2⋅M times:

Bob gives Alice a binary sequence of length 
M
M, which is 
A
=
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
M
]
A=[A 
1
​
 ,A 
2
​
 ,…,A 
M
​
 ] where 
0
≤
A
i
≤
1
0≤A 
i
​
 ≤1.
Now, Alice considers a hypothetical scenario where the weights of the edges are instead represented by 
B
i
=
W
i
⋅
A
i
B 
i
​
 =W 
i
​
 ⋅A 
i
​
  (i.e. the 
2
2 values multiplied together)
Alice returns the sum of weights of the minimum spanning tree in this new graph.
A sequence of weights 
W
W is called solvable if there exists a strategy for Bob to figure out all the weights using the above action at most 
2
⋅
M
2⋅M times.

Unfortunately, Alice has realized that not all sequences are solvable. To rectify this, she has decided to change some of the weights in her graph such that it becomes solvable, i.e. she can choose an edge and change it's value from 
0
0 to 
1
1 or vice versa.

Find the minimum number of changes to the sequence 
W
W so that it becomes solvable. It can be proven that for any graph, there always exists at least one solvable sequence.

Input Format
The first line of input will contain a single integer 
T
T, denoting the number of test cases.
Each test case consists of multiple lines of input.
The first line of each test case contains 
2
2 integers - 
N
N and 
M
M, the number of vertices and edges.
The next 
M
M lines contain 
3
3 integers each - 
U
i
,
V
i
U 
i
​
 ,V 
i
​
  and 
W
i
W 
i
​
 , representing an edge.
Output Format
For each test case, output on a new line the minimum number of changes to the sequence 
W
W so that it becomes solvable.

Constraints
1
≤
T
≤
50
1≤T≤50
2
≤
N
≤
13
2≤N≤13
N
−
1
≤
M
≤
N
⋅
(
N
−
1
)
2
N−1≤M≤ 
2
N⋅(N−1)
​
 
1
≤
U
i
,
V
i
≤
N
1≤U 
i
​
 ,V 
i
​
 ≤N
0
≤
W
i
≤
1
0≤W 
i
​
 ≤1
The given graph is simple and connected, no multi edges or self edges.
Sample 1:
Input
Output
3
3 3
1 2 0
2 3 0
3 1 0
3 3
1 2 1
2 3 0
3 1 1
3 3
1 2 1
2 3 1
3 1 1
2
0
0
Explanation:
In all 
3
3 test cases, you are given the same graph, a cycle with 
3
3 vertices.

It can be shown that (for this graph) the sequences 
[
1
,
0
,
1
]
[1,0,1] and 
[
1
,
1
,
1
]
[1,1,1] are solvable while 
[
0
,
0
,
0
]
[0,0,0] is not solvable. We can change 
[
0
,
0
,
0
]
[0,0,0] to 
[
1
,
0
,
1
]
[1,0,1] in 
2
2 changes, and thus the answer is 
2
2 for 
[
0
,
0
,
0
]
[0,0,0].

We do not provide the strategies directly, instead we mention what happens on specific actions by Bob based on the different multiplier sequences 
A
A.

Bob chooses the vector 
A
=
[
0
,
1
,
1
]
A=[0,1,1].
When 
W
=
[
0
,
0
,
0
]
W=[0,0,0], the updated weights 
B
B are 
[
0
,
0
,
0
]
[0,0,0] and the MST sum is 
0
0.
When 
W
=
[
1
,
0
,
1
]
W=[1,0,1], the updated weights 
B
B are 
[
0
,
0
,
1
]
[0,0,1] and the MST sum is 
0
0.
When 
W
=
[
1
,
1
,
1
]
W=[1,1,1], the updated weights 
B
B are 
[
0
,
1
,
1
]
[0,1,1] and the MST sum is 
1
1.
Bob chooses the vector 
A
=
[
1
,
1
,
1
]
A=[1,1,1].
When 
W
=
[
0
,
0
,
0
]
W=[0,0,0], the updated weights 
B
B are 
[
0
,
0
,
0
]
[0,0,0] and the MST sum is 
0
0.
When 
W
=
[
1
,
0
,
1
]
W=[1,0,1], the updated weights 
B
B are 
[
1
,
0
,
1
]
[1,0,1] and the MST sum is 
1
1.
When 
W
=
[
1
,
1
,
1
]
W=[1,1,1], the updated weights 
B
B are 
[
1
,
1
,
1
]
[1,1,1] and the MST sum is 
2
2.
Did you like the problem statement?
3 users found this helpful

import java.io.*;
import java.util.*;

public class Main {
    static final int MOD = 998244353;
    static final int INF = Integer.MAX_VALUE / 2;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());
        while (T-- > 0) {
            int[] temp = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
            int n = temp[0], m = temp[1];
            boolean[][] ls = new boolean[n][n];
            boolean[][] ps = new boolean[n][n];
            int tots = 0;
            for (int i = 0; i < m; i++) {
                int[] edge = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
                int u = edge[0] - 1, v = edge[1] - 1, w = edge[2];
                ls[u][v] = ls[v][u] = true;
                if (w == 0) {
                    ps[u][v] = ps[v][u] = true;
                    tots++;
                }
            }
            boolean[] trees;
            int[] val;
            int full = 1 << n;
            trees = new boolean[full];
            val = new int[full];

            for (int mask = 1; mask < full; mask++) {
                int vcnt = Integer.bitCount(mask);
                int ecnt = 0, zcnt = 0;
                for (int u = 0; u < n; u++) {
                    if ((mask & (1 << u)) == 0) continue;
                    for (int v = u + 1; v < n; v++) {
                        if ((mask & (1 << v)) != 0 && ls[u][v]) {
                            ecnt++;
                            if (ps[u][v]) zcnt++;
                        }
                    }
                }
                if (ecnt != vcnt - 1) continue;
                int r0 = Integer.numberOfTrailingZeros(mask);
                boolean[] vis = new boolean[n];
                Deque<Integer> dq = new ArrayDeque<>();
                dq.add(r0);
                vis[r0] = true;
                int seen = 1;
                while (!dq.isEmpty()) {
                    int u = dq.poll();
                    for (int v = 0; v < n; v++) {
                        if (((mask & (1 << v)) != 0) && ls[u][v] && !vis[v]) {
                            vis[v] = true;
                            dq.add(v);
                            seen++;
                        }
                    }
                }
                if (seen == vcnt) {
                    trees[mask] = true;
                    val[mask] = 2 * zcnt + 1;
                }
            }

            int[] dp = new int[full];
            Arrays.fill(dp, -1);
            dp[0] = 0;

            for (int mask = 1; mask < full; mask++) {
                int anchor = Integer.numberOfTrailingZeros(mask);
                for (int sub = mask; sub > 0; sub = (sub - 1) & mask) {
                    if (((sub & (1 << anchor)) != 0) && trees[sub] && dp[mask ^ sub] >= 0) {
                        dp[mask] = Math.max(dp[mask], dp[mask ^ sub] + val[sub]);
                    }
                }
            }
            System.out.println(tots + n - dp[full - 1]);
        }
    }
}
