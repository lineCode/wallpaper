#ifndef DETECTFRAME_H
#define DETECTFRAME_H

#include <QMainWindow>

namespace Ui {
class DetectFrame;
}

class DetectFrame : public QMainWindow
{
    Q_OBJECT

public:
    explicit DetectFrame(QWidget *parent = 0);
    ~DetectFrame();

private:
    Ui::DetectFrame *ui;
};

#endif // DETECTFRAME_H
