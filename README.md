# sensor-nivel-de-agua
Projeto sensor de nível de água T1592: prevenção de desperdício
Paula Ayumi Sakassegawa, Leandro Carlos Fernandes
1 Faculdade de Computação e Informática
Universidade Presbiteriana Mackenzie (UPM) – São Paulo, SP – Brazil
10414541@mackenzista.com.br
 
Abstract. Water scarcity has worsened every year for several reasons, including waste caused by overflowing water tanks. Therefore, measures to help reduce the waste of this resource became important. In this context, the Internet of Things (IoT) has gained ground in water monitoring and sustainability. Therefore, this project aims to develop a system with a T1592 sensor that indicates the water level (three different levels) through three LEDs, one for each level, and a buzzer (actuator) to indicate the full level. Associated with this, MQTT communication will be used to monitor water levels via mobile app.

Resumo. A escassez de água tem se agravado a cada ano por diversos motivos, entre eles, o desperdício causado pelo transbordamento de caixa d’água. Assim, torna-se importante medidas para auxiliar na redução do desperdício desse recurso. Nesse contexto, a Internet das coisas (Internet of Things – IoT) tem ganhado espaço no monitoramento de água e sustentabilidade. Portanto, este projeto tem como objetivo desenvolver um sistema com um sensor T1592 que indica o nível de água (três níveis diferentes) através de três LEDs, um para cada nível, e um buzzer (atuador) para indicar o nível cheio. Associado a isso, será utilizado a comunicação MQTT para monitoramento por aplicativo dos níveis de água.
1. Introdução
A água é um recurso essencial para a humanidade e tem grande importância econômica, social e ecológica. Porém, o acesso a ela tem sido prejudicado por diversos motivos. A escassez de água tem se agravado a cada ano devido à poluição, desperdício desse recurso, pela redução das fontes de captação, pelos vazamentos nas tubulações, desvios de água clandestino, transbordamento de reservatórios de caixa d’água, entre outros problemas. De acordo com as Nações Unidas, mais de 2 bilhões de pessoas podem ter acesso reduzido à água potável e um quarto da população viverá em um país afetado por escassez crônica em 2050. Assim, torna-se importante medidas que auxiliem na redução do desperdício de água. (ASSIS JR et. al., 2022; DO NASCIMENTO e CICHACZEWSKI, 2021; BERMUDES et. al., 2023)
Nesse contexto, a Internet das Coisas (Internet of Things - IoT) vem se tornando cada vez mais popular. O seu conceito ainda é muito discutido no meio acadêmico. O IEEE (Instituto de Engenheiros Eletricistas e eletrônicos) descreve o termo como uma rede complexa, adaptável e autoconfigurável que interconecta “coisas” à Internet através do uso de protocolos de comunicação padrão. (LEAL JR, et. al., 2020) Essa tecnologia tem rapidamente ganhado espaço no campo de monitoramento ambiental, gerenciamento de desastres, sistemas de alerta antecipado, monitoramento de água e sustentabilidade. (DO NASCIMENTO e CICHACZEWSKI, 2021)
Este projeto tem como objetivo desenvolver um sistema com um sensor T1592 que indica o nível de água (três níveis diferentes) através de três LEDs, um para cada nível, e um buzzer (atuador) para indicar o nível cheio. Associado a isso, será utilizado a comunicação MQTT para monitoramento por aplicativo dos níveis de água.

2. Materiais e métodos
Lista de materiais utilizados:
•	1 Placa NodeMCU V3 – ESP8266 – CH340 com cabo micro USB;
•	Sensor de nível de água T1592;
•	Jumper Macho-Macho;
•	Jumper Macho-Fêmea
•	Led de alto brilho vermelho – 5mm
•	Led de alto brilho verde – 5mm
•	Led de alto brilho amarelo – 5mm
•	Resistores de 220Ω;
•	Protoboard 400 pontos;
•	Buzzer 12 mm

2.1	Placa NodeMCU V3 – ESP8266 – CH340 com cabo Micro USB
 
