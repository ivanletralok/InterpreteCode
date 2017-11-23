#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMessageBox"
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <fstream>
#include <QFont>
#include <QDebug>
#include <QDateTime>

extern void setTextEditError(QPlainTextEdit* edit1);
extern int parse_string(const char* in);
extern int errorLineNumber();

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->currentLine=1;
    QFont font;
    palette = ui->plainTextEdit->palette();
    palette.setColor(QPalette::Base, QColor(40,40,40));
    ui->appOutput->setPalette(palette);

    palette.setColor(QPalette::Text, QColor(214,154,167));
    ui->plainTextEdit->setPalette(palette);

    palette.setColor(QPalette::Base, QColor(53,53,53));
    palette.setColor(QPalette::Text, QColor(150,150,150));
    palette.setColor(QPalette::AlternateBase, QColor(53,53,53));
    ui->lineCounter->setPalette(palette);

    //palette.setColor(QPalette::Borde ,QColor(53,53,53)); //Corrigiendo los bordes del lineNumber (QPlainTextEdit)
    font.setFamily("Source Code Pro");
    font.setPixelSize(13);
    ui->plainTextEdit->setFont(font);
    ui->lineCounter->setPlainText(" 1");
    ui->lineCounter->setFont(font);

    font.setPixelSize(13);
    //setCentralWidget(ui->plainTextEdit);
    ui->appOutput->setFont(font);
    font.setPixelSize(12);
    ui->statusBar->setFont(font);
    ui->statusBar->showMessage("  Linea: 1, Columna: 1");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::autoSave()
{
    QFile file;
    QTextStream io;
    file.setFileName(QString::fromStdString(this->filename));

    file.open(QIODevice::WriteOnly | QIODevice::Text);
    if(!file.isOpen()){
        ui->statusBar->showMessage("  No se puedo abrir el archivo!");
        return;
    }
    io.setDevice(&file);
    io<<ui->plainTextEdit->toPlainText();
    ui->statusBar->showMessage("  LessText for .code ha guardado el archivo...");
    file.flush();
    file.close();
}

void MainWindow::on_actionRun_triggered()
{
    if(MainWindow::on_actionSave_triggered()){
        ui->appOutput->clear();
        setTextEditError(ui->appOutput); //Establece el texto escrito al lexer
        parse_string(ui->plainTextEdit->toPlainText().toLocal8Bit().constData());
        if(ui->appOutput->document()->isEmpty()){
            QMessageBox::information(this," resultado","compilado");
            ui->appOutput->setPlainText("Resultados de compilacion... (Hora: "+QTime::currentTime().toString()+")\n--------\n- Errores: 0\n- Peligros: 0");
        }
    }
}

void MainWindow::on_actionQuit_triggered()
{
    QString data = ui->plainTextEdit->toPlainText();
    if(data.isEmpty() && this->filename.empty()) close();
    else{
        QString title;
        bool accepted = false;
        this->filename.empty() ? title = "Sin titulo" : title = QString::fromStdString(this->filename);
        switch( QMessageBox::information( this, "LessText",
              "¿Desea guardar los cambios de "+title+"?",
              "Guardar", "No guardar", "Cancelar",
              0, 1 ) ) {
            case 0:
                accepted = on_actionSaveAs_triggered();
                break;
            case 1:
                accepted = true;
                break;
            }
        if(accepted){
            close();
        }
    }
}

void MainWindow::on_actionCopy_triggered()
{
    ui->plainTextEdit->copy();
}

void MainWindow::on_actionCut_triggered()
{
    ui->plainTextEdit->cut();
}

void MainWindow::on_actionPaste_triggered()
{
    ui->plainTextEdit->paste();
}

void MainWindow::on_actionAboutQtCreator_triggered()
{
    QMessageBox::aboutQt(this,"Qt Creator");
}

void MainWindow::on_actionUndo_triggered()
{
    ui->plainTextEdit->undo();
}

void MainWindow::on_actionRedo_triggered()
{
    ui->plainTextEdit->redo();
}

