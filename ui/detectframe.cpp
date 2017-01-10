#include "detectframe.h"
#include "ui_detectframe.h"

DetectFrame::DetectFrame(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DetectFrame)
{
    ui->setupUi(this);
}

DetectFrame::~DetectFrame()
{
    delete ui;
}
