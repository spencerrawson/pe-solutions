public class pe17
{
    /**
     * Make a sum value then loop and find the length of all the sums
     * and print the sum
     */
    public static void main(String[] a)
    {
        int sum = 0;
        //loop through 1-999 and add the length of their word values
        for(int i = 1; i < 1000; i++)
        {
            sum += toWords(i).length();
        }
        //for the number 1000 specifically
        sum += 11;
        System.out.println("Sum is "+sum+"\n");
    }

    /**
     * Convert given integer (less than 1000) to word value
     * and then return the words as a string
     */
    public static String toWords(int num)
    {
        String ans = "";
        //These two arrays have the word equivalents of the numbers that will be used
        String[] ones = {"","one","two","three","four","five","six","seven","eight","nine","ten","eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen"};
        String[] tens = {"twenty","thirty","forty","fifty","sixty","seventy","eighty","ninety"};
        //If the number is greater than 100 then add the correct hundred value and if there are numbers in the tens/ones then add "and"
        if(num>99)
        {
            ans += ones[num/100]+"hundred";
            if(num%100 > 0)
            {
                ans += "and";
            }
            //remove the 100's digit to make the later steps more efficient
            num = num%100;
        }
        if(num > 19)
        {
            ans += tens[(num/10)-2];
            ans += ones[num%10];
        }
        else if(num > 0)
        {
            ans += ones[num];
        }
        return ans;
    }
}

