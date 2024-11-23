# Board Controller (ESP8266 + API)

## Motivação
Inspirado em outros projetos e no que a tecnologia pode fazer por nós, há alguns anos comprei um Arduino Uno. Fiz alguns experimentos com ele como manipulação de interfaces usando fotoresistor, sensor de proximidade, botões, RFID e relés. Devido a outros projetos de vida, o Arduino foi ficando de lado. 

No meio de 2024 dei mais uma olhada no mercado e encontrei uma placa mais poderosa, menor e com mais conectividade, a ESP8266. Então fiz alguns testes e vi que as possibilidades são "infinitas". Busquei criar um servidor web nela pra manipular as interfaces, mas achei o código muito complicado para expandir e dar manutenção, então resolvi buscar outra solução. Eis que questionei a IA sobre um código simples para manipular as interfaces da ESP usando API, então ela me forneceu o que foi o start desse projeto. Pretendo também criar um app iOS para se comunicar com a API, por meio dele teremos as definições de estado e também será possível efetuar leitura dos sensores que por ventura vierem a ser instalados.

## Do que se trata?
O projeto se consiste em programar a ESP8266 para se comunicar com a API e alterar o estado das interfaces de acordo com os dados recebidos.

## O que se pretende?
Por hora, ampliar meus conhecimentos e explorar as possibilidades, quem sabe controlar algumas funções na minha casa 🙃. 

Mas falando sério, vejo várias aplicações para esse projeto, mas sei que maiores são as que nesse momento não consigo imaginar. Com as adaptações certas, são vários os setores a serem beneficiados com projetos nessa linha. De imediato eu penso nos setores de agricultura, pecuária e transporte, mas como eu disse, são vários.


## Como funciona?
ESP: Consulta via get em /estado e verifica a string de retorno, se igual a "ligado", define a interface como ativada, do contrário, desativada.

API: Por hora, a comunicação com a API pode ser feita usando ferramentas como Postman ou Insomnia, acessando o endereço/endpiont. Para consultar, faça um get para endereco_api/estado, como a ESP faz. Para ativar a única propriedade existente, faça um post para endereco_api/ligar. Para desligar, faça um post para endereco_api/desligar.
