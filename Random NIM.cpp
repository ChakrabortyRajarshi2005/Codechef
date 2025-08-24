Random NIM
There are 
N
N piles numbered 
1
,
2
,
…
,
N
1,2,…,N. The 
i
i-th pile initially has 
A
i
A 
i
​
  stones. Alice and Bob are playing a Nim game on these piles, but there is a twist.

As per the usual rules of Nim, Alice and Bob take turns alternately choosing a pile and removing some stones from the pile, with Alice going first. The player unable to make a move loses.

However, the twist is that instead of choosing how many stones to remove from the pile, they have to use a random number generator. If there are 
X
X stones left in the pile, they will randomly generate an integer 
R
R between 
1
1 and 
X
X (inclusive, and equiprobable) and then remove exactly 
R
R stones from the pile.

In this game, find the probability that Alice wins modulo 
998244353
998244353, when both players play optimally.

Formally, it can be shown that the answer can be represented as 
P
Q
Q
P
​
  where 
Q
m
o
d
 
 
998244353
≠
0
Qmod998244353=0, and you should print the unique integer 
R
R in 
[
0
,
998244353
)
[0,998244353) such that 
R
⋅
Q
=
P
m
o
d
 
 
998244353
R⋅Q=Pmod998244353.

Input Format
The first line of input will contain a single integer 
T
T, denoting the number of test cases.
Each test case consists of multiple lines of input.
The first line of each test case contains 
1
1 integer - 
N
N, the number of piles.
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
For each test case, output on a new line the probability that Alice wins modulo 
998244353
998244353.

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
1000
1≤N≤1000
1
≤
A
i
≤
1000
1≤A 
i
​
 ≤1000
The sum of 
N
N over all test cases does not exceed 
1000
1000.
Sample 1:
Input
Output
2
1
2
2
1 1
499122177
0
Explanation:
Test Case 1 : There are 
2
2 possible ways the game can play out:

Alice chooses pile 
1
1, and the random number 
R
=
2
R=2. Alice wins because Bob has no move.
Alice chooses pile 
1
1, and the random number 
R
=
1
R=1. Bob chooses pile 
1
1, and the random number 
R
R must be 
1
1. Alice loses as she has no move.
Thus, the probability is 
1
2
2
1
​
 , and we print 
499122177
499122177 because 
2
⋅
499122177
=
1
m
o
d
 
 
998244353
2⋅499122177=1mod998244353.

import java.io.*;
import java.util.*;

class CodeChef {

    // Fast Input and Output
    static class FastIO {
        BufferedReader br;
        StringTokenizer st;

        public FastIO() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        String next() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        double nextDouble() {
            return Double.parseDouble(next());
        }

        String nextLine() {
            String str = "";
            try {
                str = br.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }

        void print(String s) {
            System.out.print(s);
        }

        void println(String s) {
            System.out.println(s);
        }
    }

    // Debug Function
    static void debug(Object...o) {
        System.err.println(Arrays.deepToString(o));
    }

    // GCD
    static long gcd(long a, long b) {
        if (b == 0) return a;
        return gcd(b, a % b);
    }

    // LCM
    static long lcm(long a, long b) {
        return (a / gcd(a, b)) * b;
    }

    // Prime Check
    static boolean isPrime(int n) {
        if (n <= 1) return false;
        if (n <= 3) return true;
        if (n % 2 == 0 || n % 3 == 0) return false;
        for (int i = 5; i * i <= n; i += 6) {
            if (n % i == 0 || n % (i + 2) == 0) return false;
        }
        return true;
    }

    // Sieve of Eratosthenes
    static boolean[] sieve(int n) {
        boolean[] isPrime = new boolean[n + 1];
        Arrays.fill(isPrime, true);
        isPrime[0] = isPrime[1] = false;
        for (int i = 2; i * i <= n; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j <= n; j += i) {
                    isPrime[j] = false;
                }
            }
        }
        return isPrime;
    }

    static long modInverse(long a, long mod) {
        return modPow(a, mod - 2, mod);
    }
    
    // Fast modular exponentiation
    static long modPow(long base, long exp, long mod) {
        long result = 1;
        base %= mod;
        while (exp > 0) {
            if ((exp & 1) == 1) {
                result = (result * base) % mod;
            }
            base = (base * base) % mod;
            exp >>= 1;
        }
        return result;
    }
    // Factorial Modulo
    static long factorialMod(int n, int mod) {
        long result = 1;
        for (int i = 2; i <= n; i++) {
            result = (result * i) % mod;
        }
        return result;
    }

    // Custom Comparator for Sorting
    static class Pair implements Comparable < Pair > {
        int first,
        second;

        public Pair(int first, int second) {
            this.first = first;
            this.second = second;
        }

        @Override
        public int compareTo(Pair o) {
            return Integer.compare(this.first, o.first); // Ascending order by first
        }
    }

    // Prefix Sum
    static int[] prefixSum(int[] arr) {
        int n = arr.length;
        int[] prefix = new int[n];
        prefix[0] = arr[0];
        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] + arr[i];
        }
        return prefix;
    }

    // Binary Search
    static int binarySearch(int[] arr, int target) {
        int left = 0, right = arr.length - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] == target) return mid;
            if (arr[mid] < target) left = mid + 1;
            else right = mid - 1;
        }
        return -1; // Not found
    }

    
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        StringBuilder sb = new StringBuilder();

        while (t--> 0) {
            int n = Integer.parseInt(br.readLine());
            int[] arr = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
            boolean a=true;
            for(int i=0;i<n;i++){
                if(arr[i]!=1){
                    a=false;
                }
            }
            if(a){
                sb.append(n%2==1?1:0);
            }else{
                sb.append(499122177);
            }
            sb.append("\n");
        }

        System.out.print(sb);
    }
   
    

}
