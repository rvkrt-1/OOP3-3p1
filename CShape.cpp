#include "CShape.h"
#include <cmath>
#include <algorithm>

CCircle::CCircle(int x, int y) {
    center = QPoint(x, y);
}

void CCircle::draw(QPainter& painter) {
    painter.setPen(isSelected() ? QPen(Qt::red, 3) : QPen(Qt::black, 1));

    painter.drawEllipse(
        center.x() - radius,
        center.y() - radius,
        radius * 2,
        radius * 2);
}

bool CCircle::contains(QPoint point) {
    int dx = point.x() - center.x();
    int dy = point.y() - center.y();

    return dx * dx + dy * dy <= radius * radius;
}

CSquare::CSquare(int x, int y){
    center = QPoint(x,y);
}

void CSquare::draw(QPainter& painter){
    painter.setPen(isSelected() ? QPen(Qt::red, 3) : QPen(Qt::black, 1));

    painter.drawRect(
        center.x() - size / 2,
        center.y() - size / 2,
        size,
        size);
}

bool CSquare::contains(QPoint point) {
    int left = center.x() - size / 2;
    int right = center.x() + size / 2;
    int top = center.y() - size / 2;
    int bottom = center.y() + size / 2;

    return point.x() >= left &&
           point.x() <= right &&
           point.y() >= top &&
           point.y() <= bottom;
}

CLine::CLine(QPoint start, QPoint end){
    this->start = start;
    this->end = end;
}

void CLine::draw(QPainter &painter){
    painter.setPen(isSelected() ? QPen(Qt::red, 3) : QPen(Qt::black, 1));
    painter.drawLine(start,end);
}

bool CLine::contains(QPoint point) {
    double dx = end.x() - start.x();
    double dy = end.y() - start.y();

    double lengthSquared = dx * dx + dy * dy;

    if (lengthSquared == 0) {
        return false;
    }

    double t = ((point.x() - start.x()) * dx +
                (point.y() - start.y()) * dy) / lengthSquared;

    t = std::max(0.0, std::min(1.0, t));

    double closestX = start.x() + t * dx;
    double closestY = start.y() + t * dy;

    double distanceX = point.x() - closestX;
    double distanceY = point.y() - closestY;

    return distanceX * distanceX +
               distanceY * distanceY <= 25;


}
