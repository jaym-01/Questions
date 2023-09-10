# Programming Questions

Just some of the solutions to the questions I have done on leet code

```
    bool validPartition(vector<int>& nums) { 
         // vector<vector<int>> mem = vector<vector<int>>(nums.size(), vector<int>(nums.size(), -1)); 
  
         int** mem1 = new int*[nums.size()]; 
  
         for(int i = 0; i < nums.size(); i++){ 
             mem1[i] = new int[nums.size()]; 
             for(int j = 0; j < nums.size(); j++){ 
                 mem1[i][j] = -1; 
             } 
         } 
  
         return find_partitions(nums, 0, mem1); 
     }

```