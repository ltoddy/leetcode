from bisect import bisect_left


class RecentCounter:

    def __init__(self):
        self.store = []

    def ping(self, t):
        """
        :type t: int
        :rtype: int
        """
        self.store.append(t)
        cur = len(self.store)
        prev = bisect_left(self.store, t - 3000)
        return cur - prev

# Your RecentCounter object will be instantiated and called as such:
# obj = RecentCounter()
# param_1 = obj.ping(t)