Figura 1. Placa NodeMCU V3 – ESP8266 – CH340 com cabo Micro USB

 
Figura 2. Datasheet: NodeMCU V3 - ESP8266 - CH340
Especificações:
- Wireless padrão 802.11 b/g/n
- Faixa de frequência: 2.4GHz
- Taxa de transmissão: 110 a 460 Mbps
- Antena Embutida
- Interface USB: CH340
- Interface: Serial UART (Tx / Rx)
- Segurança: WEP / WPA / TKIP / AES
- Alimentação: 4,0 à 9,0 VDC (conector Micro USB)
- Tensão Lógica: 3,3 VDC
- Consumo: Min 70 mA (Standby) e Máx 220 mA (802.11b, CCK 1Mbps, Pout = +19.5dBm)
- Conversor A/D: 10 bits ADC e Vin 0 à 1 VDC
- GPIO: 11 portas
- Dimensões: 49 x 25,5 x 7 mm
- Peso: 10g

Acompanha:
01 - Módulo ESP8266 NodeMCU V3 CH340
01 - Micro USB

2.2	Sensor de nível de água T1592
 
Figura 3. Sensor de nível de água T1592
Especificações:
- Alimentação: 5VDC;
- Corrente de trabalho: inferior a 20mA;
- Temperatura de operação: 10° ~ 30°;
- Umidade: 10% a 90% (sem condensação);
- Tipo de sensor: Analógico;
- Processo de produção: FR4 HASL;
- Área de detecção: 40 x 16mm;
- Dimensões: 65 x 20mm x 8mm;
- Peso: 3g.
- Datasheet: Sensor de Nível de Água - T1592

2.3	Jumper Macho-macho
 
Figura 4. Jumper Macho-macho
Especificações:
- Conector: macho nas duas extremidades;
- Secção do Fio Condutor: 24 AWG;
- Comprimento de cada cabo: 10cm;
- Largura do Conector: 2,54mm (padrão protoboard);
- Cabos Destacáveis;
- Cores: marrom, vermelho, laranja, amarelo, verde, azul, violeta, cinza, branco e preto.

2.4	Jumper Macho-Fêmea 
 
Figura 5. Jumper Macho-Fêmea
Especificações:
- Conector: macho em uma extremidade e fêmea na outra;
- Secção do Fio Condutor: 24 AWG;
- Comprimento de cada cabo: 10cm;
- Largura do Conector: 2,54mm (padrão protoboard);
- Cabos Destacáveis;
- Cores: marrom, vermelho, laranja, amarelo, verde, azul, violeta, cinza, branco e preto.

2.5	Led Alto Brilho Verde – 5mm
 
Figura 6. Led Alto Brilho Verde – 5mm
Especificações:
Especificações Técnicas:
- LED Alto Brilho 5mm Verde
- Tipo: Alto Brilho
- Encapsulamento: Formato LED 5mm
- Diâmetro: 5mm
- Tensão: 3,0V ~ 3,2V
- Corrente: 20mA
- Luminosidade: 15000 ~ 18000 MCD
- Comprimento de onda: 567 ~ 570
- Distância dos terminais: 2,54mm
- Terminal 1 (Maior): Positivo / Anodo
- Terminal 2 (Menor):  Negativo / Catodo
- Cor: Verde
- Tamanho: 5mm Largura x 5mm Profundidade x 5mm Altura 
- Peso: 1g
2.6	Led Alto Brilho Vermelho – 5mm
 
Figura 7. Led Alto Brilho Vermelho – 5mm

Especificações Técnicas:
- LED Alto Brilho 5mm Verde
- Tipo: Alto Brilho
- Encapsulamento: Formato LED 5mm
- Diâmetro: 5mm
- Tensão: 3,0V ~ 3,2V
- Corrente: 20mA
- Luminosidade: 15000 ~ 18000 MCD
- Comprimento de onda: 567 ~ 570
- Distância dos terminais: 2,54mm
- Terminal 1 (Maior): Positivo / Anodo
- Terminal 2 (Menor):  Negativo / Catodo
- Cor: Verde
- Tamanho: 5mm Largura x 5mm Profundidade x 5mm Altura 
- Peso: 1g
2.7	Led Alto Brilho Amarelo – 5mm
 
Figura 8. Led Alto Brilho Amarelo– 5mm

Especificações Técnicas:
- LED Alto Brilho 5mm Amarelo
- Tipo: Alto Brilho
- Encapsulamento: Formato LED 5mm
- Diâmetro: 5mm
- Tensão: 3,0V ~ 3,2V
- Corrente: 20mA
- Luminosidade: 15000 ~ 20000 MCD
- Comprimento de onda: 588 ~ 590
- Distância dos terminais: 2,54mm
- Terminal 1 (Maior): Positivo / Anodo
- Terminal 2 (Menor):  Negativo / Catodo
- Cor: Amarelo
- Tamanho: 5mm Largura x 5mm Profundidade x 5mm Altura 
- Peso: 1g


