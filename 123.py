import time
import os
import threading

class player():
    def __init__(self,Hp,Mp):
        self.Hp = Hp
        self.Mp = Mp

    def HpRe(Hp,Mp):
        while Mp != 0:
            time.sleep(1)
            if Hp!= 100:
                os.system('clear')
                Hp = Hp+1
                Mp = Mp-1
                print(f'your Hp:{Hp}\nyour Mp:{Mp}')
            else:
                print('Max Hp Reached')
        print('No Mana Left!!')

    def MpRe(Mp):
        while Mp != 100:
            time.sleep(2)
            Mp = Mp+1
        print('Max Mp Reached')
        
    
    technic1 = threading.Thread(target=HpRe(50,50))
    technic2 = threading.Thread(target=MpRe(50,50))

while True :
    player.technic1.start()
    player.technic2.start()