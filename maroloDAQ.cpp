/****************************************************************************
 *
 * Project:      maroloDAQ data logger
 *
 *   This program is free software; you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation; either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program; if not, write to the Free Software
 *   Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA
 *
 *
 *   autor: José Eduardo martins
 *   email: jemartins@fis.unb.br
 *          Instituto de Física
 *          Universidade de Brasília
 *   
 * programers: José Eduardo Martins
 *             Rafael Ramos [rafaelframos@gmail.com]
 *             
 ****************************************************************************/

#include "maroloDAQ.h"
#include "ui_maroloDAQ.h"
#include "calibration.h"

#include <QMenu>
#include <QMenuBar>
#include <QStatusBar>
#include <QMessageBox>
#include <QFileDialog>
#include <QElapsedTimer>
#include <unistd.h>
#include <stdlib.h>
#include <iostream>
#include <cstring>
#include <string>
#include <math.h>

maroloDAQ::maroloDAQ(QWidget *parent) :
QMainWindow(parent),
ui(new Ui::maroloDAQ)
{
    ui->setupUi(this);
    
    setWindowTitle(QApplication::translate("maroloDAQ[*]", "maroloDAQ[*]", Q_NULLPTR));

    // Formatando entradas
    formatarEntradas();
    // create new actions and toolbar
    createActions();
    // Procurando por portar seriais abertas
    
    connect(ui->actionSalvar, &QAction::triggered, this, &maroloDAQ::on_actionSalvar_triggered);
    connect(ui->actionSalvar_como, &QAction::triggered, this, &maroloDAQ::on_actionSalvar_como_triggered);    
    connect(ui->actionSalvar_tbox, &QAction::triggered, this, &maroloDAQ::on_actionSalvar_triggered);
    connect(ui->actionSalvar_como_tbox,&QAction::triggered, this, &maroloDAQ::on_actionSalvar_como_triggered);
    connect(ui->teLog->document(), &QTextDocument::contentsChanged, this, &maroloDAQ::documentWasModified);
    
    setCurrentFile(QString());
    setUnifiedTitleAndToolBarOnMac(true);
    ui->teLog->setFocusPolicy(Qt::NoFocus);
    ui->editDevModel->setFocusPolicy(Qt::NoFocus);
    ui->editDevCompiler->setFocusPolicy(Qt::NoFocus);
    ui->btnDevOpen->setFocus();
    
    scanPortas();
    // Configurado stado inicial dos objetos
    setDesconectado();
    // Tudo OK
    statusBar()->showMessage(tr("Pronto. Clique em Conectar"));

}

maroloDAQ::~maroloDAQ()
{
    delete ui;
}

void maroloDAQ::formatarEntradas() {

    // Formatando entradas
    ui->editAngulo1->setValidator(new QIntValidator(-90,90,ui->editAngulo1));
    ui->editAngulo1->setMaxLength(3);

    ui->editAngulo2->setValidator(new QIntValidator(-90,90,ui->editAngulo2));
    ui->editAngulo2->setMaxLength(3);
    
    ui->editErroSensor->setValidator(new QDoubleValidator(0.03,999999,4,ui->editErroSensor));
    ui->editErroSensor->setMaxLength(6);
    
    ui->editDeltaT->setValidator(new QDoubleValidator(0.03,999999,4,ui->editDeltaT));
    ui->editDeltaT->setMaxLength(6);

    ui->editTmax->setValidator(new QDoubleValidator(0.03,9999999,4,ui->editTmax));
    ui->editTmax->setMaxLength(6);
    
    ui->editDevCompiler->setReadOnly(true);
    ui->editDevModel->setReadOnly(true);
     
}

void maroloDAQ::on_btnAppClose_clicked()
{
    // verificar se os dados foram salvos	
    maybeSave();
    exit(0);
}

void maroloDAQ::WriteData(const QByteArray data)
{
    procSerial->Write(data);
}

QString maroloDAQ::ReadData()
{
    QString data = procSerial->Read();
    return data;
}

void maroloDAQ::createActions() {
    
    BaudRateGroup = new QActionGroup(this);
    foreach (QAction* bdaction, ui->menuBaudRate->actions()) {
        BaudRateGroup->addAction(bdaction);
        if (bdaction->text() == "9600") {
            bdaction->setCheckable(true);
            bdaction->setChecked(true);
        } else {
            bdaction->setCheckable(true);
            bdaction->setChecked(false);
        }
    }
     
    const QIcon saveIcon = QIcon::fromTheme("document-save", QIcon(":/images/save.png"));
    ui->actionSalvar->setIcon(saveIcon);
    ui->actionSalvar_tbox->setIcon(saveIcon);
    ui->mainToolBar->addAction(ui->actionSalvar_tbox);

    const QIcon saveasIcon = QIcon::fromTheme("document-save-as", QIcon(":/images/save-as.png"));
    ui->actionSalvar_como->setIcon(saveasIcon);
    ui->actionSalvar_como_tbox->setIcon(saveasIcon);
    ui->mainToolBar->addAction(ui->actionSalvar_como_tbox);
    ui->actionSair->setIcon(QIcon::fromTheme("document-close", QIcon(":/images/close.png")));        
    ui->actionSobre->setIcon(QIcon::fromTheme("help-about", QIcon(":/images/help-about.png")));        
    ui->menuPortas->setIcon(QIcon::fromTheme("code-class", QIcon(":/images/code-class.png")));        
    ui->menuBaudRate->setIcon(QIcon::fromTheme("code-class", QIcon(":/images/code-class.png")));        
    ui->menuFlowControl->setIcon(QIcon::fromTheme("code-class", QIcon(":/images/code-class.png")));        
    ui->actionRecarregar->setIcon(QIcon::fromTheme("quickopen-class", QIcon(":/images/quickopen-class.png")));        
    ui->actionConectar->setIcon(QIcon::fromTheme("irc-channel-active", QIcon(":/images/irc-channel-active.png")));        
    ui->actionDesconectar->setIcon(QIcon::fromTheme("irc-channel-inactive", QIcon(":/images/irc-channel-inactive.png")));        
    ui->mainToolBar->setFloatable(false);
    ui->mainToolBar->setMovable(false);
    
    // teLog is read only
    ui->teLog->setReadOnly(true);
    
} // end createActions

