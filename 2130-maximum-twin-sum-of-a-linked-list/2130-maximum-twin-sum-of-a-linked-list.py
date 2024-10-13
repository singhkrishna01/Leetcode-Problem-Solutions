# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def pairSum(self, head: Optional[ListNode]) -> int:
        slow = fast = head

        while fast and fast.next:

            if fast.next.next:
                slow = slow.next
                fast = fast.next.next
            else:
                fast = fast.next

        curr = slow.next
        prev = None
        while curr:
            next_node = curr.next
            curr.next = prev

        slow.next = fast
        slow = head

        max_twin_sum = 0
        while fast:
            max_twin_sum = max(max_twin_sum, slow.val + fast.val)
            slow = slow.next
            fast = fast.next

        return max_twin_sum
        