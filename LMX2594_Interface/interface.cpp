#include <interface.h>

using namespace std;

HANDLE hSerial;

// КОНСТРУКТОР ИНТЕРФЕЙСА INTERFACE
Interface::Interface(QWidget *parent) : QMainWindow(parent), ui(new Ui::Interface) {
    ui->setupUi(this);

    th = new QThread(this);
    t = new Timer();
        connect(ui->tabWidget, SIGNAL(currentChanged(int)), this, SLOT(COMClicked()));
        connect(this, SIGNAL(destroyed()), th, SLOT(quit()));
        connect(t, SIGNAL(finished()), t, SLOT(timer()));
        connect(this, SIGNAL(start()), t, SLOT(timer()));
        t->moveToThread(th);
    th->start();
}
Timer::Timer(QObject *parent) : QObject(parent){

}
// ДЕСТРУКТОР ИНТЕРФЕЙСА
Interface::~Interface() { delete ui; }

// ПОДКЛЮЧЕНИЕ И УСТАНОВКА СВЯЗИ
void Interface::COMClicked(){
    CloseHandle(hSerial);
    int index = ui->tabWidget->currentIndex()+1;
    string str = ("COM" + QString::number(index)).toStdString();
    hSerial = COM_Init(wstring(str.begin(), str.end()).c_str(), 9600);
    COM_WriteDigit(hSerial, 5);
    if (COM_ReadDigit(hSerial) == 5) {
        ui->connection->setStyleSheet("background-color: rgb(0,255,0)");
        ui->widget->show();
        emit start();
    }
    else {
        ui->widget->hide();
    }
}
//ОБРАБОТЧИК ПРОВЕРКИ СВЯЗИ КАЖДЫЕ 30СЕК
void Timer::timer(){
        QEventLoop loop;
        QTimer timer;
        timer.setInterval(30000); //30 sec
        connect (&timer, SIGNAL(timeout()), &loop, SLOT(quit()));
        timer.start();
        loop.exec();
        COM_WriteDigit(hSerial, 5);
        COM_ReadDigit(hSerial);
        emit finished();
}

//

// ОБРАБОТЧИК НАЖАТИЯ КНОПКИ СБРОСА
void Interface::on_reset_clicked() {
    COM_WriteDigit(hSerial, 0);
    requesting();
    COM_ReadDigit(hSerial);
    ui->reset->setChecked(0);
    ui->inputs->setChecked(0);
    ui->inputs->setText("Выходы ВЫКЛ.");
}

// ОБРАБОТЧИК НАЖАТИЯ КНОПКИ ИЗМЕНЕНИЯ РЕЖИМА ЭНЕРГОПОТРЕБЛЕНИЯ
void Interface::on_lowEnergy_clicked() {
    COM_WriteDigit(hSerial, 1);
    if (ui->lowEnergy->isChecked() == 0) {
        COM_WriteDigit(hSerial, 1);
        ui->lowEnergy->setText("Режим малого\n энергопотребления\nВЫКЛ.");
        ui->connection->setStyleSheet("background-color: rgb(0,255,0)");
    } else {
        COM_WriteDigit(hSerial, 0);
        ui->lowEnergy->setText("Режим малого\n энергопотребления\nВКЛ.");
        ui->connection->setStyleSheet("background-color: rgb(255,255,0)");
    }
    COM_ReadDigit(hSerial);
}

// ОБРАБОТЧИК НАЖАТИЯ КНОПКИ ИЗМЕНЕНИЯ ЧАСТОТЫ
void Interface::on_solve_clicked() {
    double Fout2 = ui->Fout_2->text().toDouble();
    if (Fout2 > 15000000000 || Fout2 < 10000000) {
        QMessageBox msgBox;
        msgBox.setText("Ошибка!");
        if (Fout2 > 15000000000) msgBox.setInformativeText("Введённое значение Fout2 > 15ГГц");
        if (Fout2 < 10000000   ) msgBox.setInformativeText("Введённое значение Fout2 < 10МГц");
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.exec();
        return;
    }
    COM_WriteDigit(hSerial, 2);
    COM_WriteDouble(hSerial, Fout2);
    requesting();
    COM_ReadDigit(hSerial);
    ui->inputs->setChecked(0);
    ui->inputs->setText("Выходы ВЫКЛ.");
    ui->solve->setChecked(0);
}

// ЧТЕНИЕ И ВЫВОД НА ЭКРАН ПОЛУЧЕННЫХ РАССЧИТАННЫХ ДАННЫХ
void Interface::requesting() {
    double Fosc1    = COM_ReadDouble(hSerial);
    uint32_t NDN1   = COM_ReadDigit(hSerial);
    uint32_t NDNUM1 = COM_ReadDigit(hSerial);
    uint32_t NDDEN1 = COM_ReadDigit(hSerial);
    double Fvco1    = COM_ReadDouble(hSerial);
    uint16_t CD1    = COM_ReadDigit(hSerial);
    double Fout1    = COM_ReadDouble(hSerial);
    double Fosc2    = COM_ReadDouble(hSerial);
    uint32_t NDN2   = COM_ReadDigit(hSerial);
    double Fvco2    = COM_ReadDouble(hSerial);
    uint16_t CD2    = COM_ReadDigit(hSerial);
    double Fout2    = COM_ReadDouble(hSerial);
    double time     = COM_ReadDouble(hSerial);
    if(ui->solve->isChecked() || ui->reset->isChecked()){
        ui->NDN2->setValue(NDN2);
    }
    ui->CD1->setText              (QString::number(CD1));
    ui->CD2->setText              (QString::number(CD2));
    ui->NDN1->setText             (QString::number(NDN1));
    ui->NDDEN1->setText           (QString::number(NDDEN1));
    ui->NDNUM1->setText           (QString::number(NDNUM1));
    ui->Fout_1->setText           (QString::number(Fout1, 'f', 3));
    ui->Fout_2->setText           (QString::number(Fout2, 'f', 3));
    ui->configutatingTime->setText(QString::number(time,  'f', 6));
}

void Interface::on_NDN2_valueChanged(int arg1)
{
    if(ui->reset->isChecked()==0 && ui->solve->isChecked()==0){
        COM_WriteDigit(hSerial, 3);
        COM_WriteDigit(hSerial, arg1);
        if(COM_ReadDigit(hSerial)){
            requesting();
        }
        COM_ReadDigit(hSerial);
    }
}



void Interface::on_inputs_clicked()
{
    COM_WriteDigit(hSerial, 4);
    if (ui->inputs->isChecked() == 0) {
        COM_WriteDigit(hSerial, 0);
        ui->inputs->setText("Выходы ВЫКЛ.");
    } else {
        COM_WriteDigit(hSerial, 1);
        ui->inputs->setText("Выходы ВКЛ.");
    }
    COM_ReadDigit(hSerial);
}


