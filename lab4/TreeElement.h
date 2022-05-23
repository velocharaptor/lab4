#pragma once


template <class T> class TreeElement {
public:
    T data;
    TreeElement* left;
    TreeElement* right;
    TreeElement(int val) {
        left = nullptr;
        right = nullptr;
        data = val;
    }
};