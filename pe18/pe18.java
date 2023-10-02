/**
 * Author: Spencer Rawson
 * Date: 10/2/23
 * Purpose: Solve the maximum number in any path
 * of the given triangle
 * I know that the LinkedNode is unnecessary,
 * but I had fun coding it so i'm leaving it in.
 */
import java.util.Scanner;
import java.io.BufferedReader;
import java.io.FileReader;
public class pe18
{
    //array for the pyramid
    private static int[][] nums = new int[15][15];
    //start node for the homemade doubly linked list thing
    private static LinkedNode start;
    public static void main(String[] a) throws Exception
    {
        Scanner s = new Scanner(new BufferedReader(new FileReader("pe18_input.txt")));
        for(int i = 0; i < 15; i++)
        {
            for(int j = 0; j <= i; j++)
            {
                nums[i][j] = s.nextInt();
            }
        } 
        s.close();
        start = new LinkedNode(nums[0][0]);
        LinkedNode temp = start;
        start = storeInNode(temp, 0, 1);
        //Now to solve the actual problem
        int sum = 0;
        simplify(start);
        System.out.println(start.getValue());
    }

    /**
     * recursively store the array into the nodes
     * only a separate function for recursion purposes
     */
    private static LinkedNode storeInNode(LinkedNode n, int index, int row)
    {
        if(row < 14)
        {
            n.setLeft(storeInNode(new LinkedNode(nums[row][index]), index, row+1));
            n.setRight(storeInNode(new LinkedNode(nums[row][index+1]), index+1, row+1));
        }
        else{
            n.setLeft(new LinkedNode(nums[row][index]));
            n.setRight(new LinkedNode(nums[row][index+1]));
        }
        return n;
    }

    /**
     * Recursively simplifies the pyramid to its final value
     * and removes the left and rights of the pyramid to remain with only the sum at the top.
     */
    private static LinkedNode simplify(LinkedNode n)
    {
        if(n.getLeft() != null)
        {
            if(n.getLeft().getLeft() != null)
            {
                simplify(n.getLeft());
                simplify(n.getRight());
                n.setValue(n.getValue() + ((n.getLeft().getValue() > n.getRight().getValue()) ? n.getLeft().getValue() : n.getRight().getValue()));
                n.setLeft(null);
                n.setRight(null);
            }
            else
            {
                n.setValue(n.getValue() + ((n.getLeft().getValue() > n.getRight().getValue()) ? n.getLeft().getValue() : n.getRight().getValue()));
            }
        }
        return n;
    }
}