void maroloDAQ::scanPortas() {
    
    QString GetInfoHw;
    QStringList InfoHW;

    // Serials Port Group
    PortasGroup = new QActionGroup(this);
    QStringList myAction_split;
    
    /* Create Object the Class QSerialPort*/
    devserial = new QSerialPort(this);
    /* Create Object the Class comserial to manipulate read/write of the my way */
    procSerial = new comserial(devserial);
    /* Load Device PortSerial available */
    QStringList DispSeriais = procSerial->CarregarDispositivos();
    
    bool statusCloseSerial;
    bool statusOpenSerial;
    
    // algumas variaveis temporarias
    int count = DispSeriais.count();
    QString minhaSerial;
    
    if(count > 0) {
        
        foreach (QAction* action, ui->menuPortas->actions()) {
            PortasGroup->removeAction(action);
            ui->menuPortas->removeAction(action);
        }
        
        foreach (QAction* action, ui->menuBaudRate->actions()) {
            if (action->isChecked()) {
                baudrate = action->text().toInt();
            }    
        }

        for(int i=0;i<count;i++) {
            
            minhaSerial = DispSeriais[i];
            
            statusOpenSerial = procSerial->Conectar(minhaSerial,baudrate);
            
            // aguardando a porta "aquecer" ;_(((
            sleep(2);
            
            if (statusOpenSerial) {
                
                // Se conectou com sucesso no disposito serial
                
                // Enviando comando para obter informações do Device
                WriteData("12\n");
                
                // * Recebendo as informações *
                GetInfoHw = ReadData();
                GetInfoHw = GetInfoHw.simplified();
                
                // * Confirmando se recebeu os dados *
                if( GetInfoHw.size() > 0 ) {
                    
                    // encontrei maroloDAQ
                    minhaSerial = minhaSerial+" [maroloDAQ]";
                }
                
                
                setPortasSeriais(minhaSerial);
                
                statusCloseSerial = procSerial->Desconectar();
                
                if (statusCloseSerial) {
                }
                else {
                    statusBar()->showMessage(tr("### FALHA ao FECHAR Porta Serial!"));
                }
            } else {
                statusBar()->showMessage(tr("### FALHA ao FECHAR Porta Serial!"));
            }
        }
        
        /* 
         * ref.: https://stackoverflow.com/questions/9399840/ \
         * how-to-iterate-through-a-menus-actions-in-qt
         */
        foreach (QAction* action, ui->menuPortas->actions()) {
            PortasGroup->addAction(action);
            
            myAction_split = action->text().split("]");
            if ( myAction_split.length() > 1 ) {
                if (  myAction_split[1] == "maroloDAQ]") {
                    action->setCheckable(true);
                    action->setChecked(true);
                }
            }
            else {
                action->setCheckable(true);
                action->setChecked(false);
            }
        }   
    }
    else {
	statusBar()->showMessage(tr("### Nenhuma porta serial foi detectada!"));
    }
}

void maroloDAQ::setDesconectado() {
    
    // limpando os edits
    ui->editDevCompiler->clear();
    ui->editDevModel->clear();
    ui->editAngulo1->clear();
    ui->editAngulo2->clear();
    ui->editErroSensor->clear();
    ui->editDeltaT->clear();    
    ui->editTmax->clear();

    // habilitando|desabilitando menus|actions
    ui->btnAppClose->setEnabled(true);
    ui->btnDevOpen->setEnabled(true);
    ui->btnDevClose->setEnabled(false);
    ui->gbSensor->setEnabled(true);
    ui->gbTempo->setEnabled(true);
    ui->gbCalibrar->setEnabled(true);
    ui->gbDisplay->setEnabled(true);
    ui->btnCalibrar1->setEnabled(false);
    ui->btnCalibrar2->setEnabled(false);
    ui->cbSensorList->setEnabled(false);
    ui->cbPinoList->setEnabled(false);
    ui->btnIniciar->setEnabled(false);
    ui->btnParar->setEnabled(false);
    ui->actionSair->setEnabled(true);
    ui->actionConectar->setEnabled(true);
    ui->actionDesconectar->setEnabled(false);
    ui->actionRecarregar->setEnabled(true);
    // Actions "Salvar" e "Salvar como" desabilitadas ao btnIniciar
    ui->actionSalvar->setEnabled(false);
    ui->actionSalvar_como->setEnabled(false);
    ui->actionSalvar_tbox->setEnabled(false);
    ui->actionSalvar_como_tbox->setEnabled(false);
    
    ui->editDevCompiler->setEnabled(false);
    ui->editDevModel->setEnabled(false);
    ui->editAngulo1->setEnabled(false);
    ui->editAngulo2->setEnabled(false);
    ui->editErroSensor->setEnabled(false);
    ui->editDeltaT->setEnabled(false);    
    ui->editTmax->setEnabled(false);
    ui->checkBoxGrace->setEnabled(false);

    }

void maroloDAQ::setConectado() {

    // limpando os edits
    ui->editAngulo1->clear();
    ui->editAngulo2->clear();
    ui->editErroSensor->clear();
    ui->editDeltaT->clear();    
    ui->editTmax->clear();
    
    // habilitando|desabilitando menus|actions
    ui->btnAppClose->setEnabled(false);
    ui->btnDevOpen->setEnabled(false);
    ui->btnDevClose->setEnabled(true);
    ui->gbSensor->setEnabled(true);
    ui->gbTempo->setEnabled(true);
    ui->gbCalibrar->setEnabled(true);
    ui->gbDisplay->setEnabled(true);
    ui->btnCalibrar1->setEnabled(false);
    ui->btnCalibrar2->setEnabled(false);
    ui->cbSensorList->setEnabled(true);
    ui->cbPinoList->setEnabled(true);
    // modificado para teste btnIniciar
    ui->btnIniciar->setEnabled(true);
    ui->btnParar->setEnabled(false);
    ui->actionSair->setEnabled(false);
    ui->actionConectar->setEnabled(false);
    ui->actionDesconectar->setEnabled(true);
    ui->actionRecarregar->setEnabled(false);

    ui->editDevCompiler->setEnabled(true);
    ui->editDevModel->setEnabled(true);
    ui->editAngulo1->setEnabled(false);
    ui->editAngulo2->setEnabled(false);
    ui->editErroSensor->setEnabled(true);
    ui->editDeltaT->setEnabled(true);    
    ui->editTmax->setEnabled(true);
    ui->checkBoxGrace->setEnabled(true);
}

void maroloDAQ::maroloDevClose()
{
    bool statusCloseSerial;

    // Serials Port Group
    PortasGroup = new QActionGroup(this);
    // removing all ations in PortasGroup
    QStringList myAction_split;
    
    foreach (QAction* action, ui->menuPortas->actions()) {
        PortasGroup->removeAction(action);
        ui->menuPortas->removeAction(action);
    }
    
    statusCloseSerial = procSerial->Desconectar();
    
    // Descontando a porta serial com sucesso
    // Desabilito os botões Versao, Desconectar, Hardware, Ligar [F10]
    // Habilito Sair e Conectar
    
    if (statusCloseSerial) {
        
        ui->editDevCompiler->clear();
        ui->editDevModel->clear();
        
        setDesconectado();
        
        statusBar()->showMessage(tr("### maroloDAQ Fechado com Sucesso!"));
    }
    else {
        statusBar()->showMessage(tr("### Falha ao fechar maroloDAQ."));
    }
}