void MainWindow::on_actionAboutLessText_triggered()
{
    QString text = "LessText 1.0\n\nAuthors: Leonardo F. Ospino Ayala & Alex I. Bornachera Lasso";
    text += "\n\nThe program is provided AS PARTICULAR SOFTWARE.";
    QMessageBox::about(this,"LessText",text);
}

void MainWindow::on_actionOpen_triggered()
{
    QString name;
    QFile file;
    QTextStream io;
    name = QFileDialog::getOpenFileName(this,tr("Abrir archivo"),"",tr("Documento de texto (*.code)"));

    if(name.isEmpty()) return;

    file.setFileName(name);
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    if(!file.isOpen()){
        return;
    }
    this->filename = name.toStdString();
    io.setDevice(&file);
    ui->plainTextEdit->setPlainText(io.readAll());
    file.close();
}

bool MainWindow::on_actionSaveAs_triggered()
{
    QFile file;
    QTextStream io;
    QString name;

    QFileDialog fileDialog(NULL,tr("Guardar..."),"",tr("Documento de texto (*.code)"));
    fileDialog.setAcceptMode(QFileDialog::AcceptSave);

    if (fileDialog.exec())
        name = fileDialog.selectedFiles().at(0);
    else
        return false;

    file.setFileName(name);
    file.open(QIODevice::WriteOnly | QIODevice::Text);
    if(!file.isOpen()){
        return false;
    }
    io.setDevice(&file);
    io<<ui->plainTextEdit->toPlainText();
    this->filename = name.toStdString();
    file.flush();
    file.close();
    ui->statusBar->showMessage("  LessText for .code ha guardado el archivo...");
    return true;
}

void MainWindow::on_actionNew_triggered()
{
    QString data = ui->plainTextEdit->toPlainText();
    if(data.isEmpty() && this->filename.empty()){
        this->filename.clear();
        ui->plainTextEdit->setPlainText("");
        ui->lineCounter->setPlainText("1");
    }else{
        QString title;
        bool accepted = false, save = false;
        this->filename.empty() ? title = "Sin titulo" : title = QString::fromStdString(this->filename);
        switch( QMessageBox::information( this, "LessText",
              "¿Desea guardar los cambios de "+title+"?",
              "Guardar", "No guardar", "Cancelar",
              0, 1 ) ) {
            case 0:
                accepted = on_actionSaveAs_triggered();
                save =true;
                break;
            case 1:
                accepted = true;
                break;
            }
        if(accepted){
            this->filename.clear();
            ui->plainTextEdit->setPlainText("");
            if(save)
                ui->statusBar->showMessage("  LessText for .code ha guardado el archivo...");
        }
    }
}

bool MainWindow::on_actionSave_triggered()
{
    if(this->filename.empty()){
        return MainWindow::on_actionSaveAs_triggered();
    }else{
        QFile file;
        QTextStream io;
        file.setFileName(QString::fromStdString(this->filename));
        file.open(QIODevice::WriteOnly | QIODevice::Text);
        if(!file.isOpen()){
            return false;
        }
        io.setDevice(&file);
        io<<ui->plainTextEdit->toPlainText();
        file.flush();
        file.close();
         ui->statusBar->showMessage("  LessText for .code ha guardado el archivo...");
        return true;
    }
}

void MainWindow::on_plainTextEdit_blockCountChanged(int newBlockCount)
{
    QString textLineCounter ="";
    for(int i=1;i<=newBlockCount ;i++){
        textLineCounter += " "+QString::number(i)+"\n";
    }
    ui->lineCounter->setPlainText(textLineCounter);
}

void MainWindow::on_plainTextEdit_undoAvailable(bool b)
{
    ui->actionUndo->setEnabled(b);
}

void MainWindow::on_plainTextEdit_redoAvailable(bool b)
{
    ui->actionRedo->setEnabled(b);
}

void MainWindow::on_plainTextEdit_cursorPositionChanged()
{
    int xAxis = ui->plainTextEdit->textCursor().blockNumber()+1;
    int yAxis = ui->plainTextEdit->textCursor().positionInBlock()+1;
    ui->statusBar->showMessage("  Linea: "+QString::number(xAxis)+", Columna: "+QString::number(yAxis));
}
