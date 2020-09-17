# **_Branch-and-bound_ para o problema da mochila 0-1**

## **Resumo**

Criar um programa em C/C++ que resolve o problema de mochila 0-1, e deve funcionar conforme a videoconferência do dia 03/09.

A relaxação Linear do problema deve ser resolvida usando o algoritmo guloso mostrado na videoaula.

Cada variável possui prioridades, determinadas pela razão custo/peso, quanto maior a razão, maior a prioridade.

Ver o PDF do professor para mais detalhes sobre como o programa deve funcionar.

## **Ideias**

    1. Ler o arquivo de entrada
    2. Passar para uma matriz (alocada dinamicamente?)
    3. Criar vetores para 
       - Função objeitvo
       - Variáveis de decisão
       - Variáveis ordenadas de acordo com a prioridade (ordem de ramificação)
       - Dizer as variáveis que foram avaliadas
       - Dizer as variáveis que não foram avaliadas
       - Ou então criar um vetor de valor 0 ou 1 (ou 1 e -1) para dizer se aquela variável foi ou não avaliada (ideia minha)
    4. Implementar os nós (?)
    5. Tempo total decorrido (biblioteca)
    6. Função que printa informações a cada 100 nós

### **Entregar até dia 16 de outubro de 2020 as 23:59**
