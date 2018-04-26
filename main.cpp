// MERGE SORT IMPLEMENTATION

// PSEUDOCODE: 
// split vector into (0, n/2] and (n/2, end]
// call MergeSort on left and right if left or right size is greater than 1
// then, merge left and right using two iterators, one pointing at left and one at right
// compare *left and *right, put the smaller one into return vector


#include <cstddef>
#include <iostream>
#include <vector> 

using namespace std;

typedef vector<int>::iterator iter;

void PrintVector(const vector<int>& vec){
    size_t size = vec.size();
    for(size_t i = 0; i!= size; ++i){
        cout << vec[i] << " ";
    }
    cout << endl;
}

vector<int> MergeSort(const vector<int>& nums){
    PrintVector(nums);

    // exit condition
    if (nums.size() == 1){
        return nums;
    } 

    // split into two
    vector<int> left(nums.begin(), nums.begin() + nums.size() / 2);
    vector<int> right(nums.begin() + nums.size() / 2, nums.end());
    left = MergeSort(left);
    right = MergeSort(right);
    
    // merge next
    iter left_iter = left.begin();
    iter right_iter = right.begin();
    vector<int> merged;
    while (left_iter != left.end()|| right_iter != right.end()){
        if (left_iter == left.end()){
            merged.push_back(*right_iter++);
            cout << "Right appended" << endl;
        } else if (right_iter == right.end()){
            merged.push_back(*left_iter++);
            cout << "left appended" << endl;
        } else if (*left_iter >= *right_iter){
            merged.push_back(*right_iter++);
            cout << "Right appended" << endl;
        } else if (*left_iter < *right_iter){
            merged.push_back(*left_iter++);
            cout << "left appended" << endl;
        }         
        PrintVector(merged);
    }

    return merged;
}

int main() {
    vector<int> nums = {5, 3, 2, 15, 0, -5, 12};
    vector<int> sorted = MergeSort(nums);
    PrintVector(sorted);

    return 0;
}