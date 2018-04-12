# maroloDAQ
O objetivo deste projeto é criar um sistema de sensoriamento com dois componentes interconectados: arduino e aplicação. A comunicação entre os componentes ocorrerá por meio de portas seriais e de cabo USB. Ela será bidirecional, permitindo que os dois recebam e transmitam comandos ou dados entre si. 

O arduino(www.arduino.cc) é um microcontrolador com uma plataforma de programação embutida. Ele será utilizado para medir a tensão elétrica em um sensor, que estará fixado ao objeto da medida, e transformá-la em um valor útil. 

A aplicação é um programa para uma plataforma(Linux, Windows, Android), que se responsabilizará pela configuração de parâmetros de sensoriamento e pela apresentação dos dados. Ela será desenvolvida utilizando o framework Qt(www.qt.io). 

As pastas fw_maroloDAQ e firware contém os códigos para a plataforma arduino. Todos os outros arquivos fazem parte do projeto da aplicação. 
