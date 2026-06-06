# Braço Robótico de Coleta de Amostras — Docking & Retrieval

## Identificação

Projeto desenvolvido para simular um braço robótico de coleta de amostras, inspirado em aplicações da Indústria Espacial, como manipulação de carga, coleta de materiais e apoio em operações de docking e retrieval em ambientes de microgravidade.

**Integrante:** Victoria Franceschini Pizza - RM550609

## Descrição do Projeto

Este projeto consiste em um circuito eletrônico com Arduino Uno, quatro botões físicos coloridos, dois servomotores, um LED branco de status, protoboard e fonte externa de 5V para alimentação dos motores.

A proposta original previa que o controle fosse feito pelo Monitor Serial, utilizando comandos como `U`, `D`, `O` e `C`. Na montagem física desenvolvida, esses comandos foram mantidos na lógica do projeto, porém foram representados por botões físicos coloridos. Dessa forma, em vez de digitar os comandos no Monitor Serial, o operador controla o braço robótico pressionando os botões correspondentes.

Essa adaptação tornou a operação mais intuitiva e próxima de um controle físico real, mantendo a mesma lógica funcional solicitada no enunciado.

## Objetivo

O objetivo do projeto é demonstrar, de forma prática, o controle de um braço robótico utilizando Arduino Uno, botões físicos, servomotores, LED de status e alimentação externa.

A aplicação simula uma operação de coleta de amostras em ambiente espacial, onde o operador precisa movimentar o braço e controlar a garra para realizar a manipulação de objetos.

## Conexão com a Indústria Espacial

Braços robóticos são utilizados em missões espaciais para manutenção de satélites, movimentação de cargas, coleta de amostras, apoio a astronautas e manipulação de objetos em ambientes de microgravidade.

Neste projeto, o braço robótico representa uma versão didática desse tipo de sistema, permitindo simular movimentos de aproximação, captura e manipulação de uma amostra por meio de servomotores controlados eletronicamente.

## Componentes Utilizados

* Arduino Uno
* 4 botões físicos coloridos
* 2 servomotores
* 1 LED branco de status
* 1 resistor de 220Ω para o LED
* Fonte externa de 5V para alimentação dos servomotores
* Protoboard
* Jumpers
* Modelo 3D em OpenSCAD da garra/gripper

## Comandos do Sistema

A lógica de controle foi baseada nos comandos previstos no enunciado original:

| Comando | Ação         |
| ------- | ------------ |
| U       | Subir braço  |
| D       | Descer braço |
| O       | Abrir garra  |
| C       | Fechar garra |

Na versão física, esses comandos são acionados por botões:

| Botão    | Pino Arduino | Comando Representado | Função       |
| -------- | -----------: | -------------------- | ------------ |
| Verde    |           D4 | U                    | Subir braço  |
| Amarelo  |           D2 | D                    | Descer braço |
| Azul     |           D3 | O                    | Abrir garra  |
| Vermelho |           D5 | C                    | Fechar garra |

## Justificativa da Adaptação dos Controles

Embora o enunciado original indique o uso do Monitor Serial para envio dos comandos, a montagem física foi adaptada para utilizar botões coloridos. Essa decisão foi tomada para tornar o controle mais visual, direto e semelhante a uma interface física de operação.

Cada botão representa um comando serial original:

* botão verde representa o comando `U`;
* botão amarelo representa o comando `D`;
* botão azul representa o comando `O`;
* botão vermelho representa o comando `C`.

Assim, a lógica de controle permanece equivalente à proposta original, mas a entrada do usuário ocorre por meio de botões físicos conectados ao Arduino.

## Servomotores

O projeto utiliza dois servomotores:

| Servo          | Pino Arduino | Função                 |
| -------------- | -----------: | ---------------------- |
| Servo da garra |           D9 | Abrir e fechar a garra |
| Servo do braço |          D10 | Subir e descer o braço |

Os servomotores são responsáveis pelos principais movimentos do braço robótico. Um deles controla o movimento vertical do braço, enquanto o outro controla a abertura e o fechamento da garra.

## LED de Status

O LED branco atua como indicador visual de funcionamento do sistema. Ele acende quando algum botão é pressionado e o Arduino está executando um comando.

| Componente  | Ligação                 |
| ----------- | ----------------------- |
| LED branco  | Indicador de status     |
| Resistor    | 220Ω                    |
| Pino do LED | D12                     |
| GND         | Terra comum do circuito |

O resistor de 220Ω foi utilizado para limitar a corrente elétrica e proteger o LED.

## Alimentação do Sistema

Os servomotores são alimentados por uma fonte externa de 5V. Essa escolha foi feita porque servomotores podem exigir mais corrente do que o Arduino consegue fornecer diretamente com segurança.

A protoboard foi utilizada como barramento de distribuição de energia, organizando as conexões de 5V e GND dos servomotores.

É importante destacar que o GND da fonte externa deve estar conectado ao GND do Arduino. Essa conexão cria uma referência elétrica comum entre Arduino, fonte e servos, permitindo que os sinais enviados pelo Arduino sejam interpretados corretamente pelos motores.

