#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "linkedlist.h"

TEST_CASE("Testing modified linkedlist functionality") {
    linkedlist lst;

    SUBCASE("Test empty list initialization after changes") {
        CHECK(lst.getNodeCount() == 0);
        lst.printLst();  // Should output nothing indicating the list is empty
    }

    SUBCASE("Adding nodes to the modified list") {
        lst.append(10);
        CHECK(lst.getNodeCount() == 1);

        lst.prepend(20);
        CHECK(lst.getNodeCount() == 2);

        SUBCASE("Check node connectivity and count increment in modified list") {
            lst.append(30);
            CHECK(lst.getNodeCount() == 3);
            lst.printLst(); // Expected output: 20 10 30
        }
    }
}