void maroloDAQ::on_btnDevOpen_clicked() {
    
    QString GetInfoHw;
    QStringList InfoHW;
    QString devport;
    QStringList devport_list;
    bool statusOpenSerial;

    foreach (QAction* action, ui->menuPortas->actions()) {
        if (action->isChecked()) {
            devport = action->text();
            devport = devport.simplified();
            devport_list = devport.split(" [");
            devport = devport_list[0];
        }    
    }
    
    foreach (QAction* action, ui->menuBaudRate->actions()) {
        if (action->isChecked()) {
            baudrate = action->text().toInt();
        }    
    }

    statusOpenSerial = procSerial->Conectar(devport,baudrate);
    
    /*
     * aguardando a porta "aquecer" ;_(((
     *
     */
    sleep(2);
    
    if (statusOpenSerial) {
        /*
         * Se conectou com sucesso no disposito serial
         * Desabilito o botão Conectar e Sair
         * Habilito Desconectar, Versao, Hardware e Ligar [F10]
         */
        
        // * Enviando comando para obter informações do Device *
        WriteData("12\n");
        // * Recebendo as informações *
        GetInfoHw = ReadData();
        GetInfoHw = GetInfoHw.simplified();
        
        // * Confirmando se recebeu os dados *
        if( GetInfoHw.size() > 0 ) {
            
            
            // * Ex: 4.3.2|UNO
            //  * O que chegou pela serial foi adicionado na variavel GetInfoHW
            //  * então acima removemos qualquer tabulação e abaixo um split
            //  * baseado no caractere |, então sera quebrado em 2 posicoes
            //  * 0 - 4.3.2
            //  * 1 - UNO
            //  *
            InfoHW = GetInfoHw.split("|");
            
            // Inserindo nos devidos Edits
            ui->editDevCompiler->setText(InfoHW[0]);
            ui->editDevModel->setText(InfoHW[1]);
            
            setConectado();
            
        statusBar()->showMessage(tr("### maroloDAQ Aberto com Sucesso!"));
        }
        else {
            QMessageBox::warning(this, tr("maroloDAQ"),
                                 tr("Falha ao Abrir maroloDAQ.\nO maroloDAQ está Conectado?\nRecarregar e Tentar de Novo."));
        }
    }
    else {
        QMessageBox::warning(this, tr("maroloDAQ"),
                             tr("Falha ao Abrir maroloDAQ.\nO maroloDAQ está Conectado?\nRecarregar e Tentar de Novo."));
    }
    
} // end on_btnDevOpen_clicked

void maroloDAQ::on_btnDevClose_clicked() {

    bool statusCloseSerial;
    
    statusCloseSerial = procSerial->Desconectar();
    
    if (statusCloseSerial) {
        setDesconectado();        
        statusBar()->showMessage(tr("### maroloDAQ Fechado com Sucesso!"));
    }
    else {
        statusBar()->showMessage(tr("### Falha ao Fechar maroloDAQ."));
    }
    
    if (GraceIsOpen()) {
        /* Flush the output buffer and close Grace */
        GraceClose();
    }
} // end on_btnDevClose_clicked

void maroloDAQ::on_btnParar_clicked() {
    
    stopFlag = true;
    ui->editErroSensor->setEnabled(true);
    ui->editDeltaT->setEnabled(true);
    ui->editTmax->setEnabled(true);
    ui->btnIniciar->setEnabled(true);
    ui->btnParar->setEnabled(false);
    ui->btnDevClose->setEnabled(true);
    ui->cbPinoList->setEnabled(true);
    ui->cbSensorList->setEnabled(true);

} // end on_btnParar_clicked

void maroloDAQ::on_btnIniciar_clicked() {
    
    if(validarEntradas()) {
        // habilita ou desabilita entradas
        ui->editErroSensor->setEnabled(false);
        ui->editDeltaT->setEnabled(false);
        ui->editTmax->setEnabled(false);
        ui->btnIniciar->setEnabled(false);
        ui->btnParar->setEnabled(true);
        ui->btnDevClose->setEnabled(false);
        ui->cbPinoList->setEnabled(false);
        ui->cbSensorList->setEnabled(false);
        ui->checkBoxGrace->setEnabled(false);
                
        // limpar o QPlainText teLog
        ui->teLog->clear();
        
        // send to Grace?
        if (ui->checkBoxGrace->isChecked()) {
            if (!GraceIsOpen()) {
                /* Start Grace with a buffer size of 4096409640964096 and open the pipe */
                if (GraceOpenVA((char*)"xmgrace", 4096, "-nosafe", "-noask", NULL) == -1) {
                    statusBar()->showMessage(tr("Can't run Grace."));
                } 
            }
        } else {
            if (GraceIsOpen()) {
                GraceClose();
            }
        } // end if checkBoxGrace->isChecked
        
        // inicia medicoes
        stopFlag = false;
        doReadings();
        
    } // end if on_btnIniciar
    
} // end on_btnIniciar_clicked

void maroloDAQ::on_actionSair_triggered() {
    on_btnDevClose_clicked();
    exit(0);
}

void maroloDAQ::on_actionConectar_triggered() {
    
    on_btnDevOpen_clicked();
    
} // end on_actionConectar_triggered

void maroloDAQ::on_actionDesconectar_triggered() {
    
    bool statusCloseSerial;
    
    
    statusCloseSerial = procSerial->Desconectar();
    
    if (statusCloseSerial) {
        setDesconectado();
        statusBar()->showMessage(tr("### maroloDAQ Fechado com Sucesso!"));
    }
    else {
        statusBar()->showMessage(tr("### Falha ao fechar maroloDAQ."));
    }
}

void maroloDAQ::on_actionRecarregar_triggered() {
    
    scanPortas();
    
}

