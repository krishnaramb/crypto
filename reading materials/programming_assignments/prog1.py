

def XOR(a,b):
	return bytes(x^y for x,y in zip(a,b))




def main():
	m1 = 'attack at dawn'
	c1 = '6c73d5240a948c86981bc294814d'
	k = XOR(m1.encode().hex().encode(), c1.encode())
	print (k)
	m2 = 'attack at dusk'
	c2 = XOR(m2.encode().hex().encode(), k)
	print(c2)



if __name__ == "__main__":
	main()