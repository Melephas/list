#include <criterion/criterion.h>
#include <criterion/new/assert.h>

#include "list/list.h"


list* test_list = NULL;

void setup() {
    test_list = list_new();
}

void teardown() {
    list_destroy(test_list);
    cr_expect(test_list == NULL);
}

TestSuite(basic, .init = setup, .fini = teardown);

Test(basic, always_pass) {
    cr_assert(1, "Something is really wrong here! Failed 'cr_assert(1)'.");
}

Test(basic, allocation) {
    cr_expect(ne(ptr, test_list, NULL), "Memory allocation in 'list_new()' failed.");
}

