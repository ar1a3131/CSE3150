#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "linked_list.h"

int zero_linked_list_elements = 0;
struct node *zero_linked_list_elements_null_node = NULL;

int one_element_linked_list = 3;
int data_value_of_initial_linked_list_element = 3;
struct node * linked_list_one_elt = build_new_linked_list(one_element_linked_list);

int two_element_linked_list = 4;
int data_value_of_second_linked_list_element = 4;
struct node * linked_list_two_elements = build_new_linked_list(two_element_linked_list);

TEST_CASE("linked_list testing"){

    SUBCASE("build_new_linked_list"){
        CHECK_EQ(build_new_linked_list(zero_linked_list_elements), zero_linked_list_elements_null_node);

        CHECK_EQ(get_linked_list_data_item_value(
                linked_list_one_elt,
                one_element_linked_list,
                one_element_linked_list),
                data_value_of_initial_linked_list_element);
        
        CHECK_EQ(get_linked_list_data_item_value(
                linked_list_two_elements,
                two_element_linked_list,
                two_element_linked_list), 
                data_value_of_second_linked_list_element);

    }

    SUBCASE("update_data_in_linked_list"){
        //updating the data of the first element in a one_element linked list
        CHECK(update_data_in_linked_list(linked_list_one_elt, 1, 13, one_element_linked_list));
        CHECK_EQ(get_linked_list_data_item_value(linked_list_one_elt,1, one_element_linked_list), 13);

        //updating the data of the second element in a two_element linked list
        CHECK(update_data_in_linked_list(linked_list_two_elements, 2, 24, two_element_linked_list));
        CHECK_EQ(get_linked_list_data_item_value(linked_list_two_elements,2, two_element_linked_list), 24);

        // Test updating data at the end of a four-element linked list
        struct node *linked_list_four_elements = build_new_linked_list(5);
        CHECK(update_data_in_linked_list(linked_list_four_elements, 5, 55, 5));
        CHECK_EQ(get_linked_list_data_item_value(linked_list_four_elements, 5, 5), 55);

        // Test updating data for an invalid node number in a five-element linked list
        struct node *linked_list_five_elements = build_new_linked_list(6);
        CHECK_FALSE(update_data_in_linked_list(linked_list_five_elements, 7, 66, 6));

    }

    SUBCASE("delete_linked_list"){
        delete_linked_list(linked_list_one_elt);
        CHECK_NOTHROW(linked_list_one_elt == nullptr); //not throw an exception
        
        struct node *empty_linked_list = nullptr;
        CHECK_NOTHROW(delete_linked_list(empty_linked_list)); // Should not throw an exception
        
        struct node *large_linked_list = build_new_linked_list(50);
        delete_linked_list(large_linked_list);
        CHECK_NOTHROW(large_linked_list == nullptr); 
    }

}