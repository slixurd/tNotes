#ifndef TNOTESBUTTON_H
#define TNOTESBUTTON_H

#include <QWidget>
#include <QPushButton>
class QString;

class tNotesButton : public QPushButton
{
	Q_OBJECT

public:
		tNotesButton(const QString &image_path, 
				int width = 28, int height = 28,
				QWidget *parent = 0);

};
#endif
