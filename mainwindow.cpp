#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowTitle("Информационная система \"Ресторан\"");

    if(L.getCount() == 0)
    {
        ui->tip->setDisabled(1);
    }

    ui->Return->setDisabled(1);
    ui->edit_w->setDisabled(1);
    ui->edit_s->setDisabled(1);
    ui->edit_a->setDisabled(1);

    ui->edit_Restoran->setDisabled(1);
    ui->Poisk->setDisabled(1);

    ui->stackedWidget->setCurrentIndex(0);
    ui->stackedWidget_2->setCurrentIndex(0);
    ui->stackedWidget_3->setCurrentIndex(0);

    ui->tablica->setColumnWidth(0,100);
    ui->tablica->setColumnWidth(1,150);
    ui->tablica->setColumnWidth(2,150);
    ui->tablica->setColumnWidth(3,200);
    ui->tablica->setColumnWidth(4,190);
    ui->tablica->setColumnWidth(5,100);
    ui->tablica->setColumnWidth(6,100);
    ui->tablica->setColumnWidth(7,75);
    ui->tablica->setColumnWidth(8,100);
    ui->tablica->setColumnWidth(9,75);
    ui->tablica->setColumnWidth(10,50);
    ui->tablica->setColumnWidth(11,100);

    ui->tablica->setColumnWidth(0,100);
    ui->tablica->setColumnWidth(1,150);
    ui->tablica->setColumnWidth(2,150);
    ui->tablica->setColumnWidth(3,100);
    ui->tablica->setColumnWidth(4,190);
    ui->tablica->setColumnWidth(5,100);
    ui->tablica->setColumnWidth(6,200);


    ui->tablica_2->setColumnWidth(7,100);
    ui->tablica_2->setColumnWidth(8,150);
    ui->tablica_2->setColumnWidth(9,150);
    ui->tablica_2->setColumnWidth(10,100);
    ui->tablica_2->setColumnWidth(11,100);
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_Open_triggered()
{
    on_Create_triggered();
    QString P, p;
    int row1 = 0, column = 0, row = 0;
    QString selFilter="All files (*.*)";
    str = QFileDialog::getOpenFileName(this,"Open file",QDir::currentPath(),
    "Text files (*.txt);;All files (*.*)",&selFilter);
    QFile file(str);
    if(file.open(QIODevice::ReadOnly|QIODevice::Text))
    {
        QTextStream in(&file);
        while(!in.atEnd())
        {
            P = in.readLine();
            if (P[0] != ' ')
            {
                ui->tablica_3->insertRow(ui->tablica_3->rowCount());
                for (int i = 0; i < P.size(); i++)
                {
                    if((P[i] == '|'))
                    {
                        ui->tablica_3->setItem(row1, column, new QTableWidgetItem(p));
                        column++;
                        p.clear();
                    }
                    else p += P[i];
                }
                ui->tablica_3->setItem(row1, column, new QTableWidgetItem(p));
                index1 = ui->tablica_3->item(row1, 1)->text().toInt();
                name = ui->tablica_3->item(row1, 0)->text();
                street = ui->tablica_3->item(row1, 4)->text();
                sity = ui->tablica_3->item(row1, 3)->text();
                oblast = ui->tablica_3->item(row1, 2)->text();
                hause = ui->tablica_3->item(row1, 5)->text().toInt();
                tel = ui->tablica_3->item(row1, 6)->text();
                L.append(new Restoran(index1, sity, oblast, street, hause, tel, name));
                ui->Restoran_w->addItem(name);
                ui->Restoran_s->addItem(name);
                ui->Restoran_a->addItem(name);

                ui->choise_Restoran_2->addItem(name);
                s++;
                column = 0;
                row1++;
                p.clear();
            }
            else
            {
                ui->tablica->insertRow(ui->tablica->rowCount());
                ui->tablica->setRowHeight(row, 50);
                for (int i = 1; i < P.size(); i++)
                {
                    if((P[i] == '|'))
                    {
                        ui->tablica->setItem(row, column, new QTableWidgetItem(p));
                        column++;
                        if (column == 4)
                        {
                            ui->tablica->setItem(row, column, new QTableWidgetItem(L.getHead()->getRestoran()));
                            column++;
                        }
                        if (column > 7) i = P.size();
                        p.clear();
                    }
                    else p += P[i];
                }
                ui->tablica->setItem(row, column, new QTableWidgetItem(p));
                p.clear();
                QString  sotr = ui->tablica->item(row, 1)->text();
                if ( sotr == "Официант")
                {
                    id = ui->tablica->item(row, 0)->text().toInt();
                    form = ui->tablica->item(row, 2)->text();
                    salary = ui->tablica->item(row, 5)->text().toDouble();
                    age = ui->tablica->item(row, 6)->text();
                    Restoran *Res = L.getTail();
                    adres = ui->tablica->item(row, 4)->text();
                    int l = 0;
                    while(l != L.getCount())
                    {
                        if (Res->getRestoran() == adres) break;
                        l++;
                        Res = Res->getPrev();
                    }
                    Res->getList().append(new waiter(id, form, salary, age));
                }
                else if ( sotr == "Повар")
                {
                    id = ui->tablica->item(row, 0)->text().toInt();
                    form = ui->tablica->item(row, 2)->text();
                    salary = ui->tablica->item(row, 5)->text().toDouble();
                    age = ui->tablica->item(row, 6)->text();

                    Restoran *Res = L.getTail();
                    adres = ui->tablica->item(row, 4)->text();
                    int l = 0;
                    while(l != L.getCount())
                    {
                        if (Res->getRestoran() == adres) break;
                        l++;
                        Res = Res->getPrev();
                    }
                    Res->getList().append(new schef(id, form, salary,  age));
                    n++;
                }
                else if ( sotr == "Охранник")
                {

                        id = ui->tablica->item(row, 0)->text().toInt();
                        form = ui->tablica->item(row, 2)->text();
                        salary = ui->tablica->item(row, 5)->text().toDouble();
                        age = ui->tablica->item(row, 6)->text();

                        Restoran *Res = L.getTail();
                        adres = ui->tablica->item(row, 4)->text();
                        int l = 0;
                        while(l != L.getCount())
                        {
                            if (Res->getRestoran() == adres) break;
                            l++;
                            Res = Res->getPrev();
                        }
                        Res->getList().append(new guard(id, form, salary, age));
                        n++;


                }
                row++;
                column = 0;
            }
        }
        file.close();
        ui->Poisk->setDisabled(0);
        if (L.getCount() != 0) ui->tip->setDisabled(0);
    }
}

