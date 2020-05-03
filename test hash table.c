
#include"hash table.h"
#include<stdlib.h>
#include<string.h>
#include<stdio.h>

void test_hash_table(void)
{
    //testing hash table - do it for different TABLE_SIZE e.g. 1,2,5,100, 100000
    ht_t *my_ht = create_ht();

    set_ht_entry(my_ht, "name_1", "111");
    set_ht_entry(my_ht, "name_2", "222");
    set_ht_entry(my_ht, "name_3", "333");
    set_ht_entry(my_ht, "name_4", "444");
    set_ht_entry(my_ht, "name_1", "111_second"); // test updating existing key with longer string
    set_ht_entry(my_ht, "name_5", "555");
    set_ht_entry(my_ht, "name_5", "555_second"); // test updating existing key with longer string
    set_ht_entry(my_ht, "name_6", "666");
    set_ht_entry(my_ht, "name_8", "888");
    set_ht_entry(my_ht, "name_9", "999");
    set_ht_entry(my_ht, "name_a", "a");
    set_ht_entry(my_ht, "name_b", "bb");
    set_ht_entry(my_ht, "name_c", "ccc");
    set_ht_entry(my_ht, "name_d", "dddd");
    set_ht_entry(my_ht, "name_e", "eee");
    set_ht_entry(my_ht, "name_f", "ff");
    set_ht_entry(my_ht, "name_g", "ggggggg");

    preview_ht(my_ht);

    // test remove operation
    remove_ht_key(my_ht, "name_4");
    remove_ht_key(my_ht, "name_1");
    remove_ht_key(my_ht, "name_6");
    remove_ht_key(my_ht, "name_3");
    remove_ht_key(my_ht, "name_6");          // test remove attempt of previously removed entry
    remove_ht_key(my_ht, "name_2");
    remove_ht_key(my_ht, "non-existent");   // test removing non-existent entry

    printf("\n********* after remove operation ********\n");
    printf("\n");

    preview_ht(my_ht);

    //test reading entry
    printf("\n Entry value for key: name_9 = %s\n",get_ht_entry(my_ht, "name_9"));
    printf("\n Entry value for non-existing key = %s\n",get_ht_entry(my_ht, "name_non-existing3232"));
    printf("\n Entry value for removed key = %s\n",get_ht_entry(my_ht, "name_1"));

}
