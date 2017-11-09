import java.io.*;
import java.util.*;
import java.math.BigInteger;

public class Solution {

    public static void main(String[] args) {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
        int n;
        BigInteger ans = new BigInteger("1");
        Scanner scanner = new Scanner(System.in);
        n = scanner.nextInt();
        for(int i = 2; i <= n ;i++){
            ans = ans.multiply(BigInteger.valueOf(i));
        }
        System.out.print(ans);
    }
}
