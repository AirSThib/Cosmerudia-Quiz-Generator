#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLineEdit>
#include <QPainter>
#include <QtSvg/QSvgGenerator>
#include <QPoint>
#include <QFileDialog>
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowTitle("Cosmerudia Quiz Generator");
    setGeometry(240,240, 180, 80);

    QWidget *mainWidget = new QWidget();
    setCentralWidget(mainWidget);

    QVBoxLayout *mainLayout = new QVBoxLayout();
    mainWidget->setLayout(mainLayout);

    text = new QLineEdit();
    text->setPlaceholderText("Enter your question here");
    mainLayout->addWidget(text);

    QPushButton *buttonGenerate = new QPushButton("Generate");
    connect(buttonGenerate, SIGNAL(clicked()), this, SLOT(generate()));
    mainLayout->addWidget(buttonGenerate);

    QPushButton *buttonSave = new QPushButton("Save");
    connect(buttonSave, SIGNAL(clicked()), this, SLOT(save()));
    mainLayout->addWidget(buttonSave);

    painter = new QPainter();
}

void MainWindow::generate()
{
    pixmap = new QPixmap(1280,720);
    painter->begin(pixmap);
    painter->drawImage(QRect(0,0,1280,720), QImage("background.png"));
    painter->setFont(QFont("sans-serif", 40));
    painter->drawText(QRect(180,180,920,360), text->text(), QTextOption(Qt::AlignCenter));
    painter->end();
}

void MainWindow::save()
{
    QString path = QFileDialog::getSaveFileName(this, tr("Save PNG"), "", tr("PNG files (*.png)"));

    generate();
    pixmap->save(path);
}

MainWindow::~MainWindow()
{
    delete ui;
}

