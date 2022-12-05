# Grafos2_Dijkstra-Kruskall-SCC

**Número da Lista**: 9<br>
**Conteúdo da Disciplina**: Grafos 2<br>

## Alunos
|Matrícula | Aluno |
| -- | -- |
| 16/0141842  |  Philipe Rosa Serafim |
| 16/0143403  |   Renan Welz Schadt   |

## Sobre 
Para o segundo trabalho da disciplina, nós optamos por submeter exercícios de juízes onlines.
As questões foram selecionadas buscando abranger alguns dos conteúdos abordados no respectivo módulo.

## Screenshots
Adicione 3 ou mais screenshots do projeto em funcionamento.

## Execução
**Linguagem**: C++<br>
Para compilar os códigos, é necessário ter um compilador de C++ (gpp, g++, etc) previamente instalado.

## Uso 
Os problemas estão organizados seguindo um padrão, o comando para compilar e executar os códigos será o mesmo para todos os problemas, mas para isso faz-se necessário explicar a organização das pastas, que seguem o seguinte formado:

```
 - Pasta raiz
   - Conteudo
      - Problema
         - problem
         - submission
         - answer
         - input
         - expected_output
```

 - Para ler o problema, deve-se abrir o arquivo no caminho `Conteudo\Problema\problem`.
 Por exemplo, para verificar o problema de *Highest Paid Tool*, deve-se navegar até `Grafos2_Dijkstra-Kruskall-SCC/Dijkstra/HighestPaidTool/problem.png`
 
 - A solução está presente no `Conteudo\Problema\answer`. 
 Por exemplo, para verificar o código, deve-se navegar até `Grafos2_Dijkstra-Kruskall-SCC/Dijkstra/HighestPaidTool/answer.cpp`
 
## Executando

Para executar qualquer uma das soluções, deve-se ir até a pasta do Problema, de acordo com a especificação anterior.

### Compilando

```c++ problem.cpp -o prog ```

### Executando

``` ./prog < input.txt > output.txt ```

### Comparando respostas

``` diff output.txt expected_output.txt```

## Extras

Algumas soluções foram implementadas em duas linguagens, em C++ e em Python3.
Para executar as implementações realizadas em Python, é necessário ter o Python3 instalado e então rodar o comando
```
python3 answer.py < input.txt > output.txt
```
E então executar o ``` diff output.txt expected_output.txt```, para verificar as respostas.

Lembrando que a forma como o python é chamado depende de como ele foi configurado em cada máquina, podendo existir variações.
