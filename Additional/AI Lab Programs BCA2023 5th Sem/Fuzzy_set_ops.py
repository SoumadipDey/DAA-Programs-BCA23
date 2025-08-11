# This code works ok for fuzzy sets having the same number of elements.
# I will implement the general version later.

members = input("Enter the members of the set: ").split()
deg_memA = list(map(float,input("Enter the degree of membership for A Set: ").split()))
deg_memB = list(map(float,input("Enter the degree of membership for B Set: ").split()))

setA = {}
setB = {}

for mem,degA,degB in zip(members, deg_memA, deg_memB):
    setA[mem] = degA
    setB[mem] = degB

print("Set A:\n",setA)
print("\nSet B:\n",setB)

def fuzzyUnion(setA:dict, setB:dict):
    setAUB = {}
    for mem in setA.keys():
        setAUB[mem] = max(setA[mem], setB[mem])

    return setAUB

def fuzzyIntersection(setA:dict, setB:dict):
    setAandB = {}
    for mem in setA.keys():
        setAandB[mem] = min(setA[mem], setB[mem])

    return setAandB

def fuzzyComplement(setA):
    setAcomplement = {mem: round(1.0 - setA[mem],2) for mem in setA.keys()}
    return setAcomplement

def fuzzyAlgebraicSum(setA, setB):
    setAplusB = {mem: round(setA[mem] + setB[mem] - setA[mem]*setB[mem],2) for mem in setA.keys()}
    return setAplusB

def fuzzyAlgebraicProduct(setA, setB):
    setAdotB = {mem: round(setA[mem] * setB[mem],2) for mem in setA.keys()}
    return setAdotB

print("\nA Union B:\n",fuzzyUnion(setA,setB))
print("\nA Intersection B:\n",fuzzyIntersection(setA,setB))
print("\nA Complement:\n",fuzzyComplement(setA))
print("\nB Complement:\n",fuzzyComplement(setB))
print("\nAlgebriac Sum of A & B:\n",fuzzyAlgebraicSum(setA,setB))
print("\nAlgebriac Product of A & B:\n",fuzzyAlgebraicProduct(setA,setB))