def home():
	print("1--Sign in\n2--Creat acount\n3--Quite")
	choic = int(input("set a command:"))
	return choic
	
class User():
	def __init__(self,name,password):
		self.name = name
		self.password = password
		
users =[]
users.append(User("taha","1234"))
users.append(User("admin","admin"))
def check(now):
	for i in users:
		if i == now:
			print("yrs")
		else:
			print("no")
			
def main():
	choic = home()
	if choic == 1 :
		print("=======Sign-In========")
		user = input("UserName: ")
		password = input("password: ")
		current = User(user,password)
		check(current)
	elif choic == 2 :
		print("=======Creat account========")
		userName = input("UserName: ")
		password = input("password: ")
		users.append(User(userName,password))
		main()
	elif choic == 3 :
		print("Good by")
		quit()
	else :
		print("Not supported command !!")
		main()	
main()
