#include <stdio.h>

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

    while (*(s + j) != '\0')
    {
        j++;
    }
    j--;

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
    int n_letra = n % 26;
    int n_digito = n % 10;
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
        n += tam; // em vez de rodar pra esquerda, vai rodar a mesma quantidade para a direita
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
    int Operacao, deslocar_qntd, rotacionar_qntd;
    char string[10000];

    // Leitura de entradas
    scanf("%[^\n]", string);
    scanf("%d", &Operacao);

    // Uso das funções
    while (Operacao != 0)
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
            break;
        }
        scanf("%d", &Operacao);
    }

    // Imprimir mensagem descriptografada
    printf("%s\n", string);

    return 0;
}
