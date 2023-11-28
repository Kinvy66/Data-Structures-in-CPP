/**
* @file matrix.cpp
* @brief 
* @author Kinvy
* @email Kinvy66@163.com
* @date 2023-11-28
*/
#include <iostream>
#include <vector>

template<typename T>
class Matrix {
public:
    Matrix(int rows, int cols) : m_mat(rows) {
        for (auto& c : m_mat) {
            c.resize(cols);
        }
    }

    Matrix(std::vector<std::vector<T>> v) : m_mat(v) { }

    Matrix(std::vector<std::vector<T>>&& v) : m_mat(std::move(v)) { }

    const std::vector<T>& operator[](int row) {
        return m_mat[row];
    }

    std::vector<T>& operator[](int row) const{
        return m_mat[row];
    }

    int numrows() const {
        return m_mat.size();
    }

    int numcols() const {
        return numrows() ? m_mat[0].size() : 0;
    }

private:
    std::vector<std::vector<T>> m_mat;
};

int main(int argc, char** argv) {

    return 0;
}