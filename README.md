<h1 align="center">Calculator Desktop Application</h1>

<p align="center">
  <img 
    src="https://user-images.githubusercontent.com/78868769/162084768-8d7cff6a-66fd-445d-bea2-458142cce088.png"
  >
</p>

## Introduction
<p align="left">
This is Qt Creator C++ based Desktop Application.
In this application we can perform Addition, Subtraction, Multiplication and Division.
We can also do arithmetic operation of decimal and negative numbers.
</p>

## Tools
* Qt Creator
* Qt Designer
* CSS Style Sheet

## Fratures

* Addition 
* Subtractiion
* Multiplication
* Division
* Percentage

## Logic Used

    private slots:
      void digit_pressed();

      void on_pushButton_decimal_released();

      void unary_operation_pressed();

      void on_pushButton_Cancel_released();
      void on_pushButton_equal_released();

      void binary_operation_pressed();

> * digit_pressed() function takes care of any digit pressed from 0 - 9 and this function append digits when more than one number is entered.
> * on_pushButton_decimal_released() function appends decimal at the appropriate place.
> * unary_operation_pressed() function takes care of positive and negative numbers. It add -ve sign in front of numbers when we chnage positive number to negative
> * on_pushButton_Cancel_released() function clears the screen.
> * binary_operation_pressed() function performs operation between two numbers. Operations performed between numbers are +, -, *, /

### <code>digit_pressed()</code> function

    void MainWindow::digit_pressed()
    {
        QPushButton *button = (QPushButton *)sender();

        double labelNumber;
        QString newLabel;

        if ((ui->pushButton_plus->isChecked() ||
                ui->pushButton_minus->isChecked() ||
                ui->pushButton_multiply->isChecked() ||
                ui->pushButton_divide->isChecked()) && (!userIsTypingSecondNumber))
        {
            labelNumber = button->text().toDouble();
            userIsTypingSecondNumber = true;
             newLabel = QString::number(labelNumber, 'g', 15);
        }
        else
        {
            if (ui->text_area->text().contains('.') && button->text() == "0")
            {
                newLabel = (ui->text_area->text() + button->text());
            }
            else
            {
                labelNumber = (ui->text_area->text() + button->text()).toDouble();
                newLabel = QString::number(labelNumber, 'g', 15);
            }

        }

        ui->text_area->setText(newLabel);
    }
    
    

### <code>on_pushButton_decimal_released()</code> function

    void MainWindow::on_pushButton_decimal_released()
    {
        ui->text_area->setText(ui->text_area->text() + ".");
    }

    void MainWindow::unary_operation_pressed()
    {
        QPushButton *button = (QPushButton *)sender();
        double labelNumber;
        QString newLabel;

        if (button->text() == "+/-")
        {
            labelNumber = ui->text_area->text().toDouble();
            labelNumber = labelNumber * -1;
            newLabel = QString::number(labelNumber, 'g', 15);
            ui->text_area->setText(newLabel);
        }

        if (button->text() == "%")
        {
            labelNumber = ui->text_area->text().toDouble();
            labelNumber = labelNumber * 0.01;
            newLabel = QString::number(labelNumber, 'g', 15);
            ui->text_area->setText(newLabel);
        }
    }
    
    
    
    
### <code>on_pushButton_Cancel_released()</code> function

    void MainWindow::on_pushButton_Cancel_released()
    {
        ui->pushButton_plus->setChecked(false);
        ui->pushButton_minus->setChecked(false);
        ui->pushButton_multiply->setChecked(false);
        ui->pushButton_divide->setChecked(false);

        userIsTypingSecondNumber = false;

        ui->text_area->setText("0");
        ui->text_area_up->setText("");
    }
    
    
    
    
    
### <code>on_pushButton_equal_released()</code> function

    void MainWindow::on_pushButton_equal_released()
    {
        double labelNumber, secondNum;

        secondNum = ui->text_area->text().toDouble();
        QString newLabel;

        if (ui->pushButton_plus->isChecked())
        {
            labelNumber = firstNum + secondNum;
            newLabel = QString::number(labelNumber, 'g', 15);
            ui->text_area->setText(newLabel);
            ui->pushButton_plus->setChecked(false);
        }
        else if (ui->pushButton_minus->isChecked())
        {
            labelNumber = firstNum - secondNum;
            newLabel = QString::number(labelNumber, 'g', 15);
            ui->text_area->setText(newLabel);
            ui->pushButton_minus->setChecked(false);
        }
        else if (ui->pushButton_divide->isChecked())
        {
            labelNumber = firstNum / secondNum;
            newLabel = QString::number(labelNumber, 'g', 15);
            ui->text_area->setText(newLabel);
            ui->pushButton_divide->setChecked(false);
        }
        else if (ui->pushButton_multiply->isChecked())
        {
            labelNumber = firstNum * secondNum;
            newLabel = QString::number(labelNumber, 'g', 15);
            ui->text_area->setText(newLabel);
            ui->pushButton_multiply->setChecked(false);
        }

        userIsTypingSecondNumber = false;
    }
    
    
    
    
### <code>binary_operation_pressed()</code> function

    void MainWindow::binary_operation_pressed()
    {
        QPushButton *button = (QPushButton *)sender();

        firstNum = ui->text_area->text().toDouble();



        if (button->text() == "+")
        {
            ui->text_area_up->setText(ui->text_area->text() + "+");

        }
        else if (button->text() == "-")
        {
            ui->text_area_up->setText(ui->text_area->text() + "-");

        }
        else if (button->text() == "×")
        {
            ui->text_area_up->setText(ui->text_area->text() + "×");

        }
        else if (button->text() == "÷")
        {
            ui->text_area_up->setText(ui->text_area->text() + "÷");
        }

        button->setChecked(true);
    }
