#include <stdio.h>


int main()
{
    int Operacao;

    scanf("%d", &Operacao);

    while(Operacao != 0)
    {
        switch (Operacao)
        {
        case 1:
            /* Inverter Mensagem */
            break;

        case 2:
            /* Deslocar Caracter */
            break;

        case 3:
            /* Trocar Pares */
            break;
            
        case 4:
            /* Inverter Maiusc/Minusc */
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


    return 0;
}
