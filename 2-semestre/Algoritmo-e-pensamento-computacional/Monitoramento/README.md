# Desafio de Monitoramento em C

## 1. Identificação

**Aluno:** Lucas Emanuel Martins Beserra

**Disciplina:** Algoritmos e Pensamento Computacional

**Professora:** Profa. Karla Sartin

**Título:** Desafio de Monitoramento de Temperaturas

---

## 2. Objetivo

O projeto tem como objetivo desenvolver um programa em linguagem C capaz de realizar o monitoramento de temperaturas informadas pelo usuário.

O programa recebe um limite de temperatura, realiza leituras sucessivas, identifica temperaturas acima desse limite, controla a quantidade de ocorrências consecutivas e encerra automaticamente o monitoramento quando são registradas três temperaturas consecutivas acima do limite.

Ao final, o programa apresenta um relatório com os principais dados das temperaturas válidas registradas.

---

## 3. Funcionamento do programa

### Definição do limite de temperatura

Inicialmente, o programa solicita ao usuário que informe o limite de temperatura.

O limite é validado e deve estar entre **-100 °C e 200 °C**. Caso seja informado um valor fora dessa faixa ou uma entrada que não seja numérica, o programa informa o erro e solicita uma nova entrada.

### Realização das leituras

Após a definição do limite, o programa entra em um processo de monitoramento contínuo.

A cada repetição, o usuário informa uma nova temperatura. Apenas temperaturas válidas são utilizadas nos cálculos do relatório final.

### Tratamento de valores inválidos

Caso o usuário informe um valor que não seja numérico ou uma temperatura fora da faixa permitida de **-100 °C a 200 °C**, o programa informa que a entrada é inválida e solicita uma nova leitura.

Essas entradas inválidas não são contabilizadas nos cálculos.

### Identificação de temperaturas acima do limite

Após cada leitura válida, o programa compara a temperatura informada com o limite definido pelo usuário.

Quando a temperatura é maior que o limite:

* a quantidade de temperaturas acima do limite é incrementada;
* o contador de temperaturas consecutivas é incrementado;
* uma mensagem de alerta é exibida.

Quando a temperatura está dentro ou abaixo do limite, o contador de consecutivas é reiniciado para zero.

### Contagem de temperaturas consecutivas

O programa utiliza uma variável chamada `consecutivas` para controlar quantas temperaturas acima do limite foram registradas em sequência.

Por exemplo:

```text
Temperatura acima
Temperatura acima
Temperatura dentro do limite
```

Nesse caso, a sequência é interrompida e o contador volta para zero.

### Condição de encerramento

O monitoramento é encerrado automaticamente quando o contador atinge **3 temperaturas consecutivas acima do limite**.

Ao final, é apresentado um relatório contendo:

* quantidade de temperaturas válidas;
* maior temperatura;
* menor temperatura;
* média das temperaturas;
* quantidade de temperaturas acima do limite;
* percentual de temperaturas acima do limite;
* motivo do encerramento.

---

## 4. Estruturas de repetição utilizadas

### `do...while`

A estrutura `do...while` foi utilizada na definição do limite de temperatura.

Ela é adequada nesse caso porque o programa precisa solicitar o limite pelo menos uma vez e continuar solicitando enquanto o valor informado for inválido.

Trecho utilizado:

```c
do {
    // solicitação e validação do limite
} while (limite < -100 || limite > 200);
```

### `while`

A estrutura `while` foi utilizada no monitoramento das temperaturas.

Ela mantém o programa executando enquanto o número de temperaturas consecutivas acima do limite for menor que 3.

Trecho utilizado:

```c
while (consecutivas < 3) {
    // leitura e processamento das temperaturas
}
```

### Justificativa

A escolha das duas estruturas foi feita de acordo com o funcionamento do problema.

O `do...while` é adequado para a definição do limite porque a entrada deve acontecer antes da primeira verificação.

Já o `while` é adequado para o monitoramento porque a condição de continuação deve ser verificada antes de cada nova leitura.

---

## 5. Como executar

### Compilação

Com o GCC instalado, abra o terminal na pasta do projeto e execute:

```bash
gcc monitoramento.c -o monitoramento
```

### Execução no Windows

```bash
monitoramento.exe
```

### Execução no Linux ou macOS

```bash
./monitoramento
```

---

## 6. Testes realizados

### Teste 1 — Validação de entradas inválidas

Foi testada a entrada de valores inválidos para verificar se o programa identifica corretamente os dados incorretos e solicita uma nova entrada.

**Resultado esperado:** o programa deve informar que a entrada é inválida e não deve considerar o valor nos cálculos.

![Teste 1](evidencias/teste01.png)

---

### Teste 2 — Temperaturas acima do limite, porém não consecutivas

Foi definido um limite de temperatura e inseridas temperaturas acima desse limite de forma não consecutiva, intercaladas por temperaturas dentro ou abaixo do limite.

Exemplo:

```text
Limite: 30 °C

35 °C
25 °C
40 °C
20 °C
```

**Resultado esperado:** o contador de temperaturas consecutivas deve ser reiniciado sempre que uma temperatura não estiver acima do limite, impedindo o encerramento automático.

![Teste 2](evidencias/teste02.png)

---

### Teste 3 — Três temperaturas consecutivas acima do limite

Foi definido um limite e inseridas três temperaturas consecutivas acima dele.

Exemplo:

```text
Limite: 30 °C

35 °C
40 °C
32 °C
```

**Resultado esperado:** ao atingir três temperaturas consecutivas acima do limite, o programa deve encerrar automaticamente o monitoramento e apresentar o relatório final.

![Teste 3](evidencias/teste03.png)

---

## 7. Evidências

As capturas de tela dos testes realizados estão armazenadas na pasta:

```text
evidencias/
```

Estrutura:

```text
evidencias/
├── teste01.png
├── teste02.png
└── teste03.png
```

---

## 8. Reflexão final

Escolhi utilizar uma combinação de `do...while` e `while` porque cada estrutura se adapta melhor a uma parte do algoritmo.

O `do...while` foi utilizado para validar o limite de temperatura, pois o programa precisa realizar a primeira solicitação antes de verificar se o valor é válido.

O `while` foi utilizado para o monitoramento porque a condição de continuidade precisa ser verificada antes de cada nova leitura. Dessa forma, quando o contador chega a três temperaturas consecutivas acima do limite, o laço deixa de executar e o programa apresenta o relatório final.

A diferença entre testar a condição antes ou depois da execução foi importante principalmente na validação do limite, pois essa informação precisa ser solicitada ao usuário pelo menos uma vez antes da verificação.

---

## 9. Autor

**Lucas Emanuel**

Projeto desenvolvido como atividade acadêmica do curso de **Engenharia de Software**.
