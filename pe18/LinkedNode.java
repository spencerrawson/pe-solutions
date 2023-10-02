/**
 * Author: Spencer Rawson
 * Date: 10/2/23
 * Purpose: Node class in order to make a list with two child nodes
 * that can be the same node in the list (unlike a BST)
 */
public class LinkedNode 
{
    private LinkedNode leftNode, rightNode;
    private int value;
    public LinkedNode(int v)
    {
        value = v;
    }    

    public LinkedNode(LinkedNode l, LinkedNode r, int v)
    {
        leftNode = l;
        rightNode = r;
        value = v;
    }

    /**
     * get and set methods for left, right, and value
     */
    public LinkedNode getLeft()
    {
        return leftNode;
    }
    public LinkedNode getRight()
    {
        return rightNode;
    }
    public void setLeft(LinkedNode l)
    {
        leftNode = l;
    }
    public void setRight(LinkedNode r)
    {
        rightNode = r;
    }
    public int getValue()
    {
        return value;
    }
    public void setValue(int v)
    {
        value = v;
    }
}
