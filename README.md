# 🎵 Projeto Musical com Buzzer n9 Kit BitDogLab

Este projeto permite armazenar e tocar músicas utilizando frequências sonoras. As músicas estão separadas em arquivos modulares, facilitando a adição de novas músicas.

## 📂 Estrutura do Projeto

```
/projeto-musical
│── main.c          # Arquivo principal que tocar as músicas
│── notas.h         # Cabeçalho contendo as estruturas e declarações das músicas
│── musicas.h       # Implementação das músicas e suas notas
│── README.md       # Documentação do projeto
```

## 🎶 Funcionalidades

- Definição de músicas usando notas e frequências.
- Cada nota tem uma duração específica (tempo em ms).
- Separação modular dos arquivos para melhor organização.
- Facilidade para adicionar novas músicas.

## 🛠️ Como Compilar e Executar

### 1️⃣ Compilar o código:

```sh
gcc main.c -o musica_player
```

### 2️⃣ Executar o programa:

```sh
./musica_player
```

## 🎼 Como Adicionar uma Nova Música

1. \*\*Editar \*\***`musicas.h`** e adicionar um novo array de notas:

```c
const Nota minhaMusica[] = {
    {"C4", 261.63, 500}, {"D4", 293.66, 500}, {"E4", 329.63, 500},
};
```

2. **Recompilar o projeto e rodar novamente.**

## 📌 Possíveis Melhorias

✅ Criar um menu interativo para escolher a música a ser reproduzida.

✅ Implementar suporte a arquivos externos para leitura de músicas.

---

💡 **Dúvidas ou sugestões?** Sinta-se à vontade para contribuir! 🚀

