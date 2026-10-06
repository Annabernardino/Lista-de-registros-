Procedimento LeFuncionarios(Var cad : TipoCadastro)
Var
    nomeTemp : Texto
Inicio
    Enquanto cad.Quant < 100 Faca
        Escreva("Digite o nome do funcionário (ou deixe vazio para encerrar): ")
        Leia(nomeTemp)
        
        Se nomeTemp = "" Entao
            Interrompa // Parar leitura se nome for vazio
        FimSe
        
        cad.Quant <- cad.Quant + 1
        cad.Funcionario[cad.Quant].Nome <- nomeTemp
        
        Escreva("RG: ")
        Leia(cad.Funcionario[cad.Quant].RG)
        Escreva("Salário: R$ ")
        Leia(cad.Funcionario[cad.Quant].Salario)
        Escreva("Idade: ")
        Leia(cad.Funcionario[cad.Quant].Idade)
        Escreva("Sexo (M/F): ")
        Leia(cad.Funcionario[cad.Quant].Sexo)
        Escreva("Data de Nascimento - Dia: ")
        Leia(cad.Funcionario[cad.Quant].DataNascimento.dia)
        Escreva("Data de Nascimento - Mês: ")
        Leia(cad.Funcionario[cad.Quant].DataNascimento.mes)
        Escreva("Data de Nascimento - Ano: ")
        Leia(cad.Funcionario[cad.Quant].DataNascimento.ano)
    FimEnquanto
FimProcedimento