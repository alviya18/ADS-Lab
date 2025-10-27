#include <stdio.h>
#include <stdlib.h>

#define MAX 32  

void printSetFromBits(unsigned int bits) {
    printf("{ ");
    for(int i = 0; i < MAX; i++) {
        if(bits & (1 << i))
            printf("%d ", i);
    }
    printf("}\n");
}

unsigned int createBitSet() {
    int n, val;
    unsigned int bitset = 0;

    printf("Enter number of elements in the set: ");
    scanf("%d", &n);

    printf("Enter set elements : ");
    for(int i = 0; i < n; i++) {
        scanf("%d", &val);
        if(val >= 0 && val < MAX)
            bitset |= (1 << val);  // Set the corresponding bit
        else
            printf("Ignoring invalid element %d\n", val);
    }

    return bitset;
}

int main() {
    unsigned int set1, set2;
    unsigned int unionSet, intersectionSet, differenceSet1, differenceSet2;

    set1 = createBitSet();
    set2 = createBitSet();

    // Perform operations
    unionSet = set1 | set2;
    intersectionSet = set1 & set2;
    differenceSet1 = set1 & ~set2;  
    differenceSet2 = set2 & ~set1;

    // Print results
    printf("\nA : ");
    printSetFromBits(set1);

    printf("\nB : ");
    printSetFromBits(set2);

    printf("\nA ∪ B : ");
    printSetFromBits(unionSet);

    printf("\nA ∩ B : ");
    printSetFromBits(intersectionSet);

    printf("\nA - B : ");
    printSetFromBits(differenceSet1);
    
    printf("\nB - A : ");
    printSetFromBits(differenceSet2);

    return 0;
}
