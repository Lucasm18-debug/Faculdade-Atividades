# PROJETO: GERENCIADOR DE SENHAS

Empresa: Tia Karla Soluções\
Linguagem de programação: C\
Desenvolvedor: Programador Trainee

## 1. Apresentação do projeto

O projeto consiste no desenvolvimento de um Gerenciador de Senhas utilizando a linguagem C. O objetivo é criar um sistema que permita ao usuário cadastrar, armazenar, consultar, editar e excluir senhas de diferentes serviços e plataformas, facilitando a organização de suas informações de acesso.

O sistema será desenvolvido com uma estrutura modularizada, dividindo o código em funções independentes, cada uma responsável por uma tarefa específica. Essa organização facilita a manutenção, a identificação de erros e a implementação de melhorias futuras.

## 2. Principais funcionalidades

O programa contará com as seguintes funcionalidades:

- Cadastrar senhas: permite registrar o nome do serviço, o nome de usuário e a respectiva senha.
- Listar senhas: apresenta todos os registros cadastrados.
- Pesquisar senhas: permite localizar um cadastro específico pelo nome do serviço.
- Editar senhas: possibilita modificar o usuário ou a senha de um registro existente.
- Excluir senhas: permite remover um cadastro selecionado.
- Salvar informações: armazena os registros em um arquivo para que permaneçam disponíveis após o encerramento do programa.
- Carregar informações: recupera automaticamente os registros salvos quando o programa é iniciado.

## 3. Bibliotecas utilizadas

Para o desenvolvimento do projeto, serão utilizadas as seguintes bibliotecas:

- stdio.h: responsável pelas operações de entrada e saída de dados, leitura e escrita em arquivos.
- stdlib.h: disponibiliza funções gerais, como conversão de valores e gerenciamento de memória.
- string.h: permite manipular e comparar textos, sendo utilizada para trabalhar com nomes de serviços, usuários e senhas.

Essas bibliotecas fornecem os recursos necessários para desenvolver a estrutura inicial do sistema.

## 4. Estrutura e modularização do código

O código será desenvolvido seguindo o conceito de programação modular, que consiste em dividir o programa em partes menores e independentes, chamadas funções ou módulos.

Cada módulo terá uma responsabilidade específica, evitando que todas as operações fiquem concentradas na função principal (`main()`).

A estrutura será organizada da seguinte maneira:

| Módulo/Função       | Responsabilidade                                            |
| ------------------- | ----------------------------------------------------------- |
| `main()`            | Controlar o programa e apresentar o menu principal.         |
| `cadastrarSenha()`  | Realizar o cadastro de novas senhas.                        |
| `listarSenhas()`    | Exibir os registros cadastrados.                            |
| `pesquisarSenha()`  | Localizar uma senha específica.                             |
| `editarSenha()`     | Modificar informações de um cadastro.                       |
| `excluirSenha()`    | Remover registros existentes.                               |
| `salvarArquivo()`   | Gravar os dados em um arquivo.                              |
| `carregarArquivo()` | Recuperar os dados armazenados.                             |
| `buscarSenha()`     | Localizar a posição de um registro no vetor.                |
| `lerTexto()`        | Padronizar a leitura de informações digitadas pelo usuário. |

Além das funções, será utilizada uma estrutura de dados (`struct`) para organizar as informações de cada cadastro, contendo três campos principais: serviço, usuário e senha.

Os registros serão armazenados em um vetor, permitindo gerenciar vários cadastros durante a execução do programa.

## 5. Organização dos arquivos do projeto

Para garantir uma melhor organização, o projeto poderá ser dividido em diferentes arquivos:

- `main.c`: contém a função principal e o menu do sistema.
- `senhas.h`: contém a definição da estrutura de dados e os protótipos das funções.
- `senhas.c`: contém a implementação das funções de cadastro, pesquisa, edição, exclusão e listagem.
- `arquivo.c`: contém as funções responsáveis por salvar e carregar os registros.
- `senhas.txt`: arquivo utilizado para armazenar os dados cadastrados.

Essa divisão permite separar as responsabilidades do sistema e facilita futuras alterações sem a necessidade de modificar todo o código.

## 6. Segurança do sistema

Por se tratar de um programa que trabalha com informações confidenciais, a segurança será considerada uma parte importante do desenvolvimento.

Como melhorias futuras, poderão ser implementados:

- Sistema de autenticação por senha principal.
- Criptografia das senhas armazenadas.
- Validação das informações inseridas.
- Controle de acesso aos registros.

A primeira versão será desenvolvida como protótipo funcional, não sendo recomendada para armazenar senhas reais antes da implementação dos mecanismos de proteção.

## 7. Conclusão

O desenvolvimento do Gerenciador de Senhas permitirá aplicar conhecimentos fundamentais da linguagem C, como estruturas de dados, funções, vetores, condicionais, estruturas de repetição e manipulação de arquivos.

A utilização da programação modular será fundamental para garantir que o sistema tenha uma estrutura organizada, facilitando sua compreensão, manutenção e expansão.

Dessa forma, a proposta é entregar à Tia Karla Soluções um sistema funcional, organizado e com possibilidade de melhorias futuras, atendendo à necessidade de gerenciamento de senhas de maneira prática e eficiente.
