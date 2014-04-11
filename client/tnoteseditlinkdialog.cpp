#include <QDialog>
#include <QPushButton>
#include <QLineEdit>
#include <QComboBox>
#include <QLabel>
#include <QGridLayout>
#include <QDialogButtonBox>
#include <QDebug>
#include <QTabWidget>
#include <QBoxLayout>

#include "tnoteseditlinkdialog.h"

tNotesEditLinkDialog::tNotesEditLinkDialog(QWidget* parent)
    : QDialog(parent)
{
    setUpGUI();
    setWindowTitle(tr("User Login"));
    setModal(true);
}

void tNotesEditLinkDialog::setUpGUI()
{
    QHBoxLayout *mainLayout = new QHBoxLayout();
    QWidget *linkWidget = new QWidget();

    QGridLayout *formGridLayout = new QGridLayout();


    labelLink = new QLabel();
    editLink = new QLineEdit(tr("http://"));
    labelLink->setText(tr("Edit the link below:"));

    labelLink->setBuddy(editLink);

    linkButtons = new QDialogButtonBox();
    linkButtons->addButton(QDialogButtonBox::Ok);
    linkButtons->addButton(QDialogButtonBox::Cancel);

    connect(linkButtons->button(QDialogButtonBox::Cancel),
            SIGNAL(clicked()), this, SLOT(close()));
    connect(linkButtons->button(QDialogButtonBox::Ok),
            SIGNAL(clicked()), this, SLOT(slotAcceptLink()));

    formGridLayout->addWidget(labelLink, 0, 0, 1, 2);
    formGridLayout->addWidget(editLink, 1, 0, 1, 2);
    formGridLayout->addWidget(linkButtons, 2, 0, 1, 2);

    linkWidget->setLayout(formGridLayout);
    mainLayout->addWidget(linkWidget);
    setLayout(mainLayout);
}


void tNotesEditLinkDialog::slotAcceptLink()
{

    QString link = editLink->text();
    emit acceptLink(link);
    close();
}



