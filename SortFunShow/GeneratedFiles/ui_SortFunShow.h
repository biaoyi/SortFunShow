/********************************************************************************
** Form generated from reading UI file 'SortFunShow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SORTFUNSHOW_H
#define UI_SORTFUNSHOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SortFunShowClass
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *lb_curSort;
    QLabel *lb_curStep;
    QPushButton *btn_start;
    QPushButton *btn_stop;
    QLabel *lb_show;
    QComboBox *comboBox;

    void setupUi(QWidget *SortFunShowClass)
    {
        if (SortFunShowClass->objectName().isEmpty())
            SortFunShowClass->setObjectName(QStringLiteral("SortFunShowClass"));
        SortFunShowClass->resize(634, 409);
        label = new QLabel(SortFunShowClass);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 22, 41, 20));
        label_2 = new QLabel(SortFunShowClass);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 50, 41, 21));
        lb_curSort = new QLabel(SortFunShowClass);
        lb_curSort->setObjectName(QStringLiteral("lb_curSort"));
        lb_curSort->setGeometry(QRect(60, 22, 281, 20));
        lb_curStep = new QLabel(SortFunShowClass);
        lb_curStep->setObjectName(QStringLiteral("lb_curStep"));
        lb_curStep->setGeometry(QRect(60, 50, 54, 21));
        btn_start = new QPushButton(SortFunShowClass);
        btn_start->setObjectName(QStringLiteral("btn_start"));
        btn_start->setGeometry(QRect(500, 10, 121, 71));
        btn_stop = new QPushButton(SortFunShowClass);
        btn_stop->setObjectName(QStringLiteral("btn_stop"));
        btn_stop->setGeometry(QRect(370, 10, 121, 71));
        lb_show = new QLabel(SortFunShowClass);
        lb_show->setObjectName(QStringLiteral("lb_show"));
        lb_show->setGeometry(QRect(10, 100, 600, 300));
        comboBox = new QComboBox(SortFunShowClass);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(220, 50, 131, 22));

        retranslateUi(SortFunShowClass);

        QMetaObject::connectSlotsByName(SortFunShowClass);
    } // setupUi

    void retranslateUi(QWidget *SortFunShowClass)
    {
        SortFunShowClass->setWindowTitle(QApplication::translate("SortFunShowClass", "SortFunShow", 0));
        label->setText(QApplication::translate("SortFunShowClass", "CurSF", 0));
        label_2->setText(QApplication::translate("SortFunShowClass", "CurSP", 0));
        lb_curSort->setText(QApplication::translate("SortFunShowClass", "TextLabel", 0));
        lb_curStep->setText(QApplication::translate("SortFunShowClass", "TextLabel", 0));
        btn_start->setText(QApplication::translate("SortFunShowClass", "Start", 0));
        btn_stop->setText(QApplication::translate("SortFunShowClass", "Stop", 0));
        lb_show->setText(QApplication::translate("SortFunShowClass", "TextLabel", 0));
    } // retranslateUi

};

namespace Ui {
    class SortFunShowClass: public Ui_SortFunShowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SORTFUNSHOW_H
