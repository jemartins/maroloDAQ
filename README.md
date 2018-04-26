# maroloDAQ
O objetivo deste projeto é criar um sistema de medição assistida por computador com dois componentes interconectados: Arduino e Software.

A comunicação entre eles ocorre por meio de portas seriais e de cabo USB. Ela é bidirecional, permitindo que ambos recebam e transmitam comandos ou dados entre si.

[Comunicação](https://github.com/jemartins/maroloDAQ/blob/rafael/com_soft-firm.jpg)

O Arduino é um micro-controlador com uma plataforma de execução embutida. Ele é utilizado, para medir a tensão elétrica em um sensor, que é fixado ao objeto da medida, e transmiti-la ao Software.

(fluxograma do firmware)

O Software, desenvolvido com o framework Qt, configura os parâmetros de sensoriamento (erro, intervalo de amostragem e tempo de captura), transforma a tensão em valores úteis e armazena os dados.

(fluxograma do software)

A sistemática de instalação é a seguinte:
1- Descarregue e instale o ambiente de desenvolvimento do arduino (www.arduino.cc);
2- Descarregue o arquivo fw_maroloDAQ.ino da pasta fw_maroloDAQ, compile e injete o código numa placa Arduino;
3- Descarregue e instale o Qt 5 (www.qt.io);
4- Descarregue os arquivos da pasta raiz do projeto;
5- Configure o Makefile para a pontar a varável “QMAKE” para o Qt;
6- Execute o Makefile;
7- Conecte o Arduino ao PC com cabo USB e execute o Software;
