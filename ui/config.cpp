#include "config.h"
#include "ui_config.h"

Config::Config(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Config)
{
    ui->setupUi(this);
}

Config::~Config()
{
    delete ui;
}
