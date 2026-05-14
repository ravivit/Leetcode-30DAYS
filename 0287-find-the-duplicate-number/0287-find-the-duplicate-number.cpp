class Solution {
public:
    int findDuplicate(vector<int>& nums) {
    
      int slow  = nums[0];
      int fast  = nums[0];   // variuble declare 

      do {
        slow = nums[slow];      // ye  1 point chelega
        fast = nums[nums[fast]]; // ye 2 point chaalega 
       }

       while (slow!= fast);     // jb tk slow and start same nahi ho jate 
       slow = nums[0];  // ek pointer dobara start pr jayega 

     while (slow!= fast ) {

        slow = nums[slow]; // now dono pointer ek ek point chalege jha
        fast = nums[fast]; // jaha milege  vhi duplicate numnber start hoga

     }

     return slow;
}

};

    