void maroloDAQ::setPortasSeriais(QString myAction) {
    
    //////////////////////////////////////////////////////
    //ref.: http://zetcode.com/gui/qt5/menusandtoolbars/
    QString myAction_spare;
    QString myAction_temp;
    QStringList myAction_split;
    myAction = myAction.simplified();
    myAction_split = myAction.split(" [");
    myAction_temp = myAction_split[0];
    myAction = "/dev/"+myAction;
    
    int ihavename = 0;
    foreach (QAction *action, ui->menuPortas->actions()) {
        if ( !(action->isSeparator()) || !(action->menu()) ) {
            if ( myAction == action->text() ) {
                ihavename = ihavename + 1;
            }
        }
    }
    if ( ihavename == 0 ) {
        if ( myAction_temp == "ttyACM0" ) {
            actionACM0 = new QAction(myAction, this);
            ui->menuPortas->addAction(actionACM0);
            if (myAction_split.length() > 1 ) {
                if ( myAction_split[1] == "maroloDAQ]") {
                    actionACM0->setCheckable(true);
                    actionACM0->setChecked(true);
                }
            }
        }
        if ( myAction_temp == "ttyACM1" ) {
            actionACM1 = new QAction(myAction, this);
            ui->menuPortas->addAction(actionACM1);
            if (myAction_split.length() > 1 ) {
                if ( myAction_split[1] == "maroloDAQ]") {
                    actionACM1->setCheckable(true);
                    actionACM1->setChecked(true);
                }
            }
        }
        if ( myAction_temp == "ttyACM2" ) {
            actionACM2 = new QAction(myAction, this);
            ui->menuPortas->addAction(actionACM2);
            if (myAction_split.length() > 1 ) {
                if ( myAction_split[1] == "maroloDAQ]") {
                    actionACM2->setCheckable(true);
                    actionACM2->setChecked(true);
                }
            }
        }
        if ( myAction_temp == "ttyACM3" ) {
            actionACM3 = new QAction(myAction, this);
            ui->menuPortas->addAction(actionACM3);
            if (myAction_split.length() > 1 ) {
                if ( myAction_split[1] == "maroloDAQ]") {
                    actionACM3->setCheckable(true);
                    actionACM3->setChecked(true);
                }
            }
        }
        if ( myAction_temp == "ttyUSB0" ) {
            actionUSB0 = new QAction(myAction, this);
            ui->menuPortas->addAction(actionUSB0);
            if (myAction_split.length() > 1 ) {
                if ( myAction_split[1] == "maroloDAQ]") {
                    actionUSB0->setCheckable(true);
                    actionUSB0->setChecked(true);
                }
            }
        }
        if ( myAction_temp == "ttyUSB1" ) {
            actionUSB1 = new QAction(myAction, this);
            ui->menuPortas->addAction(actionUSB1);
            if (myAction_split.length() > 1 ) {
                if ( myAction_split[1] == "maroloDAQ]") {
                    actionUSB1->setCheckable(true);
                    actionUSB1->setChecked(true);
                }
            }
        }
        if ( myAction_temp == "ttyUSB2" ) {
            actionUSB2 = new QAction(myAction, this);
            ui->menuPortas->addAction(actionUSB2);
            if (myAction_split.length() > 1 ) {
                if ( myAction_split[1] == "maroloDAQ]") {
                    actionUSB2->setCheckable(true);
                    actionUSB2->setChecked(true);
                }
            }
        }
        if ( myAction_temp == "ttyUSB3" ) {
            actionUSB3 = new QAction(myAction, this);
            ui->menuPortas->addAction(actionUSB3);
            if (myAction_split.length() > 1 ) {
                if ( myAction_split[1] == "maroloDAQ]") {
                    actionUSB3->setCheckable(true);
                    actionUSB3->setChecked(true);
                }
            }
        }
        if (  myAction_temp == "ttyS0") {
            actionS0 = new QAction(myAction, this);
            ui->menuPortas->addAction(actionS0);
            actionS0->setCheckable(true);
        }
        if (  myAction_temp == "ttyS1") {
            actionS2 = new QAction(myAction, this);
            ui->menuPortas->addAction(actionS2);
            actionS2->setCheckable(true);
        }
        if (  myAction_temp == "ttyS3") {
            actionS3 = new QAction(myAction, this);
            ui->menuPortas->addAction(actionS3);
            actionS3->setCheckable(true);
        }
    }

} // end setPortasSeriais

void maroloDAQ::enumerateMenu(QMenu *menu) {
    
    //////////////////////////////////////////////////////
    //ref.: https://stackoverflow.com/questions/9399840/how-to-iterate-through-a-menus-actions-in-qt

    foreach (QAction *action, menu->actions()) {
        
        if (action->isSeparator()) {
        } else if (action->menu()) {
            enumerateMenu(action->menu());
        } else {
        }
    }
}

void maroloDAQ::on_cbSensorList_activated(const QString &arg1) {
    
    if ( arg1 == "Pêndulo" ) {
        ui->editAngulo1->setEnabled(true);
        ui->editAngulo2->setEnabled(true);
    	ui->btnCalibrar1->setEnabled(true);
    	ui->btnCalibrar2->setEnabled(true);
    }
    else {
        ui->editAngulo1->setEnabled(false);
        ui->editAngulo2->setEnabled(false);
    	ui->btnCalibrar1->setEnabled(false);
    	ui->btnCalibrar2->setEnabled(false);
    }
}

bool maroloDAQ::validarEntradas() {
    
    // Se ERRO for menor que zero apresenta mensagem de erro e para operação, senão...
    // Se DeltaT for menor que zero apresenta mensagem de erro e para operação, senão...
    // Se Tmax for menor que zedo apresenta mensagem de erro e para operação, senão...
    // Se Angulo1 ou Angulo 2 for menor que zedo apresenta mensagem de erro e para operação, senão...
    // Tudo ok e continua a operação.
    if(ui->editErroSensor->text().toDouble() <= 0) {
        QMessageBox::warning(this, tr("maroloDAQ"),
                             tr("Por favor, digite o valor do Erro no Sensor. \n"
                             "Digite \"ponto\" para os decimais"));
        ui->editErroSensor->setFocus();
        return false;
    } else {
        if(ui->editDeltaT->text().toDouble() < 0.03) {
            QMessageBox::warning(this, tr("maroloDAQ"),
                                 tr("Por favor, digite o Intervalo de Tempo [ > 0.03s ]. \n"
                                 "Digite \"ponto\" para os decimais"));
            ui->editDeltaT->setFocus();
            return false;
        } else {
            if(ui->editTmax->text().toDouble() <= 0) {
                QMessageBox::warning(this, tr("maroloDAQ"),
                                     tr("Por favor, digite o Tempo Máximo da medição. \n"                                         "Digite \"ponto\" para os decimais"));
                ui->editTmax->setFocus();
                return false;
            } else {
                if (ui->editDeltaT->text().toDouble() > ui->editTmax->text().toDouble()) {
                    QMessageBox::warning(this, tr("maroloDAQ"),                                             tr("Por favor, digite o Tmax maior que Tmax. \n"
                    "Digite \"ponto\" para os decimais"));
                    ui->editDeltaT->setFocus();
                    return false;
                } else {
                    if (ui->cbSensorList->currentText() == "Pêndulo") {
                        if (ui->editAngulo1->text() == NULL) {
                            QMessageBox::warning(this, tr("maroloDAQ"),                                                                             tr("Por favor, digite o Valor do ângulo e Tecle OK. \n"
                            "Digite \"ponto\" para os decimais"));
                            ui->editAngulo1->setFocus();
                            return false;
                        } else {
                            if (ui->editAngulo2->text() == NULL) {
                                QMessageBox::warning(this, tr("maroloDAQ"),                                                 tr("Por favor, digite o Valor do ângulo e Tecle OK. \n"
                                "Digite \"ponto\" para os decimais"));
                                ui->editAngulo2->setFocus();
                                return false;
                            } else {
                                if (calibrationArray[0].voltage == calibrationArray[1].voltage) {
                                    QMessageBox::warning(this, tr("maroloDAQ"),                                                     tr("Falha ao Calibrar. Por favor, refazer a calibragem."));
                                    ui->editAngulo1->setFocus();
                                    return false;
                                } else {
                                    return true;
                                }
                            }
                        }
                    } else {
                        return true;
                    }
                }
            }
        }
    }
} // end validarEntradas

