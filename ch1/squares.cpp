/**
* @file squares.cpp
* @brief 
* @author Kinvy
* @email Kinvy66@163.com
* @date 2023-11-28
*/
#include <iostream>
#include <vector>

int main(int argc, char** argv) {
    std::vector<int> squares(100);

    for (int i = 0; i < squares.size(); ++i) {
        squares[i] = i * i;
    }

    for (int i = 0; i < squares.size(); ++i) {
        std::cout << i << " " << squares[i] << std::endl;
    }

    return 0;
}
