#include<iostream>
#include<queue>
#include<algorithm>
#include<list>
#include<sstream> 

using namespace std;

class Solution{
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        vector<int> ans;
        if(k <= 0){
            return ans;
        }
        auto&& begin = arr.begin();
        auto&& end = arr.end();
        //std::nth_element(begin,begin + k,end);
        quick_sort_nth_element(arr,k,0,arr.size());

        for (size_t i = 0; i < k; i++)
        {
            ans.push_back(arr[i]);
        }
        return ans;
    }
    
    //前序遍历
    void quick_sort_nth_element(vector<int>& arr, int k,int begin,int end){
        if(begin >= end){
            return;
        }

        int left = begin;
        int right = end;
        int pivot = arr[begin];
        //左开右开区间思想
        while(left < right){
            while(++left < end && arr[left] <= pivot);
            while(--right > begin && arr[right] >= pivot);
            if(left < right){ swap(arr[left],arr[right]); }
        }
        swap(arr[right],arr[begin]);
        if(right == k){
            return;
        }
        else if(k < right){
            quick_sort_nth_element(arr,k,begin,right);
        }
        else{
            quick_sort_nth_element(arr,k,right + 1,end);
        } 
    }

};


class Solution2 {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        vector<int> ans;
        if(k <= 0){
            return ans;
        }
        auto&& begin = arr.begin();
        auto&& end = arr.end();
        //std::nth_element(begin,begin + k,end);
         quick_sort_nth_element(arr,k,0,arr.size());

        for (size_t i = 0; i < k; i++)
        {
            ans.push_back(arr[i]);
        }
        return ans;
    }

    void quick_sort_nth_element(vector<int>& arr, int k,int begin,int end){
        if(begin >= end){
            return;
        }

        int left = begin;
        int right = end;
        int pivot = arr[begin];
        int hole_id = begin;
        while(left < right){
            while(--right > begin && arr[right] >= pivot);
            if(right <= left){ break; }
            arr[left] = arr[right];
            hole_id = right;

            while(++left < end && arr[left] <= pivot);
            if(right <= left){ break; }
            arr[right] = arr[left];
            hole_id = left;
        }
        arr[hole_id] = pivot;

        if(hole_id == k){
            return;
        }
        else if(k < right){
            quick_sort_nth_element(arr,k,begin,hole_id);
        }
        else{
            quick_sort_nth_element(arr,k,hole_id + 1,end);
        } 

    }

};



   
