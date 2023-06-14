namespace MaxSubArray{
    class Program{
        public static void Main(string[] args){
            Console.WriteLine(MaxSubArray(new int[]{1}));
        }

        public static int MaxSubArray(int[] nums) {
            int max = nums[0], tmp;

            for(int i = 0; i < nums.Length; i++){

                tmp = 0;

                for(int j = i; j < nums.Length; j++){
                    tmp += nums[j];
                    if(tmp > max){
                        max = tmp;
                    }
                }

            }

            return max;
        }
    }
}