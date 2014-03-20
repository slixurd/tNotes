#include <QString>
#include "tnotesbutton.h"

tNotesButton::tNotesButton(const QString &image_path,
		int width, int height, QWidget *parent)
	: QPushButton(parent)
{
	setStyleSheet("border-image:url(:" + image_path + ");width:" 
			+ QString::number(width, 10) + "px;height:" 
			+ QString::number(height, 10) + "px;");
}
