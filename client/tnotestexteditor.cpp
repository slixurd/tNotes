#include <QTextEdit>
#include <QGroupBox>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QLabel>
#include <QToolButton>
#include <QToolBar>
#include <QTextDocument>
#include <QIcon>
#include <QDateTime>
#include <QFont>
#include <QAction>
#include <QFrame>
#include <QLibrary>
#include <QMessageBox>

#include <windows.h>
#include <iostream>
#include <string.h>

#include "tnotestexteditor.h"
#include "tnotesbutton.h"


tNotesTextEditor::tNotesTextEditor(QWidget *parent)
	: QWidget(parent)
{


	//noteEditorGroupBox = new QGroupBox(tr("noteEditor"), this);
	noteEditor = new QTextEdit;
	
	QFont titleFont("Arial", 18, QFont::Bold);
	noteTitle = new QLabel(getTitle());
	noteTitle->setFont(titleFont);

	QFont timeFont("Arial", 8, QFont::Bold);
	noteCreatedTime = new QLabel("Created: " + getCreatedTime());
	noteCreatedTime->setFont(timeFont);
	noteLastModifiedTime = new QLabel("updated: " + getLastModifiedTime());
	noteLastModifiedTime->setFont(timeFont);

	horizonLine = new QFrame();
	horizonLine->setFrameShape(QFrame::HLine);
	horizonLine->setFrameShadow(QFrame::Sunken);

	buttonEdit = new tNotesButton("/myres/edit.png");


	editMode = VIEW_MODE;
	/*   
	QHBoxLayout *tmpLayout = new QHBoxLayout;
	tmpLayout->addWidget(buttonEdit);
	*/

	QWidget *titleWidget = new QWidget;
	QGridLayout *titleLayout = new QGridLayout;
	titleLayout->addWidget(noteTitle, 0, 0, 0, 2);
	titleLayout->addWidget(noteCreatedTime, 0, 1, 0, 2, Qt::AlignJustify);
	//titleLayout->addLayout(tmpLayout, 0, 2, 0, 2);
	titleLayout->addWidget(buttonEdit, 0, 3, 0, 2, Qt::AlignRight);
	titleLayout->addWidget(horizonLine, 1, 0, 2, 0);
	titleLayout->addWidget(noteLastModifiedTime, 2, 4, Qt::AlignRight);
	titleLayout->setContentsMargins(0, 0, 0, 2);
	titleWidget->setLayout(titleLayout);
	titleWidget->setMinimumSize(470, 80);

	QVBoxLayout *layout = new QVBoxLayout;
	layout->addWidget(titleWidget);
	layout->addWidget(noteEditor);
	

    setupEditActions();
	setLayout(layout);
}

void tNotesTextEditor::setupEditActions()
{
    connect(buttonEdit, SIGNAL(clicked()), noteEditor,
            SLOT(editModeChange()));
}

QString tNotesTextEditor::getTitle()
{
	QString ret = "Hello World!";
	return ret;
}

QString tNotesTextEditor::getCreatedTime()
{
	return QDate::currentDate().toString("yyyy.MM.dd");
}

QString tNotesTextEditor::getLastModifiedTime()
{
	return QDate::currentDate().toString("yyyy.MM.dd");
}


QString markdown2html(QString articleContents){
    QLibrary convertLib("/libs/markdown2html.dll");
    std::string result;
    if(convertLib.load()){
        QMessageBox::information(NULL, "OK", "DLL load is OK!");
        typedef std::string (*Fun)(std::string);
        Fun convertFunc = (Fun)convertLib.resolve("markdown2HTML");
        if(convertFunc){
            QMessageBox::information(NULL, "OK", "Function is found");
            result = convertFunc((const char*)articleContents.toLocal8Bit());
            return QString::fromLocal8Bit(result.c_str());
        } else {

            return NULL;
        }
    } else {
        return NULL;
    }

}

void tNotesTextEditor::editModeChange()
{
	if(editMode == EDIT_MODE){
	editMode = VIEW_MODE;
	}
}
