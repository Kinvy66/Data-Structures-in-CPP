/**
* @file maxSubSum.cpp
* @brief 
* @author Kinvy
* @email Kinvy66@163.com
* @date 2023-11-29
*/
#include <iostream>
#include <vector>
#include <random>

std::vector<int> generateRandomArray(size_t size, int min, int max) {
    std::random_device rd; // 用于获取随机种子
    std::mt19937 gen(rd()); // Mersenne Twister 生成器
    std::uniform_int_distribution<int> dis(min, max); // 均匀分布

    std::vector<int> randomArray;
    randomArray.reserve(size); // 预先分配空间以提高性能

    for (size_t i = 0; i < size; ++i) {
        randomArray.push_back(dis(gen)); // 生成随机数并添加到数组中
    }

    return randomArray;
}

/**
 * @brief 双层循环暴力 O(n^2)
 * @param a
 * @return
 */
int maxSubSum1(const std::vector<int>& a) {
    int maxSum = 0;
    for (int i = 0; i < a.size(); ++i) {
        int thisSum = 0;
        for (int j = i; j< a.size(); ++j) {
            thisSum += a[j];
            if (thisSum > maxSum) {
                maxSum = thisSum;
            }
        }
    }
    return maxSum;
}

/**
 * @brief 贪心算法
 * @param a
 * @return
 */
int maxSubSum2(const std::vector<int>& a) {
    int maxSum = 0;
    // TODO
    return maxSum;
}

/**
 * @brief 分治算法
 * @param a
 * @return
 */
int maxSubSum3(const std::vector<int>& a) {
    int maxSum = 0;
    // TODO
    return maxSum;
}

int main(int argc, char** argv) {
    size_t arraySize = 100000; // 数组大小
    int minVal = -1000; // 最小值
    int maxVal = 10000; // 最大值

    std::vector<int> randomNumbers = generateRandomArray(arraySize, minVal, maxVal);

    int result = maxSubSum1(randomNumbers);

    std::cout << "result=" << result << std::endl;

    // for (auto i : randomNumbers) {
    //     std::cout << i << " ";
    // }

    return 0;
}