/********************************************************************************
** Form generated from reading UI file 'gkrellm.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GKRELLM_H
#define UI_GKRELLM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GKrellM
{
public:
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *GKrellM)
    {
        if (GKrellM->objectName().isEmpty())
            GKrellM->setObjectName(QStringLiteral("GKrellM"));
        GKrellM->resize(1280, 800);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(GKrellM->sizePolicy().hasHeightForWidth());
        GKrellM->setSizePolicy(sizePolicy);
        GKrellM->setMinimumSize(QSize(1280, 800));
        GKrellM->setMaximumSize(QSize(1280, 800));
        centralWidget = new QWidget(GKrellM);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        GKrellM->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(GKrellM);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1280, 22));
        GKrellM->setMenuBar(menuBar);
        mainToolBar = new QToolBar(GKrellM);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        GKrellM->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(GKrellM);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        GKrellM->setStatusBar(statusBar);

        retranslateUi(GKrellM);

        QMetaObject::connectSlotsByName(GKrellM);
    } // setupUi

    void retranslateUi(QMainWindow *GKrellM)
    {
        GKrellM->setWindowTitle(QApplication::translate("GKrellM", "GKrellM", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class GKrellM: public Ui_GKrellM {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GKRELLM_H
