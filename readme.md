# Braço Robótico de Coleta de Amostras — Docking & Retrieval

## Identificação

Projeto desenvolvido para simular um braço robótico de coleta de amostras, inspirado em aplicações da Indústria Espacial, como manipulação de carga, coleta de materiais e apoio em operações de docking e retrieval em ambientes de microgravidade.

## Descrição do Projeto

Este projeto consiste em um braço robótico físico controlado por um Joystick Shield V1.A. O sistema utiliza placas Arduino para interpretar os comandos do operador e acionar três servomotores responsáveis pelos principais movimentos do braço.

A proposta original previa o controle por Monitor Serial. Porém, durante o desenvolvimento físico, o projeto foi expandido para utilizar um Joystick Shield, tornando o controle mais intuitivo e próximo de uma operação real. Assim, os comandos digitais foram substituídos por movimentos e botões físicos do joystick.

O braço robótico realiza três funções principais:

- giro da base;
- movimento de levantar e abaixar a estrutura da garra;
- abertura e fechamento da garra.

Além disso, o circuito possui um LED branco de status, ligado com resistor de 220Ω, para indicar funcionamento do sistema.

## Objetivo

O objetivo do projeto é demonstrar, de forma prática, o controle de um braço robótico utilizando Arduino, servomotores, alimentação externa e interface física de comando. A aplicação simula uma operação de coleta de amostras em ambiente espacial, onde o operador precisa manipular uma garra robótica com precisão.

## Conexão com a Indústria Espacial

Braços robóticos são utilizados em missões espaciais para manutenção de satélites, movimentação de cargas, coleta de amostras, apoio a astronautas e manipulação de objetos em microgravidade.

Neste projeto, o braço robótico representa uma versão didática desse tipo de sistema, permitindo simular movimentos de aproximação, captura e manipulação de uma amostra por meio de servomotores controlados eletronicamente.

## Componentes Utilizados

- Arduino Uno
- Arduino Mega
- Joystick Shield V1.A
- 3 servomotores
- 1 LED branco de status
- 1 resistor de 220Ω para o LED
- Fonte externa 5V
- Protoboard
- Jumpers
- Estrutura física de braço robótico em acrílico
- 2 computadores utilizados durante montagem, testes e programação

## Estrutura Física do Braço

A estrutura física do braço robótico foi adquirida pronta em acrílico por meio de compra online. A decisão foi tomada porque não havia condições adequadas para modelagem e impressão das peças em 3D dentro do prazo disponível do projeto. Apesar disso, toda a montagem eletrônica, ligação dos componentes, integração dos servomotores, conexão da alimentação externa e testes de funcionamento foram realizados manualmente pela equipe.

## Função dos Servomotores

O projeto utiliza três servomotores, cada um responsável por uma parte do movimento do braço:

| Servo | Função |
|---|---|
| Servo 1 | Gira a base do braço robótico |
| Servo 2 | Levanta e abaixa a estrutura da garra |
| Servo 3 | Abre e fecha a garra |

Essa divisão permite controlar os principais movimentos necessários para simular a coleta de uma amostra.

## Controle por Joystick Shield

O controle do braço robótico é feito por meio do Joystick Shield V1.A. O joystick funciona como interface física de comando, permitindo controlar os movimentos do braço de forma mais prática do que pelo Monitor Serial.

A proposta inicial do trabalho previa comandos como:

| Comando original | Ação |
|---|---|
| U | Subir |
| D | Descer |
| O | Abrir |
| C | Fechar |

Na versão física desenvolvida, esses comandos foram adaptados para o Joystick Shield:

| Controle físico | Ação no braço |
|---|---|
| Movimento do joystick | Controle da base e/ou movimentação do braço |
| Botões do shield | Abertura e fechamento da garra |
| Comandos interpretados pelo Arduino | Acionamento dos servomotores |

## Comunicação entre Arduinos

O sistema utiliza duas placas Arduino: Arduino Uno e Arduino Mega.

O Arduino Uno é responsável por receber e interpretar os sinais do Joystick Shield. Em seguida, os comandos são enviados para o Arduino Mega por comunicação serial.

A comunicação entre as placas é feita utilizando os pinos de transmissão e recepção serial. A lógica correta de comunicação serial utiliza conexão cruzada:

| Comunicação | Ligação |
|---|---|
| TX de uma placa | RX da outra placa |
| RX de uma placa | TX da outra placa |
| GND | GND comum entre as placas |

