#ifndef BOOKMYQITEMDE_H
#define BOOKMYQITEMDE_H
#include <QItemDelegate>
#include <QStyledItemDelegate>
#include <QSize>
#include <QMetaObject>
#include <QPainter>
#include <QStyleOptionViewItem>
#include "Operation.h"
class tnotesbookDelegate:public  QItemDelegate
{
public:
    tnotesbookDelegate(void);
    ~tnotesbookDelegate(void);
	void paint(QPainter*painter,const QStyleOptionViewItem&option, const QModelIndex&index)const ;

	void updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const;  

	virtual void drawFocus( QPainter *painter, const QStyleOptionViewItem &option, const QRect &rect ) const;

};

#endif
