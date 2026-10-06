Algoritmo Exercício2
    Tipo Horario = Registro
        horas : Inteiro
        minutos : Inteiro
        segundos : Inteiro
    FimRegistro

    Var
        h : Horario
        totalSeg : Inteiro

    // a. Ler as informações
    Procedimento LerHorario(Var t : Horario)
    Inicio
        Escreva("Digite as horas: ")
        Leia(t.horas)
        Escreva("Digite os minutos: ")
        Leia(t.minutos)
        Escreva("Digite os segundos: ")
        Leia(t.segundos)
    FimProcedimento

    // b. Mostrar as informações
    Procedimento MostrarHorario(t : Horario)
    Inicio
        EscrevaL("Horário: ", t.horas, "h ", t.minutos, "m ", t.segundos, "s")
    FimProcedimento

    // c. Transformar as informações em segundos
    Funcao ConverterParaSegundos(t : Horario) : Inteiro
    Inicio
        Retorne (t.horas * 3600) + (t.minutos * 60) + t.segundos
    FimFuncao

    // d. Mostrar as informações em segundos
    Procedimento MostrarEmSegundos(t : Horario)
    Var
        s : Inteiro
    Inicio
        s <- ConverterParaSegundos(t)
        EscrevaL("Total em segundos: ", s, " segundos")
    FimProcedimento

Inicio
    LerHorario(h)
    MostrarHorario(h)
    MostrarEmSegundos(h)
FimAlgoritmo