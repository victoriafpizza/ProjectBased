# Braço Robótico de Coleta de Amostras — Docking & Retrieval

## Identificação

Projeto desenvolvido para simular um braço robótico de coleta de amostras, inspirado em aplicações da Indústria Espacial, como manipulação de carga, coleta de materiais e apoio em operações de docking e retrieval em ambientes de microgravidade.

## Descrição do Projeto

Este projeto consiste em um circuito eletrônico com Arduino Uno, quatro botões físicos coloridos, dois servomotores, um LED branco de status, protoboard e fonte externa de 5V para alimentação dos servos.

O sistema foi desenvolvido para simular os movimentos básicos de um braço robótico utilizado em operações espaciais. Cada botão físico representa um comando de controle do braço, permitindo subir, descer, abrir e fechar a garra.

A proposta original previa o controle por Monitor Serial. Nesta versão física, os comandos foram representados por botões coloridos, tornando a operação mais direta, visual e intuitiva. A lógica dos comandos U, D, O e C foi mantida no funcionamento do circuito.

## Objetivo

O objetivo do projeto é demonstrar, de forma prática, o controle de servomotores por meio de botões físicos conectados ao Arduino Uno. A solução simula um braço robótico de coleta de amostras, utilizando alimentação externa para os motores e LED de status para indicar o funcionamento do sistema.

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

## Comandos e Funções

| Botão    | Pino Arduino | Comando | Função       |
| -------- | -----------: | ------- | ------------ |
| Amarelo  |           D2 | D       | Descer braço |
| Azul     |           D3 | O       | Abrir garra  |
| Verde    |           D4 | U       | Subir braço  |
| Vermelho |           D5 | C       | Fechar garra |

## Servomotores

O projeto utiliza dois servomotores:

| Servo          | Pino Arduino | Função                 |
| -------------- | -----------: | ---------------------- |
| Servo da garra |           D9 | Abrir e fechar a garra |
| Servo do braço |          D10 | Subir e descer o braço |

Os servos são alimentados por uma fonte externa de 5V, pois motores exigem mais corrente do que o Arduino consegue fornecer diretamente com segurança.

## LED de Status

O LED branco atua como indicador visual de funcionamento do sistema. Ele é acionado quando algum botão é pressionado e o sistema está executando um comando.

| Componente  | Ligação                 |
| ----------- | ----------------------- |
| LED branco  | Indicador de status     |
| Resistor    | 220Ω                    |
| Pino do LED | D12                     |
| GND         | Terra comum do circuito |

## Alimentação do Sistema

A alimentação dos servomotores é feita por uma fonte externa de 5V. A protoboard é utilizada como barramento de distribuição de energia, organizando os pontos de 5V e GND dos servomotores.

É importante destacar que o GND da fonte externa precisa estar conectado ao GND do Arduino. Essa conexão cria uma referência elétrica comum, permitindo que os sinais enviados pelo Arduino sejam interpretados corretamente pelos servomotores.

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
3. O código identifica qual comando foi enviado.
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
│   └── braco_robotico_gripper.scad
│
└── simulator/
    └── diagram.json
```

## Explicação dos Arquivos

### `README.md`

Arquivo principal de documentação do projeto. Contém a explicação geral da proposta, os componentes utilizados, a lógica de funcionamento, a pinagem, a alimentação do sistema, a organização do repositório e as observações da entrega.

### `src/braco_robotico_botoes.ino`

Arquivo principal do código Arduino.

Esse código é responsável por:

* ler os quatro botões físicos coloridos;
* identificar os comandos D, O, U e C;
* controlar os dois servomotores;
* acionar o LED branco de status;
* movimentar o braço e a garra de acordo com o botão pressionado.

Mapeamento usado no código:

| Elemento       | Pino |
| -------------- | ---: |
| Botão amarelo  |   D2 |
| Botão azul     |   D3 |
| Botão verde    |   D4 |
| Botão vermelho |   D5 |
| Servo da garra |   D9 |
| Servo do braço |  D10 |
| LED de status  |  D12 |

### `model/braco_robotico_gripper.scad`

Arquivo de modelagem 3D desenvolvido no OpenSCAD.

Ele representa a peça da garra/gripper do braço robótico. O modelo foi criado de forma paramétrica, utilizando variáveis para permitir ajustes de tamanho, proporção e encaixe. Esse arquivo corresponde ao projeto nativo da modelagem 3D.

O arquivo `.scad` pode ser aberto no OpenSCAD para visualização, edição e exportação.

### Arquivo `.stl`

O modelo 3D pode ser exportado pelo OpenSCAD no formato `.stl`.

Caso o arquivo `.stl` esteja presente na pasta `model`, ele representa a versão exportada do modelo 3D, pronta para visualização em softwares 3D ou eventual impressão.

Para gerar o STL no OpenSCAD:

1. Abrir o arquivo `braco_robotico_gripper.scad`.
2. Pressionar `F6` para renderizar.
3. Acessar `File > Export > Export as STL`.
4. Salvar o arquivo na pasta `model`.

### `simulator/diagram.json`

Arquivo utilizado pelo simulador Wokwi.

Ele descreve a estrutura do circuito simulado, incluindo Arduino Uno, botões, servomotores, LED, resistor e conexões principais. Esse arquivo funciona como uma representação virtual do circuito eletrônico.

A montagem física final utiliza Arduino Uno, quatro botões físicos, dois servomotores, LED de status, protoboard e fonte externa de 5V para alimentação dos servos. O arquivo `diagram.json` é utilizado como apoio para representar o circuito no ambiente de simulação.

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

O vídeo foi escolhido como principal evidência visual da montagem física e do funcionamento do projeto.

## Como Executar o Código

1. Abrir o arquivo `src/braco_robotico_botoes.ino` na Arduino IDE.
2. Conectar o Arduino Uno ao computador.
3. Selecionar a placa `Arduino Uno`.
4. Selecionar a porta correta.
5. Enviar o código para a placa.
6. Alimentar os servomotores com a fonte externa de 5V.
7. Garantir que o GND da fonte externa esteja conectado ao GND do Arduino.
8. Pressionar os botões físicos para controlar o braço.

## Observações Importantes

* Os servomotores devem ser alimentados pela fonte externa de 5V.
* O GND da fonte externa precisa estar conectado ao GND do Arduino.
* O LED branco possui resistor de 220Ω para limitar a corrente.
* A protoboard foi usada para organizar as conexões e distribuir a alimentação.
* O código final da montagem física utiliza botões físicos coloridos em vez de controle exclusivo pelo Monitor Serial.

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

A montagem eletrônica foi desenvolvida manualmente, com foco na integração entre hardware, programação e organização do circuito. O modelo 3D em OpenSCAD complementa a entrega, representando a garra do braço robótico de forma paramétrica.

O resultado final é uma solução prática e didática de manipulação robótica, conectada ao tema de operações espaciais, docking, retrieval e microgravidade.
