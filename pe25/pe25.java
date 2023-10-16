/**
 * Author: Spencer Rawson
 * Date: 10/16/23
 * Purpose: Solve problem 25 using a formula (found through the
 * wikipedia for the fibbonacci sequence) using the golden ratio
 * to the nth power divided by root(5).  Run through a number, check the digits
 * and if below 1000 multiply if above divide.
 */
public class pe25
{
    //constant for the fibbonacci formula of the nth term
    private static final double goldenRatio = 1.6180339887;
    /**
     * find the first fibbonacci number which has 1000 digits
     */
    public static void main(String[] a)
    {
        int x = 10; //arbitrary value of multiplication for reducing checks
        int ans = 0; //constantly changing value of digits for num
        int num = 1; //actual number that is being checked
        boolean upCheck = true; //boolean for if num is going up or not
        while(ans != 1000)
        {
            ans = fibonnaciDigits(num);
            //if it is not going up, reduce x to get closer to right value and then multiply by x
            if(ans < 1000 && x > 1)
            {
                if(!upCheck)
                {
                    x -= 1;
                    upCheck = true;
                }
                num *= x;
            }
            //if it is going up, reduce x to get closer to right value and then divide by x
            else if(ans > 1000 && x > 1)
            {
                if(upCheck)
                {
                    x -= 1;
                    upCheck = false;
                }
                num /= x;
            }
            //basic check for adding / subtracting to find a number that has 1000 digits
            else if(ans != 1000)
            {
                if(upCheck)
                {
                    num++;
                }
                else
                {
                    num--;
                }
            }
        }
        //final loop for ensuring that num is at the first number that has 1000 digits
        while(fibonnaciDigits(num-1) == 1000)
        {
            num--;
        }
        System.out.println(num);
    }

    /**
     * use the formula for the nth term and consistent division to find the number of digits
     * in the nth fibbonacci number and return it.
     */
    private static int fibonnaciDigits(int n)
    {
        int digits = 0;
        double num = 1/Math.sqrt(5);
        //looping formula for multiplying by golden ratio and dividing my 10 if > 10
        for(int i = 1; i <= n; i++)
        {
            num *= goldenRatio;
            if(num >= 10)
            {
                num /= 10;
                digits++;
            }
        }
        //one final digit count for the last digit
        digits++;
        return digits;
    }
}