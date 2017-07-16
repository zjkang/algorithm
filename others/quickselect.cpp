#include <iomanip>
#include <iostream>
#include <vector>
#include <iostream>
#include <string>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
using namespace std;

int partition(vector<int>& nums, int s, int e) {
    int pivot = nums[s];
    while (s < e) {
        while (s < e && nums[e] >= pivot) {
            e--;
        }
        swap(nums[s], nums[e]);
        while (s < e && nums[s] < pivot) {
            s++;
        }
        swap(nums[s], nums[e]);
    }
    return s;
}

int quickSelect(vector<int>& nums, int s, int e, int k) {
    int n = partition(nums, s, e);
    if (n == k) return nums[k];
    else if (n < k) {
        return quickSelect(nums, n+1, e, k);
    } else {
        return quickSelect(nums, s, n-1, k);
    }
}

int main() {
    vector<int> nums = {5, 9, 3, 2, 4, 8};
    int k = 6; 
    
    int val = quickSelect(nums, 0, nums.size()-1, k-1);
    cout << val << endl;
    return 0;
}