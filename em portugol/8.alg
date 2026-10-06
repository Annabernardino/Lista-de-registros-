Algoritmo Exercicios8
    Tipo Cliente = Registro
        codigo : Inteiro
        nome : Texto
        sexo : Caracter
        dataNascimento : Texto
        rg : Texto
        cpf : Texto
        endereco : Texto
        cidade : Texto
        estado : Texto
        totalFitasLocadas : Inteiro
        fitasLocadasAtualmente : Inteiro
    FimRegistro

    Var
        clientes : Vetor[1..10] de Cliente
        qtdClientes, opcao, cod, pos, numFitas : Inteiro

    Funcao BuscarClientePorCodigo(cod : Inteiro, qtd : Inteiro, c : Vetor[1..10] de Cliente) : Inteiro
    Var
        i : Inteiro
    Inicio
        Para i De 1 Ate qtd Faca
            Se c[i].codigo = cod Entao
                Retorne i
            FimSe
        FimPara
        Retorne -1
    FimFuncao

    // a. Incluir um novo cliente
    Procedimento IncluirCliente(Var c : Vetor[1..10] de Cliente, Var qtd : Inteiro)
    Inicio
        Se qtd >= 10 Entao
            EscrevaL("Erro: Limite máximo de 10 clientes atingido.")
        Senao
            qtd <- qtd + 1
            c[qtd].codigo <- qtd // Código é o próprio índice no registro
            EscrevaL("Novo cliente cadastrado com o código: ", c[qtd].codigo)
            Escreva("Nome: ")
            Leia(c[qtd].nome)
            Escreva("Sexo (M/F): ")
            Leia(c[qtd].sexo)
            Escreva("Data de Nascimento: ")
            Leia(c[qtd].dataNascimento)
            Escreva("RG: ")
            Leia(c[qtd].rg)
            Escreva("CPF: ")
            Leia(c[qtd].cpf)
            Escreva("Endereço: ")
            Leia(c[qtd].endereco)
            Escreva("Cidade: ")
            Leia(c[qtd].cidade)
            Escreva("Estado: ")
            Leia(c[qtd].estado)
            
            c[qtd].totalFitasLocadas <- 0
            c[qtd].fitasLocadasAtualmente <- 0
            EscrevaL("Cliente incluído com sucesso!")
        FimSe
    FimProcedimento

    // b. Mostrar clientes cadastrados
    Procedimento MostrarClientes(c : Vetor[1..10] de Cliente, qtd : Inteiro)
    Var
        i : Inteiro
    Inicio
        Se qtd = 0 Entao
            EscrevaL("Nenhum cliente cadastrado.")
        Senao
            Para i De 1 Ate qtd Faca
                EscrevaL("Cód: ", c[i].codigo, " | Nome: ", c[i].nome, " | Fitas com ele: ", c[i].fitasLocadasAtualmente, " | Total já locadas: ", c[i].totalFitasLocadas)
            FimPara
        FimSe
    FimProcedimento

    // c. Remover cliente
    Procedimento RemoverCliente(Var c : Vetor[1..10] de Cliente, Var qtd : Inteiro)
    Var
        cod, pos, i : Inteiro
    Inicio
        Escreva("Digite o código do cliente a ser removido: ")
        Leia(cod)
        pos <- BuscarClientePorCodigo(cod, qtd, c)
        
        Se pos = -1 Entao
            EscrevaL("Cliente não encontrado.")
        Senao
            Se c[pos].fitasLocadasAtualmente > 0 Entao
                EscrevaL("Erro: Não é possível remover cliente com fitas locadas!")
            Senao
                Para i De pos Ate qtd - 1 Faca
                    c[i] <- c[i + 1]
                    c[i].codigo <- i // Atualiza o código para corresponder à nova posição
                FimPara
                qtd <- qtd - 1
                EscrevaL("Cliente removido com sucesso!")
            FimSe
        FimSe
    FimProcedimento

    // d. Locar fitas
    Procedimento LocarFitas(Var c : Vetor[1..10] de Cliente, qtd : Inteiro)
    Var
        cod, pos, qtdFitas : Inteiro
    Inicio
        Escreva("Digite o código do cliente: ")
        Leia(cod)
        pos <- BuscarClientePorCodigo(cod, qtd, c)
        
        Se pos = -1 Entao
            EscrevaL("Cliente não encontrado.")
        Senao
            Se c[pos].fitasLocadasAtualmente > 0 Entao
                EscrevaL("Erro: O cliente já possui fitas locadas no momento!")
            Senao
                Escreva("Quantas fitas deseja locar? ")
                Leia(qtdFitas)
                c[pos].fitasLocadasAtualmente <- qtdFitas
                c[pos].totalFitasLocadas <- c[pos].totalFitasLocadas + qtdFitas
                EscrevaL("Locação realizada com sucesso!")
            FimSe
        FimSe
    FimProcedimento

    // e. Devolver fitas
    Procedimento DevolverFitas(Var c : Vetor[1..10] de Cliente, qtd : Inteiro)
    Var
        cod, pos, qtdDev : Inteiro
    Inicio
        Escreva("Digite o código do cliente: ")
        Leia(cod)
        pos <- BuscarClientePorCodigo(cod, qtd, c)
        
        Se pos = -1 Entao
            EscrevaL("Cliente não encontrado.")
        Senao
            Escreva("Quantas fitas estão sendo devolvidas? ")
            Leia(qtdDev)
            Se qtdDev > c[pos].fitasLocadasAtualmente Entao
                EscrevaL("Erro: O número devolvido é maior que o de fitas em posse (", c[pos].fitasLocadasAtualmente, ").")
            Senao
                c[pos].fitasLocadasAtualmente <- c[pos].fitasLocadasAtualmente - qtdDev
                EscrevaL("Devolução registrada com sucesso!")
            FimSe
        FimSe
    FimProcedimento

    // f. Mostrar clientes com fitas locadas
    Procedimento MostrarClientesComFitas(c : Vetor[1..10] de Cliente, qtd : Inteiro)
    Var
        i, cont : Inteiro
    Inicio
        cont <- 0
        Para i De 1 Ate qtd Faca
            Se c[i].fitasLocadasAtualmente > 0 Entao
                EscrevaL("Cód: ", c[i].codigo, " | Nome: ", c[i].nome, " | Fitas Atuais: ", c[i].fitasLocadasAtualmente)
                cont <- cont + 1
            FimSe
        FimPara
        Se cont = 0 Entao
            EscrevaL("Nenhum cliente está com fitas locadas no momento.")
        FimSe
    FimProcedimento

Inicio
    qtdClientes <- 0
    Repita
        EscrevaL("\n=== LOCADORA DE FITAS ===")
        EscrevaL("1. Cadastrar Cliente")
        EscrevaL("2. Listar Clientes")
        EscrevaL("3. Remover Cliente")
        EscrevaL("4. Locar Fitas")
        EscrevaL("5. Devolver Fitas")
        EscrevaL("6. Listar Clientes com Fitas Locadas")
        EscrevaL("7. Sair")
        Escreva("Opção: ")
        Leia(opcao)

        Escolha opcao
            Caso 1: IncluirCliente(clientes, qtdClientes)
            Caso 2: MostrarClientes(clientes, qtdClientes)
            Caso 3: RemoverCliente(clientes, qtdClientes)
            Caso 4: LocarFitas(clientes, qtdClientes)
            Caso 5: DevolverFitas(clientes, qtdClientes)
            Caso 6: MostrarClientesComFitas(clientes, qtdClientes)
        FimEscolha
    Ate opcao = 7
FimAlgoritmo