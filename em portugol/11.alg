Procedimento ListaFuncionarios(cad : TipoCadastro)
Var
    i : Inteiro
Inicio
    Se cad.Quant = 0 Entao
        EscrevaL("Nenhum funcionário cadastrado.")
    Senao
        EscrevaL("\n=== LISTA DE FUNCIONÁRIOS ===")
        Para i De 1 Ate cad.Quant Faca
            EscrevaL("----------------------------------")
            EscrevaL("Funcionário ", i)
            EscrevaL("Nome: ", cad.Funcionario[i].Nome)
            EscrevaL("RG: ", cad.Funcionario[i].RG)
            EscrevaL("Salário: R$ ", cad.Funcionario[i].Salario:0:2)
            EscrevaL("Idade: ", cad.Funcionario[i].Idade)
            EscrevaL("Sexo: ", cad.Funcionario[i].Sexo)
            EscrevaL("Data Nasc: ", cad.Funcionario[i].DataNascimento.dia, "/", cad.Funcionario[i].DataNascimento.mes, "/", cad.Funcionario[i].DataNascimento.ano)
        FimPara
    FimSe
FimProcedimento