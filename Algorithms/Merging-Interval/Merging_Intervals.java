import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class Merging_Intervals {
	
	public static void main(String args[]) {
		//Given 2D array containing intervals
		int[][] ans = {{1,3},{2,6},{8,10},{15,18}};
		
		//This function returns 2D array having our merged intervals
		ans = merge(ans);
		
		//Each merged interval will be displayed on each line
		for (int i = 0; i < ans.length; i++) {
			for (int j = 0; j < ans[0].length; j++) {
				System.out.print(ans[i][j] + " ");
			}
			System.out.println();
		}
	
	}
	
	public static int[][] merge(int[][] intervals) {
        
        if (intervals.length <= 1) {
            return intervals;
        }
        
        //Perform sorting in increasing order of first element of each interval
        Arrays.sort(intervals, (a1, a2) -> a1[0] - a2[0]);
        
        List<int[]> output_arr = new ArrayList<int[]>();
        
        int[] curr_interval = intervals[0];
        output_arr.add(curr_interval);
        
        for (int[] interval : intervals) {
            int curr_beg = curr_interval[0];
            int curr_end = curr_interval[1];
            int next_beg = interval[0];
            int next_end = interval[1];
            
            if (curr_end >= next_beg) {
                curr_interval[1] = Math.max(curr_end, next_end);
            }
            else {
                curr_interval = interval;
                output_arr.add(curr_interval);
            }
        }
        
        return output_arr.toArray(new int[output_arr.size()][]);
        
    }
	
}
