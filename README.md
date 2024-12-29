# Push_swap_42
The Push_swap project teaches concepts like stack data structures, algorithm design, and optimization. It focuses on sorting data using a minimal number of operations, helping students develop efficient algorithms and refine their problem-solving abilities.
# Push_swap Algorithm (Mandatory part)

## 📜 Step-by-Step Explanation

### 1️⃣ Initialize Stacks `stk_a` and `stk_b`
- **Initialize `stk_a` and `stk_b`**:
  - Create and initialize the linked list for `stk_a` with the input values.
  - Initialize `stk_b` as an empty stack.

### 2️⃣ Validate Input
- **Validate Input**:
  - Ensure that the input values are valid integers.
  - Check for duplicate values in the input.
  - Ensure that the input values are within the acceptable range.

### 3️⃣ Check if the List is Already Sorted
- **Check if Sorted**:
  - Traverse the linked list `stk_a` to check if it is already sorted.

### 4️⃣ Determine the Size of the List
- **Determine `size_of_list`**:
  - Count the number of elements in `stk_a` to determine `size_of_list`.

### 5️⃣ Decide Which Sorting Algorithm to Use
- **Choose Sorting Algorithm**:
  - If `size_of_list` is 3, call `sort_3(&stk_a)`.
  - If `size_of_list` is 5, call `sort_5(size_of_list, &stk_a, &stk_b)`.
  - If `size_of_list` is greater than 5, call `sort_main_algo(size_of_list, &stk_a, &stk_b)`.

---

## 🧩 `sort_main_algo` Function

1. **Create Sorted Array**:
   - Call `fill_sort_arr(size_of_list, &stk_a)` to create a sorted array of the list's elements.
     
2. **Determine Number of Chunks and chunck_size**:
   - If `size_of_list` is less than or equal to 100, set `number_of_chunks` to 5.
   - Otherwise, set `number_of_chunks` to 13.
   - Calculate `chunck_size` as `size_of_list / number_of_chunks`.
   
3. **Move Chunks**:
   - Initialize `current_chunck_key` to `chunck_size - 1`.
   - While `number_of_chunks` is greater than or equal to 1:
     - Call `move_chunk(sorted_array[current_chunck_key], &stk_a, &stk_b)` to move elements from `stk_a` to `stk_b` based on the current chunk's maximum value.
     - Decrement `number_of_chunks`.
     - Update `current_chunck_key` by adding `chunck_size`.

5. **Push Remaining Elements**:
   - Call `push_remaining(size_of_list, sorted_array, &stk_a, &stk_b)` to handle any remaining elements in `stk_a`.

6. **Push Back Chunks**:
   - Call `push_back_chuncks(&stk_a, &stk_b)` to move the sorted chunks back from `stk_b` to `stk_a`.
---

## ⚙️ Helper Functions

### 🚀  `fill_sort_arr` Function
1. **Initialize Array**:
   - Allocate memory for an array `arr` of size `size_of_arr`.
   - Initialize a temporary pointer `temp` to point to the head of the linked list.

2. **Fill Array**:
   - Iterate through the linked list and fill the array with the node values.

3. **Sort Array**:
   - Call `sort_arr(arr, size_of_arr)` to sort the array ascending.

4. **Return Array**:
   - Return the sorted array `arr`.

### 🚀 `move_chunk` Function
1. **Initialize Variables**:
   - Initialize `stka_size` by calling `count_elements_list(&stk_a)`.
   - Initialize `current` to point to the head of `stk_a`.

2. **Move Elements**:
   - If the first element in `stk_a` is less than or equal to `chunk_max_num`, call `pb(&stk_a, &stk_b)` to push it to `stk_b` and decrement `stka_size`.
   - Iterate through the linked list:
     - If the current node's value is less than or equal to `chunk_max_num`, call `push_num_top(stka_size, next_num, &stk_a, 1)` to move it to the top and then call `pb(&stk_a, &stk_b)` to push it to `stk_b`. Decrement `stka_size`.

### 🚀 `push_remaining` Function
1. **Count Elements**:
   - If `stk_1` is not empty, count the elements in `stk_1`.

2. **Push Elements**:
   - If there is 1 element, call `pb(&stk_1, &stk_2)`.
   - If there are 2 elements, call `pb(&stk_1, &stk_2)` twice.
   - If there are 3 elements, call `sort_3(&stk_1)`.
   - If there are more than 3 elements, call `move_chunk(sorted_arr[arr_size - 4], &stk_1, &stk_2)` and then `sort_3(&stk_1)`.

### 🚀 `push_back_chunks` Function
1. **Initialize Variables**:
   - Initialize `max_num` with the value of the first element in `stkb`.
   - Initialize `current` to point to the head of `stkb`.

2. **Move Elements**:
   - Iterate through the linked list:
     - Find the next maximum value by calling `get_next_max(max_num, &stkb)`.
     - Count the elements in `stkb`.
     - Move the maximum value to the top by calling `push_num_top(stkb_size, max_num, &stkb, 0)`.
     - Push the element from `stkb` to `stka` by calling `pa(&stka, &stkb)`.

### 🚀 `sort_3` Function
1. **Sort Three Elements**:
   - Implement the logic to sort three elements in `stk_main`:
     - Compare the three elements and swap them as necessary to sort them in ascending order.

### 🚀 `sort_5` Function
1. **Sort Five Elements**:
   - Find the minimum value in `stk_main` by calling `get_min(&stk_main)`.
   - Move the minimum value to the top and push it to `stk_2` using `push_num_top` and `pb`.
   - If `size_of_list` is 5, repeat the process for the next minimum value.
   - Call `sort_3(&stk_main)` to sort the remaining three elements.
   - Move the elements back from `stk_2` to `stk_main` using `pa`.

---

## ⚙️ Some of utilities Functions

1. **`get_min`**: 
   - Finds and returns the minimum value in the linked list.

2. **`push_num_top`**:
   - Moves a specific number to the top of the stack.

3. **`get_next_max`**:
   - Finds and returns the next maximum value in the linked list, excluding a specified value.

4. **`count_elements_list`**:
   - Counts and returns the number of elements in the linked list.

5. **`pb` and `pa`**:
   - Pushes elements between stacks.

---

## 📝 Summary

The algorithm sorts a linked list by:
- Dividing it into chunks.
- keeping the chunk that has the largest numbers at the top of stack_b while the bottom of stack_b has the chunk that contains the smallest numbers(the chunk itself is not sorted ).
- pushing the numbers from stack_b to stack_a.


It uses helper functions to manage the movement and sorting of elements between two stacks. The main function initializes the process, validates the input, checks if the list is already sorted, and decides which sorting algorithm to use (`sort_3`, `sort_5`, or `sort_main_algo`) based on the number of elements. The `sort_3` and `sort_5` functions handle specific cases for sorting three and five elements, respectively.

