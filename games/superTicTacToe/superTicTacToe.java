import java.util.*;
public class superTicTacToe
{
    public static void main(String[] a)
    {
        XOGame[][] myGame = new XOGame[3][3]; //matrix of tictactoe games
        for(int i = 0; i < 3; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                myGame[i][j] = new XOGame(); //initialize every game
            }
        }
        int[][] winners = new int[][] {{0,0,0},{0,0,0},{0,0,0}}; //matrix of winner values
        int superWinner = 0;
        Scanner s = new Scanner(System.in);
        System.out.println("Which Board?");
        int currentBoard = s.nextInt();
        int currentSquare = 0;
        boolean player = true;
        while(superWinner == 0)
        {
            if(winners[(currentBoard-1)/3][(currentBoard-1)%3] != 0) //if the current board is finished, let player choose new board
            {
                System.out.println("Which Board?");
                currentBoard = s.nextInt();
            }
            else
            {
                System.out.println("Current Board is "+currentBoard);//reminds player what board they are on
            }
            System.out.println("Which Square?");//gets new square
            currentSquare = s.nextInt();
            int r = (currentBoard-1)/3; //to save typing
            int c = (currentBoard-1)%3; //to save typing
            myGame[r][c].turn(player, currentSquare); //do the turn on the right board
            printGame(myGame); //print game state
            winners[r][c] = myGame[r][c].getWinner();//update winners with correct value
            currentBoard = currentSquare;//part of super tictactoe's rules
            player = !player; //change players every turn
            superWinner = superWinCheck(winners); //check if the super game is won
        }
        s.close();
        System.out.println("Winner is Player "+superWinner);
    }

    /**
     * Description: Prints entire state of all games in a meta grid
     * Pre: g is myGame
     * Post: game state is printed
     */
    private static void printGame(XOGame[][] g)
    {
        for(int i = 0; i < 3; i++)
        {
            System.out.println(g[i][0].printRow(0)+"|"+g[i][1].printRow(0)+"|"+g[i][2].printRow(0));
            System.out.println(g[i][0].printRow(1)+"|"+g[i][1].printRow(1)+"|"+g[i][2].printRow(1));
            System.out.println(g[i][0].printRow(2)+"|"+g[i][1].printRow(2)+"|"+g[i][2].printRow(2));
            if(i != 2)
            {
                System.out.println("~~~~~~~~~~~");
            }
        }
    }

    /**
     * Description: checks if there is a winner of the super game
     * Pre: a is winners
     * Post: super winner is returned (0 if no super winner)
     */
    private static int superWinCheck(int[][] a)
    {
        //horizontal lines
        if(a[0][0] == a[0][1] && a[0][1] == a[0][2] && a[0][0] != 0){ return a[0][0]; }
        if(a[1][0] == a[1][1] && a[1][1] == a[1][2] && a[1][0] != 0){ return a[1][0]; }
        if(a[2][0] == a[2][1] && a[2][1] == a[2][2] && a[2][0] != 0){ return a[2][0]; }
        //vertical lines
        if(a[0][0] == a[1][0] && a[1][0] == a[2][0] && a[0][0] != 0){ return a[0][0]; }
        if(a[0][1] == a[1][1] && a[1][1] == a[2][1] && a[0][1] != 0){ return a[0][1]; }
        if(a[0][2] == a[1][2] && a[1][2] == a[2][2] && a[0][2] != 0){ return a[0][2]; }
        //diagonals
        if(a[0][0] == a[1][1] && a[1][1] == a[2][2] && a[0][0] != 0){ return a[0][0]; }
        if(a[2][0] == a[1][1] && a[1][1] == a[0][2] && a[0][0] != 0){ return a[2][0]; }
        return 0;
    }
}