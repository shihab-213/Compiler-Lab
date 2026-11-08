# Compiler Design Lab Assignment (CSE-3141)

This repository contains the C/C++ implementations for the **Compiler Design** laboratory assignment. The problems cover the core phases of a compiler, progressing from foundational string manipulation and lexical analysis (regular expressions and tokenization) to syntax analysis (Context-Free Grammars, Chomsky Normal Form auditing, Shift-Reduce parsing, and $LL(1)$ predictive parsing) and intermediate code generation (Postfix notation).

---

## 📂 Problem List & Overview

### Part 1: String Manipulation & Pre-processing
1. **Character & Word Classification:** Reads `"Md. Tareq Zaman, Part-3, 2011"`, counts words, letters, digits, and special characters, and separates each category.
2. **Vowel & Consonant Analyzer:** Reads `"Munmun is the student of Computer Science & Engineering"`, counts and lists unique vowels and consonants, and splits words into two strings based on whether they start with a vowel or a consonant.
3. **Course Code Expander:** Abbreviates/expands codes like `CSE-3141` into `"Computer Science & Engineering, 3rd year, 1st semester, Compiler Design, Theory"`.

### Part 2: Lexical Analysis & Regular Expressions
4. **Integer Lexical Analyzer:** Reads tokens from `input.txt` and classifies them into `Integer variable`, `ShortInt Number`, `LongInt Number`, or `Invalid Input`:
   - $\text{Integer variable} = (i\text{-}n \mid I\text{-}N)(a\text{-}z \mid A\text{-}Z \mid 0\text{-}9)^*$
   - $\text{ShortInt Number} = (1\text{-}9) \mid (1\text{-}9)(0\text{-}9) \mid (1\text{-}9)(0\text{-}9)(0\text{-}9) \mid (1\text{-}9)(0\text{-}9)(0\text{-}9)(0\text{-}9)$
   - $\text{LongInt Number} = (1\text{-}9)(0\text{-}9)(0\text{-}9)(0\text{-}9)(0\text{-}9)^+$
5. **Floating-Point Lexical Analyzer:** Reads tokens from `input.txt` and classifies them into `Float variable`, `Float Number` (2 decimal places), `Double Number` (3+ decimal places), or `Invalid Input`:
   - $\text{Float variable} = (a\text{-}h \mid A\text{-}H \mid o\text{-}z \mid O\text{-}Z)(a\text{-}z \mid A\text{-}Z \mid 0\text{-}9)^*$
   - $\text{Float Number} = 0.(0\text{-}9)(0\text{-}9) \mid (1\text{-}9)(0\text{-}9)^*.(0\text{-}9)(0\text{-}9)$
   - $\text{Double Number} = 0.(0\text{-}9)(0\text{-}9)(0\text{-}9)^+ \mid (1\text{-}9)(0\text{-}9)^*.(0\text{-}9)(0\text{-}9)(0\text{-}9)^+$
6. **Character & Binary Lexical Analyzer:** Reads tokens from `input.txt` and recognizes:
   - $\text{Character variable} = ch\_(a\text{-}z \mid A\text{-}Z \mid 0\text{-}9)(a\text{-}z \mid A\text{-}Z \mid 0\text{-}9)^*$
   - $\text{Binary variable} = bn\_(a\text{-}z \mid A\text{-}Z \mid 0\text{-}9)(a\text{-}z \mid A\text{-}Z \mid 0\text{-}9)^*$
   - $\text{Binary Number} = 0(0 \mid 1)(0 \mid 1)^*$
7. **C++ Lexical Recognizer:** Identifies C++ Keywords, Identifiers, Operators, and Constants.
8. **C++ Token Classifier:** Converts individual C++ words/lexemes into their equivalent token category (e.g., `646.45` $\rightarrow$ `Float`, `do` $\rightarrow$ `Keyword`, `+` $\rightarrow$ `Arithmetic Operator`).

