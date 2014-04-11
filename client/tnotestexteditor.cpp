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
#include <QLineEdit>
#include <QTimer>
#include <QColor>
#include <QDebug>
#include <QTextBrowser>

//#include <windows.h>
#include <iostream>
#include <string.h>

#include "tnotestexteditor.h"
#include "tnotesbutton.h"
#include "tnoteseditlinkdialog.h"
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

/*
 * 初始化textEditor内部Widget
 *
 */
void tNotesTextEditor::initWidgets()
{
    editLinkDialog = new tNotesEditLinkDialog();
    linkCounter = 0;

    //noteEditor = new QTextEdit;
    noteEditor = new QTextBrowser;

    noteEditor->setStyleSheet("background-color:#FFFFFF");

    QFont titleFont("Arial", 18, QFont::Bold);
    noteTitle = new QLabel();
    noteTitle->setFont(titleFont);
    titleLineEdit = new QLineEdit();
    titleLineEdit->setVisible(false);
    titleLineEdit->setStyleSheet(readFile(":/qss/searchLineEdit.qss"));

    QFont timeFont("Arial", 8, QFont::Bold);
    noteCreatedTime = new QLabel("Created: ");
    noteCreatedTime->setFont(timeFont);
    noteLastModifiedTime = new QLabel("Version: ");
    noteLastModifiedTime->setFont(timeFont);

    horizonLine = new QFrame();
    horizonLine->setFrameShape(QFrame::HLine);
    horizonLine->setFrameShadow(QFrame::Sunken);
    QString qstr=readFile(":/qss/editButton.qss");
    buttonEdit = new QPushButton();
    buttonEdit->setStyleSheet(qstr);
    buttonBold = new tNotesButton("/myres/bold.png", 15, 15);
    buttonItalic = new tNotesButton("/myres/italic.png", 15, 15);
    buttonQuotes = new tNotesButton("/myres/quotes.png", 15, 15);
    buttonLink = new tNotesButton("/myres/link.png", 15, 15);
    buttonCode = new tNotesButton("/myres/code.png", 15, 15);
    buttonUndo = new tNotesButton("/myres/undo.png", 15, 15);
    buttonRedo = new tNotesButton("/myres/redo.png", 15, 15);

    buttonUndo->setEnabled(noteEditor->document()->isUndoAvailable());
    buttonRedo->setEnabled(noteEditor->document()->isRedoAvailable());


    editMode = VIEW_MODE;
    noteEditor->setReadOnly(true);
    autoupdateTimer = new QTimer();
    toolsEnabled(false);
}


/*
 * 初始化textEditor布局
 *
 */

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


    titleWidget = new QWidget;
    titleLayout = new QGridLayout;
    titleLayout->addWidget(noteTitle, 0, 0, 2, 1);
    titleLayout->addWidget(titleLineEdit, 0, 0, 2, 1);
    titleLayout->addWidget(noteCreatedTime, 2, 3, Qt::AlignLeft);
	//titleLayout->addLayout(tmpLayout, 0, 2, 0, 2);
    titleLayout->addWidget(buttonEdit, 0, 4, 2, 1, Qt::AlignRight);
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


/*
 * 连接signals与slots
 *
 */
void tNotesTextEditor::setupEditActions()
{
    //点击edit按钮，editmode改变
    connect(buttonEdit, SIGNAL(clicked()), this,
				SLOT(editModeChange()));

    //edit 工具按钮事件响应
    connect(buttonBold, SIGNAL(clicked()), this,
				SLOT(setBold()));
    connect(buttonItalic, SIGNAL(clicked()), this,
                SLOT(setItalic()));
    connect(buttonLink, SIGNAL(clicked()), this,
            SLOT(openLinkDialog()));
    connect(buttonCode, SIGNAL(clicked()), this,
            SLOT(setCode()));
    connect(buttonQuotes, SIGNAL(clicked()), this,
            SLOT(setQuote()));
    connect(editLinkDialog, SIGNAL(acceptLink(QString)), this,
            SLOT(setLink(QString)));


    connect(noteEditor->document(), SIGNAL(undoAvailable(bool)), buttonUndo,
            SLOT(setEnabled(bool)));
    connect(noteEditor->document(), SIGNAL(redoAvailable(bool)), buttonRedo,
            SLOT(setEnabled(bool)));

    connect(buttonUndo, SIGNAL(clicked()), noteEditor,
            SLOT(undo()));
    connect(buttonRedo, SIGNAL(clicked()), noteEditor,
            SLOT(redo()));

    //autoupdate timer
    connect(autoupdateTimer, SIGNAL(timeout()), this, SLOT(slotUpdateArticle()));
    connect(this, SIGNAL(autoupdate(string,string)), this, SLOT(updateArticle(string,string)));

}


