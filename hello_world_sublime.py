fin = open('input.txt','r')
fout = open('output.txt','w')
data = fin.read()



fout.write(data)
fin.close()
fout.close()
