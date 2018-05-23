
#include "maroloDAQ.h"
#include "ui_maroloDAQ.h"
#include "calibration.h"

#include <QMessageBox>
#include <QMenu>
#include <QMenuBar>
#include <QStatusBar>
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
    
    // Formatando entradas
    ui->editAngulo1->setValidator(new QIntValidator(-90,90,ui->editAngulo1));
    ui->editAngulo1->setMaxLength(3);
    //ui->editAngulo1->setInputMask("#99");

    ui->editAngulo2->setValidator(new QIntValidator(-90,90,ui->editAngulo2));
    ui->editAngulo2->setMaxLength(3);
    //ui->editAngulo2->setInputMask("#99");
    
    QDoubleValidator *dvVal1 = new QDoubleValidator(0,1e99,1,ui->editErroSensor);
    dvVal1->setNotation(QDoubleValidator::ScientificNotation);
    ui->editErroSensor->setValidator(dvVal1);
    ui->editErroSensor->setMaxLength(7);
    //ui->editErroSensor->setInputMask("9e#99");
    
    ui->editDeltaT->setValidator(new QDoubleValidator(0,99999,1,ui->editDeltaT));
    //dvVal2->setNotation(QDoubleValidator::ScientificNotation);
    //ui->editDeltaT->setValidator(dvVal2);
    ui->editDeltaT->setMaxLength(5);
    //ui->editDeltaT->setInputMask("99999");

    ui->editTmax->setValidator(new QDoubleValidator(0,999999,1,ui->editErroSensor));
    //dvVal3->setNotation(QDoubleValidator::ScientificNotation);
    //ui->editTmax->setValidator(dvVal3);
    ui->editTmax->setMaxLength(6);
    //ui->editTmax->setInputMask("999999");
    
    ui->editDevCompiler->setReadOnly(true);
    ui->editDevModel->setReadOnly(true);

    // Procurando por portar seriais abertas
    scanPortas();
    
    setDesconectado();

    //Conectando SIGNAL de Timer a função update
    //connect(timer, SIGNAL(timeout()), this, SLOT(update()));
}

maroloDAQ::~maroloDAQ()
{
    delete ui;
}

void maroloDAQ::on_btnAppClose_clicked()
{
    exit(0);
}

void maroloDAQ::WriteData(const QByteArray data)
{
    procSerial->Write(data);
}

QString maroloDAQ::ReadData()
{
    QString data = procSerial->Read();
    //qDebug() << "ReadData - RX UART: " << data << endl;
    return data;
}

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
    //const char * meuAction;
    //const char * meuAction_tmp;
    QString minhaSerial;
    
    if(count > 0) {
        
        foreach (QAction* action, ui->menuPortas->actions()) {
            PortasGroup->removeAction(action);
            ui->menuPortas->removeAction(action);
        }
        
        for(int i=0;i<count;i++) {
            
            minhaSerial = DispSeriais[i];
            
            statusOpenSerial = procSerial->Conectar(minhaSerial,9600);
            
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
                    ui->teLog->append("### FALHA ao FECHAR Porta Serial!");
                }
                
                //qDebug() << "AQUI minhaSerial = " << minhaSerial << endl;
            } else {
                ui->teLog->append("### FALHA ao ABRIR Porta Serial. Tente de Novo!");
            }
        }
        
        /* 
         * ref.: https://stackoverflow.com/questions/9399840/ \
         * how-to-iterate-through-a-menus-actions-in-qt
         */
        foreach (QAction* action, ui->menuPortas->actions()) {
            PortasGroup->addAction(action);
            
            myAction_split = action->text().split("]");
            //qDebug() << "$$$$ AQUI action = " << action->text();
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
        ui->teLog->append("### Nenhuma porta serial foi detectada!");
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
    ui->gbMonitor->setEnabled(true);
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
    //ui->editDevCompiler->clear();
    //ui->editDevModel->clear();
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
    ui->gbMonitor->setEnabled(true);
    ui->btnCalibrar1->setEnabled(false);
    ui->btnCalibrar2->setEnabled(false);
    ui->cbSensorList->setEnabled(true);
    ui->cbPinoList->setEnabled(true);
    //modificado para teste btnIniciar
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

        ui->teLog->append("### Porta serial fechada com sucesso!");
    }
    else {
        ui->teLog->append("### Falha ao fechar conexão serial.");
    }
}

