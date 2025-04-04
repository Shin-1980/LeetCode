class RandomizedSet:

    def __init__(self):
        self.map = {}
        self.values = []

    def insert(self, val: int) -> bool:
        if val in self.map:
            return False

        self.map[val] = len(self.values)
        self.values.append(val)
        return True

    def remove(self, val: int) -> bool:
        if val not in self.map:
            return False
        
        idx_to_remove = self.map[val]
        last_element = self.values[-1]
        self.values[idx_to_remove] = last_element
        self.map[last_element] = idx_to_remove
        self.values.pop()
        del self.map[val]

        return True

    def getRandom(self) -> int:
        return choice(self.values)
        


# Your RandomizedSet object will be instantiated and called as such:
# obj = RandomizedSet()
# param_1 = obj.insert(val)
# param_2 = obj.remove(val)
# param_3 = obj.getRandom()