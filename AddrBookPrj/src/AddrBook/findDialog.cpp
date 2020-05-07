#include "findDialog.h"


FindDialog::FindDialog(QWidget *parent):QDialog(parent)
{
    QLabel *findLabel  = new QLabel(tr("Enter the name of the contancts:"));
    lineEdit = new QLineEdit;
    findButton = new QPushButton(tr("&Find"));
    findText = "";

    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(findLabel);
    layout->addWidget(lineEdit);
    layout->addWidget(findButton);

    setLayout(layout);
    setWindowTitle(tr("Find a Contact"));

    connect(findButton,SIGNAL(clicked()),this,SLOT(findCliked()));
    connect(findButton,SIGNAL(clicked()),this,SLOT(accept()));
}

void FindDialog::findCliked()
{
    QString text = lineEdit->text();
    if(text.isEmpty())
    {
        QMessageBox::information(this,tr("Empty Failed"),tr("Please enter a name."));
        return;
    }

    findText = text;
    lineEdit->clear();

    //hide();
}

QString FindDialog::getFindText()
{
    return findText;
}



