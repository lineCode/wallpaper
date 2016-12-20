#ifndef CONFIG_H
#define CONFIG_H

#include <QMainWindow>

namespace Ui {
class Config;
}

class Config : public QMainWindow
{
    Q_OBJECT

public:
    explicit Config(QWidget *parent = 0);
    ~Config();

private:
    Ui::Config *ui;
};

#endif // CONFIG_H
