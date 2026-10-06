Algoritmo Exercicios6
    Tipo Brinquedo = Registro
        codigo : Inteiro
        descricao : Texto
        precoCompra : Real
        precoVenda : Real
        qtdEstoque : Inteiro
        estoqueMinimo : Inteiro
    FimRegistro

    Var
        estoque : Vetor[1..40] de Brinquedo
        i : Inteiro
        lucro, percLucro : Real

Inicio
    // a. Cadastre os produtos
    Para i De 1 Ate 40 Faca
        EscrevaL("--- Produto ", i, " ---")
        Escreva("Código: ")
        Leia(estoque[i].codigo)
        Escreva("Descrição: ")
        Leia(estoque[i].descricao)
        Escreva("Preço de Compra: R$ ")
        Leia(estoque[i].precoCompra)
        Escreva("Preço de Venda: R$ ")
        Leia(estoque[i].precoVenda)
        Escreva("Quantidade em Estoque: ")
        Leia(estoque[i].qtdEstoque)
        Escreva("Estoque Mínimo: ")
        Leia(estoque[i].estoqueMinimo)
    FimPara

    // b. Mostre o valor do lucro e o percentual de cada produto
    EscrevaL("\n=== ANÁLISE DE LUCRO POR PRODUTO ===")
    Para i De 1 Ate 40 Faca
        lucro <- estoque[i].precoVenda - estoque[i].precoCompra
        Se estoque[i].precoCompra > 0 Entao
            percLucro <- (lucro / estoque[i].precoCompra) * 100
        Senao
            percLucro <- 0
        FimSe
        EscrevaL("Produto: ", estoque[i].descricao, " | Lucro: R$ ", lucro:0:2, " (", percLucro:0:2, "%)")
    FimPara

    // c. Mostre os produtos abaixo do estoque mínimo
    EscrevaL("\n=== PRODUTOS ABAIXO DO ESTOQUE MÍNIMO ===")
    Para i De 1 Ate 40 Faca
        Se estoque[i].qtdEstoque < estoque[i].estoqueMinimo Entao
            EscrevaL("Código: ", estoque[i].codigo, " | Descrição: ", estoque[i].descricao, " | Atual: ", estoque[i].qtdEstoque, " | Mínimo: ", estoque[i].estoqueMinimo)
        FimSe
    FimPara
FimAlgoritmo