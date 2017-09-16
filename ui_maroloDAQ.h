/********************************************************************************
** Form generated from reading UI file 'maroloDAQ.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAROLODAQ_H
#define UI_MAROLODAQ_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_maroloDAQ
{
public:
    QAction *actionSalvar;
    QAction *actionSalvar_como;
    QAction *actionSair;
    QAction *actionConectar;
    QAction *actionDesconectar;
    QAction *actionFerramentas;
    QAction *action_No_Flow_Control;
    QAction *action9600;
    QAction *actionRecarregar;
    QWidget *Widget;
    QGroupBox *gbDevice;
    QWidget *formLayoutWidget_2;
    QFormLayout *formLayout_2;
    QLabel *lbDevDesc;
    QLineEdit *editDevCompiler;
    QLabel *lbDevModel;
    QLineEdit *editDevModel;
    QTextEdit *teLog;
    QGroupBox *gbTempo;
    QWidget *formLayoutWidget_5;
    QFormLayout *formLayout_7;
    QLabel *lbDeltaT;
    QLineEdit *editDeltaT;
    QLabel *lbTmax;
    QLineEdit *editTmax;
    QPushButton *btnIniciar;
    QPushButton *btnParar;
    QGroupBox *gbSensor;
    QWidget *formLayoutWidget_4;
    QFormLayout *formLayout_4;
    QLabel *lbSensorTipo;
    QComboBox *cbSensorList;
    QLabel *lbSensorPino;
    QComboBox *cbPinoList;
    QPushButton *btnCalibrarSensor;
    QPushButton *btnAppClose;
    QPushButton *btnBWTerminal;
    QGroupBox *gbDeviceSerial;
    QPushButton *btnDevOpen;
    QPushButton *btnDevClose;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *lbDevPorts;
    QLabel *lbDevBaudRate;
    QLabel *lbDevFlowControl;
    QComboBox *cbDevList;
    QComboBox *cbDevBaudRate;
    QComboBox *cbDevFlowControl;
    QGroupBox *gbMonitor;
    QWidget *formLayoutWidget_3;
    QFormLayout *formLayout_3;
    QLabel *lbLCDmonitorY;
    QLCDNumber *lcdMonitorY;
    QWidget *formLayoutWidget_6;
    QFormLayout *formLayout_5;
    QLabel *lbLCDmonitorX;
    QLCDNumber *lcdMonitorX;
    QCheckBox *checkBoxGrace;
    QDockWidget *dockCalibrar;
    QWidget *dockWidgetContents;
    QGroupBox *gbCalibrar;
    QMenuBar *menuBar;
    QMenu *menuArquivo;
    QMenu *menuFerramentas;
    QMenu *menuBaudRate;
    QMenu *menuFlowControl;
    QMenu *menuPortas;
    QMenu *menuAjuda;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *maroloDAQ)
    {
        if (maroloDAQ->objectName().isEmpty())
            maroloDAQ->setObjectName(QStringLiteral("maroloDAQ"));
        maroloDAQ->resize(495, 430);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(maroloDAQ->sizePolicy().hasHeightForWidth());
        maroloDAQ->setSizePolicy(sizePolicy);
        maroloDAQ->setMinimumSize(QSize(495, 430));
        maroloDAQ->setMaximumSize(QSize(495, 430));
        QFont font;
        font.setFamily(QStringLiteral("Sans Serif"));
        maroloDAQ->setFont(font);
        actionSalvar = new QAction(maroloDAQ);
        actionSalvar->setObjectName(QStringLiteral("actionSalvar"));
        actionSalvar_como = new QAction(maroloDAQ);
        actionSalvar_como->setObjectName(QStringLiteral("actionSalvar_como"));
        actionSair = new QAction(maroloDAQ);
        actionSair->setObjectName(QStringLiteral("actionSair"));
        actionConectar = new QAction(maroloDAQ);
        actionConectar->setObjectName(QStringLiteral("actionConectar"));
        actionDesconectar = new QAction(maroloDAQ);
        actionDesconectar->setObjectName(QStringLiteral("actionDesconectar"));
        actionFerramentas = new QAction(maroloDAQ);
        actionFerramentas->setObjectName(QStringLiteral("actionFerramentas"));
        action_No_Flow_Control = new QAction(maroloDAQ);
        action_No_Flow_Control->setObjectName(QStringLiteral("action_No_Flow_Control"));
        action_No_Flow_Control->setChecked(false);
        action9600 = new QAction(maroloDAQ);
        action9600->setObjectName(QStringLiteral("action9600"));
        action9600->setChecked(false);
        actionRecarregar = new QAction(maroloDAQ);
        actionRecarregar->setObjectName(QStringLiteral("actionRecarregar"));
        Widget = new QWidget(maroloDAQ);
        Widget->setObjectName(QStringLiteral("Widget"));
        gbDevice = new QGroupBox(Widget);
        gbDevice->setObjectName(QStringLiteral("gbDevice"));
        gbDevice->setGeometry(QRect(10, 180, 191, 101));
        QFont font1;
        font1.setPointSize(10);
        font1.setBold(true);
        font1.setWeight(75);
        gbDevice->setFont(font1);
        gbDevice->setAlignment(Qt::AlignCenter);
        formLayoutWidget_2 = new QWidget(gbDevice);
        formLayoutWidget_2->setObjectName(QStringLiteral("formLayoutWidget_2"));
        formLayoutWidget_2->setGeometry(QRect(10, 23, 171, 71));
        formLayout_2 = new QFormLayout(formLayoutWidget_2);
        formLayout_2->setSpacing(6);
        formLayout_2->setContentsMargins(11, 11, 11, 11);
        formLayout_2->setObjectName(QStringLiteral("formLayout_2"));
        formLayout_2->setLabelAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        formLayout_2->setFormAlignment(Qt::AlignCenter);
        formLayout_2->setContentsMargins(0, 0, 0, 0);
        lbDevDesc = new QLabel(formLayoutWidget_2);
        lbDevDesc->setObjectName(QStringLiteral("lbDevDesc"));
        QFont font2;
        font2.setPointSize(9);
        font2.setBold(false);
        font2.setWeight(50);
        lbDevDesc->setFont(font2);

        formLayout_2->setWidget(0, QFormLayout::LabelRole, lbDevDesc);

        editDevCompiler = new QLineEdit(formLayoutWidget_2);
        editDevCompiler->setObjectName(QStringLiteral("editDevCompiler"));
        editDevCompiler->setEnabled(false);
        QFont font3;
        font3.setPointSize(9);
        font3.setBold(true);
        font3.setWeight(75);
        editDevCompiler->setFont(font3);

        formLayout_2->setWidget(0, QFormLayout::FieldRole, editDevCompiler);

        lbDevModel = new QLabel(formLayoutWidget_2);
        lbDevModel->setObjectName(QStringLiteral("lbDevModel"));
        lbDevModel->setFont(font2);

        formLayout_2->setWidget(1, QFormLayout::LabelRole, lbDevModel);

        editDevModel = new QLineEdit(formLayoutWidget_2);
        editDevModel->setObjectName(QStringLiteral("editDevModel"));
        editDevModel->setEnabled(false);
        editDevModel->setFont(font3);

        formLayout_2->setWidget(1, QFormLayout::FieldRole, editDevModel);

        teLog = new QTextEdit(Widget);
        teLog->setObjectName(QStringLiteral("teLog"));
        teLog->setGeometry(QRect(10, 280, 471, 81));
        gbTempo = new QGroupBox(Widget);
        gbTempo->setObjectName(QStringLiteral("gbTempo"));
        gbTempo->setGeometry(QRect(200, 140, 171, 141));
        QFont font4;
        font4.setBold(true);
        font4.setWeight(75);
        gbTempo->setFont(font4);
        gbTempo->setAlignment(Qt::AlignCenter);
        formLayoutWidget_5 = new QWidget(gbTempo);
        formLayoutWidget_5->setObjectName(QStringLiteral("formLayoutWidget_5"));
        formLayoutWidget_5->setGeometry(QRect(9, 30, 151, 101));
        formLayout_7 = new QFormLayout(formLayoutWidget_5);
        formLayout_7->setSpacing(6);
        formLayout_7->setContentsMargins(11, 11, 11, 11);
        formLayout_7->setObjectName(QStringLiteral("formLayout_7"));
        formLayout_7->setLabelAlignment(Qt::AlignCenter);
        formLayout_7->setContentsMargins(0, 0, 0, 0);
        lbDeltaT = new QLabel(formLayoutWidget_5);
        lbDeltaT->setObjectName(QStringLiteral("lbDeltaT"));
        QFont font5;
        font5.setBold(false);
        font5.setWeight(50);
        lbDeltaT->setFont(font5);

        formLayout_7->setWidget(0, QFormLayout::LabelRole, lbDeltaT);

        editDeltaT = new QLineEdit(formLayoutWidget_5);
        editDeltaT->setObjectName(QStringLiteral("editDeltaT"));
        editDeltaT->setEnabled(true);
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(editDeltaT->sizePolicy().hasHeightForWidth());
        editDeltaT->setSizePolicy(sizePolicy1);

        formLayout_7->setWidget(0, QFormLayout::FieldRole, editDeltaT);

        lbTmax = new QLabel(formLayoutWidget_5);
        lbTmax->setObjectName(QStringLiteral("lbTmax"));
        lbTmax->setFont(font5);

        formLayout_7->setWidget(1, QFormLayout::LabelRole, lbTmax);

        editTmax = new QLineEdit(formLayoutWidget_5);
        editTmax->setObjectName(QStringLiteral("editTmax"));
        editTmax->setEnabled(true);
        sizePolicy1.setHeightForWidth(editTmax->sizePolicy().hasHeightForWidth());
        editTmax->setSizePolicy(sizePolicy1);

        formLayout_7->setWidget(1, QFormLayout::FieldRole, editTmax);

        btnIniciar = new QPushButton(gbTempo);
        btnIniciar->setObjectName(QStringLiteral("btnIniciar"));
        btnIniciar->setEnabled(true);
        btnIniciar->setGeometry(QRect(10, 100, 71, 31));
        btnIniciar->setFont(font5);
        btnParar = new QPushButton(gbTempo);
        btnParar->setObjectName(QStringLiteral("btnParar"));
        btnParar->setEnabled(true);
        btnParar->setGeometry(QRect(90, 100, 71, 31));
        btnParar->setFont(font5);
        gbSensor = new QGroupBox(Widget);
        gbSensor->setObjectName(QStringLiteral("gbSensor"));
        gbSensor->setEnabled(true);
        gbSensor->setGeometry(QRect(200, 0, 171, 141));
        gbSensor->setFont(font4);
        gbSensor->setAlignment(Qt::AlignCenter);
        formLayoutWidget_4 = new QWidget(gbSensor);
        formLayoutWidget_4->setObjectName(QStringLiteral("formLayoutWidget_4"));
        formLayoutWidget_4->setGeometry(QRect(10, 30, 159, 102));
        formLayout_4 = new QFormLayout(formLayoutWidget_4);
        formLayout_4->setSpacing(6);
        formLayout_4->setContentsMargins(11, 11, 11, 11);
        formLayout_4->setObjectName(QStringLiteral("formLayout_4"));
        formLayout_4->setLabelAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        formLayout_4->setContentsMargins(0, 0, 0, 0);
        lbSensorTipo = new QLabel(formLayoutWidget_4);
        lbSensorTipo->setObjectName(QStringLiteral("lbSensorTipo"));
        lbSensorTipo->setFont(font5);

        formLayout_4->setWidget(0, QFormLayout::LabelRole, lbSensorTipo);

        cbSensorList = new QComboBox(formLayoutWidget_4);
        cbSensorList->setObjectName(QStringLiteral("cbSensorList"));
        cbSensorList->setEnabled(true);
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(cbSensorList->sizePolicy().hasHeightForWidth());
        cbSensorList->setSizePolicy(sizePolicy2);
        cbSensorList->setFont(font5);

        formLayout_4->setWidget(0, QFormLayout::FieldRole, cbSensorList);

        lbSensorPino = new QLabel(formLayoutWidget_4);
        lbSensorPino->setObjectName(QStringLiteral("lbSensorPino"));
        lbSensorPino->setFont(font5);

        formLayout_4->setWidget(1, QFormLayout::LabelRole, lbSensorPino);

        cbPinoList = new QComboBox(formLayoutWidget_4);
        cbPinoList->setObjectName(QStringLiteral("cbPinoList"));
        cbPinoList->setEnabled(true);
        sizePolicy2.setHeightForWidth(cbPinoList->sizePolicy().hasHeightForWidth());
        cbPinoList->setSizePolicy(sizePolicy2);
        cbPinoList->setFont(font5);

        formLayout_4->setWidget(1, QFormLayout::FieldRole, cbPinoList);

        btnCalibrarSensor = new QPushButton(formLayoutWidget_4);
        btnCalibrarSensor->setObjectName(QStringLiteral("btnCalibrarSensor"));
        btnCalibrarSensor->setEnabled(false);
        sizePolicy1.setHeightForWidth(btnCalibrarSensor->sizePolicy().hasHeightForWidth());
        btnCalibrarSensor->setSizePolicy(sizePolicy1);
        btnCalibrarSensor->setFont(font2);
        btnCalibrarSensor->setLayoutDirection(Qt::LeftToRight);

        formLayout_4->setWidget(2, QFormLayout::FieldRole, btnCalibrarSensor);

        btnAppClose = new QPushButton(Widget);
        btnAppClose->setObjectName(QStringLiteral("btnAppClose"));
        btnAppClose->setGeometry(QRect(370, 240, 111, 41));
        btnAppClose->setIconSize(QSize(32, 32));
        btnBWTerminal = new QPushButton(Widget);
        btnBWTerminal->setObjectName(QStringLiteral("btnBWTerminal"));
        btnBWTerminal->setGeometry(QRect(170, 490, 121, 41));
        btnBWTerminal->setIconSize(QSize(32, 32));
        gbDeviceSerial = new QGroupBox(Widget);
        gbDeviceSerial->setObjectName(QStringLiteral("gbDeviceSerial"));
        gbDeviceSerial->setGeometry(QRect(10, 0, 191, 181));
        gbDeviceSerial->setFont(font4);
        gbDeviceSerial->setLayoutDirection(Qt::LeftToRight);
        gbDeviceSerial->setAlignment(Qt::AlignCenter);
        btnDevOpen = new QPushButton(gbDeviceSerial);
        btnDevOpen->setObjectName(QStringLiteral("btnDevOpen"));
        btnDevOpen->setEnabled(false);
        btnDevOpen->setGeometry(QRect(10, 140, 71, 31));
        sizePolicy1.setHeightForWidth(btnDevOpen->sizePolicy().hasHeightForWidth());
        btnDevOpen->setSizePolicy(sizePolicy1);
        btnDevOpen->setFont(font2);
        btnDevOpen->setIconSize(QSize(32, 32));
        btnDevClose = new QPushButton(gbDeviceSerial);
        btnDevClose->setObjectName(QStringLiteral("btnDevClose"));
        btnDevClose->setEnabled(false);
        btnDevClose->setGeometry(QRect(90, 140, 91, 31));
        sizePolicy1.setHeightForWidth(btnDevClose->sizePolicy().hasHeightForWidth());
        btnDevClose->setSizePolicy(sizePolicy1);
        btnDevClose->setFont(font2);
        btnDevClose->setIconSize(QSize(32, 32));
        formLayoutWidget = new QWidget(gbDeviceSerial);
        formLayoutWidget->setObjectName(QStringLiteral("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(10, 30, 171, 101));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::ExpandingFieldsGrow);
        formLayout->setLabelAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        formLayout->setContentsMargins(0, 0, 0, 0);
        lbDevPorts = new QLabel(formLayoutWidget);
        lbDevPorts->setObjectName(QStringLiteral("lbDevPorts"));
        sizePolicy1.setHeightForWidth(lbDevPorts->sizePolicy().hasHeightForWidth());
        lbDevPorts->setSizePolicy(sizePolicy1);
        lbDevPorts->setFont(font2);
        lbDevPorts->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        formLayout->setWidget(0, QFormLayout::LabelRole, lbDevPorts);

        lbDevBaudRate = new QLabel(formLayoutWidget);
        lbDevBaudRate->setObjectName(QStringLiteral("lbDevBaudRate"));
        sizePolicy1.setHeightForWidth(lbDevBaudRate->sizePolicy().hasHeightForWidth());
        lbDevBaudRate->setSizePolicy(sizePolicy1);
        lbDevBaudRate->setFont(font2);

        formLayout->setWidget(1, QFormLayout::LabelRole, lbDevBaudRate);

        lbDevFlowControl = new QLabel(formLayoutWidget);
        lbDevFlowControl->setObjectName(QStringLiteral("lbDevFlowControl"));
        sizePolicy1.setHeightForWidth(lbDevFlowControl->sizePolicy().hasHeightForWidth());
        lbDevFlowControl->setSizePolicy(sizePolicy1);
        lbDevFlowControl->setFont(font2);

        formLayout->setWidget(2, QFormLayout::LabelRole, lbDevFlowControl);

        cbDevList = new QComboBox(formLayoutWidget);
        cbDevList->setObjectName(QStringLiteral("cbDevList"));
        cbDevList->setEnabled(true);
        sizePolicy2.setHeightForWidth(cbDevList->sizePolicy().hasHeightForWidth());
        cbDevList->setSizePolicy(sizePolicy2);
        cbDevList->setFont(font2);
        cbDevList->setSizeAdjustPolicy(QComboBox::AdjustToContents);
        cbDevList->setIconSize(QSize(16, 16));

        formLayout->setWidget(0, QFormLayout::FieldRole, cbDevList);

        cbDevBaudRate = new QComboBox(formLayoutWidget);
        cbDevBaudRate->setObjectName(QStringLiteral("cbDevBaudRate"));
        QSizePolicy sizePolicy3(QSizePolicy::MinimumExpanding, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(cbDevBaudRate->sizePolicy().hasHeightForWidth());
        cbDevBaudRate->setSizePolicy(sizePolicy3);
        cbDevBaudRate->setFont(font2);
        cbDevBaudRate->setToolTipDuration(-1);

        formLayout->setWidget(1, QFormLayout::FieldRole, cbDevBaudRate);

        cbDevFlowControl = new QComboBox(formLayoutWidget);
        cbDevFlowControl->setObjectName(QStringLiteral("cbDevFlowControl"));
        sizePolicy3.setHeightForWidth(cbDevFlowControl->sizePolicy().hasHeightForWidth());
        cbDevFlowControl->setSizePolicy(sizePolicy3);
        cbDevFlowControl->setFont(font2);

        formLayout->setWidget(2, QFormLayout::FieldRole, cbDevFlowControl);

        gbMonitor = new QGroupBox(Widget);
        gbMonitor->setObjectName(QStringLiteral("gbMonitor"));
        gbMonitor->setGeometry(QRect(370, 0, 111, 241));
        QSizePolicy sizePolicy4(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(gbMonitor->sizePolicy().hasHeightForWidth());
        gbMonitor->setSizePolicy(sizePolicy4);
        QFont font6;
        font6.setFamily(QStringLiteral("Sans Serif"));
        font6.setBold(true);
        font6.setWeight(75);
        font6.setKerning(true);
        gbMonitor->setFont(font6);
        gbMonitor->setAlignment(Qt::AlignCenter);
        formLayoutWidget_3 = new QWidget(gbMonitor);
        formLayoutWidget_3->setObjectName(QStringLiteral("formLayoutWidget_3"));
        formLayoutWidget_3->setGeometry(QRect(10, 60, 91, 81));
        formLayout_3 = new QFormLayout(formLayoutWidget_3);
        formLayout_3->setSpacing(6);
        formLayout_3->setContentsMargins(11, 11, 11, 11);
        formLayout_3->setObjectName(QStringLiteral("formLayout_3"));
        formLayout_3->setLabelAlignment(Qt::AlignCenter);
        formLayout_3->setFormAlignment(Qt::AlignCenter);
        formLayout_3->setHorizontalSpacing(0);
        formLayout_3->setVerticalSpacing(0);
        formLayout_3->setContentsMargins(0, 0, 0, 6);
        lbLCDmonitorY = new QLabel(formLayoutWidget_3);
        lbLCDmonitorY->setObjectName(QStringLiteral("lbLCDmonitorY"));
        sizePolicy1.setHeightForWidth(lbLCDmonitorY->sizePolicy().hasHeightForWidth());
        lbLCDmonitorY->setSizePolicy(sizePolicy1);
        lbLCDmonitorY->setFont(font5);
        lbLCDmonitorY->setAlignment(Qt::AlignCenter);

        formLayout_3->setWidget(0, QFormLayout::FieldRole, lbLCDmonitorY);

        lcdMonitorY = new QLCDNumber(formLayoutWidget_3);
        lcdMonitorY->setObjectName(QStringLiteral("lcdMonitorY"));
        lcdMonitorY->setEnabled(false);
        QSizePolicy sizePolicy5(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(1);
        sizePolicy5.setHeightForWidth(lcdMonitorY->sizePolicy().hasHeightForWidth());
        lcdMonitorY->setSizePolicy(sizePolicy5);
        lcdMonitorY->setLayoutDirection(Qt::LeftToRight);

        formLayout_3->setWidget(1, QFormLayout::SpanningRole, lcdMonitorY);

        formLayoutWidget_6 = new QWidget(gbMonitor);
        formLayoutWidget_6->setObjectName(QStringLiteral("formLayoutWidget_6"));
        formLayoutWidget_6->setGeometry(QRect(10, 150, 91, 81));
        formLayout_5 = new QFormLayout(formLayoutWidget_6);
        formLayout_5->setSpacing(6);
        formLayout_5->setContentsMargins(11, 11, 11, 11);
        formLayout_5->setObjectName(QStringLiteral("formLayout_5"));
        formLayout_5->setLabelAlignment(Qt::AlignCenter);
        formLayout_5->setFormAlignment(Qt::AlignCenter);
        formLayout_5->setHorizontalSpacing(0);
        formLayout_5->setVerticalSpacing(0);
        formLayout_5->setContentsMargins(0, 0, 0, 0);
        lbLCDmonitorX = new QLabel(formLayoutWidget_6);
        lbLCDmonitorX->setObjectName(QStringLiteral("lbLCDmonitorX"));
        sizePolicy1.setHeightForWidth(lbLCDmonitorX->sizePolicy().hasHeightForWidth());
        lbLCDmonitorX->setSizePolicy(sizePolicy1);
        lbLCDmonitorX->setFont(font5);
        lbLCDmonitorX->setAlignment(Qt::AlignCenter);

        formLayout_5->setWidget(0, QFormLayout::FieldRole, lbLCDmonitorX);

        lcdMonitorX = new QLCDNumber(formLayoutWidget_6);
        lcdMonitorX->setObjectName(QStringLiteral("lcdMonitorX"));
        lcdMonitorX->setEnabled(false);
        sizePolicy5.setHeightForWidth(lcdMonitorX->sizePolicy().hasHeightForWidth());
        lcdMonitorX->setSizePolicy(sizePolicy5);
        lcdMonitorX->setLayoutDirection(Qt::LeftToRight);

        formLayout_5->setWidget(1, QFormLayout::SpanningRole, lcdMonitorX);

        checkBoxGrace = new QCheckBox(gbMonitor);
        checkBoxGrace->setObjectName(QStringLiteral("checkBoxGrace"));
        checkBoxGrace->setEnabled(false);
        checkBoxGrace->setGeometry(QRect(10, 30, 101, 20));
        checkBoxGrace->setFont(font5);
        dockCalibrar = new QDockWidget(Widget);
        dockCalibrar->setObjectName(QStringLiteral("dockCalibrar"));
        dockCalibrar->setGeometry(QRect(294, 150, 201, 191));
        dockCalibrar->setFloating(true);
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QStringLiteral("dockWidgetContents"));
        gbCalibrar = new QGroupBox(dockWidgetContents);
        gbCalibrar->setObjectName(QStringLiteral("gbCalibrar"));
        gbCalibrar->setGeometry(QRect(10, 0, 171, 151));
        gbCalibrar->setFont(font4);
        dockCalibrar->setWidget(dockWidgetContents);
        maroloDAQ->setCentralWidget(Widget);
        menuBar = new QMenuBar(maroloDAQ);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 495, 27));
        menuArquivo = new QMenu(menuBar);
        menuArquivo->setObjectName(QStringLiteral("menuArquivo"));
        menuFerramentas = new QMenu(menuBar);
        menuFerramentas->setObjectName(QStringLiteral("menuFerramentas"));
        menuBaudRate = new QMenu(menuFerramentas);
        menuBaudRate->setObjectName(QStringLiteral("menuBaudRate"));
        menuFlowControl = new QMenu(menuFerramentas);
        menuFlowControl->setObjectName(QStringLiteral("menuFlowControl"));
        menuPortas = new QMenu(menuFerramentas);
        menuPortas->setObjectName(QStringLiteral("menuPortas"));
        menuAjuda = new QMenu(menuBar);
        menuAjuda->setObjectName(QStringLiteral("menuAjuda"));
        maroloDAQ->setMenuBar(menuBar);
        mainToolBar = new QToolBar(maroloDAQ);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        maroloDAQ->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(maroloDAQ);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        maroloDAQ->setStatusBar(statusBar);

        menuBar->addAction(menuArquivo->menuAction());
        menuBar->addAction(menuFerramentas->menuAction());
        menuBar->addAction(menuAjuda->menuAction());
        menuArquivo->addAction(actionSalvar);
        menuArquivo->addAction(actionSalvar_como);
        menuArquivo->addAction(actionSair);
        menuFerramentas->addSeparator();
        menuFerramentas->addAction(menuPortas->menuAction());
        menuFerramentas->addAction(menuBaudRate->menuAction());
        menuFerramentas->addAction(menuFlowControl->menuAction());
        menuFerramentas->addSeparator();
        menuFerramentas->addAction(actionRecarregar);
        menuFerramentas->addAction(actionConectar);
        menuFerramentas->addAction(actionDesconectar);
        menuBaudRate->addAction(action9600);
        menuFlowControl->addAction(action_No_Flow_Control);
        menuAjuda->addAction(actionFerramentas);

        retranslateUi(maroloDAQ);

        cbDevBaudRate->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(maroloDAQ);
    } // setupUi

    void retranslateUi(QMainWindow *maroloDAQ)
    {
        maroloDAQ->setWindowTitle(QApplication::translate("maroloDAQ", "maroloDAQ", 0));
        actionSalvar->setText(QApplication::translate("maroloDAQ", "Salvar", 0));
        actionSalvar_como->setText(QApplication::translate("maroloDAQ", "Salvar como", 0));
        actionSair->setText(QApplication::translate("maroloDAQ", "Sair", 0));
        actionConectar->setText(QApplication::translate("maroloDAQ", "Conectar", 0));
        actionDesconectar->setText(QApplication::translate("maroloDAQ", "Desconectar", 0));
        actionFerramentas->setText(QApplication::translate("maroloDAQ", "Ferramentas", 0));
        action_No_Flow_Control->setText(QApplication::translate("maroloDAQ", " NoFlowControl", 0));
#ifndef QT_NO_TOOLTIP
        action_No_Flow_Control->setToolTip(QApplication::translate("maroloDAQ", "<html><head/><body><p>No Flow Control</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        action9600->setText(QApplication::translate("maroloDAQ", "9600", 0));
        actionRecarregar->setText(QApplication::translate("maroloDAQ", "Recarregar", 0));
        gbDevice->setTitle(QApplication::translate("maroloDAQ", "Dispositivo", 0));
        lbDevDesc->setText(QApplication::translate("maroloDAQ", "Compilador:", 0));
        lbDevModel->setText(QApplication::translate("maroloDAQ", "Modelo:", 0));
        gbTempo->setTitle(QApplication::translate("maroloDAQ", "Tempo (s)", 0));
#ifndef QT_NO_TOOLTIP
        lbDeltaT->setToolTip(QApplication::translate("maroloDAQ", "Intervalo de tempo (s) entre cada medida", 0));
#endif // QT_NO_TOOLTIP
        lbDeltaT->setText(QApplication::translate("maroloDAQ", "<html><head/><body><p>\316\224t =</p></body></html>", 0));
#ifndef QT_NO_TOOLTIP
        lbTmax->setToolTip(QApplication::translate("maroloDAQ", "Tempo total (s) para a realiza\303\247\303\243o da medi\303\247\303\243o. A medi\303\247\303\243o ser\303\241 realizada desde t=0 at\303\251 esse valor m\303\241ximo.", 0));
#endif // QT_NO_TOOLTIP
        lbTmax->setText(QApplication::translate("maroloDAQ", "<html><head/><body><p>t<span style=\" vertical-align:sub;\">m\303\241x </span>=</p></body></html>", 0));
        btnIniciar->setText(QApplication::translate("maroloDAQ", "Iniciar", 0));
        btnParar->setText(QApplication::translate("maroloDAQ", "Parar", 0));
        gbSensor->setTitle(QApplication::translate("maroloDAQ", "Sensor", 0));
#ifndef QT_NO_TOOLTIP
        lbSensorTipo->setToolTip(QApplication::translate("maroloDAQ", "Qual o sensor que ser\303\241 usado nas medi\303\247\303\265es?", 0));
#endif // QT_NO_TOOLTIP
        lbSensorTipo->setText(QApplication::translate("maroloDAQ", "Tipo:", 0));
        cbSensorList->clear();
        cbSensorList->insertItems(0, QStringList()
         << QApplication::translate("maroloDAQ", "Onda Sonora", 0)
         << QApplication::translate("maroloDAQ", "N\303\255vel Sonoro", 0)
         << QApplication::translate("maroloDAQ", "Voltagem", 0)
         << QApplication::translate("maroloDAQ", "Resist\303\252ncia", 0)
         << QApplication::translate("maroloDAQ", "pH", 0)
         << QApplication::translate("maroloDAQ", "Temperatura", 0)
         << QApplication::translate("maroloDAQ", "Luz", 0)
         << QApplication::translate("maroloDAQ", "P\303\252ndulo", 0)
        );
#ifndef QT_NO_TOOLTIP
        lbSensorPino->setToolTip(QApplication::translate("maroloDAQ", "Em qual pino do dispositivo esta conectado o sensor?", 0));
#endif // QT_NO_TOOLTIP
        lbSensorPino->setText(QApplication::translate("maroloDAQ", "Pino:", 0));
        cbPinoList->clear();
        cbPinoList->insertItems(0, QStringList()
         << QApplication::translate("maroloDAQ", "A0", 0)
         << QApplication::translate("maroloDAQ", "A1", 0)
         << QApplication::translate("maroloDAQ", "A2", 0)
         << QApplication::translate("maroloDAQ", "A3", 0)
         << QApplication::translate("maroloDAQ", "A4", 0)
         << QApplication::translate("maroloDAQ", "A5", 0)
        );
        btnCalibrarSensor->setText(QApplication::translate("maroloDAQ", "Calibrar", 0));
#ifndef QT_NO_TOOLTIP
        btnAppClose->setToolTip(QApplication::translate("maroloDAQ", "Sair da aplica\303\247\303\243o", 0));
#endif // QT_NO_TOOLTIP
        btnAppClose->setText(QApplication::translate("maroloDAQ", "Sair [F4]", 0));
        btnAppClose->setShortcut(QApplication::translate("maroloDAQ", "F4", 0));
#ifndef QT_NO_TOOLTIP
        btnBWTerminal->setToolTip(QApplication::translate("maroloDAQ", "Muda Cor/Fonte da tela de log da aplica\303\247\303\243o", 0));
#endif // QT_NO_TOOLTIP
        btnBWTerminal->setText(QApplication::translate("maroloDAQ", "Cor Terminal [F2]", 0));
        btnBWTerminal->setShortcut(QApplication::translate("maroloDAQ", "F2", 0));
        gbDeviceSerial->setTitle(QApplication::translate("maroloDAQ", "Porta Serial", 0));
#ifndef QT_NO_TOOLTIP
        btnDevOpen->setToolTip(QApplication::translate("maroloDAQ", "Abre a conex\303\243o serial com o dispositivo selecionado", 0));
#endif // QT_NO_TOOLTIP
        btnDevOpen->setText(QApplication::translate("maroloDAQ", "Conectar", 0));
        btnDevOpen->setShortcut(QApplication::translate("maroloDAQ", "F3", 0));
#ifndef QT_NO_TOOLTIP
        btnDevClose->setToolTip(QApplication::translate("maroloDAQ", "Encerra a comunica\303\247\303\243o serial", 0));
#endif // QT_NO_TOOLTIP
        btnDevClose->setText(QApplication::translate("maroloDAQ", "Desconectar", 0));
        btnDevClose->setShortcut(QApplication::translate("maroloDAQ", "F5", 0));
        lbDevPorts->setText(QApplication::translate("maroloDAQ", "Portas:", 0));
        lbDevBaudRate->setText(QApplication::translate("maroloDAQ", "BaudRate:", 0));
        lbDevFlowControl->setText(QApplication::translate("maroloDAQ", "FlowCtrl:", 0));
        cbDevBaudRate->clear();
        cbDevBaudRate->insertItems(0, QStringList()
         << QApplication::translate("maroloDAQ", "9600", 0)
        );
        cbDevFlowControl->clear();
        cbDevFlowControl->insertItems(0, QStringList()
         << QApplication::translate("maroloDAQ", "NoFlowCtrl", 0)
        );
        gbMonitor->setTitle(QApplication::translate("maroloDAQ", "Monitor", 0));
        lbLCDmonitorY->setText(QApplication::translate("maroloDAQ", "Y (un)", 0));
        lbLCDmonitorX->setText(QApplication::translate("maroloDAQ", "X (s)", 0));
        checkBoxGrace->setText(QApplication::translate("maroloDAQ", "ao Grace", 0));
        gbCalibrar->setTitle(QApplication::translate("maroloDAQ", "Calibrar", 0));
        menuArquivo->setTitle(QApplication::translate("maroloDAQ", "Arquivo", 0));
        menuFerramentas->setTitle(QApplication::translate("maroloDAQ", "Ferramentas", 0));
        menuBaudRate->setTitle(QApplication::translate("maroloDAQ", "BaudRate", 0));
        menuFlowControl->setTitle(QApplication::translate("maroloDAQ", "Flow Control", 0));
        menuPortas->setTitle(QApplication::translate("maroloDAQ", "Portas", 0));
        menuAjuda->setTitle(QApplication::translate("maroloDAQ", "Ajuda", 0));
    } // retranslateUi

};

namespace Ui {
    class maroloDAQ: public Ui_maroloDAQ {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAROLODAQ_H
