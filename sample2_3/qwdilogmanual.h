#ifndef QWDILOGMANUAL_H
#define QWDILOGMANUAL_H

#include <QDialog>
#include <QCheckBox>
#include <QPushButton>
#include <QRadioButton>
#include <QPlainTextEdit>
#include <QHBoxLayout>
#include <QPalette>
#include <QRgb>
class QWDilogManual : public QDialog
{
    Q_OBJECT
private:
    QCheckBox* chkBoxUnderLine;
    QCheckBox* chkBoxItalic;
    QCheckBox* chkBoxBold;
    QRadioButton* rBtnBlack;
    QRadioButton* rBtnRed;
    QRadioButton* rBtnBlue;
    QPushButton*  btnOK;
    QPushButton*  btnCancel;
    QPushButton*  btnClose;
    QPlainTextEdit* textEdit;
    void initUI(); //创建界面组件
    void iniSignalSlots(); // 关联所有信号与槽
private slots:
    void on_chkBoxUnderLine(bool checked);
    void on_chkBoxItalic(bool checked);
    void on_chkBoxBold(bool checked);
    void setTextFontColor();
public:
    QWDilogManual(QWidget *parent = nullptr);
    ~QWDilogManual();
};
#endif // QWDILOGMANUAL_H
