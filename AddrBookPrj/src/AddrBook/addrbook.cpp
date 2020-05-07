
#include "addrbook.h"

AddrBook::AddrBook(QWidget *parent):QWidget(parent)
{
    QLabel *nameLabel = new QLabel(tr("Name:"));
    nameLine = new QLineEdit;

    QLabel *addrLabel = new QLabel(tr("Address:"));
    addrText = new QTextEdit;

    nameLine->setReadOnly(true);
    addrText->setReadOnly(true);


    addButton = new QPushButton(tr("&Add"));
    addButton->show();

    submitButton = new QPushButton(tr("&Submit"));
    submitButton->hide();

    cancelButton = new QPushButton(tr("&Cancel"));
    cancelButton->hide();

    nextButton = new QPushButton(tr("&Next"));
    nextButton->setEnabled(false);

    preButton = new QPushButton(tr("&Previous"));
    preButton->setEnabled(false);


    editButton = new QPushButton(tr("&Edit"));
    editButton->setEnabled(false);

    removeButton = new QPushButton(tr("&Remove"));
    removeButton->setEnabled(false);

    findButton = new QPushButton(tr("&Find"));
    findButton->setEnabled(false);

    dialog = new FindDialog;

    loadButton = new QPushButton(tr("&Load..."));
    loadButton->setToolTip(tr("Load contacts from file"));  //提示框
    loadButton->setEnabled(false);

    saveButton = new QPushButton(tr("&Save..."));
    saveButton->setToolTip(tr("Save contacts into file"));
    saveButton->setEnabled(false);

    /* 为button设置对应函数 */
    connect(addButton,SIGNAL(clicked()),this,SLOT(addContact()));
    connect(submitButton,SIGNAL(clicked()),this,SLOT(submitContact()));
    connect(cancelButton,SIGNAL(clicked()),this,SLOT(cancel()));
    connect(nextButton,SIGNAL(clicked()),this,SLOT(next()));
    connect(preButton,SIGNAL(clicked()),this,SLOT(previous()));
    connect(editButton,SIGNAL(clicked()),this,SLOT(editContact()));
    connect(removeButton,SIGNAL(clicked()),this,SLOT(removeContact()));
    connect(findButton,SIGNAL(clicked()),this,SLOT(findContact()));
    connect(loadButton,SIGNAL(clicked()),this,SLOT(loadFromFile()));
    connect(saveButton,SIGNAL(clicked()),this,SLOT(saveToFile()));

    /* 添加button到布局 */
    QVBoxLayout *buttonLayout1 = new QVBoxLayout;
    buttonLayout1->addWidget(addButton,Qt::AlignTop);
    buttonLayout1->addWidget(submitButton);
    buttonLayout1->addWidget(cancelButton);
    buttonLayout1->addWidget(editButton);
    buttonLayout1->addWidget(removeButton);
    buttonLayout1->addWidget(findButton);
    buttonLayout1->addWidget(loadButton);
    buttonLayout1->addWidget(saveButton);

    buttonLayout1->addStretch();

    QHBoxLayout *buttonLayout2 = new QHBoxLayout;
    buttonLayout2->addWidget(nextButton);
    buttonLayout2->addWidget(preButton);

    QGridLayout *mainLayout = new QGridLayout;
    mainLayout->addWidget(nameLabel,0,0);
    mainLayout->addWidget(nameLine,0,1);
    mainLayout->addWidget(addrLabel,1,0,Qt::AlignTop);
    mainLayout->addWidget(addrText,1,1);
    mainLayout->addLayout(buttonLayout1,1,2);
    mainLayout->addLayout(buttonLayout2,3,1);

    setLayout(mainLayout);
    setWindowTitle(tr("Simple Addr Book"));
}

void AddrBook::addContact()
{
    QMessageBox::information(this,tr("addContact Mode!"),
                             tr("Current mode is \"%1\"").arg(curretMode));
    oldName = nameLine->text();
    oldAddr = addrText->toPlainText();

    nameLine->clear();
    addrText->clear();

   #if 0

    nameLine->setReadOnly(false);
    nameLine->setFocus(Qt::OtherFocusReason);

    addrText->setReadOnly(false);
    addButton->setEnabled(false);

    submitButton->show();
    cancelButton->show();
 #endif

    updateInterface(AddMode);           // 模式设为AddMode
}

void AddrBook::submitContact()
{
    QString name = nameLine->text();
    QString addr = addrText->toPlainText();

    QMessageBox::information(this,tr("Mode!"),
                             tr("Current mode is \"%1\"").arg(curretMode));

    if(name == "" || addr == "")
    {
        QMessageBox::information(this,tr("Empty Field"),tr("please enter a name and addr."));
        return ;
    }

    if(curretMode == AddMode)            // 添加模式
    {
        if(!contacts.contains(name))
        {
            contacts.insert(name,addr);
            QMessageBox::information(this,tr("Add Successful!"),
                                     tr("\"%1\" has been added to your addr book").arg(name));
        }
        else
        {
            QMessageBox::information(this,tr("Add Failed!"),
                                     tr("Sorry,\"%l\" is already in your addr book").arg(name));
            return;
        }
    }else if(curretMode == EditMode){     // 修改模式

        if(oldName != name)
        {
            if(!contacts.contains(name))  // 修改后的name也不和contacts中的元素相等
            {
                QMessageBox::information(this,tr("Edit Sucessful"),
                                         tr("\"%1\" has been edited to your addr book").arg(oldName));
                contacts.remove(oldName);
                contacts.insert(name,addr);
            }
            else                          // 修改后的name也和contacts中的元素相等
            {
                QMessageBox::information(this,tr("Edit Failed!"),
                                         tr("Sorry,\"%l\" is already in your addr book").arg(name));
                return;
            }
        }
        else if(oldAddr != addr)          // name值没变，只改变addr
        {
            QMessageBox::information(this,tr("Edit Sucessful"),
                                     tr("\"%1\" has been edited to your addr book").arg(name));
            contacts[name] = addr;
        }
    }

    updateInterface(NavigationMode);      //submit后改为NavigationMode
}

