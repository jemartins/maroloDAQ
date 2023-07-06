# maroloDAQ

objetivo deste projeto é criar um sistema de medição assistida por computador com dois componentes interconectados: Arduino e Software.

## Comunicação
A comunicação entre eles ocorre por meio de portas seriais e de cabo USB. Ela é bidirecional, permitindo que ambos recebam e transmitam comandos ou dados entre si.

![Alt Comunicação](fluxogramas/com_soft-firm.jpg)

## Firmware
O Arduino é um micro-controlador com uma plataforma de execução embutida. Ele é utilizado, para medir a tensão elétrica em um sensor, que é fixado ao objeto da medida, e transmiti-la ao Software.

![Alt Firmware](fluxogramas/fw_maroloDAQ-principal.jpg)

## Software
O Software, desenvolvido com o framework Qt, configura os parâmetros de sensoriamento (erro, intervalo de amostragem e tempo de captura), transforma a tensão em valores úteis e armazena os dados.

![Alt Software](fluxogramas/maroloDAQ_soft_iniciar.jpg)

## Compilar e Executar:

<ol>
<li>Instale as dependência para compilar programas com QT 5, QSerial e Grace devel</li>
<li>Download código em https://github.com/jemartins/maroloDAQ/releases/tag/1.0.0-0.rc2
<li>cd maroloDAQ.v????</li>
<li>qmake</li>
<li>make</li>
<li>./maroloDAQ</li>
</ol>
