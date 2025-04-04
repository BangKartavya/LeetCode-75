class Solution:
    def gcd(self, a, b):
        if b == 0:
            return a

        return self.gcd(b, a % b)

    def gcdOfStrings(self, str1: str, str2: str) -> str:
        if str1 + str2 != str2 + str1:
            return ""

        return str1[0 : self.gcd(len(str1), len(str2))]
