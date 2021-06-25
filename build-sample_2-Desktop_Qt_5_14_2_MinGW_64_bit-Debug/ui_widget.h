/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QLabel *label;
    QPushButton *pushButton;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(400, 300);
        QFont font;
        font.setPointSize(18);
        Widget->setFont(font);
        label = new QLabel(Widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(160, 330, 421, 111));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Segoe Script"));
        font1.setPointSize(40);
        font1.setBold(false);
        font1.setItalic(false);
        font1.setUnderline(true);
        font1.setWeight(50);
        font1.setStrikeOut(false);
        font1.setKerning(true);
        label->setFont(font1);
        label->setCursor(QCursor(Qt::IBeamCursor));
        label->setMouseTracking(false);
        label->setAlignment(Qt::AlignCenter);
        label->setWordWrap(true);
        label->setTextInteractionFlags(Qt::LinksAccessibleByMouse);
        pushButton = new QPushButton(Widget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(330, 520, 93, 28));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Monotype Corsiva"));
        font2.setPointSize(18);
        font2.setItalic(true);
        pushButton->setFont(font2);
        pushButton->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton->setIconSize(QSize(20, 20));
        pushButton->setAutoDefault(false);
        pushButton->setFlat(false);

        retranslateUi(Widget);
        QObject::connect(pushButton, SIGNAL(clicked()), Widget, SLOT(close()));

        pushButton->setDefault(false);


        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "sample_2", nullptr));
        label->setText(QCoreApplication::translate("Widget", "hello World", nullptr));
        pushButton->setText(QCoreApplication::translate("Widget", "close", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
