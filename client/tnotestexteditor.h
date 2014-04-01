#ifndef TEXTEDIT_H
#define TEXTEDIT_H

#include <QWidget>
#include <QMap>
#include <QPointer>
#include <QString>
#include "Operation.h"

class QTextEdit;
class QGroupBox;
class QLabel;
class QToolButton;
class QToolBar;
class QAction;
class QFrame;
class QGridLayout;
class QLineEdit;
class QTimer;
class QThread;
class QTextBrowser;

class tNotesButton;
class tNotesEditLinkDialog;

#define EDIT_MODE 0
#define VIEW_MODE 1

class tNotesTextEditor : public QWidget
{
	Q_OBJECT

public:
		tNotesTextEditor(QWidget *parent = 0);

private:

		QLabel *noteTitle;
		QToolBar *noteToolBar;
		QLabel *noteCreatedTime;
		QLabel *noteLastModifiedTime;
		QGroupBox *noteEditorGroupBox;
        //QTextEdit *noteEditor;
        QTextBrowser *noteEditor;
        QAction *actionUndo;
		QFrame *horizonLine;

        QTimer *autoupdateTimer;
       // QThread *timerThread;

        QString plainText;
        QString htmlText;
		tNotesButton *buttonEdit;

		tNotesButton *buttonBold;
		tNotesButton *buttonItalic;
		tNotesButton *buttonQuotes;
		tNotesButton *buttonUndo;
		tNotesButton *buttonRedo;
		tNotesButton *buttonCode;
		tNotesButton *buttonLink;

        QString title;
        QLineEdit *titleLineEdit;
        QWidget *titleWidget;
        QGridLayout *titleLayout;

        tNotesEditLinkDialog *editLinkDialog;
        int linkCounter;

		bool editMode;

        Article currentArticle;
        string currentArticleId;
        string currentDirId;


private:

		QString getTitle();
		QString getCreatedTime();
		QString getLastModifiedTime();
        QString getEditorContents();
        QString markdown2html(QString articleContents);


        void initWidgets();
		void setTextEditorLayout();
		void setupEditActions();
        void toolsEnabled(bool flags = false);
        void findInArticle(QString);

        void setTextHighLight(QString);
private slots:

		void editModeChange();
		void setBold();
        void setItalic();
        void setCode();
        void setQuote();

        void openLinkDialog();
        void setLink(QString);
        void slotUpdateArticle();
        void updateArticle(string dirId, string articleId);
        void initArticle(string dirId, string articleId, QString searchWord = NULL);

        //bool createArticle();

signals:
        void autoupdate(string dirId, string articleId);
        void updateNoteFinished(string dirId, string articleId);

};

#endif
