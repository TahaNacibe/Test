print("-"*10,"welcome to i will guess your number","-"*10)
print("-note: i never lose 😎-")
number = int(input("inter a number between 1 - 10: "))

while number < 1 or number > 10:
    print(f"{number} is not valid 😐")
    number = input("inter a number between 1 - 10: ")
print(f"your number is {number} 🤣😂👏") 
