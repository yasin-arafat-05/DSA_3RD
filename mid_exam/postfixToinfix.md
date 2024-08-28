

---

### Algorithm 1: `PostfixToInfix` (queue `input`)

**Input**: A queue `input` containing elements of a postfix expression, where each element is an operand or operator.

**Output**: A string representing the equivalent infix expression.

**Procedure**:

1. **Initialize** an empty stack `st`.
2. **While** `input` is not empty:
   1. **Set** `token` to the front element of `input`.
   2. **Dequeue** the front element of `input`.
   3. **If** `token` is an operator (`+`, `-`, `*`, `/`):
      - **Pop** the top element of `st` into `operator2`.
      - **Pop** the next top element of `st` into `operator1`.
      - **Create** a string `exp` as `"(" + operator1 + token + operator2 + ")"`.
      - **Push** `exp` onto the stack `st`.
   4. **Else** (i.e., `token` is an operand):
      - **Push** `token` onto the stack `st`.
3. **Output** the top element of `st`.

---


