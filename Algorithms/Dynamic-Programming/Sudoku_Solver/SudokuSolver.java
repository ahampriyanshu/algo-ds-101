import java.util.*;
import java.io.*;
class SudokuSolver {
    static class FastReader{
        BufferedReader br;
        StringTokenizer st;
        FastReader(){
            br = new BufferedReader(new InputStreamReader(System.in));
        }
        String next(){
            while(st==null || !st.hasMoreElements()){
                try{
                    st =new StringTokenizer(br.readLine());
                }
                catch(IOException e)    {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }
        int nextInt(){
            return Integer.parseInt(next());
        }
    }
    public static void main(String[] args) {
        FastReader fr = new FastReader();
        int n = fr.nextInt();
        int[][] board = new int[n][n];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                board[i][j] = fr.nextInt();
            }
        }
        solveSudoku(board, 0,0);
    }
    public static boolean isSafe(int[][] board,int row,int col,int index){
        if(board[row][col]!=0){
            return false;
        }
        for(int i=0;i<9;i++){
            if(board[row][i]==index){
                return false;
            }
        }
        for(int i=0;i<9;i++){
            if(board[i][col]==index){
                return false;
            }
        }
        row = row - row%3;
        col = col - col%3;
        for(int i=row;i<row+3;i++){
            for(int j=col;j<col+3;j++){
                if(board[i][j]==index){
                    return false;
                }
            }
        }
        return true;
    }
    public static void solveSudoku(int[][] board, int row, int col){
        if(row==9){
            for(int i=0;i<9;i++){
                for(int j=0;j<9;j++){
                    System.out.print(board[i][j]+ " ");
                }
                System.out.println();
            }
            return;
        }
        if(col==9){
            solveSudoku(board, row+1,0);
            return;
        }
        if(board[row][col]==0)
        {
            for(int i=1;i<=9;i++){
                if(isSafe(board,row,col,i)){
                    board[row][col] = i;
                    solveSudoku(board, row,col+1);
                    board[row][col]=0;
                }
            }
        }else{
            solveSudoku(board, row,col+1);
        }
    }
}