No projeto, o Arduino Mega recebe os comandos interpretados e aciona os servomotores responsáveis pelos movimentos do braço robótico.

## Alimentação do Sistema

Os servomotores são alimentados por uma fonte externa de 5V. Essa decisão foi tomada porque servomotores exigem mais corrente do que a fornecida diretamente pelas placas Arduino, principalmente quando vários motores são utilizados ao mesmo tempo.

A protoboard foi utilizada como barramento de distribuição de energia, permitindo organizar as conexões de 5V e GND entre a fonte externa e os servomotores.

É importante destacar que todos os terras do circuito precisam estar conectados em comum:

- GND da fonte externa;
- GND do Arduino Uno;
- GND do Arduino Mega;
- GND dos servomotores.

Essa referência comum é necessária para que os sinais enviados pelos Arduinos sejam interpretados corretamente pelos servomotores.

## LED de Status

O projeto possui um LED branco utilizado como indicador de status do sistema. O LED foi ligado com um resistor de 220Ω, garantindo proteção contra excesso de corrente.

A função do LED é indicar visualmente que o circuito está energizado ou em operação, auxiliando na identificação do estado do sistema durante os testes.

Ligação básica do LED:

| Componente | Ligação |
|---|---|
| LED branco | Indicador de status |
| Resistor | 220Ω |
| Pino positivo do LED | Ligado ao Arduino através do resistor |
| Pino negativo do LED | Ligado ao GND |

## Uso da Protoboard

A protoboard foi utilizada para organizar o circuito e distribuir a alimentação dos servomotores. Ela atua como uma base de conexão entre a fonte externa, os fios dos servos e os pontos de GND comum.

A protoboard não gera energia por si mesma. Ela apenas distribui a energia recebida da fonte 5V e organiza os pontos de conexão entre os componentes.

## Funcionamento Geral

O funcionamento do sistema ocorre da seguinte forma:

1. O operador movimenta o joystick ou pressiona os botões do Joystick Shield.
2. O Arduino Uno interpreta os comandos recebidos pelo shield.
3. O Arduino Uno envia os comandos para o Arduino Mega por comunicação serial.
4. O Arduino Mega processa os comandos recebidos.
5. O Arduino Mega aciona os servomotores.
6. Os servos movimentam a base, levantam/abaixam a garra ou abrem/fecham a garra.
7. O LED de status indica o funcionamento do sistema.

## Fluxo de Funcionamento

```txt
Joystick Shield
      ↓
Arduino Uno
      ↓ comunicação serial
Arduino Mega
      ↓
Servomotores
      ↓
Movimento do braço robótico

Código-Fonte

Os códigos-fonte utilizados no projeto estão na pasta /src.

Como o sistema utiliza duas placas Arduino, o repositório pode conter dois arquivos separados:

- código do Arduino Uno, responsável pela leitura do Joystick Shield;
- código do Arduino Mega, responsável pelo acionamento dos servomotores.

Imagens do Projeto

As imagens da montagem física, do braço robótico, do circuito eletrônico e dos testes de funcionamento estão disponíveis na pasta /images.

As imagens documentam:

- estrutura física do braço;
- ligação dos servomotores;
- uso da protoboard;
- conexão dos Arduinos;
- Joystick Shield;
- fonte externa de 5V;
- LED de status.

Principais Aprendizados

Durante o desenvolvimento do projeto, foram aplicados conceitos de:

- robótica básica;
- controle de servomotores;
- comunicação serial entre placas Arduino;
- alimentação externa para motores;
- uso de protoboard como barramento de energia;
- montagem física de circuito eletrônico;
- integração entre hardware, software e estrutura mecânica.

Considerações Finais

O projeto demonstrou a construção de um braço robótico funcional voltado à simulação de coleta de amostras em um contexto espacial. A solução foi desenvolvida com estrutura física em acrílico, controle por Joystick Shield, três servomotores, comunicação entre Arduino Uno e Arduino Mega, LED de status e alimentação externa de 5V.

Apesar da estrutura mecânica ter sido adquirida pronta, toda a integração eletrônica, montagem do circuito, conexão dos servomotores, organização da alimentação e funcionamento do sistema foram realizados manualmente. O resultado final representa uma solução prática e didática de manipulação robótica, conectada ao tema de operações espaciais e microgravidade.