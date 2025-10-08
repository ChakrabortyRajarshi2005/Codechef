Balanced Subarrays
An array 
A
A of length 
3
N
3N is said to be balanced if it contains exactly 
N
N occurrences each of 
1
,
2
,
1,2, and 
3
3.
For example, the arrays 
[
1
,
2
,
1
,
3
,
3
,
2
]
[1,2,1,3,3,2] and 
[
3
,
2
,
1
]
[3,2,1] are balanced, whereas 
[
1
,
1
,
1
]
,
[
1
,
2
,
1
,
2
,
1
,
2
]
,
[1,1,1],[1,2,1,2,1,2], and 
[
3
,
2
,
1
,
1
,
3
,
3
]
[3,2,1,1,3,3] are not.

You are given an integer 
K
K (
1
≤
K
≤
10
7
1≤K≤10 
7
 ).
Construct any array 
A
A of length at most 
10
4
10 
4
 , consisting of only the integers 
1
,
2
,
1,2, and 
3
3, such that it contains exactly 
K
K contiguous subarrays that are balanced, i.e. there exists exactly 
K
K pairs of integers 
L
L and 
R
R such that:

1
≤
L
≤
R
≤
N
1≤L≤R≤N
[
A
L
,
A
L
+
1
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
 ,…,A 
R
​
 ] is balanced.
It can be proved that a valid array always exists.
Note that you do not need to minimize the length of the constructed array: it only needs to be 
≤
10
4
≤10 
4
 .

Input Format
The first line of input will contain a single integer 
T
T, denoting the number of test cases.
The first and only line of each test case will contain a single integer 
K
K, the target number of balanced subarrays.
Output Format
For each test case, output two lines.

The first line should contain a single integer 
N
N (
1
≤
N
≤
10
4
1≤N≤10 
4
 ), the length of the array you found.
The second line should contain 
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
  (
1
≤
A
i
≤
3
1≤A 
i
​
 ≤3), denoting the array elements.
If there are multiple possible solutions, any of them will be accepted.

Constraints
1
≤
T
≤
50
1≤T≤50
1
≤
K
≤
10
7
1≤K≤10 
7
 
Sample 1:
Input
Output
3
1
2
9
3
1 2 3
5
1 1 2 3 1
10
1 3 1 2 3 1 3 2 1 2
Explanation:
Test Case 1 : The only subarray of 
[
1
,
2
,
3
]
[1,2,3] which is balanced, is the whole array itself.

Test Case 2 : The subarrays corresponding to 
(
L
,
R
)
=
(
2
,
4
)
(L,R)=(2,4) and 
(
L
,
R
)
=
(
3
,
5
)
(L,R)=(3,5) are 
[
1
,
2
,
3
]
[1,2,3] and 
[
2
,
3
,
1
]
[2,3,1]. They are the only 
2
2 balanced subarrays.use std::io::{self, Read};

fn tri_like(m: i64) -> i64 {
    (3 * m * m - m) / 2
}

fn make_seq(mut need: i64) -> Vec<i32> {
    let mut out = Vec::new();
    while need > 0 {
        let mut lo = 1i64;
        let mut hi = 10_000i64;
        let mut best = 0i64;
        while lo <= hi {
            let mid = (lo + hi) >> 1;
            if tri_like(mid) <= need {
                best = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        for _ in 0..best {
            out.push(1);
            out.push(2);
            out.push(3);
        }
        need -= tri_like(best);
        if need > 0 {
            out.extend_from_slice(&[3, 3, 2, 2]);
        }
        if out.len() > 10_000 {
            break;
        }
    }
    out
}

fn main() {
    let mut s = String::new();
    io::stdin().read_to_string(&mut s).unwrap();
    let mut it = s.split_whitespace();
    let t: usize = match it.next() {
        Some(v) => v.parse().unwrap(),
        None => return,
    };
    let mut buf = String::new();
    for _ in 0..t {
        let target: i64 = it.next().unwrap().parse().unwrap();
        let seq = make_seq(target);
        if seq.is_empty() {
            buf.push_str("1\n1\n");
            continue;
        }
        buf.push_str(&format!("{}\n", seq.len()));
        for (i, v) in seq.iter().enumerate() {
            if i > 0 {
                buf.push(' ');
            }
            buf.push_str(&v.to_string());
        }
        buf.push('\n');
    }
    print!("{buf}");
}
