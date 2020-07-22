cmake_minimum_required(VERSION 3.14)
project(DataStructureImp)

set(CMAKE_CXX_STANDARD 11)

#add_executable(DataStructureImp main.cpp)

# chapter_01_绪论
add_executable(1_1_bubblesort chapter_01_绪论/1_1_bubblesort1A.cpp)
add_executable(1_2_countOnes chapter_01_绪论/1_2_countOnes.cpp)
add_executable(1_3_sumI chapter_01_绪论/1_3_sumI.cpp)
add_executable(1_4_power2BF_I chapter_01_绪论/1_4_power2BF_I.cpp)
add_executable(1_5_sum_linearRecursion chapter_01_绪论/1_5_sum_linearRecursion.cpp)
add_executable(1_6_reverse chapter_01_绪论/1_6_reverse.cpp)
add_executable(1_8_sqr_linearRecursion chapter_01_绪论/1_8_sqr_linearRecursion.cpp)
add_executable(1_11_sum_binaryRecursion chapter_01_绪论/1_11_sum_binaryRecursion.cpp)
add_executable(1_12_fib_binaryRecursion chapter_01_绪论/1_12_fib_binaryRecursion.cpp)
add_executable(1_13_fib_linearRecursion chapter_01_绪论/1_13_fib_linearRecursion.cpp)
add_executable(1_14_fib_dynamicProgramming chapter_01_绪论/1_14_fib_dynamicProgramming.cpp)

add_executable(BSTree Tree/BinarySearchTree/BSTree.cpp)

# 1. 排序算法
add_executable(1-1_bubbleSortTest 1_排序算法/1-1_冒泡排序/bubbleSortTest.cpp)

# 2. 查找算法
add_executable(2-1sequentialSearch 2_查找算法/2-1_顺序查找/sequentialSearch.cpp)
add_executable(2-2_binSearch_loop 2_查找算法/2-2_二分查找/binSearchTest.cpp)

# 3. 栈
add_executable(3-1_StackImp 3_栈/3-1_StackImp.cpp)
add_executable(3-2_stl_stack_basic_op 3_栈/3-2_stl_stack_basic_op.cpp)
add_executable(leetcode_225_ImplementStackUsingQueue 3_栈/leetcode_225_ImplementStackUsingQueues.cpp)
add_executable(leetcode_155_MinStack 3_栈/leetcode_155_MinStack.cpp)
add_executable(leetcode_946_ValidateStackSquence 3_栈/Leetcode_946_ValidateStackSequence.cpp)


# 4. 队列
add_executable(4-1_stl_queue_basic_op 4_队列/4-1_stl_queue_basic_op.cpp)
add_executable(leetcode_232_ImplementQueueUsingStack 4_队列/leetcode_232_ImplementQueueUsingStack.cpp)


# 5. 堆
add_executable(5-1_stl_heap_basic_op 5_堆/5-1_stl_heap_basic_op.cpp)
add_executable(Leetcode_215_KthLargestElementinArray 5_堆/Leetcode_215_KthLargestElementinArray.cpp)
add_executable(Leetcode_295_FindMedianFromDataStream 5_堆/Leetcode_295_FindMedianFromDataStream.cpp)

# 6. 链表
add_executable(6-1_linklist_basic 6_链表/6-1_linklist_basic.cpp)
add_executable(6-2_stl_set_basic_op 6_链表/6-2_stl-set_basic_op.cpp)
add_executable(6-3_stl_map_basic_op 6_链表/6-3_stl_map_basic_op.cpp)
add_executable(Leetcode_206_ReverseLinkedList 6_链表/Leetcode_206_ReverseLinkedList.cpp)
add_executable(Leetcode_92_ReverseLinkedListII 6_链表/Leetcode_92_ReverseLinkedListII.cpp)
add_executable(Leetcode_160_IntersectionofTwoLinkedList 6_链表/Leetcode_160_IntersectionofTwoLinkedLists.cpp)
add_executable(Leetcode_142_IntersectionofTwoLinkedLists 6_链表/Leetcode_142_LinkedListCycleII.cpp)
add_executable(Leetcode_86_PartitionList 6_链表/Leetcode_86_PartitionList.cpp)
add_executable(Leetcode_138_CopyListwithRandomPointer 6_链表/Leetcode_138_CopyListwithRandomPointer.cpp)
add_executable(Leetcode_21_MergeTwoSortedLists 6_链表/Leetcode_21_MergeTwoSortedLists.cpp)
add_executable(Leetcode_23_MergeKSortedLists 6_链表/Leetcode_23_MergeKSortedLists.cpp)


# 7 贪心
add_executable(Leetcode_455_AssignCookies 7_贪心/Leetcode_455_AssignCookies.cpp)