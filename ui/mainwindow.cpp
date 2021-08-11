#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QGraphicsDropShadowEffect>

vector<vector<QString>> items;
QFont font3, font5, font6;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    font3.setFamily(QString::fromUtf8("Trebuchet MS"));
    font3.setPointSize(16);
    font5.setFamily(QString::fromUtf8("Trebuchet MS"));
    font5.setPointSize(12);
    font6.setFamily(QString::fromUtf8("Trebuchet MS"));
    font6.setPointSize(14);
    font6.setBold(true);
    font6.setWeight(75);

    modifyUiSetup();
    populateTransactions();
}

void MainWindow::modifyUiSetup()
{
    QString path = ":/tab.qss";
    QFile file(path);

    if ( file.open(QFile::ReadOnly) )
    {
        QString qss = QLatin1String(file.readAll());
        this->setStyleSheet(qss);
        file.close();
    }

    QGraphicsDropShadowEffect *shadowEffect = new QGraphicsDropShadowEffect;
    shadowEffect->setColor(QColor(0,0,0,120));
    shadowEffect->setBlurRadius(25);
    shadowEffect->setOffset(0, 3);
    ui->lblOverview->setGraphicsEffect(shadowEffect);

    QGraphicsDropShadowEffect *shadowEffect1 = new QGraphicsDropShadowEffect;
    shadowEffect1->setColor(QColor(0,0,0,120));
    shadowEffect1->setBlurRadius(25);
    shadowEffect1->setOffset(0, 3);
    ui->grpTab1Group1->setGraphicsEffect(shadowEffect1);

    QGraphicsDropShadowEffect *shadowEffect2 = new QGraphicsDropShadowEffect;
    shadowEffect2->setColor(QColor(0,0,0,120));
    shadowEffect2->setBlurRadius(25);
    shadowEffect2->setOffset(0, 3);
    ui->grpTab1Group2->setGraphicsEffect(shadowEffect2);

    QGraphicsDropShadowEffect *shadowEffect3 = new QGraphicsDropShadowEffect;
    shadowEffect3->setColor(QColor(0,0,0,120));
    shadowEffect3->setBlurRadius(25);
    shadowEffect3->setOffset(0, 3);
    ui->grpTab1Group3->setGraphicsEffect(shadowEffect3);

    QGraphicsDropShadowEffect *shadowEffect4 = new QGraphicsDropShadowEffect;
    shadowEffect4->setColor(QColor(0,0,0,120));
    shadowEffect4->setBlurRadius(25);
    shadowEffect4->setOffset(0, 3);
    ui->grpTab1Group4->setGraphicsEffect(shadowEffect4);

}

void MainWindow::populateTransactions()
{
    items.push_back({"08/08/2021 08:15","Jack Siro", "+3.75000000 SPM"});
    items.push_back({"08/08/2021 12:12","Obiro Nyongesa", "+3.7500000 SPM"});
    items.push_back({"08/08/2021 13:59","Nancy Akinyi", "+3.7500000 SPM"});
    items.push_back({"08/08/2021 16:47","John Maloba", "+3.75000000 SPM"});
    items.push_back({"08/08/2021 19:44","Patrick Nyosia", "+3.7500000 SPM"});
    items.push_back({"08/08/2021 20:21","Crazy Kennar", "+3.7500000 SPM"});
    items.push_back({"08/08/2021 22:23","Alex Tibwata", "+3.7500000 SPM"});

    for (decltype(items.size()) i = 0; i < items.size(); ++i)
    {
        QGroupBox *grpItem = createListItem(items[i]);
        ui->lstLayout->addWidget(grpItem);
    }

    QSpacerItem *lstSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);
    ui->lstLayout->addItem(lstSpacer);
}

QGroupBox *MainWindow::createListItem(vector<QString> item)
{
    QSizePolicy grpSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Preferred);

    QGroupBox *grpItem = new QGroupBox(ui->scrollAreaWidgetContents);
    grpSizePolicy.setHorizontalStretch(0);
    grpSizePolicy.setVerticalStretch(0);
    grpSizePolicy.setHeightForWidth(grpItem->sizePolicy().hasHeightForWidth());
    grpItem->setSizePolicy(grpSizePolicy);
    QGridLayout *grpLayout = new QGridLayout(grpItem);

    QLabel *itemImage = new QLabel(grpItem);
    itemImage->setPixmap(QPixmap(QString::fromUtf8(":/transaction.png")));
    itemImage->setAlignment(Qt::AlignCenter);

    QLabel *itemDate = new QLabel(grpItem);
    itemDate->setSizePolicy(sizePolicy1);
    itemDate->setFont(font6);
    itemDate->setText(item[0]);

    QLabel *itemName = new QLabel(grpItem);
    itemName->setFont(font3);
    itemName->setText(item[1]);

    QLabel *itemSpm = new QLabel(grpItem);
    itemSpm->setFont(font5);
    itemSpm->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
    itemSpm->setText(item[2]);

    grpLayout->addWidget(itemDate, 0, 1, 1, 1);
    grpLayout->addWidget(itemImage, 0, 0, 2, 1);
    grpLayout->addWidget(itemSpm, 0, 2, 1, 1);
    grpLayout->addWidget(itemName, 1, 1, 1, 2);

    grpItem->setStyleSheet("padding: 2px; margin: 2px; border-radius: 3px;");

    QGraphicsDropShadowEffect *grpShadowEffect = new QGraphicsDropShadowEffect;
    grpShadowEffect->setColor(QColor(0,0,0,120));
    grpShadowEffect->setBlurRadius(10);
    grpShadowEffect->setOffset(0, 2);
    grpItem->setGraphicsEffect(grpShadowEffect);
    return grpItem;
}

MainWindow::~MainWindow()
{
    delete ui;
}

