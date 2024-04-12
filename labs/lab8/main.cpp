#include "linkedlist.h"
#include <iostream>

int main() {
    linkedlist lst;
    lst.append(10);
    lst.prepend(20);
    lst.append(30);
    lst.prepend(40);
    std::cout << "Current List: ";
    lst.printLst();
    std::cout << "List Size: " << lst.getNodeCount() << std::endl;
    return 0;
}
