#include <QtGui> 
#include <QGroupBox>
#include <string>
extern QString s2q( const std::string &s);
extern std::string q2s(const QString &s);
class GroupBox :public QGroupBox
{  
public:
	GroupBox();
	void mouseDoubleClickEvent(QMouseEvent *event);   //鼠标点击响应
private:
	//QStandardItemModel是一个多用途的model,可用于表示list,table,tree views所需要的各种不同的数据结构。
	QStandardItemModel *model;
};