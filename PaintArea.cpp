#include "PaintArea.h"

PaintArea::PaintArea(QWidget* parent)
    : QWidget(parent)
{
    setMinimumSize(400, 300);
    setFocusPolicy(Qt::StrongFocus);
    setMouseTracking(true);
    setStyleSheet("background-color: white;");
}

void PaintArea::setTool(int tool) {
    currentTool = tool;
}

void PaintArea::paintEvent(QPaintEvent* event) {
    Q_UNUSED(event);

    QPainter painter(this);

    for (int i = 0; i < storage.size(); i++) {
        storage.get(i)->draw(painter);
    }

    // Отображение линии во время рисования
    if (drawingLine) {
        painter.drawLine(lineStart, lineEnd);
    }
}

void PaintArea::mousePressEvent(QMouseEvent* event) {
    if (event->button() != Qt::LeftButton) {
        return;
    }

    setFocus();

    QPoint point = event->pos();

    // Режим выделения
    if (currentTool == 3) {
        bool ctrl = event->modifiers() & Qt::ControlModifier;

        // Если Ctrl не зажат, снимаем старое выделение
        if (!ctrl) {
            for (int i = 0; i < storage.size(); i++) {
                storage.get(i)->setSelected(false);
            }
        }

        // Ищем фигуру под курсором (сверху вниз)
        for (int i = storage.size() - 1; i >= 0; i--) {
            CShape* shape = storage.get(i);

            if (shape->contains(point)) {
                shape->setSelected(ctrl ? !shape->isSelected() : true);
                break;
            }
        }

        update();
        return;
    }

    if (currentTool == 0) {
        storage.add(new CCircle(point.x(), point.y()));
    }
    else if (currentTool == 1) {
        storage.add(new CSquare(point.x(), point.y()));
    }
    else if (currentTool == 2) {
        lineStart = point;
        lineEnd = point;
        drawingLine = true;
    }

    update();
}

void PaintArea::mouseMoveEvent(QMouseEvent* event) {
    if (drawingLine) {
        lineEnd = event->pos();
        update();
    }
}

void PaintArea::mouseReleaseEvent(QMouseEvent* event) {
    if (event->button() == Qt::LeftButton && drawingLine) {
        lineEnd = event->pos();
        storage.add(new CLine(lineStart, lineEnd));
        drawingLine = false;
        update();
    }
}

void PaintArea::keyPressEvent(QKeyEvent* event) {
    if (event->key() == Qt::Key_Delete) {
        storage.removeSelected();
        update();
    }
}
