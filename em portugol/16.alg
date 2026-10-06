Procedimento AtualizaSalario(Var cad : TipoCadastro)
Var
    rgProcurado : Texto
    novoSalario : Real
    i, pos : Inteiro
Inicio
    Escreva("Digite o RG do funcionário para atualizar o salário: ")
    Leia(rgProcurado)
    
    pos <- -1
    Para i De 1 Ate cad.Quant Faca
        Se cad.Funcionario[i].RG = rgProcurado Entao
            pos <- i
        FimSe
    FimPara
    
    Se pos = -1 Entao
        EscrevaL("Funcionário com RG ", rgProcurado, " não encontrado.")
    Senao
        Escreva("Digite o novo salário para ", cad.Funcionario[pos].Nome, ": R$ ")
        Leia(novoSalario)
        cad.Funcionario[pos].Salario <- novoSalario
        EscrevaL("Salário atualizado com sucesso!")
    FimSe
FimProcedimento