2.8	Resistor 220 Ω
 
Figura 9. Resistor de Precisão 220R 1/4W 1%
Especificações:
- Resistência: 220R
- Potência: 1/4W
- Precisão: 1%

2.9	Protoboard 400 pontos
 
	Figura 10. Protoboard 400 Pontos Cristal
Especificações:
- Furos: 400;
- Material: Plástico ABS;
- Para terminais e condutores de 0,3 a 0,8 mm (20 a 29 AWG);
- Resistência de Isolamento: 100MO min;
- Tensão Máxima: 500v AC por minuto;
- Faixa de Temperatura: -20 a 80°C;
- Dimensões: 8.3 x 5.5 x 1.0 cm.
2.10	 Buzzer 12mm
 
Figura 11. Buzzer – 12mm

Características do Buzzer:
 
- Corrente: ≤ 42mA;
- Som de saída: ≥ 85DB;
- Frequência de Resonância: 2300 ± 300HZ;
- Temperatura de Operação: -20ºC ~ +45ºC;
- Temperatura de armazenamento: -20ºC ~ +60ºC;
- Sinalizador piezoelétrico de 12mm.
Funcionamento
	Será utilizado o NoceMCU V2 – ESP8266 LoLin, que é uma placa microcontroladora que faz a comunicação WiFi sem o uso de módulo externo; e o sensor de nível de água T1592. O sistema indicará o nível de água (três níveis diferentes) dentro de um tanque com a ajuda de 3 LEDs e uma campainha para indicar que o tanque está cheio.
	O Sensor de Nível de Água do modelo T1592 foi desenvolvido com dez traços de linhas metálicas expostas, sendo que cinco destas são de energia e cinco são sensores, de forma revezada. O funcionamento desse sensor se baseia na mesma lógica de um resistor variável, sendo que a resistência é alterada de acordo com o nível de água, dessa forma, a resistência é inversamente proporcional ao nível de água, portanto, quando o módulo está submerso a resistência é menor, quando não há água a resistência é maior, sabemos que o ar é um isolante natural, enquanto a água age como condutor. Consequentemente, o sensor produz uma tensão de saída referente à resistência, lembrando que a tensão é inversamente proporcional a resistência.
	Será utilizado a comunicação MQTT, que se baseia na troca de informações entre Subscriber e Publisher, através do broker; para o processo de conexão ao broker MQTT, será utilizado o “MQTTBox” e para o monitoramento e controle por aplicativo, será utilizado o aplicativo “MQTT Dashboard Cliente”. Na dashboard deste aplicativo, haverá a informação do nível de água quando o tanque estiver cheio.
 
Figura 12. MQTTBox

Modelo do protótipo

 
Figura 13. Protótipo


3. Resultados
	A montagem do sistema utilizando a placa NodeMCU V3 – ESP8266 – CH340, o sensor de nível de água T1592, LEDs indicadores e um buzzer apresentou um funcionamento satisfatório dentro dos parâmetros estabelecidos.

3.1. Conectividade Wi-Fi e MQTT
	Ao inicializar o sistema, a placa se conectou corretamente à rede Wi-Fi configurada e estabeleceu comunicação com o servidor MQTT (broker.mqtt-dashboard.com). A troca de mensagens entre o sensor e o broker foi bem-sucedida, permitindo a publicação dos dados no tópico "sensor/nivel-agua".

3.2. Detecção do Nível de Água
	O sensor de nível de água realizou medições com valores entre 0 e 1023, e com base nesses dados, diferentes estados do sistema foram acionados:

Nível Baixo (menos de 400): O LED vermelho acendeu, indicando pouca água no reservatório.

Nível Médio (entre 400 e 640): O LED amarelo acendeu, sinalizando um nível intermediário.

Nível Alto (acima de 640): O LED verde acendeu e o buzzer foi ativado, alertando que o nível de água estava alto.

3.3. Publicação de Dados no MQTT Dashboard
	Os valores captados pelo sensor foram convertidos em mensagens de texto ("Nivel Baixo", "Nivel Medio" e "Nivel Alto") e enviados para o servidor MQTT. No aplicativo MQTT Dashboard, foi possível visualizar essas mensagens em tempo real, confirmando que a comunicação entre o NodeMCU e o broker MQTT ocorreu corretamente.

