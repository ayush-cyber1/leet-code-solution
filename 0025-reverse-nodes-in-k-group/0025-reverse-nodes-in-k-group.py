# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def reverseKGroup(self, head: ListNode, k: int) -> ListNode:
        # Check if there are at least k nodes remaining
        node = head
        count = 0
        while node and count < k:
            node = node.next
            count += 1

        if count < k:
            return head  # fewer than k nodes left, leave as-is

        # Reverse the first k nodes
        prev = None
        curr = head
        for _ in range(k):
            next_node = curr.next
            curr.next = prev
            prev = curr
            curr = next_node

        # 'curr' now points to the (k+1)th node — recurse for the rest of the list
        # 'head' is now the tail of this reversed group — connect it to the next reversed group
        head.next = self.reverseKGroup(curr, k)

        return prev  # prev is the new head of this reversed group