class Activity:
    def __init__(self, name, start, end):
        self.name = name
        self.start = start
        self.end = end

if __name__ == "__main__":
    n = int(input("Enter the number of activities: "))
    activities = []
    for i in range(n):
        name = input("Enter")
        ## TODO: Complete this