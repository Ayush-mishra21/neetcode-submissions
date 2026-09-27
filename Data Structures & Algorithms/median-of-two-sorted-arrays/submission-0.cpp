class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int a=nums1.size(),b=nums2.size();
        vector<int>arr;
        int i=0,j=0;
        while(i<nums1.size() && j<nums2.size()){
            if(nums1[i]<=nums2[j]){
                arr.push_back(nums1[i]);
                i++;
            }
            else{
                arr.push_back(nums2[j]);
                j++;
            }
        }
        while(i<nums1.size()){
            arr.push_back(nums1[i]);
            i++;
        }
         while(j<nums2.size()){
            arr.push_back(nums2[j]);
            j++;
        }
        if(arr.size()%2!=0){
            return double(arr[arr.size()/2]);
        }
        else{
            int mid1=arr.size()/2;
            int mid2=mid1-1;
            return double(arr[mid1]+arr[mid2])/2.0;
        }
    }
};
