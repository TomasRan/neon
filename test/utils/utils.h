/*******************************
    @author: taotianran
    @contact: tomasran@163.com
    @date: 2023/09/06 20:03
 ********************************/

#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include <arm_neon.h>

#include "gtest/gtest.h"

template<class T>
std::shared_ptr<T> mock_data(int size, T start = 0, T step = 1) {
    std::shared_ptr<T> data(new T[size], std::default_delete<T[]>());
    T* ptr = data.get();

    for (int i = 0; i < size; ++i) {
        ptr[i] = start;
        start += step;
    }

    return data;
}

template<class T>
std::string vec_to_string(int size, T* data, std::string prefix = "") {
    std::string res = prefix;

    for (int i = 0; i < size; ++i) {
        res += std::to_string((*data)[i]) + " ";
    }

    return res;
}

template<class A, class B, class C>
void print3(
        int op1_size,
        int op2_size,
        int res_size,
        A* op1,
        B* op2,
        C* res) {
    std::string op1_str = vec_to_string(op1_size, op1, "a: ");
    std::string op2_str = vec_to_string(op2_size, op2, "b: ");
    std::string res_str = vec_to_string(res_size, res, "r: ");

    std::cout << op1_str << std::endl;
    std::cout << op2_str << std::endl;
    std::cout << res_str << std::endl;
}

template<class A, class B, class C, class D>
void print4(
        int op1_size, 
        int op2_size,
        int op3_size,
        int res_size,
        A* op1,
        B* op2,
        C* op3,
        D* res) {
    std::string op1_str = vec_to_string(op1_size, op1, "a: ");
    std::string op2_str = vec_to_string(op2_size, op2, "b: ");
    std::string op3_str = vec_to_string(op3_size, op3, "c: ");
    std::string res_str = vec_to_string(res_size, res, "r: ");

    std::cout << op1_str << std::endl;
    std::cout << op2_str << std::endl;
    std::cout << op3_str << std::endl;
    std::cout << res_str << std::endl;
}

template<class T, class D>
void compare_eq(int size, std::vector<T>& gt, D data) {
    for (int i = 0; i < size; ++i)
    {
        ASSERT_EQ(gt[i], (T)data[i]);
    }
}

template<class T, class D>
void compare_near(int size, std::vector<T>& gt, D data, T precision) {
    for (int i = 0; i < size; ++i)
    {
        ASSERT_NEAR(gt[i], (T)data[i], precision);
    }
}