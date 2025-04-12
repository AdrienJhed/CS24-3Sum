#include <vector>
#include <random>
#include <algorithm>
#include <string>
#include <iostream>
#include <cstdlib>
#include <array>
#include <ctime>
#include <chrono>
#include <thread>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> uniqueTriplets;
        for(int i = 0; i < nums.size() - 2; i++){
            for(int j = i + 1; j < nums.size() - 1; j++){
                for(int k = j + 1; k < nums.size(); k++){
                        if(nums[i] + nums[j] + nums[k] == 0){
                            vector<int> triplet = {nums[i], nums[j], nums[k]};
                            sort(triplet.begin(), triplet.end());
                            uniqueTriplets.push_back(triplet);
                        }
                    }
                }
            }
            sort(uniqueTriplets.begin(), uniqueTriplets.end());
            uniqueTriplets.erase(unique(uniqueTriplets.begin(), uniqueTriplets.end()), uniqueTriplets.end());
            return uniqueTriplets;
        }
};

vector<int> genInput(int n){
    vector<int> nums;

    int a = rand() % 100;
    int b = rand() % 100;
    int c = -(a + b);
    int d;

    for(int i = 0; i < n - 3; i++){
        d = rand() % 100;
        nums.push_back(d);
    }

    nums.push_back(a);
    nums.push_back(b);
    nums.push_back(c);

    return nums;
}

int main(){
    vector<int> n = {100, 200, 400, 800, 1600, 4000};

    Solution Sol;

    for (int i = 0; i < n.size(); i++){
        vector<int> nums = genInput(n[i]);

        //timer
        auto start = chrono::high_resolution_clock::now();
        vector<vector<int>> result = Sol.threeSum(nums);
        auto end = chrono::high_resolution_clock::now();
        
        double time_ms = chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0;
        
        cout << "Size: " << n[i] << ", Time: " << time_ms << " ms" << endl;
    }
    
    return 0;
}