void MainWindow::on_Save_triggered()

{
    if (!str.isNull())
    {
        QFile file(str);
        file.open(QFile::WriteOnly|QFile::Truncate);
        file.close();
        Save(str);
    }
    else on_Save_As_triggered();
}

void MainWindow::on_Save_As_triggered()
{
    QString selFilter="All files (*.*)";
    QString str1 = QFileDialog::getSaveFileName(this,"Save file",QDir::currentPath(),
    "Text files (*.txt);;All files (*.*)",&selFilter);
    Save(str1);
    str = str1;
}


int MainWindow::SearchByName(QString name)
{
    Restaurant = L.getHead();
    for (int i = 0; i < L.getCount(); i++)
    {
        if (Restaurant->getName() == name) return 0;
        Restaurant = Restaurant->getNext();
    }
    return 0;
}

void MainWindow::table1(Restoran *Empl, restaurant *Res, int j)
{
    ui->tablica->setItem(j, 0, new QTableWidgetItem(Res->getid()));
    ui->tablica->setItem(j, 1, new QTableWidgetItem(Res->getworker()));
    ui->tablica->setItem(j, 2, new QTableWidgetItem(Res->getform()));
    ui->tablica->setItem(j, 4, new QTableWidgetItem(Empl->getRestoran()));
    ui->tablica->setItem(j, 5, new QTableWidgetItem(Res->getsalary()));
    if (Res->getworker() == "Официант")
    {
        ui->tablica->setItem(j, 6, new QTableWidgetItem(dynamic_cast<waiter*>(Res)->getage()));
    }
    else if (Res->getworker() == "Повар")
    {
        ui->tablica->setItem(j, 6, new QTableWidgetItem(dynamic_cast<schef*>(Res)->getstag()));
    }
    else if (Res->getworker() == "Охранник")
    {
        ui->tablica->setItem(j, 6, new QTableWidgetItem(dynamic_cast<guard*>(Res)->getjeton()));
    }

}

void MainWindow::table2(Restoran *Res, restaurant *Empl, int j)
{
    ui->tablica_2->insertRow(ui->tablica_2->rowCount());
    ui->tablica_2->setRowHeight(j, 50);
    ui->tablica_2->setItem(j, 0, new QTableWidgetItem(Empl->getid()));
    ui->tablica_2->setItem(j, 1, new QTableWidgetItem(Empl->getworker()));
    ui->tablica_2->setItem(j, 2, new QTableWidgetItem(Empl->getform()));
    ui->tablica_2->setItem(j, 4, new QTableWidgetItem(Res->getRestoran()));
    ui->tablica_2->setItem(j, 5, new QTableWidgetItem(Empl->getsalary()));
    if (Empl->getworker() == "Официант")
    {
        ui->tablica_2->setItem(j, 6, new QTableWidgetItem(dynamic_cast<waiter*>(Empl)->getage()));

    }
    else if (Empl->getworker() == "Повар")
    {
        ui->tablica_2->setItem(j, 6, new QTableWidgetItem(dynamic_cast<schef*>(Empl)->getstag()));

    }
    else if (Empl->getworker() == "Охранник")
    {
        ui->tablica_2->setItem(j, 6, new QTableWidgetItem(dynamic_cast<guard*>(Empl)->getjeton()));

    }

}

void MainWindow::table3(Restoran *Res, int j)
{
    ui->tablica_3->setItem(j, 0, new QTableWidgetItem(Res->getName()));
    ui->tablica_3->setItem(j, 1, new QTableWidgetItem(Res->getIndex()));
    ui->tablica_3->setItem(j, 2, new QTableWidgetItem(Res->getOblast()));
    ui->tablica_3->setItem(j, 3, new QTableWidgetItem(Res->getSity()));
    ui->tablica_3->setItem(j, 4, new QTableWidgetItem(Res->getStreet()));
    ui->tablica_3->setItem(j, 5, new QTableWidgetItem(Res->getHause()));
    ui->tablica_3->setItem(j, 6, new QTableWidgetItem(Res->getTel()));
}

int MainWindow::unic_sotr(int id, int n)
{
    if (n != 0)
    {
        Restoran *Res = L.getHead();
        for (int i = 0; i < L.getCount(); i++)
        {
            restaurant *Empl = Res->getList().getHead();
            for (int j = 0; j < Res->getList().getCount(); j++)
            {
                if ((Empl->getid() == QString::number(id)) && (Empl != Employee))
                {
                    QMessageBox::warning(this, "Ошибка", "Данный ID уже существует");
                    return 0;
                }
                Empl = Empl->getNext();
            }
            Res = Res->getNext();
        }
    }
    return 1;
}

int MainWindow::unic_rest(QString name, int s)
{
    if (s != 0)
    {
        Restoran *Res = L.getHead();
        for (int i = 0; i < L.getCount(); i++)
        {
            if ((Res->getName() == name) && (Res != Restaurant))
            {
                QMessageBox::warning(this, "Ошибка", "Данное название уже существует");
                return 0;
            }
            Res = Res->getNext();
        }
    }
    return 1;
}

int MainWindow::SearchById(int id)
{
    Restaurant = L.getHead();
    for (int i = 0; i < L.getCount(); i++)
    {
        Employee = Restaurant->getList().getHead();
        for (int j = 0; j < Restaurant->getList().getCount(); j++)
        {
            if (Employee->getid() == QString::number(id))
            {
                return 0;
            }
            Employee = Employee->getNext();
        }
        Restaurant = Restaurant->getNext();
    }
    return 0;
}


