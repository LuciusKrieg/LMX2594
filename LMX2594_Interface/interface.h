#ifndef INTERFACE_H
#define INTERFACE_H

#include <ui_interface.h>
#include <com.h>
#include <cmath>
#include <unistd.h>
#include <QTimer>
#include <QMainWindow>
#include <QMessageBox>
#include <QThread>
#include <QEventLoop>
QT_BEGIN_NAMESPACE
namespace Ui { class Interface;}
namespace Ti { class Timer;}
QT_END_NAMESPACE



class Timer : public QObject{
    Q_OBJECT

    public:
    explicit Timer(QObject* parent = nullptr);
public slots:
    void timer();

signals:
    void finished();
private:

};


class Interface : public QMainWindow {
    Q_OBJECT

    public:
        explicit Interface(QWidget *parent = nullptr);
        ~Interface();
signals:
    void start();
    private slots:
        void on_reset_clicked();
        void on_lowEnergy_clicked();
        void on_solve_clicked();
        void requesting();
        void COMClicked();
        void on_NDN2_valueChanged(int arg1);
        void on_inputs_clicked();

private:
        Ui::Interface *ui;
        Timer *t;
        QThread *th;
        QTimer *ti;
public:
        QEventLoop *loop;
};

#endif // INTERFACE_H
