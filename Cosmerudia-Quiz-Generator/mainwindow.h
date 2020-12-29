#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLineEdit>
#include <QPainter>
#include <QtSvg/QSvgGenerator>
#include <QPoint>
#include <QFileDialog>
#include <QPixmap>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void generate();
    void save();

private:
    Ui::MainWindow *ui;
    QLineEdit *text;
    QPainter *painter;
    QPixmap *pixmap;
};
#endif // MAINWINDOW_H
