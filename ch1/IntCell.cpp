/**
* @file IntCell.cpp
* @brief 
* @author Kinvy
* @email Kinvy66@163.com
* @date 2023-11-28
*/

#include <iostream>

class IntCell {
public:
    /**
     * @brief 构造
     */
    explicit IntCell(int val = 0): m_int{val} { }

    /**
     * @brief 读操作
     * @return
     */
    int read() const {
        return m_int;
    }

    /**
     * @brief 写操作
     * @param val
     */
    void write(int val) {
        m_int = val;
    }

private:
    int m_int;
};


int main(int argc, char** argv) {

    IntCell intCell(8);
    std::cout << "intCell before: " << intCell.read() << std::endl;
    intCell.write(42);
    std::cout << "intCell after: " <<intCell.read() << std::endl;


    // use point
    IntCell *intCellPtr;
    intCellPtr = new IntCell(10);
    std::cout << "intCellPtr before: " << intCellPtr->read() << std::endl;
    intCellPtr->write(42);
    std::cout << "intCellPtr after: " <<intCellPtr->read() << std::endl;

    return 0;
}