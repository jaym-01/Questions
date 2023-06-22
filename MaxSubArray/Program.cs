using System.Collections.Generic;
namespace MaxSubArray{
    class Program{
        public static void Main(string[] args){
            Console.WriteLine(MaxSubArray(new int[]{-2,1,-3,4,-1,2,1,-5,4}));
        }

        public static int MaxSubArray(int[] nums) {
            int max = int.MinValue;
            List<int> grouped = new List<int>();

            bool prev_neg = !(nums[0] < 0);
            for(int i = 0; i < nums.Length; i++){
                if((prev_neg && nums[i] > 0) || (!prev_neg && nums[i] < 0)){
                    grouped.Add(nums[i]);
                }
                else{
                    grouped[grouped.Count - 1] += nums[i];
                }
            }

            return max;
        }
    }
}