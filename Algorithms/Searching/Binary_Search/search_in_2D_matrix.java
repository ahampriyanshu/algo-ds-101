public class search_in_2D_matrix {
    public static boolean searchMatrix(int[][] matrix, int target) {
    int colLength = matrix[0].length-1;
        for(int i = 0; i < matrix.length; i++) {
            if(target > matrix[i][colLength]) continue;
            int start = 0, end = colLength;
            while(start <= end) {
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
        int mat[][] = { { 10, 20, 30, 40 },
                    { 15, 25, 35, 45 },
                    { 27, 29, 37, 48 },
                    { 32, 33, 39, 50 } };

        boolean isFound = searchMatrix(mat,29);
        System.out.println(isFound);
    }
}