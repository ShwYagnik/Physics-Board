#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include<QEvent>
#include <QMainWindow>
#include<QPaintEvent>
#include<QMouseEvent>
#include<drawablecomponent.h>
#include<rectangle.h>
#include<circle.h>
#include<tmview.h>
#include<line.h>
#include<eraser1.h>
#include<pictures.h>
#include<scribble.h>
#include<QListWidgetItem>
#include<QCursor>
#include<QImageReader>
#include<QImage>
#include<QFileDialog>
#include<QGraphicsView>
#include<QGraphicsPixmapItem>
#include<QtMultimedia/QMediaRecorder>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();
    void closeEvent(QCloseEvent*);
    void paintEvent(QPaintEvent*);
    void mousePressEvent(QMouseEvent*);
    void mouseReleaseEvent(QMouseEvent*);
    void mouseMoveEvent(QMouseEvent*);
    void keyPressEvent(QKeyEvent*);
    void keyReleaseEvent(QKeyEvent*);
    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_13_clicked();

    void on_lineEdit_4_textChanged(const QString &arg1);

    void on_pushButton_18_clicked();

    void on_pushButton_14_clicked();

    void on_pushButton_16_clicked();

    void on_pushButton_15_clicked();

    void on_pushButton_17_clicked();

    void on_pushButton_20_clicked();

    void on_pushButton_19_clicked();

    void on_pushButton_21_clicked();

    void on_pushButton_22_clicked();

    void on_pushButton_25_clicked();

    void on_pushButton_26_clicked();

    void on_listWidget_3_itemDoubleClicked(QListWidgetItem *item);

    void on_listWidget_itemClicked(QListWidgetItem *item);

    void on_listWidget_itemDoubleClicked(QListWidgetItem *item);

    void on_pushButton_27_clicked();

    void on_pushButton_28_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
