#ifndef STORAGE_H
#define STORAGE_H
#pragma once
#include "CShape.h"
#include <vector>

class Storage {
private:
    std::vector<CShape*> shapes;

public:
    ~Storage();

    Storage() = default;

    Storage(const Storage&) = delete;
    Storage& operator=(const Storage&) = delete;

    void add(CShape* shape);
    CShape* get(int index);
    void removeSelected();
    int size();
};

#endif // STORAGE_H
