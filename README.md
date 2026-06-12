GUI Calculator

A desktop calculator application built with C++ and Qt, featuring a clean GUI and support for multi-step arithmetic expressions with proper operator precedence.

Features:

Basic arithmetic: addition, subtraction, multiplication, division
Multi-step expression evaluation with correct order of operations
Parentheses support for grouping expressions
Decimal point input
Sign toggle (+/-) on the last number in the expression
Clear (AC) and backspace (⌫) controls

## Screenshots
<img width="217" height="179" alt="CalcPic" src="https://github.com/user-attachments/assets/61604694-7117-4c91-99b4-99e128e6c9ce" />

Tech Stack:

Language: C++
Framework: Qt (Qt Widgets)
Build System: qmake

How It Works:

Expressions are evaluated using the Shunting-Yard algorithm, which converts infix notation (e.g., 3 + 4 × 2) into postfix (Reverse Polish Notation) before computing the result. This ensures multiplication and division are evaluated before addition and subtraction, and parentheses are respected.