void MainWindow::AddWaiter()
{
    strr = ui->id_w->text();
    if (!strr.size())
    {
        CorrectFlag = false;
        ui->label_id_w->setStyleSheet("QLabel { color : red; }");
    }
    strr = ui->salary_w->text();
    if (!strr.size())
    {
        CorrectFlag = false;
        ui->label_salary_w->setStyleSheet("QLabel { color : red; }");
    }
    strr = ui->age_w->text();
    if (!strr.size())
    {
        CorrectFlag = false;
        ui->label_age_w->setStyleSheet("QLabel { color : red; }");
    }

    if (CorrectFlag == true)
    {
        strr1 = ui->id_w->text();
        if (! check_correct(strr1))
        {
            CorrectFlag1 = false;
            ui->label_id_w->setStyleSheet("QLabel { color : red; }");
        }
        else id = ui->id_w->text().toInt();
        if (!unic_sotr(id, n))
        {
            CorrectFlag1 = false;
            ui->label_id_w->setStyleSheet("QLabel { color : red; }");
        }
        if (ui->form_w->currentIndex() == 0) form = "Официальная";
        else if (ui->form_w->currentIndex() == 1) form = "Свободная";
        else if (ui->form_w->currentIndex() == 2) form = "Рабочая";
        \
        strr1 = ui->salary_w->text();
        if (! check_correct(strr1))
        {
            CorrectFlag1 = false;
            ui->label_salary_w->setStyleSheet("QLabel { color : red; }");
        }
        else salary = ui->salary_w->text().toDouble();
        age = ui->age_w->text();

        currentIndex = ui->Restoran_w->currentIndex();
    }
}

void MainWindow::AddSchef()
{
    strr = ui->id_s->text();
    if (!strr.size())
    {
        CorrectFlag = false;
        ui->label_id_s->setStyleSheet("QLabel { color : red; }");
    }
    strr = ui->salary_s->text();
    if (!strr.size())
    {
        CorrectFlag = false;
        ui->label_salary_s->setStyleSheet("QLabel { color : red; }");
    }
    strr = ui->age_s->text();
    if (!strr.size())
    {
        CorrectFlag = false;
        ui->label_age_s->setStyleSheet("QLabel { color : red; }");
    }

    if (CorrectFlag == true)
    {
        strr1 = ui->id_s->text();
        if (! check_correct(strr1))
        {
            CorrectFlag1 = false;
            ui->label_id_s->setStyleSheet("QLabel { color : red; }");
        }
        else id = ui->id_s->text().toInt();
        if (!unic_sotr(id, n))
        {
            CorrectFlag1 = false;
            ui->label_id_s->setStyleSheet("QLabel { color : red; }");
        }
        if (ui->form_s->currentIndex() == 0) form = "Официальная";
        else if (ui->form_s->currentIndex() == 1) form = "Свободная";
        else if (ui->form_s->currentIndex() == 2) form = "Рабочая";

        strr1 = ui->salary_s->text();
        if (! check_correct(strr1))
        {
            CorrectFlag1 = false;
            ui->label_salary_s->setStyleSheet("QLabel { color : red; }");
        }
        else salary = ui->salary_s->text().toDouble();
        age = ui->age_s->text();


        currentIndex = ui->Restoran_s->currentIndex();
    }
}

void MainWindow::AddGuard()
{
    strr = ui->id_a->text();
    if (!strr.size())
    {
        CorrectFlag = false;
        ui->label_id_a->setStyleSheet("QLabel { color : red; }");
    }
    strr = ui->salary_a->text();
    if (!strr.size())
    {
        CorrectFlag = false;
        ui->label_salary_a->setStyleSheet("QLabel { color : red; }");
    }
    strr = ui->age_a->text();
    if (!strr.size())
    {
        CorrectFlag = false;
        ui->label_age_a->setStyleSheet("QLabel { color : red; }");
    }

    if (CorrectFlag == true)
    {
        strr1 = ui->id_a->text();
        if (! check_correct(strr1))
        {
            CorrectFlag1 = false;
            ui->label_id_a->setStyleSheet("QLabel { color : red; }");
        }
        else id = ui->id_a->text().toInt();
        if (!unic_sotr(id, n))
        {
            CorrectFlag1 = false;
            ui->label_id_a->setStyleSheet("QLabel { color : red; }");
        }
        if (ui->form_a->currentIndex() == 0) form = "Официальная";
        else if (ui->form_a->currentIndex() == 1) form = "Свободная";
        else if (ui->form_a->currentIndex() == 2) form = "Рабочая";

        strr1 = ui->salary_a->text();
        if (! check_correct(strr1))
        {
            CorrectFlag1 = false;
            ui->label_salary_a->setStyleSheet("QLabel { color : red; }");
        }
        else salary = ui->salary_a->text().toDouble();
        age = ui->age_a->text();


        currentIndex = ui->Restoran_a->currentIndex();
    }
}


int MainWindow::check_correct(QString strr)
{
    for (int i = 0; i < strr.size(); i++)
    {
        if ((strr[i] != '.') && (!strr[i].isDigit())) return 0;
    }
    return 1;
}

int MainWindow::check_letter(QString strr)
{
    for (int i = 0; i < strr.size(); i++)
    {
        if (!strr[i].isLetter()) return 0;
    }
    return 1;
}



void MainWindow::on_choise_poisk_activated(int index1)
{
    if (index1 == 1) ui->stackedWidget_2->setCurrentIndex(1);
    else ui->stackedWidget_2->setCurrentIndex(0);
}