### Part 3: Syntax Analysis & Context-Free Grammars (CFG)
9. **(a) CNF Syntax Audit Tool:** Reads production rules from `grammar.txt` (using `$` for $\epsilon$) and checks for structural violations against Chomsky Normal Form (Mixed rules, Unit rules, Start symbol on RHS, and Long rules $> 2$ non-terminals).
   **(b) English Sentence CNF Validator:** Validates whether an English present indefinite sentence is syntactically valid according to a predefined CNF grammar ($S \rightarrow \text{SUB PRED}$).
10. **Shift-Reduce Parser:** Implements a bottom-up shift-reduce parsing algorithm using a stack and input buffer.
11. **Syntax Tree Generator:** Generates a syntax tree for the expression $a + b * c$ using the grammar $E \rightarrow E+E \mid E-E \mid E*E \mid E/E \mid (E) \mid a \mid b \mid c$.
12. **Arithmetic Expression Validator:** Validates arithmetic expressions (e.g., `2+3*5` $\rightarrow$ `VALID`, `2+*3*5` $\rightarrow$ `INVALID`) using the grammar $E \rightarrow E\ A\ E \mid (E) \mid ID$.
13. **FIRST and FOLLOW Set Generator:** Computes the $\text{FIRST}$ and $\text{FOLLOW}$ sets for any given Context-Free Grammar.
14. **$LL(1)$ FOLLOW Set & Parsing Table Generator:** Computes the $\text{FOLLOW}$ set and constructs the $LL(1)$ predictive parsing table from a given non-left-recursive expression grammar and its $\text{FIRST}$ set.
15. **Predictive Parser Trace / Parse Tree:** Generates the parse tree / derivation steps using a predefined $LL(1)$ parsing table for expressions containing `id`, `+`, `*`, `(`, `)`, and `$`.

### Part 4: Intermediate Code Generation
16. **Infix to Postfix Converter (Expressions):** Converts standard parenthesized C++ infix expressions like $(A-B)*(D/E)$ into Postfix notation (`AB-DE/*`).
17. **Infix to Postfix Converter (Conditional Statements):** Converts nested C++ `if-then-else` statements into intermediate Postfix notation with conditional jumps (`?`).

---

## 🗂️ Recommended Directory Structure

```text
compiler-design-assignment/
├── README.md
├── inputs/
│   ├── input.txt          # Sample input file for Problems 4, 5, 6, and 12
│   └── grammar.txt        # Sample CFG rules for Problem 9(a)
└── src/
    ├── 01_char_count_separate.c
    ├── 02_vowel_consonant_split.c
    ├── 03_course_code_abbreviation.cpp
    ├── 04_integer_lexer.cpp
    ├── 05_float_double_lexer.cpp
    ├── 06_char_binary_lexer.cpp
    ├── 07_cpp_token_recognizer.cpp
    ├── 08_word_to_token.cpp
    ├── 09a_cnf_syntax_audit.cpp
    ├── 09b_english_cnf_validator.cpp
    ├── 10_shift_reduce_parser.cpp
    ├── 11_syntax_tree_generator.cpp
    ├── 12_expression_validator.cpp
    ├── 13_first_follow_generator.cpp
    ├── 14_ll1_parsing_table.cpp
    ├── 15_predictive_parser_tree.cpp
    ├── 16_infix_to_postfix_expr.cpp
    └── 17_if_else_to_postfix.cpp
```

---

## ⚙️ Prerequisites & Compilation

To compile and run these programs, ensure you have a standard C/C++ compiler installed (such as `gcc` / `g++` via MinGW on Windows or build-essential on Linux/macOS).

### Compiling C Programs
```bash
gcc src/01_char_count_separate.c -o 01_char_count_separate
./01_char_count_separate
```

### Compiling C++ Programs
```bash
g++ -std=c++17 src/04_integer_lexer.cpp -o 04_integer_lexer
./04_integer_lexer
```

> **Note for File-Based Programs (Problems 4, 5, 6, 9a, 12):** Make sure `input.txt` or `grammar.txt` is present in the working directory from which you execute the binary.

---

## 📝 Sample Input Files

### `grammar.txt` (For Problem 9a)
```text
S -> AB | $ | a
A -> aA | b
B -> C | S
C -> abc
```

### `input.txt` (For Problems 4–6)
```text
num1 45 123456 abc 0.25 12.345 ch_var1 bn_01 01011
```