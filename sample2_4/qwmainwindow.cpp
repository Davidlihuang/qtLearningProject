#include "qwmainwindow.h"
#include "ui_qwmainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    initUI();
    iniSignalSlots();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initUI()
{
    //状态栏上添加组件
    fLabCurFile = new QLabel;
    fLabCurFile->setMinimumWidth(150);
    fLabCurFile->setText("当前文件：");
    ui->statusbar->addWidget(fLabCurFile);//添加到状态栏

    progressBar1 = new QProgressBar;
    progressBar1->setMaximumWidth(200);
    progressBar1->setMinimum(5);
    progressBar1->setMaximum(50);
    progressBar1->setValue(ui->textEdit->font().pointSize());
    ui->statusbar->addWidget(progressBar1); //添加到状态栏

    spinFontSize = new QSpinBox; //文字大小
    spinFontSize->setMinimum(5);
    spinFontSize->setMaximum(50);
    spinFontSize->setValue(ui->textEdit->font().pointSize());
    spinFontSize->setMinimumWidth(50);

    ui->toolBar->addWidget(new QLabel("字体大小"));
    ui->toolBar->addWidget(spinFontSize); //spinBox添加到工具栏

    ui->toolBar->addSeparator();
    ui->toolBar->addWidget(new QLabel("字体"));
    comboFont = new QFontComboBox;
    comboFont->setMinimumWidth(80);
    ui->toolBar->addWidget(comboFont); //comboBox添加到工具栏

    setCentralWidget(ui->textEdit);

}

void MainWindow::on_actFontBold_triggered(bool checked)
{
    QTextCharFormat fmt;
    fmt = ui->textEdit->currentCharFormat();
    if(checked)
    {
        fmt.setFontWeight(QFont::Bold);
    }
    else
    {
        fmt.setFontWeight(QFont::Normal);
    }
    ui->textEdit->mergeCurrentCharFormat(fmt);
}

void MainWindow::on_actFontItalic_triggered(bool checked)
{
    QTextCharFormat fmt;
    fmt = ui->textEdit->currentCharFormat();
    fmt.setFontItalic(checked);
    ui->textEdit->mergeCurrentCharFormat(fmt);
}

void MainWindow::on_actUnderline_triggered(bool checked)
{
    QTextCharFormat fmt;
    fmt = ui->textEdit->currentCharFormat();
    fmt.setFontUnderline(checked);
    ui->textEdit->mergeCurrentCharFormat(fmt);
}

void MainWindow::on_textEdit_copyAvailable(bool b)
{
    ui->actCut->setEnabled(b);
    ui->actCopy->setEnabled(b);
    ui->actPaste->setEnabled(ui->textEdit->canPaste());
}

void MainWindow::on_textEdit_selectionChanged()
{
    //更新粗体，斜体和下划线三种action的checked属性
    QTextCharFormat fmt;
    fmt = ui->textEdit->currentCharFormat();
    ui->actFontItalic->setChecked(fmt.fontItalic()); //斜体
    ui->actFontBold->setChecked(fmt.font().bold());
    ui->actUnderline->setChecked(fmt.fontUnderline());
}

void MainWindow::iniSignalSlots()
{
    connect(spinFontSize, SIGNAL(valueChanged(int)),
            this, SLOT(spinBoxFontSize_valueChanged(int)));
    connect(comboFont, SIGNAL(currentIndexChanged(const QString &)),
            this, SLOT(comboFont_currentIndexChanged(const QString&)));
}

void MainWindow::spinBoxFontSize_valueChanged(int aFontSize)
{
    //改变字体大小
    QTextCharFormat fmt;
    fmt.setFontPointSize(aFontSize);
    ui->textEdit->mergeCurrentCharFormat(fmt);
    progressBar1->setValue(aFontSize);
}

void MainWindow::comboFont_currentIndexChanged(const QString &arg1)
{
    //改变字体样式
    QTextCharFormat fmt;
    fmt.setFontFamily(arg1); //设置字体名称
    ui->textEdit->mergeCurrentCharFormat(fmt);
}
