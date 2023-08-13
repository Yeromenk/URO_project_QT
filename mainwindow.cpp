
#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(this->ui->on_previousButton, SIGNAL(clicked(bool)), this, SLOT(ShowPage()));
    connect(this->ui->pushButton_3, SIGNAL(clicked(bool)), this, SLOT(ShowSecond()));
    this->ui->tableWidget_2->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    connect(ui->search_button, &QPushButton::clicked, this, &MainWindow::onSearchButtonClicked);

    connect(ui->Filter, &QPushButton::clicked, this, &MainWindow::onFilterButtonClicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::ShowPage()
{
    this->ui->MyWidget->setCurrentIndex(0);
}

void MainWindow::ShowSecond()
{
    this->ui->MyWidget->setCurrentIndex(1);
}

void MainWindow::onSearchButtonClicked()
{
    QString searchText = ui->search_line->text();
    searchInTable(searchText);
}

void MainWindow::searchInTable(const QString &searchText)
{
    int rowCount = ui->tableWidget_2->rowCount();
    int columnCount = ui->tableWidget_2->columnCount();

    for (int row = 0; row < rowCount; ++row) {
        bool rowVisible = false;
        for (int col = 0; col < columnCount; ++col) {
            QTableWidgetItem *item = ui->tableWidget_2->item(row, col);
            if (item) {
                if (item->text().contains(searchText, Qt::CaseInsensitive)) {
                    rowVisible = true;
                    break;
                }
            }
        }
        ui->tableWidget_2->setRowHidden(row, !rowVisible);
    }

}

void MainWindow::onFilterButtonClicked()
{
    QString selectedCategory = ui->Category->currentText();

    if (selectedCategory == "All") {
        for (int row = 0; row < ui->tableWidget_2->rowCount(); ++row) {
            ui->tableWidget_2->setRowHidden(row, false);
        }
    } else {
        filterTableByCategory(selectedCategory);
    }
}

void MainWindow::filterTableByCategory(const QString &category)
{
    int rowCount = ui->tableWidget_2->rowCount();

    for (int row = 0; row < rowCount; ++row) {
        QTableWidgetItem *item = ui->tableWidget_2->item(row, 1);

        if (item && item->text() != category) {
            ui->tableWidget_2->setRowHidden(row, true);
        } else {
            ui->tableWidget_2->setRowHidden(row, false);
        }
    }
}
