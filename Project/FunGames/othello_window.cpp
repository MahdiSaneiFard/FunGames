#include "othello_window.h"
#include <QVBoxLayout>
#include <QLabel>
/*
OthelloWindow::OthelloWindow(GameClient* cl, QString role, QWidget *parent)
    : QWidget(parent), client(cl), myRole(role) {

    // ۱. چیدمان اصلی عمودی (یک بخش برای اطلاعات، یک بخش برای بازی)
    QVBoxLayout* mainLayout = new QVBoxLayout(this);

    // ۲. برچسب نمایش نوبت و وضعیت
    statusLabel = new QLabel("Waiting for game to update...", this);
    statusLabel->setAlignment(Qt::AlignCenter);
    statusLabel->setStyleSheet("font-size: 18px; font-weight: bold; color: #333;");
    mainLayout->addWidget(statusLabel);

    // ۳. ایجاد گرید ۸ در ۸ برای صفحه بازی
    QGridLayout* grid = new QGridLayout();
    grid->setSpacing(0); // حذف فاصله برای شبیه شدن به صفحه واقعی

    for (int r = 0; r < 8; ++r) {
        for (int c = 0; c < 8; ++c) {
            cells[r][c] = new QPushButton(this);
            cells[r][c]->setFixedSize(60, 60);
            cells[r][c]->setProperty("row", r);
            cells[r][c]->setProperty("col", c);

            // استایل صفحه شطرنجی سبز
            cells[r][c]->setStyleSheet(
                "background-color: #2e7d32; "
                "border: 1px solid #1b5e20;"
                );

            connect(cells[r][c], &QPushButton::clicked, this, &OthelloWindow::onCellClicked);
            grid->addWidget(cells[r][c], r, c);
        }
    }
    mainLayout->addLayout(grid);
    setLayout(mainLayout);
}

void OthelloWindow::onCellClicked() {
    QPushButton* btn = qobject_cast<QPushButton*>(sender());
    int r = btn->property("row").toInt();
    int c = btn->property("col").toInt();

    QJsonObject move;
    move["type"] = "move";
    move["row"] = r;
    move["col"] = c;
    client->sendMessage(move);
}

void OthelloWindow::updateBoard(const QJsonArray& boardData, QString currentTurn) {
    for (int r = 0; r < 8; ++r) {
        QJsonArray rowData = boardData[r].toArray();
        for (int c = 0; c < 8; ++c) {
            int value = rowData[c].toInt();

            if (value == 1) { // Black
                cells[r][c]->setStyleSheet(
                    "background-color: #2e7d32; border: 1px solid #1b5e20; "
                    "color: black; font-size: 40px; border-radius: 0px;"
                    );
                cells[r][c]->setText("●"); // استفاده از کاراکتر دایره بزرگ
            } else if (value == 2) { // White
                cells[r][c]->setStyleSheet(
                    "background-color: #2e7d32; border: 1px solid #1b5e20; "
                    "color: white; font-size: 40px; border-radius: 0px;"
                    );
                cells[r][c]->setText("●");
            } else {
                cells[r][c]->setText("");
            }
        }
    }

    QString statusText = QString("You are: %1 | Current Turn: %2")
                             .arg(myRole)
                             .arg(currentTurn);

    setStatus(statusText);

    this->setEnabled(myRole.toLower() == currentTurn.toLower());
}

void OthelloWindow::setStatus(QString text) {
    statusLabel->setText(text);
}
*/
