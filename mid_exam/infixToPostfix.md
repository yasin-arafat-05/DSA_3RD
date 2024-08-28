
---

### Algorithm 1: `Postfix` (queue `input`)

**Input**: A queue `input` containing elements of an infix expression, where each element is an operand, operator, or parenthesis.

**Output**: A string `ans` representing the postfix expression.

**Procedure**:

1. **Initialize** `ans` as an empty string.
2. **Create** an empty stack `st`.
3. **Push** `"("` onto the stack `st`.
4. **Enqueue** `")"` to the end of `input`.
5. **While** `input` is not empty:
   1. **Set** `token` to the front element of `input`.
   2. **Dequeue** the front element of `input`.
   3. **If** `token` is an operator (`+`, `-`, `*`, `/`, `^`):
      - **While** the stack `st` is not empty **and** `PRECEDENCE(st.top())` is greater than or equal to `PRECEDENCE(token)`:
        1. **Pop** from `st` and **append** it to `ans` followed by a space.
      - **Push** `token` onto the stack `st`.
   4. **Else If** `token` is `")"`:
      - **While** the top of `st` is not `"("`:
        1. **Pop** from `st` and **append** it to `ans` followed by a space.
      - **Pop** `"("` from `st`.
   5. **Else If** `token` is `"("`:
      - **Push** `token` onto the stack `st`.
   6. **Else** (i.e., `token` is an operand):
      - **Append** `token` to `ans` followed by a space.
6. **Output** `ans`.

### Algorithm 2: `Precedence` (string `op`)

**Input**: A string `op` representing an operator.

**Output**: An integer representing the precedence of the operator.

**Procedure**:

1. **If** `op` is `"+"` or `"-"`:
   - **Return** 1.
2. **Else If** `op` is `"*"` or `"/"`:
   - **Return** 2.
3. **Else If** `op` is `"^"`:
   - **Return** 3.
4. **Else**:
   - **Return** 0.

---

This format mirrors the style shown in the quicksort algorithm example you provided.