void maroloDAQ::on_btnBWTerminal_clicked() {
    
    QPalette paleta;
    /*
     * Verifica se PaletaBW é True ou False
     * Se True: Fundo Preto, Fonte Branco
     * Se False: Fundo Branco, Fonte Preto
     */
    
    if(PaletaLogBW) {
        paleta.setColor(QPalette::Base,Qt::black);
        paleta.setColor(QPalette::Text,Qt::white);
        ui->teLog->setPalette(paleta);
        PaletaLogBW=false;
    }
    else {
        paleta.setColor(QPalette::Base,Qt::white);
        paleta.setColor(QPalette::Text,Qt::black);
        ui->teLog->setPalette(paleta);
        PaletaLogBW=true;
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
    
    //qDebug() << "AQUI btnDevOpen: devport = " << devport;
    statusOpenSerial = procSerial->Conectar(devport,9600);
    
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
            
            ui->teLog->append("### maroloDAQ Aberto com Sucesso!");
        }
        else {
            ui->teLog->append("### Erro ao obter informações do maroloDAQ, tente novamente.");
        }
    }
    else {
        ui->teLog->append("### FALHA ao ABRIR Porta Serial. Tente de Novo!");
    }
    
} // end on_btnDevOpen_clicked

void maroloDAQ::on_btnDevClose_clicked() {
    
    bool statusCloseSerial;
    
    statusCloseSerial = procSerial->Desconectar();
    
    if (statusCloseSerial) {
        setDesconectado();        
        ui->teLog->append("### Porta serial fechada com sucesso!");
    }
    else {
        ui->teLog->append("### Falha ao fechar conexão serial.");
    }
    
    if (GraceIsOpen()) {
        /* Tell Grace to save the data */
        //GracePrintf("saveall \"sample.agr\"");
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
    ui->cbPinoList->setEnabled(true);
    ui->cbSensorList->setEnabled(true);

} // end on_btnParar_clicked

void maroloDAQ::on_btnIniciar_clicked() {
    
    if(validarEntradas()) {
        //hablita ou desabilita entradas
        ui->editErroSensor->setEnabled(false);
        ui->editDeltaT->setEnabled(false);
        ui->editTmax->setEnabled(false);
        ui->btnIniciar->setEnabled(false);
        ui->btnParar->setEnabled(true);
        ui->cbPinoList->setEnabled(false);
        ui->cbSensorList->setEnabled(false);
        ui->checkBoxGrace->setEnabled(false);
        
        // send to Grace?
        if (ui->checkBoxGrace->isChecked()) {
            if (!GraceIsOpen()) {
                /* Start Grace with a buffer size of 2048 and open the pipe */
                if (GraceOpenVA((char*)"xmgrace", 4096, "-nosafe", "-noask", NULL) == -1) {
                    //fprintf(stderr, "Can't run Grace. \n");
                    ui->teLog->append("Can't run Grace. \n");
                } else {
                    //ui->checkBoxGrace->setEnabled(false);
                    // ajuste no visual do Grace
                    setupGrace();
                } 
            } 
        } // end if checkBoxGrace->isChecked
        
        // inicia medicoes
        stopFlag = false;
        doReadings();
        
    } // end if validarEntradas
    
} // end on_btnIniciar_clicked

void maroloDAQ::on_actionSalvar_como_triggered() {
    
}

void maroloDAQ::on_actionSalvar_triggered() {
    
}

void maroloDAQ::on_actionSair_triggered() {
    exit(0);
}

void maroloDAQ::on_actionConectar_triggered() {
    
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
    
    //qDebug() << "AQUI btnDevOpen: devport = " << devport;
    statusOpenSerial = procSerial->Conectar(devport,9600);
    
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
            
            ui->teLog->append("### maroloDAQ Aberto com Sucesso!");
        }
        else {
            ui->teLog->append("### Erro ao obter informações do maroloDAQ, tente novamente.");
        }
    }
    else {
        ui->teLog->append("### FALHA ao ABRIR Porta Serial. Tente de Novo!");
    }
    
} // end on_actionConectar_triggered

void maroloDAQ::on_actionDesconectar_triggered() {
    
    bool statusCloseSerial;
    
    
    statusCloseSerial = procSerial->Desconectar();
    
    if (statusCloseSerial) {
        setDesconectado();
        
        ui->teLog->append("### Porta serial fechada com sucesso!");
    }
    else {
        ui->teLog->append("### Falha ao fechar conexão serial.");
    }
}

void maroloDAQ::on_actionRecarregar_triggered() {
    
    scanPortas();
    
}

