# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def swapPairs(self, head: ListNode) -> ListNode:
        dummy = ListNode(0, head)
        prev = dummy

        while prev.next and prev.next.next:
            first = prev.next
            second = first.next

            # Perform the swap
            first.next = second.next
            second.next = first
            prev.next = second

            # Move prev forward by two (past the swapped pair)
            prev = first

        return dummy.next