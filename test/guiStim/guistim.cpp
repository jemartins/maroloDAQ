#include "guistim.h"
#include "ui_guistim.h"

guiStim::guiStim(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::guiStim)
{
    ui->setupUi(this);
    QPalette paleta;

    paleta.setColor(QPalette::Base,Qt::black);
    paleta.setColor(QPalette::Text,Qt::white);
    ui->teLog->setPalette(paleta);
}

guiStim::~guiStim()
{
    delete ui;
}

void guiStim::on_pbExit_clicked()
{
    exit(0);
}

void guiStim::on_pbSend_clicked()
{

}

void guiStim::on_editSendCmd_returnPressed()
{
    
    QByteArray CmdSendline;

    //ui->teLog->append("> "+ui->editSendCmd->text());
    /* Envia para stdout (Debug) o comando a ser escrito na Serial */
    //qDebug() << "TX UART:" << CmdSendUart << endl;

    /*
     * Armazena a string digitada em Comandos em CmdSendUart
     * e remove qualquer tabulação
     */
    CmdSendline = ui->editSendCmd->text().toLatin1().simplified();
    
    /* Limpar o edit do Comandos */
    ui->editSendCmd->clear();
    
    /*
     *  A resposta é enviada para a tela de Log da aplicação
     */
    ui->teLog->append("Question: "+CmdSendline);
    ui->teLog->append("   Answer: ???");
}
