     Mini Compiler Project body { font-family: Arial, sans-serif; line-height: 1.6; margin: 0; padding: 0; } header, footer { background: #333; color: #fff; padding: 10px 20px; text-align: center; } .container { padding: 20px; } h1, h2 { color: #333; } code { background: #f4f4f4; border: 1px solid #ddd; display: block; padding: 10px; margin: 10px 0; } a { color: #007BFF; }

Mini Compiler Project
=====================

This is a mini compiler project built in C that covers essential stages of the compilation process, including lexical analysis, NFA/DFA conversion, and left recursion elimination. The goal of this project is to demonstrate fundamental concepts used in compilers, providing a foundation for learning compiler construction techniques.

Features
--------

*   **Lexical Analysis:** Scans the source code to identify tokens like keywords, operators, and identifiers.
*   **NFA/DFA Conversion:** Constructs a Non-deterministic Finite Automaton (NFA) and converts it into a Deterministic Finite Automaton (DFA) for efficient token recognition.
*   **Left Recursion Elimination:** Transforms grammars to remove left recursion, making them suitable for top-down parsers (LL(1)).

Getting Started
---------------

To use this compiler, follow the steps below to set up the project on your local machine.

### Prerequisites

*   C compiler (e.g., GCC)
*   A code editor or IDE (e.g., Visual Studio Code, Code::Blocks)

### Installation

1.  Clone the repository to your local machine:
`git clone https://github.com/<username>/mini-compiler.git`3.  Navigate to the project directory:
`cd mini-compiler`5.  Compile the code:
`gcc -o compiler main.c`7.  Run the compiler:
`./compiler input.txt`

Replace `input.txt` with your source code file.

How It Works
------------

*   **Lexical Analysis:** The source code is tokenized by scanning the input and using regular expressions to match token patterns.
*   **NFA/DFA Conversion:** An NFA is created based on token definitions and then converted into a DFA for more efficient parsing.
*   **Left Recursion Elimination:** Left-recursive rules are rewritten into right-recursive ones to make the grammar LL(1) compatible.

Contributing
------------

Feel free to fork this repository and contribute to its improvement. If you encounter bugs or want to suggest features, please open an issue or submit a pull request.

License
-------

This project is licensed under the MIT License - see the `LICENSE` file for details.

Author
------

**Md. Asraful Alom**

Copyright
---------

© 2024 Md. Asraful Alom. All rights reserved.

Mini Compiler Project © 2024