Resumo da alimentação:

| Item             | Função                                            |
| ---------------- | ------------------------------------------------- |
| Arduino Uno      | Controle lógico do circuito                       |
| Fonte externa 5V | Alimentação dos servomotores                      |
| Protoboard       | Distribuição de 5V e GND                          |
| GND comum        | Referência elétrica entre Arduino, fonte e servos |

## Funcionamento Geral

O funcionamento do sistema ocorre da seguinte forma:

1. O usuário pressiona um dos botões físicos coloridos.
2. O Arduino Uno lê o sinal do botão pressionado.
3. O código identifica qual comando foi acionado.
4. O LED branco de status acende durante a execução do comando.
5. O Arduino envia o sinal para o servomotor correspondente.
6. O servo do braço ou o servo da garra se movimenta.
7. Quando nenhum botão está pressionado, o LED permanece apagado.

## Fluxo de Funcionamento

```txt
Botões físicos coloridos
      ↓
Arduino Uno
      ↓
Leitura dos comandos U, D, O e C
      ↓
Acionamento dos servomotores
      ↓
Movimento do braço robótico

Fonte externa 5V
      ↓
Protoboard
      ↓
Alimentação dos servomotores

GND comum
      ↓
GND da fonte externa conectado ao GND do Arduino
      ↓
Referência elétrica comum para funcionamento correto dos sinais

LED de status
      ↓
Indicação visual de funcionamento do sistema
```

## Simulador

O arquivo `diagram.json`, localizado na pasta `/simulator`, representa o circuito no ambiente Wokwi.

Esse arquivo descreve uma versão simulada do circuito eletrônico, com Arduino Uno, botões, servomotores, LED de status, resistor e conexões principais.

**Link público do simulador:** inserir aqui o link público do Wokwi ou Tinkercad.

## Modelagem 3D

A modelagem 3D foi desenvolvida no OpenSCAD. O modelo representa uma garra/gripper do braço robótico, criada de forma paramétrica para permitir ajustes de tamanho e proporção.

O arquivo nativo do modelo está na pasta `/model`.

Arquivos da modelagem:

* `braco_robotico_gripper.scad`: arquivo nativo do OpenSCAD;
* `braco_robotico_gripper.stl`: arquivo exportado em formato STL.

O modelo 3D complementa a proposta física do projeto, representando a estrutura de manipulação da garra robótica.

## Estrutura do Repositório

```txt
PBMK/
│
├── README.md
│
├── src/
│   └── braco_robotico_botoes.ino
│
├── model/
│   ├── braco_robotico_gripper.scad
│   └── braco_robotico_gripper.stl
│
├── images/
│   ├── circuito_simulador.png
│   └── modelo_3d_render.png
│
└── simulator/
    └── diagram.json
```

## Explicação dos Arquivos

### `README.md`

Arquivo principal de documentação do projeto. Contém a explicação geral da proposta, os componentes utilizados, a lógica de funcionamento, a pinagem, a alimentação do sistema, a modelagem 3D e a organização do repositório.

### `src/braco_robotico_botoes.ino`

Arquivo principal do código Arduino.

Esse código é responsável por:

* ler os quatro botões físicos coloridos;
* identificar os comandos equivalentes a `U`, `D`, `O` e `C`;
* controlar os dois servomotores;
* acionar o LED branco de status;
* movimentar o braço e a garra de acordo com o botão pressionado.

### `model/braco_robotico_gripper.scad`

Arquivo de modelagem 3D desenvolvido no OpenSCAD. Representa a garra/gripper do braço robótico e pode ser editado para ajustes de dimensões e proporções.

### `model/braco_robotico_gripper.stl`

Arquivo exportado em formato STL a partir do OpenSCAD. Esse formato permite visualização em softwares 3D e eventual impressão da peça.

### `simulator/diagram.json`

Arquivo utilizado pelo simulador Wokwi. Ele descreve a estrutura do circuito simulado, incluindo Arduino Uno, botões, servomotores, LED, resistor e conexões principais.

### `/images`

Pasta destinada às imagens do projeto, como render do modelo 3D e captura de tela do circuito simulado.

## Vídeo de Funcionamento

O vídeo de funcionamento do circuito físico será anexado diretamente na plataforma de entrega.

No vídeo, é possível visualizar:

* a montagem real do circuito;
* o Arduino Uno conectado à protoboard;
* os quatro botões físicos coloridos;
* o LED branco de status;
* os dois servomotores;
* a fonte externa de 5V;
* o funcionamento dos comandos do braço robótico.

O vídeo foi escolhido como evidência visual complementar da montagem física e do funcionamento do sistema.

## Como Executar o Código

1. Abrir o arquivo `src/braco_robotico_botoes.ino` na Arduino IDE.
2. Conectar o Arduino Uno ao computador.
3. Selecionar a placa `Arduino Uno`.
4. Selecionar a porta correta.
5. Enviar o código para a placa.
6. Alimentar os servomotores com a fonte externa de 5V.
7. Garantir que o GND da fonte externa esteja conectado ao GND do Arduino.
8. Pressionar os botões físicos para controlar o braço.

