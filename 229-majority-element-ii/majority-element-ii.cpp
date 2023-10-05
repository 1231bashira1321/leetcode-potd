class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
     int n=nums.size();
     vector<int> ans;
     int cnt1=0;
     int cnt2=0;
     int ele1=0;
     int ele2=0;
     for(int i=0;i<n;i++){
         if(cnt1==0 && ele2 !=nums[i]){
             cnt1++;
             ele1=nums[i];
         }
         else if(cnt2==0 && ele1 !=nums[i]){
             cnt2++;
             ele2=nums[i];
         }
         else if(ele1==nums[i]){cnt1++;}
         else if(ele2==nums[i]){cnt2++;}
         else {cnt1--;cnt2--;}
     }
     //check
     cnt1=0;
     cnt2=0;
     for(int i=0;i<n;i++){
         if(ele1==nums[i]){cnt1++;}
         else if(ele2==nums[i]){cnt2++;}
     }
     int mini=(int)(n/3) +1;
     if(cnt1>=mini){ans.push_back(ele1);}
     if(cnt2>=mini){ans.push_back(ele2);}
     return ans;   
    }
};