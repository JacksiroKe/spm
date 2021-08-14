#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QGraphicsDropShadowEffect>
#include <QStandardItemModel>
#include <QObject>

using namespace std;

vector<vector<QString>> actions1;
QFont font1, font2;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    font1.setFamily(QString::fromUtf8("Trebuchet MS"));
    font1.setPointSize(14);
    font1.setBold(true);
    font1.setWeight(75);
    font2.setFamily(QString::fromUtf8("Trebuchet MS"));
    font2.setPointSize(12);

    modifyUiSetup();
    populateAction1Lists();
}

void MainWindow::modifyUiSetup()
{
    QFile file(":/theme.qss");

    if ( file.open(QFile::ReadOnly) )
    {
        setStyleSheet(QLatin1String(file.readAll()));
        file.close();
    }

    QGraphicsDropShadowEffect *shadowEffect1 = new QGraphicsDropShadowEffect;
    shadowEffect1->setColor(QColor(0,0,0,120));
    shadowEffect1->setBlurRadius(25);
    shadowEffect1->setOffset(0, 0);
    ui->tabPanel2->setGraphicsEffect(shadowEffect1);

}

void MainWindow::populateAction1Lists()
{

    actions1.push_back({ ":/transaction.png", "BTC", "Bitcoin #0", "0.06375653"});
    actions1.push_back({ ":/transaction.png", "ETH", "Ethereum #0", "0.00079000"});
    actions1.push_back({ ":/transaction.png", "ETHt", "Ethereum Ropsten Testnet #0", "0.0000000"});
    actions1.push_back({ ":/transaction.png", "ZCASH", "Litecoin Testnet #0", "0.000000000"});

    for (decltype(actions1.size()) i = 0; i < actions1.size(); ++i)
    {
        QGroupBox *grpItem = createAction1Item(actions1[i]);
        ui->lstActions1Layout->addWidget(grpItem);

        QFrame *lineTab1Item = new QFrame(ui->grpPanel2);
        lineTab1Item->setStyleSheet(QString::fromUtf8("background-color: #fff;"));
        lineTab1Item->setFrameShape(QFrame::HLine);
        lineTab1Item->setFrameShadow(QFrame::Sunken);
        ui->lstActions1Layout->addWidget(lineTab1Item);

    }

    QSpacerItem *lstSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);
    ui->lstActions1Layout->addItem(lstSpacer);
}

QGroupBox *MainWindow::createAction1Item(vector<QString> item)
{
    QSizePolicy grpSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Preferred);

    QGroupBox *grpItem = new QGroupBox(ui->scrollAreaWidgetContents);
    grpSizePolicy.setHorizontalStretch(0);
    grpSizePolicy.setVerticalStretch(0);
    grpSizePolicy.setHeightForWidth(grpItem->sizePolicy().hasHeightForWidth());
    grpItem->setSizePolicy(grpSizePolicy);
    QGridLayout *grpLayout = new QGridLayout(grpItem);

    QLabel *itemIcon = new QLabel(grpItem);
    itemIcon->setPixmap(QPixmap(item[0]));
    itemIcon->setAlignment(Qt::AlignCenter);

    QLabel *itemTitle = new QLabel(grpItem);
    itemTitle->setSizePolicy(sizePolicy1);
    itemTitle->setFont(font1);
    itemTitle->setText(item[1]);

    QLabel *itemDescription = new QLabel(grpItem);
    itemDescription->setFont(font2);
    itemDescription->setText(item[2]);

    QLabel *itemAmount = new QLabel(grpItem);
    itemAmount->setFont(font1);
    itemAmount->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
    itemAmount->setText(item[3]);

    grpLayout->addWidget(itemTitle, 0, 1, 1, 1);
    grpLayout->addWidget(itemIcon, 0, 0, 2, 1);
    grpLayout->addWidget(itemAmount, 0, 2, 1, 1);
    grpLayout->addWidget(itemDescription, 1, 1, 1, 2);

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