void maroloDAQ::on_btnCalibrar1_clicked() {
    
    double myangle = ui->editAngulo1->text().toDouble();
    angleCalibrate(myangle, 0);
    
}

void maroloDAQ::on_btnCalibrar2_clicked() {

    double myangle = ui->editAngulo2->text().toDouble();
    angleCalibrate(myangle, 1);
    
}

void maroloDAQ::doReadings() {
    
    // Configura myCALL com o valor do pino do Arduino
    QByteArray myCALL = infoCALL();
    
    // dois timers para medicoes
    QElapsedTimer timer;
    QElapsedTimer timer_deltaT;
    
    // variáveis temporárias
    double mysound,myvoltage,myresistence,mytemperature, mylight,myangle;
    // contador
    int cont = 0;
    //intervalo de tempo para as leituras
    double deltaT = ui->editDeltaT->text().toDouble() * 1000;
    // tempo para as leituras
    double Tmax = ui->editTmax->text().toDouble() * 1000;
    // erro indicado no gui para o sensor
    double erroY = ui->editErroSensor->text().toDouble();
    // tolerância no tempo máximo de leitura
    double tolerance = deltaT * 0.1;
    
    // verificando numero de digitos decimais no erroY
    const int ndig = decimalSensor(erroY);
    // convertendo erroY com 1 algarismo significativo
    QString erroY_temp = QString::number(erroY, 'g', 1);
    erroY = erroY_temp.toDouble();
    
    if (GraceIsOpen()) {
        setupGrace();
    }
    
    // inicializando o relogio
    timer.start();
    timer_deltaT.start();
    // instante inicial das medicoes
    double tempo_atual = timer.elapsed();
    // define timeout
    double timeout = Tmax + tolerance;
    
    ui->teLog->appendPlainText("########## início: Dados Adquiridos via maroloDAQ");
    while ( (!timer.hasExpired(timeout)) && (!stopFlag) ) {
        
        // descongelando o GUI
        QCoreApplication::processEvents();
        
        if ( (timer_deltaT.hasExpired(cont * deltaT)) && (!stopFlag) ) {
            
            switch(ui->cbSensorList->currentIndex()) {
                case 0:
                    mysound = readSound(myCALL);
                    mysound = roundValue(mysound, erroY);
                    // formatando Display antes de enviar valores
                    formatDisplay(mysound/10.0, tempo_atual/1000.0, erroY);
                    // Envia o valor medido ao lcdDisplayY
                    ui->lcdDisplayY->display(QString::number(mysound/10.0, 'f', ndig));
                    // Envia o tempo decorrido para o lcdDisplayX
                    ui->lcdDisplayX->display(QString::number(tempo_atual/1000.0, 'f', 2));
                    // Envia ao Console
                    ui->teLog->appendPlainText((QString::number(tempo_atual/1000.0, 'f', 2))+"    "+\
                    (QString::number(mysound/10.0, 'f', ndig))+"    "+\
                    (QString::number(0.01, 'f', 2))+"    "+\
                    (QString::number(erroY, 'f', ndig)));
                    
                    // send to Grace?
                    if (ui->checkBoxGrace->isChecked()) {
                        plotaGrace(tempo_atual/1000.0, mysound/10.0, 0.01, erroY);
                    }
                    break;
                case 1:
                    myvoltage = readVoltage(myCALL);
                    myvoltage = roundValue(myvoltage, erroY);
                    // formatando Display antes de enviar valores
                    formatDisplay(myvoltage/10.0, tempo_atual/1000.0, erroY);
                    // Envia o valor medido ao lcdDisplayY
                    ui->lcdDisplayY->display(QString::number(myvoltage/10.0, 'f', ndig));
                    // Envia o tempo decorrido para o lcdDisplayX
                    ui->lcdDisplayX->display(QString::number(tempo_atual/1000.0, 'f', 2));
                    // Envia ao Console
                    ui->teLog->appendPlainText((QString::number(tempo_atual/1000.0, 'f', 2))+"    "+\
                    (QString::number(myvoltage/10.0, 'f', ndig))+"    "+\
                    (QString::number(0.01, 'f', 2))+"    "+\
                    (QString::number(erroY, 'f', ndig)));
                    
                    // send to Grace?
                    if (ui->checkBoxGrace->isChecked()) {
                        plotaGrace(tempo_atual/1000.0, myvoltage/10.0, 0.01, erroY);
                    }
                    break;
                case 2:
                    myresistence = readResistence(myCALL);
                    myresistence = roundValue(myresistence, erroY);
                    // formatando Display antes de enviar valores
                    formatDisplay(myresistence/10.0, tempo_atual/1000.0, erroY);
                    // Envia o valor medido ao lcdDisplayY
                    ui->lcdDisplayY->display(QString::number(myresistence/10.0, 'f', ndig));
                    // Envia o tempo decorrido para o lcdDisplayX
                    ui->lcdDisplayX->display(QString::number(tempo_atual/1000.0, 'f', 2));
                    // Envia ao Console
                    ui->teLog->appendPlainText((QString::number(tempo_atual/1000.0, 'f', 2))+"    "+\
                    (QString::number(myresistence/10.0, 'f', ndig))+"    "+\
                    (QString::number(0.01, 'f', 2))+"    "+\
                    (QString::number(erroY, 'f', ndig)));
                    
                    // send to Grace?
                    if (ui->checkBoxGrace->isChecked()) {
                        plotaGrace(tempo_atual/1000.0, myresistence/10.0, 0.01, erroY);
                    }
                    break;
                case 3:
                    mytemperature = readTemperature(myCALL);
                    mytemperature = roundValue(mytemperature, erroY);
                    // formatando Display antes de enviar valores
                    formatDisplay(mytemperature/10.0, tempo_atual/1000.0, erroY);
                    // Envia o valor medido ao lcdDisplayY
                    ui->lcdDisplayY->display(QString::number(mytemperature/10.0, 'f', ndig));
                    // Envia o tempo decorrido para o lcdDisplayX
                    ui->lcdDisplayX->display(QString::number(tempo_atual/1000.0, 'f', 2));
                    // Envia ao Console
                    ui->teLog->appendPlainText((QString::number(tempo_atual/1000.0, 'f', 2))+"    "+\
                    (QString::number(mytemperature/10.0, 'f', ndig))+"    "+\
                    (QString::number(0.01, 'f', 2))+"    "+\
                    (QString::number(erroY, 'f', ndig)));
                    
                    // send to Grace?
                    if (ui->checkBoxGrace->isChecked()) {
                        plotaGrace(tempo_atual/1000.0, mytemperature/10.0, 0.01, erroY);
                    }
                    break;
                case 4:
                    mylight = readLight(myCALL);
                    mylight = roundValue(mylight, erroY);
                    // formatando Display antes de enviar valores
                    formatDisplay(mylight/10.0, tempo_atual/1000.0, erroY);
                    // Envia o valor medido ao lcdDisplayY
                    ui->lcdDisplayY->display(QString::number(mylight/10.0, 'f', ndig));
                    // Envia o tempo decorrido para o lcdDisplayX
                    ui->lcdDisplayX->display(QString::number(tempo_atual/1000.0, 'f', 2));
                    // Envia ao Console
                    ui->teLog->appendPlainText((QString::number(tempo_atual/1000.0, 'f', 2))+"    "+\
                    (QString::number(mylight/10.0, 'f', ndig))+"    "+\
                    (QString::number(0.01, 'f', 2))+"    "+\
                    (QString::number(erroY, 'f', ndig)));
                    
                    // send to Grace?
                    if (ui->checkBoxGrace->isChecked()) {
                        plotaGrace(tempo_atual/1000.0, mylight/10.0, 0.01, erroY);
                    }
                    break;
                case 5:
                    myangle = readAngle(myCALL);
                    myangle = roundValue(myangle, erroY);
                    // formatando Display antes de enviar valores
                    formatDisplay(myangle/10.0, tempo_atual/1000.0, erroY);
                    // Envia o valor medido ao lcdDisplayY
                    ui->lcdDisplayY->display(QString::number(myangle/10.0, 'f', ndig));
                    // Envia o tempo decorrido para o lcdDisplayX
                    ui->lcdDisplayX->display(QString::number(tempo_atual/1000.0, 'f', 2));
                    // Envia ao Console
                    ui->teLog->appendPlainText((QString::number(tempo_atual/1000.0, 'f', 2))+"    "+\
                    (QString::number(myangle/10.0, 'f', ndig))+"    "+\
                    (QString::number(0.01, 'f', 2))+"    "+\
                    (QString::number(erroY, 'f', ndig)));
                    
                    // send to Grace?
                    if (ui->checkBoxGrace->isChecked()) {
                        plotaGrace(tempo_atual/1000.0, myangle/10.0, 0.01, erroY);
                    }
                    break;
            } // end switch sensor
            
            cont++;
            if ( (cont % 10 == 0) && (GraceIsOpen()) ) {
                GracePrintf("autoscale");
                GracePrintf("redraw");
            }
        } // end if deltaT
        
        tempo_atual = timer.elapsed();
        
    } // end while timeout
    
    if (GraceIsOpen()) {
	GracePrintf ("yaxis  ticklabel format decimal");
        GracePrintf ("yaxis  ticklabel prec %d", ndig);
        GracePrintf("autoscale");
        GracePrintf("redraw");
    }
    
    ui->teLog->appendPlainText("##########    fim: Dados Adquiridos via maroloDAQ");
    
    // habilitar actionSalvar
    ui->actionSalvar->setEnabled(true);
    ui->actionSalvar_tbox->setEnabled(true);
    
    // GUI é reabilitado
    ui->editErroSensor->setEnabled(true);
    ui->editDeltaT->setEnabled(true);
    ui->editTmax->setEnabled(true);
    ui->btnIniciar->setEnabled(true);
    ui->btnParar->setEnabled(false);
    ui->btnDevClose->setEnabled(true);
    ui->cbPinoList->setEnabled(true);
    ui->cbSensorList->setEnabled(true);
    ui->checkBoxGrace->setEnabled(true);
    
} // end doReadings

