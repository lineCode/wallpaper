#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
	
	// ÏÔÊ¾Í¼Æ¬
	QGraphicsScene *scene = new QGraphicsScene(this);
	ui->graphicsView->setScene(scene);
	QPixmap *pic = new QPixmap(".\\1.png");
	
	scene->addPixmap(*pic);
	ui->graphicsView->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}
