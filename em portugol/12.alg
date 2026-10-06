// Procedimento para trocar dois registros do tipo tiporeg
Procedimento Troca(Var a, b : tiporeg)
Var
    temp : tiporeg
Inicio
    temp <- a
    a <- b
    b <- temp
FimProcedimento

// Ordenação por Nome adaptando DOSORT
Procedimento OrdenaNome(Var cad : TipoCadastro)
Var
    pig, j : Inteiro
Inicio
    Para pig De 1 Ate cad.Quant Faca
        Para j De 1 Ate cad.Quant Faca
            Se cad.Funcionario[j].Nome > cad.Funcionario[pig].Nome Entao
                Troca(cad.Funcionario[j], cad.Funcionario[pig])
            FimSe
        FimPara
    FimPara
FimProcedimento

// Ordenação por Salário adaptando DOSORT
Procedimento OrdenaSalario(Var cad : TipoCadastro)
Var
    pig, j : Inteiro
Inicio
    Para pig De 1 Ate cad.Quant Faca
        Para j De 1 Ate cad.Quant Faca
            Se cad.Funcionario[j].Salario > cad.Funcionario[pig].Salario Entao
                Troca(cad.Funcionario[j], cad.Funcionario[pig])
            FimSe
        FimPara
    FimPara
FimProcedimento