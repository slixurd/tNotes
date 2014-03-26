#ifndef MYQITEMDE_H
#define MYQITEMDE_H
#include <QItemDelegate>
#include <QStyledItemDelegate>
#include <QSize>
#include <QMetaObject>
#include <QPainter>
#include <QStyleOptionViewItem>
#include "Operation.h"
class MyQItemDelegate:public  QItemDelegate
{
public:
	MyQItemDelegate(void);
	~MyQItemDelegate(void);
	void paint(QPainter*painter,const QStyleOptionViewItem&option, const QModelIndex&index)const ;

	void updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const;  

	virtual void drawFocus( QPainter *painter, const QStyleOptionViewItem &option, const QRect &rect ) const;

};

#endif
