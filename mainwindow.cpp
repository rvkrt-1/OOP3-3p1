#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QVBoxLayout>
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    paintArea = new PaintArea(ui->drawingContainer);

    QVBoxLayout* layout = new QVBoxLayout(ui->drawingContainer);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->addWidget(paintArea);

    connect(ui->btnCircle, &QPushButton::clicked, this, [this]() {
        paintArea->setTool(0);
    });

    connect(ui->btnSquare, &QPushButton::clicked, this, [this]() {
        paintArea->setTool(1);
    });

    connect(ui->btnLine, &QPushButton::clicked, this, [this]() {
        paintArea->setTool(2);
    });
    connect(ui->btnSelect, &QPushButton::clicked, this, [this]() {
        paintArea->setTool(3);
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}
