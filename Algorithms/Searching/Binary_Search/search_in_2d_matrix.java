import java.util.Arrays;

public class Binary_Search_in_2D_matrix {
    public static void main(String[] args) {
        int [][]nums  = {{1,2,3,4},
                {5,6,7,8},
                {9,10,11,12},
                {13,14,15,16}};
        System.out.println(Arrays.toString(binarySearch2D(nums,16)));
    }
    static int[] binarySearch2D(int[][]arr,int target){
        int row = 0;
        int column = arr.length-1;
        while(row< arr.length&&column>=0){
            if(target>arr[row][column]){
                row++;
            }else if(target<arr[row][column]){
                column--;
            }else{
                return new int[]{row,column};
            }
        }
        return new int[]{-1,-1};
    }
}
