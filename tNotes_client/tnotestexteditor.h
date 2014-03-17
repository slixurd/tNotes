#ifndef TEXTEDIT_H
#define TEXTEDIT_H

#include <QWidget>
#include <QMap>
#include <QPointer>


class QTextEdit;
class QGroupBox;

class tNotesTextEditor : public QWidget
{
	Q_OBJECT

public:
		tNotesTextEditor(QWidget *parent = 0);

private:
		QGroupBox *noteEditorGroupBox;
		QTextEdit *noteEditor;
};

#endif
