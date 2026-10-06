Procedimento CalculaImpostoRenda(cad : TipoCadastro)
Var
    i : Inteiro
    salario, imposto : Real
Inicio
    Se cad.Quant = 0 Entao
        EscrevaL("Nenhum funcionário cadastrado.")
    Senao
        EscrevaL("\n=== IMPOSTO DE RENDA RETIDO NA FONTE ===")
        Para i De 1 Ate cad.Quant Faca
            salario <- cad.Funcionario[i].Salario
            
            Se salario <= 1000.00 Entao
                imposto <- 0.0
            Senao
                Se salario <= 2000.00 Entao
                    imposto <- salario * 0.10
                Senao
                    Se salario <= 3500.00 Entao
                        imposto <- salario * 0.15
                    Senao
                        imposto <- salario * 0.25
                    FimSe
                FimSe
            FimSe
            
            EscrevaL("Nome: ", cad.Funcionario[i].Nome, " | Salário: R$ ", salario:0:2, " | Imposto: R$ ", imposto:0:2)
        FimPara
    FimSe
FimProcedimento