void MainWindow::on_add_Restoran_clicked()
{
    ui->add__Restoran->setDisabled(0);
    ui->edit_Restoran_2->setDisabled(0);
    ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_Choose_clicked()
{
    ui->add_w->setDisabled(0);
    ui->add_a->setDisabled(0);
    ui->add_s->setDisabled(0);
    ui->edit_a->setDisabled(1);
    ui->edit_s->setDisabled(1);
    ui->edit_w->setDisabled(1);
    ui->Return->setDisabled(0);
    int x = ui->tip->currentIndex();
    if (x == 0) ui->stackedWidget->setCurrentIndex(1);
    if (x == 1) ui->stackedWidget->setCurrentIndex(2);
    if (x == 2)  ui->stackedWidget->setCurrentIndex(3);
}


void MainWindow::add_Restoran()
{
    strr = ui->oblast_Restoran->text();
    if ((!strr.size()) || (!check_letter(strr)))
    {
        CorrectFlag = false;
        ui->label_oblast->setStyleSheet("QLabel { color : red; }");
    }
    strr = ui->sity_Restoran->text();
    if ((!strr.size()) || (!check_letter(strr)))
    {
        CorrectFlag = false;
        ui->label_sity->setStyleSheet("QLabel { color : red; }");
    }
    strr = ui->street_Restoran->text();
    if ((!strr.size()) || (!check_letter(strr)))
    {
        CorrectFlag = false;
        ui->label_street->setStyleSheet("QLabel { color : red; }");
    }
    strr = ui->hause_Restoran->text();
    if ((!strr.size()) || (! check_correct(strr)))
    {
        CorrectFlag = false;
        ui->label_hause->setStyleSheet("QLabel { color : red; }");
    }
    strr = ui->index_Restoran->text();
    if ((!strr.size()) || (! check_correct(strr)))
    {
        CorrectFlag = false;
        ui->label_index->setStyleSheet("QLabel { color : red; }");
    }
    strr = ui->tel_Restoran->text();
    if ((!strr.size()) || (! check_correct(strr)))
    {
        CorrectFlag = false;
        ui->label_tel->setStyleSheet("QLabel { color : red; }");
    }
    strr = ui->name_Restoran->text();
    if ((!strr.size() || !unic_rest(strr, s)))
    {
        CorrectFlag = false;
        ui->label_name->setStyleSheet("QLabel { color : red; }");
    }
}



void MainWindow::on_add_w_clicked()
{
    ui->Return->setDisabled(1);
    AddWaiter();
    if ((CorrectFlag == true) && (CorrectFlag1 == true))
    {
        int l = 0;
        Restoran* Res = L.getTail();
        while(l != currentIndex)
        {
            Res = Res->getPrev();
            l++;
        }
        Res->getList().append(new waiter(id, form, salary, age));
        restaurant *Empl = Res->getList().getHead();
        ui->tablica->insertRow(ui->tablica->rowCount());
        ui->tablica->setRowHeight(n, 50);
        table1(Res, Empl, n);
        n++;
        ui->form_w->setCurrentIndex(0);

        ui->id_w->clear();
        ui->salary_w->clear();
        ui->age_w->clear();
        ui->stackedWidget->setCurrentIndex(0);
        ui->label_id_w->setStyleSheet("QLabel { color : white; }");
        ui->label_salary_w->setStyleSheet("QLabel { color : white; }");
        ui->label_age_w->setStyleSheet("QLabel { color : white; }");
        ui->Poisk->setDisabled(0);
    }
    if (CorrectFlag1 == false)
    {
        QMessageBox::warning(this, "Ошибка", "Недопустимое значение");
        CorrectFlag1 = true;

    }
    if (CorrectFlag == false)
    {
        QMessageBox::warning(this, "Ошибка", "Все поля должны быть заполнены");

        CorrectFlag = true;
    }
}

void MainWindow::on_add__Restoran_clicked()
{
    ui->Return->setDisabled(1);
    add_Restoran();
    if (CorrectFlag == true)
    {
        oblast = ui->oblast_Restoran->text();
        sity = ui->sity_Restoran->text();
        street = ui->street_Restoran->text();
        hause = ui->hause_Restoran->text().toInt();
        index1 = ui->index_Restoran->text().toInt();
        tel = ui->tel_Restoran->text();
        name = ui->name_Restoran->text();
        L.append(new Restoran(index1, sity, oblast, street, hause, tel, name));
        Restoran *Res = L.getHead();
        ui->tablica_3->insertRow(ui->tablica_3->rowCount());
        table3(Res, s);
        s++;
        ui->Restoran_w->addItem(name);
        ui->Restoran_s->addItem(name);
        ui->Restoran_a->addItem(name);

        ui->choise_Restoran_2->addItem(name);
        ui->oblast_Restoran->clear();
        ui->index_Restoran->clear();
        ui->hause_Restoran->clear();
        ui->sity_Restoran->clear();
        ui->street_Restoran->clear();
        ui->tel_Restoran->clear();
        ui->name_Restoran->clear();
        ui->stackedWidget->setCurrentIndex(0);
        ui->label_oblast->setStyleSheet("QLabel { color : white; }");
        ui->label_sity->setStyleSheet("QLabel { color : white; }");
        ui->label_street->setStyleSheet("QLabel { color : white; }");
        ui->label_hause->setStyleSheet("QLabel { color : white; }");
        ui->label_index->setStyleSheet("QLabel { color : white; }");
        ui->label_tel->setStyleSheet("QLabel { color : white; }");
        ui->label_name->setStyleSheet("QLabel { color : white; }");
        ui->stackedWidget_3->setCurrentIndex(0);
    }
    else
    {
        QMessageBox::warning(this, "Ошибка", "Недопустимое значение");

        CorrectFlag = true;
    }
    if (L.getCount() != 0) ui->tip->setDisabled(0);
}


void MainWindow::on_Delete_clicked()
{
    if (ui->stackedWidget_3->currentIndex() == 1) QMessageBox::warning(this, "Ошибка", "Ошибка");
    else
    {
        QItemSelectionModel *selectionform = ui->tablica->selectionModel();
        if (selectionform->hasSelection())
        {
            itm = ui->tablica->currentRow();
            id = ui->tablica->item(itm, 0)->text().toInt();
            adres = ui->tablica->item(itm, 4)->text();
            ui->tablica->removeRow(itm);
            Restoran *Res = L.getTail();
            for (int i = 0; i < L.getCount(); i++)
            {
                if (Res->getRestoran() == adres)
                {
                    Res->getList().Del(id);
                    break;
                }
                Res = Res->getPrev();
            }
            n--;
            if (n == 0)
            {
                ui->Poisk->setDisabled(1);
            }
        }
        else
        {
            QMessageBox::warning(this, "Ошибка", "Выберите линию");
        }
    }
}

void MainWindow::on_delete_Restoran_clicked()
{
    QItemSelectionModel *selectionform = ui->tablica_3->selectionModel();
    if (selectionform->hasSelection())
    {
        itm = ui->tablica_3->currentRow();
        ui->tablica_3->removeRow(itm);
        s--;
        ui->choise_Restoran_2->removeItem(itm);
        ui->Restoran_w->removeItem(itm);
        ui->Restoran_s->removeItem(itm);
        ui->Restoran_a->removeItem(itm);

        int l = 0;
        Restoran* Res = L.getTail();
        while (l != itm)
        {
            Res = Res->getPrev();
            l++;
        }
        for (int i = 0; i < n; i++)
        {
            if (ui->tablica->item(i, 4)->text() == Res->getRestoran())
            {
                ui->tablica->removeRow(i);
                i--;
                n--;
            }
        }
        L.Del(itm);
        if (L.getCount() == 0)
        {
            ui->Poisk->setDisabled(1);
        }
    }
    else
    {
        QMessageBox::warning(this, "Ошибка", "Выберите линию");
    }
}

void MainWindow::on_Restoran_clicked()
{
    ui->stackedWidget_3->setCurrentIndex(2);
    ui->stackedWidget->setCurrentIndex(6);
    ui->Return->setDisabled(0);
}

void MainWindow::on_Poisk_2_clicked()
{
    ui->stackedWidget_3->setCurrentIndex(1);
    int h = n;
    for (int i = 0; i < h; i++)
    {
        ui->tablica_2->removeRow(i);
        i--;
        h--;
    }
    int f = 0;
    if (ui->choise_poisk->currentIndex() == 0)
    {
        Restoran *Res = L.getTail();
        for (int i = 0; i < L.getCount(); i++)
        {
            restaurant *Empl = Res->getList().getTail();
            for (int j = 0; j < Res->getList().getCount(); j++)
            {
                if (Empl->getid() == ui->Znach->text())
                {
                    table2(Res, Empl, f);
                    f++;
                }
                Empl = Empl->getPrev();
            }
            Res = Res->getPrev();
        }
        f = 0;
    }
    else if (ui->choise_poisk->currentIndex() == 1)
    {
        int l = 0;
        Restoran *Res = L.getTail();
        currentIndex = ui->choise_Restoran_2->currentIndex();
        while(l != currentIndex)
        {
            Res = Res->getPrev();
            l++;
        }
        restaurant *Empl = Res->getList().getTail();
        {
            for (int i = 0; i < Res->getList().getCount(); i++)
            {
                table2(Res, Empl, f);
                f++;
                Empl = Empl->getPrev();
            }
        }
        f = 0;
    }
    else if (ui->choise_poisk->currentIndex() == 2)
    {
        Restoran *Res = L.getTail();
        for (int i = 0; i < L.getCount(); i++)
        {
            restaurant *Empl = Res->getList().getTail();
            for (int j = 0; j < Res->getList().getCount(); j++)
            {
                if (Empl->getworker() == ui->Znach->text())
                {
                    table2(Res, Empl, f);
                    f++;
                }
                Empl = Empl->getPrev();
            }
            Res = Res->getPrev();
        }
        f = 0;
    }
}


void MainWindow::on_add_s_clicked()
{
    ui->Return->setDisabled(1);
    AddSchef();
    if ((CorrectFlag == true) && (CorrectFlag1 == true))
    {
        int l = 0;
        Restoran* Res = L.getTail();
        while(l != currentIndex)
        {
            Res = Res->getPrev();
            l++;
        }
        Res->getList().append(new schef(id, form, salary, age));
        restaurant *Empl = Res->getList().getHead();
        ui->tablica->insertRow(ui->tablica->rowCount());
        ui->tablica->setRowHeight(n, 50);
        table1(Res, Empl, n);
        n++;
        ui->form_s->setCurrentIndex(0);

        ui->id_s->clear();
        ui->salary_s->clear();
        ui->age_s->clear();
        ui->stackedWidget->setCurrentIndex(0);
        ui->label_id_s->setStyleSheet("QLabel { color : white; }");
        ui->label_salary_s->setStyleSheet("QLabel { color : white; }");
        ui->label_age_s->setStyleSheet("QLabel { color : white; }");
        ui->Poisk->setDisabled(0);
    }
    if (CorrectFlag1 == false)
    {
        QMessageBox::warning(this, "Ошибка", "Недопустимое значение");

        CorrectFlag1 = true;
    }
    if (CorrectFlag == false)
    {
        QMessageBox::warning(this, "Ошибка", "Все поля должны быть заполнены");

        CorrectFlag = true;
    }
}

void MainWindow::on_add_a_clicked()
{
    ui->Return->setDisabled(1);
    AddGuard();
    if ((CorrectFlag == true) && (CorrectFlag1 == true))
    {
        int l = 0;
        Restoran* Res = L.getTail();
        while (l != currentIndex)
        {
            Res = Res->getPrev();
            l++;
        }
        Res->getList().append(new guard(id, form, salary, age));
        restaurant *Empl = Res->getList().getHead();
        ui->tablica->insertRow(ui->tablica->rowCount());
        ui->tablica->setRowHeight(n, 50);
        table1(Res, Empl, n);
        n++;
        ui->form_a->setCurrentIndex(0);
        ui->id_a->clear();
        ui->salary_a->clear();
        ui->age_a->clear();

        ui->stackedWidget->setCurrentIndex(0);
        ui->label_id_a->setStyleSheet("QLabel { color : white; }");
        ui->label_salary_a->setStyleSheet("QLabel { color : white; }");
        ui->label_age_a->setStyleSheet("QLabel { color : white; }");

        ui->Poisk->setDisabled(0);
    }
    if (CorrectFlag1 == false)
    {
        QMessageBox::warning(this, "Ошибка", "Недопустимое значение");

        CorrectFlag1 = true;
    }
    if (CorrectFlag == false)
    {
        QMessageBox::warning(this, "Ошибка", "Все поля должны быть заполнены");

        CorrectFlag = true;
    }
}


void MainWindow::on_edit_Restoran_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
    ui->edit_Restoran->setDisabled(0);
    ui->add__Restoran->setDisabled(1);
    itm = ui->tablica_3->currentRow();
    ui->index_Restoran->setText(ui->tablica_3->item(itm, 1)->text());
    ui->name_Restoran->setText(ui->tablica_3->item(itm, 0)->text());
    ui->street_Restoran->setText(ui->tablica_3->item(itm, 4)->text());
    ui->sity_Restoran->setText(ui->tablica_3->item(itm, 3)->text());
    ui->oblast_Restoran->setText(ui->tablica_3->item(itm, 2)->text());
    ui->hause_Restoran->setText(ui->tablica_3->item(itm, 5)->text());
    ui->tel_Restoran->setText(ui->tablica_3->item(itm, 6)->text());
    SearchByName(ui->tablica_3->item(itm, 0)->text());
}

