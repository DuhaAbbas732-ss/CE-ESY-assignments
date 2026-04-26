# Assignment 1: Circular Buffer in C

## Project Description

This program implements a **Circular Buffer** (also known as a Ring Buffer) in the C programming language.  
A circular buffer is a fixed-size data structure that efficiently stores and retrieves data using two pointers:
- **`head`**: points to the next data to be read.
- **`tail`**: points to the next empty slot for writing.
- **`count`**: keeps track of how many items are currently in the buffer.

When the buffer reaches the end, it "wraps around" to the beginning — hence the name **circular**.

---

## How the Program Works

The program follows these exact steps:

1. **Asks for the user's name** using standard input (`stdin`).
2. **Appends the string `"CE-ESY"`** to the entered name.
3. **Writes each character** of the resulting string into the circular buffer one by one.
4. **Reads the characters back** from the buffer and displays them on the screen.
5. **Ensures the buffer becomes empty** after reading all data.

---

## Important Features

- Handles Buffer Overflow – If you try to write to a full buffer, an error message is printed.
- Handles Buffer Underflow – If you try to read from an empty buffer, an error message is printed.
- Works with different buffer sizes – You can test small and large buffers by changing one line of code.

---

## Testing the Buffer Sizes

You can easily test two different cases:

| Buffer Size | Number of Characters | Expected Result |
|-------------|----------------------|------------------|
| Small (e.g., 8) | More than 8 | Overflow occurs (some data cannot be written) |
| Large (e.g., 20) | Less than 20 | All data written and read successfully, buffer ends empty |

To change the buffer size, modify this line in the code:  
`#define SIZE 12` → change `12` to any number you want.

---

## Functions Used

| Function           | Purpose                                                                 |
|--------------------|-------------------------------------------------------------------------|
| `init()`           | Initializes the buffer (head = 0, tail = 0, count = 0).                 |
| `isFull()`         | Checks if the buffer is full.                                           |
| `isEmpty()`        | Checks if the buffer is empty.                                          |
| `write()`          | Adds one character to the buffer if there is space. Otherwise, prints "Overflow". |
| `read()`           | Removes and returns one character from the buffer if available. Otherwise, prints "Underflow". |
| `main()`           | Controls the whole program flow (input, appending, writing, reading, output). |

---

## Example Run

### Example 1: Buffer size = 12 (successful)
