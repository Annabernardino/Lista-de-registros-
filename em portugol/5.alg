Algoritmo Exercicios5
    Tipo Habitante = Registro
        salario : Real
        idade : Inteiro
        sexo : Caracter // 'M' ou 'F'
        numFilhos : Inteiro
    FimRegistro

    Var
        h : Habitante
        somaIdadeMulheres300, qtdMulheres300 : Inteiro
        somaSalario, maiorSalario : Real
        somaFilhos, menorIdade, totalPessoas : Inteiro
        continuar : Caracter

Inicio
    somaIdadeMulheres300 <- 0
    qtdMulheres300 <- 0
    somaSalario <- 0
    somaFilhos <- 0
    totalPessoas <- 0
    maiorSalario <- -1.0
    menorIdade <- 999

    Repita
        totalPessoas <- totalPessoas + 1
        EscrevaL("--- Habitante ", totalPessoas, " ---")
        Escreva("Salário: R$ ")
        Leia(h.salario)
        Escreva("Idade: ")
        Leia(h.idade)
        Escreva("Sexo (M/F): ")
        Leia(h.sexo)
        Escreva("Número de Filhos: ")
        Leia(h.numFilhos)

        // a. Média de idade das mulheres com salário < 300
        Se (h.sexo = 'F') e (h.salario < 300.0) Entao
            somaIdadeMulheres300 <- somaIdadeMulheres300 + h.idade
            qtdMulheres300 <- qtdMulheres300 + 1
        FimSe

        // b e c. Soma de salário e filhos
        somaSalario <- somaSalario + h.salario
        somaFilhos <- somaFilhos + h.numFilhos

        // d. Maior salário
        Se h.salario > maiorSalario Entao
            maiorSalario <- h.salario
        FimSe

        // e. Menor idade
        Se h.idade < menorIdade Entao
            menorIdade <- h.idade
        FimSe

        Escreva("Deseja cadastrar outro habitante? (S/N): ")
        Leia(continuar)
    Ate (continuar = 'N') ou (continuar = 'n')

    EscrevaL("\n=== RESULTADOS DA PESQUISA ===")
    
    Se qtdMulheres300 > 0 Entao
        EscrevaL("a. Média de idade das mulheres com salário < R$ 300: ", somaIdadeMulheres300 / qtdMulheres300)
    Senao
        EscrevaL("a. Nenhuma mulher com salário < R$ 300 cadastrada.")
    FimSe

    EscrevaL("b. Média de salário da população: R$ ", somaSalario / totalPessoas)
    EscrevaL("c. Média do número de filhos: ", somaFilhos / totalPessoas)
    EscrevaL("d. Maior salário: R$ ", maiorSalario)
    EscrevaL("e. Menor idade: ", menorIdade)
FimAlgoritmo