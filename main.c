#include <stdio.h>
#include <stdio.h>
#define MAX 100

void desloca_direita(int v[], int n) {
    int ultimo = v[n - 1];
    for (int i = n - 1; i > 0; i--)
        v[i] = v[i - 1];
    v[0] = ultimo;
}

void desloca_esquerda(int v[], int n) {
    int primeiro = v[0];
    for (int i = 0; i < n - 1; i++)
        v[i] = v[i + 1];
    v[n - 1] = primeiro;
}

int main() {
    int v[MAX], n, i;

    scanf("%d", &n);
    for (i = 0; i < n; i++)
        scanf("%d", &v[i]);

    /* 6 e 7: maior, menor e índices da primeira ocorrência */
    int maior = v[0], menor = v[0], im = 0, in = 0;
    for (i = 1; i < n; i++) {
        if (v[i] > maior) { maior = v[i]; im = i; }  /* ">" estrito mantém a primeira ocorrência */
        if (v[i] < menor) { menor = v[i]; in = i; }
    }
    printf("Maior: %d (indice %d)\n", maior, im);
    printf("Menor: %d (indice %d)\n", menor, in);

    /* 8: positivos, negativos e zeros */
    int pos = 0, neg = 0, zer = 0;
    for (i = 0; i < n; i++) {
        if (v[i] > 0) pos++;
        else if (v[i] < 0) neg++;
        else zer++;
    }
    printf("Positivos: %d, Negativos: %d, Zeros: %d\n", pos, neg, zer);

    /* 9: quantas vezes um número aparece */
    int x, cont = 0;
    scanf("%d", &x);
    for (i = 0; i < n; i++)
        if (v[i] == x) cont++;
    printf("%d aparece %d vez(es)\n", x, cont);

    /* 10: trocar duas posições */
    int a, b, aux;
    scanf("%d %d", &a, &b);
    if (a >= 0 && a < n && b >= 0 && b < n) {
        aux = v[a];
        v[a] = v[b];
        v[b] = aux;
    }

    /* 11: inverter no próprio vetor (só vai até a metade) */
    for (i = 0; i < n / 2; i++) {
        aux = v[i];
        v[i] = v[n - 1 - i];
        v[n - 1 - i] = aux;
    }

    /* 12: deslocamento circular */
    desloca_direita(v, n);
    desloca_esquerda(v, n);   /* volta ao estado anterior */

    for (i = 0; i < n; i++)
        printf("%d ", v[i]);
    printf("\n");
    return 0;
}

#include <stdio.h>
#define MAX 100

int tamanho(char s[]) {
    int i = 0;
    while (s[i] != '\0') i++;
    return i;
}

int main() {
    char s[MAX], t[MAX], c, novo;
    int i;

    /* leitura com espaços, ignorando espaços/quebras antes */
    scanf(" %99[^\n]", s);

    /* 21: substituir um caractere por outro */
    scanf(" %c %c", &c, &novo);
    for (i = 0; s[i] != '\0'; i++)
        if (s[i] == c) s[i] = novo;
    printf("%s\n", s);

    /* 22: contar um caractere (== já diferencia maiúscula de minúscula) */
    int cont = 0;
    scanf(" %c", &c);
    for (i = 0; s[i] != '\0'; i++)
        if (s[i] == c) cont++;
    printf("'%c' aparece %d vez(es)\n", c, cont);

    /* 23: imprimir invertida sem modificar */
    for (i = tamanho(s) - 1; i >= 0; i--)
        printf("%c", s[i]);
    printf("\n");

    /* 24: inverter no próprio vetor */
    int n = tamanho(s), aux;
    for (i = 0; i < n / 2; i++) {
        aux = s[i];
        s[i] = s[n - 1 - i];
        s[n - 1 - i] = aux;
    }
    printf("%s\n", s);

    /* 25: comparar duas strings */
    scanf(" %99[^\n]", t);
    i = 0;
    while (s[i] != '\0' && t[i] != '\0' && s[i] == t[i])
        i++;
    if (s[i] == t[i])   /* os dois chegaram ao '\0' juntos */
        printf("Iguais\n");
    else
        printf("Diferentes\n");

    /* 26: três strings, uma por linha */
    char a[MAX], b[MAX], d[MAX];
    scanf(" %99[^\n]", a);
    scanf(" %99[^\n]", b);
    scanf(" %99[^\n]", d);
    printf("%s\n%s\n%s\n", a, b, d);

    return 0;
}

// Função Auxiliar Tamanho da String
int meu_strlen(char *s)
{
    int tam = 0, j = 0;
    while (s[j] != '\0')
    {
        tam++;
        j++;
    }
    return tam;
}

