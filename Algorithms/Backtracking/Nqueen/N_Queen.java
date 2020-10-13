import java.util.*;
public class N_Queen {
	final int N=4;
	public boolean solveNQUtil(int board[][],int col) {
		if(col>=N)
			return  true;
		for(int i=0;i<N;i++) {
			if(isSafe(board,i,col)) {
				board[i][col]=1;
			if(solveNQUtil(board,col+1)) 
				return true;
			board[i][col]=0;
			}
		}
		return false;
		
	}
boolean isSafe(int board[][],int row,int col) {
	int i,j;
	for(i=0;i<col;i++) 
		if(board[row][i]==1)
			return false;
		for(i=row,j=col;i>=0&&j>=0;i--,j--)
			if(board[i][j]==1)
				return false;
		return true;
	
}


boolean solveNQ() {
	int board[][]= {{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}
			
	};

	if(solveNQUtil(board,0)==false) {
		System.out.println("solution does nor exist");
		return false;
	}
	
	printsolution(board);
	return true;
	
}


void printsolution(int board[][]) {
	for(int i=0;i<N;i++) {
		for(int j=0;j<N;j++) 
			System.out.print(" "+board[i][j]+"  ");
		System.out.println();
 }
}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		N_Queen Queen= new N_Queen();
		Queen.solveNQ();
	}

}
