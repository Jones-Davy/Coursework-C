#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStackedWidget>
#include <QSpinBox>
#include <QMessageBox>
#include <QFileDialog>
#include <QInputDialog>
#include <QTextStream>
#include "listR.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);

    ~MainWindow();

private slots:
    void on_Choose_clicked();
    void on_add_w_clicked();
    void on_add__Restoran_clicked();
    void on_add_s_clicked();
    void on_add_a_clicked();
    void on_Edit_clicked();
    void on_Delete_clicked();
    void on_delete_Restoran_clicked();
    void on_Restoran_clicked();
    void on_edit_Restoran_2_clicked();
    void on_choise_poisk_activated(int index);
    void on_Poisk_2_clicked();
    void on_Poisk_clicked();
    void on_Return_clicked();
    void on_edit_w_clicked();
    void on_edit_s_clicked();
    void on_edit_a_clicked();
    void on_edit_Restoran_clicked();
    void on_add_Restoran_clicked();
    void on_Exit_triggered();
    void on_About_the_program_triggered();
    void on_Managment_triggered();
    void on_Create_triggered();
    void on_Open_triggered();
    void on_Save_triggered();
    void on_Save_As_triggered();

private:



    void AddGuard();
    void add_Restoran();
    void Save(QString str);
    void edit(int itm);
    void table1(Restoran *B, restaurant *A, int j);
    int unic_sotr(int id, int n);
    int unic_rest(QString name, int s);
    int check_correct(QString check);
    int check_letter(QString check);
    void table2(Restoran *A, restaurant *B, int j);
    void table3(Restoran *A, int j);
    int SearchById(int id);
    int SearchByName(QString name);
    void AddWaiter();
    void AddSchef();



    Ui::MainWindow *ui;
    restaurant *Employee;
    Restoran *Restaurant;
    int id;
    int currentIndex;
    int n = 0;
    int k1;
    int itm;
    int id1;
    int s = 0;
    int hause;
    int index1;
    QString form, age, strr, strr1, adres, str, sotr, oblast, sity, street, tel, name;
    double salary;

    bool CorrectFlag = true, CorrectFlag1 = true;

    ListR L;
};

#endif // MAINWINDOW_H
