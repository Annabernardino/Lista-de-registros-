Funcao ListaMaraja(cad : TipoCadastro) : tiporeg
Var
    i, posMaior : Inteiro
    maraja : tiporeg
Inicio
    Se cad.Quant = 0 Entao
        maraja.Nome <- ""
    Senao
        posMaior <- 1
        Para i De 2 Ate cad.Quant Faca
            Se cad.Funcionario[i].Salario > cad.Funcionario[posMaior].Salario Entao
                posMaior <- i
            FimSe
        FimPara
        maraja <- cad.Funcionario[posMaior]
    FimSe
    
    Retorne maraja
FimFuncao