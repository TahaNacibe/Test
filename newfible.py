import time
import os
isactiv = True
class HpRegaine() :
	def __init__(self,hp,mp):
		self.hp= hp
		self.mp=mp
	def mp(mp):
		mp = mp+1
		
	  
		
	def calc(hp,mp):
		
		while mp!= 0:
			hp = hp+1
			mp = mp-1
			time.sleep(0.5)
			os.system('clear')
			print(f"curent hp : {hp}\n current mp : {mp}")
			if isactiv :
			   
			   HpRegaine.mp(mp)
		print("run out of mp")

		
HpRegaine.calc(10,100)

	
		