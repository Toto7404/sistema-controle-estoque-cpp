# Sistema de Controle de Estoque em C++

Programa de terminal desenvolvido em C++ para gerenciar o estoque de uma pequena loja. Projeto pessoal criado para aplicar conceitos fundamentais de lógica de programação, estruturas de dados e organização de código.

## Funcionalidades

- Cadastro de produtos (nome, preço e quantidade)
- Listagem de todos os produtos cadastrados
- Pesquisa de produto por nome
- Entrada de estoque (reposição)
- Saída de estoque (venda), com validação para não deixar quantidade negativa
- Cálculo do valor total do estoque
- Alerta de produtos com estoque baixo (menos de 5 unidades)

## Tecnologias e conceitos aplicados

- **C++** puro, sem bibliotecas externas
- `struct` para modelar a entidade Produto
- `vector` para armazenamento dinâmico dos dados em memória
- Funções modulares, cada uma com responsabilidade única
- Validação de regras de negócio (ex: impedir saída de estoque maior que o disponível)
- Formatação de saída no terminal com `iomanip`

## Como executar

```bash
g++ -o estoque estoque.cpp
./estoque
```

No Windows (PowerShell):
```bash
g++ -o estoque estoque.cpp
.\estoque
```

## Próximos passos

- Persistência de dados em arquivo (para os produtos não serem perdidos ao fechar o programa)
- Refatoração para orientação a objetos (classes em vez de struct + funções soltas)

---
Desenvolvido por Heitor de Oliveira Marcelino
