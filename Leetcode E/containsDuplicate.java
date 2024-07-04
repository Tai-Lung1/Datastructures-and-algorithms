
//Faulty code because TLE, but the logic is correct
class Solution {
    public boolean containsDuplicate(int[] nums) {
        int f_pointer = 0;
        int s_pointer = nums.length-1;
        while(f_pointer<s_pointer){
        if(nums[f_pointer]==nums[s_pointer]){
            return true;
        }
        if(s_pointer-1==f_pointer){
            f_pointer +=1;
            s_pointer =nums.length-1;
        }
        else{
            s_pointer -=1;
        }
        }
    return false;
    }
}