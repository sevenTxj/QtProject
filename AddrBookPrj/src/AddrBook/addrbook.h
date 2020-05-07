#ifndef __ADDR_BOOK_H
#define __ADDR_BOOK_H

#include<QWidget>
#include<QLabel>
#include<QLineEdit>
#include<QTextEdit>
#include<QGridLayout>
#include<QPushButton>
#include<QMessageBox>
#include<QFileDialog>

#include "findDialog.h"

class AddrBook : public QWidget
{
    Q_OBJECT
public:
    AddrBook(QWidget *parent=0);

    enum Mode{NavigationMode,AddMode,EditMode};

public slots:
    void addContact();
    void submitContact();
    void cancel();
    void next();
    void previous();
    void editContact();
    void removeContact();
    void saveToFile();
    void loadFromFile();

private slots:
    void findContact();


private:
    QLineEdit *nameLine;
    QTextEdit *addrText;
    QPushButton *addButton;
    QPushButton *submitButton;
    QPushButton *cancelButton;
    QPushButton *nextButton;
    QPushButton *preButton;
    QPushButton *editButton;
    QPushButton *removeButton;
    QPushButton *findButton;
    QPushButton *loadButton;
    QPushButton *saveButton;

    Mode curretMode;

    QMap<QString,QString> contacts;
    QString oldName;
    QString oldAddr;

    FindDialog *dialog;

    void updateInterface(Mode mode);
};


#endif
