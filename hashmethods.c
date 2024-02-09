#include<stdio.h>
#include<stdlib.h>
#define n 10
int division(int key) {
    return (key % n);
}

int midsquare(int key) {
    int square = key * key;
    return (square / 100) % n;
}
 
int digitfold(int key) {
    int sum = 0;
    while (key > 0) {
        sum =sum+ key % 10;
        key =key/ 10;
    }
    return (sum % n);
}

void insert(int head[], int key) {
    int div = division(key);
    int mid = midsquare(key);
    int fold = digitfold(key);

    if (head[div] == -1) {
        head[div] = key;
        printf("\nInserted Succecfully using division method.!\n");
        return;
    } else {
        printf("\nCollision occur using division method.\n");
    }

    if (head[mid] == -1) {
        head[mid] = key;
        printf("\nInserted Succecfully using mid square method.!\n");
        return;
    } else {
        printf("\nCollision occur using mid square method.\n");
    }

    if (head[fold] == -1) {
        head[fold] = key;
        printf("\nInserted Succecfully using digit folding method.!\n");
        return;
    } else {
        printf("\nCollision occur using digit folding method.\n");
    }
}

int search(int head[], int key) {
    int i, index;
    for (i = 0; i < n; i++) {
        index = (key % n + i) % n;
        if (head[index] == key) {
            return index;
        }
    }
    return -1;
}

void delete(int head[], int key) {
    int index;
    index = search(head, key);
    if (index == -1) {
        printf("\nKey not found!\n");
    } else {
        head[index] = -1;
    }
}

void display(int head[]) {
    int i;
    for (i = 0; i < n; i++) {
        printf("\n%d--->[%d]", i, head[i]);
    }
}

int main() {
    int head[n], ch, key, i, index;
    for (i = 0; i < n; i++) {
        head[i] = -1;
    }

    while (1) {
        printf("\nEnter your choice:");
        printf("\nPress\n1.Insert\n2.Search\n3.Delete\n4.Display\n5.Exit\n");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter the key to be inserted:");
                scanf("%d", &key);
                insert(head, key);
                break;
            case 2:
                printf("Enter the key to be searched:");
                scanf("%d", &key);
                index = search(head, key);
                if (index == -1) {
                    printf("\nKey element not found!\n");
                } else {
                    printf("\nKey element found at index %d\n", index);
                }
                break;
            case 3:
                printf("Enter the key to be deleted:");
                scanf("%d", &key);
                delete(head, key);
                break;
            case 4:
                printf("\nHash Table:\n");
                display(head);
                break;
            case 5:
                exit(0);
        }
    }

    return 0;
}