## Guia de Operação

Para operar o braço robótico:

| Ação desejada | Botão    |
| ------------- | -------- |
| Subir braço   | Verde    |
| Descer braço  | Amarelo  |
| Abrir garra   | Azul     |
| Fechar garra  | Vermelho |

Durante a operação, o LED branco de status acende quando algum comando está sendo executado.

## Especificações Técnicas

| Item                       | Especificação                   |
| -------------------------- | ------------------------------- |
| Placa principal            | Arduino Uno                     |
| Quantidade de servomotores | 2                               |
| Alimentação dos servos     | Fonte externa 5V                |
| LED de status              | LED branco com resistor de 220Ω |
| Entrada de controle        | Botões físicos coloridos        |
| Software de modelagem      | OpenSCAD                        |
| Simulador                  | Wokwi                           |

## Tutorial de Uso

Este tutorial explica como preparar e operar o braço robótico de coleta de amostras.

### 1. Preparação do circuito

Antes de ligar o sistema, confira se os componentes estão conectados corretamente:

- Arduino Uno conectado ao computador por cabo USB;
- botões físicos coloridos conectados aos pinos digitais do Arduino;
- dois servomotores conectados aos pinos de sinal D9 e D10;
- LED branco de status conectado ao pino D12 com resistor de 220Ω;
- fonte externa de 5V conectada à alimentação dos servomotores;
- GND da fonte externa conectado ao GND do Arduino.

A conexão de GND comum é obrigatória para que os servomotores recebam corretamente os sinais enviados pelo Arduino.

### 2. Envio do código para o Arduino

1. Abra a Arduino IDE.
2. Abra o arquivo `src/braco_robotico_botoes.ino`.
3. Conecte o Arduino Uno ao computador.
4. Em `Tools > Board`, selecione `Arduino Uno`.
5. Em `Tools > Port`, selecione a porta correspondente ao Arduino.
6. Clique em `Upload` para enviar o código para a placa.

### 3. Alimentação dos servomotores

Os servomotores devem ser alimentados pela fonte externa de 5V.

A fonte externa não substitui o cabo USB do Arduino. O Arduino continua sendo alimentado pelo computador, enquanto a fonte de 5V alimenta os servomotores.

A ligação correta é:

| Fonte externa 5V | Ligação |
|---|---|
| Positivo 5V | Alimentação positiva dos servomotores |
| GND | GND dos servomotores e GND do Arduino |

### 4. Operação do braço robótico

Após enviar o código e ligar a fonte externa, utilize os botões físicos para controlar o braço.

| Botão | Comando equivalente | Ação |
|---|---|---|
| Verde | U | Subir braço |
| Amarelo | D | Descer braço |
| Azul | O | Abrir garra |
| Vermelho | C | Fechar garra |

Durante a operação, o LED branco de status acende quando algum botão está pressionado, indicando que o sistema está executando um comando.

### 5. Funcionamento esperado

- Ao pressionar o botão verde, o servo do braço move a estrutura para cima.
- Ao pressionar o botão amarelo, o servo do braço move a estrutura para baixo.
- Ao pressionar o botão azul, o servo da garra abre.
- Ao pressionar o botão vermelho, o servo da garra fecha.
- Quando nenhum botão está pressionado, os servos permanecem na última posição e o LED de status fica apagado.

### 6. Observação sobre o Monitor Serial

O enunciado original previa o envio dos comandos `U`, `D`, `O` e `C` pelo Monitor Serial. Nesta montagem física, esses comandos foram representados por botões coloridos, mantendo a mesma lógica de operação:

- `U` foi substituído pelo botão verde;
- `D` foi substituído pelo botão amarelo;
- `O` foi substituído pelo botão azul;
- `C` foi substituído pelo botão vermelho.

Essa adaptação tornou a operação mais visual e próxima de uma interface física de controle.

## Principais Aprendizados

Durante o desenvolvimento do projeto, foram aplicados conceitos de:

* robótica básica;
* controle de servomotores;
* entradas digitais com botões;
* alimentação externa para motores;
* uso de protoboard como barramento de energia;
* GND comum entre fonte externa e Arduino;
* LED de status com resistor;
* modelagem 3D em OpenSCAD;
* documentação técnica em GitHub.

## Considerações Finais

O projeto demonstrou a construção de um sistema robótico funcional voltado à simulação de coleta de amostras em um contexto espacial. A solução utiliza Arduino Uno, quatro botões físicos coloridos, dois servomotores, LED de status, protoboard e fonte externa de 5V.

Embora o enunciado original previsse o uso do Monitor Serial, a solução física foi adaptada para botões coloridos, mantendo a equivalência dos comandos `U`, `D`, `O` e `C`. Essa adaptação tornou o controle mais intuitivo e adequado à montagem prática realizada.

O resultado final é uma solução prática e didática de manipulação robótica, conectada ao tema de operações espaciais, docking, retrieval e microgravidade.
