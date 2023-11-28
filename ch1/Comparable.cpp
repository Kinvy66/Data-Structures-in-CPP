/**
* @file Comparable.cpp
* @brief 
* @author Kinvy
* @email Kinvy66@163.com
* @date 2023-11-28
*/
#include <iostream>
#include <vector>
#include <algorithm>

class Square {
public:
    explicit Square(double val = 0.0) : m_side(val) {}

    double getSide() const {
        return m_side;
    }

    double getArea() const {
        return m_side * m_side;
    }

    double getPerimeter() const {
        return 4 * m_side;
    }

    bool operator<(const Square& rhs) const {
        return getSide() < rhs.getSide();
    }

    void print(std::ostream& out = std::cout) const {
        out << "(square " << getSide( ) << ")";
    }

private:
    double m_side;
};

std::ostream& operator<<(std::ostream& out, const Square& rhs) {
    rhs.print(out);
    return out;
}

template<typename T>
const T& findMax(const std::vector<T>& vec) {
    int max = 0;
    for (int i = 0; i < vec.size(); ++i) {
        if (vec[max] < vec[i]) {
            max = i;
        }
    }
    return vec[max];
}

/**
 * @brief 自定义方式
 * @tparam T
 * @tparam Comparator
 * @param vec
 * @param isLessThan
 * @return
 */
template<typename T, typename Comparator>
const T& findMax(const std::vector<T>& vec, Comparator isLessThan) {
    int max = 0;
    for (int i = 0; i < vec.size(); ++i) {
        if (isLessThan(vec[max], vec[i])) {
            max = i;
        }
    }
    return vec[max];
}


int main(int argc, char** argv) {

    std::vector<Square> v = { Square{ 3.0 }, Square{ 2.0 }, Square{ 2.5 } };

    std::cout << "Largest square: " << findMax(v) << std::endl;

    std::cout << "Smallest square: "
    << findMax(v,
        [](const Square& a, const Square b){
                    return  a.getSide() > b.getSide();})
                    << std::endl;
    return 0;
}