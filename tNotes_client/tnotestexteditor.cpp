#include <QTextEdit>
#include <QGroupBox>
#include <QVBoxLayout>
#include "tnotestexteditor.h"


tNotesTextEditor::tNotesTextEditor(QWidget *parent)
	: QWidget(parent)
{
	noteEditorGroupBox = new QGroupBox(tr("noteEditor"), this);
	noteEditor = new QTextEdit;
	noteEditor->setMinimumSize(this->width(),
			this->height() * 0.7);

	QVBoxLayout *layout = new QVBoxLayout;
	layout->addWidget(noteEditor, 1);

	noteEditorGroupBox->setLayout(layout);
}
