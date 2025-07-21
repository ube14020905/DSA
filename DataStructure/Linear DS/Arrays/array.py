class Array:

    t = [int,float,complex]

    def __init__(self,size,typeOfArray):
        self.size = size
        if typeOfArray in self.t:
            self.typeOfArray = typeOfArray
        else:
             raise TypeError("Unsupported ArrayType: " + str(typeOfArray))
        
        self.__data=[]
        self.__count=0
    
    def insert(self,val):
        if not isinstance(val, self.typeOfArray):
            return f"Type mismatch: Expected {self.typeOfArray.__name__}, got {type(val).__name__}"

        if self.__count < self.size:
            self.__data.append(val)
            self.__count += 1
        else:
            return "Array is full"
    
    def pop(self):
        if self.__data:
            print(f"{self.__data[-1]} is removed from the Array")
            self.__data.pop();
            self.__count -=1
        else:
            return "array is empty"
    
    def count(self):
        return self.__count;
    
    def sum(self):   
        s = 0
        for x in self.__data:
            s += x
        return s
    
    def __str__(self):
        return str(self.__data)
    
    def search(self,k):
        if k not in self.__data:
            return f"{k} is not Found in the Array"
        else:
            return f"{k} found at index {self.__data.index(k)} in Array"
    
    def __getitem__(self, index):
            
        if 0 <= index < self.__count:
                return self.__data[index]
        else:
            raise IndexError("Index out of range")

    def __setitem__(self, index, value):
        if not isinstance(value, self.typeOfArray):
            raise TypeError(f"Expected {self.typeOfArray.__name__}, got {type(value).__name__}")

        if 0 <= index < self.__count:
            self.__data[index] = value
        else:
            raise IndexError("Index out of range")

    def sort(self):
        if self.typeOfArray != complex:
            self.__data.sort()
        else:
            raise TypeError(f"Unsupported {self.typeOfArray} Type for Sorting ")
