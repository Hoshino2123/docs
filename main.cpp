#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Cliente {
    int numero;
    vector<int> carrinho;
};

int main() {
    queue<Cliente> fila;
    int opcao = 0;
    int proximo_numero = 1;

    while (opcao != 6) {
        cout << "Escolha uma opção:" << endl;
        cout << "1. Inserir um cliente na fila para a caixa" << endl;
        cout << "2. Atender o 1º cliente da fila" << endl;
        cout << "3. Dizer quantos clientes ha na fila" << endl;
        cout << "4. Listar os numeros dos clientes na fila" << endl;
        cout << "5. Listar os numeros dos produtos que estão no carrinho do 1º cliente da fila" << endl;
        cout << "6. Listar os numeros dos produtos de todos os clientes que estão na fila" << endl;
        cout << "7. Sair" << endl;
        cin >> opcao;

        switch (opcao) {
            case 1:
                {
                    Cliente c;
                    c.numero = proximo_numero++;
                    int n_produtos;
                    cout << "Digite o numero de produtos no carrinho do cliente: ";
                    cin >> n_produtos;
                    for (int i = 0; i < n_produtos; i++) {
                        int produto;
                        cout << "Digite o numero do produto " << i+1 << ": ";
                        cin >> produto;
                        c.carrinho.push_back(produto);
                    }
                    fila.push(c);
                }
                break;
            case 2:
                if (fila.empty()) {
                    cout << "A fila esta vazia." << endl;
                } else {
                    Cliente c = fila.front();
                    cout << "O cliente " << c.numero << " foi atendido." << endl;
                    fila.pop();
                }
                break;
            case 3:
                cout << "Ha " << fila.size() << " clientes na fila." << endl;
                break;
            case 4:
                if (fila.empty()) {
                    cout << "A fila esta vazia." << endl;
                } else {
                    queue<Cliente> temp = fila;
                    while (!temp.empty()) {
                        Cliente c = temp.front();
                        cout << "Cliente " << c.numero << endl;
                        temp.pop();
                    }
                }
                break;
            case 5:
                if (fila.empty()) {
                    cout << "A fila esta vazia." << endl;
                } else {
                    Cliente c = fila.front();
                    if (c.carrinho.empty()) {
                        cout << "O carrinho do cliente esta vazio." << endl;
                    } else {
                        for (int i = 0; i < c.carrinho.size(); i++) {
                            cout << "Produto " << i+1 << ": " << c.carrinho[i] << endl;
                        }
                    }
                }
                break;
            case 6:
                if (fila.empty()) {
                    cout << "A fila esta vazia." << endl;
                } else {
                    queue<Cliente> temp = fila;
                    while (!temp.empty()) {
                        Cliente c = temp.front();
                        cout << "Cliente " << c.numero << ":";

                        if (c.carrinho.empty()) {
                            cout << " O carrinho do cliente esta vazio."<<endl;;
                        } else {
                            for (int i = 0; i < c.carrinho.size(); i++) {
                                cout <<" Produto "<<i+1<<": "<<c.carrinho[i];
                            }
                            cout<<endl;;
                        }

                        temp.pop();
                    }
                }
                break;

            case 7:
                break;

            default:
                cout<<"Opção invalida."<<endl;;
        }
    }

    return 0;
}