void MainWindow::on_edit_w_clicked()
{
    AddWaiter();
    if (k1 != currentIndex)
    {
        Restaurant->getList().Del(id1);
        if ((CorrectFlag == true) && (CorrectFlag1 == true))
        {
            int l = 0;
            Restoran* Res = L.getTail();
            while(l != currentIndex)
            {
                Res = Res->getPrev();
                l++;
            }
            Res->getList().append(new waiter(id, form, salary, age));
            restaurant *Empl = Res->getList().getHead();
            table1(Res, Empl, itm);
            ui->form_w->setCurrentIndex(0);

            ui->id_w->clear();
            ui->salary_w->clear();
            ui->age_w->clear();
            ui->label_id_w->setStyleSheet("QLabel { color : white; }");
            ui->label_salary_w->setStyleSheet("QLabel { color : white; }");
            ui->label_age_w->setStyleSheet("QLabel { color : white; }");
            ui->add_w->setDisabled(0);
            ui->edit_w->setDisabled(1);
            ui->stackedWidget->setCurrentIndex(0);
        }
        if (CorrectFlag1 == false)
        {
            CorrectFlag1 = true;
            QMessageBox::warning(this, "Ошибка", "Недопустимое значение");
        }
        if (CorrectFlag == false)
        {
            CorrectFlag = true;
            QMessageBox::warning(this, "Ошибка", "Все поля должны быть заполнены");
        }
    }
    else
    {
        if ((CorrectFlag == true) && (CorrectFlag1 == true))
        {
            restaurant *Res = new waiter(id, form, salary, age);
            if (Restaurant->getList().getCount() != 1)
            {
                Employee->getPrev()->setNext(Res);
                Employee->getNext()->setPrev(Res);
                Res->setNext(Employee->getNext());
                Res->setPrev(Employee->getPrev());
            }
            else
            {
                Res->setNext(Res);
                Res->setPrev(Res);
            }
            if (Restaurant->getList().getHead() == Employee) Restaurant->getList().setHead(Res);
            if (Restaurant->getList().getTail() == Employee) Restaurant->getList().setTail(Res);
            table1(Restaurant, Res, itm);
            ui->add_w->setDisabled(0);
            ui->edit_w->setDisabled(1);
            ui->stackedWidget->setCurrentIndex(0);
        }
        if (CorrectFlag1 == false)
        {
            CorrectFlag1 = true;
            QMessageBox::warning(this, "Ошибка", "Недопустимое значение");
        }
        if (CorrectFlag == false)
        {
            CorrectFlag = true;
            QMessageBox::warning(this, "Ошибка", "Все поля должны быть заполнены");
        }
    }
}

