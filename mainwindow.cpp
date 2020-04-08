#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pix(":/resource/img/suck.jpg");
    pic_label = new QLabel(this);
    text_label = new QLabel(this);
    btn = new QPushButton(this);
    input = new QLineEdit(this);

    btn->setGeometry(50, 40, 80, 25);
    input->setGeometry(180, 40, 575, 25);
    pic_label->setGeometry(50, 80, 705,500);
    text_label->setGeometry(100, 230, 325, 100);

    btn->setText("Enter");
    pic_label->setPixmap(pix.scaled(pic_label->width(), pic_label->height(), Qt::KeepAspectRatio));
    text_label->setText("我就爛");
    text_label->setFont(QFont("微軟正黑體", 35, QFont::Bold));

    connect(btn, SIGNAL(clicked(bool)), this, SLOT(buttonClick()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::buttonClick()
{
    text_label->setText(input->text());
}
