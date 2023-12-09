from typing import List

class Solution:
    def leastInterval(self, tasks: List[str], n: int) -> int:
        # if n == 0:
        #     return len(tasks)

        chars = {}

        for task in tasks:
            if task in chars:
                chars[task] += 1
            else:
                chars[task] = 1
        
        sChars = sorted(chars.items(), key=lambda item:item[1], reverse=True)

        charCount = []

        for char in sChars:
            charCount.append(char[1])

        ptr = 0

        count = 0

        queue = []

        while len(sChars) > 0:
            if len(queue) == n + 1:
                front = queue.pop(0)

                if sChars[0][0] == front:
                    ptr = 0
            
            if ptr >= len(sChars):
                queue.append("-1")
                count += 1
                ptr += 1
            else:
            
                count += 1

                queue.append(sChars[ptr][0])

                charCount[ptr] -= 1
                if charCount[ptr] < 1:
                    sChars.remove(sChars[ptr])
                    del charCount[ptr]
            
                else:
                    ptr += 1
        
        return count



test = Solution()

print(test.leastInterval(["A","A","A","B","B","B"], 0))