void AddrBook::cancel()
{
    nameLine->setText(oldName);
    nameLine->setReadOnly(true);

    addrText->setText(oldAddr);
    addrText->setReadOnly(true);

    addButton->setEnabled(true);
    submitButton->hide();
    cancelButton->hide();

    int num = contacts.size();
    nextButton->setEnabled(num>1);
    preButton->setEnabled(num>1);
}

void AddrBook::next()
{
    QString name = nameLine->text();
    QMap<QString,QString>::iterator i = contacts.find(name);
    if(i != contacts.end())
    {
        i++;
    }
    if(i == contacts.end())     // 这里不能用else ，否则，到end（）-1后不能回到开始
    {
        i = contacts.begin();
    }

    nameLine->setText(i.key());
    addrText->setText(i.value());
}

void AddrBook::previous()
{
    QString name = nameLine->text();
    QMap<QString,QString>::iterator i = contacts.find(name);
    if(i ==contacts.end())
    {
        nameLine->clear();
        addrText->clear();
        return ;
    }

    if(i ==contacts.begin())
    {
        i = contacts.end();
    }

    i--;
    nameLine->setText(i.key());
    addrText->setText(i.value());
}

void AddrBook::editContact()            // 编辑（修改）
{
    oldName = nameLine->text();
    oldAddr = addrText->toPlainText();
    updateInterface(EditMode);
}

void AddrBook::removeContact()
{
    QString name = nameLine->text();
  //  QString addr = addrText->toPlainText();

    if(contacts.contains(name))
    {
        int button = QMessageBox::question(this,tr("Remoive confirm"),
                                           tr("Are you sure to remove \" %1 \"?").arg(name),
                                           QMessageBox::Yes | QMessageBox::No);

        if(QMessageBox::Yes == button)
        {
            previous();

            contacts.remove(name);
            QMessageBox::information(this,tr("Remove Sucessful"),
                                     tr("\"%1\" has been removed from your addr book").arg(name));

        }
    }

    updateInterface(NavigationMode);
}

void AddrBook::updateInterface(Mode mode)
{
    curretMode = mode;
    switch(curretMode)
    {
    case AddMode:
    case EditMode:
        nameLine->setReadOnly(false);
        nameLine->setFocus(Qt::OtherFocusReason);
        addrText->setReadOnly(false);

        addButton->setEnabled(false);

        nextButton->setEnabled(false);        // 添加完成后才能查询
        preButton->setEnabled(false);

        loadButton->setEnabled(true);         // 可以从文件中加载

        submitButton->show();
        cancelButton->show();

        break;

    case NavigationMode:
        if(contacts.isEmpty())
        {
            nameLine->clear();
            addrText->clear();
        }

        nameLine->setReadOnly(true);
        addrText->setReadOnly(true);
        addButton->setEnabled(true);

        int num = contacts.size();

        editButton->setEnabled(num>=1);
        removeButton->setEnabled(num>=1);

        nextButton->setEnabled(num>1);
        preButton->setEnabled(num>1);

        findButton->setEnabled(num>=1);

        saveButton->setEnabled(num>=1);

        submitButton->hide();
        cancelButton->hide();

        break;

      }
}

void AddrBook::findContact()
{
    dialog->show();

    if(dialog->exec() == QDialog::Accepted)
    {
        QString contactName = dialog->getFindText();
        if(contactName.isEmpty())
        {
            QMessageBox::information(this,tr("Contact Found Failed"),tr("Please enter a find name."));
            return ;
        }

        if(contacts.contains(contactName))
        {
            nameLine->setText(contactName);
            addrText->setText(contacts.value(contactName));
        }
        else
        {
            QMessageBox::information(this,tr("Contact Not Found"),tr("Sorry,\"%1\" is not in your addr Book").arg(contactName));
            return ;
        }
    }
    updateInterface(NavigationMode);
}

void AddrBook::saveToFile()
{
    QString fileName = QFileDialog::getSaveFileName(this,tr("Save Addr Book"),"",tr("Addr Book (*.abk);;All Files(*)"));
    if(fileName.isEmpty())
        return;
    else
    {
        QFile file(fileName);
        if(!file.open(QIODevice::WriteOnly))
        {
            QMessageBox::information(this,tr("Unable to open file"),file.errorString());
            return ;
        }

        QDataStream out(&file);
        out.setVersion(QDataStream::Qt_5_2);
        out<<contacts;
    }
}

void AddrBook::loadFromFile()
{
    QString fileName = QFileDialog::getOpenFileName(this,tr("Open Addr Book"),"",tr("Addr Book (*.abk);All Files(*)"));
    if(fileName.isEmpty())
        return;
    else
    {
        QFile file(fileName);
        if(!file.open(QIODevice::ReadOnly))
        {
            QMessageBox::information(this,tr("Unable to open file"),file.errorString());
            return ;
        }

        QDataStream in(&file);
        in.setVersion(QDataStream::Qt_5_2);

        contacts.empty();
        in>>contacts;
        if(contacts.isEmpty())
        {
            QMessageBox::information(this,tr("No contacts in file"),tr("The file you are attempt to open contains no contact "));
        }
        else
        {
            QMap<QString,QString>::iterator i = contacts.begin();
            nameLine->setText(i.key());
            addrText->setText(i.value());

        }

    }

     updateInterface(NavigationMode);
}
