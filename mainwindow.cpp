#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <stack>

double result = 0;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QString style = "color: rgb(64, 64, 64); background-color: rgb(255, 204, 229);";
    ui->Num_0->setStyleSheet(style);
    ui->Num_1->setStyleSheet(style);
    ui->Num_2->setStyleSheet(style);
    ui->Num_3->setStyleSheet(style);
    ui->Num_4->setStyleSheet(style);
    ui->Num_5->setStyleSheet(style);
    ui->Num_6->setStyleSheet(style);
    ui->Num_7->setStyleSheet(style);
    ui->Num_8->setStyleSheet(style);
    ui->Num_9->setStyleSheet(style);

    this->setMinimumSize(434,331);
    this->setMaximumSize(434,331);


    ui->line->setAlignment(Qt::AlignRight);

}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_Num_0_clicked()
{
    ui->line->insert(QString::number(0));
}


void MainWindow::on_Num_1_clicked()
{
    ui->line->insert(QString::number(1));
}


void MainWindow::on_Num_2_clicked()
{
    ui->line->insert(QString::number(2));
}


void MainWindow::on_Num_3_clicked()
{
    ui->line->insert(QString::number(3));
}


void MainWindow::on_Num_4_clicked()
{
    ui->line->insert(QString::number(4));

}


void MainWindow::on_Num_5_clicked()
{
    ui->line->insert(QString::number(5));

}


void MainWindow::on_Num_6_clicked()
{
    ui->line->insert(QString::number(6));

}


void MainWindow::on_Num_7_clicked()
{
    ui->line->insert(QString::number(7));

}


void MainWindow::on_Num_8_clicked()
{
    ui->line->insert(QString::number(8));

}


void MainWindow::on_Num_9_clicked()
{
    ui->line->insert(QString::number(9));

}


void MainWindow::on_Divide_clicked()
{
    ui->line->insert(" ÷ ");
}


void MainWindow::on_Multiply_clicked()
{
    ui->line->insert(" × ");
}


void MainWindow::on_Subtract_clicked()
{
    ui->line->insert(" - ");
}


void MainWindow::on_Add_clicked()
{
    ui->line->insert(" + ");
}

void MainWindow::on_Parenthesis_clicked()
{
    static int times = 1;
    if (times % 2 != 0) {
        ui->line->insert("(");
        times++;
    }
    else {
        ui->line->insert(")");
        times++;
    }
}
void MainWindow::on_point_clicked()
{
    ui->line->insert(".");
}

void MainWindow::on_Equals_clicked()
{
    QString text = ui->line->text();
    if (text.isEmpty()) return;

    std::vector<QString> tokens;
    QString currentNumber;

    auto isOperator = [](const QString& op) {
        return op == "+" || op == "-" || op == "×" || op == "÷";
    };


    for (int i = 0; i < text.length(); ++i) {
        QChar c = text[i];

        if (c.isDigit() || c == '.') {
            currentNumber.append(c);
        } else {
            if (!currentNumber.isEmpty()) {
                tokens.push_back(currentNumber);
                currentNumber.clear();
            }

            QString currentChar(c);


            if (c == '(') {
                if (!tokens.empty() && (tokens.back()[0].isDigit() || tokens.back() == ")")) {
                    tokens.push_back("×");
                }
                tokens.push_back("(");
            }
            else if (c == ')') {
                tokens.push_back(")");
            }
            else if (isOperator(currentChar)) {
                tokens.push_back(currentChar);
            }
        }
    }

    if (!currentNumber.isEmpty()) {
        tokens.push_back(currentNumber);
    }


    std::vector<QString> postfix;
    std::stack<QString> opStack;

    auto precedence = [](const QString& op) {
        if (op == "+" || op == "-") return 1;
        if (op == "×" || op == "÷") return 2;
        return 0;
    };

    for (const QString& token : tokens) {
        if (token[0].isDigit() || token.contains('.')) {
            postfix.push_back(token);
        } else if (token == "(") {
            opStack.push(token);
        } else if (token == ")") {
            while (!opStack.empty() && opStack.top() != "(") {
                postfix.push_back(opStack.top());
                opStack.pop();
            }
            if (!opStack.empty()) opStack.pop();
        } else if (isOperator(token)) {
            while (!opStack.empty() && precedence(opStack.top()) >= precedence(token)) {
                postfix.push_back(opStack.top());
                opStack.pop();
            }
            opStack.push(token);
        }
    }

    while (!opStack.empty()) {
        postfix.push_back(opStack.top());
        opStack.pop();
    }


    std::stack<double> evalStack;

    for (const QString& token : postfix) {
        if (token[0].isDigit() || token.contains('.')) {
            evalStack.push(token.toDouble());
        } else {
            if (evalStack.size() < 2) return;
            double b = evalStack.top(); evalStack.pop();
            double a = evalStack.top(); evalStack.pop();

            if (token == "+") evalStack.push(a + b);
            else if (token == "-") evalStack.push(a - b);
            else if (token == "×") evalStack.push(a * b);
            else if (token == "÷") evalStack.push(a / b);
        }
    }


    if (!evalStack.empty()) {
        double result = evalStack.top();
        ui->line->setText(QString::number(result));
    }

}





void MainWindow::on_AC_clicked()
{
    ui->line->setText("");
}


void MainWindow::on_Delete_clicked()
{
    QString text = ui->line->text();
    QString newText = "";

    for (int i = 0; i < text.size() - 1; ++i) {
        newText.append(text[i]);
    }
    ui->line->setText(newText);


}


void MainWindow::on_Switch_clicked()
{
    QString text = ui->line->text();
    int index = text.size()-1;

    while (index > 0) {
        if (text[index] == '+') {
            text[index] = '-';
            break;
        }
        else if (text[index] == '-') {
            text[index] = '+';
            break;
        }
        index--;
    }
    ui->line->setText(text);
}

