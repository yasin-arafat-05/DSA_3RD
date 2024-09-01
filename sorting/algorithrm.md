
# quickSort Algorithrm: 
<br>
<br>

1. **Input**: An array `arr`, starting index `s`, ending index `e`.
2. **Output**: The array `arr` is sorted in place.

<br>
<br>


### Algorithm 1: `QuickSort` (array `arr`, `s`, `e`)

3. **Procedure**:
   1. **If** `s ≥ e` **then**
   2. &emsp; **Return**
   3. **End if**
   4. `p` = `Partition(arr, s, e)`
   5. `QuickSort(arr, s, p-1)`
   6. `QuickSort(arr, p+1, e)`

<br>
<br>

### Algorithm 2: `Partition` (array `arr`, `s`, `e`)

   1. `poviet` = `arr[s]`
   2. `cnt` = 0
   3. **For** `i = s + 1` **to** `e` :
   4. &emsp; **If** `arr[i] ≤ poviet` **then**
   5. &emsp;&emsp; `cnt = cnt + 1`
   6. &emsp; **End if**
   7. **End for**
   8. `povietIndex = s + cnt`
   9. `Swap(arr[povietIndex], arr[s])`
   10. `i = s`, `j = e`
   11. **While** `i < povietIndex` **and** `j > povietIndex`:
   12. &emsp; **While** `arr[i] < poviet`:
   13. &emsp;&emsp; `i = i + 1`
   14. &emsp; **End while**
   15. &emsp; **While** `arr[j] > poviet`:
   16. &emsp;&emsp; `j = j - 1`
   17. &emsp; **End while**
   18. &emsp; **If** `i < povietIndex` **and** `j > povietIndex` **then**
   19. &emsp;&emsp; `Swap(arr[i], arr[j])`
   20. &emsp;&emsp; `i = i + 1`, `j = j - 1`
   21. &emsp; **End if**
   22. **End while**
   23. **Return** `povietIndex`


