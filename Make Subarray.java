Make Subarray
There is a canvas with 
N
N total cells, and each cell can be painted white or black. Currently, the state of the board can be represented by a binary string 
S
S, where 
S
i
=
1
S 
i
​
 =1 if and only if the 
i
i-th call in the canvas is painted black, and 
S
i
=
0
S 
i
​
 =0 otherwise.

You want the black cells to form a contiguous subarray, i.e. if cell 
x
x and cell 
y
y are coloured black, then all cells 
z
z between the 
2
2 must also be black. Note that if there are no black cells, this condition is satisfied.

You can only change the colour of a cell from white to black (but not the other way around). Find the minimum number of changes needed.

Input Format
The first line of input will contain a single integer 
T
T, denoting the number of test cases.
Each test case consists of multiple lines of input.
The first line of each test case contains 
N
N - the number of cells.
The second line contains 
S
S - a binary string of size 
N
N.
Output Format
For each test case, output on a new line the minimum number of cells that need to be changed from white to black, such that the black cells form a contiguous subarray.

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
Sample 1:
Input
Output
4
2
00
3
101
4
0110
10
0100010011
0
1
0
5
Explanation:
Test Case 1 : There are no black cells, so the condition is satisfied.

Test Case 2 : We can colour the 
2
n
d
2 
nd
  cell, and now the condition is satisfied.import java.util.*;
import java.lang.*;
import java.io.*;

class Codechef
{
    public static void main(String[] args) throws java.lang.Exception
    {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        sc.nextLine();
        while(t-->0){
            int n=sc.nextInt();
            sc.nextLine();
            String s=sc.nextLine();
            List<Integer> blackIndices=new ArrayList<>();
            for(int i=0;i<n;i++){
                if(s.charAt(i)=='1'){
                    blackIndices.add(i);
                }
            }
            int count=0;
            for(int i=0;i<blackIndices.size()-1;i++){
                count+=(blackIndices.get(i+1)-blackIndices.get(i)-1);
            }
            System.out.println(count);
        }

    }
}
