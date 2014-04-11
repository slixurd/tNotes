#ifndef TNOTESEDITLINKDIALOG_H
#define TNOTESEDITLINKDIALOG_H
#include <QDialog>
class QPushButton;
class QLabel;
class QComboBox;
class QDialogButtonBox;
class QLineEdit;
class QString;
class QTabWidget;

class tNotesEditLinkDialog : public QDialog
{
    Q_OBJECT

public:
    tNotesEditLinkDialog(QWidget *parent = 0);
    void setUsername(QString &username);
    void setPassword(QString &password);
    void setUsernamesList(const QStringList &usernames);

private:

    QLabel *labelLink;

    QDialogButtonBox *linkButtons;

    QLineEdit *editLink;

    void setUpGUI();

signals:
    void acceptLink(QString link);

private slots:
    void slotAcceptLink();

};
#endif // TNOTESEDITLINKDIALOG_H