/*
 * 返回当前文章标题
 */
QString tNotesTextEditor::getTitle()
{
    //QString ret = "Hello World!";
    if(editMode == EDIT_MODE){
        return titleLineEdit->text();
    } else {
        return noteTitle->text();
    }
   // return ret;
}


/*
 * 返回当前文章内容
 */
QString tNotesTextEditor::getEditorContents()
{
    if(editMode == EDIT_MODE){
        plainText = noteEditor->toPlainText();
        return plainText;
    } else {
        return plainText;
    }
}


/*
 * 获取笔记创建时间
 */
QString tNotesTextEditor::getCreatedTime()
{
    if (currentArticle.createTime.empty()){
        return QDate::currentDate().toString("yyyyMMdd");
    } else {
        return s2q(currentArticle.modifiedTime);
    }
}

/*
 * 获取笔记最后修改时间
 */
QString tNotesTextEditor::getLastModifiedTime()
{
    return s2q(currentArticle.articleId);
}

/*
 * markdown转换为html
 */
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
            std::cout<< in <<std::endl;
            //QMessageBox::information(NULL, "OK", QString::fromLocal8Bit(in.c_str()));
            result = convertFunc(in);
            //QMessageBox::information(NULL, "OK", "Function works well");
            //QMessageBox::information(NULL, "OK", QString::fromLocal8Bit(result.c_str()));
            std::cout<< result << std::endl;
            return s2q(result);// QString::fromStdString(result.c_str());
        } else {
            //QMessageBox::information(NULL, "OK", "Function not found");
            return NULL;
        }
    } else {
        QMessageBox::information(NULL, "OK", "Lib not found");
        return NULL;
    }
}


/*
 * 工具按钮enable
 */
void tNotesTextEditor::toolsEnabled(bool flag)
{
    buttonBold->setEnabled(flag);
    buttonItalic->setEnabled(flag);
    buttonCode->setEnabled(flag);
    buttonLink->setEnabled(flag);
    buttonQuotes->setEnabled(flag);
}

/*
 * viewmode与editmode切换
 */
