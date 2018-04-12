# maroloDAQ
O objetivo deste projeto é criar um sistema de sensoriamento com dois componentes interconectados: arduino e aplicação. A comunicação entre os componentes ocorrerá por meio de portas seriais e de cabo USB. Ela será bidirecional, permitindo que os dois recebam e transmitam comandos ou dados entre si. 

O arduino (www.arduino.cc) é um microcontrolador com uma plataforma de programação embutida. Ele será utilizado para medir a tensão elétrica em um sensor, que estará fixado ao objeto da medida, e transformá-la em um valor útil. 

A aplicação é um programa para uma plataforma(Linux, Windows, Android), que se responsabilizará pela configuração de parâmetros de sensoriamento e pela apresentação dos dados. Ela será desenvolvida utilizando o framework Qt (www.qt.io). 

A pastas fw_maroloDAQ contém os códigos para a plataforma arduino (firmware).Os outros arquivos fazem parte da aplicação. Para testar o firmware, descarregue o ambiente de desenvolvimento para arduino , abra o arquivo fw_maroloDAQ.ino, compile e injete o código numa placa Arduino. Para testar a aplicação, descarregue o QtCreator, configure-o e compile o código. Não se esqueça de editar o arquivo Makefile e apontar a varável 'QMAKE' para a pasta correta no seu ambiente de desenvolvimento.

