#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class LinkedList {
private:
    Node* head;
    int size;

public:
    LinkedList() { head = nullptr; size = 0; }

    void createEmptyList() { head = nullptr; size = 0; }

    bool isEmpty() { return head == nullptr; }

    int getSize() { return size; }

    int get(int position) {
        if (position < 1 || position > size) return -1;
        Node* temp = head;
        for (int i = 1; i < position; i++) temp = temp->next;
        return temp->data;
    }

    void set(int position, int value) {
        if (position < 1 || position > size) return;
        Node* temp = head;
        for (int i = 1; i < position; i++) temp = temp->next;
        temp->data = value;
    }

    void insert(int position, int value) {
        if (position < 1 || position > size + 1) return;
        Node* newNode = new Node;
        newNode->data = value;
        if (position == 1) {
            newNode->next = head;
            head = newNode;
        } else {
            Node* temp = head;
            for (int i = 1; i < position - 1; i++) temp = temp->next;
            newNode->next = temp->next;
            temp->next = newNode;
        }
        size++;
    }

    void remove(int position) {
        if (position < 1 || position > size) return;
        Node* temp = head;
        if (position == 1) {
            head = head->next;
            delete temp;
        } else {
            for (int i = 1; i < position - 1; i++) temp = temp->next;
            Node* toDelete = temp->next;
            temp->next = temp->next->next;
            delete toDelete;
        }
        size--;
    }

    void printList() {
        if (isEmpty()) { cout << "Lista vazia!" << endl; return; }
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    ~LinkedList() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    LinkedList list;
    int choice, pos, value;

    do {
        cout << "\n1. Inserir elemento\n2. Remover elemento\n3. Obter valor\n4. Modificar valor";
        cout << "\n5. Verificar se está vazia\n6. Tamanho da lista\n7. Imprimir lista\n0. Sair\n";
        cout << "Escolha uma opção: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Posição: "; cin >> pos;
                cout << "Valor: "; cin >> value;
                list.insert(pos, value);
                break;
            case 2:
                cout << "Posição: "; cin >> pos;
                list.remove(pos);
                break;
            case 3:
                cout << "Posição: "; cin >> pos;
                cout << "Valor: " << list.get(pos) << endl;
                break;
            case 4:
                cout << "Posição: "; cin >> pos;
                cout << "Novo valor: "; cin >> value;
                list.set(pos, value);
                break;
            case 5:
                cout << (list.isEmpty() ? "Sim" : "Não") << endl;
                break;
            case 6:
                cout << "Tamanho: " << list.getSize() << endl;
                break;
            case 7:
                list.printList();
                break;
            case 0:
                cout << "Encerrando..." << endl;
                break;
            default:
                cout << "Opção inválida!" << endl;
        }
    } while (choice != 0);

    return 0;
}
