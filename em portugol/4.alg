Algoritmo Exercício4
    Tipo ContaBancaria = Registro
        numero : Inteiro
        nomeCliente : Texto
        saldo : Real
    FimRegistro

    Var
        contas : Vetor[1..100] de ContaBancaria
        qntContas, opcao : Inteiro

    Funcao BuscarConta(num : Inteiro, qtd : Inteiro, contas : Vetor[1..100] de ContaBancaria) : Inteiro
    Var
        i : Inteiro
    Inicio
        Para i De 1 Ate qtd Faca
            Se contas[i].numero = num Entao
                Retorne i
            FimSe
        FimPara
        Retorne -1
    FimFuncao

    // b. Cadastrar as contas (uma por vez, sem números duplicados)
    Procedimento CadastrarConta(Var contas : Vetor[1..100] de ContaBancaria, Var qtd : Inteiro)
    Var
        num : Inteiro
        pos : Inteiro
    Inicio
        Se qtd >= 100 Entao
            EscrevaL("Erro: Limite máximo de 100 contas atingido.")
        Senao
            Escreva("Digite o número da conta: ")
            Leia(num)
            
            pos <- BuscarConta(num, qtd, contas)
            Se pos <> -1 Entao
                EscrevaL("Erro: Já existe uma conta com esse número!")
            Senao
                qtd <- qtd + 1
                contas[qtd].numero <- num
                Escreva("Digite o nome do cliente: ")
                Leia(contas[qtd].nomeCliente)
                Escreva("Digite o saldo inicial: ")
                Leia(contas[qtd].saldo)
                EscrevaL("Conta cadastrada com sucesso!")
            FimSe
        FimSe
    FimProcedimento

    // c. Visualizar todas as contas de um determinado cliente
    Procedimento VisualizarContasCliente(contas : Vetor[1..100] de ContaBancaria, qtd : Inteiro)
    Var
        nomeProcurado : Texto
        i, encontradas : Inteiro
    Inicio
        Se qtd = 0 Entao
            EscrevaL("Nenhuma conta cadastrada.")
        Senao
            Escreva("Digite o nome do cliente: ")
            Leia(nomeProcurado)
            encontradas <- 0
            
            Para i De 1 Ate qtd Faca
                Se contas[i].nomeCliente = nomeProcurado Entao
                    EscrevaL("Conta: ", contas[i].numero, " | Saldo: R$ ", contas[i].saldo:0:2)
                    encontradas <- encontradas + 1
                FimSe
            FimPara
            
            Se encontradas = 0 Entao
                EscrevaL("Nenhuma conta encontrada para o cliente informado.")
            FimSe
        FimSe
    FimProcedimento

    // d. Excluir a conta com menor saldo
    Procedimento ExcluirMenorSaldo(Var contas : Vetor[1..100] de ContaBancaria, Var qtd : Inteiro)
    Var
        i, posMenor : Inteiro
        menorSaldo : Real
    Inicio
        Se qtd = 0 Entao
            EscrevaL("Erro: Não há contas para excluir.")
        Senao
            posMenor <- 1
            menorSaldo <- contas[1].saldo
            
            Para i De 2 Ate qtd Faca
                Se contas[i].saldo < menorSaldo Entao
                    menorSaldo <- contas[i].saldo
                    posMenor <- i
                FimSe
            FimPara
            
            EscrevaL("Removendo conta número ", contas[posMenor].numero, " (Cliente: ", contas[posMenor].nomeCliente, ") com menor saldo: R$ ", contas[posMenor].saldo:0:2)
            
            // Shift para manter os elementos contíguos no vetor
            Para i De posMenor Ate qtd - 1 Faca
                contas[i] <- contas[i + 1]
            FimPara
            
            qtd <- qtd - 1
            EscrevaL("Conta removida com sucesso!")
        FimSe
    FimProcedimento

Inicio
    qntContas <- 0
    
    // a. Menu de opções
    Repita
        EscrevaL("\n=== MENU DE CONTAS BANCÁRIAS ===")
        EscrevaL("1. Cadastrar Conta")
        EscrevaL("2. Visualizar Contas do Cliente")
        EscrevaL("3. Excluir Conta com Menor Saldo")
        EscrevaL("4. Sair")
        Escreva("Escolha uma opção: ")
        Leia(opcao)
        
        Escolha opcao
            Caso 1
                CadastrarConta(contas, qntContas)
            Caso 2
                VisualizarContasCliente(contas, qntContas)
            Caso 3
                ExcluirMenorSaldo(contas, qntContas)
            Caso 4
                EscrevaL("Saindo do programa...")
            OutroCaso
                EscrevaL("Opção inválida!")
        FimEscolha
    Ate opcao = 4
FimAlgoritmo