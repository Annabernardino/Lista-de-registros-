Procedimento RemovePorRG(Var cad : TipoCadastro; rgProcurado : Texto)
Var
    i, pos : Inteiro
Inicio
    pos <- -1
    
    // Procura a posição do funcionário pelo RG
    Para i De 1 Ate cad.Quant Faca
        Se cad.Funcionario[i].RG = rgProcurado Entao
            pos <- i
        FimSe
    FimPara
    
    // Se encontrou, faz o deslocamento (shift) para manter contiguidade
    Se pos <> -1 Entao
        Para i De pos Ate cad.Quant - 1 Faca
            cad.Funcionario[i] <- cad.Funcionario[i + 1]
        FimPara
        
        cad.Quant <- cad.Quant - 1
        EscrevaL("Funcionário removido com sucesso!")
    Senao
        EscrevaL("RG não localizado. Nenhuma alteração realizada.")
    FimSe
FimProcedimento