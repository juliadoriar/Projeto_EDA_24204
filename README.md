
# Projeto_EDA_24204

1. Este é um projeto de avaliação da unidade curricular Estrutura de Dados, lecionada pelo professor Luís Ferreira, do curso de Licenciatura em Engenharia de Sistemas Informáticos pelo Instituto Politécnico do Cávado e Ave.

    O projeto consiste na aplicação de conhecimentos de programação em C para o desenvolvimento de um programa capaz de implementar soluções na área da micromobilidade.

# Estrutura

## Ficheiros .h
1. FunctionsClientes.h - Biblioteca com assinatura das funções e estruturas dos clientes

2. FunctionsAlugueres.h - Biblioteca com assinatura das funções e estruturas dos alugueres

3. FunctionsMeios.h - Biblioteca com assinatura das funções e estruturas dos meios de mobilidade

4. FunctiosGestores.h - Biblioteca de funções dos gestores

5. Grafos.h - Biblioteca com as estruturas de vertices e adjacencias, e as assinaturas de todas as funções referentes aos grafos (vertices, adjacencias, recursivas, etc.)

## Ficheiros.c 
1. Functions.c - Este ficheiro em C contém todas as funções que serão chamadas na main, seja de forma direta ou recursiva. Ele utiliza as duas bibliotecas já mencionadas.

2. FunctiosGestores.c - Funções de criação dos gestores

3. FunctionsMeios.c - Funções relacionadas a criação e demais gestões dos Meio de mobilidade.

4. FunctionsClientes.c - Funções relacionadas a criação e demais gestões dos clientes.

5. FunctionsAlugueres.c - Funções relacionadas a criação e demais gestões dos alugueres.

6. Grafos.c - Funções relacionadas a criação e demais gestões dos grafos.

7. Main.c - Esta é a main, responsável por passar todos os parâmetros das funções, devolvendo resultados em memória, em tela ou em ficheiros binários ou de texto, assim como lendo tais ficheiros.

## Ficheiros .bin 
O projeto possui alguns ficheiros binários que são criados ao longo do código e guardam as informações fornecidas preservando dados.

## Ficheiros .txt 
Assim como os ficheiros binários, os ficheiros de texto guardam informações que podem ser lidas pelo código, atribuindo valores pré estabelecidos, assim como guardando informações novas.

## Fases 
O projeto é divido em duas fases, que podem ser analizadas nas regiões da Main. 
A primeira fase se propõe a crias as litas ligadas de clientes, meios e alugueres, e realizar diversas funções com essas.
A segunda fase é responsável pela implementação dos grafos e funções relacionadas.


## Funcionalidades

- Inicialmente, é capaz de cadastrar novos clientes, meios de mobilidade e um gestor por meio de structs.
- Ao cadastrar, aloca cada uma das structs em suas respectivas listas.
- Guarda todas as listas em ficheiros de texto e ficheiros binários.
- Remove um nó de uma lista, a partir do parâmetro passado.
- Altera dados de um nó a partir do parâmetro passado.
- Ordena os meios de mobilidade em uma lista em ordem decrescente a partir do parâmetro autonomia.



## Aprendizados

O projeto trouxe a urgência em conhecer como funcionam as listas e como manipular cada uma delas.

A maior dificuldade encontrada foi entender a funcionalidade dos ponteiros e fazer bom uso deles para um código mais limpo e fluido.

Ao fim desta primeira fase, foi possível compreender além das listas e ponterios, também como passar parâmetros para testar cada função, sem usos exagerados de funções de output como printf.


## Autores

- [@juliadoriar](https://github.com/juliadoriar)

