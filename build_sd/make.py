class File:
    def __init__(self, size):
        self.size = size
        self.placeholders = []


class SDFS:
    def __init__(self, size: int):
        self.size = size
        self.files = []

    def add(self, file: File):
        self.files.append(file)
