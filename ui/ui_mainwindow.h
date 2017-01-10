/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionImageFolder;
    QAction *actionhomepage;
    QAction *actionabout;
    QAction *actionDuplicateRemoval;
    QAction *actionautoWallpaper;
    QWidget *centralWidget;
    QLabel *label;
    QLabel *labelPath;
    QGraphicsView *graphicsView;
    QLabel *label_3;
    QTextBrowser *textBrowser;
    QMenuBar *menuBar;
    QMenu *menuConfig;
    QMenu *menuProcess;
    QMenu *menuAbout;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(731, 425);
        actionImageFolder = new QAction(MainWindow);
        actionImageFolder->setObjectName(QStringLiteral("actionImageFolder"));
        actionhomepage = new QAction(MainWindow);
        actionhomepage->setObjectName(QStringLiteral("actionhomepage"));
        actionabout = new QAction(MainWindow);
        actionabout->setObjectName(QStringLiteral("actionabout"));
        actionDuplicateRemoval = new QAction(MainWindow);
        actionDuplicateRemoval->setObjectName(QStringLiteral("actionDuplicateRemoval"));
        actionautoWallpaper = new QAction(MainWindow);
        actionautoWallpaper->setObjectName(QStringLiteral("actionautoWallpaper"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 10, 54, 12));
        labelPath = new QLabel(centralWidget);
        labelPath->setObjectName(QStringLiteral("labelPath"));
        labelPath->setGeometry(QRect(70, 10, 381, 10));
        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(10, 40, 521, 311));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(550, 20, 54, 12));
        textBrowser = new QTextBrowser(centralWidget);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(550, 40, 171, 311));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 731, 23));
        menuConfig = new QMenu(menuBar);
        menuConfig->setObjectName(QStringLiteral("menuConfig"));
        menuProcess = new QMenu(menuBar);
        menuProcess->setObjectName(QStringLiteral("menuProcess"));
        menuAbout = new QMenu(menuBar);
        menuAbout->setObjectName(QStringLiteral("menuAbout"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuConfig->menuAction());
        menuBar->addAction(menuProcess->menuAction());
        menuBar->addAction(menuAbout->menuAction());
        menuConfig->addAction(actionImageFolder);
        menuProcess->addAction(actionDuplicateRemoval);
        menuProcess->addSeparator();
        menuProcess->addAction(actionautoWallpaper);
        menuAbout->addAction(actionhomepage);
        menuAbout->addSeparator();
        menuAbout->addAction(actionabout);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        actionImageFolder->setText(QApplication::translate("MainWindow", "\345\233\276\347\211\207\346\220\234\347\264\242\350\267\257\345\276\204", Q_NULLPTR));
        actionhomepage->setText(QApplication::translate("MainWindow", "\345\270\256\345\212\251", Q_NULLPTR));
        actionabout->setText(QApplication::translate("MainWindow", "\345\205\263\344\272\216", Q_NULLPTR));
        actionDuplicateRemoval->setText(QApplication::translate("MainWindow", "\345\216\273\351\207\215", Q_NULLPTR));
        actionautoWallpaper->setText(QApplication::translate("MainWindow", "\350\207\252\345\212\250\350\256\276\347\275\256\346\241\214\351\235\242", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "\345\233\276\345\203\217\350\267\257\345\276\204\357\274\232", Q_NULLPTR));
        labelPath->setText(QApplication::translate("MainWindow", "\345\233\276\347\211\207\350\267\257\345\276\204", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "\345\233\276\345\203\217\344\277\241\346\201\257\357\274\232", Q_NULLPTR));
        menuConfig->setTitle(QApplication::translate("MainWindow", "\351\205\215\347\275\256", Q_NULLPTR));
        menuProcess->setTitle(QApplication::translate("MainWindow", "\345\233\276\345\203\217\345\244\204\347\220\206", Q_NULLPTR));
        menuAbout->setTitle(QApplication::translate("MainWindow", "\345\270\256\345\212\251", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
