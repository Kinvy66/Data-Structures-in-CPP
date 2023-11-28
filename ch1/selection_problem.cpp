/**
* @file selection_problem.cpp
* @brief 
* @author Kinvy
* @email Kinvy66@163.com
* @date 2023-11-28
*/
#include <iostream>
#include <vector>
#include <time.h>
#include <stdlib.h>
#include <algorithm>

int select(std::vector<int>& arr, int k) {
    std::vector<int> vec(k);
    for (int i = 0; i < k; ++i) {
        vec[i] = arr[i];
    }
    std::sort(vec.begin(), vec.end());
    for (int i = k; i  < arr.size(); ++i) {
        if (arr[i] < vec[k - 1]) {  // 如果元素小于最后一个，将其放在适当的位置
            int val = arr[i];
            int j = k - 2;
            // 将元素逐个向后移动
            while (val < vec[j] && j >= 0) {
                vec[j+1] = vec[j];
                j--;
            }
            vec[j+1] = val;  // 正确的位置
        }
    }
    return vec[k - 1];
}

int main(int argc, char** argv) {
    srand(time(0));
    std::vector<int> arr;

    for (int i = 0; i < 100; ++i) {
        arr.push_back(1 + (rand() % 1000));
        // std::cout << arr[i] << " ";
    }

    int k = 20;
    int result = select(arr, k);
    std::sort(arr.begin(), arr.end());

    // for (auto i : arr) {
    //     std::cout <<  i << std::endl;
    // }

    std::cout << "result=" << result << " stl=" << arr[k-1] << std::endl;

    return 0;
}