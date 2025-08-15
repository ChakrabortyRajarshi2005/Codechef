Fence Colouring
You have 
N
N fences, and you want to colour them. You have 
N
N total types of colours numbered 
1
,
2
,
…
,
N
1,2,…,N.

Currently, all the 
N
N fences are coloured with the type 
1
1 colour. At the end, you want the 
i
i-th fence to have a colour of 
A
i
A 
i
​
  for every 
1
≤
i
≤
N
1≤i≤N.

You can choose to do one of the following at each minute:

Colour all 
N
N fences at the same time with type 
X
X colour, where you can choose 
X
(
1
≤
X
≤
N
)
X(1≤X≤N).
Colour a specific fence 
i
i with type 
X
X colour, where you can choose 
X
(
1
≤
X
≤
N
)
X(1≤X≤N).
Both of the above operations take only 
1
1 minute to perform. What is the minimum number of minutes needed to colour the entire fence as desired.

Input Format
The first line of input will contain a single integer 
T
T, denoting the number of test cases.
Each test case consists of multiple lines of input.
The first line of each test case contains 
N
N - the number of fences.
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
For each test case, output on a new line the minimum time needed to colour all 
N
N fences.

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
3
2
1 2
3
3 3 3
6
2 1 3 2 5 2
1
1
4
Explanation:
Test Case 1 : You can choose to colour the 
2
n
d
2 
nd
  fence with a colour of 
2
2. Thus, it only takes 
1
1 minute since fence 
1
1 was already coloured 
1
1.

Test Case 2 : You can choose to colour all the fences with 
3
3 at the same time. 

import java.util.Scanner;

class Codechef {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int testCases = scanner.nextInt();

        while (testCases-- > 0) {
            int n = scanner.nextInt();
            int[] arr = new int[n];

            int repaintCount = 0;
            int[] frequency = new int[n + 1];

            for (int i = 0; i < n; i++) {
                arr[i] = scanner.nextInt();
                if (arr[i] != 1) {
                    repaintCount++;
                }
                frequency[arr[i]]++;
            }

            int highestFreq = 0;
            for (int freq : frequency) {
                if (freq > highestFreq) {
                    highestFreq = freq;
                }
            }

            int fixAfterGlobalOne = 1 + (n - highestFreq);

            System.out.println(Math.min(repaintCount, fixAfterGlobalOne));
        }

        scanner.close();
    }
}
