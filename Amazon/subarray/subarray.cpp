#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

void printArray(vector<int> arr) {
    cout << setw(4);
    cout << '[';
    for(auto i : arr) {
        cout << i << (i == arr.back() ? "" : " ");
    }
    cout << "]," << endl;
}

void printArray(vector<int> arr, int target) {
    cout << "array: [";
    for(auto i : arr) {
        cout << i << (i == arr.back() ? "" : " ");
    }
    cout << "]     target: " << target << endl;
}

void printArray(vector<vector<int>> arr) {
    cout << '[' << endl;
    for(int i = 0; i < arr.size(); ++i) {
        printArray(arr[i]);
    }
    cout << ']' << endl;
}

vector<vector<int>> findSubArray(const vector<int>& nums, int target) {
    vector<vector<int>> sub;
    vector<int> temp;
    int i = 0, j = 1, curr = nums[i] + nums[j];
    
    while(j < nums.size()) {
        if(curr == target) {
            for(int k = i; k <=  j; ++k) {
                temp.push_back(k);
            }   
            sub.push_back(temp);
            temp.clear();
            curr += nums[++j];
        }
        else if(curr < target) {
            ++j;
            curr += nums[j];
        }        
        else if(curr > target) {
            curr -= nums[i];
            ++i;
        }
    }
    return sub;

}

int main() {
    vector<int> nums = {2, 4, 2, 3, 1};
    int target = 6;
    printArray(nums, target);
    vector<vector<int>> sub = findSubArray(nums, target);
    printArray(sub);
    return 0;
}
