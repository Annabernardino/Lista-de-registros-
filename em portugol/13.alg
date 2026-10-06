Procedimento SalarioIntervalo(cad : TipoCadastro; v1, v2 : Real)
Var
    i, cont : Inteiro
    somaSalarios, media : Real
Inicio
    somaSalarios <- 0
    cont <- 0
    
    EscrevaL("\n=== FUNCIONÁRIOS COM SALÁRIO ENTRE R$ ", v1:0:2, " E R$ ", v2:0:2, " ===")
    
    Para i De 1 Ate cad.Quant Faca
        Se (cad.Funcionario[i].Salario >= v1) e (cad.Funcionario[i].Salario <= v2) Entao
            EscrevaL("Nome: ", cad.Funcionario[i].Nome, " | Salário: R$ ", cad.Funcionario[i].Salario:0:2)
            somaSalarios <- somaSalarios + cad.Funcionario[i].Salario
            cont <- cont + 1
        FimSe
    FimPara
    
    Se cont > 0 Entao
        media <- somaSalarios / cont
        EscrevaL("Média dos salários listados: R$ ", media:0:2)
    Senao
        EscrevaL("Nenhum funcionário encontrado nessa faixa salarial.")
    FimSe
FimProcedimento