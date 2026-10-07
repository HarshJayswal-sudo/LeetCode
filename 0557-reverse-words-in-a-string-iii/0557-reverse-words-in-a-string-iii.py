class Solution(object):
    def reverseWords(self, s):
        words = s.split()
        print(s.split())
        
        reverse_words = [word[::-1] for word in words]
        print(reverse_words)

        return " ".join(reverse_words)
        