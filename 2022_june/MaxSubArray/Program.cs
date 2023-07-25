using System.Collections.Generic;
namespace MaxSubArray{
    class Program{
        public static void Main(string[] args){
            Console.WriteLine(MaxSubArray(new int[]{-2,1,-3,4,-1,2,1,-5,4}));
        }

        public static int MaxSubArray(int[] nums) {
            // int max = nums[0];
            // int[] mem = new int[nums.Length];

            // for(int i = 0; i < nums.Length; i++){
            //     if(nums[i] > max){
            //         max = nums[i];
            //     }
            //     mem[0] = nums[i];
            //     for(int j = i+1; j < mem.Length; j++){
            //         if(i == 0){
            //             mem[j] = mem[j - 1] + nums[j];
            //         }
            //         else{
            //             mem[j] -= nums[i - 1];
            //         }

            //         if(mem[j] > max){
            //             max = mem[j];
            //         }
            //     }
            // }

            // return max;

            int max = int.MinValue, sum = 0;
            
            for(int i = 0; i < nums.Length; i++){
                sum += nums[i];

                if(sum > max){
                    max = sum;
                }

                if(sum < 0){
                    sum = 0;
                }
            }

            return max;
        }
    }
}