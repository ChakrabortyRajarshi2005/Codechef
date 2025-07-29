Subsequence Sort
Chef has an array 
A
A containing 
N
N non-negative integers.

He will perform a sequence of operations on this array.
The 
X
X-th operation is as follows:

For each index 
i
i (
1
≤
i
≤
N
1≤i≤N), either leave 
A
i
A 
i
​
  unchanged, or replace 
A
i
A 
i
​
  with 
A
i
∣
X
A 
i
​
 ∣X.
The choice is made independently for each index.
Here, 
∣
∣ denotes the bitwise OR operation.
Find the minimum number of operations needed for Chef to be able to obtain an array that's sorted in non-decreasing order, i.e. for
A
1
≤
A
2
≤
…
≤
A
N
A 
1
​
 ≤A 
2
​
 ≤…≤A 
N
​
  to hold.
It can be proved that the answer is finite.
If the array is already sorted, output 
0
0.

Input Format
The first line of input will contain a single integer 
T
T, denoting the number of test cases.
Each test case consists of two lines of input.
The first line of each test case contains a single integer 
N
N — the length of the array.
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
 .
Output Format
For each test case, output on a new line the minimum number of operations needed to obtain a sorted array.

Constraints
1
≤
T
≤
10
5
1≤T≤10 
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
 
0
≤
A
i
≤
10
9
0≤A 
i
​
 ≤10 
9
 
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
3
3
2 1 3
4
2 5 5 7
5
9 8 9 15 14
2
0
1
Explanation:
Test case 
1
1: One optimal sequence of operations is as follows.

Initially, 
A
=
[
2
,
1
,
3
]
A=[2,1,3].
First, we have 
X
=
1
X=1.
Leave all elements unchanged, so that 
A
=
[
2
,
1
,
3
]
A=[2,1,3] still.
Next, we have 
X
=
2
X=2.
Leave 
A
1
A 
1
​
  and 
A
3
A 
3
​
  unchanged, and replace 
A
2
A 
2
​
  by 
A
2
∣
X
A 
2
​
 ∣X.
This will make the array 
[
2
,
3
,
3
]
[2,3,3], which is sorted.
Test case 
2
2: The array is already sorted.

Test case 
3
3: 
A
=
[
9
,
8
,
9
,
15
,
14
]
A=[9,8,9,15,14].
For 
X
=
1
X=1, replace 
A
2
A 
2
​
  and 
A
5
A 
5
​
  by their bitwise ORs with 
X
X, to obtain 
[
9
,
9
,
9
,
15
,
15
]
[9,9,9,15,15] which is sorted.

# cook your dish here
import sys

def main():
    input = sys.stdin.read
    data = input().split()
    idx = 0
    T = int(data[idx])
    idx += 1
    results = []
    for _ in range(T):
        N = int(data[idx])
        idx += 1
        A = list(map(int, data[idx:idx+N]))
        idx += N
        
        prev = 0
        required_bits = set()
        
        for a in A:
            current = max(prev, a)
            s = current & (~a)
            # Collect all set bits in s
            if s != 0:
                bit = 0
                temp = s
                while temp > 0:
                    if temp & 1:
                        required_bits.add(bit)
                    bit += 1
                    temp >>= 1
            prev = current
        
        if not required_bits:
            results.append(0)
        else:
            max_bit = max(required_bits)
            K = 1 << max_bit
            results.append(K)
    
    sys.stdout.write('\n'.join(map(str, results)) + '\n')

if __name__ == '__main__':
    main()
