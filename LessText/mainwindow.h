#ifndef MAINWINDOW_H
#define MAINWINDOW_HS
#include <string.h>

#include <QMainWindow>


using std::string;
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void autoSave();
    ~MainWindow();
private slots:
    void on_actionQuit_triggered();
    void on_actionCopy_triggered();
    void on_actionCut_triggered();
    void on_actionPaste_triggered();
    void on_actionAboutQtCreator_triggered();
    void on_actionAboutLessText_triggered();
    void on_actionOpen_triggered();
    bool on_actionSaveAs_triggered();
    void on_actionNew_triggered();
    bool on_actionSave_triggered();
    void on_actionUndo_triggered();
    void on_actionRedo_triggered();
    void on_actionRun_triggered();
    void on_plainTextEdit_blockCountChanged(int newBlockCount);
    void on_plainTextEdit_undoAvailable(bool b);
    void on_plainTextEdit_redoAvailable(bool b);
    void on_plainTextEdit_cursorPositionChanged();

private:
    int currentLine;
    Ui::MainWindow *ui;
    string filename;
    QPalette palette;
};

#endif // MAINWINDOW_H
