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
    void populateTransactions();
    QGroupBox *createListItem(vector<QString> item);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