void maroloDAQ::setPortasSeriais(QString myAction) {
    
    //qDebug() << ">>>>> AQUI myAction = " << myAction;
    
    //////////////////////////////////////////////////////
    //ref.: http://zetcode.com/gui/qt5/menusandtoolbars/
    QString myAction_spare;
    QString myAction_temp;
    QStringList myAction_split;
    myAction = myAction.simplified();
    //myAction_temp = myAction;
    myAction_split = myAction.split(" [");
    myAction_temp = myAction_split[0];
    myAction = "/dev/"+myAction;
    //qDebug() << ">>>>> AQUI myAction = " << myAction;
    
    int ihavename = 0;
    foreach (QAction *action, ui->menuPortas->actions()) {
        if ( !(action->isSeparator()) || !(action->menu()) ) {
            //if ( QString::compare(myAction_temp, myAction_spare, Qt::CaseInsensitive) ) {
            if ( myAction == action->text() ) {
                ihavename = ihavename + 1;
            }
        }
    }
    if ( ihavename == 0 ) {
        if ( myAction_temp == "ttyACM0" ) {
            //qDebug() << ">>>>> AQUI myAction_split[1] = " << myAction_split[1];
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
            //qDebug() << ">>>>> AQUI myAction_split[0] = " << myAction_split[0];
            actionACM0 = new QAction(myAction, this);
            ui->menuPortas->addAction(actionACM1);
            if (myAction_split.length() > 1 ) {
                if ( myAction_split[1] == "maroloDAQ]") {
                    actionACM0->setCheckable(true);
                    actionACM0->setChecked(true);
                }
            }
        }
        if ( myAction_temp == "ttyACM2" ) {
            //qDebug() << ">>>>> AQUI myAction_split[0] = " << myAction_split[0];
            actionACM0 = new QAction(myAction, this);
            ui->menuPortas->addAction(actionACM2);
            if (myAction_split.length() > 1 ) {
                if ( myAction_split[1] == "maroloDAQ]") {
                    actionACM0->setCheckable(true);
                    actionACM0->setChecked(true);
                }
            }
        }
        if ( myAction_temp == "ttyACM3" ) {
            //qDebug() << ">>>>> AQUI myAction_split[0] = " << myAction_split[0];
            actionACM0 = new QAction(myAction, this);
            ui->menuPortas->addAction(actionACM3);
            if (myAction_split.length() > 1 ) {
                if ( myAction_split[1] == "maroloDAQ]") {
                    actionACM0->setCheckable(true);
                    actionACM0->setChecked(true);
                }
            }
        }
        if (  myAction_temp == "ttyS0") {
            //qDebug() << ">>>>> AQUI myAction_split[0] = " << myAction_split[0];
            actionS0 = new QAction(myAction, this);
            ui->menuPortas->addAction(actionS0);
            actionS0->setCheckable(true);
        }
        if (  myAction_temp == "ttyS1") {
            //qDebug() << ">>>>> AQUI myAction_split[0] = " << myAction_split[0];
            actionS1 = new QAction(myAction, this);
            ui->menuPortas->addAction(actionS1);
            actionS1->setCheckable(true);
        }
        if (  myAction_temp == "ttyS2") {
            //qDebug() << ">>>>> AQUI myAction_split[0] = " << myAction_split[0];
            actionS2 = new QAction(myAction, this);
            ui->menuPortas->addAction(actionS2);
            actionS2->setCheckable(true);
        }
        if (  myAction_temp == "ttyS3") {
            //qDebug() << ">>>>> AQUI myAction_split[0] = " << myAction_split[0];
            actionS3 = new QAction(myAction, this);
            ui->menuPortas->addAction(actionS3);
            actionS3->setCheckable(true);
        }
    }
    /*
     / / ref.: *https://stackoverflow.com/questions/9399840/how-to-iterate-through-a-menus-actions-in-qt
     PortasGroup = new QActionGroup(this);
     foreach (QAction* action, ui->menuPortas->actions())
     {
     PortasGroup->addAction(action);
     actions->setCheckable(true);
}
*/
} // end setPortasSeriais

void maroloDAQ::enumerateMenu(QMenu *menu) {
    
    //////////////////////////////////////////////////////
    //ref.: https://stackoverflow.com/questions/9399840/how-to-iterate-through-a-menus-actions-in-qt

    foreach (QAction *action, menu->actions()) {
        
        if (action->isSeparator()) {
            //qDebug() << "this action is a separator.";// << "" << endl;
        } else if (action->menu()) {
            //qDebug() << "action1: %s:" << qUtf8Printable(action->text());// << endl;
            //qDebug() << "this action is associated with a submenu, iterating it recursively...";// << "" << endl;
            enumerateMenu(action->menu());
            //qDebug() << "finished iterating the submenu";// << "" << endl;
        } else {
            //qDebug() << "action2: %s" << qUtf8Printable(action->text());// << endl;
        }
    }
}

