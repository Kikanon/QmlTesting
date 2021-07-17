#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile> // upravljanje datotek od Qt
#include <QTextStream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    naloziDatoteko();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    //funkcija ki jo naredis z Go to slot
    //not pa koda ki se izvede ko kliknes gumbek
    QString searchString = ui->lineEdit->text();
    if(ui->textEdit->find(searchString, QTextDocument::FindWholeWords))ui->label_2->setText("Naslo");
    else ui->label_2->setText("Ne najde");
}

void MainWindow::naloziDatoteko(){
    QFile inputFile(":/input.txt");//odprem datoteko
    inputFile.open(QIODevice::ReadOnly);

       QTextStream in(&inputFile);//z Textstream spravim v line
       QString line = in.readAll();
       inputFile.close();

       ui->textEdit->setPlainText(line);//polje textEdit nastavi na tekst in prestavi cursor na zacetek
       QTextCursor cursor = ui->textEdit->textCursor();
       cursor.movePosition(QTextCursor::Start, QTextCursor::MoveAnchor, 1);
}

/*
Dialog za odpiranje datoteke
#include <QFileDialog>
void MainWindow::on_pushButton_clicked(){
    QString file_name = QFileDialog::getOpenFileName(this,"Choose file", "C:/Desktop");
}



*/
