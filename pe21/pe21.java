import java.util.Hashtable;
/**
 * Author: Spencer Rawson
 * Date: 10/11/23
 * Purpose: solve problem 21 by finding the sum of
 * amicable numbers below 10,000
 */
public class pe21
{
    private static final int SIZE = 10000;
    public static void main(String[] a)
    {
        Hashtable<Integer,Integer> list = new Hashtable<Integer, Integer>();
        //store the number of divisors of i at index i
        for(int i = 1; i < SIZE; i++)
        {
            list.put(i,divisors(i));
        }
        // sum up every amicable number that is not a perfect number (6 for instance is excluded)
        int sum = 0;
        for(int i = 2; i < SIZE; i++)
        {
            int temp = list.get(i);
            System.out.println(i+" "+temp);
            if(temp < SIZE && i != temp)
            {
                sum += (i == list.get(temp)) ? i : 0;
            }
        }
        System.out.println(sum);
    }

    /**
     * find the divisors in n not including n
     */
    private static int divisors(int n)
    {
        int sum = 0;
        for(int i = 1; i < n; i++)
        {
            sum += (n%i == 0) ? i : 0;
        }
        return sum;
    }
}