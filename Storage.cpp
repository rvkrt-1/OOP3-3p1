
#include "Storage.h"

Storage::~Storage() {
    for (CShape* shape : shapes) {
        delete shape;
    }
}

void Storage::add(CShape* shape) {
    if (shape != nullptr) {
        shapes.push_back(shape);
    }
}

CShape* Storage::get(int index) {
    if (index >= 0 && index < shapes.size()) {
        return shapes[index];
    }

    return nullptr;
}

void Storage::removeSelected() {
    for (int i = 0; i < shapes.size();) {
        if (shapes[i]->isSelected()) {
            delete shapes[i];
            shapes.erase(shapes.begin() + i);
        }
        else {
            i++;
        }
    }
}

int Storage::size() {
    return shapes.size();
}
