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

//#include <windows.h>
#include <iostream>
#include <string.h>

#include "tnotestexteditor.h"
#include "tnotesbutton.h"
#include "Operation.h"


tNotesTextEditor::tNotesTextEditor(QWidget *parent)
	: QWidget(parent)
{


	//noteEditorGroupBox = new QGroupBox(tr("noteEditor"), this);

    /*
	QHBoxLayout *tmpLayout = new QHBoxLayout;
	tmpLayout->addWidget(buttonEdit);
	*/
    initWidgets();
	setTextEditorLayout();
	setupEditActions();
}



void tNotesTextEditor::initWidgets()
{
    noteEditor = new QTextEdit;
    noteEditor->setStyleSheet("background-color:#FFFFFF");

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
    buttonBold = new tNotesButton("/myres/bold.png", 15, 15);
    buttonItalic = new tNotesButton("/myres/italic.png", 15, 15);
    buttonQuotes = new tNotesButton("/myres/quotes.png", 15, 15);
    buttonLink = new tNotesButton("/myres/link.png", 15, 15);
    buttonCode = new tNotesButton("/myres/code.png", 15, 15);
    buttonUndo = new tNotesButton("/myres/undo.png", 15, 15);
    buttonRedo = new tNotesButton("/myres/redo.png", 15, 15);


    editMode = VIEW_MODE;
    noteEditor->setReadOnly(true);
    toolsEnabled(false);
}

void tNotesTextEditor::setTextEditorLayout()
{

	QHBoxLayout *toolButtonsLayout = new QHBoxLayout;

	toolButtonsLayout->addWidget(buttonBold);
	toolButtonsLayout->addWidget(buttonItalic);
	toolButtonsLayout->addWidget(buttonLink);
	toolButtonsLayout->addWidget(buttonQuotes);
	toolButtonsLayout->addWidget(buttonCode);
	toolButtonsLayout->addWidget(buttonUndo);
	toolButtonsLayout->addWidget(buttonRedo);
	toolButtonsLayout->addStretch();


	QWidget *titleWidget = new QWidget;
	QGridLayout *titleLayout = new QGridLayout;
	titleLayout->addWidget(noteTitle, 0, 0, 0, 2);
	titleLayout->addWidget(noteCreatedTime, 0, 1, 0, 2, Qt::AlignJustify);
	//titleLayout->addLayout(tmpLayout, 0, 2, 0, 2);
	titleLayout->addWidget(buttonEdit, 0, 3, 0, 2, Qt::AlignRight);
	titleLayout->addWidget(horizonLine, 1, 0, 2, 0);
	titleLayout->addLayout(toolButtonsLayout, 2, 0);
	titleLayout->addWidget(noteLastModifiedTime, 2, 4, Qt::AlignRight);
	titleLayout->setContentsMargins(0, 0, 0, 2);
	titleWidget->setLayout(titleLayout);
	titleWidget->setMinimumSize(470, 80);

	QVBoxLayout *layout = new QVBoxLayout;
	layout->addWidget(titleWidget);
	layout->addWidget(noteEditor);

	setLayout(layout);
}

void tNotesTextEditor::setupEditActions()
{
    connect(buttonEdit, SIGNAL(clicked()), this,
				SLOT(editModeChange()));
    connect(buttonBold, SIGNAL(clicked()), this,
				SLOT(setBold()));
    connect(buttonItalic, SIGNAL(clicked()), this,
                SLOT(setItalic()));
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


QString tNotesTextEditor::markdown2html(QString articleContents){

    QLibrary convertLib(tr("markdown2html.dll"));
    std::string result;
    std::string in = "helloworld";
    if(convertLib.load()){
        typedef std::string (__cdecl *Fun)(std::string);
        Fun convertFunc = (Fun)convertLib.resolve("markdown2HTML");
        if(convertFunc){
            //QMessageBox::information(NULL, "OK", "Function is found");
            in = articleContents.toLocal8Bit().constData();
            //QMessageBox::information(NULL, "OK", QString::fromLocal8Bit(in.c_str()));
            result = convertFunc(in);
            //QMessageBox::information(NULL, "OK", "Function works well");
            //QMessageBox::information(NULL, "OK", QString::fromLocal8Bit(result.c_str()));
            return QString::fromStdString(result.c_str());
        } else {
            //QMessageBox::information(NULL, "OK", "Function not found");
            return NULL;
        }
    } else {
        QMessageBox::information(NULL, "OK", "Lib not found");
        return NULL;
    }
}

void tNotesTextEditor::toolsEnabled(bool flag)
{
    buttonBold->setEnabled(flag);
    buttonItalic->setEnabled(flag);
    buttonCode->setEnabled(flag);
    buttonLink->setEnabled(flag);
    buttonQuotes->setEnabled(flag);
}

void tNotesTextEditor::editModeChange()
{
    if(editMode == EDIT_MODE){
        editMode = VIEW_MODE;
        //QMessageBox::information(NULL, "OK", noteEditor->toPlainText());
        plainText = noteEditor->toPlainText();
        noteEditor->setHtml(markdown2html(plainText));
        noteEditor->setReadOnly(true);
        toolsEnabled(false);
    } else {
        editMode = EDIT_MODE;
        toolsEnabled(true);
        noteEditor->setReadOnly(false);
        noteEditor->setPlainText(plainText);

    }
}

void tNotesTextEditor::setBold()
{
	QString s = noteEditor->textCursor().selectedText();
    s = "**" + s + "**";
	noteEditor->textCursor().insertText(s); 
    //print(s);
}

void tNotesTextEditor::setItalic()
{
    QString s = noteEditor->textCursor().selectedText();
    s = "*" + s + "*";
    noteEditor->textCursor().insertText(s);
    //print(s);
}


