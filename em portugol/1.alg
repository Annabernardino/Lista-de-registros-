// Item a: Tempo em horas, minutos e segundos
Tipo Horario = Registro
    horas : Inteiro
    minutos : Inteiro
    segundos : Inteiro
FimRegistro

// Item b: Uma lista telefônica
Tipo Contato = Registro
    nome : Texto
    telefone : Texto
    email : Texto
    endereco : Texto
FimRegistro

// Item c: Descrição de um automóvel para uma locadora
Tipo Automovel = Registro
    marca : Texto
    modelo : Texto
    ano : Inteiro
    placa : Texto
    cor : Texto
    valorDiaria : Real
    disponivel : Logico
FimRegistro

// Item d: Descrição de um livro para uma biblioteca
Tipo Livro = Registro
    titulo : Texto
    autor : Texto
    editora : Texto
    anoPublicacao : Inteiro
    isbn : Texto
    disponivel : Logico
FimRegistro