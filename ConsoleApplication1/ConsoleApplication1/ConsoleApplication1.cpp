#include <iostream>
#include "List.h";

void ListPrint(List<int> list)
{
    list.Print();
}

List<int> ListReturn()
{
    List<int> list;
    list.Insert(0, 1);
    list.Insert(0, 2);
    list.Insert(0, 3);
    list.Insert(0, 4);

    return list;
}

int main()
{
    List<int> list;
    list.Insert(0, 100);
    list.Insert(0, 200);
    list.Insert(0, 300);

    list.Insert(list.Size(), 400);

    list.Insert(2, 500);

    list.Insert(list.Size(), 300);

    list.Print();

    list[3] = 700;

    list.Print();

    //ListPrint(list);

    List<int> listNew = ListReturn();
    ListPrint(listNew);

    /*std::cout << list.Find(100) << "\n";
    std::cout << list.Find(300) << "\n";

    std::cout << list.At(0) << "\n";*/
}
