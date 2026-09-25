#include <stdio.h>

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

//Função 4
void inverterCaixa(char *s)
{
    int i = 0;
    while (s[i] != '\0')
    {
        if (65 <= s[i] && s[i] <= 90)
        {
            s[i]+= 32;
        }
        else if(97 <= s[i] && s[i] <= 122)
        {
            s[i] -=32;
        }
        i++;
    }
}


int main()
{
    int Operacao;
    char string[10000];

    scanf("%[^\n]", string);
    scanf("%d", &Operacao);
    

    while(Operacao != 0)
    {
        switch (Operacao)
        {
        case 1:
            inverter(string);
            break;

        case 2:
            /* Deslocar Caracter */
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
            /* Trocar Metades */
            break;
        
        default:
            break;
        }
        scanf("%d", &Operacao);
    }

    //imprimir resultado
    printf("%s\n", string);


    return 0;
}
