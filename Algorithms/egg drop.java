public class EggDroppDP {

    public int getDrops(int eggs, int floors){

        int [][] eggDrops = new int [eggs+1][floors+1];
        //base case 1:
        //if floors = 0 then no drops are required // OR floors = 1 then 1 drop is required
        for (int i = 1; i <=eggs ; i++) {
            eggDrops[i][0] = 0;
            eggDrops[i][1] = 1;
        }
        //base case 2:
        //if only one egg is there then drops = floors
        for (int i = 1; i <=floors ; i++) {
            eggDrops[1][i] = i;
        }

        for (int i = 2; i <=eggs ; i++) {
            for (int j = 2; j <=floors ; j++) {
                eggDrops[i][j] = Integer.MAX_VALUE;
                int tempResult;
                for (int k = 1; k <=j ; k++) {
                    tempResult = 1 + Math.max(eggDrops[i-1][k-1], eggDrops[i][j-k]);
                    eggDrops[i][j] = Math.min(tempResult,eggDrops[i][j]);
                }
            }
        }
        // eggDrops[eggs][floors] will have the result : minimum number of drops required in worst case
        return eggDrops[eggs][floors];
    }

    public static void main(String[] args) {
        EggDroppDP eggDP = new EggDroppDP();
        int eggs = 2;
        int floors = 100;
        System.out.printf("(DP) Minimum number of drops required in worst case with eggs:
             %s and floors: %s is : %s",eggs,floors,eggDP.getDrops(eggs,floors));
    }
}
