#include <iostream>   // cout
#include <algorithm>  // copy, fill

#include "tasks.hpp"

// ИСПОЛЬЗОВАНИЕ ЛЮБЫХ ДРУГИХ БИБЛИОТЕК НЕ СОВЕТУЕТСЯ И МОЖЕТ ПОВЛИЯТЬ НА ВАШИ БАЛЛЫ

using std::cout;
using std::fill;
using std::copy;

// Задание 1
void swap_args(int *lhs, int *rhs) {
    if (!lhs | !rhs)
    {
        return;
    }

    int abv = *lhs;
    *lhs = *rhs;
    *rhs = abv;
}

// Задание 2
int **allocate_2d_array(int num_rows, int num_cols, int init_value) {
    if (num_cols <= 0 || num_rows <= 0){
        return nullptr;
    }
    int** arr = new int* [num_rows];
    for (int i = 0; i < num_rows; i++){
        arr[i] = new int[num_cols];
    }
    for (int i = 0; i < num_rows; i++) {
        for (int j = 0; j < num_cols; j++) {
            arr[i][j] = init_value;
        }
    }
    return arr;
}

// Задание 3
bool copy_2d_array(int **arr_2d_source, int **arr_2d_target, int num_rows, int num_cols) {
    if (arr_2d_source && arr_2d_target && num_cols > 0 && num_rows > 0){
        for (int i = 0; i < num_rows; i++) {
            for (int j = 0; j < num_cols; j++) {
                arr_2d_target[i][j] = arr_2d_source[i][j];
            }
        }
        return true;
    }
    return false;
}

// Задание 4
void reverse_1d_array(vector<int> &arr) {
    for (int i = 0; i < arr.size()/2; i++)
    {
        int a = arr[i];
        arr[i] = arr[arr.size() - 1 - i];
        arr[arr.size() - 1- i] = a;
    }
}

// Задание 5
void reverse_1d_array(int *arr_begin, int *arr_end) {
    if (arr_begin && arr_end){
        while (arr_end > arr_begin) {
            swap_args(arr_begin, arr_end);
            arr_begin++;
            arr_end--;
        }
    }
}

// Задание 6
int *find_max_element(int *arr, int size) {
    if (arr && size > 0) {
        int* max = arr;
        for (int i = 0; i < size; i++) {
            if (*arr > *max) {
                max = arr;
            }
            arr += 1;
        }
        return max;
    }
    return nullptr;
}

// Задание 7
vector<int> find_odd_numbers(vector<int> &arr) {
    vector<int> abv = {};
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] % 2 != 0)
        {
            abv.emplace_back(arr[i]);
        }
    }
    return abv;
}

// Задание 8
vector<int> find_common_elements(vector<int> &arr_a, vector<int> &arr_b) {
    vector<int> abv = {};
    for (int i = 0; i < arr_a.size(); i++){
        for (int j = 0; j < arr_b.size(); j++) {
            if (arr_a[i] == arr_b[j])
            {
                abv.emplace_back(arr_a[i]);
            }
        }
    }
    return abv;
}