3.4. Resposta do Sistema
	Os componentes eletrônicos reagiram conforme esperado às variações do nível de água, demonstrando que o código foi implementado corretamente. A ativação do buzzer em níveis elevados proporcionou um alerta sonoro eficiente, reforçando a indicação visual dos LEDs.

 
Figura 14. Protótipo do Projeto sensor de nível de água T1592
 
Figura 15. Protótipo com o LED vermelho aceso indicando o nível de água baixo

 
Figura 16. Protótipo com o LED amarelo aceso indicando o nível de água médio


 
Figura 17. Protótipo com o LED verde aceso indicando o nível de água alto e o buzzer tocando

 
Figura 18. Interface do aplicativo “MQTT Dashboard Cliente” indicando os níveis de água
Link para o vídeo-demonstração no YouTube da apresentação do funcionamento do projeto

https://www.youtube.com/shorts/r8yixLV95uk

4. Conclusão
	Os testes realizados confirmaram que o sistema monitora e transmite corretamente as leituras do sensor de nível de água. A comunicação via Wi-Fi e MQTT foi estabelecida com sucesso, permitindo o envio dos dados para um servidor remoto. Esse projeto pode ser utilizado para aplicações práticas, como monitoramento de caixas d’água, sistemas de irrigação automatizados e controle remoto de níveis de líquidos.
5. Referências
AUTOCORE ROBÓTICA. Cabos Dupont jumper fêmea para macho 10cm - Pacote com 40 peças. Disponível em: <https://www.autocorerobotica.com.br/cabos-dupont-jumper-fxm-10cm-pacote-com-40pcs>. Acesso em: 10 mar. 2025.
AUTOCORE ROBÓTICA. Protoboard 400 pontos cristal. Disponível em: <https://www.autocorerobotica.com.br/protoboard-400-pontos-cristal>. Acesso em: 10 mar. 2025.
ASSIS JR., L. B. de; SILVA, F. L.; HENRIQUES, F. da R.; OLIVEIRA GUERRA, R. P. de; CARVALHO, C. S. de; BRANDÃO, D. N. Construção e validação de um sistema IoT de baixo custo para detecção de vazamento de água em residências. In: COMPUTER ON THE BEACH, 13., 2022, Itajaí. Anais [...]. Itajaí: [s.n.], 2022.
BERMUDES, L. P.; VIEIRA, J. P. da S.; SILVA, M. G. da F. M. da; FREITAS, A. A. C. de. Monitoramento de nível de água e detecção de falhas através do sistema IoT. Revista Espaço Acadêmico, Maringá, v. 14, n. 2, p. 260, 2024. ISSN 2178-3829.
CURTO CIRCUITO. Sensor de nível de água analógico. Disponível em: <https://curtocircuito.com.br/sensor-de-nivel-de-agua-analogico.html>. Acesso em: 10 mar. 2025.
IOT ROBÓTICA. Buzzer 12mm. Disponível em: <https://www.iot-robotica.com.br/produto/buzzer-12mm.html>. Acesso em: 10 mar. 2025.
IOT ROBÓTICA. LED alto brilho amarelo. Disponível em: <https://www.iot-robotica.com.br/produto/led-alto-brilho-amarelo.html>. Acesso em: 10 mar. 2025.
IOT ROBÓTICA. LED alto brilho verde. Disponível em: <https://www.iot-robotica.com.br/produto/led-alto-brilho-verde.html>. Acesso em: 10 mar. 2025.
IOT ROBÓTICA. LED alto brilho vermelho. Disponível em: <https://www.iot-robotica.com.br/produto/led-alto-brilho-vermelho.html>. Acesso em: 10 mar. 2025.
LEAL JUNIOR, W. B.; ARAÚJO, H. X. de; TAVARES, F. M. Monitoramento da qualidade da água utilizando plataforma de Internet das Coisas. Revista Humanidades e Inovação, v. 7, n. 9, p. 47, 2020.
MERCADO LIVRE. ESP8266 Módulo WiFi ESP8266 NodeMCU V3 CH340 Micro USB. Disponível em: <https://produto.mercadolivre.com.br/MLB-2712613399-esp8266-modulo-wifi-esp8266-nodemcu-v3-ch340-micro-usb-_JM>. Acesso em: 10 mar. 2025.
NASCIMENTO, J. F.; CICHACZEWSKI, E. Internet das Coisas (IoT) aplicada ao monitoramento do nível de água em reservatórios domésticos. Caderno Progressus, Curitiba, v. 1, n. 2, p. 34-48, 2021.
