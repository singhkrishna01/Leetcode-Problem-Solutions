class Solution:
    def judgePoint24(self, cards: List[int]) -> bool:
        def find_numbers(cards, st, end):
            
            if st > end:
                return []
            
            if st == end:
                return [cards[st]]
            
            ans = set()

            for i in range(st, end):
                left_ans = find_numbers(cards, st, i)
                right_ans = find_numbers(cards, i+1, end)
                for left in left_ans:
                    for right in right_ans:
                        ans.add(left + right)
                        ans.add(left-right)
                        ans.add(left * right)
                        if right != 0:
                            ans.add(left/right)
            
            return list(ans)

            
        
        
        to_find = 24
        eps = 10**-6

        for cur_cards in permutations(cards):
            all_possible_numbers = find_numbers(list(cur_cards), 0, 3)
            for num in all_possible_numbers:
                if abs(num-24) < eps:
                    return True
        
        return False