void MainWindow::on_edit_s_clicked()
{
    AddSchef();
    if (k1 != currentIndex)
    {
        Restaurant->getList().Del(id1);
        if ((CorrectFlag == true) && (CorrectFlag1 == true))
        {
            int l = 0;
            Restoran* Res = L.getTail();
            while(l != currentIndex)
            {
                Res = Res->getPrev();
                l++;
            }
            Res->getList().append(new schef(id, form, salary, age));
            restaurant *Empl = Res->getList().getHead();
            table1(Res, Empl, itm);
            ui->form_s->setCurrentIndex(0);

            ui->id_s->clear();
            ui->salary_s->clear();
            ui->age_s->clear();
            ui->stackedWidget->setCurrentIndex(0);
            ui->label_id_s->setStyleSheet("QLabel { color : white; }");
            ui->label_salary_s->setStyleSheet("QLabel { color : white; }");
            ui->label_age_s->setStyleSheet("QLabel { color : white; }");
            ui->add_s->setDisabled(0);
            ui->edit_s->setDisabled(1);
        }
        if (CorrectFlag1 == false)
        {
            CorrectFlag1 = true;
            QMessageBox::warning(this, "Ошибка", "Недопустимое значение");
        }
        if (CorrectFlag == false)
        {
            CorrectFlag = true;
            QMessageBox::warning(this, "Ошибка", "Все поля должны быть заполнены");
        }
    }
    else
    {
        if ((CorrectFlag == true) && (CorrectFlag1 == true))
        {
            restaurant *Res = new schef(id, form, salary,  age);
            if (Restaurant->getList().getCount() != 1)
            {
                Employee->getPrev()->setNext(Res);
                Employee->getNext()->setPrev(Res);
                Res->setNext(Employee->getNext());
                Res->setPrev(Employee->getPrev());
            }
            else
            {
                Res->setNext(Res);
                Res->setPrev(Res);
            }
            if (Restaurant->getList().getHead() == Employee) Restaurant->getList().setHead(Res);
            if (Restaurant->getList().getTail() == Employee) Restaurant->getList().setTail(Res);
            table1(Restaurant, Res, itm);
            ui->add_s->setDisabled(0);
            ui->edit_s->setDisabled(1);
            ui->stackedWidget->setCurrentIndex(0);
        }
        if (CorrectFlag1 == false)
        {
            CorrectFlag1 = true;
            QMessageBox::warning(this, "Ошибка", "Недопустимое значение");
        }
        if (CorrectFlag == false)
        {
            CorrectFlag = true;
            QMessageBox::warning(this, "Ошибка", "Все поля должны быть заполнены");
        }
    }
}

