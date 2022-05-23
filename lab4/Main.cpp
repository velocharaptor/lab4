#include <iostream>
#include "BinaryTree.h"
#include "Tests.h"
using namespace std;

int plusOne(int a) {
    return a + 1;
}

int multipluByTwo(int a) {
    return a * 2;
}

bool isMoreThan8(int a) {
    return a > 8;
}

#define menu cout<<"Команды:\n\t1)Задать дерево с клавиатуры\n\t2)Мое дерево (9 6 3 1 4 8 7 17 16 12 11 14 20 19 18 21)\n\t3)Получить поддерево\n\t4)Добавить элемент\n\t5)map\n\t6)where\n\t7)Удалить элемент\n\t8)Найти элемент\n\t9)Вывести дерево\n10)Запустить тесты\n11)Выход\n"

int main() {
    setlocale(LC_ALL, "rus");

    menu;
    while (true) {
        int switcher;
        cin >> switcher;
        string s = "9 6 3 1 4 8 7 17 16 12 11 14 20 19 18 21";
        BinaryTree<int> BT(s);
        switch (switcher) {
        case 1:
            break;
        case 2:
            break;
        case 3: {
            cout << "Введите корень нового дерева: ";
            int newRoot;
            cin >> newRoot;
            BT.getSubTree(newRoot).print();
            break;
        }
        case 4: {
            cout << "Введите новый элемент: ";
            int newElem;
            cin >> newElem;
            BT.insert(newElem);
            cout << "Новый элемент успешно добавлен!\n";
            break; 
        }
        case 5: {
            int (*pt2Func1)(int) = nullptr;
            pt2Func1 = &plusOne;
            BT.map(pt2Func1);
            cout << "Успешно!\n";
            break; 
        }
        case 6: {
            BinaryTree<int> treeRes(9);
            bool (*pt2Func2)(int) = nullptr;
            pt2Func2 = &isMoreThan8;
            BT.where(treeRes, pt2Func2);
            treeRes.print();
            break; 
        }
        case 7: {
            cout << "Введите элемент для удаления: ";
            int delElem;
            cin >> delElem;
            BT.erase(delElem);
            cout << "Элемент успешно удален!";
            break;
        }
        case 8: {
            cout << "Введите элемент для поиска: ";
            int findElem;
            cin >> findElem;
            if (BT.find(findElem))
                cout << "Элмент найден\n";
            else
                cout << "Элмент не найден\n";
            break;
        }
        case 9: 
            BT.print();
            break;
        case 10:
            startAllTests();
            break;
        case 11:
            return 0;
            break;
        default:
            return 0;
            break;
        }
    }
}