# Calculadora Modular

Este projeto é uma **calculadora modular simples**, que realiza cálculos de congruências, inversos modulares e aplica o Pequeno Teorema de Fermat para resolver expressões no formato \(a^x \mod n\). Ele pode ser útil para quem deseja entender ou testar operações modulares em matemática computacional.

## Funcionalidades

- **Cálculo de Inverso Modular**: Calcula o inverso de um número em um determinado módulo usando o **Algoritmo de Euclides**.
- **Multiplicação Modular**: Realiza multiplicações modulares entre números.
- **Pequeno Teorema de Fermat**: Aplica o Teorema de Fermat para resolver expressões modulares quando o módulo é um número primo.
- **Teorema de Euler**: Aplica o Teorema de Euler para calcular inversos modulares em números que não sejam primos.
- **Verificação de Primalidade**: Verifica se o módulo fornecido é um número primo.

## Algoritmos Utilizados

### Algoritmo de Euclides

Usado para calcular o máximo divisor comum (MDC) entre dois números. O Algoritmo de Euclides é essencial para encontrar o **inverso modular** de um número \(a\) módulo \(n\), caso o MDC entre \(a\) e \(n\) seja 1 (ou seja, \(a\) e \(n\) são coprimos).

### Teorema de Euler

Se o módulo \(n\) não for primo, o **Teorema de Euler** é utilizado para calcular o inverso modular. O teorema afirma que, se \(a\) e \(n\) são coprimos, então \(a^{\phi(n)} \equiv 1 \mod n\), onde \(\phi(n)\) é a função totiente de Euler. Usamos este teorema para aplicar a fórmula de inverso modular quando o número \(n\) não for primo.

### Pequeno Teorema de Fermat

Quando o módulo \(n\) é primo, o **Pequeno Teorema de Fermat** pode ser usado para simplificar cálculos modulares, pois o teorema afirma que, para qualquer número \(a\) tal que \(a\) e \(n\) sejam coprimos, temos que \(a^{n-1} \equiv 1 \mod n\).