QByteArray maroloDAQ::infoCALL() {
    
    // Configura myCALL com o valor do pino do Arduino
    QByteArray myCALL;
    switch(ui->cbPinoList->currentIndex()) {
        case 0:
            // Ler pino A0 no Arduino
            myCALL = "14\n";
            break;
        case 1:
            // Ler pino A1 no Arduino
            myCALL = "15\n";
            break;
        case 2:
            // Ler pino A2 no Arduino
            myCALL = "16\n";
            break;
        case 3:
            // Ler pino A3 no Arduino
            myCALL = "17\n";
            break;
        case 4:
            // Ler pino A4 no Arduino
            myCALL = "18\n";
            break;
        case 5:
            // Ler pino A5 no Arduino
            myCALL = "19\n";
            break;
    }
    
    return myCALL;
}

double maroloDAQ::readTemperature(QByteArray myCALL) {
    
    // Envia comando para Arduino ler pino
    WriteData(myCALL);

    // recebe valor lido pelo ADC no pino do sensor
    QString AdcReadString = ReadData();

    // converte String em Inteiro
    double AdcReadDouble = AdcReadString.toDouble();

    // Converte Inteiro em Temperatura
    double temperature = scale_temp(AdcReadDouble * (4095/1023));
    return temperature;

}

// Converte valor de leitura do ADC em valor de temperatura
double maroloDAQ::scale_temp(double adcCount) {
    
    int i, diffScaled, diffRaw, diffAdc;
        double scaleFactor, scaledValue=0;
        for (i=0; i<100; i++)
        {
            if (adcCount >= temp[i][0] && adcCount < temp[i+1][0])
            {
                    diffScaled = temp[i][1] - temp[i+1][1];
                    diffRaw = temp[i+1][0] - temp[i][0];
                    scaleFactor = ((double)diffScaled ) / (double)diffRaw;
                    diffAdc = adcCount - temp[i][0];
                    scaledValue = temp[i][1] - (diffAdc * scaleFactor);
                    return scaledValue;
            }
    }
    return -1;
}

// Calibrando o Pendulo
void maroloDAQ::angleCalibrate(double myangle, int index) {
    
    // Configura myCALL com o valor do pino do Arduino
    QByteArray myCALL = infoCALL();
    
    double myvoltage = readVoltage(myCALL);
    
    calibrationArray[index].angle = myangle;
    calibrationArray[index].voltage = myvoltage;

} // end angleCalibrate

