Algoritmo Exercício3
    Tipo Horario = Registro
        horas : Inteiro
        minutos : Inteiro
        segundos : Inteiro
    FimRegistro

    Var
        h1, h2, dif : Horario

    // a. Ler as informações
    Procedimento LerHorario(Var t : Horario, num : Inteiro)
    Inicio
        EscrevaL("--- Horário ", num, " ---")
        Escreva("Digite as horas: ")
        Leia(t.horas)
        Escreva("Digite os minutos: ")
        Leia(t.minutos)
        Escreva("Digite os segundos: ")
        Leia(t.segundos)
    FimProcedimento

    Funcao ConverterParaSegundos(t : Horario) : Inteiro
    Inicio
        Retorne (t.horas * 3600) + (t.minutos * 60) + t.segundos
    FimFuncao

    // b. Obter a diferença entre os dois horários
    Funcao ObterDiferenca(t1, t2 : Horario) : Horario
    Var
        seg1, seg2, diffSeg, resto : Inteiro
        resultado : Horario
    Inicio
        seg1 <- ConverterParaSegundos(t1)
        seg2 <- ConverterParaSegundos(t2)
        
        Se seg1 >= seg2 Entao
            diffSeg <- seg1 - seg2
        Senao
            diffSeg <- seg2 - seg1
        FimSe

        resultado.horas <- diffSeg \ 3600
        resto <- diffSeg % 3600
        resultado.minutos <- resto \ 60
        resultado.segundos <- resto % 60

        Retorne resultado
    FimFuncao

    // c. Mostrar a diferença entre os dois horários
    Procedimento MostrarHorario(t : Horario)
    Inicio
        EscrevaL("Diferença: ", t.horas, "h ", t.minutos, "m ", t.segundos, "s")
    FimProcedimento

Inicio
    LerHorario(h1, 1)
    LerHorario(h2, 2)
    
    dif <- ObterDiferenca(h1, h2)
    
    MostrarHorario(dif)
FimAlgoritmo