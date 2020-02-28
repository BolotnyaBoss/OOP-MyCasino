#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qrandom.h>
#include <ctime>
#include <cstdlib>
#include <time.h>
#include <qmessagebox.h>
#include <string>
#include <QDebug>
int val=0;
int startVal=10,balance=100;
bool oneTrigger=false;
bool twoTrigger=false;
bool threeTrigger=false;
bool fourTrigger=false;
bool fiveTrigger=false;
bool sixTrigger=false;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->spinBox->setValue(startVal);
        ui->tableWidget->setItem(0,0,new QTableWidgetItem("     "+QString::number(balance,'g',15)+"   UAH"));

        ui->one->setStyleSheet("border-image:url(D:/labs oop/MyCasino/dice_one.png);");
        ui->two->setStyleSheet("border-image:url(D:/labs oop/MyCasino/dice_two.png);");
        ui->three->setStyleSheet("border-image:url(D:/labs oop/MyCasino/dice_three.png);");
        ui->four->setStyleSheet("border-image:url(D:/labs oop/MyCasino/dice_four.png);");
        ui->five->setStyleSheet("border-image:url(D:/labs oop/MyCasino/dice_five.png);");
        ui->six->setStyleSheet("border-image:url(D:/labs oop/MyCasino/dice_six.png);");
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_spinBox_valueChanged(int arg1)
{
    QString display = ui->spinBox->text();
       double val=display.toDouble();
       ui->tableWidget_2->setItem(0,0,new QTableWidgetItem("          "+QString::number(val,'g',16)+"   UAH"));
}
int MainWindow::on_one_pressed()
{
    oneTrigger=true;
         twoTrigger=false;
         threeTrigger=false;
         fourTrigger=false;
         fiveTrigger=false;
         sixTrigger=false;
        return 1;
}
int MainWindow::on_two_pressed()
{
    twoTrigger=true;
    oneTrigger=false;
    fourTrigger=false;
    fiveTrigger=false;
    sixTrigger=false;
    threeTrigger=false;
    return 2;
}
int MainWindow::on_three_pressed()
{
    threeTrigger=true;
    oneTrigger=false;
    twoTrigger=false;
    fourTrigger=false;
    fiveTrigger=false;
    sixTrigger=false;
    return 3;
}
int  MainWindow::on_four_pressed()
{
    fourTrigger=true;
    oneTrigger=false;
    twoTrigger=false;
    threeTrigger=false;
    fiveTrigger=false;
    sixTrigger=false;
    return 4;
}
int MainWindow::on_five_pressed()
{
    fiveTrigger=true;
    oneTrigger=false;
    threeTrigger=false;
    twoTrigger=false;
    fourTrigger=false;
    sixTrigger=false;
  return 5;
}
int MainWindow::on_six_pressed()
{
    sixTrigger=true;
    twoTrigger=false;
    oneTrigger=false;
    threeTrigger=false;
    fourTrigger=false;
    fiveTrigger=false;
    return 6;
 }

void MainWindow::on_pushButton_7_pressed()
{
    if(oneTrigger || twoTrigger || threeTrigger || fourTrigger || fiveTrigger || sixTrigger){
     if(oneTrigger){
        val=on_one_pressed();
     }
     else if(twoTrigger){
         val=on_two_pressed();
      }
     else if(threeTrigger){
         val=on_three_pressed();
      }
     else if(fourTrigger){
         val=on_four_pressed();
      }
     else if(fiveTrigger){
         val=on_five_pressed();
      }
     else if(sixTrigger)  {
         val=on_six_pressed();
      }
     QMessageBox::StandardButton reply;
      reply = QMessageBox::question(this, "Casino", "Ви хочете зробити ставку?",
                                    QMessageBox::Yes|QMessageBox::No);
      if (reply == QMessageBox::No) {
      return;
      }
     }
     else return;
      int win;
       srand(time(NULL));
       int ran=1+rand()%6;
       QString displayVal = ui->spinBox->text();
    double bet=displayVal.toDouble();
     if(balance<bet || bet<10){
         if(balance<bet){
         QMessageBox::warning(this,"Casino","Замало грошей на рахунку");
              return;
         }
         if(bet<10)
         {
             QMessageBox::warning(this, "Casino", "Зробіть більшу ставку");
             return;
         }}
      if(ran==6){
           QPixmap pixmap0("D:/labs oop/MyCasino/dice_six.png");
           ui->label->setPixmap(pixmap0);
     }
     if(ran==5){
           QPixmap pixmap0("D:/labs oop/MyCasino/dice_five.png");
           ui->label->setPixmap(pixmap0);
       }
     if(ran==4){
           QPixmap pixmap0("D:/labs oop/MyCasino/dice_four.png");
           ui->label->setPixmap(pixmap0);
       }
     if(ran==3){
           QPixmap pixmap0("D:/labs oop/MyCasino/dice_three.png");
           ui->label->setPixmap(pixmap0);
       }
     if(ran==2){
           QPixmap pixmap0("D:/labs oop/MyCasino/dice_two.png");
           ui->label->setPixmap(pixmap0);
       }
     if(ran==1){
           QPixmap pixmap0("D:/labs oop/MyCasino/dice_one.png");
           ui->label->setPixmap(pixmap0);
       }
       if(val==ran){
            win=3*bet;
             QString winVal = QString::number(win);
             QMessageBox::warning(this,"Casino777"," Ви виграли!!! " +    winVal+"UAH" );
                 balance=balance-bet+win;
                 ui->tableWidget->setItem(0,0,new QTableWidgetItem("          "+QString::number(balance,'g',15)+"   UAH"));
               }
               else {
                     QMessageBox::warning(this,"Casino777 ","  От дідько, ви програли ");
                   balance=balance-bet;
                   ui->tableWidget->setItem(0,0,new QTableWidgetItem("          "+QString::number(balance,'g',15)+"   UAH"));
               }
}

void MainWindow::on_pushButton_8_pressed()
{
    if (balance<200){
      QMessageBox::warning(this,"Casino777","Замало грошей, щоб їх вивести" );
      }
      else {
        QMessageBox::StandardButton reply;
         reply = QMessageBox::question(this, "Warning", "Щоб вивести гроші, авторизуйтесь",
                                       QMessageBox::Ok|QMessageBox::No);
         if (reply == QMessageBox::No) {
             return;
         }
         else {
             QMessageBox::warning(this,"Casino777","Для авторизації зробіть донат на 4441 1144 4020 2602" );
         }
    }
}

void MainWindow::on_pushButton_9_pressed()
{
    QMessageBox::StandardButton reply;
         reply = QMessageBox::question(this, "Warning", "Ви хочете взяти у борг гроші ?",
                                       QMessageBox::Yes|QMessageBox::No);
         if (reply == QMessageBox::No) {
             return;
         }
         else {
             QMessageBox::warning(this,"Casino777","Для цього зробіть донат на 4441 1144 4020 2602" );
         }
}
