str1 = input()
str2 = input()
str3 = input()

n = 0

if str1.isdigit():
    n = int(str1) + 3
elif str2.isdigit():
    n = int(str2) + 2
else:
    n = int(str3) + 1

if n % 3 == 0 and n % 5 == 0:
    print("FizzBuzz")
elif n % 3 == 0:
    print("Fizz")
elif n % 5 == 0:
    print("Buzz")
else:
    print(n)