void MainWindow::on_edit_a_clicked()
{
    AddGuard();
    if (k1 != currentIndex)
    {
        Restaurant->getList().Del(id1);
        if ((CorrectFlag == true) && (CorrectFlag1 == true))
        {
            int l = 0;
            Restoran* Res = L.getTail();
            while (l != currentIndex)
            {
                Res = Res->getPrev();
                l++;
            }
            Res->getList().append(new guard(id, form, salary, age));
            restaurant *Empl = Res->getList().getHead();
            table1(Res, Empl, itm);
            ui->form_a->setCurrentIndex(0);
            ui->id_a->clear();
            ui->salary_a->clear();
            ui->age_a->clear();

            ui->stackedWidget->setCurrentIndex(0);
            ui->label_id_a->setStyleSheet("QLabel { color : white; }");
            ui->label_salary_a->setStyleSheet("QLabel { color : white; }");
            ui->label_age_a->setStyleSheet("QLabel { color : white; }");

            ui->add_a->setDisabled(0);
            ui->edit_a->setDisabled(1);
        }
        if (CorrectFlag1 == false)
        {
            CorrectFlag1 = true;
            QMessageBox::warning(this, "Ошибка", "Недопустимое значение");
        }
        if (CorrectFlag == false)
        {
            CorrectFlag = true;
            QMessageBox::warning(this, "Ошибка", "Все поля должны быть заполнены");
        }
    }
    else
    {
        if ((CorrectFlag == true) && (CorrectFlag1 == true))
        {
            restaurant *Res = new guard(id, form, salary, age);
            if (Restaurant->getList().getCount() != 1)
            {
                Employee->getPrev()->setNext(Res);
                Employee->getNext()->setPrev(Res);
                Res->setNext(Employee->getNext());
                Res->setPrev(Employee->getPrev());
            }
            else
            {
                Res->setNext(Res);
                Res->setPrev(Res);
            }
            if (Restaurant->getList().getHead() == Employee) Restaurant->getList().setHead(Res);
            if (Restaurant->getList().getTail() == Employee) Restaurant->getList().setTail(Res);
            table1(Restaurant, Res, itm);
            ui->add_a->setDisabled(0);
            ui->edit_a->setDisabled(1);
            ui->stackedWidget->setCurrentIndex(0);
        }
        if (CorrectFlag1 == false)
        {
            CorrectFlag1 = true;
            QMessageBox::warning(this, "Ошибка", "Недопустимое значение");
        }
        if (CorrectFlag == false)
        {
            CorrectFlag = true;
            QMessageBox::warning(this, "Ошибка", "Все поля должны быть заполнены");
        }
    }
}


void MainWindow::on_Poisk_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
    ui->Return->setDisabled(0);
}

void MainWindow::on_Return_clicked()
{
    ui->stackedWidget_3->setCurrentIndex(0);
    ui->stackedWidget->setCurrentIndex(0);
    ui->Return->setDisabled(1);
}

void MainWindow::on_Edit_clicked()
{
    QItemSelectionModel *selectionform = ui->tablica->selectionModel();
    if (selectionform->hasSelection())
    {
        ui->edit_w->setDisabled(0);
        ui->edit_s->setDisabled(0);
        ui->edit_a->setDisabled(0);

        ui->add_w->setDisabled(1);
        ui->add_s->setDisabled(1);
        ui->add_a->setDisabled(1);

        itm = ui->tablica->currentRow();
        QString  sotr = ui->tablica->item(itm, 1)->text();
        if ( sotr == "Официант")
        {
            ui->stackedWidget->setCurrentIndex(1);
            ui->id_w->setText(ui->tablica->item(itm, 0)->text());
            if (ui->tablica->item(itm, 2)->text() == "Официальная") ui->form_w->setCurrentIndex(0);
            else if(ui->tablica->item(itm, 2)->text() == "Свободная") ui->form_w->setCurrentIndex(1);
            else if(ui->tablica->item(itm, 2)->text() == "Рабочая") ui->form_w->setCurrentIndex(2);
            ui->salary_w->setText(ui->tablica->item(itm, 5)->text());
            ui->age_w->setText(ui->tablica->item(itm, 6)->text());

            Restoran *Res = L.getTail();
            adres = ui->tablica->item(itm, 4)->text();
            int l = 0;
            while(l != L.getCount())
            {
                if (Res->getRestoran() == adres) break;
                l++;
                Res = Res->getPrev();
            }
            ui->Restoran_w->setCurrentIndex(l);
            k1 = l;
        }
        else if ( sotr == "Повар")
        {
            ui->stackedWidget->setCurrentIndex(2);
            ui->id_s->setText(ui->tablica->item(itm, 0)->text());
            if (ui->tablica->item(itm, 2)->text() == "Официальная") ui->form_s->setCurrentIndex(0);
            else if(ui->tablica->item(itm, 2)->text() == "Свободная") ui->form_s->setCurrentIndex(1);
            else if(ui->tablica->item(itm, 2)->text() == "Рабочая") ui->form_s->setCurrentIndex(2);

            ui->salary_s->setText(ui->tablica->item(itm, 5)->text());
            ui->age_s->setText(ui->tablica->item(itm, 6)->text());

            Restoran *Res = L.getTail();
            adres = ui->tablica->item(itm, 4)->text();
            int l = 0;
            while(l != L.getCount())
            {
                if (Res->getRestoran() == adres) break;
                l++;
                Res = Res->getPrev();
            }
            ui->Restoran_s->setCurrentIndex(l);
            k1 = l; id1 = id;
        }
        else if ( sotr == "Охранник")
        {

                ui->stackedWidget->setCurrentIndex(3);
                ui->id_a->setText(ui->tablica->item(itm, 0)->text());
                if (ui->tablica->item(itm, 2)->text() == "Официальная") ui->form_a->setCurrentIndex(0);
                else if(ui->tablica->item(itm, 2)->text() == "Свободная") ui->form_a->setCurrentIndex(1);
                else if(ui->tablica->item(itm, 2)->text() == "Рабочая") ui->form_a->setCurrentIndex(2);

                ui->salary_a->setText(ui->tablica->item(itm, 5)->text());
                ui->age_a->setText(ui->tablica->item(itm, 6)->text());

                Restoran *Res = L.getTail();
                adres = ui->tablica->item(itm, 4)->text();
                int l = 0;
                while(l != L.getCount())
                {
                    if (Res->getRestoran() == adres) break;
                    l++;
                    Res = Res->getPrev();
                }
                ui->Restoran_a->setCurrentIndex(l);
                k1 = l; id1 = id;
            }


        SearchById(ui->tablica->item(itm, 0)->text().toInt());
        id1 = ui->tablica->item(itm, 0)->text().toInt();
    }
    else
    {
        QMessageBox::warning(this, "Ошибка", "Выберите линию");
    }
}


