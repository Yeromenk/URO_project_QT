
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow

{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QString getFindText();

public slots:
    void ShowPage();
    void ShowSecond();
    void onSearchButtonClicked();
    void onFilterButtonClicked();

private:
    Ui::MainWindow *ui;
    QString findText;
    void searchInTable(const QString &searchText);
    void filterTableByCategory(const QString &category);

};

#endif // MAINWINDOW_H