void maroloDAQ::on_cbSensorList_activated(const QString &arg1) {
    
    //qDebug() << "----> AQUI cbSensorList e &arg1 = " << arg1;
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
    
    //Se ERRO for vazio apresenta mensagem de erro e para operação, senão...
    //Se DeltaT for vazio apresenta mensagem de erro e para operação, senão...
    //Se Tmax for vazio apresenta mensagem de erro e para operação, senão...
    //Tudo ok e continua a operação.
    if(ui->editErroSensor->text()==NULL) {
        msgBox.setText("Digite o Erro");
        msgBox.exec();
        ui->editErroSensor->setFocus();
        return false;
    } else {
        if(ui->editDeltaT->text()==NULL){
            msgBox.setText("Digite o intervalo de amostragem");
            msgBox.exec();
            ui->editDeltaT->setFocus();
            return false;
        } else {
            if(ui->editTmax->text()==NULL){
                msgBox.setText("Digite o tempo máximo da amostra");
                msgBox.exec();
                ui->editTmax->setFocus();
                return false;
            } else {
                return true;
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
    
    double mysound,myvoltage,myresistence,mytemperature, mylight,myangle;
    // contador
    int cont = 0;
    //intervalo de tempo para as leituras
    double deltaT = ui->editDeltaT->text().toDouble() * 1000;
    //tempo para as leituras
    double Tmax = ui->editTmax->text().toDouble() * 1000;
    //erro indicado no gui para o sensor
    double erroY = ui->editErroSensor->text().toDouble();
    // tolerância no tempo máximo de leitura
    double tolerance = deltaT * 0.3;
    
    // inicializando o relogio
    timer.start();
    // instante inicial das medicoes
    double tempo_inicial = timer.elapsed();
    // momento da medicao
    double tempo_atual = 0 ;
    // define timeout
    double timeout = Tmax + tolerance;

    // Teste com QTextStream
    QString abobora;
    QTextStream out(&abobora);
    //out << "Qt" << "rocks!";
    
    while ( (!timer.hasExpired(timeout)) && (!stopFlag) ) {
        
        if ( (timer.hasExpired(cont * deltaT)) && (!stopFlag) ) {
            
            //Qual Sensor foi Selecionado
            switch(ui->cbSensorList->currentIndex()) {
                case 0:
                    mysound = readSound(myCALL);
                    // descongelando o GUI
                    QCoreApplication::processEvents();
                    // Envia o valor medido ao lcdMonitorY
                    ui->lcdMonitorY->display(QString::number(mysound, 'f', 1));
                    // Envia o tempo decorrido para o lcdMonitorX
                    ui->lcdMonitorX->display(QString::number(tempo_atual/1000, 'f', 2));
                    ui->teLog->append((QString::number(tempo_atual/1000, 'f', 2))+"    "+\
                    (QString::number(mysound, 'f', 1))+"    "+\
                    (QString::number(0.01, 'f', 2))+"    "+\
                    (QString::number(erroY, 'f', 1)));

                    break;
                case 1:
                    myvoltage = readVoltage(myCALL);
                    // descongelando o GUI
                    QCoreApplication::processEvents();
                    // Envia o valor medido ao lcdMonitorY
                    ui->lcdMonitorY->display(QString::number(myvoltage, 'f', 1));
                    // Envia o tempo decorrido para o lcdMonitorX
                    ui->lcdMonitorX->display(QString::number(tempo_atual/1000, 'f', 2));
                    ui->teLog->append((QString::number(tempo_atual/1000, 'f', 2))+"    "+\
                    (QString::number(myvoltage, 'f', 1))+"    "+\
                    (QString::number(0.01, 'f', 2))+"    "+\
                    (QString::number(erroY, 'f', 1)));
                    break;
                case 2:
                    myresistence = readResistence(myCALL);
                    // descongelando o GUI
                    QCoreApplication::processEvents();
                    // Envia o valor medido ao lcdMonitorY
                    ui->lcdMonitorY->display(QString::number(myresistence, 'f', 1));
                    // Envia o tempo decorrido para o lcdMonitorX
                    ui->lcdMonitorX->display(QString::number(tempo_atual/1000, 'f', 2));
		    // Envia ao Console
                    ui->teLog->append((QString::number(tempo_atual/1000, 'f', 2))+"    "+\
                    (QString::number(myresistence, 'f', 1))+"    "+\
                    (QString::number(0.01, 'f', 2))+"    "+\
                    (QString::number(erroY, 'f', 1)));
                    break;
                case 3:
                    mytemperature = readTemperature(myCALL);
                    // descongelando o GUI
                    QCoreApplication::processEvents();
                    // Envia o valor medido ao lcdMonitorY
                    ui->lcdMonitorY->display(QString::number(mytemperature/10, 'f', 1));
                    // Envia o tempo decorrido para o lcdMonitorX
                    ui->lcdMonitorX->display(QString::number(tempo_atual/1000, 'f', 3));
                    // Envia ao Console
		    ui->teLog->append((QString::number(tempo_atual/1000, 'f', 2))+"    "+\
                    (QString::number(mytemperature/10, 'f', 1))+"    "+\
                    (QString::number(0.01, 'f', 2))+"    "+\
                    (QString::number(erroY, 'f', 1)));
		    
		    out << QString::number(tempo_atual/1000, 'f', 2) << " " << QString::number(mytemperature/10, 'f', 1);
                    qDebug() << "AQUI ABOBORA = " << abobora;
		    abobora.clear();

		    //qDebug() << tempo_atual/1000 << "    " << mytemperature/10 << "    " << 0.01 << "    " << erroY;
                    // send to Grace?
                    if (ui->checkBoxGrace->isChecked()) {
                        plotaGrace(tempo_atual/1000, mytemperature/10, 0.01, erroY);
			//GracePrintf ("autoscale");
			GracePrintf ("redraw");
                    }
                    break;
                case 4:
                    mylight = readLight(myCALL);
                    // descongelando o GUI
                    QCoreApplication::processEvents();
                    // Envia o valor medido ao lcdMonitorY
                    ui->lcdMonitorY->display(QString::number(mylight, 'f', 1));
                    // Envia o tempo decorrido para o lcdMonitorX
                    ui->lcdMonitorX->display(QString::number(tempo_atual/1000, 'f', 2));
                    ui->teLog->append((QString::number(tempo_atual/1000, 'f', 2))+"    "+\
                    (QString::number(mylight, 'f', 1))+"    "+\
                    (QString::number(0.01, 'f', 2))+"    "+\
                    (QString::number(erroY, 'f', 1)));
                    break;
                case 5:
                    myangle = readAngle(myCALL);
                    // descongelando o GUI
                    QCoreApplication::processEvents();
                    // Envia o valor medido ao lcdMonitorY
                    ui->lcdMonitorY->display(QString::number(myangle, 'f', 1));
                    // Envia o tempo decorrido para o lcdMonitorX
                    ui->lcdMonitorX->display(QString::number(tempo_atual/1000, 'f', 2));
                    ui->teLog->append((QString::number(tempo_atual/1000, 'f', 2))+"    "+\
                    (QString::number(myangle, 'f', 1))+"    "+\
                    (QString::number(0.01, 'f', 2))+"    "+\
                    (QString::number(erroY, 'f', 1)));
                    break;
            } // end switch sensor
            
            cont++;
            
        } // end if deltaT
        
        // Atualiza o tempo decorrido na medicao
        tempo_atual = (timer.elapsed() - tempo_inicial);
        
    } // end while timeout
    
    
    //GUI é reabilitado
    ui->editErroSensor->setEnabled(true);
    ui->editDeltaT->setEnabled(true);
    ui->editTmax->setEnabled(true);
    ui->btnIniciar->setEnabled(true);
    ui->btnParar->setEnabled(false);
    ui->cbPinoList->setEnabled(true);
    ui->cbSensorList->setEnabled(true);
    ui->checkBoxGrace->setEnabled(true);
    
}

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
    double temperature = scale_temp(AdcReadDouble * (4096/1023));
    return temperature;

}

//Converte valor de leitura do ADC em valor de temperatura
double maroloDAQ::scale_temp(double adcCount) {
    
    //int i, diffScaled, diffRaw, diffAdc, scaledValue=0;
    int i, diffScaled, diffRaw, diffAdc;
        //double scaleFactor;
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
    //qDebug() << "AQUI myCALL = " << myCALL << endl;
    //qDebug() << "AQUI index  = " << index << endl;
    
    double myvoltage = readVoltage(myCALL);
    
    calibrationArray[index].angle = myangle;
    //qDebug() << "AQUI calibrationArray[index].angle = " << 
    //	    calibrationArray[index].angle << endl;
    calibrationArray[index].voltage = myvoltage;
    //qDebug() << "AQUI calibrationArray[index].voltage = " <<
    //      calibrationArray[index].voltage << endl;

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
    	qDebug() << "AQUI calibrationArray[0].voltage = " << \
    		calibrationArray[0].voltage << endl;
	// v1
	v1 = (float)calibrationArray[1].voltage;
    	qDebug() << "AQUI calibrationArray[1].voltage = " << \
    		calibrationArray[1].voltage << endl;
	// teta0
	teta0 = (float)(calibrationArray[0].angle);
    	qDebug() << "AQUI calibrationArray[0].angle = " << \
    		calibrationArray[0].angle << endl;
	// teta1
	teta1 = (float)(calibrationArray[1].angle);
    	qDebug() << "AQUI calibrationArray[1].angle = " << \
    		calibrationArray[1].angle << endl;
	
	teta0 = (teta0)*(pi/180); // conversion to rad
	teta1 = (teta1)*(pi/180); // conversion to rad
	
	a = (v0-v1)/(sin(teta0)-sin(teta1));
	b = v0-a*sin(teta0);

	voltage = readVoltage(myCALL);

	// Here, conversion voltage into degree
	angle = (180/pi)*asin((voltage-b)/a);
	qDebug() << "AQUI angle = " << angle << endl;
	
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
    //int voltage = (int(AdcReadDouble * (5/1023)));
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
    double light = scale_light(AdcReadDouble * (4096/102333));
    
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
    double sound = scale_sound(AdcReadDouble * (4096/1023));
    
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
        //GracePrintf ("g0 on");
        //GracePrintf ("g0 type XY");
        //GracePrintf ("with g0");
        GracePrintf ("legend on");
        GracePrintf ("legend 0.8, 0.8");
        GracePrintf ("title \"Insira Aqui o Titulo\"");
        GracePrintf ("subtitle \"insira aqui o subtitulo\"");
        GracePrintf ("xaxis  label \"insira aqui nome do eixoX (unid)\"");
        GracePrintf ("yaxis  label \"insira aqui nome eixoY (unid)\"");
       
       	//GracePrintf ("kill s0");	
        GracePrintf ("s0 on");
        GracePrintf ("s0 symbol 1");
        GracePrintf ("s0 symbol size 0.4");
        GracePrintf ("s0 symbol color 1");
        GracePrintf ("s0 symbol fill color 2");
        GracePrintf ("s0 symbol fill pattern 1");
        GracePrintf ("s0 symbol linewidth 1.0");
        GracePrintf ("s0 symbol char 65");
        GracePrintf ("s0 line color 2");
        
        GracePrintf ("s0 legend  \"Dados Experimentais\"");
        GracePrintf ("s0 line type 0");
        GracePrintf ("target g0.s0");
        GracePrintf ("s0 type xydxdy");
    } // end if GraceIsOpen
    
} // end setupGrace

void maroloDAQ::plotaGrace (double x, double y, double dx, double dy) {
    
    if (GraceIsOpen()) {
        //GracePrintf ("g0.s0 type xydxdy");
        //qDebug() << "AQUI x y dx dy = " << x << " " << y << " " << dx << " " << dy << endl;
        //qDebug() << x << "    " << y << "    " << dx << "    " << dy;
        //GracePrintf("s0 point %5.2f, %5.1f", x, y);
        //GracePrintf ("S0.Y1[S0.LENGTH - 1] = %5.2f", dx);
        //GracePrintf ("S0.Y2[S0.LENGTH - 1] = %5.2f", dy);
	int px = int (x*1000);
	int rpx = px % 100;
	px = px /1000;
	int py = int (y*100);
	int rpy = py % 10;
	py = py /100;
	//int dpx = 10;
	//int dpy = dy * 100;
        qDebug() << px << "    " << rpx << "    " << py << "    " << rpy;
	GracePrintf("s0 point %d.%d, %d.%d", px, rpx, py, rpy);
        //GracePrintf ("S0.Y1[S0.LENGTH - 1] = %d", dpx);
        //GracePrintf ("S0.Y2[S0.LENGTH - 1] = %d", dpy);

	//GracePrintf ("autoscale");
    } // end if GraceIsOpen
    
} //end plotaGrace

/* 
 * Coisas para o GRACE
 * Fim
 */