void MainWindow::Save(QString str1)
{
    QFile file(str1);
    if (file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QTextStream out(&file);
        Restoran *Res = L.getTail();
        for (int i = 0; i < L.getCount(); i++)
        {
            out << Res->getName() << "|"
                << Res->getIndex() << "|"
                << Res->getOblast() << "|"
                << Res->getSity() << "|"
                << Res->getStreet() << "|"
                << Res->getHause() << "|"
                << Res->getTel() << Qt::endl;
            restaurant *Empl = Res->getList().getTail();
            for (int j = 0; j < Res->getList().getCount(); j++)
            {
                out << ' ' << Empl->getid() << "|"
                    << Empl->getworker() << "|"
                    << Empl->getform() << "|"
                    << " |";
                if (Empl->getworker() == "Официант")
                {
                    out << Empl->getsalary() << "|"
                    << dynamic_cast<waiter*>(Empl)->getage() << "|" << Qt::endl;
                }
                else if (Empl->getworker() == "Повар")
                {
                    out << Empl->getsalary() << "|"
                    << dynamic_cast<schef*>(Empl)->getstag() << "|" << Qt::endl;
                }
                else if (Empl->getworker() == "Охранник")
                {
                   out << Empl->getsalary() << "|"
                    << dynamic_cast<guard*>(Empl)->getjeton() << "|" << Qt::endl;

                }

                Empl = Empl->getPrev();
            }
            Res = Res->getPrev();
        }
    }
    else QMessageBox::warning(this, "Ошибка", "Не удалось записать");
}


void MainWindow::on_About_the_program_triggered()
{
    QMessageBox::about(this, "О программе", "Информационно-поисковая система 'Ресторан'\n Автор: Яшин Никита\n email: nikitayashin3@gmail.com");
}

void MainWindow::on_Managment_triggered()
{
    QMessageBox::about(this, "Руководство", "Информационно-поисковая система 'Ресторан'. Руководство по использованию: https://docs.google.com/document/d/1_vbrDfp539HUQJKrrvbI1W1OloaVsIwt/edit?usp=drive_web&ouid=104104070984444668302&rtpof=true\n");
}

void MainWindow::on_Create_triggered()
{
    if (!str.isNull())
    {
        str.clear();
        for (int i = n-1; i >= 0; i--)
        {
            ui->tablica->removeRow(i);
        }
        ui->tip->setDisabled(1);
        n = 0;
        for (int i = s-1; i >= 0; i--)
        {
            ui->tablica_3->removeRow(i);
            ui->Restoran_w->removeItem(i);
            ui->Restoran_s->removeItem(i);
            ui->Restoran_a->removeItem(i);

            ui->choise_Restoran_2->removeItem(i);
            L.Del(i);
        }
        s = 0;
        ui->Return->setDisabled(1);
        ui->edit_w->setDisabled(1); ui->add_w->setDisabled(0);
        ui->edit_s->setDisabled(1); ui->add_s->setDisabled(0);
        ui->edit_a->setDisabled(1); ui->add_a->setDisabled(0);

        ui->edit_Restoran->setDisabled(1); ui->add_Restoran->setDisabled(0);
        ui->Poisk->setDisabled(1);
        ui->stackedWidget->setCurrentIndex(0);
        ui->stackedWidget_2->setCurrentIndex(0);
        ui->stackedWidget_3->setCurrentIndex(0);
    }
    else
        QMessageBox::warning(this, "Ошибка", "Текущий файл не сохранен");
}


void MainWindow::on_edit_Restoran_clicked()
{
    add_Restoran();
    if (CorrectFlag == true)
    {
        oblast = ui->oblast_Restoran->text();
        sity = ui->sity_Restoran->text();
        street = ui->street_Restoran->text();
        hause = ui->hause_Restoran->text().toInt();
        index1 = ui->index_Restoran->text().toInt();
        tel = ui->tel_Restoran->text();
        name = ui->name_Restoran->text();
        Restoran *Res = new Restoran(index1, sity, oblast, street, hause, tel, name);
        if (L.getCount() != 1)
        {
            Restaurant->getPrev()->setNext(Res);
            Restaurant->getNext()->setPrev(Res);
            Res->setNext(Restaurant->getNext());
            Res->setPrev(Restaurant->getPrev());
        }
        else {
            Res->setNext(Res);
            Res->setPrev(Res);
        }
        if (L.getHead() == Restaurant) L.setHead(Res);
        if (L.getTail() == Restaurant) L.setTail(Res);
        table3(Res, itm);
        Res->getList().setCount(Restaurant->getList().getCount());
        Res->getList().setHead(Restaurant->getList().getHead());
        Res->getList().setTail(Restaurant->getList().getTail());
        restaurant *Empl = Res->getList().getHead(), *C = Restaurant->getList().getHead();
        for (int i = 0; i < Res->getList().getCount(); i++)
        {
            Empl->setNext(C->getNext());
            Empl->setPrev(C->getPrev());
            Empl = Empl->getNext();
            C = C->getNext();
        }
        for (int i = 0; i < n; i++)
        {
            QString name1 = ui->tablica->item(i, 4)->text();
            if (name1 == Restaurant->getRestoran()) ui->tablica->setItem(i, 4, new QTableWidgetItem(Res->getRestoran()));
        }
        ui->add__Restoran->setDisabled(0);
        ui->edit_Restoran->setDisabled(1);
        ui->stackedWidget->setCurrentIndex(8);
    }
    else
    {
        CorrectFlag = true;
        QMessageBox::warning(this, "Ошибка", "Неверное значение");
    }
}

void MainWindow::on_Exit_triggered()
{
    QMessageBox::StandardButton reply =
    QMessageBox::question(this, "Выход", "Вы уверены, что хотите выйти из программы?", QMessageBox::Yes | QMessageBox::No);
    if (reply == QMessageBox::Yes)
    {
    QApplication::quit();
    }
    if (reply == QMessageBox::No)
    {
    }


}

