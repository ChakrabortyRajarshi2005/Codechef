Gladiator Fighting
There are 
N
N gladiators standing in a field. They will fight till only 
1
1 gladiator is left, and the other 
N
−
1
N−1 gladiators have been defeated.

Initially, everyone has a skill factor of 
0
0. But, every fight that a gladiator wins, his skill factor increases by 
1
1.

There will be exactly 
N
−
1
N−1 rounds. Each round, 
2
2 gladiators (not yet defeated), will come and fight; and one of will win, the other will be defeated. The entertainment level of a fight between gladiators of skill level 
X
X and 
Y
Y is 
X
+
Y
X+Y. Note that it is possible for the lower skill gladiator to win.

What is the minimum and maximum possible total sum of entertainment level over all fights?

Input Format
The first line of input will contain a single integer 
T
T, denoting the number of test cases.
The first and only line of input contains a single integer 
N
N.
Output Format
For each test case, output 
2
2 integers - the minimum and maximum possible sums of entertainment levels.

Constraints
1
≤
T
≤
99
1≤T≤99
2
≤
N
≤
100
2≤N≤100
Sample 1:
Input
Output
4
2
3
4
5
0 0
1 1
2 3
3 6
Explanation:
Test Case 1 : Only 
1
1 fight happens, between gladiators of skills 
0
0 and 
0
0. Thus, the answer is always 
0
0.

Test Case 2 : Only 
2
2 fights happen, the first between gladiators of skills 
0
0 and 
0
0, and the second between 
0
0 and 
1
1. Thus, the answer is always 
1
1.

Test Case 3 : here is how the minimum case is achieved:

Gladiator 
1
1 fights gladiator 
2
2 and wins. Entertainment level of 
0
0, gladiator 
1
1 has skill of 
1
1.
Gladiator 
3
3 fights gladiator 
4
4 and wins. Entertainment level of 
0
0, gladiator 
3
3 has skill of 
1
1.
Gladiator 
1
1 fights gladiator 
3
3 and wins. Entertainment level of 
2
2, gladiator 
1
1 has skill of 
2
2.
Thus, the final sum of entertainment levels is 
2
2.#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while(t--) {
        int n;
        cin >> n;
        
       
        int minSum =  (n - 2) ;
       
        
        int maxSum = (n - 2) * (n - 1) / 2;
        
        cout << minSum << " " << maxSum << endl;
    }
    
    return 0;
}
