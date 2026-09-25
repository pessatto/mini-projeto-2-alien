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

// Função 6
void trocarMetades(char *s)
{
    int i;
    char temp;
    int tam = meu_strlen(s);
    int metade = tam / 2;
    metade = (tam % 2 == 0) ? metade : metade + 1;
    for (i = 0; i < metade - 1; i++)
    {
        temp = s[i];
        s[i] = s[i + metade];
        s[i + metade] = temp;
    }
}

int main()
{
    int Operacao, tamanho_string = 0, j = 0, deslocar_qntd;
    char string[10000];

    scanf("%[^\n]", string);
    scanf("%d", &Operacao);

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
            /* Trocar Pares */
            break;

        case 4:
            inverterCaixa(string);
            break;

        case 5:
            /* Rotacionar msg */
            break;

        case 6:
            trocarMetades(string);
            break;

        default:
            break;
        }
        scanf("%d", &Operacao);
    }

    // imprimir resultado
    printf("%s\n", string);

    return 0;
}
