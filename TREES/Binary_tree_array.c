#include <stdio.h>

#define SIZE 14

int left_child_index(int index) {
    return 2 * index + 1;
}

int right_child_index(int index) {
    return 2 * index + 2;
}

char get_data(int index, char tree[], int size) {
    if (index >= 0 && index < size)
        return tree[index];
    else
        return '\0';
}

int main() {

    char binary_tree_array[SIZE] = {
        'R', 'A', 'B', 'C', 'D', 'E', 'F',
        '\0', '\0', '\0', '\0', '\0', '\0', 'G'
    };

    int right_child = right_child_index(0);

    int left_child_of_right_child = left_child_index(right_child);

    char data = get_data(left_child_of_right_child, binary_tree_array, SIZE);

    if (data != '\0')
        printf("root.right.left.data: %c\n", data);
    else
        printf("No node exists at that index.\n");

    return 0;
}
