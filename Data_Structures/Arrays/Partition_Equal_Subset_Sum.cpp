 #include<iostream>
 #include<vector>
 #include<algorithm>

 using namespace std;
 bool isSubset(vector<int>& nums, int sum,int n){
        bool t[n+1][sum+1];
        for(int i=1;i<=n;i++){
            for(int j=1;j<=sum;j++){
                t[0][0]=true;
                    t[0][j]= false;

                t[i][0]= true;

                 if(nums[i-1]<=j){
                    t[i][j]= (t[i-1][j-nums[i-1]] || t[i-1][j]);

                }
                else{t[i][j]= t[i-1][j];}
            }
        }
        return t[n][sum];

    }

 bool canPartition(vector<int>& nums) {

       long  int sum=0;
        for(int i=0;i<nums.size();i++){
            sum=sum+nums[i];
        }
        if(sum%2!=0){
            return false;
        }
        else if(sum%2==0){
         return isSubset(nums,sum/2, nums.size());
        }
        return false;
    }


    int main(){
        vector<int> nums ;
        
        nums.push_back(1);
        nums.push_back(5);
        nums.push_back(11);
        nums.push_back(5);
          nums.push_back(5);
        bool n = canPartition(nums);
        cout<<n;
        return 0;
    }
