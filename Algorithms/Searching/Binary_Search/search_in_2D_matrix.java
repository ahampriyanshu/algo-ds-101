public class search_in_2D_matrix {
    public static boolean searchMatrix(int[][] matrix, int target) {
        int colLength = matrix[0].length-1; // each row length
        for(int i = 0; i < matrix.length; i++) { // iterate over every row
            if(target > matrix[i][colLength]) continue; // if target is greater than the highest number in that row then skip that row
            int start = 0, end = colLength;
            while(start <= end) { // using binary search algorithm to search through the row for the target
                int mid = start + (end-start)/2;
                if(matrix[i][mid] == target) return true;
                if(matrix[i][mid] > target) end = mid-1;
                else if(matrix[i][mid] < target) start = mid+1;
            }
        }
        return false;
    }
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter number of rows");
        int row = sc.nextInt();
        System.out.println("Enter number of coloumns");
        int col = sc.nextInt();
  
        int mat[][] = new int[row][col];
        
        System.out.println("Enter matrix elements in sorted manner");
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                mat[i][j] = sc.nextInt();
            }
        }
        System.out.println("Enter element to be searched");
        int target = sc.nextInt();
        boolean isFound = searchMatrix(mat,target);
        if(isFound) {
            System.out.println("Target element found in matrix");
        }
        else {
            System.out.println("Target element not found in matrix");
        }
    }
}
