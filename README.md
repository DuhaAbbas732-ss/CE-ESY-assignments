# Assignment 1 - Circular Buffer Implementation in C

## Note
I will explain the assignment in english, because it's suitable for GitHub.

## Project Description

This program implements a **Circular Buffer** (Ring Buffer) in the C programming language, exactly following the pseudocode provided in the assignment.

A circular buffer is a fixed-size data structure that uses three variables to manage data:
- **`head`**: points to the next data to be read
- **`tail`**: points to the next empty slot for writing
- **`count`**: keeps track of how many items are currently in the buffer

When the buffer reaches the end, it wraps around to the beginning — hence the name **circular**.

---

## Pseudocode vs C Implementation

| Pseudocode | C Code |
|------------|--------|
| `DEFINE SIZE = N` | `#define SIZE 12` |
| `STRUCT CircularBuffer` | `struct CircularBuffer` |
| `buffer[SIZE]` | `char buffer[SIZE]` |
| `int head = 0` | `int head` |
| `int tail = 0` | `int tail` |
| `int count = 0` | `int count` |
| `FUNCTION init(cb)` | `void init(struct CircularBuffer *cb)` |
| `FUNCTION isFull(cb)` | `bool isFull(struct CircularBuffer *cb)` |
| `FUNCTION isEmpty(cb)` | `bool isEmpty(struct CircularBuffer *cb)` |
| `FUNCTION write(cb, data)` | `void write(struct CircularBuffer *cb, char data)` |
| `FUNCTION read(cb)` | `char read(struct CircularBuffer *cb)` |
| `PRINT "Buffer Overflow"` | `printf("Buffer Overflow\n")` |
| `PRINT "Buffer Underflow"` | `printf("Buffer Underflow\n")` |
| `RETURN NULL` | `return '\0'` |

---

## Program Flow

The program follows these exact steps from the assignment:

1. **DECLARE CircularBuffer cb**
2. **init(cb)** - Initialize the buffer
3. **DECLARE string name**
4. **INPUT name** - Read user name from standard input
5. **name = name + "CE-ESY"** - Append required suffix
6. **FOR each char in name:** - Write each character to buffer using `write(cb, char)`
7. **WHILE NOT isEmpty(cb):** - Read back and print using `read(cb)`
8. **PRINT char (without newline)** - Display the result

---

## Functions Description

| Function | Purpose | Returns |
|----------|---------|---------|
| `init(cb)` | Initializes head, tail, and count to 0 | Nothing |
| `isFull(cb)` | Checks if buffer is full | `true` if full, `false` otherwise |
| `isEmpty(cb)` | Checks if buffer is empty | `true` if empty, `false` otherwise |
| `write(cb, data)` | Writes one character to buffer | Nothing (prints "Buffer Overflow" if full) |
| `read(cb)` | Reads one character from buffer | Character (prints "Buffer Underflow" if empty, returns `'\0'`) |

---

## How to Compile and Run

### Compile
```bash
gcc circular_buffer.c -o circular_buffer