double maroloDAQ::readAngle(QByteArray myCALL) {
	
	int voltage;
	float angle;
	
	float a;
	float b;
	float pi=3.1415926;
	float v0;
	float v1;
	float teta0;
	float teta1;

	// v0
	v0 = (float)calibrationArray[0].voltage;	
	// v1
	v1 = (float)calibrationArray[1].voltage;
	// teta0
	teta0 = (float)(calibrationArray[0].angle);
	// teta1
	teta1 = (float)(calibrationArray[1].angle);
	
	teta0 = (teta0)*(pi/180); // conversion to rad
	teta1 = (teta1)*(pi/180); // conversion to rad
	
	a = (v0-v1)/(sin(teta0)-sin(teta1));
	b = v0-a*sin(teta0);

	voltage = readVoltage(myCALL);

	// Here, conversion voltage into degree
	angle = (180/pi)*asin((voltage-b)/a);
	
    return angle;
    
} // end readAngle

double maroloDAQ::readVoltage(QByteArray myCALL) {
    
    // Envia comando para Arduino ler pino
    WriteData(myCALL);

    // recebe valor lido pelo ADC no pino do sensor
    QString AdcReadString = ReadData();

    // converte String em Inteiro
    double AdcReadDouble = AdcReadString.toDouble();

    // Converte Inteiro em Temperatura
    double voltage = AdcReadDouble;
    
    return voltage;
    
} // end readVoltage

double maroloDAQ::readLight(QByteArray myCALL) {
    
    // Envia comando para Arduino ler pino
    WriteData(myCALL);

    // recebe valor lido pelo ADC no pino do sensor
    QString AdcReadString = ReadData();

    // converte String em Inteiro
    double AdcReadDouble = AdcReadString.toDouble();

    // Converte Inteiro em Temperatura
    double light = scale_light(AdcReadDouble * (4096/1023));
    
    return light;
    
} // end readLight

double maroloDAQ::scale_light(double adcCount) {
    int i, diffScaled, diffRaw, diffAdc, scaledValue=0;
    double scaleFactor;
    for (i=0; i<10; i++)
    {
        if (adcCount >= light[i][0] && adcCount < light[i+1][0])
        {
            diffScaled = light[i+1][1] - light[i][1];
            diffRaw = light[i+1][0] - light[i][0];
            scaleFactor = (double)diffScaled / (double)diffRaw;
            diffAdc = adcCount - light[i][0];
            scaledValue = (diffAdc * scaleFactor) + light[i][1];
            return scaledValue;
        }
    }
    return -1;
} // end scale_light

double maroloDAQ::readSound(QByteArray myCALL) {
    
    // Envia comando para Arduino ler pino
    WriteData(myCALL);

    // recebe valor lido pelo ADC no pino do sensor
    QString AdcReadString = ReadData();

    // converte String em Inteiro
    double AdcReadDouble = AdcReadString.toDouble();

    // Converte Inteiro em Temperatura
    double sound = scale_sound(AdcReadDouble * (4095/1023));
    
    return sound;
    
} // end readSound

double maroloDAQ::scale_sound(double adcCount) {
    
    int i, diffScaled, diffRaw, diffAdc, scaledValue=0;
    double scaleFactor;
    for (i=0; i<47; i++)
    {
        if (adcCount >= sound[i][0] && adcCount < sound[i+1][0])
        {
            diffScaled = sound[i+1][1] - sound[i][1];
            diffRaw = sound[i+1][0] - sound[i][0];
            scaleFactor = (double)diffScaled / (double)diffRaw;
            diffAdc = adcCount - sound[i][0];
            scaledValue = (diffAdc * scaleFactor) + sound[i][1];
            return scaledValue;
        }
    }
    
    return -1;
    
} // end scale_sound

double maroloDAQ::readResistence(QByteArray myCALL) {
    
    // Envia comando para Arduino ler pino
    WriteData(myCALL);

    //recebe valor lido pelo ADC no pino do sensor
    QString AdcReadString = ReadData();

    // converte String em Inteiro
    double AdcReadDouble = AdcReadString.toDouble();

    // Converte Inteiro em Temperatura
    double resistence = AdcReadDouble;

    return resistence;
    
} // end readResistence

double maroloDAQ::round_to_decimal(float f) {
    char buf[42];
    sprintf(buf, "%.7g", f); // round to 7 decimal digits
    return atof(buf);
}

/* 
 * Coisas para o GRACE
 * inicio
 */
void maroloDAQ::setupGrace () {
    
    if (GraceIsOpen()) {
        GracePrintf ("map font 0 to \"Times-Roman\", \"Times-Roman\"");
	GracePrintf ("page size 842, 595");
        GracePrintf ("default font 0");
        GracePrintf ("g0 on");
        GracePrintf ("g0 type XY");
        GracePrintf ("with g0");
        GracePrintf ("legend on");
        GracePrintf ("legend 0.8, 0.873");
        GracePrintf ("title \"Insira Aqui o T\\#{ed}tulo\"");
        GracePrintf ("title font 0");
        GracePrintf ("subtitle \"insira aqui o sub-t\\#{ed}tulo\"");
        GracePrintf ("subtitle font 0");
        GracePrintf ("xaxis label \"Tempo (s)\"");
        GracePrintf ("xaxis tick minor ticks 2");
	GracePrintf ("xaxis  ticklabel format decimal");
	GracePrintf ("xaxis  ticklabel prec 2");
        GracePrintf ("yaxis label \"insira aqui nome eixoY (unid)\"");
        GracePrintf ("yaxis tick minor ticks 2");
        
        GracePrintf ("kill s0");	
        GracePrintf ("s0 on");
        GracePrintf ("s0 symbol 1");
        GracePrintf ("s0 symbol size 0.4");
        GracePrintf ("s0 symbol color 1");
        GracePrintf ("s0 symbol fill color 2");
        GracePrintf ("s0 symbol fill pattern 1");
        GracePrintf ("s0 symbol linewidth 1.0");
        GracePrintf ("s0 symbol char 65");
        GracePrintf ("s0 line color 2");
        
        GracePrintf ("s0 legend \"Dados Experimentais\"");
        GracePrintf ("s0 line type 0");
        GracePrintf ("target g0.s0");
        GracePrintf ("s0 type xydxdy");
    } // end if GraceIsOpen
    
} // end setupGrace

