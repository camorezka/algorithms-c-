#pragma once
#include <iostream>

using namespace std;

void allocate(float*& p, int s) {
    p = new float[s];
}

void set(float* p, int s) {
    for (int i = 0; i < s; i++) {
        p[i] = rand() % 20 - 10;
    }
}

void print(float* p, int s) {
    for (int i = 0; i < s; i++) {
        cout << p[i] << " ";
    }
    cout << endl;
}

void del(float* p) {
    delete[] p;
}

void addEnd(float*& p, int* s, float v) {
    float* t = new float[*s + 1];
    for (int i = 0; i < *s; i++) {
        t[i] = p[i];
    }
    t[*s] = v;
    delete[] p;
    p = t;
    (*s)++;
}

void insert(float*& p, int* s, float v, int idx) {
    float* t = new float[*s + 1];
    for (int i = 0; i < idx; i++) {
        t[i] = p[i];
    }
    t[idx] = v;
    for (int i = idx; i < *s; i++) {
        t[i + 1] = p[i];
    }
    delete[] p;
    p = t;
    (*s)++;
}

void delIdx(float*& p, int* s, int idx) {
    float* t = new float[*s - 1];
    int j = 0;
    for (int i = 0; i < *s; i++) {
        if (i != idx) {
            t[j] = p[i];
            j++;
        }
    }
    delete[] p;
    p = t;
    (*s)--;
}
