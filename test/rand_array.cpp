/**
* @file rand_array.cpp
* @brief 
* @author Kinvy
* @email Kinvy66@163.com
* @date 2023-11-29
*/

#include <iostream>
#include <vector>
#include <random>

// 生成随机整数数组的函数
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

int main() {
    size_t arraySize = 10; // 数组大小
    int minVal = -100; // 最小值
    int maxVal = 100; // 最大值

    std::vector<int> randomNumbers = generateRandomArray(arraySize, minVal, maxVal);

    // 打印生成的随机数组
    std::cout << "Generated Random Array:\n";
    for (size_t i = 0; i < arraySize; ++i) {
        std::cout << randomNumbers[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}