void maroloDAQ::plotaGrace(double x, double y, double dx, double dy) {
    
    if (GraceIsOpen()) {
	
	// número de casas decimais no erroY
	const int ndig = decimalSensor(dy);
        
        // formating xy_point
        QString xy_point;
        QTextStream xyout(&xy_point);
        xyout << "s0 point " << QString::number(x, 'f', 2) << \
        ", " << QString::number(y, 'f', ndig);
        QByteArray xy_point_tmp = xy_point.toUtf8();
        const char *xy_expr = xy_point_tmp.simplified();
        
        GracePrintf(xy_expr);
        xy_point.clear();
        
        // formating dx_point
        QString dx_point;
        QTextStream dxout(&dx_point);
        dxout << "s0.y1[s0.length -1] = " << QString::number(dx, 'f', 2);
        QByteArray dx_point_tmp = dx_point.toUtf8();
        const char *dx_expr = dx_point_tmp.simplified();
        
        GracePrintf(dx_expr);
        dx_point.clear();
        
        // formating dy_point
        QString dy_point;
        QTextStream dyout(&dy_point);
        dyout << "s0.y2[s0.length -1] = " << QString::number(dy, 'f', ndig);
        QByteArray dy_point_tmp = dy_point.toUtf8();
        const char *dy_expr = dy_point_tmp.simplified();
        
        GracePrintf(dy_expr);
        dy_point.clear();
        
    } // end if GraceIsOpen
    
} //end plotaGrace

/* 
 * Coisas para o GRACE
 * Fim
 */


void maroloDAQ::closeEvent(QCloseEvent *event) {

    if (maybeSave()) {
        event->accept();
    } else {
        event->ignore();
    }
}

bool maroloDAQ::maybeSave() {
    if (!ui->teLog->document()->isModified()) 
        return true;
        const QMessageBox::StandardButton ret = \
        QMessageBox::warning(this, tr("maroloDAQ"), \
        tr("The document has been modified.\n" \
        "Do you want to save your changes?"), \
        QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
        switch (ret) {
            case QMessageBox::Save:
                return on_actionSalvar_triggered();
            case QMessageBox::Cancel:
                on_btnDevClose_clicked();
                return false;
            default:
                on_btnDevClose_clicked();
                break;
	}
    	return true;
}

void maroloDAQ::documentWasModified() {
    setWindowModified(ui->teLog->document()->isModified());
}

void maroloDAQ::setCurrentFile(const QString &fileName) {
    curFile = fileName;
    ui->teLog->document()->setModified(false);
    setWindowModified(false);
    ui->actionSalvar_como->setEnabled(true);
    ui->actionSalvar_como_tbox->setEnabled(true);
    
    QString shownName = curFile;
    if (curFile.isEmpty()) {
        shownName = "untitled.dat";
    }
    setWindowFilePath(shownName);

} // end setCurrentFile

bool maroloDAQ::on_actionSalvar_como_triggered() {
    QFileDialog dialog(this);
    dialog.setWindowTitle(QApplication::translate("maroloDAQ Save as", "maroloDAQ Salvar como", Q_NULLPTR));
    dialog.setWindowModality(Qt::WindowModal);
    dialog.setAcceptMode(QFileDialog::AcceptSave);
    if (dialog.exec() != QDialog::Accepted)
        return false;
    return saveFile(dialog.selectedFiles().first());
}

bool maroloDAQ::on_actionSalvar_triggered() {
    if (curFile.isEmpty()) {
        return on_actionSalvar_como_triggered();
    } else {
        return saveFile(curFile);
    }
}

void maroloDAQ::on_actionSobre_triggered() {
    QMessageBox msgBox;
    msgBox.setText("<b>maroloDAQ</b> datalogger");
    msgBox.setInformativeText(  "author: "
                                "\t José Eduardo Martins \n"
                                "\t jemartins@fis.unb.br \n"
                                "programers: \n"
                                "\t José Eduardo Martins \n"
                                "\t Rafael Ramos \n"
                                "\t rafaelframos@gmail.com \n \n"
                                "freeSoftware and openProject"
                             );
    msgBox.exec();
}

bool maroloDAQ::saveFile(const QString &fileName)
{
    QFile file(fileName);
    if (!file.open(QFile::WriteOnly | QFile::Text)) {
        QMessageBox::warning(this, tr("maroloDAQ"),
                             tr("Cannot write file %1:\n%2.")
                             .arg(QDir::toNativeSeparators(fileName),
                                  file.errorString()));
        return false;
    }
    
    QTextStream out(&file);
    
    #ifndef QT_NO_CURSOR
    QApplication::setOverrideCursor(Qt::WaitCursor);
    #endif
    out << ui->teLog->toPlainText();
    #ifndef QT_NO_CURSOR
    QApplication::restoreOverrideCursor();
    #endif
    setCurrentFile(fileName);
    statusBar()->showMessage(tr("File saved"), 2000);
    return true;

} // end saveFile

int maroloDAQ::decimalSensor(double value) { 
    
    int ndig;
    const int inteiro = floor(value);
    const double decimal = value - inteiro;
    if (inteiro == 0 && decimal > 0) {
	    QString decimal_string = QString::number(decimal, 'g', 1);
	    ndig = decimal_string.length() - 2;
    } else {
	    ndig = 0;
    }

    return ndig;
}

void maroloDAQ::formatDisplay(double value, double time, double erroY) {
    
    // lcdDisplayX
    if (time >= 1000) {
        ui->lcdDisplayX->setDigitCount(7);
    } else { 
        if (time >= 100) {
            ui->lcdDisplayX->setDigitCount(6);
        } else {
            ui->lcdDisplayX->setDigitCount(5);
        }
    }
    
    // lcdDisplayY
    const int ndig = decimalSensor(erroY);
    
    if (ndig == 0) {
        ui->lcdDisplayY->setDigitCount(5);
    } else {
        if ((ndig != 0) && (ndig <= 2)) {
            if (value >= 1000) {
                ui->lcdDisplayY->setDigitCount(7);
            } else {
                if (value >= 100) {
                    ui->lcdDisplayY->setDigitCount(6);
                } else {
                    ui->lcdDisplayY->setDigitCount(5);
                }
            }
        } else {
            if (value >= 100000) {
                ui->lcdDisplayY->setDigitCount(ndig + 7);
            } else {
                if (value >= 10000) {
                    ui->lcdDisplayY->setDigitCount(ndig + 6);
                } else {
                    if (value >= 1000) {
                        ui->lcdDisplayY->setDigitCount(ndig + 5);
                    } else {
                        if (value >= 100) {
                            ui->lcdDisplayY->setDigitCount(ndig + 4);
                        } else {
                            ui->lcdDisplayY->setDigitCount(ndig + 3);
                        }
                    }
                }
            }
        }
    }
}

double maroloDAQ::roundValue(double value, double error) {
    
    const int inteiro =  floor(error);
    const double decimal = double (error - inteiro);
    QString inteiro_string = QString::number(int(inteiro));
    int ntrunc = inteiro_string.length();
    double value_resp = 0;
    int resto_value = 0;
    int factor = 1;
    
    if (decimal == 0) {
        for (int k=0; k<ntrunc; k++) {
            factor = factor * 10;
            resto_value = round(value/factor);
        }
        value_resp = double (resto_value * factor);
        return value_resp;
    } else {
        return value;
    }
}

