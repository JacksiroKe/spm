#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

using namespace std;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void modifyUiSetup();
    void populateAction1Lists();
    QGroupBox *createAction1Item(vector<QString> item);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
