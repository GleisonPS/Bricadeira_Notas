#ifndef NOTAS_H
#define NOTAS_H

typedef struct {
    char nome[5];
    float frequencia;
    int tempo;
} Nota;


// Estrutura para armazenar músicas
struct Musica {
    const char* titulo;
    const Nota* notas;
    int tamanho;
};



// Declaração do array de notas
extern const Nota notas[];

// Tamanho do array de notas
extern const int notas_tamanho;

// Função para buscar a frequência de uma nota pelo nome
float buscar_frequencia(const char* nome);


// Estrutura para armazenar músicas
typedef struct {
    char nome[5];
    float frequencia;
    int tempo;
} Musica;

// Declaração das músicas (definidas em `musicas.cpp`)
extern const Musica musicas[];
extern const int qtdMusicas;
#endif

