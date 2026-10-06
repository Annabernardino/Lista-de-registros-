Algoritmo Exercicios7
    Tipo Paciente = Registro
        nome : Texto
        idade : Inteiro
        sexo : Caracter // 'M' ou 'F'
        peso : Real
        altura : Real
    FimRegistro

    Var
        pacientes : Vetor[1..20] de Paciente
        i, posMaisPesado : Inteiro
        maiorPeso, pesoIdeal, pesoFaltante : Real

    Funcao CalcularPesoIdeal(p : Paciente) : Real
    Inicio
        Se (p.sexo = 'M') ou (p.sexo = 'm') Entao
            Retorne (72.7 * p.altura) - 58
        Senao
            Retorne (62.1 * p.altura) - 44.7
        FimSe
    FimFuncao

Inicio
    // Leitura das informações dos 20 pacientes
    Para i De 1 Ate 20 Faca
        EscrevaL("--- Paciente ", i, " ---")
        Escreva("Nome: ")
        Leia(pacientes[i].nome)
        Escreva("Idade: ")
        Leia(pacientes[i].idade)
        Escreva("Sexo (M/F): ")
        Leia(pacientes[i].sexo)
        Escreva("Peso (kg): ")
        Leia(pacientes[i].peso)
        Escreva("Altura (m): ")
        Leia(pacientes[i].altura)
    FimPara

    // a. Nome da pessoa mais pesada
    posMaisPesado <- 1
    maiorPeso <- pacientes[1].peso
    Para i De 2 Ate 20 Faca
        Se pacientes[i].peso > maiorPeso Entao
            maiorPeso <- pacientes[i].peso
            posMaisPesado <- i
        FimSe
    FimPara
    EscrevaL("\na. Pessoa mais pesada: ", pacientes[posMaisPesado].nome, " com ", maiorPeso, " kg")

    // b. Nomes e idades das pessoas acima do peso ideal
    EscrevaL("\nb. Pessoas ACIMA do peso ideal:")
    Para i De 1 Ate 20 Faca
        pesoIdeal <- CalcularPesoIdeal(pacientes[i])
        Se pacientes[i].peso > pesoIdeal Entao
            EscrevaL("- ", pacientes[i].nome, ", ", pacientes[i].idade, " anos (Peso Atual: ", pacientes[i].peso, "kg | Ideal: ", pesoIdeal:0:2, "kg)")
        FimSe
    FimPara

    // c. Nomes e peso a adquirir para pessoas abaixo do peso ideal
    EscrevaL("\nc. Pessoas ABAIXO do peso ideal:")
    Para i De 1 Ate 20 Faca
        pesoIdeal <- CalcularPesoIdeal(pacientes[i])
        Se pacientes[i].peso < pesoIdeal Entao
            pesoFaltante <- pesoIdeal - pacientes[i].peso
            EscrevaL("- ", pacientes[i].nome, " deve ganhar ", pesoFaltante:0:2, " kg para atingir o peso ideal de ", pesoIdeal:0:2, " kg")
        FimSe
    FimPara
FimAlgoritmo