import random
f = open('ran_10000', 'w')
f.write(str(10000)+"\n")
for i in range(0,10000):
    f.write(str(random.randint(0,10000))+"\n")
f.close()
f = open('ran_100000', 'w')
f.write(str(100000)+"\n")
for i in range(0,100000):
    f.write(str(random.randint(0,100000))+"\n")
f.close()
f = open('ran_1000000', 'w')
f.write(str(1000000)+"\n")
for i in range(0,1000000):
    f.write(str(random.randint(0,1000000))+"\n")
f.close()
