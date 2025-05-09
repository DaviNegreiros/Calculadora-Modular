#include <stdio.h>
#include <math.h> //para fazer o pow

//acentos!!
#ifdef _WIN32
#include <windows.h>
#endif


int restos[100], quocientes[100], A1s[100], B1s[100], G;
int H, Zn, a, x, n1, x1, q, r, x2, k, k_, retornoFinal;


int mdc(int a,int  b){ //algoritmo de euclides
    int resto = a % b;
    printf("Algorítmo de Euclides: %d mod %d = %d\n", a, b, resto);
    if (resto == 0){
        return b;
    } else{
        return mdc(b, resto);
    }
}

int inverso(int a, int Z){
    int resto = 99, k = Z, i = 0, contagem = 0;
    
    while(resto != 0){
        resto = a % k;
        A1s[i] = a;
        B1s[i] = k;
        restos[i] = resto;
        quocientes[i] = a / k;
        a = k;
        k = resto;
        contagem = i;
        i++;
    }

    int X = 0, Y = 1, temp;
    for (int j = contagem - 1; j >= 0; j--){
        temp = X;
        X = Y;
        Y = temp - quocientes[j] * Y;
    }

    int inverso = (X % Z + Z) % Z;
    return inverso;
}



int multMod(int a, int b, int Z){
    printf("\nFazendo a multiplicação modular: %d * %d mod %d\n Sendo %d o inverso de %d.\n\n", a, b, Z, b, G);
    return (a * b) % Z;
}

int primo(int n) {
    if (n <= 3) return 1; 
    if (n <= 1 || n % 2 == 0 || n % 3 == 0) return 0;
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0){
        printf("\n%d é divisível por %d, logo, %d não é primo.\n\n", n, i, n);
            return 0;
        }
    }
    printf("\n%d é primo, pois não é divisível por nenhum número fora 1 e %d.\n\n", n, n);
    return 1;
}

int fi(int n){
    int contador = 0;
    for (int i = 1; i <= n; i++){
        if(mdc(n, i) == 1){
            contador++;
            printf("\nmdc(%d, %d) = 1, logo %d é coprimo de %d.\n\n", n, i, i, n);
        }
    }
    printf("\nO número %d tem %d coprimos.\n\n", n, contador);
    return contador;
}

int modularExpo(int base, int exp, int mod) {
    int result = 1;
    base = base % mod;
    while (exp > 0) {
        if (exp % 2 == 1)
            result = (result * base) % mod;
        exp = exp / 2;
        base = (base * base) % mod;
    }
    return result;
}

int main(){
    //Acentos!!
    #ifdef _WIN32
        SetConsoleOutputCP(CP_UTF8); // Usa a API do Windows pra colocar codificação UTF-8 
    #endif
    // Fim acentos!!


    printf("\nInsira as váriaveis de acordo com o formato:\n");
    printf("H divisão modular G em Zn\n");
    printf("a^x mod n1\n\n");

    printf("Insira H: ");
    scanf("%d", &H);

    printf("Insira G: ");
    scanf("%d", &G);

    printf("Insira Zn: ");
    scanf("%d", &Zn);

    printf("Insira x: ");
    scanf("%d", &x);

    printf("Insira n1: ");
    scanf("%d", &n1);
    printf("\n");
    if(mdc(G, Zn) != 1){
        printf("\nNão existe inverso, pois mdc(%d, %d) = %d.\n\n", G, Zn, mdc(G, Zn));
        return 0;
    }
    int inv = inverso(G, Zn);
    printf("\nSubstituindo, temos que o inverso de %d em %d é %d.\n\n", G, Zn, inv);
    a = multMod(H, inv, Zn);
    if(mdc(a, n1) == 1){
        if(primo(n1)){
            printf("\nVamos aplicar o Pequeno Teorema de Fermat.\n\n");
            x1 = n1 - 1;
        } else{
            printf("\nVamos aplicar o Teorema de Euler.\n\n");
            x1 = fi(n1);
        }
    } else {
        printf("\nNão é possível aplicar os teoremas, pois %d e %d não são coprimos.\n\n", a, n1);
        return 0;
    }

    q = x / x1;
    r = x % x1;

    printf("\n%d^%d ≡ ( ((%d^%d)%d mod %d) * (%d^%d mod %d) ) mod %d\n\n", a, x, a, x1, q, n1, a, r, n1, n1);

    x2 = modularExpo(a, x1, n1);
    k = modularExpo(x2, q, n1);
    k_ = modularExpo(a, r, n1);

    retornoFinal = (k * k_) % n1;

    printf("\n\nValor final da congruência: %d\n", retornoFinal);

    return retornoFinal; //caso queira aplicar em algum lugar dps
}
