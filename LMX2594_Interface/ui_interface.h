/********************************************************************************
** Form generated from reading UI file 'interface.ui'
**
** Created by: Qt User Interface Compiler version 6.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INTERFACE_H
#define UI_INTERFACE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Interface
{
public:
    QWidget *centralwidget;
    QTabWidget *tabWidget;
    QWidget *COM1;
    QWidget *tab_2;
    QWidget *tab;
    QWidget *tab_3;
    QWidget *tab_4;
    QWidget *tab_5;
    QWidget *tab_6;
    QWidget *tab_7;
    QWidget *tab_8;
    QWidget *tab_9;
    QWidget *tab_10;
    QWidget *tab_11;
    QWidget *widget;
    QFrame *line_9;
    QFrame *line_18;
    QFrame *line_8;
    QFrame *line;
    QFrame *line_20;
    QLabel *label_2;
    QPushButton *reset;
    QPushButton *solve;
    QFrame *line_7;
    QLabel *label_4;
    QFrame *line_16;
    QLabel *labelFosc_1;
    QFrame *frame;
    QLabel *lableFosc_1_SI;
    QFrame *line_19;
    QFrame *line_12;
    QFrame *line_10;
    QFrame *frameLMX2594_1;
    QLineEdit *PFD_1;
    QLineEdit *CD1;
    QFrame *line_2;
    QFrame *line_5;
    QLabel *label;
    QLineEdit *frame_2;
    QFrame *line_22;
    QLineEdit *NDN1;
    QLineEdit *NDNUM1;
    QLineEdit *NDDEN1;
    QFrame *line_4;
    QLabel *label_6;
    QFrame *frameLMX2594_2;
    QLineEdit *PFD_2;
    QLineEdit *CD2;
    QFrame *line_14;
    QFrame *line_15;
    QLabel *label_5;
    QSpinBox *NDN2;
    QLabel *lableFout_1_SI;
    QPushButton *lowEnergy;
    QFrame *line_13;
    QTextEdit *connection;
    QFrame *line_6;
    QLineEdit *Fosc_1;
    QLineEdit *Fout_2;
    QLineEdit *Fout_1;
    QFrame *line_3;
    QLabel *lableFout_1_SI_2;
    QFrame *line_17;
    QFrame *line_11;
    QFrame *line_21;
    QLineEdit *configutatingTime;
    QLabel *configuratingLable;
    QLabel *configuratingLable_2;
    QPushButton *inputs;
    QLabel *label_7;

    void setupUi(QMainWindow *Interface)
    {
        if (Interface->objectName().isEmpty())
            Interface->setObjectName(QString::fromUtf8("Interface"));
        Interface->resize(851, 482);
        Interface->setToolButtonStyle(Qt::ToolButtonFollowStyle);
        centralwidget = new QWidget(Interface);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(10, 0, 831, 31));
        tabWidget->setTabPosition(QTabWidget::South);
        tabWidget->setTabShape(QTabWidget::Rounded);
        tabWidget->setUsesScrollButtons(true);
        COM1 = new QWidget();
        COM1->setObjectName(QString::fromUtf8("COM1"));
        tabWidget->addTab(COM1, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        tabWidget->addTab(tab_2, QString());
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        tabWidget->addTab(tab, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QString::fromUtf8("tab_4"));
        tabWidget->addTab(tab_4, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QString::fromUtf8("tab_5"));
        tabWidget->addTab(tab_5, QString());
        tab_6 = new QWidget();
        tab_6->setObjectName(QString::fromUtf8("tab_6"));
        tabWidget->addTab(tab_6, QString());
        tab_7 = new QWidget();
        tab_7->setObjectName(QString::fromUtf8("tab_7"));
        tabWidget->addTab(tab_7, QString());
        tab_8 = new QWidget();
        tab_8->setObjectName(QString::fromUtf8("tab_8"));
        tabWidget->addTab(tab_8, QString());
        tab_9 = new QWidget();
        tab_9->setObjectName(QString::fromUtf8("tab_9"));
        tabWidget->addTab(tab_9, QString());
        tab_10 = new QWidget();
        tab_10->setObjectName(QString::fromUtf8("tab_10"));
        tabWidget->addTab(tab_10, QString());
        tab_11 = new QWidget();
        tab_11->setObjectName(QString::fromUtf8("tab_11"));
        tabWidget->addTab(tab_11, QString());
        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(10, 30, 831, 441));
        line_9 = new QFrame(widget);
        line_9->setObjectName(QString::fromUtf8("line_9"));
        line_9->setGeometry(QRect(170, 230, 481, 31));
        QFont font;
        font.setPointSize(9);
        font.setBold(true);
        line_9->setFont(font);
        line_9->setFrameShadow(QFrame::Plain);
        line_9->setFrameShape(QFrame::HLine);
        line_18 = new QFrame(widget);
        line_18->setObjectName(QString::fromUtf8("line_18"));
        line_18->setGeometry(QRect(0, 430, 831, 20));
        line_18->setFrameShadow(QFrame::Plain);
        line_18->setFrameShape(QFrame::HLine);
        line_8 = new QFrame(widget);
        line_8->setObjectName(QString::fromUtf8("line_8"));
        line_8->setGeometry(QRect(620, 121, 61, 125));
        line_8->setFont(font);
        line_8->setFrameShadow(QFrame::Plain);
        line_8->setFrameShape(QFrame::VLine);
        line = new QFrame(widget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(150, 90, 61, 31));
        line->setFont(font);
        line->setFrameShadow(QFrame::Plain);
        line->setFrameShape(QFrame::HLine);
        line_20 = new QFrame(widget);
        line_20->setObjectName(QString::fromUtf8("line_20"));
        line_20->setGeometry(QRect(-10, 0, 20, 440));
        line_20->setFrameShadow(QFrame::Plain);
        line_20->setFrameShape(QFrame::VLine);
        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(550, 70, 49, 16));
        label_2->setFont(font);
        label_2->setAlignment(Qt::AlignCenter);
        reset = new QPushButton(widget);
        reset->setObjectName(QString::fromUtf8("reset"));
        reset->setGeometry(QRect(100, 310, 80, 31));
        reset->setFont(font);
        reset->setCheckable(true);
        solve = new QPushButton(widget);
        solve->setObjectName(QString::fromUtf8("solve"));
        solve->setGeometry(QRect(680, 230, 141, 31));
        solve->setFont(font);
        solve->setCheckable(true);
        line_7 = new QFrame(widget);
        line_7->setObjectName(QString::fromUtf8("line_7"));
        line_7->setGeometry(QRect(460, 90, 41, 31));
        line_7->setFont(font);
        line_7->setFrameShadow(QFrame::Plain);
        line_7->setFrameShape(QFrame::HLine);
        label_4 = new QLabel(widget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(550, 260, 49, 16));
        label_4->setFont(font);
        label_4->setAlignment(Qt::AlignCenter);
        line_16 = new QFrame(widget);
        line_16->setObjectName(QString::fromUtf8("line_16"));
        line_16->setGeometry(QRect(170, 280, 41, 31));
        line_16->setFont(font);
        line_16->setFrameShadow(QFrame::Plain);
        line_16->setFrameShape(QFrame::HLine);
        labelFosc_1 = new QLabel(widget);
        labelFosc_1->setObjectName(QString::fromUtf8("labelFosc_1"));
        labelFosc_1->setGeometry(QRect(38, 70, 71, 20));
        labelFosc_1->setFont(font);
        labelFosc_1->setAlignment(Qt::AlignCenter);
        frame = new QFrame(widget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(90, 90, 61, 31));
        frame->setFont(font);
        frame->setAutoFillBackground(false);
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Plain);
        lableFosc_1_SI = new QLabel(frame);
        lableFosc_1_SI->setObjectName(QString::fromUtf8("lableFosc_1_SI"));
        lableFosc_1_SI->setGeometry(QRect(0, 0, 61, 31));
        lableFosc_1_SI->setFont(font);
        lableFosc_1_SI->setAlignment(Qt::AlignCenter);
        line_19 = new QFrame(widget);
        line_19->setObjectName(QString::fromUtf8("line_19"));
        line_19->setGeometry(QRect(0, -10, 830, 20));
        QFont font1;
        line_19->setFont(font1);
        line_19->setFrameShadow(QFrame::Plain);
        line_19->setFrameShape(QFrame::HLine);
        line_12 = new QFrame(widget);
        line_12->setObjectName(QString::fromUtf8("line_12"));
        line_12->setGeometry(QRect(390, 340, 41, 31));
        line_12->setFont(font);
        line_12->setFrameShadow(QFrame::Plain);
        line_12->setFrameShape(QFrame::HLine);
        line_10 = new QFrame(widget);
        line_10->setObjectName(QString::fromUtf8("line_10"));
        line_10->setGeometry(QRect(140, 246, 61, 50));
        line_10->setFont(font);
        line_10->setFrameShadow(QFrame::Plain);
        line_10->setFrameShape(QFrame::VLine);
        frameLMX2594_1 = new QFrame(widget);
        frameLMX2594_1->setObjectName(QString::fromUtf8("frameLMX2594_1"));
        frameLMX2594_1->setGeometry(QRect(190, 70, 301, 171));
        frameLMX2594_1->setFont(font);
        frameLMX2594_1->setFrameShape(QFrame::StyledPanel);
        frameLMX2594_1->setFrameShadow(QFrame::Plain);
        frameLMX2594_1->setLineWidth(2);
        PFD_1 = new QLineEdit(frameLMX2594_1);
        PFD_1->setObjectName(QString::fromUtf8("PFD_1"));
        PFD_1->setGeometry(QRect(20, 20, 61, 31));
        PFD_1->setFont(font);
        PFD_1->setAlignment(Qt::AlignCenter);
        PFD_1->setReadOnly(true);
        PFD_1->setClearButtonEnabled(false);
        CD1 = new QLineEdit(frameLMX2594_1);
        CD1->setObjectName(QString::fromUtf8("CD1"));
        CD1->setGeometry(QRect(210, 20, 61, 31));
        CD1->setFont(font);
        CD1->setAlignment(Qt::AlignCenter);
        CD1->setReadOnly(true);
        CD1->setClearButtonEnabled(false);
        line_2 = new QFrame(frameLMX2594_1);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setGeometry(QRect(20, 50, 61, 41));
        line_2->setFont(font);
        line_2->setFrameShadow(QFrame::Plain);
        line_2->setFrameShape(QFrame::VLine);
        line_5 = new QFrame(frameLMX2594_1);
        line_5->setObjectName(QString::fromUtf8("line_5"));
        line_5->setGeometry(QRect(210, 50, 61, 41));
        line_5->setFont(font);
        line_5->setFrameShadow(QFrame::Plain);
        line_5->setFrameShape(QFrame::VLine);
        label = new QLabel(frameLMX2594_1);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(210, 140, 91, 31));
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);
        frame_2 = new QLineEdit(frameLMX2594_1);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setGeometry(QRect(60, 70, 171, 41));
        frame_2->setFont(font);
        frame_2->setAlignment(Qt::AlignCenter);
        frame_2->setReadOnly(true);
        frame_2->setClearButtonEnabled(false);
        line_22 = new QFrame(frameLMX2594_1);
        line_22->setObjectName(QString::fromUtf8("line_22"));
        line_22->setGeometry(QRect(137, 81, 91, 20));
        line_22->setFont(font);
        line_22->setFrameShadow(QFrame::Plain);
        line_22->setLineWidth(2);
        line_22->setFrameShape(QFrame::HLine);
        NDN1 = new QLineEdit(frameLMX2594_1);
        NDN1->setObjectName(QString::fromUtf8("NDN1"));
        NDN1->setGeometry(QRect(61, 80, 68, 21));
        NDN1->setFrame(false);
        NDN1->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        NDN1->setReadOnly(true);
        NDNUM1 = new QLineEdit(frameLMX2594_1);
        NDNUM1->setObjectName(QString::fromUtf8("NDNUM1"));
        NDNUM1->setGeometry(QRect(129, 73, 101, 16));
        NDNUM1->setFrame(false);
        NDNUM1->setAlignment(Qt::AlignCenter);
        NDNUM1->setReadOnly(true);
        NDDEN1 = new QLineEdit(frameLMX2594_1);
        NDDEN1->setObjectName(QString::fromUtf8("NDDEN1"));
        NDDEN1->setGeometry(QRect(135, 92, 91, 16));
        NDDEN1->setFrame(false);
        NDDEN1->setAlignment(Qt::AlignCenter);
        NDDEN1->setReadOnly(true);
        line_4 = new QFrame(frameLMX2594_1);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setGeometry(QRect(230, 70, 10, 41));
        line_4->setFont(font);
        line_4->setFrameShadow(QFrame::Plain);
        line_4->setFrameShape(QFrame::HLine);
        label_6 = new QLabel(frameLMX2594_1);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(120, 78, 21, 21));
        label_6->setFont(font);
        label_6->setAlignment(Qt::AlignCenter);
        frame_2->raise();
        PFD_1->raise();
        CD1->raise();
        line_2->raise();
        line_5->raise();
        label->raise();
        line_22->raise();
        NDN1->raise();
        NDNUM1->raise();
        NDDEN1->raise();
        line_4->raise();
        label_6->raise();
        frameLMX2594_2 = new QFrame(widget);
        frameLMX2594_2->setObjectName(QString::fromUtf8("frameLMX2594_2"));
        frameLMX2594_2->setGeometry(QRect(190, 250, 301, 151));
        frameLMX2594_2->setFont(font);
        frameLMX2594_2->setFrameShape(QFrame::StyledPanel);
        frameLMX2594_2->setFrameShadow(QFrame::Plain);
        PFD_2 = new QLineEdit(frameLMX2594_2);
        PFD_2->setObjectName(QString::fromUtf8("PFD_2"));
        PFD_2->setGeometry(QRect(20, 30, 61, 31));
        PFD_2->setFont(font);
        PFD_2->setAlignment(Qt::AlignCenter);
        PFD_2->setReadOnly(true);
        PFD_2->setClearButtonEnabled(false);
        CD2 = new QLineEdit(frameLMX2594_2);
        CD2->setObjectName(QString::fromUtf8("CD2"));
        CD2->setGeometry(QRect(210, 30, 61, 31));
        CD2->setFont(font);
        CD2->setAlignment(Qt::AlignCenter);
        CD2->setReadOnly(true);
        CD2->setClearButtonEnabled(false);
        line_14 = new QFrame(frameLMX2594_2);
        line_14->setObjectName(QString::fromUtf8("line_14"));
        line_14->setGeometry(QRect(20, 60, 61, 45));
        line_14->setFont(font);
        line_14->setFrameShadow(QFrame::Plain);
        line_14->setFrameShape(QFrame::VLine);
        line_15 = new QFrame(frameLMX2594_2);
        line_15->setObjectName(QString::fromUtf8("line_15"));
        line_15->setGeometry(QRect(210, 60, 61, 45));
        line_15->setFont(font);
        line_15->setFrameShadow(QFrame::Plain);
        line_15->setFrameShape(QFrame::VLine);
        label_5 = new QLabel(frameLMX2594_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(210, 120, 91, 31));
        label_5->setFont(font);
        label_5->setAlignment(Qt::AlignCenter);
        NDN2 = new QSpinBox(frameLMX2594_2);
        NDN2->setObjectName(QString::fromUtf8("NDN2"));
        NDN2->setGeometry(QRect(90, 90, 111, 31));
        NDN2->setAutoFillBackground(false);
        NDN2->setWrapping(false);
        NDN2->setFrame(true);
        NDN2->setAlignment(Qt::AlignCenter);
        NDN2->setReadOnly(false);
        NDN2->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        NDN2->setAccelerated(false);
        NDN2->setProperty("showGroupSeparator", QVariant(false));
        NDN2->setMinimum(1);
        NDN2->setMaximum(25346457);
        NDN2->setValue(96);
        NDN2->setDisplayIntegerBase(10);
        lableFout_1_SI = new QLabel(widget);
        lableFout_1_SI->setObjectName(QString::fromUtf8("lableFout_1_SI"));
        lableFout_1_SI->setGeometry(QRect(650, 90, 61, 31));
        lableFout_1_SI->setFont(font);
        lableFout_1_SI->setFrameShape(QFrame::StyledPanel);
        lableFout_1_SI->setAlignment(Qt::AlignCenter);
        lowEnergy = new QPushButton(widget);
        lowEnergy->setObjectName(QString::fromUtf8("lowEnergy"));
        lowEnergy->setGeometry(QRect(680, 350, 141, 51));
        lowEnergy->setFont(font);
        lowEnergy->setAcceptDrops(false);
        lowEnergy->setLayoutDirection(Qt::LeftToRight);
        lowEnergy->setAutoFillBackground(false);
        lowEnergy->setCheckable(true);
        lowEnergy->setChecked(true);
        lowEnergy->setAutoDefault(false);
        lowEnergy->setFlat(false);
        line_13 = new QFrame(widget);
        line_13->setObjectName(QString::fromUtf8("line_13"));
        line_13->setGeometry(QRect(240, 340, 41, 31));
        line_13->setFont(font);
        line_13->setFrameShadow(QFrame::Plain);
        line_13->setFrameShape(QFrame::HLine);
        connection = new QTextEdit(widget);
        connection->setObjectName(QString::fromUtf8("connection"));
        connection->setGeometry(QRect(10, 400, 31, 31));
        connection->setReadOnly(true);
        line_6 = new QFrame(widget);
        line_6->setObjectName(QString::fromUtf8("line_6"));
        line_6->setGeometry(QRect(270, 90, 131, 31));
        line_6->setFont(font);
        line_6->setFrameShadow(QFrame::Plain);
        line_6->setFrameShape(QFrame::HLine);
        Fosc_1 = new QLineEdit(widget);
        Fosc_1->setObjectName(QString::fromUtf8("Fosc_1"));
        Fosc_1->setGeometry(QRect(10, 90, 81, 31));
        Fosc_1->setFont(font);
        Fosc_1->setAlignment(Qt::AlignCenter);
        Fosc_1->setReadOnly(true);
        Fout_2 = new QLineEdit(widget);
        Fout_2->setObjectName(QString::fromUtf8("Fout_2"));
        Fout_2->setGeometry(QRect(500, 280, 151, 31));
        Fout_2->setFont(font);
        Fout_2->setTabletTracking(false);
        Fout_2->setAcceptDrops(false);
        Fout_2->setFrame(true);
        Fout_2->setAlignment(Qt::AlignCenter);
        Fout_2->setDragEnabled(false);
        Fout_2->setReadOnly(false);
        Fout_2->setClearButtonEnabled(false);
        Fout_1 = new QLineEdit(widget);
        Fout_1->setObjectName(QString::fromUtf8("Fout_1"));
        Fout_1->setGeometry(QRect(500, 90, 151, 31));
        Fout_1->setFont(font);
        Fout_1->setEchoMode(QLineEdit::Normal);
        Fout_1->setAlignment(Qt::AlignCenter);
        Fout_1->setReadOnly(true);
        Fout_1->setClearButtonEnabled(false);
        line_3 = new QFrame(widget);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setGeometry(QRect(240, 140, 10, 41));
        line_3->setFont(font);
        line_3->setFrameShadow(QFrame::Plain);
        line_3->setFrameShape(QFrame::HLine);
        lableFout_1_SI_2 = new QLabel(widget);
        lableFout_1_SI_2->setObjectName(QString::fromUtf8("lableFout_1_SI_2"));
        lableFout_1_SI_2->setGeometry(QRect(650, 280, 61, 31));
        lableFout_1_SI_2->setFont(font);
        lableFout_1_SI_2->setFrameShape(QFrame::StyledPanel);
        lableFout_1_SI_2->setAlignment(Qt::AlignCenter);
        line_17 = new QFrame(widget);
        line_17->setObjectName(QString::fromUtf8("line_17"));
        line_17->setGeometry(QRect(460, 280, 41, 31));
        line_17->setFont(font);
        line_17->setFrameShadow(QFrame::Plain);
        line_17->setFrameShape(QFrame::HLine);
        line_11 = new QFrame(widget);
        line_11->setObjectName(QString::fromUtf8("line_11"));
        line_11->setGeometry(QRect(270, 280, 131, 31));
        line_11->setFont(font);
        line_11->setFrameShadow(QFrame::Plain);
        line_11->setFrameShape(QFrame::HLine);
        line_21 = new QFrame(widget);
        line_21->setObjectName(QString::fromUtf8("line_21"));
        line_21->setGeometry(QRect(820, 0, 20, 440));
        line_21->setFrameShadow(QFrame::Plain);
        line_21->setFrameShape(QFrame::VLine);
        configutatingTime = new QLineEdit(widget);
        configutatingTime->setObjectName(QString::fromUtf8("configutatingTime"));
        configutatingTime->setGeometry(QRect(280, 10, 81, 31));
        configutatingTime->setFont(font);
        configutatingTime->setAlignment(Qt::AlignCenter);
        configutatingTime->setReadOnly(true);
        configutatingTime->setClearButtonEnabled(false);
        configuratingLable = new QLabel(widget);
        configuratingLable->setObjectName(QString::fromUtf8("configuratingLable"));
        configuratingLable->setGeometry(QRect(10, 10, 271, 31));
        configuratingLable->setFont(font);
        configuratingLable->setFrameShape(QFrame::StyledPanel);
        configuratingLable->setAlignment(Qt::AlignCenter);
        configuratingLable->setWordWrap(false);
        configuratingLable_2 = new QLabel(widget);
        configuratingLable_2->setObjectName(QString::fromUtf8("configuratingLable_2"));
        configuratingLable_2->setGeometry(QRect(360, 10, 31, 31));
        configuratingLable_2->setFont(font);
        configuratingLable_2->setFrameShape(QFrame::StyledPanel);
        configuratingLable_2->setAlignment(Qt::AlignCenter);
        configuratingLable_2->setWordWrap(false);
        inputs = new QPushButton(widget);
        inputs->setObjectName(QString::fromUtf8("inputs"));
        inputs->setGeometry(QRect(560, 360, 101, 31));
        inputs->setFont(font);
        inputs->setAcceptDrops(false);
        inputs->setLayoutDirection(Qt::LeftToRight);
        inputs->setAutoFillBackground(false);
        inputs->setCheckable(true);
        inputs->setChecked(false);
        inputs->setAutoDefault(false);
        inputs->setFlat(false);
        label_7 = new QLabel(widget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(50, 400, 81, 31));
        Interface->setCentralWidget(centralwidget);

        retranslateUi(Interface);

        tabWidget->setCurrentIndex(0);
        lowEnergy->setDefault(false);
        inputs->setDefault(false);


        QMetaObject::connectSlotsByName(Interface);
    } // setupUi

    void retranslateUi(QMainWindow *Interface)
    {
        Interface->setWindowTitle(QCoreApplication::translate("Interface", "Interface", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(COM1), QCoreApplication::translate("Interface", "COM1", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("Interface", "COM2", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("Interface", "COM3", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("Interface", "COM4", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QCoreApplication::translate("Interface", "COM5", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QCoreApplication::translate("Interface", "COM6", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_6), QCoreApplication::translate("Interface", "COM7", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_7), QCoreApplication::translate("Interface", "COM8", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_8), QCoreApplication::translate("Interface", "COM9", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_9), QCoreApplication::translate("Interface", "COM10", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_10), QCoreApplication::translate("Interface", "COM11", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_11), QCoreApplication::translate("Interface", "COM12", nullptr));
        label_2->setText(QCoreApplication::translate("Interface", "Fout_1", nullptr));
        reset->setText(QCoreApplication::translate("Interface", "\320\241\320\261\321\200\320\276\321\201", nullptr));
        solve->setText(QCoreApplication::translate("Interface", "\320\237\320\265\321\200\320\265\321\201\321\207\320\270\321\202\320\260\321\202\321\214", nullptr));
        label_4->setText(QCoreApplication::translate("Interface", "Fout_2", nullptr));
        labelFosc_1->setText(QCoreApplication::translate("Interface", "Fosc_1", nullptr));
        lableFosc_1_SI->setText(QCoreApplication::translate("Interface", "\320\234\320\223\321\206", nullptr));
        PFD_1->setText(QCoreApplication::translate("Interface", "PFD", nullptr));
        CD1->setText(QCoreApplication::translate("Interface", "/CD1", nullptr));
        label->setText(QCoreApplication::translate("Interface", "LMX_2594 #1", nullptr));
        frame_2->setText(QString());
        NDN1->setText(QCoreApplication::translate("Interface", "96", nullptr));
        NDNUM1->setText(QCoreApplication::translate("Interface", "0", nullptr));
        NDDEN1->setText(QCoreApplication::translate("Interface", "1", nullptr));
        label_6->setText(QCoreApplication::translate("Interface", "<html><head/><body><p><span style=\" font-size:12pt;\">+</span></p></body></html>", nullptr));
        PFD_2->setText(QCoreApplication::translate("Interface", "PFD", nullptr));
        CD2->setText(QCoreApplication::translate("Interface", "/CD2", nullptr));
        label_5->setText(QCoreApplication::translate("Interface", "LMX_2594 #2", nullptr));
        NDN2->setSuffix(QString());
        NDN2->setPrefix(QString());
        lableFout_1_SI->setText(QCoreApplication::translate("Interface", "\320\223\321\206", nullptr));
        lowEnergy->setText(QCoreApplication::translate("Interface", "\320\240\320\265\320\266\320\270\320\274 \320\274\320\260\320\273\320\276\320\263\320\276\n"
" \321\215\320\275\320\265\321\200\320\263\320\276\320\277\320\276\321\202\321\200\320\265\320\261\320\273\320\265\320\275\320\270\321\217\n"
"\320\222\320\232\320\233.", nullptr));
        connection->setHtml(QCoreApplication::translate("Interface", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        Fosc_1->setText(QCoreApplication::translate("Interface", "100", nullptr));
        Fout_2->setText(QCoreApplication::translate("Interface", "100000000", nullptr));
        Fout_2->setPlaceholderText(QCoreApplication::translate("Interface", "FOut 2", nullptr));
        Fout_1->setText(QCoreApplication::translate("Interface", "100000000", nullptr));
        Fout_1->setPlaceholderText(QCoreApplication::translate("Interface", "FOut 1", nullptr));
        lableFout_1_SI_2->setText(QCoreApplication::translate("Interface", "\320\223\321\206", nullptr));
        configuratingLable->setText(QCoreApplication::translate("Interface", "\320\222\321\200\320\265\320\274\321\217 \320\264\320\273\321\217 \320\272\320\276\320\275\321\204\320\270\320\263\321\203\321\200\320\260\321\206\320\270\320\270 \321\201\320\270\320\275\321\202\320\265\320\267\320\260\321\202\320\276\321\200\320\276\320\262", nullptr));
        configuratingLable_2->setText(QCoreApplication::translate("Interface", "\321\201\320\265\320\272.", nullptr));
        inputs->setText(QCoreApplication::translate("Interface", "\320\222\321\213\321\205\320\276\320\264\321\213 \320\222\320\253\320\232\320\233.", nullptr));
        label_7->setText(QCoreApplication::translate("Interface", "\320\237\320\276\320\264\320\272\320\273\321\216\321\207\320\265\320\275\320\270\320\265", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Interface: public Ui_Interface {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INTERFACE_H
