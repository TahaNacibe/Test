import os
import time
class Student():
	def __init__(self,name,sub,s1,s2,s3):
		self.name = name
		self.sub = sub
		self.s1 = s1
		self.s2 = s2
		self.s3 = s3
		
		self.isPassed = "Failed"
		self.total = int((s1+s2+s3)/3)
		def check():
			if self.total >=10:
				self.isPassed = "Passed"
			return self.isPassed
		self.isPassed = check()


idBase = ["0000","1234"]
students =[
Student("student","real",12,12,11),
Student("atudent2","here",10,9,11),
Student("fuck","you",11,10,8),
Student("hauii","yooo",9,9,11),
Student("shit","man",8,7,5)
]
def acces():
	user = input("enter you ID : ")
	os.system('clear')
	if (user in idBase):
		print("Welcome Master ")
		return True
	else :
		print("Access Denid")
		time.sleep(1)
		os.system('clear')
		main()
		return False

def add():
	name = input("Enter the Name :")
	sub = input("Enter the SurName :")
	s1 = int(input("First Simester :"))
	s2 = int(input("Second Sumester :"))
	s3 = int(input("Third Simester :"))
	os.system('clear')
	students.append(Student(name,sub,s1,s2,s3))
	print("Add it Secsasfully")
	time.sleep(1)
	os.system('clear')
	main()

def edit():
	print("Im Bord so i will do it other time \n")
	x = 0
	while(x != 10):
		time.sleep(1)
		print("\t \(°0°)/ \t \n")
		x = x+1
	print("\t _____\(=-=)/ _______\t")
	time.sleep(3)
	os.system('clear')
	main()

def main():
	print("student counsill archive :")
	if (acces()):
		print("0-Show Studenta\n1- new Student\n2- edit Student\n3-Search for student")
	chois = input("Enter Your Command :")
	os.system('clear')
	if chois == "0":
		i = 1
		for student in students :
			print(f"{i}- {student.name} \t{student.sub}\t{student.isPassed}")
			i = i +1
		chois = input(" Enter ID to Prossed :")
		if chois in idBase :
			os.system('clear')
			main()
	elif chois == "1" :
		add()
	elif chois == "2":
		edit()
	else :
		edit()
		
main()