#include <interface.h>

using namespace std;

HANDLE hSerial;

// КОНСТРУКТОР ИНТЕРФЕЙСА
Interface::Interface(QWidget *parent) : QMainWindow(parent), ui(new Ui::Interface) { ui->setupUi(this); ui->widget->hide(); }
// ДЕСТРУКТОР ИНТЕРФЕЙСА
Interface::~Interface() { delete ui; }

// ПОДКЛЮЧЕНИЕ И УСТАНОВКА СВЯЗИ
void Interface::on_tabWidget_tabBarClicked(int index) {
    CloseHandle(hSerial);
    string str = ("COM" + QString::number(index + 1)).toStdString();
    hSerial = COM_Init(wstring(str.begin(), str.end()).c_str(), 9600);
    COM_WriteDigit(hSerial, 5);
    if (COM_ReadDigit(hSerial) == 5) {
        ui->connection->setStyleSheet("background-color: rgb(0,255,0)");
        ui->widget->show();
    } else {
        ui->widget->hide();
    }
}

// ОБРАБОТЧИК НАЖАТИЯ КНОПКИ СБРОСА
void Interface::on_reset_clicked() {
    COM_WriteDigit(hSerial, 0);
    requesting();
    COM_ReadDigit(hSerial);
    ui->reset->setChecked(0);
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



/*
void Interface::Error(uint8_t error_flag) {
    QMessageBox msgBox;
    msgBox.setText("Ошибка");
    switch(error_flag) {
        case 1:
            msgBox.setInformativeText("Устройство не подключено");
        break;
        case 2:
            msgBox.setInformativeText("Введённое значение Fout2 некорректно");
        break;
        case 3:
            ui->Fout_2->setStyleSheet("background-color: rgb(225,25,25)");
        break;
    }
    msgBox.setIcon(QMessageBox::Critical);
    msgBox.exec();
}

QString Interface::tabbing(QString str){
    int x = str.length() - 3;
    if (x == 1 || x == 4) str.insert(x, ' ');
    return str;
}

void Interface::on_Fout_2_textChanged(const QString &arg1) {
    double Y = modf(modf(arg1.toDouble() * 1000, &Y), &Y);
    if ((arg1.contains('.') && Y < 1.0 && Y != 0.0) || arg1.contains(".0000")) {
        Error(3);
        ui->Fout_2->setText((arg1.chopped(1)));
        return;
    }
    ui->Fout_2->setStyleSheet("background-color: rgb(255,255,255)");
}

void Interface::on_Fout_2_editingFinished() {
    double Fout2 = ui->Fout_2->text().toDouble();
    if (Fout2 > 15000000000 || Fout2 < 10000000) {
        Error(3);
        return;
    }
}
*/


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


