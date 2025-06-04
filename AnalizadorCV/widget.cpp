#include "widget.h"
#include "ui_widget.h"
#include <QPainter>
#include <QImage>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setWindowTitle("CVscanner");

    this->setFixedSize(600,300);

    // Cargar la imagen de fondo desde recursos .qrc
    fondo.load(":/background.jpg");

    // Si querés cargar desde archivo directo, usá esta línea en lugar de la de arriba:
    // fondo.load("background.jpg");
}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

    if (!fondo.isNull()) {
        painter.drawImage(rect(), fondo);  // Escala la imagen al tamaño del widget
    }

    QWidget::paintEvent(event);  // Llama al paint original para dibujar demás elementos
}
