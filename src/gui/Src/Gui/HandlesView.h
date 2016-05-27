#ifndef HANDLESVIEW_H
#define HANDLESVIEW_H
#include "StdTable.h"
#include <QVBoxLayout>
#include <QSplitter>

class HandlesView : public QWidget
{
    Q_OBJECT
public:
    explicit HandlesView(QWidget* parent = nullptr);
    ~HandlesView();

public slots:
    void reloadData();

    void handlesTableContextMenuSlot(const QPoint & pos);
    void tcpConnectionsTableContextMenuSlot(const QPoint & pos);
    void privilegesTableContextMenuSlot(const QPoint & pos);

    void closeHandleSlot();
    void disablePrivilegeSlot();
    void enablePrivilegeSlot();
    void disableAllPrivilegesSlot();
    void enableAllPrivilegesSlot();

private:
    QVBoxLayout* mVertLayout;
    QSplitter* mSplitter;
    StdTable* mHandlesTable;
    StdTable* mTcpConnectionsTable;
    StdTable* mPrivilegesTable;

    QAction* mActionRefresh;
    QAction* mActionCloseHandle;
    QAction* mActionDisablePrivilege;
    QAction* mActionEnablePrivilege;
    QAction* mActionDisableAllPrivileges;
    QAction* mActionEnableAllPrivileges;

    void enumHandles();
    void enumTcpConnections();
    void enumPrivileges();

    void AppendPrivilege(int row, const char* PrivilegeString);
    QString TcpStateToString(DWORD State);
    HMODULE hIpHlp;
};

#endif // HANDLESVIEW_H