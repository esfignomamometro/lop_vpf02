# Relatório de Desenvolvimento - Desafio LOP VPF02

Olá, professor! Este repositório contém a minha solução para o desafio de processamento de dados e geração do relatório de vendas. 

Gostaria de aproveitar este espaço para ser totalmente transparente sobre o processo de desenvolvimento deste projeto, os desafios que enfrentei e como cheguei a este resultado.

## 💻 Sobre o meu Ambiente de Desenvolvimento
Atualmente, minha máquina local está sem um ambiente de desenvolvimento ou compilador configurado e licenciado para C. Por conta dessa limitação técnica, eu não tinha como criar e testar os arquivos `.c` ou `.csv` diretamente no meu computador. 

Para contornar isso e conseguir entregar o desafio, optei por estruturar e criar todos os arquivos diretamente aqui pelo navegador no GitHub e utilizei IDEs e compiladores online gratuitos (como o OnlineGDB) para validar se o código estava rodando perfeitamente.

## 🔍 Fontes de Pesquisa e Uso de IA
Como ainda sou iniciante na linguagem C e ponteiros avançados são novos para mim, precisei recorrer a fontes externas de pesquisa para entender como resolver o problema dos dados fornecidos.

Durante as minhas pesquisas, utilizei o suporte da Inteligência Artificial (Gemini) não apenas para me ajudar a estruturar o código, mas principalmente como um "tutor particular" para me explicar a lógica por trás de cada função. 

Com essa ajuda, aprendi conceitos que ainda não dominava completamente, como:
* O uso de funções de biblioteca como `sscanf` com modificadores especiais (`%n` e `%[^,]`) para conseguir fatiar e separar textos grudados sem precisar usar ponteiros complexos.
* Como organizar o código de forma modular e estruturada usando funções e `structs`, seguindo o modelo que o senhor compartilhou no exemplo de clientes.

## 🧠 A Lógica que Desenvolvi
Em vez de tentar abrir um arquivo físico que eu não conseguiria testar localmente, embuti a string de dados brutos diretamente no programa. O código utiliza um laço `while` que percorre essa string caractere por caractere, isolando o nome do produto ao encontrar a vírgula e, em seguida, usa o `sscanf` para capturar os dados numéricos de quantidade e preço. Tudo isso é guardado em um vetor da struct `Produto`, calcula os totais e exibe o relatório formatado na tela.

Agradeço a compreensão pelas minhas limitações técnicas atuais e estou à disposição para explicar e defender toda a lógica do código em aula!

```
