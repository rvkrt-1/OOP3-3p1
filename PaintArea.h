#pragma once
#ifndef PAINTAREA_H
#define PAINTAREA_H
#include <QWidget>
#include <QMouseEvent>
#include <QKeyEvent>
#include <QPainter>
#include "Storage.h"

class PaintArea : public QWidget {
    Q_OBJECT

private:
    Storage storage;
    int currentTool = 0;

    QPoint lineStart;
    QPoint lineEnd;
    bool drawingLine = false;

protected:
    void paintEvent(QPaintEvent* event) override;
    void mousePressEvent(QMouseEvent* event) override;
    void mouseMoveEvent(QMouseEvent* event) override;
    void mouseReleaseEvent(QMouseEvent* event) override;
    void keyPressEvent(QKeyEvent* event) override;

public:
    explicit PaintArea(QWidget* parent = nullptr);

    void setTool(int tool);
};

#endif // PAINTAREA_H
