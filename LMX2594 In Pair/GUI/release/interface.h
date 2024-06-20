#ifndef INTERFACE_H
#define INTERFACE_H

#include <ui_interface.h>
#include <com.h>
#include <cmath>

#include <QMainWindow>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class Interface; }
QT_END_NAMESPACE

class Interface : public QMainWindow {
    Q_OBJECT

    public:
        Interface(QWidget *parent = nullptr);
        ~Interface();

    private slots:
        void on_tabWidget_tabBarClicked(int index);
        void on_reset_clicked();
        void on_lowEnergy_clicked();
        void on_solve_clicked();
        void requesting();

        /*
        void on_Fout_2_editingFinished();
        void Error(uint8_t flag);
        void on_Fout_2_textChanged(const QString &arg1);
        QString tabbing(QString str);
        */

        void on_NDN2_valueChanged(int arg1);

private:
        Ui::Interface *ui;
};

#endif // INTERFACE_H
