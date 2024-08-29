class Solution:
	def isPalindrome(self, s: str) -> bool:
		string = ''
		for n in s:
			if n.isalnum():
				string += n.lower()

		l, r = 0, len(string) - 1

		while l < r:
			if string[l] == string[r]:
				l += 1
				r -= 1
			else:
				return False
		return True
            