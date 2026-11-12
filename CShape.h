#pragma once
#ifndef CSHAPE_H
#define CSHAPE_H
#include <QPainter>
#include <QPoint>

class CShape {
private:
    bool selected = false;
public:
    virtual void draw(QPainter& painter) = 0;
    virtual bool contains(QPoint point) = 0;
    void setSelected(bool value) {selected = value;}
    bool isSelected() const {return selected;}
    virtual ~CShape() = default;
};

class CCircle: public CShape{
private:
    QPoint center;
    int radius = 30;
    bool selected = false;

public:
    CCircle(int x, int y);

    void draw(QPainter& painter) override;
    bool contains(QPoint point) override;
};

class CSquare : public CShape {
private:
    QPoint center;
    int size = 60;

public:
    CSquare(int x, int y);

    void draw(QPainter& painter) override;
    bool contains(QPoint point) override;
};

class CLine : public CShape{
private:
    QPoint start;
    QPoint end;
public:
    CLine(QPoint start, QPoint end);

    void draw(QPainter& painter) override;
    bool contains(QPoint point) override;
};

#endif // CSHAPE_H
