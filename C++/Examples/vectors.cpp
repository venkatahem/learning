// #include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> nums;
    // nums[0] = 4;
    // nums[1] = 8;
    nums.push_back(5);
    nums.push_back(3);
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " | ";
    }
    nums.pop_back();
    cout << "\n";
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " | ";
    }
    vector<int>::iterator it;
    nums.push_back(6);
    nums.push_back(1);
    cout << "\n";
    for (it = nums.begin(); it != nums.end(); it++)
    {
        cout << *it << " | ";
    }

    // for (auto ar : nums)
    // {
    //     cout << "[";
    //     for (auto it : ar)
    //         cout << it << " ";
    //     cout << "]\n";
    // }
    return 0;
}