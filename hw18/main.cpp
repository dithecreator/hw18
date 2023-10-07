//
//  main.cpp
//  hw18
//
//  Created by Дима on 07.10.23.
//


#include <iostream>
#include <string.h>
#include <time.h>
using namespace std;

class Stack
{
    // нижняя и верхняя границы стека
    enum { EMPTY = -1, FULL = 5 };

    // массив для хранения данных
    char st[FULL + 1];

    // указатель на вершину стека
    int top;

public:
    //  конструктор
    Stack();

    // добавление элемента
    void Push(char c);

    // извлечение элемента
    char Pop();

    // очистка стека
    void Clear();

    // проверка существования элементов в стеке
    bool IsEmpty();

    // проверка на переполнение стека
    bool IsFull();

    //  количество элементов в стеке
    int GetCount();
    
    //получение последнего символа
    char getLast();
    int getSize();
    bool checkSymbol(string text);
    bool checkSymbol1(string text);
    bool checkSymbol2(string text);
    bool Check(Stack ST, string userStr);
    void print();
    char Top();
};


Stack::Stack()
{
    //изначально стек пуст
    top = EMPTY;
}

void Stack::Clear()
{
    //эффективная очистка стека
    //(данные в массиве всё ещё существуют), но функции класса
    //ориентированные на работу с вершиной стека будут их игнорировать
    top = EMPTY;
}

bool Stack::IsEmpty()
{
    // проверка на пустоту
    return top == EMPTY;
}



bool Stack:: checkSymbol(string text){
    int openCount = 0;
    int closeCount = 0;
    int i = 0;
    char c;
    while (i < text.length()){
          c = text[i];
         if (c == '(') {
             openCount++;
         }
         else if (c == ')') {
             closeCount++;
             if (closeCount != openCount) {
                 return false;
             }
         }
        if(text[i] == ';'){
            break;
        }
             i++;
     }
    return openCount == closeCount;
}


bool Stack:: checkSymbol1(string text){
    int openCount = 0;
    int closeCount = 0;
    int i = 0;
    char c;
    while (i < text.length()){
          c = text[i];
         if (c == '[') {
             openCount++;
         }
         else if (c == ']') {
             closeCount++;
             if (closeCount != openCount) {
                 return false;
             }
         }
        if(text[i] == ';'){
            break;
        }
             i++;
     }
    return openCount == closeCount;
}


bool Stack:: checkSymbol2(string text){
    int openCount = 0;
    int closeCount = 0;
    int i = 0;
    char c;
    while (i < text.length()){
          c = text[i];
         if (c == '{') {
             openCount++;
         }
         else if (c == '}') {
             closeCount++;
             if (closeCount != openCount) {
                 return false;
             }
         }
        if(text[i] == ';'){
            break;
        }
             i++;
     }
    return openCount == closeCount;
}


bool Stack::IsFull()
{
    // проверка на полность
    return top == FULL;
}

int Stack::GetCount()
{
    //  количество присутствующих в стеке элементов
    return top + 1;
}

void Stack::Push(char c)
{
    // если в стеке есть место, то увеличиваем указатель
    // на вершину стека и вставляем новый элемент
    if (!IsFull())
        st[++top] = c; //если стек не полон, увеличиваем вершину и добавляем на это место символ
}

char Stack::Pop() //извлекаем верхний элемент
{
//если в стеке есть элементы, то возвращаем верхний
//и уменьшаем указатель на вершину стека
    if (!IsEmpty()){
        return st[top--];
    }
    else{ // если в стеке элементов нет
        return 0;
    }
}

char Stack :: getLast(){
    return st[FULL];
}

int Stack :: getSize(){
    return FULL;
}
void Stack:: print(){
    for(int i = 0; i <= top; i++){
        cout << st[i] << " ";
    }
    cout << endl;
}

int main()
{
    

    Stack ST;
    char c;
    string text;
    cout << "enter some text: ";
    cin >> text;
//    cout << "enter a symbol: ";
    
//    while (!ST.IsFull()) {   // пока стек не заполнится
//        c = rand() % 100;
//        ST.Push(c);
//        cin >> c;
//        ST.Push(c);
//    }
    
    
    
//     пока стек не освободится
//    while (c = ST.Pop()) { //вывод стека в консоль
//        cout << c << " ";
//    }
//    cout << "\n\n";
    
//    ST.print();
    

    if(ST.checkSymbol(text)){
        cout << "(): correct" << endl;
    }
    else{
        cout << "(): incorrect" << endl;
    }

    if(ST.checkSymbol1(text)){
        cout << "[]: correct" << endl;
    }
    else{
        cout << "[]: incorrect" << endl;
    }

    if(ST.checkSymbol2(text)){
        cout << "{}: correct" << endl;
    }
    else{
        cout << "{}: incorrect" << endl;
    }

    
    
//    char last = ST.getLast();
//    cout << "last symbol: " << last << endl;
     
//    char input[100];
//    cout << "Enter a string: ";
//    cin.getline(input, sizeof(input)); // Считываем строку

//    Stack ST;
//    ST.Push('A');
//    ST.Push('B');
//    ST.Push('C');
//    ST.Push('D');
//    ST.print();
//    ST.Pop();
//    ST.print();
//    ST.Clear();
//    ST.print();
}