void tNotesTextEditor::editModeChange()
{
    if(currentDirId == "-1" || currentArticleId == "-1"){
        editMode == VIEW_MODE;
        print("请选择一个笔记进行编辑");
        return;
    }
    updateArticle(currentDirId, currentArticleId);

    if(editMode == EDIT_MODE){

        editMode = VIEW_MODE;
        noteTitle->setText(titleLineEdit->text());
        //print(titleLineEdit->text());
        titleLineEdit->setVisible(false);
        noteTitle->setVisible(true);
        //QMessageBox::information(NULL, "OK", noteEditor->toPlainText());
        plainText = noteEditor->toPlainText();
        noteEditor->setHtml(markdown2html(plainText));
        noteEditor->setReadOnly(true);
        toolsEnabled(false);
    } else {
        editMode = EDIT_MODE;

        //titleLayout->removeWidget(noteTitle);
        noteTitle->setVisible(false);
        titleLineEdit->setText(noteTitle->text());
        titleLineEdit->setVisible(true);
        //titleLayout->addWidget(titleLineEdit, 0, 0, 2, 1);
        //titleWidget->setLayout(titleLayout);

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

void tNotesTextEditor::setCode()
{
    QString s = noteEditor->textCursor().selectedText();
    s = "`" + s + "`";
    noteEditor->textCursor().insertText(s);
    //print(s);
}

void tNotesTextEditor::setQuote()
{
    QString s = noteEditor->textCursor().selectedText();
    s = "> " + s ;
    noteEditor->textCursor().insertText(s);
    //print(s);
}



void tNotesTextEditor::openLinkDialog()
{
    editLinkDialog->exec();
}

void tNotesTextEditor::setLink(QString link)
{
    QString s = noteEditor->textCursor().selectedText();

    char buffer[20];
    _itoa( ++linkCounter, buffer, 10 );
    string count(buffer);


    if(s == NULL){
        s = "[edit alias here]["+ s2q(count) + "]";
    } else {
        s = "["+s+"][" + s2q(count) + "]";
    }

    QString linkText = "  [" + s2q(count) + "]: " + link;
    noteEditor->textCursor().insertText(s);
    noteEditor->append(linkText);
}

/*
 * 格式化日期
 */
QString formatDate(QString date)
{
    QString s = "";
    for(int i = 0; i < date.size(); i ++){
        s += date[i];
        if(i == 3 || i == 5)
            s += "/";
    }
    return s;
}

/*
 * 用户登录时利用本地数据初始化笔记
 */
void tNotesTextEditor::initArticle(string dirId, string articleId, QString searchWord)
{
    if (editMode == EDIT_MODE){
        editMode = VIEW_MODE;
        noteTitle->setVisible(true);
        titleLineEdit->setVisible(false);
    }
    currentArticleId = articleId;
    currentDirId = dirId;
    currentArticle = searchArticle(dirId, articleId);
    //cout<<dirId<<" "<<articleId<<endl;
    noteTitle->setText(s2q(currentArticle.name));
    //cout<<currentArticle.context<<endl;
    plainText = s2q(currentArticle.context);
    //QString content = s2q(plainText);
    //print(content);
    //noteEditor->setHtml("你好");
    noteEditor->setHtml(markdown2html(plainText));
    //cout<<q2s(markdown2html(content))<<endl;

    noteCreatedTime->setText("Created: " + formatDate(s2q(currentArticle.createTime)));
    noteLastModifiedTime->setText("Version: " + s2q(currentArticle.modifiedTime));
    if(searchWord != NULL)
    findInArticle(searchWord);

    autoupdateTimer->setSingleShot(false);
    autoupdateTimer->start(5000);
}

/*
 * 更新笔记在本地存储内容
 * 更新成功后产生信号updateNoteFinished()
 */
void tNotesTextEditor::updateArticle(string dirId, string articleId)
{
    if(currentArticleId == "-1" || currentDirId == "-1") return;
    currentArticle.name = q2s(getTitle());
    currentArticle.context = q2s(getEditorContents());
    currentArticle.createTime = q2s(getCreatedTime());
    currentArticle.modifiedTime = q2s(getLastModifiedTime());
    if(titleLineEdit->isModified()){
        changeArticleName(dirId, articleId, currentArticle.name);
    }
    if(noteEditor->document()->isModified()){   
        changeArticleContent(dirId, articleId, currentArticle.context);
        changeArticleId(dirId, articleId, articleId, q2s(getLastModifiedTime()));
//print("autosaving");
        noteEditor->document()->setModified(false);

    } else {

    }
    emit updateNoteFinished(dirId, articleId);
}

/*
 * 定时器调用的slot，用于自动保存笔记
 */
void tNotesTextEditor::slotUpdateArticle()
{
    emit autoupdate(currentDirId, currentArticleId);
}

void tNotesTextEditor::setTextHighLight(QString targetStr)
{
    int startIndex = 0;
    int endIndex = 0;
    QString htmlContents = markdown2html(s2q(currentArticle.context));
    while(true){
        startIndex = htmlContents.indexOf(targetStr, endIndex);
        if (startIndex == -1){
            break;
        } else {
            QString highlightString = "<span style=\"background: yellow;\">" + targetStr + "</span>";
            htmlContents.replace(startIndex, targetStr.length(), highlightString);
            endIndex = htmlContents.indexOf("</span>", startIndex) + 7;
        }
    }
    //int startIndex = htmlContents.indexOf("hello");
    //QString hightlightString = "<span style=\"background: yellow;\">hello</span>";
    //htmlContents.replace(startIndex, 5, hightlightString);
    noteEditor->setHtml(htmlContents);
    //qDebug()<<"after: "<<endl << noteEditor->toHtml();
}

void tNotesTextEditor::findInArticle(QString word){
    if(editMode == EDIT_MODE){
        updateArticle(currentDirId, currentArticleId);
        editMode = VIEW_MODE;
        QString currentContent = markdown2html(noteEditor->toPlainText());
        noteEditor->setHtml(currentContent);
        noteEditor->setReadOnly(true);
    }
    setTextHighLight(word);
}

void tNotesTextEditor::clearArticle()
{

    if(editMode == EDIT_MODE){
        editMode = VIEW_MODE;
    }

    noteEditor->clear();
    noteTitle->setText("");
    titleLineEdit->setText("");
    noteCreatedTime->setText("Created: ");
    noteLastModifiedTime->setText("Version: ");

    currentArticleId = "-1";
    currentDirId = "-1";

}
