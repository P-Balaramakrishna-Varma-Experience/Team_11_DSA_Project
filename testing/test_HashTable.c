#include "../Header/HashTable.h"
#include <time.h>

int main() {
    srand(time(NULL));
    Table T = InitTable(101);
    T = AddElement(T, 909);
    T = AddElement(T, 808);
    T = AddElement(T, 1);
    for(int i = 0; i < 99; i++) {
        int a = rand() % 1001;
        T = AddElement(T, a);
    }
    PrintTable(T);
    T = RemoveElement(T, 1);
    int b = rand() % 1001;
    T = AddElement(T, b);
    PrintTable(T);
}