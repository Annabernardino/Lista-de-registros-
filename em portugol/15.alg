Funcao BuscaNome(cad : TipoCadastro; nomeProcurado : Texto) : tiporeg
Var
    i : Inteiro
    fEncontrado : tiporeg
Inicio
    // Inicializa como não encontrado (nome vazio)
    fEncontrado.Nome <- ""
    
    Para i De 1 Ate cad.Quant Faca
        Se cad.Funcionario[i].Nome = nomeProcurado Entao
            fEncontrado <- cad.Funcionario[i]
            Retorne fEncontrado
        FimSe
    FimPara
    
    Retorne fEncontrado
FimFuncao