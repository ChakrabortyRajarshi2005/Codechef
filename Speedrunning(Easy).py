Speedrunning (Easy)
This is the easy version of the problem. The only difference between the versions are the constraints. Here 
∑
N
≤
4000
∑N≤4000 and 
Q
=
1
Q=1. Each version is worth 
40
40 points.

You're playing a game which consists of 
N
N levels, and you have an integer parameter 
X
X.

You initially start the game with 0 armour points. At the start of the 
i
i-th level, you may perform each of the following actions zero or more times:

Take 
K
K seconds to increase your armour points by 1.
Take 
0
0 seconds to decrease your armour points by 1.
After this process you must have at least 
A
i
A 
i
​
  armour points to be able to beat the 
i
i-th level. However, the armour also slows you down 
−
− if you have 
y
y armour points, it will take you 
y
y seconds to complete the level. After this you will instantly proceed to level 
i
+
1
i+1 unless level 
i
i was the final level.

Let 
f
(
i
,
j
,
X
)
f(i,j,X) be the minimum time required to start the game at level 
i
i and finish it after completing level 
j
j given that it takes 
X
X seconds to increase your armour points by 1.

You are given 
Q
Q queries, each consisting of a single integer 
K
K. For each query, you need to print the value of 
∑
i
=
1
N
∑
j
=
i
N
f
(
i
,
j
,
K
)
∑ 
i=1
N
​
 ∑ 
j=i
N
​
 f(i,j,K). Since the answer may be large, print it modulo 
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
Q
Q - the size of the array and the number of queries.
The second line contains 
N
N integers 
−
− 
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
The next 
Q
Q lines contain 
1
1 integer each 
−
− 
K
i
K 
i
​
 , the parameters for each query.
Output Format
For each test case, for each query, output on a new line 
∑
i
=
1
N
∑
j
=
i
N
f
(
i
,
j
,
K
)
∑ 
i=1
N
​
 ∑ 
j=i
N
​
 f(i,j,K) modulo 
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
500
1≤T≤500
1
≤
N
≤
4000
1≤N≤4000
Q
=
1
Q=1
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
1
≤
K
i
≤
N
1≤K 
i
​
 ≤N
The sum of 
N
N and the sum of 
Q
Q over all test cases do not exceed 
4000
4000.
Sample 1:
Input
Output
8
1 1
1
1
2 1
1 2
1
3 1
2 1 2
1
3 1
2 1 2
2
4 1
1 2 3 1
2
4 1
1 2 3 1
3
5 1
5 1 2 3 4
2
5 1
5 1 5 1 2
3
2
11
28
39
86
110
214
294
Explanation:
Test Case 1: Here, we only need to find 
f
(
1
,
1
,
1
)
f(1,1,1). We start at level 
1
1, end after completing level 
1
1 and the cost to increase our armour points is 
1
1.

We first need to increase the armour points from 
0
0 to 
1
1 at the start of level 
1
1. This takes 
1
1 second. Now, we complete level 
1
1, and we are slowed by 
1
1 second due to our armour.

Test Case 2: It can be shown that 
f
(
1
,
1
,
1
)
=
2
,
f
(
1
,
2
,
1
)
=
5
f(1,1,1)=2,f(1,2,1)=5 and 
f
(
2
,
2
,
1
)
=
4
f(2,2,1)=4. Let us show the computation of 
f
(
1
,
2
,
1
)
f(1,2,1).

We need to start at level 
1
1 and end after level 
2
2.
At the start of level 
1
1, we take 
1
1 second to increase our armour points to 
1
1.
We complete level 
1
1 in 
1
1 second.
At the start of level 
2
2, we take 
1
1 second to increase our armour points to 
2
2.
We complete level 
2
2 in 
2
2 seconds (we have 
2
2 armour points, so it takes 
2
2 seconds).
The total time is 
1
+
1
+
1
+
2
=
5
1+1+1+2=5 seconds.
#!/usr/bin/env python3
#  Speedrunning (Easy) – editorial solution
#  uses the layer–gap decomposition explained above
MOD = 1_000_000_007


def solve_one_case(N: int, A: list[int], K: int) -> int:
    """return Σ_{i≤j} f(i,j,K)  modulo MOD"""

    ans = 0
    for t, a in enumerate(A, start=1):                # 1‑based
        weight = t * (N - t + 1)                      # sub‑arrays containing level t
        ans = (ans + a * weight) % MOD

    # pre‑compute for later use
    total_subarrays = N * (N + 1) // 2
    Kmod = K % MOD
    maxA = max(A)

    for h in range(1, maxA + 1):
        prev_one = None           # previous position with A ≥ h
        zero_len = 0              # current run of zeros length
        zero_only_subs = 0        # Σ len·(len+1)/2 over all zero‑blocks

        for pos, a in enumerate(A, start=1):          # 1‑based
            if a >= h:                                # Rt = 1
                # close a zero‑block (if any)
                if zero_len:
                    zero_only_subs += zero_len * (zero_len + 1) // 2
                    zero_len = 0

                # gap between two required runs
                if prev_one is not None:
                    gap = pos - prev_one - 1
                    if gap:                           # internal gap exists
                        w = prev_one * (N - pos + 1)  # #sub‑arrays that contain the gap
                        ans = (ans + min(gap, K) * w) % MOD
                prev_one = pos
            else:                                     # Rt = 0
                zero_len += 1

        # tailing zero‑block
        if zero_len:
            zero_only_subs += zero_len * (zero_len + 1) // 2

        have_layer_subs = total_subarrays - zero_only_subs
        ans = (ans + Kmod * (have_layer_subs % MOD)) % MOD

    return ans


import sys

it = iter(sys.stdin.read().strip().split())
T = int(next(it))
out_lines = []

for _ in range(T):
    N = int(next(it))
    Q = int(next(it))              # Q == 1 in the easy version
    A = [int(next(it)) for _ in range(N)]
    for _ in range(Q):
        K = int(next(it))
        out_lines.append(str(solve_one_case(N, A, K)))

print("\n".join(out_lines))
