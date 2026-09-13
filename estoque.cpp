#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

// ---- "Ficha" de cada produto do estoque ----
struct Produto {
    string nome;
    double preco;
    int quantidade;
};

// Lista (dinâmica) que guarda todos os produtos cadastrados
vector<Produto> estoque;

// Declaração das funções (o compilador precisa saber que elas existem
// antes de serem chamadas no main)
void exibirMenu();
void cadastrarProduto();
void listarProdutos();
void pesquisarProduto();
void entradaEstoque();
void saidaEstoque();
void calcularValorTotal();
void estoqueBaixo();

int main() {
    int opcao;

    do {
        exibirMenu();
        cin >> opcao;
        cin.ignore(); // limpa o "enter" que fica no buffer depois do cin >>

        switch (opcao) {
            case 1: cadastrarProduto();   break;
            case 2: listarProdutos();     break;
            case 3: pesquisarProduto();   break;
            case 4: entradaEstoque();     break;
            case 5: saidaEstoque();       break;
            case 6: calcularValorTotal(); break;
            case 7: estoqueBaixo();       break;
            case 0: cout << "\nSaindo... até mais!\n"; break;
            default: cout << "\nOpcao invalida! Tente novamente.\n";
        }
    } while (opcao != 0);

    return 0;
}

void exibirMenu() {
    cout << "\n===== SISTEMA DE CONTROLE DE ESTOQUE =====\n";
    cout << "1 - Cadastrar produto\n";
    cout << "2 - Listar produtos\n";
    cout << "3 - Pesquisar produto\n";
    cout << "4 - Entrada de estoque\n";
    cout << "5 - Saida de estoque\n";
    cout << "6 - Calcular valor total do estoque\n";
    cout << "7 - Produtos com estoque baixo\n";
    cout << "0 - Sair\n";
    cout << "Escolha uma opcao: ";
}

void cadastrarProduto() {
    Produto p;

    cout << "\nNome do produto: ";
    getline(cin, p.nome);

    cout << "Preco (ex: 19.90): R$ ";
    cin >> p.preco;

    cout << "Quantidade inicial: ";
    cin >> p.quantidade;
    cin.ignore();

    estoque.push_back(p); // adiciona a ficha na "gaveta"
    cout << "Produto cadastrado com sucesso!\n";
}

void listarProdutos() {
    if (estoque.empty()) {
        cout << "\nNenhum produto cadastrado ainda.\n";
        return;
    }

    cout << "\n" << left << setw(20) << "NOME"
         << setw(12) << "PRECO"
         << setw(10) << "QTD" << "\n";
    cout << string(40, '-') << "\n";

    for (const auto &p : estoque) {
        cout << left << setw(20) << p.nome
             << "R$ " << fixed << setprecision(2) << setw(8) << p.preco
             << setw(10) << p.quantidade << "\n";
    }
}

void pesquisarProduto() {
    string nome;
    cout << "\nNome do produto a pesquisar: ";
    getline(cin, nome);

    bool encontrado = false;
    for (const auto &p : estoque) {
        if (p.nome == nome) {
            cout << "Encontrado -> Preco: R$ " << fixed << setprecision(2)
                 << p.preco << " | Quantidade: " << p.quantidade << "\n";
            encontrado = true;
        }
    }

    if (!encontrado) {
        cout << "Produto nao encontrado.\n";
    }
}

void entradaEstoque() {
    string nome;
    int qtd;

    cout << "\nNome do produto: ";
    getline(cin, nome);
    cout << "Quantidade a adicionar: ";
    cin >> qtd;
    cin.ignore();

    for (auto &p : estoque) {
        if (p.nome == nome) {
            p.quantidade += qtd;
            cout << "Estoque atualizado! Nova quantidade: " << p.quantidade << "\n";
            return;
        }
    }
    cout << "Produto nao encontrado.\n";
}

void saidaEstoque() {
    string nome;
    int qtd;

    cout << "\nNome do produto: ";
    getline(cin, nome);
    cout << "Quantidade a remover: ";
    cin >> qtd;
    cin.ignore();

    for (auto &p : estoque) {
        if (p.nome == nome) {
            if (qtd > p.quantidade) {
                cout << "Quantidade insuficiente em estoque! (disponivel: "
                     << p.quantidade << ")\n";
                return;
            }
            p.quantidade -= qtd;
            cout << "Saida registrada! Nova quantidade: " << p.quantidade << "\n";
            return;
        }
    }
    cout << "Produto nao encontrado.\n";
}

void calcularValorTotal() {
    double total = 0;
    for (const auto &p : estoque) {
        total += p.preco * p.quantidade;
    }
    cout << "\nValor total do estoque: R$ " << fixed << setprecision(2) << total << "\n";
}

void estoqueBaixo() {
    const int LIMITE = 5;
    cout << "\nProdutos com estoque baixo (menos de " << LIMITE << " unidades):\n";

    bool algum = false;
    for (const auto &p : estoque) {
        if (p.quantidade < LIMITE) {
            cout << "- " << p.nome << " (" << p.quantidade << " unidades)\n";
            algum = true;
        }
    }

    if (!algum) {
        cout << "Nenhum produto com estoque baixo.\n";
    }
}
