#include "qwdilogmanual.h"

QWDilogManual::QWDilogManual(QWidget *parent)
    : QDialog(parent)
{
    initUI(); //create ui
    iniSignalSlots(); //connect signal and slots
    setWindowTitle("Form created mannualy");
}

QWDilogManual::~QWDilogManual()
{
    delete chkBoxUnderLine;
    delete chkBoxItalic;
    delete chkBoxBold;
    delete rBtnBlack;
    delete rBtnRed;
    delete rBtnBlue;
    delete btnOK;
    delete btnCancel;
    delete btnClose;
    delete textEdit;
}

void QWDilogManual::initUI()
{
    //create check box: underline, Italic, Bold
    //then horizon
    chkBoxUnderLine = new QCheckBox(tr("Underline"));
    chkBoxItalic    = new QCheckBox(tr("Italic"));
    chkBoxBold      = new QCheckBox(tr("Bold"));
    QHBoxLayout *Hlay1 = new QHBoxLayout();
    Hlay1->addWidget(chkBoxUnderLine);
    Hlay1->addWidget(chkBoxItalic);
    Hlay1->addWidget(chkBoxBold);
    //create color radio button
    rBtnBlack = new QRadioButton(tr("rBtnBlack"));
    rBtnBlack->setChecked(true);
    rBtnRed   = new QRadioButton(tr("rBtnRed"));
    rBtnBlue  = new QRadioButton(tr("rBtnBlue"));
    QHBoxLayout *Hlay2  = new QHBoxLayout();
    Hlay2->addWidget(rBtnBlack);
    Hlay2->addWidget(rBtnRed);
    Hlay2->addWidget(rBtnBlue);
    //create push button
    btnOK     = new QPushButton(tr("Ok"));
    btnCancel = new QPushButton(tr("Cancel"));
    btnClose  = new QPushButton(tr("close"));
    QHBoxLayout *Hlay3  = new QHBoxLayout();
    Hlay3->addStretch();
    Hlay3->addWidget(btnOK);
    Hlay3->addWidget(btnCancel);
    Hlay3->addStretch();
    Hlay3->addWidget(btnClose);
    //create textEdit, and init content
    textEdit = new QPlainTextEdit();
    textEdit->setPlainText("Hello World!\n\nIt is my demo!");
    QFont font = textEdit->font();
    font.setPointSize(20);
    textEdit->setFont(font);

    //create vertical layout and setup the main dialog layout
    QVBoxLayout *VLay = new QVBoxLayout;
    VLay->addLayout(Hlay1);
    VLay->addLayout(Hlay2);
    VLay->addWidget(textEdit);
    VLay->addLayout(Hlay3);
    setLayout(VLay);
}

void QWDilogManual::iniSignalSlots()
{
    //connect checkbox slots function
    connect(chkBoxUnderLine, SIGNAL(clicked(bool)), this, SLOT(on_chkBoxUnderLine(bool)));
    connect(chkBoxItalic, SIGNAL(clicked(bool)), this, SLOT(on_chkBoxItalic(bool)));
    connect(chkBoxBold, SIGNAL(clicked(bool)), this, SLOT(on_chkBoxBold(bool)));
    //connnect radiobox slots function
    connect(rBtnBlack, SIGNAL(clicked()), this, SLOT(setTextFontColor()));
    connect(rBtnRed, SIGNAL(clicked()), this, SLOT(setTextFontColor()));
    connect(rBtnBlue, SIGNAL(clicked()), this, SLOT(setTextFontColor()));
    //connect push button slots function
    connect(btnOK, SIGNAL(clicked()), this, SLOT(accept()));
    connect(btnCancel, SIGNAL(clicked()), this, SLOT(reject()));
    connect(btnClose, SIGNAL(clicked()), this, SLOT(close()));
}

void QWDilogManual::setTextFontColor()
{
    QPalette palet = textEdit->palette();
    if(rBtnRed->isChecked())
    {
        palet.setColor(QPalette::Text, Qt::red);
    }
    else if(rBtnBlack->isChecked())
    {
        palet.setColor(QPalette::Text, Qt::black);
    }
    else if(rBtnBlue->isChecked())
    {
        palet.setColor(QPalette::Text, Qt::blue);
    }
    textEdit->setPalette(palet);
}

void QWDilogManual::on_chkBoxBold(bool checked)
{
    QFont font  = textEdit->font();
    font.setBold(checked);
    textEdit->setFont(font);
}
void QWDilogManual::on_chkBoxItalic(bool checked)
{
    QFont font  = textEdit->font();
    font.setItalic(checked);
    textEdit->setFont(font);
}
void QWDilogManual::on_chkBoxUnderLine(bool checked)
{
    QFont font  = textEdit->font();
    font.setUnderline(checked);
    textEdit->setFont(font);
}