// Função 1
void inverter(char *s)
{
    int i = 0, j = 0;
    char temp;

    j = meu_strlen(s) - 1;

    while (i < j)
    {
        temp = *(s + i);
        *(s + i) = *(s + j);
        *(s + j) = temp;

        i++;
        j--;
    }
}

// Função 2
void deslocar(char *s, int n)
{
    int i, valor_passou, valor_coube;
    int n_letra = ((n % 26) + 26) % 26;  /* evita rotações completas */
    int n_digito = ((n % 10) + 10) % 10; /* em vez de deslocar pra esquerda,
    vai deslocar a mesma quantidade para a direita */

    for (i = 0; *(s + i) != '\0'; i++)
    {
        if (*(s + i) >= 'a' && *(s + i) <= 'z')
        {
            if ((*(s + i) + n_letra) > 'z')
            {
                valor_passou = (*(s + i) + n_letra) - 'z';
                valor_coube = n_letra - valor_passou;
                *(s + i) += valor_coube;
                *(s + i) = ('a' - 1) + valor_passou;
            }
            else
            {
                *(s + i) += n_letra;
            }
        }
        else if (*(s + i) >= 'A' && *(s + i) <= 'Z')
        {
            if ((*(s + i) + n_letra) > 'Z')
            {
                valor_passou = (*(s + i) + n_letra) - 'Z';
                valor_coube = n_letra - valor_passou;
                *(s + i) += valor_coube;
                *(s + i) = ('A' - 1) + valor_passou;
            }
            else
            {
                *(s + i) += n_letra;
            }
        }
        else if (*(s + i) >= '0' && *(s + i) <= '9')
        {
            if ((*(s + i) + n_digito) > '9')
            {
                valor_passou = (*(s + i) + n_digito) - '9';
                valor_coube = n_digito - valor_passou;
                *(s + i) += valor_coube;
                *(s + i) = ('0' - 1) + valor_passou;
            }
            else
            {
                *(s + i) += n_digito;
            }
        }
    }
}

// Função 3
void trocarParesImpares(char *s)
{
    int i;
    char temp;
    int limite = meu_strlen(s);

    limite = (limite % 2 == 0) ? limite : limite - 1;
    for (i = 0; i < limite; i += 2)
    {
        temp = s[i];
        s[i] = s[i + 1];
        s[i + 1] = temp;
    }
}

// Função 4
void inverterCaixa(char *s)
{
    int i = 0;
    while (s[i] != '\0')
    {
        if (65 <= s[i] && s[i] <= 90)
        {
            s[i] += 32;
        }
        else if (97 <= s[i] && s[i] <= 122)
        {
            s[i] -= 32;
        }
        i++;
    }
}
// Função 5
void rotacionar(char *s, int n)
{
    int tam = meu_strlen(s);
    int i, j;
    char ultimo;

    if (tam <= 1)
    {
        return;
    }

    n = n % tam; // evita rotações completas

    if (n < 0)
    {
        n += tam; /* em vez de rodar pra esquerda, vai rodar a mesma
        quantidade para a direita */
    }

    for (i = 0; i < n; i++)
    {
        ultimo = *(s + tam - 1);

        for (j = tam - 1; j > 0; j--)
        {
            *(s + j) = *(s + j - 1);
        }

        *(s) = ultimo;
    }
}

// Função 6
void trocarMetades(char *s)
{
    int i;
    char temp;
    int tam = meu_strlen(s);
    int metade = tam / 2;

    metade = (tam % 2 == 0) ? metade : metade + 1;

    if (tam % 2 == 0)
    {
        for (i = 0; i < metade; i++)
        {
            temp = s[i];
            s[i] = s[i + metade];
            s[i + metade] = temp;
        }
    }
    else
    {
        for (i = 0; i < metade - 1; i++)
        {
            temp = s[i];
            s[i] = s[i + metade];
            s[i + metade] = temp;
        }
    }
}

int main()
{
    int Operacao, deslocar_qntd, rotacionar_qntd, rodar = 1;
    char string[10000];

    scanf("%[^\n]", string);
    scanf("%d", &Operacao);

    while (Operacao != 0 && rodar == 1)
    {
        switch (Operacao)
        {
        case 1:
            inverter(string);
            break;

        case 2:
            scanf("%d", &deslocar_qntd);
            deslocar(string, deslocar_qntd);
            break;

        case 3:
            trocarParesImpares(string);
            break;

        case 4:
            inverterCaixa(string);
            break;

        case 5:
            scanf("%d", &rotacionar_qntd);
            rotacionar(string, rotacionar_qntd);
            break;

        case 6:
            trocarMetades(string);
            break;

        default:
            rodar = 0;
            break;
        }
        if (rodar == 1)
        {
            scanf("%d", &Operacao);
        }
    }

    // imprimir resultado
    printf("%s\n", string);

    return 0;
}
