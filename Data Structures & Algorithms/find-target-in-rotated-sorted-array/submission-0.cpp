class Solution {
public:
    int bs(int i,int j,vector<int>&nums,int target){
        while(i<=j){
            int mid = i+(j-i)/2;
            if(nums[mid]==target)return mid;
            else if(nums[mid]>target)j=mid-1;
            else i=mid+1;
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int i=0,j=nums.size()-1,res=-1;
        while(i<=j){
            int mid = i+(j-i)/2;
            bool flag = mid-1>=0? nums[mid-1]<nums[mid]? true:false:true;
            flag = mid+1<nums.size()? nums[mid+1]<nums[mid]? true:false:true;
            if(flag){
                res=mid;
                break;
            }
            else if(nums[i]<nums[mid]){
                if(res==-1 || (res!=-1 && nums[res]<nums[mid]))
                   res=mid;
                i=mid+1;
            }
            else{
                if(res==-1 || (res!=-1 && nums[res]<nums[j]))
                   res=j;
                j=mid-1;
            }
        }
        if(target>=nums[0] && target<=nums[res]){
            int ans=bs(0,res,nums,target);
            if(ans!=-1)return ans;
        }
        else{
            int ans=bs(res+1,nums.size()-1,nums,target);
            if(ans!=-1)return ans;
        }
        return -1;
    }
};
