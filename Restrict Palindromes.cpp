Restrict Palindromes
For a string 
S
S, we define 
f
(
S
)
f(S) as the number of distinct palindromic
†
†
  substrings
‡
‡
  of 
S
S.

For example, 
f
(
a
b
a
a
)
=
4
f(abaa)=4 because we can find the palindrome substrings 
a
,
b
,
a
a
a,b,aa and 
a
b
a
aba.

Call a string 
S
S good if 
f
(
S
)
≤
5
f(S)≤5, i.e. it has at most 
5
5 distinct palindrome substrings.

You are given an integer 
N
N. Construct any good string of length 
N
N using only lowercase Latin characters. It can be proven that at least one good string exists. You are allowed to print any good string.

†
†
  A string is called palindromic if it reads the same forwards and backwards.

‡
‡
  A substring is a string that can be obtained by deleting some (possibly zero) characters from the beginning and some (possibly zero) characters from the end.

Input Format
The first line of input will contain a single integer 
T
T, denoting the number of test cases.
The first and only line of input contains a single integer 
N
N.
Output Format
For each test case, output a string 
S
S of length 
N
N, using only lowercase Latin characters, with 
f
(
S
)
≤
5
f(S)≤5.

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
Sample 1:
Input
Output
2
2
4
aa
abaa
Explanation:
Test Case 1 : 
a
a
aa has 
2
2 distinct palindrome substrings, 
a
a and 
a
a
aa.

Test Case 2 : 
f
(
a
b
a
a
)
=
4
f(abaa)=4 as mentioned in the statement.

import java.util.*;
class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        String base = "abcde";
        while (T-- > 0) {
            int N = sc.nextInt();
            StringBuilder sb = new StringBuilder();
            for (int i = 0; i < N; i++) {
                sb.append(base.charAt(i % 5));
            }
            System.out.println(sb.toString());
        }
    }
}
