#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define SIZE 12   // Change to 8 or 20 to test different sizes

typedef struct {
    char buffer[SIZE];
    int head;
    int tail;
    int count;
} CircularBuffer;

void init(CircularBuffer *cb) {
    cb->head = 0;
    cb->tail = 0;
    cb->count = 0;
}

bool isFull(CircularBuffer *cb) {
    return cb->count == SIZE;
}

bool isEmpty(CircularBuffer *cb) {
    return cb->count == 0;
}

void write(CircularBuffer *cb, char data) {
    if (isFull(cb)) {
        printf("Overflow! Cannot write '%c', buffer is full.\n", data);
        return;
    }
    cb->buffer[cb->tail] = data;
    cb->tail = (cb->tail + 1) % SIZE;
    cb->count++;
}

char read(CircularBuffer *cb) {
    if (isEmpty(cb)) {
        printf("Underflow! Buffer is empty, cannot read.\n");
        return '\0';
    }
    char data = cb->buffer[cb->head];
    cb->head = (cb->head + 1) % SIZE;
    cb->count--;
    return data;
}

int main() {
    CircularBuffer cb;
    init(&cb);

    char name[100];
    printf("Enter your name: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';

    // Append "CE-ESY"
    strcat(name, "CE-ESY");
    int length = strlen(name);
    printf("\nText to store: \"%s\" (length = %d)\n", name, length);
    printf("Current buffer size = %d\n\n", SIZE);

    // Write each character
    printf("--- Writing ---\n");
    for (int i = 0; i < length; i++) {
        write(&cb, name[i]);
    }

    // Read and display
    printf("\n--- Reading ---\nOutput: ");
    while (!isEmpty(&cb)) {
        char ch = read(&cb);
        if (ch != '\0') putchar(ch);
    }
    printf("\n");

    // Verify buffer is empty
    if (isEmpty(&cb)) {
        printf("\n✓ Buffer is completely empty after reading.\n");
    } else {
        printf("\n✗ Error: Buffer still contains data.\n");
    }

    return 0;
}