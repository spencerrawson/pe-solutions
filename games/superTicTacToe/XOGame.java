public class XOGame {
    private int[][] board;
    private int winner;

    //basic constructor that makes everything 0
    public XOGame()
    {
        board = new int[][] {{0,0,0}, {0,0,0}, {0,0,0}};
        winner = 0;
    }

    /**
     * Description: Makes a turn in board given a player and a square
     * Pre: player is true for player 1 and false for player 2, and square is 1-9 and not occupied
     * Post: board is updated
     */
    public void turn(boolean player, int square)
    {
        square--;
        board[square/3][square%3] = (player) ? 1 : 2;
        winner = winnerCheck();
    }

    /**
     * Description: Returns the Nth row as a string
     * Pre: row is properly made, n is from 0 to 2
     * Post: returns the string print of the nth row
     */
    public String printRow(int n)
    {
        String ans = "";
        if(winner == 0)
        {
            for(int x : board[n])
            {
                if(x == 0) { ans += "-"; }
                if(x == 1) { ans += "X"; }
                if(x == 2) { ans += "O"; }
            }
        }
        else if(winner == 1)
        {
            if(n==0) { ans += "\\ /"; }
            if(n==1) { ans += " X "; }
            if(n==2) { ans += "/ \\"; }
        }
        else
        {
            if(n==0) { ans += "/-\\"; }
            if(n==1) { ans += "| |"; }
            if(n==2) { ans += "\\-/"; }
        }
        return ans;
    }

    /**
     * Description: checks for winner in current board
     * Pre: Board is made
     * Post: winner is returned (0 if no winner)
     */
    private int winnerCheck()
    {
        //horizontal lines
        if(board[0][0] == board[0][1] && board[0][1] == board[0][2] && board[0][0] != 0){ return board[0][0]; }
        if(board[1][0] == board[1][1] && board[1][1] == board[1][2] && board[1][0] != 0){ return board[1][0]; }
        if(board[2][0] == board[2][1] && board[2][1] == board[2][2] && board[2][0] != 0){ return board[2][0]; }
        //vertical lines
        if(board[0][0] == board[1][0] && board[1][0] == board[2][0] && board[0][0] != 0){ return board[0][0]; }
        if(board[0][1] == board[1][1] && board[1][1] == board[2][1] && board[0][1] != 0){ return board[0][1]; }
        if(board[0][2] == board[1][2] && board[1][2] == board[2][2] && board[0][2] != 0){ return board[0][2]; }
        //diagonals
        if(board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != 0){ return board[0][0]; }
        if(board[2][0] == board[1][1] && board[1][1] == board[0][2] && board[0][0] != 0){ return board[2][0]; }
        return 0;
    }

    //returns winner publicly
    public int getWinner() { return winner; }
}
