/**
* @file IntCellPtr.cpp
* @brief Big-Five
* @author Kinvy
* @email Kinvy66@163.com
* @date 2023-11-28
*/
#include <iostream>

class IntCellPtr {
public:
    /**
     * @brief 有参构造
     * @param val
     */
    IntCellPtr(int val = 0): m_int(new int(val)) {
        std::cout << " constructor " << std::endl;
    }

    /**
     * @brief 拷贝构造
     * @param rhs
     */
    IntCellPtr(const IntCellPtr& rhs) {
        std::cout << " copy constructor " << std::endl;
        m_int = new int(*(rhs.m_int));
    }

    /**
     * @brief 移动构造
     * @param rhs
     */
    IntCellPtr(IntCellPtr&& rhs) {
        std::cout << " move constructor " << std::endl;
        int* temp = m_int;
        m_int = rhs.m_int;
        delete temp;
        temp = nullptr;
    }

    /**
     * @brief 拷贝赋值
     * @param rhs
     * @return
     */
    IntCellPtr& operator=(const IntCellPtr& rhs) {
        std::cout << " copy assignment " << std::endl;
        if (this != &rhs) {  // 自身赋值不做处理
            *this->m_int = *rhs.m_int;
        }
        return *this;
    }

    /**
     * @brief 移动赋值
     * @param rhs
     * @return
     */
    IntCellPtr& operator=(IntCellPtr&& rhs) {
        std::cout << " move assignment " << std::endl;
        int* temp = m_int;
        m_int = rhs.m_int;
        delete temp;
        temp = nullptr;
    }

    ~IntCellPtr() {
        std::cout << " destructor " << std::endl;
        delete m_int;
        m_int = nullptr;
    }

    int read() const {
        return *m_int;
    }

    void write(int val) {
        *m_int = val;
    }


private:
    int* m_int;
};

int main(int argc, char** argv) {

    IntCellPtr a { 2 };
    IntCellPtr b = a;
    IntCellPtr c;

    c = b;
    a.write(4);
    std::cout << a.read() << std::endl
        << b.read() << std::endl
        << c.read() << std::endl;

    return 0;
}
