# Mini Projeto 02 - Central de Comunicações Alienígenas

## Identificação

- João Pedro Mendonça Pessatto
- Eduardo Rezende Matos

## Como compilar e rodar

Compilar:

```
gcc main.c -o main
```

Para rodar:

```
./main
```

O programa lê tudo pela entrada padrão, então dá pra digitar direto no terminal.

## Visão geral do programa

A ideia é bem simples: o programa lê uma mensagem e depois vai aplicando, operação por operação, conforme o usuário for digitando, até aparecer um `0` (ou qualquer número que não seja uma operação válida).

Na `main` o fluxo é:

1. Lê a mensagem inicial até o `\n`.
2. Lê o primeiro código de operação.
3. Enquanto o código for de `1` a `6`, entra no `switch`, chama a função da operação correspondente, passando a string por ponteiro pra função mexer direto na memória, e lê o próximo código. Nas operações 2 e 5 lê também o `n` já dentro do switch.
4. Se vier um código inválido ou `0`, para o laço.
5. No final só dá `printf` da string, que já foi sendo modificada esse tempo todo.

A `main` não faz nenhuma conta de string, só controla a leitura e chama as funções. Toda a lógica de manipulação está dentro de cada função, que recebe a string por ponteiro.

## Decisões de implementação

**`meu_strlen`**: como não podia usar `string.h`, fizemos uma função de tamanho pra reaproveitar nas funções que precisam saber o tamanho da string (`inverter`, `trocarParesImpares`, `rotacionar`, `trocarMetades`), em vez de ficar contando de novo em cada uma.

**`inverter`**: usa um índice no começo e outro no final da string (calculado com o meu_strlen) e vai trocando os dois de fora pra dentro até eles se encontrarem no meio.

**`deslocar`**: trata letra maiúscula, minúscula e número separado, cada um com seu próprio "ciclo" (26 letras, 10 dígitos). O que não é letra nem número não muda.

O ponto mais chato foi fazer funcionar com `n` negativo. No começo a gente só tratava o caso de passar do `z`/`Z`/`9`, mas com `n` negativo o valor podia ficar antes do `a`/`A`/`0`, e aí davam caracteres estranhos, tipo `[` no lugar de letra. Resolvemos normalizando o `n` antes de usar, com essa conta:

```
int n_letra = ((n % 26) + 26) % 26;
int n_digito = ((n % 10) + 10) % 10;
```

Isso transforma qualquer `n` (positivo, negativo, ou maior que 26) num valor sempre positivo dentro do intervalo certo, então a lógica de "passar do limite e voltar pro começo" que já tínamos feito funciona igual pros dois casos, sem precisar duplicar código.

**`trocarParesImpares`**: percorre a string de 2 em 2 posições trocando cada par. Se o tamanho for ímpar, o laço para um índice antes do final, então o último caractere fica sem par e não é mexido.

**`inverterCaixa`**: usa direto os números da tabela ASCII (maiúscula é 65 a 90, minúscula é 97 a 122) e soma ou subtrai 32 pra trocar de caixa. O resto dos caracteres passa direto sem alterar.

**`rotacionar`**: a gente fez rotacionando de 1 em 1 posição pra direita, `n` vezes: guarda o último caractere, empurra todo mundo uma posição pra direita, e põe o que guardou lá no começo.

Pra não ficar rodando à toa quando `n` é maior que o tamanho da string, primeiro reduz com `n = n % tam`. E pra tratar rotação negativa (pra esquerda) sem escrever outra função, a gente converte ela numa rotação equivalente pra direita:

```
n = n % tam;
if (n < 0) n += tam;
```

Assim uma rotação de `-2`, por exemplo, numa string de tamanho 6 vira uma rotação de `4` pra direita, que dá exatamente no mesmo resultado.

**`trocarMetades`**: troca a primeira metade da string com a segunda. Se o tamanho é par, é só trocar metade com metade igual (`tam/2` cada). Se for ímpar, calculamos a metade como `tam/2 + 1` mas paramos o laço uma posição antes, pra deixar o caractere bem do meio da string parado no lugar dele, só trocando o que tá antes e depois dele.

**Encerrar o protocolo com código inválido**: o enunciado pede que o programa pare tanto no `0` quanto em qualquer número que não seja uma operação válida. Pra isso usamos uma variável `rodar` que é zerada no `default` do `switch`. Sem isso, se um código inválido fosse o último número do arquivo de entrada, o programa ia tentar ler mais um `scanf` que não existe, e o `while` nunca ia perceber que devia parar, ficando travado num laço infinito.
